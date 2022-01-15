#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

char ans[100][100] {};
char mp[100][100] {};

int find(int i, int j){
    int num;
    if(i-1 >= 0 && mp[i-1][j] == '*') num++;
    if(i+1 >= 0 && mp[i+1][j] == '*') num++;
    if(j-1 >= 0 && mp[i][j-1] == '*') num++;
    if(j+1 >= 0 && mp[i][j+1] == '*') num++;

    if(i-1 >= 0 && j - 1 >=0 && mp[i-1][j-1] == '*') num++;
    if(i-1 >= 0 && j + 1 >=0 && mp[i-1][j+1] == '*') num++;
    if(i+1 >= 0 && j - 1 >=0 && mp[i+1][j-1] == '*') num++;
    if(i+1 >= 0 && j + 1 >=0 && mp[i+1][j+1] == '*') num++;
    return num;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mp[j][i];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[j][i] == '*')  ans[j][i] = mp[j][i];
            else    ans[j][i] = find(j, i) + '0';
            cout << ans[j][i];
        }
        cout << endl;
    }
    return 0;
}
