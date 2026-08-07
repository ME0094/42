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

compile_programs Level01
assert_output 1-0-repeat_alpha abbccc abc
assert_output 1-0-search_and_replace bonono banana a o
assert_output 1-0-ulstr 'hELLO 42' 'Hello 42'
assert_output 1-1-rot_13 Uryyb Hello
assert_output 1-2-first_word hello '  hello world'
assert_output 1-3-first_word hello '  hello world'
assert_output 1-3-rev_print dcba abcd
assert_output 1-4-rotone 'Bcd YZA' 'Abc XYZ'
find "$root/Level01" -name '*.c' -type f | while IFS= read -r source
do
	cc -Wall -Wextra -Werror -c "$source" -o "$build/$(basename "$(dirname "$source")").o"
done
printf 'Level01: all tests passed\n'

compile_programs Level02
assert_output 2-0-inter bc abc bcd
assert_output 2-0-last_word world ' hello world  '
assert_output 2-0-union abcd abc bcd
assert_output 2-1-alpha_mirror 'zyx CBA' 'abc XYZ'
assert_output 2-3-wdmatch abc abc axbyc
assert_output 2-4-do_op 42 40 + 2
find "$root/Level02" -name '*.c' -type f | while IFS= read -r source
do
	cc -Wall -Wextra -Werror -c "$source" -o "$build/$(basename "$(dirname "$source")").o"
done
printf 'Level02: all tests passed\n'

compile_programs Level03
assert_output 3-0-add_prime_sum 17 7
assert_output 3-0-epur_str 'hello world' '  hello   world  '
assert_output 3-0-hidenp 1 abc axbyc
assert_output 3-0-pgcd 6 18 24
assert_output 3-0-print_hex 2a 42
assert_output 3-1-expand_str 'hello   world' ' hello world '
assert_output 3-4-paramsum 3 a b c
assert_output 3-4-str_capitalizer 'Hello World' 'hELLO wORLD'
find "$root/Level03" -name '*.c' -type f | while IFS= read -r source
do
	cc -Wall -Wextra -Werror -c "$source" -o "$build/$(basename "$(dirname "$source")").o"
done
printf 'Level03: all tests passed\n'

compile_programs Level04
assert_output 4-5-check_mate Success '...K' '....' '....' '...R'
assert_output brainfuck A '+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.'
assert_output fprime '3*3*5*5' 225
assert_output rev_wstr 'world hello' 'hello world'
assert_output rostring 'two three one' ' one  two three '
find "$root/Level04" -name '*.c' -type f | while IFS= read -r source
do
	cc -Wall -Wextra -Werror -I"$(dirname "$source")" -c "$source" -o "$build/$(basename "$(dirname "$source")").o"
done
printf 'Level04: all tests passed\n'

compile_programs Level05
assert_output 5-3-brackets OK '{a[(b)]}'
assert_output 5-3-brackets Error '([)]'
assert_output 5-4-rpn_calc 10 '1 2 * 3 * 4 +'
assert_output 5-4-rpn_calc Error '1 2 3 +'
assert_output 5-5-options '00000000 00000000 00000111 00000111' -abc -ijk
assert_output biggest_pal abcba abcba
assert_output biggest_pal aba abacdfgdcaba
find "$root/Level05" -name '*.c' -type f | while IFS= read -r source
do
	cc -Wall -Wextra -Werror -I"$(dirname "$source")" -c "$source" -o "$build/$(basename "$(dirname "$source")").o"
done
printf 'Level05: all tests passed\n'
