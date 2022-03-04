#include<bits/stdc++.h>
using namespace std;

const int maxn=30010;
int e[maxn],ne[maxn],h[maxn],idx;
int n,m;
int din[maxn],top[maxn],cnt;
bitset<maxn> dp[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        add(x,y);
        din[y]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(din[i]==0){
            q.push(i);
        }
    }

    while(q.size()){
        int t=q.front(); q.pop();
        top[++cnt]=t;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            din[j]--;
            if(din[j]==0){
                q.push(j);
            }
        }
    }

    for(int i=n;i>=0;i--){
        int j=top[i];   
        dp[j][i]=1;

        for(int k=h[j];~k;k=ne[k]){
            dp[j]|=dp[e[k]];
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i].count()<<endl;
    }

    return 0;
}