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

int n,k;
const int maxn=5e5+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
bool st[maxn];
int dis[maxn],cnt[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

bool spfa(){
    deque<int> q;
    q.push_back(0);
    st[0]=true;
    memset(dis,-0x3f,sizeof dis);
    dis[0]=0;

    while(q.size()){
        int t=q.back();
        q.pop_back();
        st[t]=false;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]<dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n+1) return false;
                if(!st[j]){
                    q.push_back(j);
                    st[j]=true;
                }
            }
        }
    }
    return true;
}

void sol(){
    cin>>n>>k;
    memset(h,-1,sizeof h);
    while(k--){
        int x,a,b; cin>>x>>a>>b;
        if(x==1) add(b,a,0),add(a,b,0);
        else if(x==2) add(a,b,1);
        else if(x==3) add(b,a,0);
        else if(x==4) add(b,a,1);
        else add(a,b,0);
    }

    for(int i=1;i<=n;i++) add(0,i,1);

    if(!spfa()) cout<<-1<<endl;
    else{
        int res=0;
        for(int i=1;i<=n;i++) res+=dis[i];
        cout<<res<<endl;
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
