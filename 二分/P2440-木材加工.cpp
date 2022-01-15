#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
// const int maxn = 4;

int n, k, l, ans;
int a[maxn];

bool check(int x){
    int num = 0;
    for(int i = 0; i < n; i++){
        int len = a[i];
        while(len >= x){
            num ++;
            len -= x;
        }
        if(num >= k) return true;
    }
    return false;
}

int main (){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int l = 0, r = a[n - 1];
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans;
    return 0;
}