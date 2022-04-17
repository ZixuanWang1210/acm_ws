#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int g[maxn][1000];
int cd[maxn];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        for(int j=1;j<=t;j++){
            int x; cin>>x;
            g[i][j]=x;
        }
    }
    int now=1;
    for(int i=1;i<=m;i++){
        int op; cin>>op;
        if(op==0){
            int x; cin>>x;
            now=g[now][x];
        }
        else if(op==1){
            int j; cin>>j;
            cd[j]=now;
            cout<<now<<endl;
        }
        else{
            int j; cin>>j;
            now=cd[j];
        }
    }
    cout<<now;
    return 0;
}