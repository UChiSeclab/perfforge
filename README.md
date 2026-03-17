# PERFFORGE: An Effective Performance-Stressing Benchmark for Improving Code Efficiency

PERFFORGE is a benchmark of performance-stressing test cases for a subset of AlphaCode's [CodeContests](https://www.science.org/doi/abs/10.1126/science.abq1158) problems. The dataset was created with [WEDGE](https://github.com/UChiSeclab/wedge), an LLM-guided fuzzing framework for synthesizing inputs that expose performance bottlenecks in a program under test.

This repository is intended to support evaluation of code efficiency, performance-aware code generation, and optimization techniques. For methodology and experimental details, see our NeurIPS 2025 [paper](https://openreview.net/forum?id=Qh458ZamHm).

## What is in this repository?

The `main` branch contains the released benchmark dataset. In this checkout, the repository includes 207 problems and is large (about 51 GiB), so plan disk usage accordingly.

Each problem directory contains:

- `full_tests/`: the released input/output test set for the problem.
- `slow_tests/`: per-solution subsets of inputs that were observed to stress specific AlphaCode-generated C/C++ solutions.
- `metadata/`: the original problem statement plus sampled artifacts from WEDGE's constraint-synthesis process.

## Repository layout

```text
perfforge_new/
├── problems/
│   ├── 40_B/
│   │   ├── full_tests/
│   │   │   ├── input/
│   │   │   └── output/
│   │   ├── slow_tests/
│   │   │   └── solutions_0001/
│   │   │       ├── input/
│   │   │       ├── output/
│   │   │       ├── mapping.json
│   │   │       └── solutions_0001.cpp
│   │   └── metadata/
│   │       ├── problem_statement.txt
│   │       └── synthesized_constraints/
│   │           └── solutions_0001/
│   │               └── private_tests_057_generated_tests_054/
│   │                   ├── conversations.txt
│   │                   ├── gpt_response.txt
│   │                   └── transformed_program.cpp
├── README.md
└── LICENSE
```

## Per-problem contents

### `full_tests/`

`full_tests/input/` contains released test inputs and `full_tests/output/` contains the corresponding ground-truth outputs.

### `slow_tests/`

Each `slow_tests/solutions_xxxx/` directory is centered on one AlphaCode-generated solution that was meaningfully stressed by synthesized tests. These directories contain:

- `solutions_xxxx.cpp`: the specific solution source file.
- `input/` and `output/`: the stressing test cases and their expected outputs for that solution.
- `mapping.json`: provenance and ranking metadata for each released stressing test, including the original generated filename, measured mean runtime, and its rank among selected slow tests.

### `metadata/`

Each problem's `metadata/` directory contains:

- `problem_statement.txt`: the original problem statement.
- `synthesized_constraints/.../conversations.txt`: prompt/interaction traces used during constraint synthesis.
- `synthesized_constraints/.../gpt_response.txt`: the model-generated constraint description or related artifact.
- `synthesized_constraints/.../transformed_program.cpp`: the constraint-augmented program variant used in the synthesis workflow.

## NeurIPS 2025 evaluation data

The raw data used for the paper's evaluation against other performance-test generation tools is provided on the `neurips25-eval` branch.

## Citation

```bibtex
@inproceedings{
    yang-neurips25,
    title={Synthesizing Performance Constraints for Evaluating and Improving Code Efficiency},
    author={Jun Yang and Cheng-Chi Wang and Bogdan Alexandru Stoica and Kexin Pei},
    booktitle={The Thirty-ninth Annual Conference on Neural Information Processing Systems},
    year={2025},
    url={https://openreview.net/forum?id=Qh458ZamHm}
}
```
