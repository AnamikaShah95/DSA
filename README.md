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

---

## 🎯 Journey Goals
- [x] Set up topic-based repository structure
- [x] Master **Two Pointers** pattern (7 problems solved!)
- [ ] Solve **100+** core interview problems
- [ ] Master fundamental patterns (Sliding Window, Fast & Slow Pointers, Prefix Sum, etc.)
- [ ] Maintain consistent daily streak & progress updates
---

## 🗺️ Topic Roadmap

<details open>
<summary><b>📂 Core Topics Breakdown</b></summary>

| Topic | Status | Problems Solved | Key Concepts |
| :--- | :---: | :---: | :--- |
| **Two Pointers** | 🟢 Completed | 7 | Opposite direction, Same direction, Dutch National Flag, Triplets |
| **Sliding Window** | 🟢 Completed | 8 | Fixed window, Dynamic window |
| **Arrays & Hashing** | 🟡 In Progress | 1 | Prefix Sum, Frequency Maps |
| **Fast & Slow Pointers** | 🟢 Completed  | 5 | Cycle detection (Floyd's algorithm) |
| **Recursion & Backtracking** | ⚪ Not Started | 0 | Subsets, Permutations |

</details>

---

## 📊 Problem Tracker

> 💡 *Click on the problem name for the question description, or the solution link for my C++ implementation.*

| ID | Problem | Topic | Difficulty | Solution | Key Concept |
| :-: | :--- | :--- | :-: | :-: | :--- |
| 0167 | [Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | Two Pointers | 🟡 Medium | [C++](./Two-Pointers/TwoSum2_Sorted.cpp) | Opposite-end pointers |
| 0026 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | Two Pointers | 🟢 Easy | [C++](./Two-Pointers/RemoveDuplicatesFromSortedArray.cpp) | Slow & fast two pointers |
| 0080 | [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | Two Pointers | 🟡 Medium | [C++](./Two-Pointers/RemoveDuplicatesFromSortedArray2.cpp) | Two pointers comparing with `i - 2` |
| 0977 | [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/) | Two Pointers | 🟢 Easy | [C++](./Two-Pointers/SquaresOfASortedArray.cpp) | Two pointers, filling result from end |
| 0015 | [3Sum](https://leetcode.com/problems/3sum/) | Two Pointers | 🟡 Medium | [C++](./Two-Pointers/ThreeSum.cpp) | Sort + fixed element with two pointers |
| 0016 | [3Sum Closest](https://leetcode.com/problems/3sum-closest/) | Two Pointers | 🟡 Medium | [C++](./Two-Pointers/ThreeSumClosest.cpp) | Sort + track minimum absolute difference |
| 0075 | [Sort Colors](https://leetcode.com/problems/sort-colors/) | Two Pointers | 🟡 Medium | [C++](./Two-Pointers/SortColors.cpp) | Dutch National Flag algorithm (3 pointers) |
| GFG | [Count Triplets with Sum Smaller than X](https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1) | Two Pointers | 🟡 Medium | [C++](./Two-Pointers/CountTripletsWithSumSmallerThanX.cpp) | Two pointers, add `(k - j)` combinations |
| GFG | [Max Sum Subarray of Size K](https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1) | Sliding Window | 🟢 Easy | [C++](./Sliding-Window/MaxSumSubarraySizeK.cpp) | Fixed window: add incoming, subtract outgoing |
| 0209 | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) | Sliding Window | 🟡 Medium | [C++](./Sliding-Window/MinimumSizeSubarraySum.cpp) | Variable window: expand right, shrink left |
| GFG | [Longest Substring with K Unique Characters](https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1) | Sliding Window | 🟡 Medium | [C++](./Sliding-Window/LongestKSubstr.cpp) | Variable window + hash map frequency count |
| 0904 | [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/) | Sliding Window | 🟡 Medium | [C++](./Sliding-Window/FruitIntoBaskets.cpp) | Variable window: at most 2 distinct elements |
| 0003 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | Sliding Window | 🟡 Medium | [C++](./Sliding-Window/LongestSubstringWithoutRepeatingCharacters.cpp) | Variable window: shrink when `f.size() < len`
| 0424 | [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) | Sliding Window | 🟡 Medium | [C++](./Sliding-Window/CharacterReplacement.cpp) | Variable window: `window_len - max_freq <= k` |
| 0076 | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | Sliding Window | 🔴 Hard | [C++](./Sliding-Window/MinimumWindowSubstring.cpp) | Variable window: expand until valid, shrink left to minimize |
| 0141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) | Fast & Slow Pointers | 🟢 Easy | [C++](./Fast-Slow-Pointers/LinkedListCycle.cpp) | Floyd's cycle detection algorithm |
| 0876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) | Fast & Slow Pointers | 🟢 Easy | [C++](./Fast-Slow-Pointers/MiddleOfTheLinkedList.cpp) | Slow moves 1 step, fast moves 2 steps |
| 0142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/) | Fast & Slow Pointers | 🟡 Medium | [C++](./Fast-Slow-Pointers/LinkedListCycle2.cpp) | Reset `slow` to `head`, move both 1 step to find cycle entry |
| 0287 | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) | Fast & Slow Pointers | 🟡 Medium | [C++](./Fast-Slow-Pointers/FindTheDuplicateNumber.cpp) | Treat array as linked list, Floyd's cycle detection |
| 0202 | [Happy Number](https://leetcode.com/problems/happy-number/) | Fast & Slow Pointers | 🟢 Easy | [C++](./Fast-Slow-Pointers/HappyNumber.cpp) | Detect implicit sequence cycle via digit square sums |
| 1004 | [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | Sliding Window | 🟡 Medium | [C++](./Sliding-Window/MaxConsecutiveOnes3.cpp) | Variable window: allow at most `k` zeros in current window |
| 0053 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | Arrays & Hashing | 🟡 Medium | [C++](./Arrays-Hashing/MaximumSubarray.cpp) | Kadane's Algorithm: `max(nums[i], bestending + nums[i])` |

---


<div align="center">

⭐ **"Consistency is what transforms average into excellence."** ⭐  
*Feel free to explore the repository and connect on [LinkedIn](https://linkedin.com)!*

</div>