#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=100;
int e[maxn],ne[maxn],h[maxn],idx;
int n;
int din[maxn];
int ans[maxn],cnt;

queue<int> q;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int t=0;
        
        while(cin>>t,t){
            // cout<<t<<endl;
            add(i,t);
            din[t]++;
        }
        // cout<<t<<endl;
    }

    for(int i=1;i<=n;i++){
        if(din[i]==0){
            q.push(i);
        }
    }

    while(q.size()){
        int tt=q.front(); q.pop();
        ans[++cnt]=tt;
        for(int i=h[tt];~i;i=ne[i]){
            int j=e[i];
            din[j]--;
            if(din[j]==0) q.push(j);
        }
    }
    
    for(int i=1;i<=cnt;i++) cout<<ans[i]<<" ";
    
    return 0;
}
