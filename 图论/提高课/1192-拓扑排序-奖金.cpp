#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;
int n,m;
int top[maxn],cnt;
int cost[maxn],din[maxn];
int e[maxn],h[maxn],ne[maxn],idx;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b; 
        add(b,a);
        din[a]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(din[i]==0){
            q.push(i);
            cost[i]=100;
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
                cost[j]=cost[t]+1;
            }
        }
    }

    if(cnt<n) cout<<"Poor Xed"<<endl;
    else{
        int res=0;
        for(int i=1;i<=cnt;i++){
            res+=cost[i];
        }
        cout<<res<<endl;
    }


    return 0;
}