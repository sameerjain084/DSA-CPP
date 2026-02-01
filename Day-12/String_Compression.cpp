/*
=====================================
Problem: String Compression (LC #443)
=====================================

Problem Statement:
Given an array of characters chars, compress it using the following algorithm:
- Begin with an empty string s.
- For each group of consecutive repeating characters:
  - Append the character to s.
  - If the group’s length is greater than 1, append the length.
The compressed string s should not be returned separately but stored in the
input character array chars.

Return the new length of the array.

Approach Used:
Two Pointers with In-place Modification
- Traverse the array to count consecutive repeating characters.
- Write the character and its count (if > 1) at the correct index.
- Use an index pointer to track the position for writing compressed characters.
- Resize the array to the final compressed length.

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1)

Why This Approach?
This method compresses the string in-place without using extra space,
making it efficient and optimal as required by the problem.

Concepts Used:
Arrays, Two Pointers, String Manipulation

Problem Link:
https://leetcode.com/problems/string-compression/
=====================================
*/


class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;

        for(int i=0; i<n; i++) {
            char ch = chars[i];
            int count = 0;

            while(i < n && chars[i] == ch) {
                count++; i++;
            }  

            if(count == 1) {
                chars[idx++] = ch;
            } else {
                chars[idx++] = ch;
                string str = to_string(count) ;
                for(char dig : str) {
                    chars[idx++] = dig;
                }
            }

            i--;
        } 

        chars.resize(idx) ;
        return idx;
    }
};
