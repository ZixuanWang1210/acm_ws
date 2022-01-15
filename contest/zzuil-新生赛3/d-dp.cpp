#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
typedef int ull;
#define pii pair<int, int>
using namespace std;

const int maxn = 1010;
int n, m, ans;
char mp[maxn][maxn];
int a[maxn][maxn];
int dx[] = {-1, 0}, dy[] = {0, 1};

bool judge(int x, int y){
    if(x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] != '#') return true;
    else return false;
}

void debug(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][j] << " ";
        }

        cout << endl;

    }
        cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mp[i][j];
        }
    }
    
    for(int i = n; i > 0; i--){
        for(int j = 1; j <= m; j++){
            if(i == n && j == 1){
                a[i][j] = 1;
                continue;
            }
            if(judge(i, j) == true){
                a[i][j] = ((a[i][j-1] % 998244353) + (a[i+1][j] % 998244353)) % 998244353;
            }
            // debug();
        }
    }
    
    cout << a[1][m];

    return 0;
}
