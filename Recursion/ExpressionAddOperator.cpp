#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void recursion(int index,string num,long long currentSum,int target,long long prevOperand,string temp,vector<string>&result)
    {
        if(index == num.size())
        {
            if(currentSum == target)
            {
                result.push_back(temp);
            }
            return;
        }
        for(int i = index;i<num.size();i++)
        {
            if(i>index && num[index] == '0') break;
            string numString = num.substr(index,i-index+1);
            long long numVal  = stoll(numString);
            if(index == 0)
            {
                recursion(i+1,num,numVal,target,numVal,numString,result);
            }
            else{
                recursion(i+1,num,currentSum+numVal,target,+numVal,temp + '+' + numString,result);
                recursion(i+1,num,currentSum-numVal,target,-numVal,temp + '-' + numString,result);
                recursion(i+1,num,currentSum-prevOperand + prevOperand*numVal,target,prevOperand*numVal,temp + '*' + numString,result);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string>result;
        string temp = "";
        recursion(0,num,0,target,0,temp,result);
        return result;
    }
};

int main() {
    Solution sol;

    string num1 = "232";
    int target1 = 8;
    vector<string> res1 = sol.addOperators(num1, target1);
    cout << "Input: num = \"" << num1 << "\", target = " << target1 << "\nOutput: [";
    for (int i = 0; i < res1.size(); ++i) {
        cout << "\"" << res1[i] << "\"" << (i + 1 < res1.size() ? ", " : "");
    }
    cout << "]\n\n";

    string num2 = "105";
    int target2 = 5;
    vector<string> res2 = sol.addOperators(num2, target2);
    cout << "Input: num = \"" << num2 << "\", target = " << target2 << "\nOutput: [";
    for (int i = 0; i < res2.size(); ++i) {
        cout << "\"" << res2[i] << "\"" << (i + 1 < res2.size() ? ", " : "");
    }
    cout << "]\n";

    return 0;
}