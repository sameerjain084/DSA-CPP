/*
=====================================
Problem: Single Number (LC #136)
=====================================

Problem Statement:
Given a non-empty array of integers nums, every element appears twice except
for one. Find that single one.

You must implement a solution with linear runtime complexity and use only
constant extra space.

Approach Used:
Bit Manipulation (XOR)
- Initialize an answer variable with 0.
- XOR all elements of the array.
- Since a ^ a = 0 and a ^ 0 = a, all duplicate elements cancel out.
- The remaining value is the single number.

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1)

Why This Approach?
XOR naturally eliminates duplicate numbers and keeps the unique number,
making it the most optimal solution in terms of time and space.

Concepts Used:
Bit Manipulation, XOR Operation

Problem Link:
https://leetcode.com/problems/single-number/
=====================================
*/


class Solution {
public:
    int singleNumber(vector<int> &nums) {
     int ans =0 ;
     for(int val :nums) {
         ans=ans^val;
     }
     return ans;
    }
};
