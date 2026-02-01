/*
===========================================
Problem: Container With Most Water (LC #11)
===========================================

Problem Statement:
Given an array height where each element represents the height of a vertical
line drawn at that index, find two lines that together with the x-axis form
a container such that the container holds the maximum amount of water.
You may not slant the container.

Approach Used:
Two Pointer Technique
- Initialize two pointers at the beginning and end of the array.
- Calculate area using:
  area = min(height[left], height[right]) * (right - left)
- Move the pointer pointing to the smaller height.
- Repeat until both pointers meet.

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1)

Why This Approach?
The two-pointer approach efficiently reduces the search space and avoids
unnecessary comparisons, making it optimal compared to the brute-force O(n²) solution.

Concepts Used:
Arrays, Two Pointers, Greedy Strategy

Problem Link:
https://leetcode.com/problems/container-with-most-water/
===========================================
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0, rp = height.size() - 1;
        int maxArea = 0;

        while (lp < rp) {
            int width = rp - lp;
            int ht = min(height[lp], height[rp]);
            maxArea = max(maxArea, width * ht);

            if (height[lp] < height[rp])
                lp++;
            else
                rp--;
        }
        return maxArea;
    }
};
