// reverse an array using recursion (by one variable)
#include <bits/stdc++.h>
using namespace std;

void fn(int i, int arr[], int n){
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    fn(i+1,arr,n);
}

int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    fn(0,arr,n);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    return  0;
}

// Another Code (more simple and suitable)
#include <bits/stdc++.h>
using namespace std;

void reverseArr(int arr[], int left, int right) {
    if(left >= right) return;  //stop where both pointers meet

    swap(arr[left], arr[right]);
    reverseArr(arr, left + 1, right - 1);
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    reverseArr(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
