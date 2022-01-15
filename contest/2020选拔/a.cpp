#include<bits/stdc++.h>
using namespace std;

char a[110][1100] = {'0'};
int b[1100];
int len;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int cnt = 0, idx = 0;
    string s;
    getline(cin, s);
    int l = s.length();
    for(int i = 0; i < l; i++){
        if(s[i] == ' '){
            cnt ++;
            len = max(len, idx);
            idx = 0;
        }
        else a[cnt][idx++] = s[i];
    }

    for(int i = 0; i < len; i++){
        for(int j = cnt; j >= 0; j--){
            if(a[j][i] == '\000') cout << ' ';
            else{
                // cout << "ttt";
                cout << a[j][i];
            }
        }
        cout << endl;
    }
    

    return 0;
}