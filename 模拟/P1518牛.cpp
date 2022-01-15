#include <bits/stdc++.h>
using namespace std;

int mp[20][20];
int fx, fy, cx, cy, _time, df=1, dc=1, ans;
int nfx, nfy, ncx, ncy;

int _move(int &x, int &y, int &d){
    int xx, yy;
    if(d==1) xx = x - 1, yy = y;
    else if(d==2) xx = x, yy = y + 1;
    else if(d==3) xx = x + 1, yy = y;
    else if(d==4) xx = x, yy = y - 1;
    if(mp[xx][yy]!=1) x = xx, y = yy;
    else{
        d++;
        if(d>4) d = 1;
    } 
}

int move_c(){
    if(dc==1){
        ncx = cx - 1;
        ncy = cy;
    }
    if(dc==2){
        ncx = cx;
        ncy = cy + 1;
    }
    if(dc==3){
        ncx = cx + 1;
        ncy = cy;
    }
    if(dc==4){
        ncx = cx;
        ncy = cy - 1;
    }
    if(mp[ncx][ncy]!=1){
        cx = ncx;
        cy = ncy;
    }
    else{
        dc++;
        if(dc > 4) dc = 1;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    char temp;
    for(int i = 0; i <= 11; i++){
        for(int j = 0; j <= 11; j++){
            if(i==0||i==11) {mp[i][j] = 1; continue;}
            if(j==0||j==11) {mp[i][j] = 1; continue;}
            cin >> temp;
            if(temp=='*') mp[i][j] = 1;
            else if(temp=='.') mp[i][j] = 0;
            else if(temp=='C'){
                cx = i, cy = j;
                //mp[i][j] = 3;
            }
            else if(temp=='F'){
                fx = i, fy = j;
                //mp[i][j] = 2;
            }
        }
    }
    // for(int i = 0; i <= 11; i++){
    //     for(int j = 0; j <= 11; j++){
    //         cout << mp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    while(1){
        _move(cx, cy, dc);
        _move(fx, fy, df);
        ans++;
        if(ans > 1000){
            cout << 0;
            return 0;
        }
        if(fx==cx&&fy==cy){
            cout << ans;
            return 0;
        }
    }
    return 0;
}
