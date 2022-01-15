#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;

int judge(int x){
    if(x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x== 12) return 31;
    else if(x == 2) return 28;
    else return 30;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    while(n--){
        int x; cin >> x;
        int mm; cin >> mm;
        int y = judge(mm);
        int idx = 0;
        for(int i = 2; i <= x; i ++){
            idx ++;
            cout << "   " ;
            
        }
        // for(int i = 2; i <)
        for(int i = 1; i <= y; i++){
            idx ++;
            if(idx == 8){
                cout << endl;
                idx = 1;
            }
            if(i < 10) cout << " ";
            
            cout << i;
            if(idx != 8) cout << " ";
            // cout << i << ' ';

            // idx ++;
        }
        cout << endl;
    }
    
    return 0;
}
