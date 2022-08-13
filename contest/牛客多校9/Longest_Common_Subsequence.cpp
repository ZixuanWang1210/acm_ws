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

int n,m,p,x,a,b,c;

int f(int x){
    return (a*x*x+b*x+c)%p;
}

void sol(){
    cin>>n>>m>>p>>x>>a>>b>>c;

    // set<int> st;
    unordered_map<int,int> mp;
    int cnt=0;
    while(1){
        x=f(x);
        if(mp[x]==1){
            break;
        }
        else mp[x]=1,cnt++;

        if(cnt>=m+n){
            cout<<0<<endl;
            return;
        }
    }
    int siz=mp.size();
    int res1=n/siz*siz,res2=(m+n-((n+siz-1)/siz)*siz)/siz*siz;
    cout<<min(res1,res2)<<endl;

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
