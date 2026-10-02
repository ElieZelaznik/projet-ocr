# OCR Word Search Solver — Work Plan

This plan breaks the project into four parts and schedules regular check-ins.
All check-ins are proposed for **17:00 Europe/Paris time**.

The project brief sets the first Git snapshot for **Friday 30 October 2026
at 20:00**, the final Git snapshot for **Friday 11 December 2026 at 20:00**,
the first defense during the **week of 2 November**, and the final defense
during the **week of 14 December**.

## Part 1 — First-defense MVP

**Dates:** 2–30 October 2026

**Work**

- Set up the C project, team responsibilities, interfaces, and Git workflow.
- Implement image loading, grayscale conversion, and manual rotation.
- Detect the grid, word list, and character regions; save extracted
  character images.
- Implement the command-line `solver` and its required input/output format.
- Build a neural-network proof of concept for the required Boolean function.
- Prepare a demonstration of all required first-defense elements.

**Check-ins**

- **Friday 9 October, 17:00:** agree interfaces, test images, and task owners.
- **Friday 16 October, 17:00:** review image loading, grayscale/manual
  rotation, and the solver.
- **Friday 23 October, 17:00:** review detection, character extraction, and
  the neural-network proof of concept together.
- **Friday 30 October, 17:00:** rehearse the first-defense demo and verify
  the release. Git snapshot at **20:00**.

## Part 2 — Preprocessing and OCR

**Dates:** 2–20 November 2026

**Work**

- Incorporate feedback from the first defense and re-confirm priorities.
- Complete preprocessing: automatic rotation, noise removal, and contrast
  enhancement.
- Complete neural-network training and character recognition for both grid
  letters and word-list letters.
- Test OCR independently using prepared character images as well as images
  from the end-to-end workflow.

**Check-ins**

- **Friday 6 November, 17:00:** review first-defense feedback and revised
  priorities.
- **Friday 13 November, 17:00:** demonstrate preprocessing and OCR progress
  on sample images.
- **Friday 20 November, 17:00:** acceptance check for preprocessing and the
  learning/recognition flow.

## Part 3 — End-to-end application

**Dates:** 23 November–4 December 2026

**Work**

- Reconstruct the character grid and word list from OCR results.
- Connect the reconstructed data to the solver.
- Display the solved grid with hidden words marked and save the result as a
  standard image.
- Integrate the required graphical interface so users can load, view,
  correct, solve, and save an image through one coherent workflow.

**Check-ins**

- **Friday 27 November, 17:00:** demonstrate a complete pipeline on at least
  one non-trivial image.
- **Friday 4 December, 17:00:** feature-complete review of the GUI, solved
  grid, and saved output.

## Part 4 — Stabilization and final delivery

**Dates:** 7–14 December 2026

**Work**

- Fix integration and reliability issues; test against examples at different
  image difficulty levels.
- Verify the project builds in the school's environment with `-Wall -Wextra`.
- Check repository contents and prepare the report, defense outline, and
  final demonstration.
- Freeze and verify the `master` branch before the final Git snapshot.

**Check-ins**

- **Wednesday 9 December, 17:00:** release-candidate tests and final-demo
  rehearsal.
- **Friday 11 December, 17:00:** final acceptance check and branch freeze.
  Git snapshot at **20:00**.
- **Week of 14 December:** final defense.

## Ongoing review checklist

At every check-in, confirm what can be demonstrated, remaining blockers,
owners and due dates for next steps, and that the latest code is committed
and builds. Keep integrating components throughout the project rather than
waiting until the end.

For the four-person team, assign leads for image processing/detection, neural
network, solver, and GUI/integration/testing. Review the handoffs together.
Maintain the project constraints throughout: C implementation, English
identifiers and comments, maximum 80-character lines, and no executables or
unnecessary files in the repository.
