#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int x;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    cin >> x;
    while(x){
        int temp = x % 2;
        x /= 2;
        cout << "shang:" << x <<" "<< "yu:" << temp << endl;
    }

    return 0;
}
