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

void sol(){
    int n; cin>>n;
    string s; cin>>s;
    char c1=s[0],c11=s[n-1];
    vector<int> v1,v2;
    int cnt1=0,cnt2=0;
    v1.push_back(0);
    v2.push_back(0);
    for(int i=1;i<n;i++){
        int a=s[i-1]-'0';
        int b=s[i]-'0';
        int x=a^b;
        if(x) cnt1++;
        v1.push_back(x);
    }

    cin>>s;
    char c2=s[0],c22=s[n-1];
    for(int i=1;i<n;i++){
        int a=s[i-1]-'0';
        int b=s[i]-'0';
        int x=a^b;
        if(x) cnt2++;
        v2.push_back(x);
    }
    if(cnt1!=cnt2||(c1!=c2||c11!=c22)){
        cout<<-1<<endl;
        return;
    }
    n=v1.size()-1;
    // cout<<n<<endl;
    int tt=0,ttt=0;
    vector<int> vvv,vvvv;
    for(int i=1;i<=n;i++){
        if(v1[i]==1) vvv.push_back(i);
        if(v2[i]==1) vvvv.push_back(i);
        // if(!v1[i]) tt+=i;
        // if(!v2[i]) ttt+=i;
    }
    int res=0;
    for(int i=0;i<vvv.size();i++){
        res+=abs(vvv[i]-vvvv[i]);
    }
    cout<<res<<endl;
    // cout<<abs(tt-ttt)<<endl;
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
