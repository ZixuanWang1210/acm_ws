#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int t;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> t;
    while(t--){
        int a, p; cin >> a >> p;
        int mark = a;
        if(p < 16){
            mark = a - 10;
            if(mark < 0) mark = 0;
        }
        else if(p > 20){
            int tmp = p - 20;
            mark = mark - tmp;
            if(mark < 0) mark = 0;
        }
        cout << mark << endl;
    }
    

    return 0;
}
