//rotating an array by D places.
#include <bits/stdc++.h>
using namespace std;
//BRUTEFORCE SOLUTION

// void rotate(int arr[], int n, int d){
//     d = d%n;
//     //putting d places elements into temp
//     int temp[d];
//     for(int i=0;i<d;i++){
//         temp[i] = arr[i];
//     }

//     //shifting rest elements to left
//     for(int i=d;i<n;i++){
//         arr[i-d] = arr[i];
//     }

//     //putting temp to last
//     int j = 0;
//     for(int i=n-d; i<n; i++){
//         arr[i] = temp[j];
//         j++;
//     }
// }

//OPTIMAL SOLUTION
void rotate(int arr[],int n, int d){
    reverse(arr, arr+d);      //starting se d places element ko reverse
    reverse(arr+d, arr+n);    //d se last tak ke element ko reverse
    reverse(arr, arr+n);      //and now reverse the entire array
}

int main(){
    int n;
    cin>>n;
    int d;
    cin>>d;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rotate(arr,n,d);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return  0;
}