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
    string s1,s2;
    cin>>s1>>s2;
    bool f1=0,f2=0;
    for(int i=0;i<n;i++){
        if(s1[i]==s2[i]) f1=1;
        if(s1[i]!=s2[i]) f2=1;
    }
    if(f1&&f2){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    vector<pii> vec;

    if(f1){
        int c=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='0') vec.push_back({i+1,i+1}),c++;
        }
        if(c%2==0){
            vec.push_back({1,1});
            vec.push_back({2,n});
        }
        else{
            vec.push_back({1,n});
        }
    }
    else{
        int c=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='0'){
                vec.push_back({i+1,i+1});
                c++;
            }
        }
        if(c%2!=0){
            vec.push_back({1,1});
            vec.push_back({2,n});
        }
        else{
            vec.push_back({1,n});
        }
    }
    cout<<vec.size()<<endl;
    for(auto x:vec){
        cout<<x.first<<' '<<x.second<<endl;
    }
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
