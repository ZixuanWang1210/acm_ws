#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n ,t; 
unsigned long long a[maxn], s[maxn];

int main(){
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    scanf("%d%d", &n, &t);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        if(a[i] < 0) a[i] = 0;
        
        s[i] = s[i - 1] + a[i];
    }

    while(t--){
        int l, r; scanf("%d%d", &l, &r);
        if(r > n) r = n;
        if(l < 0) l = 0;
        printf("%d\n", s[r] - s[l - 1]);
    }


    return 0;
}