#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

int h[maxn];
int n, ans;
ll sum, m;

bool cmp(int &x, int &y){
    return x > y;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> h[i];

    sort(h, h + n, cmp);

    int id = 0;
    while(sum < m){
        sum += (h[id] - h[id + 1]) * (id + 1);
        id ++;
    }
    id --;
    ans = h[id + 1] + (sum - m) / (id + 1);
    cout << ans;
    return 0;
}