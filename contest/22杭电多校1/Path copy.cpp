#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 3e18
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn=1e6+10,maxm=2*maxn;
int h[maxn],ne[maxm],e[maxm],w[maxm],p[maxm],idx;
int dis[maxn][2];
int st[maxn][2];
int n,m,s,k;
struct node{
    int u,d,op;
    bool operator<(const node&t) const{
        return d>t.d;
    }
};

void add(int a,int b,int c,int d){
    e[idx]=b,w[idx]=c,p[idx]=d,ne[idx]=h[a],h[a]=idx++;
}

int gg[maxn];
void bfs(){
    set<int> ss;
    priority_queue<node> q;
    for(int i=1;i<=n;i++){
        if(i!=s) ss.insert(i);
        dis[i][1]=dis[i][0]=inf;
        st[i][1]=st[i][0]=0;
    }
    dis[s][0]=0,st[s][0]=0;
    q.push({s,0,0});
    int cnt=0;
    while(q.size()){
        auto t=q.top(); q.pop();
        int ty=t.op,ver=t.u;
        cnt++;
        if(!ty) ss.erase(ver)   ;
        else{
            for(int i=h[ver];~i;i=ne[i]){
                int j=e[i];
                gg[j]=cnt;
            }
            vector<int> temp;
            for(auto it:ss){
                if(gg[it]!=cnt){
                    temp.push_back(it);
                    dis[it][0]=dis[ver][ty];
                    q.push({it,dis[it][0],0});
                }
            }
            for(auto it :temp){
                ss.erase(it);
            }
        }
        int y=0;
        if(ty) y-=k;
        if(st[ver][ty]) continue;
        st[ver][ty]=true;
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dis[j][p[i]]>dis[ver][ty]+w[i]+y){
                dis[j][p[i]]=dis[ver][ty]+w[i]+y;
                q.push({j,dis[j][p[i]],p[i]});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(min(dis[i][0],dis[i][1])==inf) cout<<-1<<' ';
       else  cout<<min(dis[i][0],dis[i][1])<<' ';
    }
    cout<<endl;
}

void sol(){
    cin>>n>>m>>s>>k;
    for(int i=0;i<=n;i++){
        h[i]=-1;
        gg[i]=0;
    }
    idx=0;
    for(int i=1;i<=m;i++){
        int a,b,c,d; cin>>a>>b>>c>>d;
        add(a,b,c,d);
    }

    bfs();

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
