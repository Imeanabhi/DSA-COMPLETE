#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find k maximum sum combinations
    vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {
        sort(nums1.begin(),nums1.end(),greater<int>());
        sort(nums2.begin(),nums2.end(),greater<int>());
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({nums1[0]+nums2[0],{0,0}});
        set<pair<int,int>>st;
        st.insert({0,0});
        vector<int>result;
        while(k-- && !pq.empty())
        {
            int sum = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            result.push_back(sum);
            if(i+1<nums1.size() && !st.count({i+1,j}));
            {
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                st.insert({i+1,j});
            }
            if(j+1<nums2.size() && !st.count({i,j+1}));
            {
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                st.insert({i,j+1});
            }
        }
        return result;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> nums1 = {3, 4, 5};
    vector<int> nums2 = {2, 6, 3};
    int k = 2;
    vector<int> result = sol.maxCombinations(nums1, nums2, k);
    for(int val : result) cout << val << " ";
    return 0;
}