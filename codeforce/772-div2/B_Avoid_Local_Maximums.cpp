#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> v(2*n);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }
        long long cnt=0;
        for(int i=2;i<=n-1;i++){
            if(v[i]>v[i-1]&&v[i]>v[i+1]){
                v[i+1]=max(v[i],v[i+2]);
                cnt++;
            }
        }
        cout<<cnt<<endl;
        for(int i=1;i<=n;i++){
            cout<<v[i]<<' ';
        }
        cout<<endl;

    }


    return 0;
}