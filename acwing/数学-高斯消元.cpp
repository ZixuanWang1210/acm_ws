#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int N = 110;
const double eps = 1e-6;

int n;
double a[N][N];

int gauss(){
    int r = 0, c = 0;
    for(; c < n; c ++){
        int t = r;
        for(int i = r; i < n; i ++){
            if(fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        }

        if(fabs(a[t][c]) < eps) continue;

        for(int i = c; i < n + 1; i ++){
            swap(a[t][i], a[r][i]);
        }
        for(int i = n; i >= c; i--){
            a[r][i] /= a[r][c];
        }
        for(int i = r + 1; i < n; i ++){
            if(fabs(a[i][c]) > eps){
                for(int j = n; j >= c; j--){
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r ++;
    }

    if(r < n){
        for(int i = r; i < n; i ++){
            if(fabs(a[i][n]) > eps){
                return 2;
            }
        }
        return 1;
    }

    for(int i = n - 1; i >= 0; i --){
        for(int j = i + 1; j < n; j ++){
            a[i][n] -= a[j][n] * a[i][j];
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n + 1; j ++){
            cin >> a[i][j];
        }
    }
    
    int t = gauss();

    if(t == 0){
        for(int i = 0; i < n; i ++){
            cout << fixed << setprecision(2) << a[i][n] << endl;
        }
    }
    else if(t == 1) puts("Infinite group solutions");
    else puts("No solution");

    return 0;
}
