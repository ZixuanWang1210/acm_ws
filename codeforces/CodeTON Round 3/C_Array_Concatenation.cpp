#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define rep(x,a,b) for(int (x)=(a); (x)<=(b); (x)++)
#define Rep(x,a,b) for(int (x)=(a); (x)<(b); (x)++)
#define For(x,a,b) for(int (x)=(a); (x)>=(b); (x)--)
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl '\n'
#define LL long long
#define LD long double
//#define double LD
#define int LL
#define PLL pair<LL,LL>
#define PII pair<int,int>
#define PDD pair<double,double>
#define fir first
#define sec second

const double eps=1e-8,PI=acos(-1);
const int N=2e5+10,P=1e9+7;
int n,m;
int a[N];

signed main()
{
    IOS;
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];

    LL s1=0,s2=0,sum=0;
    for(int i=1; i<=n; i++){
        sum = (sum+a[i])%P;
        s1 = (s1+(n-i+1)*a[i])%P;
        s2 = (s2+i*a[i])%P;
    }

    LL res=m*(m+1)/2%P*n%P*sum%P;
    // // cout << res << endl;
    // cout << s1 << ' ' << s2 << endl;
    if(s1>=s2)
        // res = (res+(m+1)*s1%P)%P;
        res=
    else{
        // res = (res+m*s2%P)%P;
        // res = (res+s1)%P;
    }
    cout << res;

    return 0;
}
