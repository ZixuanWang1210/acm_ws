#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

char mp[110][100];
bool f[110][110];
int n;
string s = "yizhong";
int dx[] = {0,1,0,1,-1,0,-1,1,-1}, dy[] = {0,0,1,1,0,-1,-1,-1,1};

void dfs(int idx, int x, int y){
    if(idx == s.length() - 1) return;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++){
            if(mp[x + i][y + j] == s[idx + 1])
                dfs(idx + 1, x + i, y + j);
        }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mp[i][j];

    


    return 0;
}