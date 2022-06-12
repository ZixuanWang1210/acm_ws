#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol(){
    int n,m; cin>>n>>m;
    vector<int> r,c;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=0;j<s.length();j++){
            if(s[j]=='B'){
                r.push_back(i);
                c.push_back(j+1);
            }
        }
    }
    sort(_all(r));sort(_all(c));
    int cnt=r.size();

    if(cnt&1){
        cout<<r[(cnt+1)/2-1]<<' '<<c[(cnt+1)/2-1]<<endl;
    }
    else cout<<(r[cnt/2-1]+r[cnt/2+1-1])/2<<' '<<(c[cnt/2-1]+c[cnt/2+1-1])/2<<endl;
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
