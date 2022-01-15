#include<bits/stdc++.h>
using namespace std;

int x, y;
bool a[4100];

int main(){
    cin >> x >> y;
    int total = 2 * x;
    int cnt = 0, idx = 1, num = 1;

    while(cnt != x){
        if(idx == total + 1) idx = 1;
        if(a[idx]){
            num ++;
            if(num == y){
                num = 1;
                a[idx] = false;
                cnt ++;
            }
        }
        idx ++;
    }

    for(int i = 1; i <= total; i++){
        if(a[i]) cout << "X";
        else cout << "Y";
        if(i % 50 == 0) cout << endl;
    }
    
    return 0;
}