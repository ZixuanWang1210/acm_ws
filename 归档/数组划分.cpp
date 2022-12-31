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

int n; 
unordered_map<int,int> s;
int x;

void sol(){
    cin>>n;
    for(int ii=1;ii<=n;ii++){
        cin>>x;
        for(int i=2;i<=x/i;i++){
            if(x%i==0){
                while(x&i==0) x/=i;
                s[i]++;
            }
        }
        if(x>1) s[x]++;
    }
    for(int ii=1;ii<=n;ii++){
        cin>>x;
        for(int i=2;i<=x/i;i++){
            if(x%i==0){
                while(x&i==0) x/=i;
                if(s[i]){
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
        if(x>1) if(s[x]){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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
