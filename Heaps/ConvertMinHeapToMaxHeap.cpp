#include <iostream>
#include <vector>
using namespace std;
void maxHeapify(int i,vector<int>&arr,int n)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left]>arr[largest])
    {
        largest = left;
    }
    if(right<n && arr[right]>arr[largest])
    {
        largest = right;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        maxHeapify(largest,arr,n);
    }
}
void convertToMaxHeap(vector<int>&arr){
    int n = arr.size();
    for(int i = n/2 - 1;i>=0;i--)
    {
        maxHeapify(i,arr,n);
    }
}

void printHeap(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    // Array representation of a sample Min-Heap
    //        3
    //      /   \
    //    5       9
    //   / \
    //  6   8
    std::vector<int> heap = {3, 5, 9, 6, 8};

    std::cout << "Original Min-Heap: ";
    printHeap(heap);

    convertToMaxHeap(heap);

    std::cout << "Converted Max-Heap: ";
    printHeap(heap);
    // Expected Output: 9 8 3 6 5 (or another valid max-heap array)

    return 0;
}
