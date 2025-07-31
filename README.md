# Technical Research

![Technical Research Logo](https://img.shields.io/badge/Technical%20Research-Algorithm%20Implementation-purple?style=for-the-badge&logo=code)

**Advanced Cross-Language Implementation of Fundamental Algorithms and Data Structures**

[![C++](https://img.shields.io/badge/C++-17+-00599C?style=flat&logo=cplusplus&logoColor=white)](https://isocpp.org)
[![Python](https://img.shields.io/badge/Python-3.10+-3776ab?style=flat&logo=python&logoColor=white)](https://python.org)
[![Java](https://img.shields.io/badge/Java-11+-ED8B00?style=flat&logo=openjdk&logoColor=white)](https://openjdk.org)
[![Go](https://img.shields.io/badge/Go-1.19+-00ADD8?style=flat&logo=go&logoColor=white)](https://golang.org)
[![License](https://img.shields.io/badge/License-MIT-green.svg?style=flat)](LICENSE)
[![Tests](https://img.shields.io/badge/Tests-Comprehensive-brightgreen?style=flat&logo=checkmarx)](https://github.com)

---

## 🌍 **Documentation / Documentação**

**📖 [🇺🇸 Read in English](README_EN.md)**  
**📖 [🇧🇷 Leia em Português](README_PT.md)**

---

## 🎯 What is Technical Research?

Technical Research is an **educational project** focused on the comprehensive implementation and deep understanding of fundamental algorithms and data structures across **four programming languages** (C++, Python, Java, Go). This project serves as a continuous learning journey to master computer science fundamentals.

### ⚡ Key Highlights

- 🌍 **Multilingual Implementation** - Same algorithms implemented in C++, Python, Java, and Go
- 🔬 **94+ Algorithms** - From basic sorting to advanced mathematical algorithms
- 📊 **12 Categories** - Complete coverage of CS fundamentals
- 🧪 **Extensive Testing** - Comprehensive test suites for all implementations
- 📈 **From Scratch** - Zero external library dependencies for core logic
- 🏗️ **Educational Focus** - Built for learning and skill development
- 🔄 **Continuous Development** - Ongoing expansion and refinement

### 🏆 What Makes It Special?

```
✅ 400+ individual implementations across 4 languages
✅ From-scratch implementations without library dependencies
✅ Comprehensive test coverage with edge cases
✅ Detailed complexity analysis and documentation
✅ Cross-language comparative learning approach
✅ Continuous learning and improvement focus
```

---

## ⚡ Quick Start

### Option 1: Clone and Explore
```bash
git clone https://github.com/thiagodifaria/technical-research.git
cd technical-research

# View project structure
tree -L 3
```

### Option 2: Test Specific Language
```bash
# C++ Tests
cd c++
mkdir build && cd build
cmake .. && make
./tests/fibonacci_pd_test

# Python Tests  
cd python
pytest tests/algoritmos_ordenacao/test_quick_sort.py

# Java Tests
cd java
mvn test -Dtest=QuickSortTest

# Go Tests
cd go
go test ./algoritmos_ordenacao/
```

### 🔥 Test It Now!
```bash
# Test the same algorithm across all languages
cd c++/build && ./tests/dijkstra_test
cd ../../python && python -m pytest tests/algoritmos_grafos/test_dijkstra.py -v
cd ../java && mvn test -Dtest=DijkstraTest
cd ../go && go test ./algoritmos_grafos/ -run TestDijkstra
```

---

## 🔍 Algorithm Categories

| Category | Count | Description |
|----------|-------|-------------|
| 🔢 **Sorting Algorithms** | 10 | Bubble, Quick, Merge, Heap, Insertion, etc. |
| 🔍 **Search Algorithms** | 3 | Binary Search, DFS, BFS |
| 🏗️ **Data Structures** | 15 | Trees, Hash Tables, Heaps, Tries, etc. |
| 📊 **Graph Algorithms** | 12 | Dijkstra, Floyd-Warshall, Prim, Kruskal, etc. |
| ⚡ **Dynamic Programming** | 11 | Fibonacci, Knapsack, LCS, Edit Distance, etc. |
| 🔤 **String Manipulation** | 11 | KMP, Rabin-Karp, Suffix Trees, etc. |
| 🧮 **Mathematical/Numerical** | 19 | FFT, Miller-Rabin, Number Theory, etc. |
| 🔀 **Bit Manipulation** | 3 | Bit counting, Power checks, etc. |
| 🔄 **Backtracking** | 5 | N-Queens, Sudoku Solver, etc. |
| 💾 **Common Patterns** | 1 | LRU Cache |
| 📐 **Computational Geometry** | 4 | Convex Hull, Closest Pair, etc. |
| 🌐 **Concurrency/Distributed** | 2 | Leader Election, Distributed Lock |

---

## 📊 Implementation Status

| Language | Sorting | Graphs | DP | Strings | Math | Overall |
|----------|---------|--------|----|---------|----- |---------|
| **C++** | ✅ 10/10 | ✅ 12/12 | ✅ 11/11 | ✅ 11/11 | ✅ 19/19 | **94/94** |
| **Python** | ✅ 10/10 | ✅ 12/12 | ✅ 11/11 | ✅ 11/11 | ✅ 19/19 | **94/94** |
| **Java** | ✅ 10/10 | ✅ 12/12 | ✅ 11/11 | ✅ 11/11 | ✅ 19/19 | **94/94** |
| **Go** | ✅ 5/10 | ✅ 8/12 | ✅ 6/11 | ✅ 3/11 | ✅ 6/19 | **28/94** |

---

## 🧪 Testing Overview

### Test Coverage by Language
- **C++**: Google Test framework with comprehensive edge cases
- **Python**: Pytest with parametrized testing and fixtures
- **Java**: JUnit 5 with extensive assertion coverage
- **Go**: Native testing package with table-driven tests

### Test Categories
```
✅ Edge cases (empty inputs, null values)
✅ Boundary testing (single elements, large datasets)
✅ Algorithmic correctness verification
✅ Performance validation
✅ Memory management testing
```

---

## 🚀 Run Tests

```bash
# Run all tests across all languages
./run_all_tests.sh

# Language-specific test execution
cd c++ && ./run_cpp_tests.ps1
cd python && ./run_python_tests.sh  
cd java && ./run_java_tests.sh
cd go && ./run_go_tests.sh
```

---

## 📈 Educational Goals

This project serves as a **continuous learning platform** to:

- **Master Algorithm Design**: Deep understanding of fundamental approaches
- **Compare Language Paradigms**: See how the same logic translates across languages
- **Practice Best Practices**: Industry-standard code organization and testing
- **Build Portfolio**: Demonstrate comprehensive CS knowledge
- **Improve Problem-Solving**: Tackle increasingly complex algorithmic challenges

---

## 🔧 Development Environment

### Prerequisites by Language
- **C++**: CMake 3.15+, GCC/Clang with C++17 support
- **Python**: Python 3.10+, pytest
- **Java**: JDK 11+, Maven 3.6+
- **Go**: Go 1.19+

### Recommended Tools
- **IDE**: VS Code with language extensions
- **Testing**: Each language's standard testing framework
- **Build**: Language-specific build tools (CMake, Maven, etc.)

---

## 📞 Contact

**Thiago Di Faria** - thiagodifaria@gmail.com

[![GitHub](https://img.shields.io/badge/GitHub-@thiagodifaria-black?style=flat&logo=github)](https://github.com/thiagodifaria)

---

### 🌟 **Star this project if you find it useful for learning!**

**Made with ❤️ for continuous learning and skill development**