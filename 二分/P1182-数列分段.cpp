#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
// const int maxn = 7;

int a[maxn], s[maxn];
int m, n, ans;

bool judge(int x){
    int sum = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        if(sum + a[i] > x){
            sum = a[i];
            cnt ++;
        }
        else sum += a[i];
    }
    return cnt < m;
}

int main(){
    cin >> n >> m;
    int _min = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        _min = max(_min, a[i]);
    }

    int l = _min, r = s[n];
    while(l <= r){
        int mid = (l + r) >> 1;
        if(judge(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ans;

    return 0;
}