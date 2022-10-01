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
    int n,x,y; cin>>n>>x>>y;
    string s1,s2; cin>>s1>>s2;
    int cnt1=0,cnt2=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s1[i]!=s2[i]) cnt++;
    }
    if(cnt&1){
        cout<<-1<<endl;
        return;
    }
    else{
        if(2*y<=x){
            cout<<y*cnt<<endl;
            return;
        }
        else{
            int res=0;
            for(int i=1;i<n;i++){
                if(s1[i-1]!=s2[i-1]&&s1[i]!=s2[i]) {res+=x,cnt-=2;i++;}
            }
            res+=cnt*y;
            cout<<res<<endl;
        }
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
