#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int cnt_s=0;
    int a,b,n;
    cin>>a>>b>>n;
    cnt_s=n/(a*5+b*2);
    // cout<<cnt_s<<endl;
    int res=n-cnt_s*(a*5+b*2);
    cnt_s*=7;
    // cout<<res<<endl;
    for(int i=1;i<=7;i++){
        if(i==6||i==7){
            res-=b;
            cnt_s++;
        }
        else res-=a,cnt_s++;
        if(res<=0) break;
    }
    cout<<cnt_s<<endl;
    return 0;
}