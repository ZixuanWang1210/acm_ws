#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol(){
    int n; 
    cin>>n;
    int x=ceil((double)n/3);
    int a=x+1,b=x,c=n-a-b; 
    if(c==0){
        b--,c++;
    }
    cout<<b<<' '<<a<<' '<<c<<endl;

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
