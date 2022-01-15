#include<iostream>
using namespace std;
const int maxn = 1000 + 10;

int m, n, q, x1, x2, y1, y2;
int a[maxn][maxn], s[maxn][maxn];

int main(){
    cin >> n >> m >> q;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
        
    while(q--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] << endl;
    }
            
}
