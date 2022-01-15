#include<bits/stdc++.h>
using namespace std;
const int maxn = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, ans = 1;
pii s[100010];
priority_queue<int, vector<int>, greater<int>> heap;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        s[i] = {a, b};
    }

    sort(s, s + n);

    heap.push(s[0].second);
    for(int i = 1; i < n; i++){
        if(s[i].first <= heap.top()){
            ans++;
            heap.push(s[i].second);
        }
        else{
            heap.pop();
            heap.push(s[i].second);
        }
    }

    cout << ans;

    return 0;
}