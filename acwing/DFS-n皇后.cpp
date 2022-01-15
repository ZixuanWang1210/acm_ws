#include<bits/stdc++.h>
using namespace std;

//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
bool hang[10], lie[10], cha[20], he[20];
int mp[10][10];
int n;

void dfs(int x){
    if(x == n + 1){
        for(int i = 1; i <= n; i++){    
            for(int j = 1; j <= n; j++){
                if(mp[i][j]) cout << 'Q';
                else cout << '.';
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(hang[x] || lie[i] || cha[i - x + n] || he[i + x]) continue;
        mp[x][i] = 1;
        hang[x] = 1, lie[i] = 1, cha[i - x + n] = 1, he[i + x] = 1;
        dfs(x + 1);
        hang[x] = 0, lie[i] = 0, cha[i - x + n] = 0, he[i + x] = 0;
        mp[x][i] = 0;
    }
}

int main(){
    cin >> n;

    dfs(1);

    return 0;
}