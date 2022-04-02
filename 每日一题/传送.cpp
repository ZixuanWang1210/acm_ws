#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a,b,x,y; cin>>a>>b>>x>>y;
    if(b<a) swap(a,b);
    if(y<x) swap(x,y);
    int ans1=b-a;
    int ans2=abs(x-a)+abs(b-y);
    cout<<min(ans1,ans2)<<endl;

    

    return 0;
}
