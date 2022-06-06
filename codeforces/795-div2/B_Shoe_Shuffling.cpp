#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    #define pii pair<int,int> 
    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<int> ans;

    for(int i=1;i<=n;i++){
        int j=i,cnt=0;
        while(v[i]==v[j]) j++,cnt++;
        j--;
        if(cnt==1){
            cout<<-1<<endl;
            return ;
        }
        ans.push_back(j);
        for(int ii=i;ii<=j-1;ii++){
            ans.push_back(ii);
        }
        i=j;
    }
    for(auto x:ans){
        cout<<x<<" ";
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
