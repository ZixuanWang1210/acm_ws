#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;
const int N=10;
int a[N],t[N];
int w[N][N];
int st[N];
bool ok = false;

void dfs(int u, int count){
    // cout << count  << ":  ";
    // for(int i=1; i<=4; i++)
    //     cout << a[i] << ' ';
    // cout << endl;
    if(ok) return;
    if(count == 9){
        ok = true;
        return;
    }
    st[u]++;
    a[u] = 0;
    for(int j=1; j<=4; j++){
            a[j] += w[u][j];
        }

    for(int i=1; i<=4; i++){
        if(st[i]>2) continue; 
        if(a[i]<t[i]) continue;
        
        dfs(i, count+1);
        
    }

    for(int j=1; j<=4; j++){
            a[j] -= w[u][j];
        }

    a[u] = t[u];
    st[u]--;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=1; i<=4; i++){
        cin >> t[i];
    }
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++)
            cin >> w[i][j];

    for(int i=1; i<=4; i++){
        memcpy(a, t, sizeof t);
        memset(st, 0, sizeof st);
        dfs(i, 1);
        if(ok){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

    return 0;
}
