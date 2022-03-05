#include<bits/stdc++.h>
using namespace std;

int n,m,k,cnt;
const int maxn=1100;
int g[maxn][maxn];
int match[maxn];
bool st[maxn];

bool find(int x){
    for(int i=0;i<m;i++){
        if(!st[i]&&g[x][i]){
            st[i]=true;
            int t=match[i];
            if(t==-1||find(t)){
                match[i]=x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    while(cin>>n,n){
        cin>>m>>k;
        memset(g,0,sizeof g);
        memset(match,-1,sizeof match);
        while(k--){
            int i,a,b; cin>>i>>a>>b;
            if(!a||!b) continue;
            g[a][b]=1;
        }
        cnt=0;
        memset(match,-1,sizeof match);
        for(int i=1;i<=n;i++){
            memset(st,0,sizeof st);
            if(find(i)) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}