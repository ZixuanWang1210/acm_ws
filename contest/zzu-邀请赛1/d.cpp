#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;


void sol() {
    int hh1,mm1,ss1,hh2,mm2,ss2;
    int hh,mm,ss;
    scanf("%d:%d-%d:%d",&hh1,&mm1,&hh2,&mm2);
    scanf("%d:%d",&hh,&mm);
    int len=(hh2-hh1)*60+(mm2-mm1);
    len++;
    int det=(hh2-hh)*60+(mm2-mm);
    double sum=(double)(1+det)*det/2;
    cout<<fixed<<setprecision(2)<<sum/len<<endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    // cin>>_;
    while (_--) {
        sol();
    }

    return 0;
}
