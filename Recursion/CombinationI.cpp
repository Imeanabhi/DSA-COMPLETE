#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find all combinations of numbers that sum up to the target
    void findCombinationUsingPickNonPick(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
       /*Method 1 : using pick and non pick*/
       if(target == 0){
        ans.push_back(ds);
        return;
       }
       if(ind == arr.size()) return;
       if(arr[ind] <= target)
       {
        ds.push_back(arr[ind]);
        findCombinationUsingPickNonPick(ind,target-arr[ind],arr,ans,ds);
        ds.pop_back();
       }
       /* if you want only distinct answers then
       int nextInd = ind + 1;
       while(nextInd < arr.size() && arr[ind] == arr[nextInd])
       {
       nextInd++;
       }
       in below findCombinationUsingPickNonPick(nextInd,target,arr,ans,ds);
        */
       findCombinationUsingPickNonPick(ind+1,target,arr,ans,ds);
    }
    void findCombinationUsingForloop(int ind,int target,vector<int>& arr,vector<vector<int>>&ans,vector<int>&ds)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i = ind;i<arr.size();i++)
        {
            //for distinct use if(i>ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombinationUsingForloop(i,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }

  public:
    // Main function to get all combinations
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;  // To store the result
        vector<int> ds;  // To store a current combination
        //findCombinationUsingPickNonPick(0, target, candidates, ans, ds);
        findCombinationUsingForloop(0,target,candidates,ans,ds);
        return ans;  // Return all valid combinations
    }
};

int main() {
    Solution obj;
    vector<int> v {2, 3, 6, 7};  // Candidate numbers
    int target = 7;  // Target sum

    // Get all combinations
    vector<vector<int>> ans = obj.combinationSum(v, target);

    // Output the combinations
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";  // Print each element of the combination
        }
        cout << endl;  // Print a newline after each combination
    }

    return 0;
}
