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
    int n ; cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    int ans[5]={0};
    int p=0;
    for(int i=1;i<=n;i++){
        ans[0]++;
        for(int j=3;j>=0;j--){
            if(ans[j]){
                if(j+v[i]>3){
                    p+=ans[j],ans[j]=0;        
                }
            }
            else ans[j+v[i]]+=ans[j],ans[j]=0;
        }
    }


    cout<<p<<endl;

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