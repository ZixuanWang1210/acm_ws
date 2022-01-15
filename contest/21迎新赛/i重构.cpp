#include<bits/stdc++.h>
using namespace std;
const int N = 1010;

map<int, int> mp;

int p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    int flag = 0;
    while (m -- )
    {
        int a, b; cin >> a >> b;
        p[find(a)] = find(b);
        if(mp.find(b) == mp.end()) flag ++;
        if(mp.find(a) == mp.end()) flag ++;
        mp[a] = b;
    }

    if(flag != 0){
        cout << "YES";
        return 0;
    }

    // int cmp = find(1);
    // for(int i = 1; i <= n; i++){
    //     if(cmp != find(i)){
    //         cout << "YES";
    //         return 0;
    //     }
    // }
    // cout << "NO";
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        if(p[i] == i) tmp ++;
    }
    if(tmp > 0){
        cout << "YES";
        return 0;
    }
    else cout << "NO";
    return 0;
}
