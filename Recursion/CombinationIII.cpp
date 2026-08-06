#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void recursionUsingPickAndNonPick(int num,int k,int target,vector<int>&ds,vector<vector<int>>&ans)
    {
        if(ds.size() == k && target == 0)
        {
            ans.push_back(ds);
            return;
        }

        if(num > 9 || ds.size() > k || target < 0) return;
        if(num <= target)
        {
            ds.push_back(num);
            recursionUsingPickAndNonPick(num+1,k,target-num,ds,ans);
            ds.pop_back();
        }

        recursionUsingPickAndNonPick(num+1,k,target,ds,ans);
    }
    void recursionUsingForLoop(int num,int k,int target,vector<int>&ds,vector<vector<int>>&ans)
    {
        if(target == 0 && ds.size() == k)
        {
            ans.push_back(ds);
            return;
        }
        if(ds.size() > k || target < 0)return;
        for(int i = num;i<=9;i++)
        {
            if(i>target) break;
            ds.push_back(i);
            recursionUsingForLoop(i+1,k,target-i,ds,ans);
            ds.pop_back();
        }
    }
public:
    // Function to find all possible combinations of k numbers that add up to n
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        // Call the recursive function with initial parameters
        //recursionUsingPickAndNonPick(1,k,n,ds,ans);
        recursionUsingForLoop(1,k,n,ds,ans);
        return ans; 
    }
};
int main() {
    Solution sol;
    int k = 3; // Number of elements in the combination
    int n = 9; // Target sum
    vector<vector<int>> result = sol.combinationSum3(k, n);

    // Print the result
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}