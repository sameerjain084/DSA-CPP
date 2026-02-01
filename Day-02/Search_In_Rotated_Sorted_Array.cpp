/*
==============================================
Problem: Search in Rotated Sorted Array (LC #33)
==============================================

Problem Statement:
You are given an integer array A sorted in ascending order and rotated at some
unknown pivot. Given a target value tar, return its index if it exists in the
array; otherwise, return -1.

You must write an algorithm with O(log n) time complexity.

Approach Used:
Modified Binary Search
- Use binary search to find the middle element.
- Determine which half of the array is sorted.
- If the left half is sorted, check whether the target lies within it.
- Otherwise, the right half must be sorted.
- Narrow down the search space accordingly.
- Repeat until the target is found or the search space is exhausted.

Complexity Analysis:
Time Complexity: O(log n)
Space Complexity: O(1)

Why This Approach?
Even after rotation, at least one half of the array remains sorted.
By identifying the sorted half at each step, we can apply binary search
efficiently and achieve logarithmic time complexity.

Concepts Used:
Arrays, Binary Search, Divide and Conquer

Problem Link:
https://leetcode.com/problems/search-in-rotated-sorted-array/
==============================================
*/

class Solution {
public:
    int search(vector<int>& A, int tar) {
        int st = 0, end = A.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (A[mid] == tar) {
                return mid;
            }

            // Left half sorted
            if (A[st] <= A[mid]) {
                if (A[st] <= tar && tar <= A[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }
            // Right half sorted
            else {
                if (A[mid] <= tar && tar <= A[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};
