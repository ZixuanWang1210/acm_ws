#include<bits/stdc++.h>
using namespace std;

int n,m;

bool st[1000];
int cnt=0;
void dfs(int x){
    if(x==n+1&&cnt==m){
        for(int i=1;i<=n;i++){
            if(st[i]) cout<<i<<" ";
        }
        cout<<endl;
    }
    if(cnt<m){
        st[x]=true;
        dfs(x+1);
    }
    st[x]=false;
    dfs(x+1);
}

int main(){
    cin>>n>>m;
    dfs(1);

    return 0;
}