# 42 Málaga — C and Systems Programming

An evidence-based learning portfolio of original exercises and projects completed while studying at 42 Málaga. The repository documents progression from C fundamentals to memory management, data structures, Unix interfaces, build tooling, and systematic testing.

## Progress map

| Area | Evidence | Concepts demonstrated | Status |
| --- | --- | --- | --- |
| C foundations | [`C03`–`C06`](C03) | Strings, numeric conversion, program arguments, and control flow | Complete |
| Dynamic memory | [`C07`](C07) | Allocation, ranges, string composition, and base conversion | Complete |
| Headers and structures | [`C08`](C08) | Macros, headers, structures, and modular interfaces | Complete |
| Libraries and build systems | [`C09`](C09) | Static libraries, Makefiles, and reusable utilities | Complete |
| Unix file I/O | [`C10`](C10) | File descriptors, `cat`, `tail`, and hexadecimal output | Complete |
| Linked data structures | [`C12`](C12) | List traversal, mutation, sorting, and ownership | Complete |
| Team algorithm project | [`Rush01`](Rush01/ex00) | Input validation, constraint solving, decomposition, and collaboration | Complete |
| Timed practice | [`Exam`](Exam) | Algorithms, defensive C, test harnesses, and memory checks | In progress |

Directories are added only when they contain legitimate work, so the repository itself remains the source of truth for progress.

## How the work is validated

The exam-practice suite provides functional, edge-case, architecture, quality, and memory checks:

```bash
git clone --recurse-submodules https://github.com/ME0094/42.git
cd 42
bash Exam/tests/run.sh
```

Individual projects include their own build or validation notes. For example, the Rush01 solver can be compiled with strict warnings:

```bash
cc -Wall -Wextra -Werror Rush01/ex00/*.c -o rush01
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

## Engineering approach

- Prefer small functions with explicit ownership and error behavior.
- Compile with strict warnings and test boundary conditions.
- Use Valgrind or sanitizers when dynamic memory is involved.
- Keep third-party references separate from original implementation.
- Record reasoning and validation, not only final answers.

Supporting material lives in [`docs/`](docs), including the learning plan and audit notes. Larger projects are indexed under [`projects/`](projects).

## Academic integrity and provenance

All solution code in this repository is original educational work. External prompts and reference material remain separated in the `Exam/reference` submodule and retain their original authorship and licenses. Nothing here is presented as official 42 material.

Public solutions should be consulted only after making and documenting an independent attempt. Restricted assessments, official solutions, credentials, grades, identity documents, and other students' work must never be committed.

AI may be used to explain concepts, interpret compiler errors, review code already written, or guide debugging through questions. It must not generate answers for assessed exercises, and every use remains subject to the stricter rules of the relevant 42 project.

## License

Original code is available under the [MIT License](LICENSE). Submodules and external references retain their respective licenses.
