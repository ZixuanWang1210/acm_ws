#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 10;
int a[maxn], b[maxn];

void sol(){
    int A, B, n;
    cin >> A >> B >> n;
    for(int i = 0; i < A; i ++) cin >> a[i];
    for(int i = 0; i < B; i ++) cin >> b[i];
    sort(a, a+A,greater<int>()), sort(b,b+B,greater<int>());

    int cnta = 0, cntb=0, ans = 0;
    cnta ++;
    ans += a[cnta];
    for(int cnt = n; cnt >= 0; cnt --){
        if(cntb>=cnta){
            cnta ++;
            ans += a[cnta];
        }
        else{
            if(a[cnta]>=b[cntb]){
                cnta ++;
                ans += a[cnta];
            }
            else{
                cntb++;
                ans+=b[cntb];
            }
        }
        if(cnta == A){
            int res = 0;
            res = cnta - cntb - 1;
            if(res <= cnt){
                cout << -1 << endl;
                return;
            }
            else{
                a[cnta] = -0x3f3f3f3f;
            }
        }
        if(cntb == B){
            int res = 0;
            if(A - cnta < cnt){
                cout << -1 << endl;
                return;
            }
            else{
                b[cntb] = -0x3f3f3f3f;
            }
        }
    }


    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        sol();
    }
    

    return 0;
}
