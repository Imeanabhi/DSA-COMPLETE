#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortNearlySortedArray(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n = arr.size();
        vector<int>ans;
        for(int i = 0; i <= k && i<n;i++)
        {
            pq.push(arr[i]);
        }
        for(int i = k+1;i<n;i++)
        {
            ans.push_back(pq.top());
            pq.pop();

            pq.push(arr[i]);
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

// Driver code
int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    Solution obj;
    vector<int> sortedArr = obj.sortNearlySortedArray(arr, k);

    for (int num : sortedArr) {
        cout << num << " ";
    }

    return 0;
}
