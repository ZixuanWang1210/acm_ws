#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int a,b,c; a=b=c=n/3;
    int res=n%3;
    if(res==1){
        b++;
    }
    else if(res==2){
        b++,c++;
    }
    cout<<a*b*c<<endl;

    return 0;
}
