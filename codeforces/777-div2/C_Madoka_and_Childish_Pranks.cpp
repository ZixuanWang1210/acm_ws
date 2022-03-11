#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

struct ans{
    int a,b,c,d;
    bool operator<(const ans &t) const{
        if(a==t.a){
            return b>t.b;
        }
        return a>t.a;
    }
};

const int maxn=200;

void sol(){
    int mp[maxn][maxn];
    int n,m; cin>>n>>m;
    string s; 
    getline(cin,s);
    for(int i=1;i<=n;i++){
        getline(cin,s);
        for(int j=1;j<=m;j++){
            mp[i][j]=s[j-1]-'0';
        }
    }
    if(mp[1][1]==1){
        cout<<-1<<endl;
        return;
    }
    vector<ans> v;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            if(mp[i][j]==0&&mp[i][j+1]==1&&mp[i+1][j]==1&&mp[i+1][j+1]==0){
                v.push_back({i,j,i+1,j+1});
                mp[i][j+1]=0;
                mp[i+1][j]=0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-1;j++){
            if(mp[i][j]==0&&mp[i][j+1]==1){
                v.push_back({i,j,i,j+1});
                mp[i][j+1]=0;
            }
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]==0&&mp[i+1][j]==1){
                v.push_back({i,j,i+1,j});
                mp[i+1][j]=0;
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m-1;j++){
    //         if(mp[i][j]==1&&mp[i-1][j]==0&&i-1>=1){
    //             // cout<<i-1<<j<<i<<j<<endl;
    //             v.push_back({i-1,j,i,j});
    //             mp[i][j]=0;
    //         }
    //         if(mp[i][j]==1&&mp[i][j-1]==0&&j-1>=1){
    //             // cout<<i<<j-1<<i<<j<<endl;
    //             v.push_back({i,j-1,i,j});
    //             mp[i][j]=0;
    //         }
    //     }
    // }
    sort(v.begin(),v.end());
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //        if(mp[i][j]){
    //            cout<<-1<<endl;
    //            return;
    //        }
    //     }
    // }
    cout<<v.size()<<endl;
    for(auto x:v){
        cout<<x.a<<' '<<x.b<<' '<<x.c<<' '<<x.d<<endl;
    }
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
