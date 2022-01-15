#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int flag1, flag2, cnt;
int ans1, ans2 = 0x3f3f3f3f;

int main(){
    //cin >> s1;
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    getline(cin, s1);
    getline(cin, s2);
    s2 = ' ' + s2 + ' ';
    int n1 = s1.length(), n2 = s2.length();

    for(int i = 0; i < n2; i++){
        for(int j = 0; j < n1; j++){
            if(s2[i] == s1[j] || s2[i] + 32 == s1[j] || s2[i] - 32 == s1[j]){
                if(s1[i] == ' ' || s2[i] == ' ') break;
                if(cnt == 0 && s2[i - 1] != ' ') break; 
                cnt ++; i++;
                if(cnt == n1){
                    if(s2[i] != ' ') break;
                    ans1 ++, ans2 = min(ans2, i);
                } 
            }
        }
        cnt = 0;
    }

    if(ans1 == 0) cout << -1;
    else cout << ans1 << " " << ans2 - n1 - 1;

    return 0;
}