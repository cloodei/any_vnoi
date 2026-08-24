---
name: cp-explain-problem
description: Explain competitive programming problems and solutions from an attached PDF, image, written statement, or existing code with precise statement interpretation, motivated reasoning, correctness, complexity, and approachable teaching. Use for walkthroughs, editorial-style explanations, or understanding why a solution works; use cp-solve-problem when implementation is the primary deliverable.
---

# Explain a Competitive Programming Problem

Create an accurate, self-contained explanation that teaches both what the problem demands and how the solution is discovered. Optimize for understanding without sacrificing rigor.

## Recover the exact problem

Read every supplied artifact. For PDFs, extract text and inspect rendered pages wherever layout, mathematics, diagrams, or OCR may be significant. For images, inspect at sufficient resolution. Reconcile the statement with samples; never infer the contract solely from a title, known problem, or existing implementation.

Surface any ambiguity that affects the solution. Attempt better extraction first, then ask for missing information if different interpretations require different algorithms. Clearly label any harmless assumption.

## Explain the statement first

Before discussing an algorithm, restate in plain language:

- what objects the input describes;
- what must be produced or optimized;
- every condition the output must satisfy;
- the role of each constraint;
- what one representative sample is doing step by step.

Define unfamiliar terms and notation at first use. Separate facts given by the problem from conclusions derived by the solver. For constructive problems, distinguish “find any valid object” from optimization or uniqueness.

## Develop the idea, not just the answer

Build the reasoning in useful increments:

1. Start from direct observations and small examples.
2. Show why the constraints make obvious approaches too slow or insufficient when that comparison is informative.
3. Introduce each technique at the moment it becomes useful. Explain what it is, the intuition behind it, and the exact role it plays here.
4. State the invariant, recurrence, greedy choice, graph interpretation, or structural lemma precisely.
5. Connect that idea to implementable steps.

Avoid a fake autobiographical chain of thought. Present a concise, teachable derivation: the observations a contestant can verify and reuse. Expand prerequisite ideas when the audience may not know them, but do not bury the central solution under unrelated theory.

## Prove and analyze

Give a correctness argument matched to the method. Split it into small claims when helpful, and explicitly connect the claims to the required output. For greedy methods, justify the choice; for dynamic programming, define state and transitions; for constructions, prove every property and impossibility boundary.

Derive time and auxiliary-space complexity from the operations performed. Relate it back to the given bounds so the reader understands why it passes.

## Connect to code

If code exists, map its important variables and phases to the explanation and point out any mismatch with the statement. If the user requests code, provide or implement clean portable C++ following the target folder's `index.cpp` convention; otherwise do not edit files merely to explain them.

Use a small trace, table, or diagram only when it materially clarifies changing state or structure. Keep examples valid under the original constraints.

## Deliver

Make the explanation self-contained and easy to scan. A useful order is: problem in plain language, key observations, derived algorithm, correctness, complexity, worked example, and implementation notes. Adapt the depth to the user, but retain exact definitions, proof, and constraint-based complexity.
