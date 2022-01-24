#include <bits/stdc++.h>
#define endl "\n"


using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    int t; cin >> t;
    while(t--){
        int n,m; cin >>n>>m;
        int ans = 0;

        priority_queue<int> down;
        priority_queue<int, vector<int>, greater<int>> up;

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt ++;
            int x; cin >> x;
            if(down.empty() || x <= down.top()) down.push(x);
            else up.push(x);

            if(down.size() > up.size() + 1) up.push(down.top()), down.pop();
            if(up.size() > down.size()) down.push(up.top()), up.pop();
            
            int mid = 0;
            if(cnt % 2 == 0){
                mid = min(down.top(),up.top());
            }
            else{
                mid = down.top();
            }
            if(mid >= m){
                priority_queue<int> downcls;
                priority_queue<int, vector<int>, greater<int>> upcls;
                swap(downcls, down), swap(upcls, up);
                ans ++; cnt = 0;
            }
            // cout << mid <<endl;                 
        }
                cout << ans <<endl;

    }

    return 0;
}
