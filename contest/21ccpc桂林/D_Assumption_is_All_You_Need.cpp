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

void sol(){
    int n; cin>>n;
    vector<int> A(n+1),B(n+1);
    map<int,int> mp;
    for(int i=1;i<=n;i++) cin>>A[i],mp[A[i]]=i;
    for(int i=1;i<=n;i++) cin>>B[i];

    bool ok=false;
    vector<pii> res;
    for(int i=n;i>=1;i--){
        if(A[i]>B[i]){
            ok=true;
            break;
        }
        else if(A[i]<B[i]){
            vector<int> mx(n+1,0);
            int r=i-1,l=mp[B[i]];
            int x=B[i];
            int pos=mp[B[i]];
            mx[i]=i;
            for(int j=r;j>=l;j--){
                if(A[j]<B[i]&&A[j]>A[mx[j+1]]) mx[j]=j;
                else mx[j]=mx[j+1];
            }
            while(pos<i){
                int x=pos,y=mx[pos+1];
                res.push_back({x,y});
                swap(A[x],A[y]);
                mp[A[x]]=x;
                mp[A[y]]=y;
                pos=mx[pos+1];
            }
        }
    }
    if(ok) cout<<-1<<endl;
    else{
        cout<<res.size()<<endl;
        for(auto x:res){
            cout<<x.first<<' '<<x.second<<endl;
        }
    }
    return ;
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
