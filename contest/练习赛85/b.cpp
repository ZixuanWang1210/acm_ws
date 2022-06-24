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

int n,m;
const int maxn=3e7+10;
int a[maxn];
int cnt[300];
int lm[maxn],rm[maxn];

void sol(){
    cin>>n>>m;
    string s; cin>>s;   
    s=' '+s;
    int l=1,r=1;
    while(l<=r&&r<=n){
        int x=s[r]-'a';
        cnt[x]++;
        while(cnt[x]>m) cnt[s[l]-'a']--,l++;
        int len=r-l+1;
        lm[r]=len;
        r++;
    }
    for(int i=1;i<=n;i++) lm[i]=max(lm[i-1],lm[i]);

    memset(cnt,0,sizeof cnt);
    l=r=n;
    while(l>=1&&l<=r){
        int x=s[l]-'a';
        cnt[x]++;
        while(cnt[x]>m) cnt[s[r]-'a']--,r--;
        int len=r-l+1;
        rm[l]=len;
        l--;
    }
    for(int i=n;i>=1;i--) rm[i]=max(rm[i+1],rm[i]);

    memset(cnt,0,sizeof cnt);
    l=r=1;
    int ans=0;
    while(l<=r&&r<=n){
        int x=s[r]-'a';
        cnt[x]++;
        while(cnt[x]>m) cnt[s[l]-'a']--,l++;
        int len=r-l+1;
        ans=max(ans,lm[l-1]+rm[r+1]+len);
        r++;
    }
    cout<<ans<<endl;
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
