#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

void sol(){
    int n,m; cin>>n>>m;
    int mp[n+1][m+1];
    int b[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            b[i][j]=mp[i][j];
        }
    }
    int l=0,r=0;
    bool ok=0;
    for(int i=1;i<=n;i++){
        sort(b[i]+1,b[i]+1+m);
        int cnt=0;
        for(int j=1;j<=m;j++){
            if(b[i][j]!=mp[i][j]){
                if(ok){
                    // if(j==l||j==r) ;
                    // else {
                        cout<<-1<<endl;
                        return;
                    // }
                }

                if(!l) l=j;
                else if(!r){
                    r=j,ok=1;
                    for(int k=1;k<=n;k++){
                        swap(mp[k][l],mp[k][r]);
                    }
                    
                }

            }
        }
        if(ok) break;
        // if(cnt>2){
        //     cout<<-1<<endl;
        //     return;
        // }
    }
    bool success=1;
    for(int i=1;i<=n;i++){
        if(!is_sorted(mp[i]+1,mp[i]+1+m)){
            success=0;
        }
    }
    if(!success) cout<<-1<<endl;
    else if(!l) cout<<1<<' '<<1<<endl;
    else cout<<l<<' '<<r<<endl;
    // bool ok=false;
    // int a1,a2=0;
    // for(int i=1;i<=n&&!ok;i++){
    //     for(int j=2;j<=m;j++){
    //         if(!a2) a1=j;
    //         if(mp[i][j]<mp[i][j-1]){
    //             a2=j;
    //             for(int k=1;k<=n;k++){
    //                 swap(mp[k][j],mp[k][j-1]);
    //             }
    //             ok=1;
    //         }
    //     }
    // }

    // for(int i=1;i<=n;i++){
    //     if(!is_sorted(mp[i]+1,mp[i]+1+m)){
    //         cout<<"-1"<<endl;
    //         return;
    //     }
    // }
    // if(!a2){
    //     cout<<1<<" "<<1<<endl;
    //     return ;
    // }
    // cout<<a1-1<<' '<<a2<<endl;



}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
