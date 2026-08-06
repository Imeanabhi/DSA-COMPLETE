#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({startWord,1});
        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == targetWord) return steps;
            for(int i = 0;i<word.size();i++)
            {
                char originalChar = word[i];
                for(char ch = 'a';ch<='z';ch++)
                {
                    word[i] = ch;
                    if(st.find(word)!=st.end())
                    {
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i] = originalChar;
            }
        }
        return 0;
    }
};

int main() {
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    Solution obj;
    cout << obj.wordLadderLength(startWord, targetWord, wordList) << endl;
    return 0;
}
