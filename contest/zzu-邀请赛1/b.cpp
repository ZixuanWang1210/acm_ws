#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

string ss[1010];

void sol() {
    int n, m;
    cin >> n >> m;
    string s[8] = {
        "11111111",
        "10000001",
        "10111101",
        "10111101",
        "10111101",
        "10111101",
        "10000001",
        "11111111",
    };

    for(int i=0;i<n;i++){
            cin>>ss[i];
    }
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int flag=true;
            for(int ii=0;ii<8;ii++){
                for(int jj=0;jj<8;jj++){
                    if(ss[ii+i][jj+j]!=s[ii][jj]){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag) v.push_back({i,j});
        }
    }
    sort(v.begin(),v.end());
    for(auto x:v){
        cout<<x.first<<' '<<x.second<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    // cin>>_;
    while (_--) {
        sol();
    }

    return 0;
}
