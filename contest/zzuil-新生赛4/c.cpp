#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void d_s(){
    cout << "  *" << endl;
    cout << " ***" << endl;
    cout << "*****" << endl;
}

void d_z(){
    for(int i = 0; i < 5; i++){
        cout << "*****" << endl;
    }
}

int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    while(n--){
        int a, b; cin >> a >> b;
        for(int i = 0; i < a; i++){
            d_s();
            cout << endl;
        }
        for(int i = 0; i < b; i++){
            d_z();
            cout << endl;
        }

    }
    

    return 0;
}
