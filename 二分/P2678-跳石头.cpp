#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;

int a[maxn], b[maxn];
int L, m, n;

// bool judge(int x){
//     int cnt = 0;
//     for(int i = 1; i <= n + 1; i++){
//         if(b[i] < x){
//             b[i+1] += b[i];
//             cnt ++;
//         }
//     }
//     if(b[n+1] < x) cnt++;
//     if(cnt <= m) return true;
//     else return false;
// }

bool judge(int mid){
    int ans=0,st=0;
    for(int i=1;i<=n;++i)
        if(a[i]-st<mid)
            ans=ans+1;
        else st=a[i];
    return ans<=m;
}

int main(){
    cin >> L >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i] - a[i-1];
    }
    b[n+1] = L - a[n];

    int l = 0, r = L, ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(judge(mid)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    cout << ans;

    return 0;
}