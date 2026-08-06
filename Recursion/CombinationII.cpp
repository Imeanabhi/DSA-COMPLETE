#include<bits/stdc++.h>
using namespace std;

// Function to find all combinations of numbers that sum up to the target
void findCombinationUsingForLoop(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    if(target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for(int i = ind;i<arr.size();i++)
    {
        if(i>ind && arr[i] == arr[i-1]) continue;
        if(arr[i] > target) break;
        ds.push_back(arr[i]);
        findCombinationUsingForLoop(i+1,target-arr[i],arr,ans,ds);
        ds.pop_back();
    }
}

void findCombinationUsingPickAndNonPick(int ind,int target,vector<int>& arr,vector<vector<int>>& ans,vector<int>& ds)
{
    if(target == 0){
    ans.push_back(ds);
    return;
    }
    if(ind == arr.size()) return;
    //pick
    if(arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        findCombinationUsingPickAndNonPick(ind+1,target-arr[ind],arr,ans,ds);
        ds.pop_back();
    }
     //nonpick
    int nextInd = ind + 1;
    while(nextInd < arr.size() && arr[nextInd] == arr[ind])
    {
        nextInd++;
    }
    findCombinationUsingPickAndNonPick(nextInd,target,arr,ans,ds);
}

// Function to calculate all unique combinations that sum up to the target
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());  // Sort the candidates to handle duplicates
    vector<vector<int>> ans;  // To store the final answer
    vector<int> ds;  // To store the current combination
    findCombinationUsingForLoop(0, target, candidates, ans, ds);
    //findCombinationUsingPickAndNonPick(0, target, candidates, ans, ds);
    return ans;  // Return all valid combinations
}

int main() {
    // Example input
    vector<int> v{10, 1, 2, 7, 6, 1, 5};

    // Get all combinations that sum up to 8
    vector<vector<int>> comb = combinationSum2(v, 8);

    // Output the combinations
    cout << "[ ";
    for (int i = 0; i < comb.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < comb[i].size(); j++) {
            cout << comb[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]";

    return 0;
}
