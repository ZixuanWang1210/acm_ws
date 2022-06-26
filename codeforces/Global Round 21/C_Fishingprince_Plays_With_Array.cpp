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

int q_mi(int a,int b){
    int res=1;
    while(b){
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

vector<pii> v3,v4;
vector<pii> v5,v6;

void sol(){
    v3.clear(),v4.clear();
    v5.clear(),v6.clear();

    int n,k; cin>>n>>k;
    int sum1=0,sum2=0;
    
    vector<int> v,v1;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        sum1+=x;
        int cnt=0;
        if(x%k) v3.push_back({x,1});
        else{
            while(x%k==0){
                cnt++;
                x/=k;
            }
            // mp[x]+=q_mi(k,cnt);
            v3.push_back({x,q_mi(k,cnt)});
            // for(int i=1;i<=q_mi(k,cnt);i++){
            //     v3.push_back(x);
            // }
        }
    }
    int m; cin>>m;
    for(int i=1;i<=m;i++){
        int x; cin>>x;
        sum2+=x;
        int cnt=0;
        if(x%k) v4.push_back({x,1});
        else{
            while(x%k==0){
                cnt++;
                x/=k;
            }
            // mp[x]+=q_mi(k,cnt);
            v4.push_back({x,q_mi(k,cnt)});
            // for(int i=1;i<=q_mi(k,cnt);i++){
            //     v4.push_back(x);
            // }
        }
    }
    // for(int i=0;i<)
    if(sum1!=sum2){
        cout<<"NO"<<endl;
        return;
    }
    int now=-1;
    int cnt=0;
    bool bz=false;
    for(int i=0;i<(int)v3.size();i++){
        if(v3[i].first!=now){
            v5.push_back({now,cnt});
            now=v3[i].first;
            cnt=v3[i].second;
            if(i==v3.size()-1) bz=true;
        }
        else{
            cnt+=v3[i].second;
            // if(i==v3.size()-1) bz=true;
        }
    }
    if(!bz) v5.push_back({now,cnt});

    now=-1;
    cnt=0;
    bz=false;
    for(int i=0;i<(int)v4.size();i++){
        if(v4[i].first!=now){
            v6.push_back({now,cnt});
            now=v4[i].first;
            cnt=1;
            cnt=v4[i].second;
            if(i==v4.size()-1) bz=true;
        }
        else cnt+=v4[i].second;
    }
    if(!bz) v6.push_back({now,cnt});

    if(v5==v6) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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
