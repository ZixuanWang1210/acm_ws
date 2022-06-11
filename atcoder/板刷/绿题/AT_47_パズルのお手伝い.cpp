#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

const int maxn=30;
int mp[maxn][maxn];
int c[maxn],row[maxn],r[maxn],l[maxn];

void _debug(){
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(mp[i][j]==1){
                cout<<'Q';
            }
            else cout<<'.';
        }
        cout<<endl;
    }
    cout<<endl;
}

bool dfs(int x){
    if(x==9){
        _debug();
        exit(0);
    }
    if(row[x]) dfs(x+1);
    for(int i=1;i<=8;i++){
        if(!row[x]&&!c[i]&&!l[i+x]&&!r[x-i+8]) {

            row[x]=1,c[i]=1,l[i+x]=1,r[x-i+8]=1;
            mp[x][i]=1;
            //  _debug();
            dfs(x+1);
            mp[x][i]=0;
            row[x]=0,c[i]=0,l[i+x]=0,r[x-i+8]=0;
        }
    }
    return false;
}

void sol(){
    bool flag=false;
    for(int i=1;i<=8;i++){
        string s; cin>>s;
        for(int j=1;j<=8;j++){
            char x=s[j-1];
            if(x=='.') mp[i][j]=0;
            else{
                if(row[i]||c[j]||l[i+j]||r[i-j+8]) flag=true;
                row[i]=1,c[j]=1,l[i+j]=1,r[i-j+8]=1;
                mp[i][j]=1;
            }
        }
    }    
    //  _debug();
    if(flag){
        cout<<"No Answer"<<endl;
        return ;
    }
    dfs(1);
    cout<<"No Answer"<<endl;

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
