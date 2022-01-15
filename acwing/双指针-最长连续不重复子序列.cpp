#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n = 0, ans, ns;
int a[maxn];
int vis[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    for(int i = 0, j = 0; j < n; j++){
        vis[a[j]]++;
        while(vis[a[j]] > 1){
            vis[a[i]]--;
            i++;    
        }

        res = max(res, j - i + 1);
    }
    cout << res;
    return 0;
}