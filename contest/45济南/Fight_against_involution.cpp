#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<pair<int,int>,int> 
using namespace std;

const int maxn=10;
int n;
pii seg[maxn];
vector<int> v[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int rk=0;
    int re=-1;
    cin>>n;
    for(int i=1;i<=n;i++){
        int l,r; cin>>l>>r;
        // if(re==-1||re!=r) rk++,re=r;
        if(re==-1||re!=r) rk++,re=r;
        // seg[i]={{l,r},rk};
        v[rk].push_back(l);

    }
    int ans=0,now=0;
    int _min=0x3f3f3f3f;
    re=-2;
    for(int i=1;i<=rk;i++){
        auto x=v[i];
        int now=*max_element(x.begin(),x.end());
        if(re==-2){
            re=now;
        }
        for(auto xx:x){
            if(xx<=re+2) ans+=re+1;
            else ans+=now;
            // ans+=now;
        }
        re=now;
    }
    cout<<ans<<endl;
    // re=-1;
    // for(int i=1;i<=n;i++){
    //     if(re==-1||re==seg[i].second){
    //         ans+=seg[i].first.first;
    //         re=seg[i].second;
    //         now=seg[i].first.first;
    //     }
    //     else{
    //         now++;
    //         if(now<seg[i].first.first) now=seg[i].first.first;
    //         ans+=now;
    //         re=seg[i].second;
    //     }
    // }

    // cout<<ans<<endl;
    

    return 0;
}
