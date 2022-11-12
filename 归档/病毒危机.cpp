#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn=1e5+10;
int cnt[maxn];
int t[maxn];
set<int> st;
int res=1;
void sol(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int c; cin>>c;
        bool f=false;
        for(int j=1;j<=c;j++){
            int x; cin>>x;
            if(f) continue;
            if(i==1) st.insert(x);
            else{
                if(st.count(x)){
                    res++;
                    f=1;
                }
            }
        }
    }
    cout<<res<<endl;
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
