/*
================================
Problem: Pow(x, n) (LC #50)
================================

Problem Statement:
Implement pow(x, n), which calculates x raised to the power n (xⁿ).

Approach Used:
Binary Exponentiation (Exponentiation by Squaring)
- Convert n into a long integer to handle edge cases.
- If n is negative, invert x and make n positive.
- Repeatedly square the base and multiply it to the answer when
  the current exponent bit is set.
- Reduce the exponent by half at each step.

Complexity Analysis:
Time Complexity: O(log n)
Space Complexity: O(1)

Why This Approach?
Binary exponentiation reduces the number of multiplications from O(n)
to O(log n), making it highly efficient for large values of n.

Concepts Used:
Binary Exponentiation, Bit Manipulation, Math

Problem Link:
https://leetcode.com/problems/powx-n/
================================
*/

class Solution {
public:
    double myPow(double x, int n) {
        long binaryform=n;
        if(n<0) {
            x=1/x;
            binaryform=-binaryform;
        }
        double ans=1;
        while(binaryform>0) {
            if(binaryform%2==1) {
                ans*=x;
            }
            x*=x;
            binaryform/=2;
        }
        return ans;
        
    }
};
