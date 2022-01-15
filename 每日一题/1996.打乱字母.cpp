#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 50010;
// char s[maxn][30], s1[maxn][30], s2[maxn][30];
string s[maxn], s1[maxn], s2[maxn], s1bk[maxn], s2bk[maxn];
int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> s[i];
        s1[i] = s[i];
        sort(s1[i].begin(), s1[i].end());
        s1bk[i] = s1[i];
        s2[i] = s1[i];
        reverse(s2[i].begin(), s2[i].end());
        s2bk[i] = s2[i];
    }

    sort(s1->begin(), s1->end());
    sort(s2->begin(), s2->end());
    for(int i = 0; i < n; i ++){
        cout << s1->find(s1bk[i]) << ' ' << s2->find(s2bk[i]) << endl;
    }    
    
    return 0;
}
