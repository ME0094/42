#!/bin/sh

set -eu

root=$(CDPATH= cd -- "$(dirname "$0")/.." && pwd)
reference="$root/reference"
build="${TMPDIR:-/tmp}/c-piscine-exam-audit"
norminette_bin=${NORMINETTE:-"$HOME/.local/bin/norminette"}
total=0
passed=0
failed=0
rm -rf "$build"
mkdir -p "$build"

is_allowed()
{
	symbol="$1"
	allowed="$2"
	case " $allowed " in
		*" $symbol "*) return 0 ;;
	esac
	return 1
}

check_expected_files()
{
	subject="$1"
	solution="$2"
	expected=$(sed -n 's/^Expected files[[:space:]]*:[[:space:]]*//p' "$subject" \
		| tr -d '\r')
	for item in $(printf '%s' "$expected" | tr ',' ' ')
	do
		case "$item" in
			'*.c'|'*.h') : ;;
			*) test -f "$solution/$item" || return 1 ;;
		esac
	done
}

check_symbols()
{
	subject="$1"
	objects="$2"
	allowed=$(sed -n 's/^Allowed functions[[:space:]]*:[[:space:]]*//p' "$subject" \
		| tr -d '\r')
	allowed=$(printf '%s' "$allowed" | tr ',' ' ')
	case "$allowed" in
		None|none|'-') allowed='' ;;
	esac
	for symbol in $(nm -u "$objects"/*.o 2>/dev/null | awk '{print $NF}' | sort -u)
	do
		case "$symbol" in
			_GLOBAL_OFFSET_TABLE_) continue ;;
		esac
		is_allowed "$symbol" "$allowed" || return 1
	done
}

audit_exercise()
{
	subject="$1"
	solution="$2"
	name=$(basename "$solution")
	objects="$build/$(basename "$(dirname "$solution")")-$name"
	total=$((total + 1))
	mkdir -p "$objects"
	result=PASS
	check_expected_files "$subject" "$solution" || result=FILES
	if ! "$norminette_bin" "$solution" >/dev/null 2>&1
	then
		result=NORM
	fi
	for source in "$solution"/*.c
	do
		if ! cc -Wall -Wextra -Werror -fno-builtin -fno-stack-protector \
			-I"$solution" \
			-c "$source" -o "$objects/$(basename "$source" .c).o"
		then
			result=COMPILE
		fi
	done
	if test "$result" = PASS && ! check_symbols "$subject" "$objects"
	then
		result=SYMBOLS
	fi
	if test "$result" = PASS
	then
		passed=$((passed + 1))
	else
		failed=$((failed + 1))
	fi
	printf '%-7s %s/%s\n' "$result" "$(basename "$(dirname "$solution")")" "$name"
}

for number in 00 01 02 03 04 05
do
	ref_level="$reference/Level $number"
	solution_level="$root/Level$number"
	for subject in "$ref_level"/*/subject.en.txt
	do
		name=$(basename "$(dirname "$subject")")
		audit_exercise "$subject" "$solution_level/$name"
	done
done

printf 'Audit summary: total=%d passed=%d failed=%d\n' "$total" "$passed" "$failed"
test "$total" -eq 73
test "$failed" -eq 0
