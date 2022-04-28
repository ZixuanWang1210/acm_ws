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
    int a=0,b=0;
    bool st=true;
    for(int i=1;i<n;i++){
        if(v[i+1]-v[i]==2) a++;
        else if(v[i+1]-v[i]==3) b++;
        else if(v[i+1]-v[i]>3) st=false;
    }

    if(b>1) st=false;
    else if(b==1&&a) st=false;
    else if(a>2) st=false;

    if(st) cout<<"YES"<<endl;
    else cout<<"No"<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
