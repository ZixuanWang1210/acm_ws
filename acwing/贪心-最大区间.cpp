#include<bits/stdc++.h>
using namespace std;
const int N = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, cnt;
priority_queue<pii> q;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        q.push({b, a});
    }

    int st = -N, ed = q.top().first;
    while(!q.empty()){
        st = q.top().second;
        if(st > ed){
            cnt ++;
        }
        ed = min(ed, q.top().first);
        q.pop();
    }

    cout << cnt;

    return 0;
}