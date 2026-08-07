#!/bin/sh

set -eu
root=$(CDPATH= cd -- "$(dirname "$0")/.." && pwd)
build="${TMPDIR:-/tmp}/c-piscine-architectures"
rm -rf "$build"
mkdir -p "$build/64" "$build/32"

compile_architecture()
{
	flag="$1"; destination="$2"
	find "$root" -path "$root/reference" -prune -o -path "$root/tests" -prune \
		-o -name '*.c' -type f -print | while IFS= read -r source
	do
		name=$(printf '%s' "$source" | cksum | cut -d ' ' -f 1)
		cc -Wall -Wextra -Werror "$flag" -I"$(dirname "$source")" \
			-c "$source" -o "$destination/$name.o"
	done
}

compile_architecture -m64 "$build/64"
compile_architecture -m32 "$build/32"
expected=$(find "$root" -path "$root/reference" -prune -o \
	-path "$root/tests" -prune -o -name '*.c' -type f -print | wc -l)
objects64=$(find "$build/64" -name '*.o' -type f | wc -l)
objects32=$(find "$build/32" -name '*.o' -type f | wc -l)
[ "$objects64" -eq "$expected" ] && [ "$objects32" -eq "$expected" ]
printf 'Architecture compile: sources=%d 64-bit=%d 32-bit=%d PASS\n' \
	"$expected" "$objects64" "$objects32"
