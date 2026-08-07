#!/bin/sh

set -eu

root=$(CDPATH= cd -- "$(dirname "$0")/../.." && pwd)
cd "$root"

norminette_bin=${NORMINETTE:-"$HOME/.local/bin/norminette"}
"$norminette_bin" Exam/Level00 Exam/Level01 Exam/Level02 \
	Exam/Level03 Exam/Level04 Exam/Level05
sh Exam/tests/run.sh
sh Exam/tests/functional.sh
sh Exam/tests/memory.sh
sh Exam/tests/audit.sh

printf 'Quality gate: PASS\n'
