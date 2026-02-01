/*
===============================================
Problem: Product of Array Except Self (LC #238)
===============================================

Problem Statement:
Given an integer array nums, return an array answer such that answer[i] is equal
to the product of all the elements of nums except nums[i].

You must write an algorithm that runs in O(n) time and without using the
division operation.

Approach Used:
Prefix and Suffix Product
- Create an answer array initialized with 1.
- First pass (prefix):
  ans[i] stores the product of all elements to the left of index i.
- Second pass (suffix):
  Maintain a running suffix product and multiply it with ans[i].
- The result at each index is the product of prefix and suffix values.

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1) (excluding output array)

Why This Approach?
By separating the product calculation into prefix and suffix products, we avoid
using division and compute the result efficiently in linear time.

Concepts Used:
Arrays, Prefix Sum Technique, Suffix Product

Problem Link:
https://leetcode.com/problems/product-of-array-except-self/
===============================================
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n,1);
        // prefix 
        for(int i=1;i<n;i++) {
            ans[i]= ans[i-1]*nums[i-1];
        }
        // suffix
        int suffix = 1;
        for(int i=n-2;i>=0;i--){
            suffix*=nums[i+1];
            ans[i]*= suffix;// final answer
        }
        return ans;
    }
};
