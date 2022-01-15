#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N = 110, M = 10010;
int n, m;
int s[N], f[M];

int sg(int x){
    if(f[x] != -1) return f[x];

    unordered_set<int> S;
    for(int i = 0; i < m; i++){
        int sum = s[i];
        if(x >= sum) S.insert(sg(x - sum));
    }


}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    

    return 0;
}
