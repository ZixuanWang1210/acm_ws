#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v1(n+1),v2(n+1);
    for(int i=1;i<=n;i++){
        cin>>v1[i];
        v2[i]=v1[i];
    }
    sort(v1.begin()+1,v1.end());
    sort(v2.begin()+1,v2.end(),greater<int>());
    
    vector<int> ans;
    ans.push_back(v1[(n+2)/2]);
    for(int i=1;i<=ceil((double)n/2);i++){
        ans.push_back(v1[i]);
        if(n&1&&i==ceil((double)n/2)) ;
        else ans.push_back(v2[i]);;
    }
    ans.push_back(ans[1]);
    // for(auto x:ans){
    //     cout<<x<<' ';
    // }
    // cout<<endl;
    // if(ans[0]>=ans[n-1]){
    //     cout<<"NO"<<endl;
    //     return;
    // }
    // else{
        for(int i=1;i<=n;i++){
            if(ans[i]>ans[i-1]&&ans[i]>ans[i+1]){
                
            }
            else if(ans[i]<ans[i-1]&&ans[i]<ans[i+1]){}
            else {
                cout<<"NO"<<endl;
                return;
            }
        }
    // }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
