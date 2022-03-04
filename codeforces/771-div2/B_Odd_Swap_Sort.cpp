#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;

using namespace std;

const int maxn=2e6+10;
int n;
ll a[maxn];

void sol(){
    // memset(a,0,sizeof a);
    
    cin>>n;
    for(int i=0;i<=2*n;i++){
        a[i]=0;
    }
    ll re=-1;
    bool falg=false;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(re>a[i]){
            // cout<<i<<endl;
            if((re+a[i])%2!=1){
            // if(!((re&1)^(a[i]&1))){
                falg=true;
                // string s;
                // getline(cin,s);
                // cout<<"No"<<endl;
                // return;
            }
        }
        else{
            re=a[i];
        }        
    }
    if(falg==true) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }

    return 0;
}
