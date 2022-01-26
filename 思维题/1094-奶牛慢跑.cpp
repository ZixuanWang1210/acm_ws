#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int,int>
using namespace std;

int n,ans;
vector<pii> v;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end());

    int _max = v[0].second;
    for(int i=1;i<v.size();i++){
        if(v[i].second>=_max){
            ans++;
            _max=v[i].second;
        }
    }
    cout<<ans;

    return 0;
}
