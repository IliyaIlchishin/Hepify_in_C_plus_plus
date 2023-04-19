#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void heapify(int arr[], int heapSize, int rootIndex) {
    int largest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    if (leftChild < heapSize && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    if (rightChild < heapSize && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if (largest != rootIndex) {
        int temp = arr[rootIndex];
        arr[rootIndex] = arr[largest];
        arr[largest] = temp;
        heapify(arr, heapSize, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}



int* FillArray(int num) {
    
    int* random_array = new int[num];

    
    std::srand(std::time(nullptr));

    for (int i = 0; i < num; i++) {
        random_array[i] = std::rand();
    }

    return random_array;
}




int main() {
    int test_array[] = {12, 2, 1688, 325, 11, 13, 5, 48, 325, 5346,92,825, 92, 6, 7};
    int n = sizeof(test_array) / sizeof(test_array[0]);

    heapSort(test_array, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << test_array[i] << " ";
    }
    cout << endl;

    return 0;
}

