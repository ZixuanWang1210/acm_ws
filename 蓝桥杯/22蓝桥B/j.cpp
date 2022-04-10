#include<bits/stdc++.h>
using namespace std;
int cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x==0) continue;
        while(x!=1){
            cnt++;
            x=sqrt((int)x/2+1);
        }
    }
    cout<<cnt<<endl;

    return 0;
}