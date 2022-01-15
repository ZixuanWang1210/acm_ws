#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int a[maxn], siz, n, m;

void down(int x){
    int u = x;
    if((x << 1) <= siz && a[(x << 1)] < a[x]) u = (x << 1);
    if((x << 1) + 1 <= siz && a[(x << 1) + 1] < a[u]) u = (x << 1) + 1;
    if(u != x){
        swap(a[x], a[u]);
        down(u);
    }
}

// void down(int u){
//     int t = u;
//     if(u << 1 <= siz && a[u << 1] < a[t]) t = u << 1;
//     if(u << 1 + 1 <= siz && a[u << 1 + 1] < a[t]) t = u << 1 + 1;
//     if(t != u){
//         swap(a[t], a[u]);
//         down(t);
//     }
// }

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    siz = n;
    
    for(int i = n >> 1; i; i--) down(i);

    while(m--){
        cout << a[1] << ' ';
        a[1] = a[siz];
        siz--;
        down(1);
    }


    return 0;
}