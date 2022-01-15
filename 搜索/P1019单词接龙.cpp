#include<bits/stdc++.h>
using namespace std;

string a[30], s;
int vis[30];
int n, ans = 1;

int judge(string s1, string s2){//s1主串
    int len1 = s1.length(), len2 = s2.length();
    for(int i = 1; i < min(len1, len2); i++){
        bool flag = 1;
        for(int j = 0; j < i; j++){
            if(s1[len1 - i + j] != s2[j]){
                flag = 0;
                //break;
            }
        }
        if(flag) return i;
    }
    return 0;
}

void dfs(string now, int len){
    ans = max(ans, len);
    for(int i = 0; i < n; i ++){
        if(vis[i] >= 2) continue;
        int fg = judge(now, a[i]);
        if(fg == 0) continue;

        
        // len = a[i].length() - fg + len;
        // vis[i] ++;
        // dfs(len);
        // vis[i] --;
        // len = len - a[i].length() + fg; 
        vis[i]++;
        dfs(a[i], len + a[i].length() - fg);
        vis[i]--;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], vis[i] = 0;
    cin >> s;
    s = ' ' + s;

    dfs(s, 1);

    cout << ans;

   

    return 0;
}