#include<bits/stdc++.h>
using namespace std;

int t;

long long f(int a, int b){
    return (a + b)*(b - a + 1) / 2;
}

int main(){
    scanf("%d", &t);
    while(t--){
        int a, b; scanf("%d%d", &a, &b);
        cout << f(a, b);
        printf("%d", f(a, b));
        puts("");
    }

    return 0;
}