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
    int n; cin>>n;
    vector<pair<string,string>> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i].first>>v[i].second;
    }

    for(int i=1;i<=n;i++){
        set<string> s;
        s.insert(v[i].second);
        for(int j=i+1;j<=n;j++){
            if(v[i].first!=v[j].first) continue;
            else if(s.count(v[j].second)){
                break;
            }
            else {
                s.insert(v[j].second);
                if(s.size()==5){
                    cout<<"PENTA KILL!"<<endl;
                    return;
                }
            }

        }
    }

    cout<<"SAD:("<<endl;
    return;
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
