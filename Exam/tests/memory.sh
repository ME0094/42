#!/bin/sh

set -eu

root=$(CDPATH= cd -- "$(dirname "$0")/.." && pwd)
build="${TMPDIR:-/tmp}/c-piscine-exam-memory"
vg="valgrind --quiet --leak-check=full --show-leak-kinds=all"
vg="$vg --errors-for-leak-kinds=all --error-exitcode=42"
rm -rf "$build"
mkdir -p "$build"

cc -Wall -Wextra -Werror -g \
	"$root/tests/memory_harness.c" \
	"$root/Level02/2-0-ft_strdup/ft_strdup.c" \
	"$root/Level03/3-0-ft_rrange/ft_rrange.c" \
	"$root/Level03/3-3-ft_range/ft_range.c" \
	"$root/Level04/4-4-ft_itoa/ft_itoa.c" \
	"$root/Level04/5-2-ft_itoa_base/ft_itoa_base.c" \
	"$root/Level04/ft_split/ft_split.c" \
	"$root/Level04/4-2-ft_list_remove_if/ft_list_remove_if.c" \
	-o "$build/dynamic"
$vg "$build/dynamic"

sh "$root/tests/run.sh" >/dev/null
programs="${TMPDIR:-/tmp}/c-piscine-exam-tests"
program_count=0

check_program()
{
	name="$1"
	shift
	$vg "$programs/$name" "$@" >/dev/null
}

for program in "$programs"/*
do
	if test -x "$program" && test -f "$program"
	then
		$vg "$program" >/dev/null
		program_count=$((program_count + 1))
	fi
done

check_program 0-0-aff_a alphabet
check_program 1-0-repeat_alpha abc
check_program 2-0-union abc bcd
check_program 3-0-add_prime_sum 100
check_program 3-0-pgcd 48 18
check_program 4-5-check_mate ...K .... .... ...R
check_program brainfuck '++++++++[>++++++++<-]>+.'
check_program fprime 225225
check_program 5-3-brackets '{a[(b)]}'
check_program 5-4-rpn_calc '1 2 * 3 * 4 +'
check_program 5-5-options -abc -ijk
check_program biggest_pal abacdfgdcaba

printf 'Valgrind: dynamic functions and %d programs passed\n' "$program_count"
