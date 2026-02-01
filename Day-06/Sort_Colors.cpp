/*
=====================================
Problem: Sort Colors (LC #75)
=====================================

Problem Statement:
Given an array nums with n objects colored red, white, or blue, sort them
in-place so that objects of the same color are adjacent, with the colors
in the order red (0), white (1), and blue (2).

You must solve this problem without using the library's sort function.

Approach Used:
Dutch National Flag Algorithm
- Maintain three pointers: low, mid, and high.
- low represents the boundary for 0s, mid is the current element,
  and high represents the boundary for 2s.
- Traverse the array once and place elements in their correct positions
  using swaps.

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1)

Why This Approach?
The Dutch National Flag algorithm sorts the array in a single pass and
constant space, making it optimal for this problem.

Concepts Used:
Arrays, Two Pointers, In-place Sorting

Problem Link:
https://leetcode.com/problems/sort-colors/
=====================================
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {//O(n)
        int n = nums.size();
        int low =0, mid = 0, high = n-1;

        while(mid <= high) {
            if(nums[mid] ==0) {
                swap(nums[low], nums[mid]);
                mid++; low++;
            } else if(nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
  
    }
};
