#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;

int t;
int hh,mm,ss;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    
    int ms=86400000;
    t%=ms;

    hh=t/3600000;
    t-=hh*3600000;
    // cout<<t<<endl;
    mm=t/60000;
    t-=mm*60000;
    // cout<<t<<endl;
    ss=t/1000;
    cout << setw(2) << setfill('0')<<hh<<':'<< setw(2) << setfill('0')<<mm<<':'<< setw(2) << setfill('0')<<ss<<endl;



    return 0;
}
