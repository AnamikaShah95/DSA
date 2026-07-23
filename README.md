# ⚔️ Data Structures & Algorithms Mastery

<div align="center">

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-In_Progress-brightgreen?style=for-the-badge)
![Focus](https://img.shields.io/badge/Focus-Problem_Solving-orange?style=for-the-badge)

*Tracking my journey through core algorithms, interview patterns, and clean code principles.*

---

</div>

## 📌 Quick Navigation
- [🎯 Journey Goals](#-journey-goals)
- [🗺️ Topic Roadmap](#️-topic-roadmap)
- [📊 Problem Tracker](#-problem-tracker)
- [🧠 Key Takeaways & Cheat Sheet](#-key-takeaways--cheat-sheet)

---

## 🎯 Journey Goals
- [x] Set up topic-based repository structure
- [ ] Solve **100+** core interview problems
- [ ] Master fundamental patterns (Two Pointers, Sliding Window, Fast/Slow Pointers, etc.)
- [ ] Maintain consistent daily streak & progress updates

---

## 🗺️ Topic Roadmap

<details open>
<summary><b>📂 Core Topics Breakdown</b></summary>

| Topic | Status | Problems Solved | Key Concepts |
| :--- | :---: | :---: | :--- |
| **Two Pointers** | 🟡 In Progress | 1 | Opposite direction, Same direction, Fast/Slow |
| **Arrays & Hashing** | ⚪ Not Started | 0 | Prefix Sum, Frequency Maps |
| **Sliding Window** | ⚪ Not Started | 0 | Fixed size, Dynamic size |
| **Strings** | ⚪ Not Started | 0 | String manipulation, Pattern matching |
| **Recursion & Backtracking** | ⚪ Not Started | 0 | Subsets, Permutations |

</details>

---

## 📊 Problem Tracker

> 💡 *Click on the problem name for the question description, or the solution link for my C++ implementation.*

| ID | Problem | Topic | Difficulty | Solution | Key Concept |
| :-: | :--- | :--- | :-: | :-: | :--- |
| 0167 | [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | Two Pointers | 🟡 Medium | [C++](./Two-Pointers/TwoSum2_Sorted.cpp) | Opposite-end pointers to achieve $O(n)$ time |

---

## 🧠 Key Takeaways & Cheat Sheet

### 💡 Pattern: Two Pointers
* **When to use:** When dealing with sorted arrays/strings and searching for pairs, triplets, or sub-segments.
* **Core Logic:**
  * `sum == target`: Match found! Return result.
  * `sum < target`: Move left pointer rightward (`left++`) to increase the value.
  * `sum > target`: Move right pointer leftward (`right--`) to decrease the value.
* **Complexity Advantage:** Reduces a brute-force $O(n^2)$ nested loop down to $O(n)$ time complexity using $O(1)$ auxiliary space.

---

<div align="center">

⭐ **"Consistency is what transforms average into excellence."** ⭐  
*Feel free to explore the repository and connect on [LinkedIn](https://linkedin.com)!*

</div>