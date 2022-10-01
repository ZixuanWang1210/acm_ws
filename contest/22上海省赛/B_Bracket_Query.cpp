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

const int maxn=1e6+10;
int h[maxn],ne[maxn],w[maxn],e[maxn],idx;
int n,m;
int q;

int p[maxn];
int L[maxn],R[maxn],X[maxn];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int d[maxn],cnt[maxn];
bool st[maxn];
bool spfa(int s){
    for(int i=1;i<=n;i++) d[i]=1e9;
    queue<int> q;
    q.push(s);
    d[0]=0,st[0]=1;
    while(q.size()){
        int t=q.front(); q.pop();
        st[t]=false;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(d[j]>d[t]+w[i]){
                d[j]=d[t]+w[i];
                if(!st[j]){
                    st[j]=1;
                    ++cnt[j];
                    q.push(j);
                    if(cnt[j]==n) return 0;
                }
            }
        }
    }
    return 1;
}

void sol(){
    cin>>n>>q;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        p[i]=i;
        add(i,0,-((i+1)/2));
        add(i-1,i,1);
        add(i,i-1,0);
    }
    add(0,n,n/2);
    for(int i=1;i<=q;i++){
        cin>>L[i]>>R[i]>>X[i];
        int len=R[i]-L[i]+1;
        if((len+X[i])&1){
            cout<<"?"<<endl;
            return;
        }
        X[i]=(len+X[i])/2;
        if(find(L[i]-1)!=find(R[i])){
            int x=find(L[i]-1),y=find(R[i]);
            p[x]=y;
            add(L[i]-1,R[i],X[i]),add(R[i],L[i]-1,-X[i]);
        }
    }
    if(!spfa(0)){
        cout<<"?"<<endl;
        return;
    }
    for(int i=1;i<=q;i++){
        if(d[R[i]]-d[L[i]-1]!=X[i]){
            cout<<"?"<<endl;
            return;
        }
    }
    cout<<"!"<<' ';
    for(int i=1;i<=n;i++){
        if(d[i]==d[i-1]) cout<<")";
        else cout<<"(";
    }
    cout<<endl;
    return;
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
