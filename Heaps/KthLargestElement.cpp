#include <iostream>
#include <vector>
#include <queue>

int findKthLargestHeap(std::vector<int>& nums, int k) {
    // Create a min-heap (greater comparator makes the smallest element sit at the top)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        
        // If the heap exceeds size K, pop the smallest element
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

int main() {
    std::vector<int> nums = {1,4,8,5,13,2};
    int k = 3;
    std::cout << "The " << k << "-th largest element is: " << findKthLargestHeap(nums, k) << "\n";
    // Output: 5
    return 0;
}