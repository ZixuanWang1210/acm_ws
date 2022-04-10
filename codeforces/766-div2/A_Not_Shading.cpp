#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    char mp[100][100];
    bool bz1=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='B') bz1=false;
        }
    }
    if(mp[r][c]=='B'){
        cout<<0<<endl;
        return;
    }
    if(bz1){
        cout<<-1<<endl;
        return;
    }
    int bz2=true;
    for(int i=1;i<=m;i++){
        if(mp[r][i]=='B') bz2=false;
    }
    for(int i=1;i<=n;i++){
        if(mp[i][c]=='B') bz2=false;
    }
    if(bz2){
        cout<<2<<endl;
        return;
    }
    else cout<<1<<endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    
    int t; cin>>t;
    while(t--) sol();
    return 0;
}
