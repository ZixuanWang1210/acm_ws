#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

int n,m;
const int maxn=8e4+7;
#define pii pair<int,int>

struct node{
    int u,v;
} seg[maxn];
struct N{
    string op;
    int a,b;
} ask[maxn];
int c[maxn];
int q;
int bk[maxn];

int p[maxn];
int msg[maxn];

int find(int x){
    if(x==p[x]) return x;
    // int root=find(p[x]);
    p[x]=find(p[x]);

    // if(c[root]<c[x]) msg[root]=x;
    // else if(c[root]==c[x]) msg[root]=min(msg[root],msg[x]);

    c[x]=max(c[p[x]],c[x]);
    return p[x];
}

bool merge(int x,int y){
    int xx=find(x),yy=find(y);
    if(xx!=yy){
        // p[py]=px;
        // if(c[px]<c[py]) msg[px]=py;
        // else if(c[px]==c[py]) msg[px]=min(msg[px],msg[py]);
        if(c[xx]>c[yy]||(c[xx]==c[yy]&&xx<yy)) p[yy]=xx;
        else p[xx]=yy;

        // c[px]=max(c[px],c[py]);
        return true;
    }
    else return false;
}

void sol(){
    // cin>>n;
    for(int i=0;i<=n;i++){
        p[i]=i;
        msg[i]=i;
    }
    for(int i=0;i<n;i++) cin>>c[i],bk[i]=c[i];
    map<pii,int> st;
    cin>>m;
    while(m--){
        int a,b; cin>>a>>b; 
        if(a>b) swap(a,b);
        st[{a,b}]=1;
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        string s; int a,b;
        cin>>s; 
        if(s=="destroy"){
            cin>>a>>b;
            if(a>b) swap(a,b);
            ask[i]={s,a,b};
            // st.erase({a,b});
            st[{a,b}]=0;
        }
        else{
            cin>>a;
            ask[i]={s,a};
        }
    }


    for(auto x:st){
        if(x.second==0) continue;
        int u=x.first.first,v=x.first.second;
        merge(u,v);
    }

    stack<int> que;
    for(int i=q;i>=1;i--){
        string op=ask[i].op;
        int a=ask[i].a,b=ask[i].b;
        if(op=="query"){
            int pa=find(a);
            if(c[pa]>bk[a]) que.push(pa);
            else que.push(-1);

        }
        else{
            merge(a,b);
        }
    }
    while(que.size()){
        int x=que.top();
        cout<<x<<endl;
        que.pop();
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    int ok=1;
    while(cin>>n){
        if(ok){
            ok=0;
            // cout<<endl;
        }
        else cout<<endl;
        sol();
        // ok==0;
    }

    return 0;
}
