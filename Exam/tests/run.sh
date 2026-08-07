#!/bin/sh

set -eu

root=$(CDPATH= cd -- "$(dirname "$0")/.." && pwd)
build="${TMPDIR:-/tmp}/c-piscine-exam-tests"
rm -rf "$build"
mkdir -p "$build"

compile_programs()
{
	level="$1"
	find "$root/$level" -name '*.c' -type f | while IFS= read -r source
	do
		if grep -q 'int[[:space:]]*main' "$source"
		then
			name=$(basename "$(dirname "$source")")
			cc -Wall -Wextra -Werror "$source" -o "$build/$name"
		fi
	done
}

assert_output()
{
	name="$1"
	expected="$2"
	shift 2
	actual=$("$build/$name" "$@")
	if [ "$actual" != "$expected" ]
	then
		printf 'FAIL %s: expected <%s>, got <%s>\n' "$name" "$expected" "$actual"
		exit 1
	fi
}

compile_programs Level00
assert_output 0-0-aff_a a alphabet
assert_output 0-0-aff_a '' xyz
assert_output 0-0-aff_a a
assert_output 0-0-ft_countdown 9876543210
assert_output 0-0-hello 'Hello World!'
assert_output 0-0-maff_alpha aBcDeFgHiJkLmNoPqRsTuVwXyZ
assert_output 0-1-aff_first_param first first second
assert_output 0-1-aff_last_param second first second
assert_output 0-1-maff_revalpha zYxWvUtSrQpOnMlKjIhGfEdCbA
assert_output 0-1-only_a a
assert_output 0-1-only_z z
assert_output 0-2-aff_z z
cc -Wall -Wextra -Werror -c "$root/Level00/0-0-ft_print_numbers/ft_print_numbers.c" -o "$build/ft_print_numbers.o"
printf 'Level00: all tests passed\n'
