#include <bits/stdc++.h>
#define endl "\n"
#define pii pair<int,int>
using namespace std;

int n;
string s;
const int maxn=2e6+10;
unordered_map<int,vector<pii>> mp;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        mp[y].push_back({x,i-1});
    }
    cin>>s;

    

    for(auto x:mp){
        if(x.second.size()>=2){
            sort(x.second.begin(),x.second.end());
            bool bz=false;
            for(auto i:x.second){
                if(bz&&s[i.second]=='L'){
                    cout<<"Yes"<<endl;
                    return 0;
                }
                if(s[i.second]=='R') bz=true;
            }
        }
    }
    cout<<"No"<<endl;

    return 0;
}
