#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int P = 131;
const int maxn = 1e6 + 10;

char s[maxn];
ull h[maxn], a[maxn];
int n, m, ans;
set<ull> se;

ull get(ull s[], int l, int r){
    return s[r] - s[l - 1] * a[r - l + 1];
}

int main(){
    cin >> n;

    a[0] = 1;
    for(int i = 1; i <= 1e4; i++){
        a[i] = a[i - 1] * P;
    }

    for(int i = 0; i < n; i++){
        cin >> s + 1;
        for(int i = 1; i <= sizeof(s); i++){
            h[i] = h[i - 1] * P + s[i];
        }

        if(se.find(h[sizeof(s)]) != se.end()){
            se.insert(h[sizeof(s)]);
        }
        else{
            ans ++;
        }

    }

    

    cout << ans;
    return 0;
}