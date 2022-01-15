#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000+5][1000+5] {};
//int temp[1005][1005] {};

void debug(){
    cout <<"-----a--------------"<< endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"----------------------" << endl;
    cout <<"----==temp==---------"<< endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            //cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"----------------------" << endl;
}

void rotation(int x, int y, int r, int z){
    int flag = 2 * r + 1;
    int temp[2*r+1][2*r+1] = {0};
    int tempOpt[flag][flag] = {0};
    for(int i = y - r, x = 1; i <= y + r; i++, x++){
        for(int j = x - r, y = 1; j <= x + r; j++, y++){
            temp[x][y] = a[i][j];
            // if(z == 1) {temp[i][j] = a[j][abs(i-r*2-2)];}
            // else {temp[i][j] = a[abs(j-r*2-2)][i];}
        }
    } 
    for(int i = 1; i <= flag; i++){
        for(int j = 1; j <= flag; j++){
            if(z == 1) {tempOpt[i][j] = temp[j][abs(i-r*2-2)];}
            else {tempOpt[i][j] = temp[abs(j-r*2-2)][i];}
        }
    }
    for(int i = y - r, x = 1; i <= y + r; i++, x++){
        for(int j = x - r, y = 1; j <= x + r; j++, y++){
            a[i][j] = tempOpt[x][y];
        }
    } 
    debug();

    for(int i = y - r; i <= y + r; i++){
        for(int j = x - r; j <= x + r; j++){
            a[i][j] = temp[i][j];
        }
    }
    memset(temp, 0, sizeof(temp));
    debug();
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
        }
    }
    debug();
    int x, y, z, r;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> r >> z;
        rotation(x, y, r, z);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
