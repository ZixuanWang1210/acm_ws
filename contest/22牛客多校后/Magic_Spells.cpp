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

int k;
// StringHash has[5];
string s[10];

void sol(){
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>s[i];
        int n=s[i].length();
        StringHash has1(s[i].length(),s[i],131,mod);
        reverse(_all(s[i]));
        StringHash has2(s[i].length(),s[i],131,mod);
        for(int ii=1;i<=n;ii++){
            int l=1,r=s[i].length();
            while(l<r){
                int mid=l+r>>1;
                if(has1.get(ii,ii+mid)!=has2.get(n-ii+1,n-(ii+mid)+1)){
                    r=mid;
                }
                else{
                    l=mid;
                }
            }
        }


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
