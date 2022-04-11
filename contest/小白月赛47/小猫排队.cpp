#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    int x; cin>>x;

    int l=1,r=n;
    int cnt=0;
    int bz=true;
    for(int i=1;i<=n;i++){
        if(v[i]>x) bz=false;
    }
    if(bz){
        cout<<n+1<<endl;
        return;
    }
    // bool bz=false;
    while(l<=r){
        cnt++;
        l++;
        // bz=true;
        // bool bz=false;
        for(int i=r-1;i>=l;i--){
            if(v[i]>x){
                r=i;
                // l++;
                // bz=true;
                break;
            }
            
        }
    }
    // if(bz) cnt++;
    cout<<cnt<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    sol();

    return 0;
}
