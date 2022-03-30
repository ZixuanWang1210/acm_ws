#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int a,b,c,n;
    cin>>a>>b>>c>>n;

    // int res=log(n-c)/log(c-a);
    // cout<<res<<endl;
    int cnt=0;
    int nn=0;
    while(a<n&&b<n&&c<n){
        nn++;
        if(cnt==0){
            a=c+(c-a);
            cnt++;
        }
        else if(cnt==1){
            b=a+(a-b);
            cnt++;
        }
        else if(cnt==2){
            c=b+(b-c);
            cnt++;
        }
        cnt%=3;
    }
    cout<<nn<<endl;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
