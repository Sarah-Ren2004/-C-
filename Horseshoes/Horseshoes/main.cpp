//
//  main.cpp
//  Horseshoes
//
//  Created by 姚欣 on 2021/7/17.
//  Copyright © 2021 任奕霏. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define pii pair<int,int>
int N;
bool unvis[7][7];
int graph[7][7];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ans = 0;
void calc(int r, int c, int numopen, int numclose, bool second)
{
    if(numopen == numclose)
    {
        ans = max(ans, numopen + numclose);
        return;
    }
    if(second && (2*numopen <= ans))
        return;
    unvis[r][c] = false;
    for (int i = 0; i < 4; i++)
    {
        int r2 = r + dx[i];
        int c2 = c + dy[i];
        if(unvis[r2][c2])
        {
            if(graph[r2][c2] == 1)
                calc(r2, c2, numopen, numclose + 1, true);
            else if(!second)
                calc(r2, c2, numopen + 1, numclose, false);
        }
    }
    unvis[r][c] = true;
}
int main()
{
    ifstream fin ("hshoe.in");
    ofstream fout ("hshoe.out");
    cin >> N;
    for (int i = 0; i <= N+1; i++)
    {
        unvis[0][i] = unvis[N+1][i] = unvis[i][0] = unvis[i][N+1] = false;
        graph[0][i] = graph[N+1][i] = graph[i][0] = graph[i][N+1] = -1;
    }
    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++)
        {
            unvis[i][j] = true;
            if(s[j-1] == '(')
                graph[i][j] = 0;
            else
                graph[i][j] = 1;
        }
    }
    if(graph[1][1] == 0)
        calc(1,1,1,0,false);
    cout << ans << endl;
    return 0;
}
