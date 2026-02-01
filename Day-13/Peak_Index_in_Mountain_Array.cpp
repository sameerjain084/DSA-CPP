/*
=================================================
Problem: Peak Index in a Mountain Array (LC #852)
=================================================

Problem Statement:
An array arr is a mountain array if:
- arr.length >= 3
- There exists some index i (0 < i < arr.length - 1) such that:
  arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
  arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given a mountain array arr, return the index i of the peak element.

Approach Used:
Binary Search on Mountain Array
- Perform binary search between indices 1 and n-2.
- Check if the middle element is greater than both neighbors.
- If the slope is increasing, move to the right half.
- If the slope is decreasing, move to the left half.

Complexity Analysis:
Time Complexity: O(log n)
Space Complexity: O(1)

Why This Approach?
A mountain array has a single peak. Binary search efficiently finds the peak
by eliminating half of the search space at each step.

Concepts Used:
Arrays, Binary Search

Problem Link:
https://leetcode.com/problems/peak-index-in-a-mountain-array/
=================================================
*/


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int st = 1;
        int end = A.size() - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
                return mid;
            } 
            else if (A[mid] < A[mid + 1]) { // increasing slope
                st = mid + 1;
            } 
            else { // decreasing slope
                end = mid - 1;
            }
        }
        return -1;
    }
};
