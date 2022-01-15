#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1e6 + 10;
int n, k, m, ans;
bool a[maxn] = {false}, flag = false;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;

    if(n % k == 0 || k % n == 0){
        flag = true;
    }
    int num = max(n / k, k / n);

    while(m--){
        int x; cin >> x;
        if(flag == true){
            while(x >= k){
                x -= k;
            }
            a[x] = true;
        }
    }

    if(flag = false){
        cout << 0 << endl;
        return 0;
    }
    else{
        for(int i = 0; i < k; i++){
            if(a[i] == true) ans ++;
        }
        if(ans == k){
            cout << 0 << endl;
            return 0;
        }
    }

    cout << ans * num;

    return 0;
}
