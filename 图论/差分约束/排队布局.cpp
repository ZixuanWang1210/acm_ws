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

const int maxn=10000;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int n;
int dis[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

bool st[maxn];
int cnt[maxn];

bool spfa(int size){
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    memset(cnt,0,sizeof cnt);
    queue<int> q;
    for(int i=1;i<=size;i++){
        q.push(i);
        dis[i]=0;
        st[i]=true;
    }
    while(q.size()){
        int t=q.front(); q.pop();
        st[t]=false;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n) return true;
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    return false;
}

void sol(){
    cin>>n;
    int ml,md; cin>>ml>>md;
    memset(h,-1,sizeof h);

    for(int i=1;i<n;i++) add(i+1,i,0);
    for(int i=1;i<=ml;i++){
        int a,b,c; cin>>a>>b>>c;
        if(a>b) swap(a,b);
        add(a,b,c);
    }
    for(int i=1;i<=md;i++){
        int a,b,c; cin>>a>>b>>c;
        if(a>b) swap(a,b);
        add(b,a,-c);
    }

    if(spfa(n)) cout<<-1<<endl;
    else{
        spfa(1);
        if(dis[n]==inf) cout<<-2<<endl;
        else cout<<dis[n]<<endl;
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
