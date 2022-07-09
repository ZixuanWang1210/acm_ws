#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int int64_t

using namespace std;

void sol(){
    int n,x,y; cin>>n>>x>>y;
    // if(x==y&&x!=n){
    //     cout<<"-1"<<endl;
    //     return;
    // }
    if(x==y&&x==n){
        for(int i=1;i<=n;i++){
            cout<<1<<endl;
        }
        return;
    }
    // else if(x<y){
    //     cout<<-1<<endl;
    //     return;
    // }
    else{
        if(n>y){
            cout<<-1<<endl;
            return;
        }
        else{
            // vector<int> v(n+1);
            // for(int i=1;i<=n-1;i++){
            //     v[i]=1;
            // }
            // v[n]=y-n+1;
            int la=y-n+1;
            if(n-1+la*la>=x){
                for(int i=1;i<=n-1;i++){
                    cout<<1<<endl;
                }
                cout<<la<<endl;
            }
            else cout<<-1<<endl;
        }
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
