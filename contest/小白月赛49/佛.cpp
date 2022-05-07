#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
using namespace std;

set<int> st[300]; 
int ans[300]={0};

void sol(){
    int n,m; cin>>n>>m;
    memset(ans,0,sizeof ans);
    for(int i=1;i<=n;i++){
        st[i].clear();
        for(int j=1;j<=m;j++){
            int x; cin>>x;
            st[i].insert(x);
        }
    }
    for(int i=1;i<=m;i++){
        int x; cin>>x;
        int res=0;
        for(int j=1;j<=n;j++){
            if(st[j].count(x)!=0&&(ans[j]!=0||i==1)) ans[j]++,res++;
            else ans[j]=0;

        }
        cout<<res<<' ';
    }
    cout<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
