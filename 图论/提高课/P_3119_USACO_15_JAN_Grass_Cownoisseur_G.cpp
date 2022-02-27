#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=100100*42+10,M=500500*42+10; //容易爆空间
int e[M],ne[M],h[N],w[M],idx;
bool st[N];
int dis[N];
int n,p,k;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

// void dij(){
//     memset(dis,0x3f,sizeof dis);
//     dis[1]=0;
//     priority_queue<pii,vector<pii>,greater<pii>> pq;
//     pq.push({0,1});

//     while(pq.size()){
//         auto t=pq.top(); pq.pop();
//         int ver=t.second, d=t.first;
//         if(st[ver]) continue;
//         st[ver]=true;
//         for(int i=h[ver];~i;i=ne[i]){
//             int j=e[i];
//             if(dis[j]>dis[ver]+w[i]){
//                 dis[j]=dis[ver]+w[i];
//                 pq.push({dis[j],j});
//             }
//         }
//     }
// }

void spfa(){
    memset(dis,-0x3f,sizeof dis);
    queue<int>q;
    q.push(1);
    st[1]=true;
    dis[1]=0;

    while(q.size()){
        int t=q.front(); q.pop(); st[t]=false;
        cout<<t<<endl;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]<dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
                if(!st[j]){
                    st[j]=true;
                    q.push(j);
                }
            }
        }
    }
}


int main(){
    cin>>n>>p;
    memset(h,-1,sizeof h);
    for(int i=1;i<=p;i++){
        int a,b,l; cin>>a>>b;
        add(a,b,1);
        add(b,a+n,0);
        add(a+n,b+n,1);

    }
    cout<<2<<endl;
    spfa();

    // cout<<dis[(k+1)*n]<<endl;
    int ans=dis[n+1];
    // for(int i=1;i<=k;i++){
	// 	// cout<<"### dis["<<i*n+n<<"]: "<<dis[i*n+n]<<endl;
    //     ans=min(dis[i*n+n],ans);
    // }
    cout<<ans;

    return 0;
}