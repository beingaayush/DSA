// Divide and Merge

#include <bits/stdc++.h>
using namespace std;

//Merging
void merge(vector<int> &arr, int low, int mid, int high){
    
    vector<int> temp;  //temporary array
    
    int left = low;
    int right = mid+1;
    
    //merge two halves
    while(left <= mid && right <= high){
      if(arr[left] <= arr[right]){
        temp.push_back(arr[left]);
        left++;
      }
      else{
        temp.push_back(arr[right]);
        right++;
      }  
    }
    // Copy remaining elements of left half
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    // Copy remaining elements of right half
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    // Copy back to original array
    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}


//Dividing
void mergeSort(vector<int> &arr, int low, int high){
    if(low == high) return;
    int mid = (low + high)/2 ;
    mergeSort(arr, low, mid);            //sort left half
    mergeSort(arr, mid + 1, high);      //sort right half
    merge(arr, low, mid, high);        //Merge both half
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);     // 0 = 1st idx, n-1 = last idx

    cout<<"sorted array = ";
    for(int x:arr) cout<< x <<" ";
    return  0;
}