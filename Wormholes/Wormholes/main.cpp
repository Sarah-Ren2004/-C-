//
//  main.cpp
//  Wormholes
//
//  Created by 姚欣 on 2021/7/17.
//  Copyright © 2021 任奕霏. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,ans;
int v[20];
struct node
{
    int x,y;
}w[20];
bool cmp(node a,node b)
{
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}
int find(int vis,int end,int begin,int way)
{
    if(vis != 1 && end == begin && way == 1)
        return 1;
    if(way == 0)
    {
        if(w[end].y == w[end + 1].y)
            return find(vis + 1,end + 1,begin,1);
        return 0;
    }
    return find(vis + 1,v[end],begin,0);
}
int judge()
{
    for(int i = 1; i <= n; i ++)
        if(find(1,i,i,1))
            return 1;
    return 0;
}
void dfs(int x)
{
    if(x == n + 1)
    {
        if(judge())
            ans ++;
        return;
    }
    if(v[x] == 0)
    {
        for(int i = x + 1; i <= n; i ++)
            if(v[i] == 0)
            {
                v[i] = x;
                v[x] = i;
                dfs(x + 1);
                v[i] = v[x] = 0;
            }
    }
    if(v[x] != 0)
        dfs(x + 1);
    return;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> w[i].x >> w[i].y;
    sort(w,w + n,cmp);
    dfs(1);
    cout << ans << endl;
    return 0;
}
