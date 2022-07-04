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

const int maxn=3e5+10;
int cnt_1[maxn],cnt_0[maxn];
int n;
string s;

void sol(){
    cin>>n;
    cin>>s;
    s=' '+s;
    int ans=0;
    int flag=-1;
    for(int i=1;i<=n;i++){
        if(s[i]=='A'){
            cnt_1[i]=cnt_1[i-1]+1;
            if(cnt_1[i]==1){
                ans+=cnt_0[i-1];
            }  
        }

        else{
            cnt_0[i]=cnt_0[i-1]+1;
            if(cnt_0[i]==1){
                ans+=cnt_1[i-1];
            }
        }
        if(s[i]!=s[i-1]) flag++;
    }
    // cout<<ans<<endl;
    reverse(s.begin()+1,s.end());
    memset(cnt_1,0,sizeof cnt_1);
    memset(cnt_0,0,sizeof cnt_0);

    for(int i=1;i<=n;i++){
        if(s[i]=='A'){
            cnt_1[i]=cnt_1[i-1]+1;
            if(cnt_1[i]==1){
                ans+=cnt_0[i-1];
            }  
        }

        else{
            cnt_0[i]=cnt_0[i-1]+1;
            if(cnt_0[i]==1){
                ans+=cnt_1[i-1];
            }
        }
    }

    cout<<n*(n-1)/2-ans+flag<<endl;


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
