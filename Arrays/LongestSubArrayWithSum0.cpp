#include <bits/stdc++.h>
using namespace std;

// compute length of the longest subarray with sum 0
int maxLen(int A[], int n) {
  // map prefix sum -> first index seen
  unordered_map<int, int> mpp;
  int maxi = 0;
  int sum = 0;

  for (int i = 0; i < n; i++) {
    sum += A[i];
    if (sum == 0) {
      maxi = i + 1;
    }
    else {
      // when seen, zero-sum segment between previous index + 1 and i
      if (mpp.find(sum) != mpp.end()) {
        maxi = max(maxi, i - mpp[sum]);
      }
      else {
        mpp[sum] = i;
      }
    }
  }
  return maxi;
}

// program entry
int main() {
  // sample input
  int A[] = {9, -3, 3, -1, 6, -5};
  // compute size
  int n = sizeof(A) / sizeof(A[0]);
  // print result
  cout << maxLen(A, n) << endl;
  // exit
  return 0;
}
