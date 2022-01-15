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
        if(mp.find(b) != mp.end()) flag ++;
        if(mp.find(a) != mp.end()) flag ++;
        mp[a] = b;
    }

    if(flag != 0){
        // cout << "YES";
        puts("YES");
        return 0;
    }


    int tmp = 0;
    for(int i = 1; i <= n; i++){
        find(i);
        if(p[i] == i) tmp ++;
    }
    if(tmp > 1){
        // cout << "YES";
        puts("YES");
        return 0;
    }
    else puts("NO");
    return 0;
}
