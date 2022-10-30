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
    StringHash(string s,int b=13331,LL m=LLONG_MAX){
        int n=s.length();
        s=' '+s;
        h.resize(n+1),w.resize(n+1);
        h[0]=0, w[0]=1, base=b, P=m;
        for(int i=1; i<=n; i++)
            h[i] = (h[i-1]*base+s[i])%P, w[i]=w[i-1]*base%P;
    }

    LL get(int l, int r){
        return (h[r]-h[l-1]*w[r-l+1]%P+P)%P;
    }
private:
    LL base, P;
    vector<LL> h,w;
};
string s;
const int maxn=2e6+10;
int ans[maxn];

void sol(){
    cin>>s;
    int n=s.length();
    StringHash plt(s);
    for(int i=1;i<=n/2;i++){
        if(plt.get(1,i)==plt.get(n-i+1,n)){
            ans[i]=ans[i-1]+1;
        }
        else ans[i]=ans[i-1];
    }
    int m; cin>>m;
    while(m--){
        int pos;
        cin>>pos;
        cout<<ans[min(pos-1,n-pos)]<<endl;
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
