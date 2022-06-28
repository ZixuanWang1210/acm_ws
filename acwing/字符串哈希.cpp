#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define LL long long
// #define int long long

using namespace std;

struct StringHash{
    StringHash(int n,string s,int b,int m){
        int len=s.length();
        s=' '+s;

        h.resize(n+1),w.resize(n+1);
        h[0]=0, w[0]=1, base=b, P=m;

        for(int i=1; i<=len; i++)
            h[i] = (h[i-1]*base+s[i])%P, w[i]=w[i-1]*base%P;
    }

    LL get(int l, int r){
        return (h[r]-h[l-1]*w[r-l+1]%P+P)%P;
    }
private:
    LL base, P;
    vector<LL> h,w;
};

void sol(){
    int n,m; cin>>n>>m;
    string s; cin>>s;

    StringHash has(n,s,1331,(1234452341));

    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(has.get(l1,r1)==has.get(l2,r2)) puts("Yes");
        else puts("No");
    }

}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
