/*
======================================================
Problem: Single Element in a Sorted Array (LC #540)
======================================================

Problem Statement:
You are given a sorted array consisting of only integers where every element
appears exactly twice, except for one element which appears exactly once.
Find this single element and return it.

You must write an algorithm that runs in O(log n) time and O(1) space.

Approach Used:
Binary Search with Index Parity
- Use binary search on the sorted array.
- Check if the middle element is the unique one by comparing neighbors.
- Use index parity (even/odd index) to determine which half of the array
  contains the single element.
- Eliminate half of the search space at each step.

Complexity Analysis:
Time Complexity: O(log n)
Space Complexity: O(1)

Why This Approach?
In a sorted array, pairs occupy predictable index positions.
Using index parity allows us to identify the side where the pairing breaks,
making binary search possible in logarithmic time.

Concepts Used:
Arrays, Binary Search, Index Parity

Problem Link:
https://leetcode.com/problems/single-element-in-a-sorted-array/
======================================================
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
           int n= A.size();
        if(n==1) return A[0];// corner case if arr is of size 1.
        int st=0,end=n-1;
        while(st<=end) {
            int mid = st+(end-st)/2;

            if(mid==0 && A[0]!=A[1]) return A[mid];// corner case if 1 element is unique.
            if(mid==n-1 && A[n-1!=A[n-2]]) return A[mid];// corner case if last element is unique.

            if(A[mid-1]!=A[mid] && A[mid]!=A[mid+1]) return A[mid];

            if(mid %2 ==0) {//even case
                if(A[mid-1]==A[mid]) {// left
                    end = mid-1;
                }else{// right
                    st = mid+1;
                }
            } else { // odd case
                if(A[mid-1]==A[mid]) {// right
                    st = mid+1;
                }else {//left
                    end = mid-1;
                }
            }
        }

        return -1;
        
    }
};
