#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index

    //If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    //If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    //If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap the elements

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

//Heap Sort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    //Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    //Extract elements from the heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        //Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

//Function to print an array
void printArray(const vector<int>& myArr) {
    for (int i : myArr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> myArr = {100, 90, 55, 25, 15, 5,2};

    cout << "Original array: ";
    printArray(myArr);

    heapSort(myArr);

    cout << "Sorted array: ";
    printArray(myArr);

    return 0;
}
