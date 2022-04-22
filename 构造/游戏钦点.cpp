#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

int lowbit(int x){
    return x&-x;
}

void sol(){
    int x,y; cin>>x>>y;
    int sum=x+y;

    int n=sqrt(sum);
    if(n*n!=sum){
        cout<<-1<<endl;
        return;
    }
    if(x==0){
        cout<<0<<endl;
        return;
    }
    bool flag=false;
    int ans=0;
    for(int i=n;i>=1;i--){
        if(x>=2*i-1&&(x-2*i+1!=2)){
            x-=2*i-1;
            ans++;
        }
        if(x==0){
            flag=1;
            break;
        }
    }
    if(flag) cout<<ans;
    else cout<<-1;


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
