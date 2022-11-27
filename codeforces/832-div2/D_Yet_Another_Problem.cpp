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
    int n,q; cin>>n>>q;
    vector<int> v(n+1),x(n+1),s(n+1);
    map<int,vector<int>> mp1,mp2;
    for(int i=1;i<=n;i++){
        cin>>v[i],s[i]=s[i-1]+v[i],x[i]=x[i-1]^v[i];
        if(i&1) mp1[x[i]].push_back(i);
        else mp2[x[i]].push_back(i);
    }

    while(q--){
        int l,r; cin>>l>>r;
        int len=r-l+1;
        if(x[r]^x[l-1]){
            cout<<-1<<endl;
            continue;
        }
        if(s[r]==s[l-1]){
            cout<<0<<endl;
            continue;
        }
        if(len&1){
            cout<<1<<endl;
            continue;
        }
        // while(s[l]==s[l-1]) l++,len--;
        // while(s[r]==s[r+1]) r--,len--;
        if(!v[l]||!v[r]){
            cout<<1<<endl;
            continue;
        }
        if(len&1){
            cout<<1<<endl;
            continue;
        }
        if((l-1)&1){
            auto it=lower_bound(_all(mp2[x[l-1]]),l-1);
            if(it!=mp2[x[l-1]].end()&&*it<r){
                cout<<2<<endl;
                continue;
            }
        }
        else{
            auto it=lower_bound(_all(mp1[x[l-1]]),l-1);
            if(it!=mp1[x[l-1]].end()&&*it<r){
                cout<<2<<endl;
                continue;
            }
        }
        cout<<-1<<endl;
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
