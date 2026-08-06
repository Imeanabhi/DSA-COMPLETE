#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>&v)
{
    int count = 0;
    int m = v.size();
    int n = v[0].size();
    queue<pair<int,int>>q;
    int days =0;
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(v[i][j] != 0)
            {
                count++;
            }
            if(v[i][j] == 2)
            {
                q.push({i,j});
            }
        }
    }
    int cnt = 0;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    while(!q.empty())
    {
        int k = q.size();
        cnt += k;

        while(k--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if(nx>=0 && ny>=0 && nx<m && ny<n && v[nx][ny] == 1)
                {
                    v[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
        }
        if(!q.empty())
        {
            days++;
        }

    }
    return count == cnt ? days : -1;
}
int main() {

    vector<vector<int>> v{{2, 1, 1},
                        {1, 1, 0},
                        {0, 1, 1}};
    int rotting = orangesRotting(v);
    cout << "Minimum Number of Minutes Required " << rotting << endl;

    return 0;
}