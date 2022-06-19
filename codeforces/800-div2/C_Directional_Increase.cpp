#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n);
    int cnt=-1;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]!=0) cnt=max(cnt,i);
    }
    if(cnt==-1){
        cout<<"YES"<<endl;
        return;
    }
    if(v[cnt]>0){
        cout<<"NO"<<endl;
        return;
    }
    int sum=0;
    for(int i=0;i<cnt;i++){
        sum+=v[i];
        if(sum<0){
            cout<<"NO"<<endl;
            return;
        }
        if(sum==0&&i!=cnt){
            cout<<"NO"<<endl;
            return;
        }
    }
    if(sum!=-v[cnt]) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;


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
