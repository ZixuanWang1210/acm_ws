#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=1e5+10;
int d[maxn];
int h[maxn],ne[maxn],e[maxn],idx;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void sol(){
    int n,m;
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;
        add(a,b),add(b,a);
        d[a]++,d[b]++;
    }
    int ans=0;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(d[i]==1){
            q.push(i);
            ans=max(ans,1);
            // break;
        }
    }


    while(q.size()){
        int t=q.front();
        d[t]--;
        q.pop();
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            d[j]--;
            for(int kk=h[j];~kk;kk=ne[kk]){
                int jj=e[kk];
                d[jj]--;
                if(d[jj]==1) q.push(jj),ans++;
            }
        }
    }



    cout<<ans<<endl;


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
