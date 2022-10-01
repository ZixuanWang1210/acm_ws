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
    int b,r,d,s; cin>>b>>r>>d>>s;
    if(r==0){
        if(d!=0) cout<<"gua!"<<endl;
        else cout<<"ok"<<endl;
        return;
    }
    int t=r*s/60+1;
    t*=b;
    if(t<d) cout<<"gua!"<<endl;
    else cout<<"ok"<<endl;
    // b/=s;
    // int t=ceil((double)d/b);
    // int bz=ceil((double)r/60);
    // cout<<t<<' '<<bz<<endl;
    //19 18
    // if(t>bz) cout<<"gua!"<<endl;
    // else cout<<"ok"<<endl;

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
