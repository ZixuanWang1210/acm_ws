#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int a[maxn], ans[maxn];
int n;
stack<int> s;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        while(!s.empty() && a[i] <= s.top()) s.pop();
        ans[i] = s.empty () ? -1 : s.top();
        cout << ans[i] << " ";
        s.push(a[i]);
    }
    return 0;
}