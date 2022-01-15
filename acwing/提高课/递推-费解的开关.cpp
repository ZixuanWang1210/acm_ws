#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N = 6;
char g[N][N], bg[N][N];
int n;
int dx[] = {0, -1, 1, 0, 0}, dy[] = {0, 0, 0, 1, -1};

void debug(){
    cout << "==================" << endl;
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl << endl;
}

void turn(int x, int y){
    for(int i = 0; i < 5; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx >= 1 && xx <= 5 && yy >= 1 && yy <= 5){
            g[xx][yy] ^= 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n; 
    while(n--){
        for(int i = 1; i <= 5; i++){
            for(int j = 1; j <= 5; j++){
                cin >> bg[i][j];
            }
        }
        int re = 0x3f3f3f3f;
        for(int op = 0; op < 64; op++){
            int cnt = 0;
            memcpy(g, bg, sizeof g);
            for(int i = 1; i <= 5; i++){
                if(op >> (i - 1) & 1){
                    cnt ++;
                    turn(1, i);
                    // debug();
                }
            }

            for(int i = 1; i <= 4; i++){
                for(int j = 1; j <= 5; j++){
                    if(g[i][j] == '0'){
                        cnt ++;
                        turn(i + 1, j);
                    }
                }
            }

            bool flag = true;
            for(int i = 1; i <= 5 ; i ++){
                if(g[5][i] == '0') flag = false;
            }

            if(flag == true)
                re = min(cnt, re);
        }

        if(re > 6) re = -1;
        cout << re << endl;

    }
    

    return 0;
}
