#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n ,t; 
long long a[maxn], s[maxn];

int main(){
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >>t;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        // cin >> a[i];
        if(a[i] < 0) a[i] = 0;
        // cout << a[i] << " ";
        s[i] = s[i - 1] + a[i];
    }

    while(t--){
        int l, r; scanf("%d%d", &l, &r);

        printf("%d\n", s[r] - s[l - 1]);
    }


    return 0;
}