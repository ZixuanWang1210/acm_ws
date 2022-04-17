#include<bits/stdc++.h>
using namespace std;

int n,k;
string my,op;
int bg,ed;
map<int,int> mp;
map<string,int> hs;
int cnt;

const int maxn=2000;
int h[maxn],ne[maxn],w[maxn],e[maxn],idx;
int fro[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dis[maxn];
bool st[maxn];
struct node{
    int id;
    int dis;
    int cnt;
    int ar_cnt;
    bool operator<(const node&t) const{
        if(dis==t.dis){
            if(cnt==t.cnt) return ar_cnt>t.ar_cnt;
            else return cnt>t.cnt;
        }
        else return dis>t.dis;
    }
};

node dij(){
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    priority_queue<node> pq;
    pq.push({bg,0,0,0});
    dis[bg]=0;

    while(pq.size()){
        node t=pq.top(); pq.pop();
        int ver=t.id,dist=t.dis;
        if(st[ver]) continue;
        st[ver]=true;
        for(int i=h[ver];~h[i];i=ne[i]){
            int j=e[i];
            if(st[j]) continue;
            if(dis[j]>dist+w[i]){
                dis[j]=dist+w[i];
                fro[j]=ver;
                int ar_cnt=t.ar_cnt+mp[j];
                pq.push({j,dis[j],t.cnt+1,ar_cnt});
                if(j==ed){
                    return {j,dis[j],t.cnt+1,ar_cnt};
                }
            }
        }
    }
    
}


int main(){
    cin>>n>>k>>my>>op;

    hs[my]=++cnt; 
    mp[cnt]=0;

    for(int i=1;i<=n-1;i++){
        string name; int num;
        cin>>name>>num; 
        hs[name]=++cnt;
        mp[cnt]=num; 
    }

    bg=hs[my],ed=hs[op];

    memset(h,-1,sizeof h);
    for(int i=1;i<=k;i++){
        string s1,s2; cin>>s1>>s2;
        int u,v; u=hs[s1],v=hs[s2];
        int c; cin>>c;
        add(u,v,c),add(v,u,c);
    }

    node res=dij();

    while(fro[ed]){
        cout<<fro[ed];
        ed=fro[ed];
    }
    cout<<res.cnt<<res.ar_cnt<<endl;
    



    



    return 0;
}