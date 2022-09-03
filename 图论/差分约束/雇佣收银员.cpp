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

const int maxn=100;
int h[maxn],ne[maxn],w[maxn],e[maxn],idx;
int num[maxn],s[maxn],a[maxn];
int n,m;
int dis[maxn],cnt[maxn];
bool st[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

bool spfa(int s24){
    memset(h,-1,sizeof h);
    memset(dis,-0x3f,sizeof dis);
    memset(st,0,sizeof st);
    memset(cnt,0,sizeof cnt);
    idx=0;

    dis[0]=0;
    for(int i=1;i<=24;i++){
        add(i-1,i,0),add(i,i-1,-a[i]);
        if(i>=8) add(i-8,i,num[i]);
        else add(i+16,i,-s24+num[i]);
    }
    add(0,24,s24),add(24,0,-s24);

    queue<int> q;
    q.push(0);
    st[0]=true;
    while(q.size()){
        int t=q.front(); q.pop();
        // cout<<t<<endl;
        st[t]=false;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]<dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=25) return true;
                if(!st[j]) q.push(j),st[j]=true;
            }
        }
    }
    return false;
}

void sol(){
    for(int i=1;i<=24;i++) cin>>num[i];

    cin>>n;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        a[++x]++;
    }

    bool ok=false;
    for(int i=1;i<=n;i++){
        if(!spfa(i)){
            cout<<dis[24]<<endl;
            ok=true;
            break;
        }
    }
    if(!ok) cout<<"No Solution"<<endl;
}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
