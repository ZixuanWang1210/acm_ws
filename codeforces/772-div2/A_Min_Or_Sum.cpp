#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        long long ans=0;
        for(int i=1;i<=n;i++){
            long long t; cin>>t;
            ans = ans|t;
        }
        cout<<ans<<endl;
    }

    return 0;
}