#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N=2510,M=6200*2+10;
int h[N],e[M],ne[M],idx;
int w[M],dis[M],st[N];
int t,c,S,T;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void spfa(){
    memset(dis,0x3f,sizeof dis);
    dis[S]=0;
    queue<int>q;
    q.push(S);
    st[S]=true;
    while(q.size()){
        int top=q.front();q.pop();st[top]=false;
        for(int i=h[top];i!=-1;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[top]+w[i]){
                dis[j]=dis[top]+w[i];
                if(!st[j]){
                    st[j]=true;
                    q.push(j);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t>>c>>S>>T;
    memset(h,-1,sizeof h);
    for(int i=0;i<c;i++){
        int a,b,c;cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }

    spfa();

    cout<<dis[T];

    return 0;
}
