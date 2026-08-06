#include <bits/stdc++.h>
using namespace std;

// Class to solve the gas station placement problem
class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> howMany(n - 1, 0); 
       priority_queue<pair<long double,int>>pq;
       for(int i = 0;i<n-1;i++)
       {
        int distance = arr[i+1] - arr[i];
        pq.push({distance,i});
       }
       vector<int>count(n+1,0);
       for(int i = 1;i<=k;i++)
       {
        auto it = pq.top();
        pq.pop();
        long double d = it.first;
        int node = it.second;
        count[node]++;
        long double len = d / (count[node] + 1);
        pq.push({len,node});
    }
    return pq.top().first;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    Solution obj;
    long double ans = obj.minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
