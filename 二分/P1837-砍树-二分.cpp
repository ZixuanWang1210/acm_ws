#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

int h[maxn];
int n, ans;
ll sum, m;

int main(){
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> h[i];

    sort(h, h + n);

    int l = h[0], r = h[n - 1];
    while(l < r){
        int mid = (l + r) / 2;
        for(int i = 0; i < n; i++){
            if(h[i] > mid) sum += h[i] - mid;
        }
        if(sum > m) l = mid - 1;
        else if(sum == m){
            l = mid;
            break;
        }
        else r = mid + 1;
        sum = 0;
    }

    cout << l;
    return 0;
}