#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m;
int x, y, r, z;
int a[1000][1000], b[1000][1000];

int opt(int x, int y, int r, int z){
    for(int i = -r; i <= r; i++){
        for(int j = -r; j <= r; j++){
            if(z == 0) b[x+j][y-i] = a[x+i][y+j];
            else b[x-j][y+i] = a[x+i][y+j];
        }
    }
}

inline void copy(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = b[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    cin >> n >> m;
    int flag = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = flag++;
            b[i][j] = a[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        cin >>x>>y>>r>>z;
        opt(x, y, r, z);
        copy();
    }

    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= n; j++){
            cout << b[i][j] <<" ";
        }
        cout << endl;
    }
    return 0;
}
