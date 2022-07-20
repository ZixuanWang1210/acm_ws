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

const int maxn=2e5+10;
int n,m;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int din[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void sol(){
    for(int i=0;i<=2e5;i++){
        ne[i]=e[i]=w[i]=din[i]=0;
        h[i]=-1;
    }
    idx=0;
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        add(y,x);
        din[x]++;
    }
    priority_queue<int> q;
    int cnt=0;
    int res[maxn];
    for(int i=1;i<=n;i++){
        if(din[i]==0) q.push(i);
    }

    while(q.size()){
        int t=q.top(); q.pop();
        res[++cnt]=t;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            din[j]--;
            if(din[j]==0){
                q.push(j);
            }
        }
    }

    if(cnt!=n){
        cout<<"Impossible!"<<endl;
        return;
    }

    for(int i=n;i>=1;i--) cout<<res[i]<<' ';
    cout<<endl;

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
