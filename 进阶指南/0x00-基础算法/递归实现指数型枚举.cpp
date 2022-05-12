#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

bool st[100];
int n;
// void dfs(int x){
//     if(x>n){
//         for(int i=1;i<=n;i++){
//             if(st[i]) cout<<i<<' ';
//         }
//         cout<<endl;
//         return;
//     }
//     else{
//         st[x]=true;
//         dfs(x+1);
//         st[x]=false;
//         dfs(x+1);
//     }
// }

void dfs(int x){
    if(x==n+1){
        for(int i=1;i<=n;i++){
            if(st[i]) cout<<i<<' ';
        }
        cout<<endl;
        return;
    }
    st[x]=true;
    dfs(x+1);
    st[x]=false;
    dfs(x+1);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    dfs(1);

    return 0;
}
