#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

char a[maxn], b[maxn];//a 模板串
int ne[maxn];
int n, m;

void nex(){
    ne[1] = 0;
    int indx = 1, j = 0;
    while(indx <= n){
        if(j==0 || a[indx] == a[j]) ne[++indx] = ++j;
        else j = ne[j];
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];

    for(int i = 1, j = 0; i <=m; i++){
        while(j && a[j + 1] != b[i]) j = ne[j];
        if(a[j + 1] == b[i]) j++;
        if(j == n){
            cout << i - n << " ";
            j = ne[j];
        }
    }

    return 0;
}