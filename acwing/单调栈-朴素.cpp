#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

stack<int> s;
int n, a[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(s.empty()){
            cout << "-1 ";
            s.push(a[i]);
        } 
        else{
            while(!s.empty() && a[i] <= s.top()) s.pop();
            if(s.empty()) cout << "-1 ";
            else cout << s.top() << " "; 
            s.push(a[i]);
        }
        
    }
    return 0;
}