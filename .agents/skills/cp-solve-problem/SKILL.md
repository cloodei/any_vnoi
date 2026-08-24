---
name: cp-solve-problem
description: Solve competitive programming problems from an attached PDF, image, or written statement by recovering the exact specification, deriving a correct efficient algorithm, implementing it in the repository's C++ style, and validating it. Use for implementation-first contest problem requests; use cp-explain-problem when the requested deliverable is primarily a tutorial or conceptual walkthrough.
---

# Solve a Competitive Programming Problem

Produce a submission-ready solution whose correctness and complexity follow from the actual statement, not from a guessed familiar problem.

## Establish the specification

Read every supplied statement artifact before coding. For a PDF, extract its text and inspect rendered pages when formulas, diagrams, subscripts, tables, or formatting may affect meaning. For images, inspect at sufficient resolution to recover all visible text. If the repository contains both a statement and existing code, treat the statement as the contract and the code as evidence only.

Write down, at least internally:

- the required output and the condition that makes it valid;
- all input bounds, including sums of bounds across test cases;
- indexing, ordering, distinctness, numeric range, and precision rules;
- sample behavior and any special or impossible cases.

Do not silently invent unreadable or absent constraints. Try alternate extraction or visual inspection first. If a missing detail can change the algorithm or correctness, ask for that detail; otherwise state the narrow assumption used.

## Derive before implementing

Identify the mathematical or algorithmic structure, then use the constraints to rule approaches in or out. Test the idea manually against samples, smallest valid inputs, boundary cases, and adversarial shapes. When a construction is required, prove every demanded property and prove that every claimed impossible case is impossible.

Prefer the simplest algorithm that comfortably satisfies the bounds. State the key invariant or exchange/induction argument and compute time and memory complexity before committing to code.

## Implement cleanly

Inspect the target folder and preserve its established language, standard, entry-point naming, and formatting. In this repository, default to portable contest C++ in the problem folder's `index.cpp` when that convention is present.

- Use fast I/O when input size warrants it.
- Choose types from proven numeric bounds; use wider intermediate types when multiplication or accumulation can overflow.
- Keep the implementation direct and submission-ready: no prompts, debug output, filesystem assumptions, or nonstandard dependencies unless the judge explicitly supports them.
- Use descriptive names for problem concepts. Add comments only for invariants or non-obvious reasoning, not line-by-line narration.
- Handle multiple test cases and output formatting exactly as specified.

Do not replace existing user work without inspecting it. Modify only the requested problem's files unless shared infrastructure is genuinely necessary.

## Validate

Compile with strict warnings using the repository's configured toolchain when available. Run all statement samples and compare exact output when the answer is unique; for constructive or non-unique output, validate the required properties instead of comparing to one sample arrangement.

Add focused edge cases. When practical, use a small brute-force oracle or property checker for randomized differential testing; keep such helpers temporary unless the user asks to retain tests. Distinguish compilation/sample checks from proof and from live judge acceptance.

## Deliver

Lead with the algorithm and result. Briefly include the correctness argument, complexity, changed file, and validations performed. Call out any unresolved statement ambiguity or unverified judge-specific assumption.
