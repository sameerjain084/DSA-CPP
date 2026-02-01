Problem Statement:

Given an array height where each element represents the height of a vertical line drawn at that index, find two lines that together with the x-axis form a container such that the container holds the maximum amount of water.
You may not slant the container.

Approach Used:

Two Pointer Technique
Initialize two pointers at the beginning and end of the array.
Move the pointer pointing to the smaller height to maximize the area.
Repeat until both pointers meet.

Complexity Analysis: 

Time Complexity: O(n)
Space Complexity: O(1)

Why This Approach?

The two-pointer approach efficiently reduces the search space and avoids unnecessary comparisons, making it optimal compared to the brute-force O(n²) solution.

Problem Link:

LeetCode — Container With Most Water (Problem #11)

🧠 Concepts Used:

Arrays
Two Pointers
Greedy Strategy
