// Push the max element to the last
// compares adjacent elements, if they're in wrong order - just swap them
// Outer loop → controls passes (pushes biggest element to end).
// Inner loop → compares and swaps neighbors.
// Swap → moves the larger number forward.
// we use optimization here coz in bubbleSort "sorted array" hone k baad v loop run krta h

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;  // optimization
        for (int j = 0; j < n-i-1; j++) { // last i elements are already sorted
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break; // stop if no swaps in inner loop (stop if all sorted)
    }
}


int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
