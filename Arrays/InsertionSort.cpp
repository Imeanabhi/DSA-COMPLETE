#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to sort the array using insertion sort
    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            int key = nums[i]; 
            int j = i - 1; 
            
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            
            nums[j + 1] = key; 
        }
        
        return nums;
    }
};


int main() {
    // Create an instance of solution class
    Solution solution;
    
    vector<int> nums = {13, 46, 24, 52, 20, 9};
    
    cout << "Before Using Insertion Sort: " << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Function call for insertion sort
    nums = solution.insertionSort(nums);

    cout << "After Using Insertion Sort: " << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}