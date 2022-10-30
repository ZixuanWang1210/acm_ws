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

map<string,int> mp;
void sol(){
    string a,b; cin>>a>>b;
    string s;
    for(int i=0;i<4;i++){
        s+='0'+(a[i]-b[i]+10)%10;
    }
    cout<<mp[s]<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    mp["0000"]=0;
    queue<string> q;
    q.push("0000");
    while(q.size()){
        string t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            for(int j=i;j<4;j++){
                string f=t,e=t;
                for(int k=i;k<=j;k++){
                    f[k]='0'+(f[k]-'0'+1)%10;
                    e[k]='0'+(e[k]-'0'+9)%10;
                }
                if(mp.count(f)==0){
                    mp[f]=mp[t]+1;
                    q.push(f);
                }
                if(mp.count(e)==0){
                    mp[e]=mp[t]+1;
                    q.push(e);
                }
            }
        }

    }
    while(_--){
        sol();
    }

    return 0;
}
