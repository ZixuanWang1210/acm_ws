#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;
const int N=1e3+10;
int n;
struct node{
    int v,p,k,type;
    bool operator<(const node &t) const{
        return p>t.p;
    }
};

priority_queue<node> heap,row,col;
int cntrow[N],cntcol[N];
int cntrownull[N],cntcolnull[N];
int version[2][N];
int g[N][N];

void sol(){
    cin >> n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) {
        int x;cin >> x;
        g[i][j] = x;
        if(x==-1) cntcolnull[j]++,cntrownull[i]++;
        if(x==1) cntrow[i]^=1, cntcol[j]^=1;
    }

    for(int i=1; i<=n; i++){
        if(cntcolnull[i]) heap.push({cntcolnull[i], i, 0, 1});
        if(cntrownull[i]) heap.push({cntrownull[i], i, 0, 0});
    }

    while(heap.size()){
        auto u=heap.top();
        heap.pop();
        if(version[u.type][u.p]!=u.k) continue;
        if(u.v>1) {
            cout << -1;
            return;
        }
    
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
