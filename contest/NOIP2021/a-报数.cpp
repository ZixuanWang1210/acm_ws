#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1e7 + 10;
int T;
bool a[maxn] = {false}, vis[maxn] = {false};

void dabiao(){
    for(int i = 7; i <= maxn; i++){
        int x = i;
        bool flag = false;
        while(x){
            if(x % 10 == 7){
                flag = true;
                break;
            }
            x /= 10;
        }

        x = i;
        while(x <= maxn && flag == true){ 
            a[x] = true;
            x += i;
        }

    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> T;
    dabiao();
    while(T--){
        int x; cin >> x;
        if(a[x]){
            cout << -1 << endl;
            continue;
        }

        for(int i = x + 1;;i++){
            if(a[i] == false){
                cout << i << endl;
                break;
            }
        }
    }
    

    return 0;
}