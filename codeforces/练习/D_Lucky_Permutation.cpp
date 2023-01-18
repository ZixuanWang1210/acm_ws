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
const int maxn=1e6+10;
int a[maxn];
int d[maxn];
ll sz[maxn];

int find(int x){
    if(d[x]==x)
        return x;
    else
        return d[x] = find(d[x]);
}

void join(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy){
        d[fx] = fy;
        sz[fy]+=sz[fx];
    }

}

void sol(){
    int n;cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++)
        d[i] = i,sz[i] = 1;
    ll sum = 0;
    for(int i = 1;i<=n;i++){
        if(find(a[i])==find(i)){
            sum+=sz[find(a[i])]-1;
        }
        else{
            join(a[i],i);
        }
    }
    int ok = 0;
    for(int i = 1;i<n;i++){
        if(find(i)== find(i+1)){
            ok = 1;
            break;
        }
    }
    if(!ok){
        cout<<sum+1<<endl;
    }
    else{
        cout<<sum-1<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
