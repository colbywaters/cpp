#include <iostream>
#include <fstream>
#include "MaxHeap.h"

using namespace std;

/*
 * Build Max Heap data structure from array (private data).
 */
void MaxHeap::heapify(int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && arr[left] > arr[largest])
        largest = left;

    if (right <= size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(largest);
    }
}

/*
 * Build Max Heap data structure from array (private data).
 */
void MaxHeap::insert(int value) {
    if (size == MAX_SIZE)
        return;

    arr[++size] = value;
    int i = size;

    while (i > 1 && arr[i] > arr[i / 2]) {
        swap(arr[i], arr[i / 2]);
        i /= 2;
    }
}

/*
 * Build heap from provided array and size n.
 */
void MaxHeap::buildHeap(int arr[], int n) {
    size = n;
    for (int i = 0; i < n; i++)
        this->arr[i + 1] = arr[i];

    for (int i = size / 2; i >= 1; i--)
        heapify(i);
}