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

const int maxn=5e5+10;

template<typename T> struct ST{
    ST(T a[], int n){
        siz = n;
        dp.resize(n+1);
        int t = __lg(n) + 1;
        for(int i= 0;i<=n;i++) dp[i].resize(t);
        for(int i = 0; i <= n; i++) dp[i][0] = a[i];
        for(int j = 1; j < t; j++) 
        {
            for(int i = 0; i <= n - (1<<j)+1; i++)
            {
                dp[i][j] = __gcd(dp[i][j-1], dp[i+(1 << (j-1))][j-1]);
            }
        }
    }
    T get(int l,int r){
	    int k = __lg(r-l+1);
	    return __gcd(dp[l][k],dp[r-(1<<k)+1][k]);
    }    
private:
    int siz = 0;
    vector<vector<T>> dp;
};

int n,m;
int a[maxn];

void sol(){
    cin>>n>>m;
    memset(a,0,sizeof a);
    map<int,int> mp;
    for(int i=1;i<=n;i++) cin>>a[i];
    ST<int> plt(a,n+100);

    auto get=[&](int L,int R,int l,int r,int x){
        // int l=L,r=R;
        int res=0;
        // int tmp=a[l];
        while(l<=r){
            int mid=(l+r)>>1;
            assert(mid>0);
            if(plt.get(L,mid)==x){
                res=l;
                l=mid+1;
            }
            else r=mid-1;
        }
        return res;
    };

    // mp[a[n]]++;
    for(int i=1;i<=n;i++){
        int l=i,r=n;
        // if(tmp==a[l]) mp[tmp]--;
        // mp[a[l]]++;
        // int tmp=__gcd(a[l],a[l+1]);
        int tmp=a[l];
        while(l<=r){
            int nw=get(i,n,l,r,tmp);
            int len=nw-l+1;
            mp[tmp]+=len;
            l=nw+1;
            tmp=__gcd(tmp,a[l]);
        }
    }
    while(m--){
        int x; cin>>x;
        cout<<mp[x]<<endl;
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
