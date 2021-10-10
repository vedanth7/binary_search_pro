
?
Related Articles
Program to check if a given number is Lucky (all digits are different)
Lucky Numbers
Write a program to add two numbers in base 14
Babylonian method for square root
Square root of an integer
Find square root of number upto given precision using binary search
Binary Search
Linear Search
Linear Search vs Binary Search
Interpolation search vs Binary search
Interpolation Search
Exponential Search
Why is Binary Search preferred over Ternary Search?
Ternary Search
Stooge Sort
Python Program for Stooge Sort
Python Program for Insertion Sort
Python Program for Selection Sort
Python Program for Bubble Sort
Bubble Sort
Merge Sort
QuickSort
Maximum and minimum of an array using minimum number of comparisons
Count Inversions in an array | Set 1 (Using Merge Sort)
Program for Tower of Hanoi
Write a program to calculate pow(x,n)
Divide and Conquer Algorithm | Introduction
Median of two sorted arrays of same size
Median of two sorted arrays of different sizes

Binary Search
Difficulty Level : Easy
Last Updated : 28 Jun, 2021
Given a sorted array arr[] of n elements, write a function to search a given element x in arr[].
A simple approach is to do a linear search. The time complexity of the above algorithm is O(n). Another approach to perform the same task is using Binary Search. 
Binary Search: Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise, narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.
 

Example : 

Attention reader! Don’t stop learning now. Get hold of all the important DSA concepts with the DSA Self Paced Course at a student-friendly price and become industry ready.  To complete your preparation from learning a language to DS Algo and many more,  please refer Complete Interview Preparation Course.

In case you wish to attend live classes with experts, please refer DSA Live Classes for Working Professionals and Competitive Programming Live for Students.



The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(Log n). 

Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution. 
 
We basically ignore half of the elements just after one comparison.

Compare x with the middle element.
If x matches with the middle element, we return the mid index.
Else If x is greater than the mid element, then x can only lie in the right half subarray after the mid element. So we recur for the right half.
Else (x is smaller) recur for the left half.
Recursive implementation of Binary Search 


// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;
  
// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
  
         
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        // Else the element can only be present
    
        return binarySearch(arr, mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}
  
int main(void)
{
     
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}