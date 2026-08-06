
#include <bits/stdc++.h>
  using namespace std;
  
  class Solution {
  public:
      // Method to check if two strings are isomorphic
      bool isomorphicString(string s, string t) {
          // Arrays to store last seen positions of characters in s and t
          int a1[256] = {0}, a2[256] = {0}; 
          
          // Get the length of the strings
          int n = s.size(); 
          
          // Traverse each character of the strings
          for (int i = 0; i < n; ++i) {
            if(a1[s[i]]!=a2[t[i]])return false;
            a1[s[i]] = i+1;
            a2[t[i]] = i+1;
          }
          return true;
        }

  };
  
  // Main function to test the method
  int main() {
      // Create object of Solution
      Solution solution;
      
      // Sample input strings
      string s = "paper";
      string t = "title";
      
      // Check if strings are isomorphic
      if (solution.isomorphicString(s, t)) {
          cout << "Strings are isomorphic." << endl;
      } else {
          cout << "Strings are not isomorphic." << endl;
      }
      
      return 0;
  }