#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v1(2*n),v2(2*n);
    map<int,int> mp;
    multiset<int> s1,s2;
    int idx=0;
    for(int i=1;i<=n;i++){
        cin>>v1[i];
        s1.insert(v1[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>v2[i];
        if(mp[v2[i]]==0) mp[v2[i]]=idx++;
        // if(s.count(v2[i])==0){
        //     cout<<"NO"<<endl;
        //     return;
        // }
        s2.insert(v2[i]);
    }

    if(s1!=s2){
        cout<<"NO"<<endl;
        return;
    }
    // cout<<"YES"<<endl;

    for(int i=1;i<=n;i++){
        v1[i]=mp[v1[i]];
    }
    cout<<"YES"<<endl;
    while(!is_sorted(v1.begin()+1,v1.begin()+1+n)){
       for(int i=1;i<=n-1;i++){
           if(v1[i]>v1[i+1]){
               cout<<i<<' '<<i+1<<endl;
               swap(v1[i],v1[i+1]);
           }
       }
   }
   cout<<"0 0"<<endl;

    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
