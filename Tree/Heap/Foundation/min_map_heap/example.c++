// ====================== HEAP (Max Heap + Min Heap) ======================
// Heap is a Complete Binary Tree stored inside an array/vector.
//
// Index Formula:
// Parent = (i - 1) / 2
// Left Child = 2 * i + 1
// Right Child = 2 * i + 2
//
// Time Complexity:
// Insert      -> O(log n)
// Delete Root -> O(log n)
// Peek        -> O(1)
// Build Heap  -> O(n)
// ========================================================================

#include <iostream>
#include <vector>
using namespace std;

// ======================= MAX HEAP =======================

class MaxHeap {
    vector<int> heap;

public:

    // Build Heap (Insert all elements one by one)
    void buildHeap(vector<int> arr) {
        for (int x : arr)
            insert(x);
    }

    // Insert new element (Heapify Up)
    void insert(int val) {
        heap.push_back(val);

        int i = heap.size() - 1;

        while (i > 0) {
            int parent = (i - 1) / 2;

            if (heap[parent] < heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
                break;
        }
    }

    // Delete Root (Maximum Element)
    void deleteRoot() {

        if (heap.empty())
            return;

        heap[0] = heap.back();
        heap.pop_back();

        int i = 0;

        while (true) {

            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < heap.size() && heap[left] > heap[largest])
                largest = left;

            if (right < heap.size() && heap[right] > heap[largest])
                largest = right;

            if (largest == i)
                break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    // Returns maximum element
    int top() {
        return heap[0];
    }

    // Display Heap
    void print() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

// ======================= MIN HEAP =======================

class MinHeap {
    vector<int> heap;

public:

    // Build Heap
    void buildHeap(vector<int> arr) {
        for (int x : arr)
            insert(x);
    }

    // Insert (Heapify Up)
    void insert(int val) {

        heap.push_back(val);

        int i = heap.size() - 1;

        while (i > 0) {

            int parent = (i - 1) / 2;

            if (heap[parent] > heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
                break;
        }
    }

    // Delete Root (Minimum Element)
    void deleteRoot() {

        if (heap.empty())
            return;

        heap[0] = heap.back();
        heap.pop_back();

        int i = 0;

        while (true) {

            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < heap.size() && heap[left] < heap[smallest])
                smallest = left;

            if (right < heap.size() && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i)
                break;

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

    // Returns minimum element
    int top() {
        return heap[0];
    }

    // Display Heap
    void print() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

// ======================= DRIVER CODE =======================

int main() {

    vector<int> arr = {40, 10, 30, 50, 60, 15};

    // ---------- MAX HEAP ----------
    MaxHeap maxH;

    maxH.buildHeap(arr);       // Build Heap
    maxH.insert(100);          // Insert
    maxH.deleteRoot();         // Delete Maximum

    cout << "Max Heap : ";
    maxH.print();

    cout << "Top : " << maxH.top() << endl << endl;


    // ---------- MIN HEAP ----------
    MinHeap minH;

    minH.buildHeap(arr);       // Build Heap
    minH.insert(5);            // Insert
    minH.deleteRoot();         // Delete Minimum

    cout << "Min Heap : ";
    minH.print();

    cout << "Top : " << minH.top() << endl;
}