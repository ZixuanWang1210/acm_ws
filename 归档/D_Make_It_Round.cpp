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

map<int,int> dev(int x){
    map<int,int> mp;
    if(x<2) mp[x]++;
    for(int i=2;i<=x/i;i++){
        int cnt=0;
        while(x%i==0){
            cnt++;
            x/=i;
        }
        if(cnt) mp[i]+=cnt;
    }
    if(x>1) mp[x]++;
    return mp;
}

void sol(){
    int n,k; cin>>n>>k;
    auto mp=dev(n);
    int cnt=0;
    int kk=1;
    if(mp[2]>=mp[5]){
        int det=mp[2]-mp[5];
        cnt+=mp[5];
        while(k&&det) {
            if(k/5==0) break;
            k/=5,det--,cnt++,kk*=5;
        }
        while(k) {
            if(k/10==0) break;
            k/=10,cnt++,kk*=10;
        }
        kk*=k;
        cout<<kk*n<<endl;
    }
    else if(mp[2]<mp[5]){
        int det=mp[5]-mp[2];
        cnt+=mp[2];
        while(k&&det) {
            if(k/2==0) break;
            k/=2,det--,cnt++,kk*=2;
        }
        while(k) {
            if(k/10==0) break;
            k/=10,cnt++,kk*=10;
        }
        kk*=k;
        cout<<kk*n<<endl;
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
