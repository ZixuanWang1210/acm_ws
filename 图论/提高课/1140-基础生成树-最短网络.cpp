#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

const int N=110;
int g[N][N];
int n;
int dis[N];
bool st[N];

int prim(){
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    // st[1]=true;
    int ans=0;

    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dis[t]>dis[j])){
                t=j;
            }
        }
        ans+=dis[t];
        st[t]=true;
        for(int j=1;j<=n;j++) dis[j]=min(dis[j],g[t][j]);
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }

    cout<<prim()<<endl;
    

    return 0;
}
