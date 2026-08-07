#!/bin/sh

set -eu

exam=$(CDPATH= cd -- "$(dirname "$0")/.." && pwd)
build="${TMPDIR:-/tmp}/c-piscine-functional"
passed=0
failed=0

check()
{
	id="$1"; expected="$2"; shift 2
	printf '%b' "$expected" > "$build/edge-expected"
	if "$build/$id" "$@" > "$build/edge-actual" \
		&& cmp -s "$build/edge-expected" "$build/edge-actual"
	then
		passed=$((passed + 1)); printf 'EDGE PASS %s\n' "$id"
	else
		failed=$((failed + 1)); printf 'EDGE FAIL %s\n' "$id"
	fi
}

[ -x "$build/0-0-aff_a" ] || sh "$exam/tests/functional.sh"
check 0-0-aff_a '\n' ''
check 0-0-ft_countdown '9876543210\n' ignored
check 0-0-hello 'Hello World!\n' ignored
check 0-0-maff_alpha 'aBcDeFgHiJkLmNoPqRsTuVwXyZ\n' ignored
check 0-1-aff_first_param '\n'
check 0-1-aff_last_param '\n'
check 0-1-maff_revalpha 'zYxWvUtSrQpOnMlKjIhGfEdCbA\n' ignored
check 0-1-only_a 'a' ignored
check 0-1-only_z 'z' ignored
check 0-2-aff_z 'z\n' ignored
check 1-0-repeat_alpha '\n'
check 1-0-search_and_replace '\n' abc a
check 1-0-ulstr '42!?\n' '42!?'
check 1-1-rot_13 'Abc-Nop\n' 'Nop-Abc'
check 1-2-first_word '\n' '   '
check 1-2-fizzbuzz '1\n2\nfizz\n4\nbuzz\nfizz\n7\n8\nfizz\nbuzz\n11\nfizz\n13\n14\nfizzbuzz\n16\n17\nfizz\n19\nbuzz\nfizz\n22\n23\nfizz\nbuzz\n26\nfizz\n28\n29\nfizzbuzz\n31\n32\nfizz\n34\nbuzz\nfizz\n37\n38\nfizz\nbuzz\n41\nfizz\n43\n44\nfizzbuzz\n46\n47\nfizz\n49\nbuzz\nfizz\n52\n53\nfizz\nbuzz\n56\nfizz\n58\n59\nfizzbuzz\n61\n62\nfizz\n64\nbuzz\nfizz\n67\n68\nfizz\nbuzz\n71\nfizz\n73\n74\nfizzbuzz\n76\n77\nfizz\n79\nbuzz\nfizz\n82\n83\nfizz\nbuzz\n86\nfizz\n88\n89\nfizzbuzz\n91\n92\nfizz\n94\nbuzz\nfizz\n97\n98\nfizz\nbuzz\n' ignored
check 1-3-first_word '\n'
check 1-3-rev_print '\n' ''
check 1-4-rotone '\n'
check 2-0-inter 'a\n' aaa aaa
check 2-0-last_word '\n' '   '
check 2-0-union 'a\n' aaa aaa
check 2-1-alpha_mirror '123 !\n' '123 !'
check 2-3-wdmatch '\n' abc acb
check 2-4-do_op '\n' 7 +
check 3-0-add_prime_sum '0\n' 1
check 3-0-epur_str '\n' '   '
check 3-0-hidenp '1\n' '' anything
check 3-0-pgcd '1\n' 17 13
check 3-0-print_hex '0\n' 0
check 3-0-rstr_capitalizer '\n'
check 3-1-expand_str '\n' '   '
check 3-1-tab_mult '1 x 0 = 0\n2 x 0 = 0\n3 x 0 = 0\n4 x 0 = 0\n5 x 0 = 0\n6 x 0 = 0\n7 x 0 = 0\n8 x 0 = 0\n9 x 0 = 0\n' 0
check 3-4-paramsum '0\n'
check 3-4-str_capitalizer '\n'
check 4-5-check_mate 'Fail\n' K
check brainfuck ''
check fprime '1\n' 1
check rev_wstr '\n' '   '
check rostring '\n' '   '
check 5-3-brackets 'OK\n' ''
check 5-4-rpn_calc 'Error\n' '4 0 /'
check 5-5-options 'options: abcdefghijklmnopqrstuvwxyz' -h
check biggest_pal '\n' ''

printf 'Program edge cases: total=%d passed=%d failed=%d\n' \
	"$((passed + failed))" "$passed" "$failed"
[ "$((passed + failed))" -eq 44 ] && [ "$failed" -eq 0 ]
