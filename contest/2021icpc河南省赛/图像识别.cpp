#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;
const int maxn=1100;
char mp[maxn][maxn];
int n,m;
int sx,sy,dx,dy;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='#'){
                sx=i;
                sy=j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='*'&&mp[i+1][j]=='*'&&mp[i-1][j]=='*'&&mp[i][j+1]=='*'&&mp[i][j-1]=='*'){
                dx=i;
                dy=j;
            }
        }
    }
    cout<<sy-dy<<' '<<dx-sx<<endl;

    return 0;
}
