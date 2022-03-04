#include<bits/stdc++.h>
using namespace std;

int n;
const int maxn=5000;
int ans[133000],cnt;
int d[maxn];
int g[maxn][maxn];
int h[maxn],ne[maxn],e[maxn],idx;
int p[maxn];
bool st[maxn];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void dfs(int u){
    for(int i=0;i<58;i++){
        if(g[u][i]) g[u][i]=g[i][u]=0,dfs(i);
    }
    ans[++cnt]=u;
}

bool sol(){
    cin>>n;
    for(int i=0;i<58;i++) p[i]=i;

    int _min=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        int a=s[0]-'A',b=s[1]-'A';
        // _min=min(_min,min(a,b));
        d[a]++,d[b]++;
        st[a]=st[b]=1;
        g[a][b]=g[b][a]=1;
        p[find(a)]=find(b);
    }

    //连通性判断
    // int anc=-1;
    // for(int i=0;i<58;i++){
    //     if(anc==-1&&st[i]){
    //         anc=p[i];
    //     }
    //     else if(anc!=p[i]&&st[i]) return false;
    // }
    
    int tt=0,id=-1;
    for(int i=0;i<58;i++){
        if(d[i]%2){
            tt++;
            if(id==-1) id=i;
        }
    }
    // cout<<tt<<' '<<id<<endl;
    if(id==-1){
        for(int i=0;i<58;i++){
            if(d[i]){
                id=i;
                break;
            }
        }
    }
    if(!(tt==0||tt==2)) return false;


    dfs(id);

    return true;
}

int main(){
    if(!sol()) cout<<"No Solution"<<endl;
    else{
        for(int i=cnt;i>=1;i--){
            char ttt='A'+ans[i];
            cout<<ttt;
        }
    }
    return 0;
}