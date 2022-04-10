#include<iostream>
#include<algorithm>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int xa,ya,xb,yb;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    int sx1=min(x1, x3), sy1=min(y1, y3), sx2=max(x2, x4), sy2=max(y2, y4);
    int s=max(sx2-sx1, sy2-sy1);
    cout<<s*s;
    return 0;
}
