# Sorting Base Case Benchmarks

This repository contains preliminary benchmarks comparing `std::sort`
and insertion sort for small to moderate array sizes. The goal is to
study base-case behavior, reproducibility, and motivate hybrid sorting
algorithms.

## Experimental Setup
- Language: C++
- Compiler: MSVC
- Build mode: Release
- Platform: Windows
- Timing: `std::chrono::high_resolution_clock`
- Data: Random integer arrays

## Results
Insertion sort consistently outperformed or closely matched `std::sort`
for array sizes up to N ≈ 200. The performance gap narrowed near this
point, suggesting a delayed crossover due to constant-factor overhead in
`std::sort`.

## Motivation
These observations motivate:
- principled threshold selection in hybrid sorting algorithms
- reproducibility studies across compilers and platforms
- integration of optimized base-case routines

## Next Steps
- Implement hybrid MergeSort / QuickSort using insertion sort as base case
- Perform compiler-level reproducibility experiments (MSVC vs GCC/Clang)
- Study AI-optimized base cases (e.g., AlphaDev-style primitives)
