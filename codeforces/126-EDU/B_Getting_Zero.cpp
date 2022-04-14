#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;
#define pii pair<int,int>
int dist[1000000];

void sol(){
    dist[0]=0;
    queue<int> q; q.push(0);
    int cnt=0;
    while(q.size()){
        cnt++;
        int v=q.front();
        q.pop();
        if(v%2==0&&dist[v/2]==-1) dist[v/2]=dist[v]+1,q.push(v/2);
        if(v%2==0&&dist[(v+32768)/2]==-1) dist[(v+32768)/2]=dist[v]+1,q.push((v+32768)/2);
        if(dist[(v+32767)%32768]==-1) dist[(v+32767)%32768]=dist[v]+1,q.push((v+32767)%32768);
    }
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(dist,-1,sizeof dist);
    sol();
    int t; cin>>t;

    while(t--){
        int x; cin>>x;
        cout<<dist[x]<<' ';
    }

    return 0;
}

