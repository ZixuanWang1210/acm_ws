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

bool has(int x){
    while(x){
        int res=x%16;
        if(res>=10) return false;
        x/=16;
    }
    return true;
}

const int maxn=1e6+10;
int a[maxn];
void init(){
    for(int i=1;i<=maxn;i++){
        a[i]=has(i);
        a[i]+=a[i-1];
    }
}

void sol(){
    int l,r; cin>>l>>r;
    cout<<a[r]-a[l-1]<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    init();
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
