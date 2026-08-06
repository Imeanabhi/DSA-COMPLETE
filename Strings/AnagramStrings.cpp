#include <bits/stdc++.h>
using namespace std;

// Function to check if two strings are anagrams
bool CheckAnagrams(string str1, string str2) {
    if(str1.length()!=str2.length())return false;
    map<int,int>mp;
    int n = str1.length();
    for(int i = 0;i<n;i++)
    {
        mp[str1[i]-'A']++;
    }
        for(int i = 0;i<n;i++)
    {
        mp[str2[i]-'A']--;
    }
        for(int i = 0;i<n;i++)
    {
        if(mp[str1[i]-'A']!=0) return false;
    }

    return true;  // The strings are anagrams
}

int main() {
    string Str1 = "INTEGER";
    string Str2 = "TEGERNI";

    // Check if the strings are anagrams and output the result
    if (CheckAnagrams(Str1, Str2))
        cout << "True" << endl;  // Output "True" if they are anagrams
    else
        cout << "False" << endl;  // Output "False" if they aren't anagrams

    return 0;
}
