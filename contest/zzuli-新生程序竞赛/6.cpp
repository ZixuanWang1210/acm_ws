#include<bits/stdc++.h>
#define int long long
using namespace std;

const int P=1000000007;
// int n;
vector<pair<pair<int,int>,string>>v;
// vector<pair<pair<int,int>,string>>
void sol(){
    int n; cin>>n;
    map<int,string> mp;
    for(int i=1;i<=n;i++){
        string name; cin>>name;
        int hh,mm,ss; scanf("%d:%d:%d",&hh,&mm,&ss);
        int time=hh*3600+mm*60+ss;
        // mp[time]=name;
        v.push_back({{time,i},name});
    }
    sort(v.begin(),v.end());
    for(auto x:v){
        cout<<x.second<<endl;
        // cout<<x.first<<endl;
    }
}

signed main(){
    // ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}