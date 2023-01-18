#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    string t;
    cin >> s >> t;
    int slen = s.size();
    int tlen = t.size();
    bool dp[slen + 1][tlen + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;

    int cnt1=0,cnt2=0;
    for(int i=0;i<slen;i++){
        if(s[i]=='(') cnt1++;
        else cnt2++;
        if(cnt1==cnt2) dp[i+1][0]=1;
    }

    for (int i = 1; i <= slen; i++) {
        for (int j = 1; j <= tlen; j++) {
            if (s[i - 1] == t[j - 1]) dp[i][j] |= dp[i - 1][j - 1];
            if (s[i - 1] == ')') {
                int k = i - 1;
                int cnt = 1;
                while (cnt > 0) {
                    if (s[k - 1] == ')')
                        cnt++;
                    else
                        cnt--;
                    k--;
                }
                dp[i][j] |= dp[k][j];
            }
        }
    }
    for(int i=0;i<=slen;i++){
        for(int j=0;j<=tlen;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    if (dp[slen][tlen])
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
}
