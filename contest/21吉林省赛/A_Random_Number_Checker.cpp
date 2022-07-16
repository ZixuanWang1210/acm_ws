#include <bits/stdc++.h>
using namespace std;
int n,c0,c1;


signed main()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;cin >> x;
        if(x&1) c0++;
        else c1++;
    }
    if(abs(c0-c1)<=1) cout << "Good";
    else cout << "Not Good" << endl;
    return 0;
}