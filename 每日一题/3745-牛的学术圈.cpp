#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n,l;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>l;
    int ans=0;
    vector<int> v(2*n);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin()+1,v.begin()+1+n);
    if(n==1){
        cout<<v[1]+l<<endl;
        return 0;
    }
    for(int i=n,j=1;i>=1;i--,j++){
        if(j>v[i]){
            int det=v[i+1]-v[i];
            l-=det;
            v[i]=v[i+1];
            if(l<0||j>v[i]) break;
            ans++;
        }
        else ans++;
    }
    cout<<ans;

    return 0;
}
