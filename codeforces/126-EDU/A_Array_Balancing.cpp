#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) cin>>b[i];

    for(int i=1;i<=n;i++){
        if(a[i]>b[i]) swap(a[i],b[i]);
    }

    long long sum=0;
    for(int i=1;i<=n-1;i++){
        sum+=abs(a[i]-a[i+1])+abs(b[i]-b[i+1]);
    }
    cout<<sum<<endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--) sol();

    return 0;
}
