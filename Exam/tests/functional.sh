#!/bin/sh

set -eu

exam=$(CDPATH= cd -- "$(dirname "$0")/.." && pwd)
build="${TMPDIR:-/tmp}/c-piscine-functional"
harness="$exam/tests/functional_harness.c"
passed=0
failed=0
seen="$build/seen"
rm -rf "$build"
mkdir -p "$build"
: > "$seen"

record()
{
	id="$1"
	status="$2"
	printf '%s\n' "$id" >> "$seen"
	if [ "$status" -eq 0 ]
	then
		passed=$((passed + 1))
		printf 'PASS %s\n' "$id"
	else
		failed=$((failed + 1))
		printf 'FAIL %s\n' "$id"
	fi
}

check_output()
{
	id="$1"
	expected="$2"
	shift 2
	printf '%b' "$expected" > "$build/expected"
	if "$@" > "$build/actual" && cmp -s "$build/expected" "$build/actual"
	then
		record "$id" 0
	else
		record "$id" 1
		printf '  expected: '; od -An -tc "$build/expected"
		printf '  actual:   '; od -An -tc "$build/actual"
	fi
}

program()
{
	id="$1"; source="$2"; expected="$3"; shift 3
	cc -Wall -Wextra -Werror "$exam/$source" -o "$build/$id"
	check_output "$id" "$expected" "$build/$id" "$@"
}

function_case()
{
	id="$1"; macro="$2"; source="$3"; expected="$4"
	cc -Wall -Wextra -Werror -D"$macro" "$harness" "$exam/$source" -o "$build/$id"
	check_output "$id" "$expected" "$build/$id"
}

# Level00 (11)
program 0-0-aff_a Level00/0-0-aff_a/aff_a.c 'a\n' alphabet
program 0-0-ft_countdown Level00/0-0-ft_countdown/ft_countdown.c '9876543210\n'
function_case 0-0-ft_print_numbers TEST_PRINT_NUMBERS Level00/0-0-ft_print_numbers/ft_print_numbers.c '0123456789'
program 0-0-hello Level00/0-0-hello/hello.c 'Hello World!\n'
program 0-0-maff_alpha Level00/0-0-maff_alpha/maff_alpha.c 'aBcDeFgHiJkLmNoPqRsTuVwXyZ\n'
program 0-1-aff_first_param Level00/0-1-aff_first_param/aff_first_param.c 'first\n' first second
program 0-1-aff_last_param Level00/0-1-aff_last_param/aff_last_param.c 'second\n' first second
program 0-1-maff_revalpha Level00/0-1-maff_revalpha/maff_revalpha.c 'zYxWvUtSrQpOnMlKjIhGfEdCbA\n'
program 0-1-only_a Level00/0-1-only_a/only_a.c 'a'
program 0-1-only_z Level00/0-1-only_z/only_z.c 'z'
program 0-2-aff_z Level00/0-2-aff_z/aff_z.c 'z\n'

# Level01 (13)
function_case 1-0-ft_strcpy TEST_STRCPY Level01/1-0-ft_strcpy/ft_strcpy.c 'Piscine'
function_case 1-0-ft_strlen TEST_STRLEN Level01/1-0-ft_strlen/ft_strlen.c '7,0'
program 1-0-repeat_alpha Level01/1-0-repeat_alpha/repeat_alpha.c 'abbccc\n' abc
program 1-0-search_and_replace Level01/1-0-search_and_replace/search_and_replace.c 'bonono\n' banana a o
program 1-0-ulstr Level01/1-0-ulstr/ulstr.c 'hELLO 42\n' 'Hello 42'
program 1-1-rot_13 Level01/1-1-rot_13/rot_13.c 'Uryyb\n' Hello
program 1-2-first_word Level01/1-2-first_word/first_word.c 'hello\n' '  hello world'
program 1-2-fizzbuzz Level01/1-2-fizzbuzz/fizzbuzz.c '1\n2\nfizz\n4\nbuzz\nfizz\n7\n8\nfizz\nbuzz\n11\nfizz\n13\n14\nfizzbuzz\n16\n17\nfizz\n19\nbuzz\nfizz\n22\n23\nfizz\nbuzz\n26\nfizz\n28\n29\nfizzbuzz\n31\n32\nfizz\n34\nbuzz\nfizz\n37\n38\nfizz\nbuzz\n41\nfizz\n43\n44\nfizzbuzz\n46\n47\nfizz\n49\nbuzz\nfizz\n52\n53\nfizz\nbuzz\n56\nfizz\n58\n59\nfizzbuzz\n61\n62\nfizz\n64\nbuzz\nfizz\n67\n68\nfizz\nbuzz\n71\nfizz\n73\n74\nfizzbuzz\n76\n77\nfizz\n79\nbuzz\nfizz\n82\n83\nfizz\nbuzz\n86\nfizz\n88\n89\nfizzbuzz\n91\n92\nfizz\n94\nbuzz\nfizz\n97\n98\nfizz\nbuzz\n'
function_case 1-2-ft_putstr TEST_PUTSTR Level01/1-2-ft_putstr/ft_putstr.c '42 Piscine'
function_case 1-2-ft_swap TEST_SWAP Level01/1-2-ft_swap/ft_swap.c '42,-4'
program 1-3-first_word Level01/1-3-first_word/first_word.c 'hello\n' '  hello world'
program 1-3-rev_print Level01/1-3-rev_print/rev_print.c 'dcba\n' abcd
program 1-4-rotone Level01/1-4-rotone/rotone.c 'Bcd YZA\n' 'Abc XYZ'

# Level02 (15)
function_case 2-0-ft_atoi TEST_ATOI Level02/2-0-ft_atoi/ft_atoi.c '-42,-214,0'
function_case 2-0-ft_strdup TEST_STRDUP Level02/2-0-ft_strdup/ft_strdup.c 'copy me'
program 2-0-inter Level02/2-0-inter/inter.c 'bc\n' abc bcd
program 2-0-last_word Level02/2-0-last_word/last_word.c 'world\n' ' hello world  '
function_case 2-0-reverse_bits TEST_REVERSE_BITS Level02/2-0-reverse_bits/reverse_bits.c '72'
function_case 2-0-swap_bits TEST_SWAP_BITS Level02/2-0-swap_bits/swap_bits.c '20'
program 2-0-union Level02/2-0-union/union.c 'abcd\n' abc bcd
program 2-1-alpha_mirror Level02/2-1-alpha_mirror/alpha_mirror.c 'zyx CBA\n' 'abc XYZ'
function_case 2-1-max TEST_MAX Level02/2-1-max/max.c '-2,0'
program 2-3-wdmatch Level02/2-3-wdmatch/wdmatch.c 'abc\n' abc axbyc
program 2-4-do_op Level02/2-4-do_op/do_op.c '42\n' 40 + 2
function_case 2-4-print_bits TEST_PRINT_BITS Level02/2-4-print_bits/print_bits.c '00101010'
function_case 2-5-ft_strcmp TEST_STRCMP Level02/2-5-ft_strcmp/ft_strcmp.c '0,1,1'
function_case 2-5-ft_strrev TEST_STRREV Level02/2-5-ft_strrev/ft_strrev.c 'edcba,'
function_case 2.6-is_power_of_2 TEST_POWER2 Level02/2.6-is_power_of_2/is_power_of_2.c '1,1,0'

# Level03 (15)
program 3-0-add_prime_sum Level03/3-0-add_prime_sum/add_prime_sum.c '17\n' 7
program 3-0-epur_str Level03/3-0-epur_str/epur_str.c 'hello world\n' '  hello   world  '
function_case 3-0-ft_list_size TEST_LIST_SIZE Level03/3-0-ft_list_size/ft_list_size.c '3,0'
function_case 3-0-ft_rrange TEST_RRANGE Level03/3-0-ft_rrange/ft_rrange.c '-2,-1,0,1'
program 3-0-hidenp Level03/3-0-hidenp/hidenp.c '1\n' abc axbyc
program 3-0-pgcd Level03/3-0-pgcd/pgcd.c '6\n' 18 24
program 3-0-print_hex Level03/3-0-print_hex/print_hex.c '2a\n' 42
program 3-0-rstr_capitalizer Level03/3-0-rstr_capitalizer/rstr_capitalizer.c 'hellO worlD\n' 'HELLO WORLD'
program 3-1-expand_str Level03/3-1-expand_str/expand_str.c 'hello   world\n' ' hello world '
function_case 3-1-lcm TEST_LCM Level03/3-1-lcm/lcm.c '42,0'
program 3-1-tab_mult Level03/3-1-tab_mult/tab_mult.c '1 x 9 = 9\n2 x 9 = 18\n3 x 9 = 27\n4 x 9 = 36\n5 x 9 = 45\n6 x 9 = 54\n7 x 9 = 63\n8 x 9 = 72\n9 x 9 = 81\n' 9
function_case 3-2-ft_atoi_base TEST_ATOI_BASE Level03/3-2-ft_atoi_base/ft_atoi_base.c '-42,45,63'
function_case 3-3-ft_range TEST_RANGE Level03/3-3-ft_range/ft_range.c '-2,-1,0,1;0'
program 3-4-paramsum Level03/3-4-paramsum/paramsum.c '3\n' a b c
program 3-4-str_capitalizer Level03/3-4-str_capitalizer/str_capitalizer.c 'Hello World\n' 'hELLO wORLD'

# Level04 (13)
function_case 4-2-ft_list_remove_if TEST_REMOVE_IF Level04/4-2-ft_list_remove_if/ft_list_remove_if.c 'keep'
function_case 4-3-sort_list TEST_SORT_LIST Level04/4-3-sort_list/sort_list.c '123'
function_case 4-4-ft_itoa TEST_ITOA Level04/4-4-ft_itoa/ft_itoa.c '-2147483648,0'
program 4-5-check_mate Level04/4-5-check_mate/check_mate.c 'Success\n' '...K' '....' '....' '...R'
function_case 5-2-ft_itoa_base TEST_ITOA_BASE Level04/5-2-ft_itoa_base/ft_itoa_base.c 'FFFFFFD6,101010'
program brainfuck Level04/brainfuck/brainfuck.c 'A' '+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.'
function_case flood_fill TEST_FLOOD_FILL Level04/flood_fill/flood_fill.c 'FFF0/F000/FFF0'
program fprime Level04/fprime/fprime.c '3*3*5*5\n' 225
function_case ft_list_foreach TEST_LIST_FOREACH Level04/ft_list_foreach/ft_list_foreach.c '2,5'
function_case ft_split TEST_SPLIT Level04/ft_split/ft_split.c 'one,two,three'
program rev_wstr Level04/rev_wstr/rev_wstr.c 'world hello\n' 'hello world'
program rostring Level04/rostring/rostring.c 'two three one\n' ' one  two three '
function_case sort_int_tab TEST_SORT_INT Level04/sort_int_tab/sort_int_tab.c '-1,0,3,3'

# Level05 (6)
function_case 5-1-print_memory TEST_PRINT_MEMORY Level05/5-1-print_memory/print_memory.c '4865 6c6c 6f                            Hello\n'
program 5-3-brackets Level05/5-3-brackets/brackets.c 'OK\nError\n' '{a[(b)]}' '([)]'
program 5-4-rpn_calc Level05/5-4-rpn_calc/rpn_calc.c '10\n' '1 2 * 3 * 4 +'
program 5-5-options Level05/5-5-options/options.c '00000000 00000000 00000111 00000111\n' -abc -ijk
program biggest_pal Level05/biggest_pal/biggest_pal.c 'abcba\n' abcba
function_case cycle_detector TEST_CYCLE Level05/cycle_detector/cycle_detector.c '0,1'

expected=$(find "$exam/reference" -name subject.en.txt -type f | wc -l | tr -d ' ')
unique=$(sort -u "$seen" | wc -l | tr -d ' ')
total=$((passed + failed))
printf 'Functional coverage: total=%d unique=%d expected=%d passed=%d failed=%d\n' \
	"$total" "$unique" "$expected" "$passed" "$failed"
[ "$total" -eq 73 ] && [ "$unique" -eq 73 ] && [ "$expected" -eq 73 ] && [ "$failed" -eq 0 ]
