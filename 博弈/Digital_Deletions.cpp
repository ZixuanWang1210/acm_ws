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

const int maxn=1e6+10;
int f[maxn];

void init(){
    f[0]=1;
    for(int i=1;i<=1000000;i++){
        int x=i,ten=1;
        while(x){
            int dig=x%10;
            x/=10;
            if(dig==0){
                f[i]|=(f[x]==0);
            }else{
                for(int j=0;j<dig;j++){
                    if(x==0&&j==0) continue;
                    f[i]|=(f[i-dig*ten+j*ten]==0);
                }
            }
            ten*=10;
        }
    }
}

void sol(){
    string s; cin>>s;
    if(s[0]=='0'){
        cout<<"Yes"<<endl;
        return;
    }
    int x=0;
    for(int i=0;i<s.length();i++){
        x*=10;
        x+=s[i]-'0';
    }
    if(f[x]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    init();
    while(_--){
        sol();
    }

    return 0;
}
