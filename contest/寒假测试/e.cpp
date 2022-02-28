#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

vector<string> b,g;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        string s; cin>>s;
        if(t) b.push_back(s);
        else g.push_back(s);
    }

    for(int i=0;i<b.size();i++){
        cout<<g[i]<<' '<<b[b.size()-1-i]<<endl;
    }
    

    return 0;
}
