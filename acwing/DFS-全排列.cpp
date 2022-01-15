#include<bits/stdc++.h>
using namespace std;

int n;
int a[10];
bool b[10];

void dfs(int x){
    if(x == n + 1){
        for(int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(b[i]) continue;
        else{
            a[x] = i, b[i] = 1;
            dfs(x + 1);
            a[x] = 0, b[i] = 0;
        }
    }
}


int main(){
    cin >> n;

    dfs(1);

    return 0;
}