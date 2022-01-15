#include<bits/stdc++.h>
using namespace std;

set<int> s;
int n, x, m;

bool f(int a, int b){
    int ans = -(a * x * x + b * x);
    if(s.find(ans) != s.end())
        return true;
    else return false;
}

int main(){
    // scanf("%d %d", n, x);
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        scanf("%d", &m);
        s.insert(m);
    }
    if(x == 0){
        if(s.find(0) != s.end()){
            puts("YES");
        }
        else puts("NO");
    }
    else{
        for(auto i : s){
            for(auto j : s){
                if(f(i, j)){
                    puts("YES");
                    return 0;
                }
            }
        }
    }

    puts("NO");
    return 0;
}