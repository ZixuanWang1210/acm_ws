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
    vector<int> v(n+1);
    int cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];    
        if(v[i]&1) cnt1++;
        else cnt0++;
    }
    // cout<<cnt0<<' '<<cnt1<<endl;
    // cout<<cnt1<<' '<<cnt0<<endl;
    // cout<<((int)ceil((double)n/2))<<endl;
    // if(cnt1==cnt0&&cnt1!=1) cout<<"Bob"<<endl;
    // else if(cnt1==cnt0&&cnt1==1) cout<<"Alice"<<endl;
    // else if(cnt1==0) cout<<"Alice"<<endl;
    // else if(cnt0==0&&((int)ceil((double)n/2)&1)) cout<<"Bob"<<endl;
    // else if(cnt0==0&&(((int)ceil((double)n/2)&1)==0)) cout<<"Alice"<<endl;
    // // else if(cnt1-cnt0==1) cout<<"Bob"<<endl;
    // // else if(cnt1&1==0) cout<<"Alice"<<endl;

    // // else cout<<"Alice"<<endl;
    // else if((cnt1&1)&&(cnt0&1)) cout<<"Alice"<<endl;
    // else if(((cnt1&1)==0)&&((cnt0&1)==0)) cout<<"Alice"<<endl;
    // else if((cnt1&1)&&((cnt0&1)==0)) cout<<"Bob"<<endl;
    // else if(((cnt1&1)==0)&&(cnt0&1)) cout<<"Bob"<<endl;
    // else assert(1==0);
    // int x=ceil((double)n/2);
    // int xj=min(x,cnt1);
    // cout<<xj<<endl;
    // if(xj&1) xj--;
    // int res=x-xj;
    // if(cnt0>=res) cout<<"Alice"<<endl;
    // else cout<<"Bob"<<endl;

    cnt1%=4;
    cnt0%=2;
    // cout<<cnt1<<' '<<cnt0<<endl;
    if(cnt1==0&&cnt0==0) cout<<"Alice"<<endl; //
    else if(cnt1==1&&cnt0==0) cout<<"Bob"<<endl; //
    else if(cnt1==2&&cnt0==0) cout<<"Bob"<<endl; //
    else if(cnt1==3&&cnt0==0) cout<<"Alice"<<endl; //
    else if(cnt1==0&&cnt0==1) cout<<"Alice"<<endl; //1
    else if(cnt1==1&&cnt0==1) cout<<"Alice"<<endl; //1
    else if(cnt1==2&&cnt0==1) cout<<"Bob"<<endl; //
    else if(cnt1==3&&cnt0==1) cout<<"Alice"<<endl; //1
    else assert(1==0);

}
signed main(){
    ios::sync_with_snnnnnnnnnnnnnnnnnnnnnjjjmmmmmmmmmmmmmmmmm[p8]