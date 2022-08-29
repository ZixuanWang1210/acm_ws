#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

void sol(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    char now=' ';
    int cnt=0;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(now==s[i]) cnt++;
        else{
            v.push_back(cnt);
            cnt=1;
            now=s[i];
        }
    }
    if(cnt) v.push_back(cnt);

    sort(_all(v),[&](int x,int y){
        return x>y;
    });

    for(auto x:v) cout<<x<<" ";

    int sum=0;
    for(int i=0;i<min(k,(int)v.size());i++){
        sum+=v[i];
    }
    cout<<sum<<endl;
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
