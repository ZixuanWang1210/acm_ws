#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int mp[30];
    for(int i=0;i<=23;i++){
        cin>>mp[i];
    }
    int x;
    while(cin>>x){
        if(x>=24||x<0) return 0;
        if(mp[x]>50){
            cout<<mp[x]<<" Yes"<<endl;
        }
        else cout<<mp[x]<<" No"<<endl;
    }

    return 0;
}
