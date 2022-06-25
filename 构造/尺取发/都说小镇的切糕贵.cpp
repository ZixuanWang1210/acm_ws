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
int cnt[1000]={0};

void sol(){
    int n; cin>>n;
    string s; cin>>s;
    set<char> st;
    for(int i=1;i<=n;i++) st.insert(s[i]);
    int num= st.size();
    st.clear();

    s=' '+s;
    int l=1,r=1;
    int ans=inf;
    while(l<=r&&r<=n){
        st.insert(r);
        int x=s[r]-'A';
        cnt[x]++;
        while(st.size()==num){
            ans=min(ans,r-l+1);
            cnt[s[l]-'A']--;
            if(!cnt[s[l]-'A']) st.erase(s[l]);
            l++;
        }
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
