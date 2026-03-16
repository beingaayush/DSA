// Problem Statement:- (Book Allocation)
// Given an array arr[] of size N, where each element represents the number of pages in a book.
// You are also given M students.

// Your task is to allocate books to students such that:
// > Each student gets at least one book.
// > Each book is allocated to only one student.

// Books must be allocated in contiguous order.
// The goal is to minimize the maximum number of pages assigned to a student.
// Return the minimum possible value of the maximum pages assigned to any student.
// If allocation is not possible (i.e., students > books), return -1.

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int countStudents(vector<int> &arr, int pages){
            int cntStudents = 1;
            long long pagesStudent = 0;
            for(int i=0; i<arr.size(); i++){
                if(pagesStudent + arr[i] <= pages){
                    pagesStudent += arr[i];
                }
                else{
                    cntStudents++;
                    pagesStudent = arr[i];
                }
            }
            return cntStudents;
        }
        int findPages(vector<int> &arr, int n, int m){
            if(m > n) return -1;
            int low = *max_element(arr.begin(), arr.end());
            int high = accumulate(arr.begin(), arr.end(), 0);

            while(low <= high){
                int mid = (low + high)/2;
                int students = countStudents(arr, mid);

                if(students > m){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            return low;
        }
};