#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10, INF = 0x3f3f3f3f;

int n, m, k;
int mp[maxn][maxn];

void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(i == j) mp[i][j] = 0;
            else mp[i][j] = INF;
        }

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        mp[a][b] = min(mp[a][b], c);
    }

    floyd();

    while(k--){
        int a, b;
        cin >> a >> b;
        if(mp[a][b] > INF / 2) puts("impossible");
        else cout << mp[a][b] << endl;
    }

    return 0;
}