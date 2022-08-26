#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;


const int maxn=1e6+10;
bool st[maxn];
int pri[maxn],cnt;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1),res(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];

    for(int i=2;i<=200010;i++){
        if(!st[i]) pri[cnt++]=i;
        for(int j=0;pri[j]<=n/i;j++){
            st[pri[j]*i]=true;
            if(i%pri[j]==0) break;
        }
    }

    int idx=1;
    for(int i=1;i<=n;i++){
        if(v[i]!=pri[idx]) res[i]=res[i-1];
        else{
            idx++;
            res[i]=pri[idx];
        }
    }

    int q; cin>>q;
    while(q--){
        int x; cin>>x;
        cout<<res[x]<<endl;
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
