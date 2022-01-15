#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

// new char a[70000][700000];
char **a = (char **)calloc(100000,sizeof(char));


int n; 

void debug(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3*n + 4; j++){
            if(a[i][j] != '@') cout << ' ';
            else cout << a[i][j];
        }
        if(i != n) cout << "\n";
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    for(int i=0;i<100000;i++) {
    a[i] = (char*)calloc(100000,sizeof(char));
    }
    cin >> n;
    int m = n * 2 + 2;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j ++){
            if(i == 1 || i == n) a[i][j] = '@';
            if(i + j == n + 1) a[i][j] = '@';
// debug();
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = n + 3; j <= n + 2 + n; j++){
            if(j == n + 3 || j == 2*n + 2){
                a[i][j] = '@';
            }
            if(i == n / 2 + 1) a[i][j] = '@';
        }
    }
    int mid = n / 2 + 1;
    for(int i = 1; i <= n; i++){
        for(int j = 2*n + 5; j <= 2*n + 5 + n; j++){
            if(j == 2*n + 5) a[i][j] = '@';
            if((i == 1 || i == n) && j < 2*n + 5 + n - 2) a[i][j] = '@';
            if((i == 2 || i == n - 1) && j == 2*n + 5 + n - 2) a[i][j] = '@';
            if((i == 3 || i == n - 2) && j == 2*n + 5 + n - 1) a[i][j] = '@';
            if(i >= 4 && i <= n - 3 && j == 2*n + 5 + n - 1) a[i][j] = '@';
            // if()
        }
    }

    debug();
    return 0;
}
