#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 10;

long long n, k, ans, sum;
int a[maxn], flag[maxn];

bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0) return false;
    }
    return true;
}

void dfs(int x, int sum, int sx){
    if(x == k){
        if(is_prime(sum)) ans ++;
        return;
    }
    for(int i = sx; i < n; i++){
        if(flag[i] == 1) continue;
        sum += a[i];
        flag[i] = 1;
        dfs(x + 1, sum, i + 1);
        sum -= a[i];
        flag[i] = 0;
    }
    return;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    dfs(0, 0, 0);

    cout << ans;

    return 0;
}

