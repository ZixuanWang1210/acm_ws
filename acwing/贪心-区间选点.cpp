#include<bits/stdc++.h>
using namespace std;
const int maxn = 0x3f3f3f3f;
typedef pair<int, int> pii;

priority_queue<pii,vector<pii>,greater<pii>> q;
int n, cnt = 0;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        q.push({b, a});
    }

    int st = -maxn, ed = -maxn;
    while(!q.empty()){
        st = q.top().second;
        if(st > ed){
            cnt++;
            ed = q.top().first;
        }
        q.pop();
    }

    cout << cnt;
    
    return 0;
}