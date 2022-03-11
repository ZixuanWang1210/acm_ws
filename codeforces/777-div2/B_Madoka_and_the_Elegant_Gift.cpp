#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=150;



void sol(){
    int mp[maxn][maxn];
    int n,m; cin>>n>>m;
    string s; 
        getline(cin,s);
    for(int i=1;i<=n;i++){
        // string s; 
        getline(cin,s);
        for(int j=1;j<=m;j++){
            mp[i][j]=s[j-1]-'0';
        }
        // for(int j=1;j<=m;j++){
        //     cin>>mp[i][j];
        //     // cout<<mp[i][j];
        // }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            int res=mp[i][j]+mp[i+1][j]+mp[i][j+1]+mp[i+1][j+1];
            // cout<<res<<' ';
            if(res==3){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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
