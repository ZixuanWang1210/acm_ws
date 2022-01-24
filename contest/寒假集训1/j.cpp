#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 1e4+10;
int a[maxn], b[maxn];

void sol(){
    int A, B, n;
    cin >> A >> B >> n;
    for(int i = 0; i < A; i ++) cin >> a[i];
    for(int i = 0; i < B; i ++) cin >> b[i];
    sort(a, a+A,greater<int>()), sort(b,b+B,greater<int>());

    int cnta = 0, cntb=0, ans = 0;
    int flag = false;
    while(n--){
        if(cntb == B && cnta < A){
            flag = true;
            if(n-1 >= A - cnta){
                cout << -1 <<endl;
                return;
            }
            else{
                ans+=a[cnta];
                cnta++;
            }
        }
        if(cnta == A){
            flag = true;
            if(cntb + 1 > cnta){
                cout << -1 << endl;
                return;
            }
            else{
                ans+=b[cntb];
                cntb++;
            }
        }
        if(flag == false){
            if(a[cnta]>=b[cntb] || (cntb >= cnta && cntb != 0)){
                ans+=a[cnta];
                cnta++;
            }else{
                ans+=b[cntb];
                cntb++;
            }
        }
        // else{
        // }
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
