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

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    vector<int> v1(n+1),v2(n+1);
    map<int,int> mp;
    bool ok=true;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        mp[v[i]]++;
        if(mp[v[i]]==1) v1[i]=v[i];
        else if(mp[v[i]]==2) v2[i]=v[i];
        else ok=false;
    }
    if(!ok){
        cout<<"NO"<<endl;
        return;
    }
    set<int> st1,st2;
    for(int i=1;i<=n;i++){
        st1.insert(i);
        st2.insert(i);
    }

    for(int i=1;i<=n;i++){
        if(v1[i]!=0) st1.erase(v1[i]);
        if(v2[i]!=0) st2.erase(v2[i]);
    }

    for(int i=1;i<=n;i++){
        if(!v1[i]){
            auto it = st1.upper_bound(v[i]);
            if(it==st1.begin()){
                cout<<"No"<<endl;
                return;
            }
            it = prev(it);
            st1.erase(v1[i] = *it);
        }
        else{
            auto it = st2.upper_bound(v[i]);
            if(it==st2.begin()){
                cout<<"No"<<endl;
                return;
            }
            it = prev(it);
            st2.erase(v2[i] = *it);
        }
    }

    // for(int i=1;i<=n;i++){
    //     if(v1[i]!=0) ok=1;
    //     else{
    //         if(st1.size()==0){
    //             cout<<"NO"<<endl;
    //             return;
    //         }
    //         int x=*prev(st1.upper_bound(v2[i]));
    //         v1[i]=x;
    //         st1.erase(x);
    //     }

    //     if(v2[i]!=0) ok=1;
    //     else{
    //         if(st2.size()==0){
    //             cout<<"NO"<<endl;
    //             return;
    //         }
    //         int x=*prev(st2.upper_bound(v1[i]));
    //         v2[i]=x;
    //         st2.erase(x);
    //     }
    // }
    for(int i=1;i<=n;i++){
        if(v[i]!=max(v1[i],v2[i])){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++){
        cout<<v1[i]<<' ';
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;
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
