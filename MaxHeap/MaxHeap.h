
/*
 * MaxHeap definition
 *
 * Colby Waters
 * 3/5/2023
 */

#ifndef MaxHeap_h
#define MaxHeap_h

const int MAX_SIZE = 100;

/*
 * Max Heap class definition
 */
class MaxHeap
{
public:
    MaxHeap() : size(0) { }

    void buildHeap(int arr[], int n);

    void buildHeapFromFile(const char* fileName);

    void insert(int value);

    int removeMax();

    void removeAll();

    void display(int i, int indent = 0);

private:
    int arr[MAX_SIZE];
    int size;

    void heapify(int i);
};

#endif // MaxHeap_h