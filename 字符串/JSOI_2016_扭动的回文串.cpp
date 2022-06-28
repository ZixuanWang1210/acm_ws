#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 10000000007
#define ll long long
// #define int long long

using namespace std;

int n,q;
string s,t;

struct StringHash{
    // 下标从1开始
    StringHash(int n,string s,int b,ll m){
        int len=s.length();
        s=' '+s;

        h.resize(n+1),w.resize(n+1);
        h[0]=0, w[0]=1, base=b, P=m;

        for(int i=1; i<=len; i++)
            h[i] = (h[i-1]*base+s[i])%P, w[i]=w[i-1]*base%P;
    }

    ll get(int l, int r){
        return (h[r]-h[l-1]*w[r-l+1]%P+P)%P;
    }
private:
    ll base, P;
    vector<ll> h,w;
};

void sol(){
    cin>>n>>q;
    cin>>s;

    StringHash S(n,s,131,mod);
    
    while(q--){
        cin>>t;
        int m=t.length();
        StringHash T(m,t,131,mod);
        bool ok=false;
        for(int i=m;i<=n;i++){
            if(S.get(i-m+1,i)==T.get(1,m)){
                cout<<"YES"<<endl;
                ok=true;
                break;
            }
        }
        if(!ok) cout<<"NO"<<endl;
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;/
    while(_--){
        sol();
    }

    return 0;
}
