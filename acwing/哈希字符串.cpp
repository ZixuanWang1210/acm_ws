#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 1e5 + 10;
const int P = 131;

int n, m;
char str[maxn];
ull h[maxn], p[maxn]; //使用ull,自动取模

int _hash(){
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        p[i] = p[i - 1] * P; //存P的i次方
        h[i] = h[i - 1] * P + str[i]; //转换成P进制的数
    }
}

ull get(int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main(){
    scanf("%d%d%s", &n, &m, str + 1);
    _hash();

    while(m--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }
    
    return 0;
}