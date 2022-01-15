#include<bits/stdc++.h>
using namespace std;

int n, idx;
int a[10001] = {1};

void dfs(int sum, int idx){
    if(sum == 0){
        if(a[0] == n) return;
        for(int i = 0; i < idx - 1; i++){
            cout << a[i] << '+';
        }
        cout << a[idx - 1] << endl;
    }
    for(int i = 1; i <= sum; i++){
        a[idx] = i;
        if(a[idx - 1] > a[idx]) continue;
        idx++;
        dfs(sum - i, idx);
        idx--;
    }
}


int main(){
    cin >> n;
    dfs(n, 0);


    return 0;
}