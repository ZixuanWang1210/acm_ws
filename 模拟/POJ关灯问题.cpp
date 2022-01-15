#include <bits/stdc++.h>

using namespace std;

int mp[6][5] {};
int mp1[6][5] {};
int press[6][5] {};

int change(int i){
    return i ? (i = 0) : (i = 1);
}
void ans();

void rule(int i, int j){
    press[i][j] = 1;
    mp[i][j] = change(mp[i][j]);
    if(i-1 >= 0) mp[i-1][j] = change(mp[i-1][j]);
    if(j-1 >= 0) mp[i][j-1] = change(mp[i][j-1]);
    if(i+1 < 6) mp[i+1][j] = change(mp[i+1][j]);
    if(j+1 < 5) mp[i][j+1] = change(mp[i][j+1]);
}

int solve(){
    for(int j = 0; j < 4; j++){
        for(int i = 0; i < 6; i++){
            if(mp[i][j] == 1){
                //press[i][j+1] = 1;
                rule(i, j + 1);
                // ans();
            }
        }
    }
    for(int i = 0; i < 6; i++){
        if(mp[i][4] == 1) return -1;
    }
    return 1;
}

void dubug(){
    cout << "---------------------------" << endl;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            cout << press[j][i] << " ";
        }
        cout << endl;
    } 
    cout << endl; 
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            cout << mp[j][i] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------" << endl;
}

void ans(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            cout << press[j][i] << " ";
        }
        cout << endl;
    } 
}

void copy(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            mp[j][i] = mp1[j][i];
            press[j][i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            cin >> mp[j][i];
            mp1[j][i] = mp[j][i];
        }
    }
    
    for(int i = 0; i < 6; i++){
        copy(), rule(i, 0);
        if(solve() == 1) {ans(); return 0;}
    }
    for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++){
            copy(), rule(i, 0), rule(j, 0);
            if(solve() == 1) {ans(); return 0;}
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++){
            for(int k = j + 1; k < 6; k++){
                copy(), rule(i, 0), rule(j, 0), rule(k, 0);
                //ans();
                if(solve() == 1) {ans(); return 0;}
            }
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++){
            for(int k = j + 1; k < 6; k++){
                for(int m = k + 1; m < 6; m++){
                copy(), rule(i, 0), rule(j, 0), rule(k, 0), rule(m, 0);
                //ans();
                if(solve() == 1) {ans(); return 0;}
                }
            }
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++){
            for(int k = j + 1; k < 6; k++){
                for(int m = k + 1; m < 6; m++){
                    for(int n = m + 1; m < 6; n++){
                        copy(), rule(i, 0), rule(j, 0), rule(k, 0), rule(m, 0), rule(n, 0);
                        //ans();
                        if(solve() == 1) {ans(); return 0;}
                    }
                }
            }
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++){
            for(int k = j + 1; k < 6; k++){
                for(int m = k + 1; m < 6; m++){
                    for(int n = m + 1; m < 6; n++){
                        for(int u = n + 1; u < 6; u++){
                            copy(), rule(i, 0), rule(j, 0), rule(k, 0), rule(m, 0), rule(n, 0), rule(u, 0);
                            //ans();
                            if(solve() == 1) {ans(); return 0;}
                        }
                    }
                }
            }
        }
    }
    cout << "NO";
    return 0;
}
