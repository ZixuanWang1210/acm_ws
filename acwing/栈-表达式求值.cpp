#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

stack<int> num;
stack<char> opt;
unordered_map<char, int> pr;
string s;

void eval(){
    int b = num.top(); num.pop();
    int a = num.top(); num.pop();

    int ans = 0;
    char op = opt.top(); opt.pop();

    if(op == '+') ans = a + b;
    else if(op == '-') ans = a - b;
    else if(op == '*') ans = a * b;
    else if (op == '/') ans = a / b;

    num.push(ans);
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> s;
    pr['+'] = 1, pr['-'] = 1, pr['*'] = 2, pr['/'] = 2;
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s[i])){
            int x = 0;
            while(isdigit(s[i])){
                x = x * 10 + s[i] - '0';
                i ++;
            }
            num.push(x);
            i --;
        }
        else if(s[i] == '('){
            opt.push(s[i]);
        }
        else if(s[i] == ')'){
            while(opt.top() != '('){
                eval();
            }
            opt.pop();
        }
        else{
            while(!opt.empty() && pr[opt.top()] >= pr[s[i]]){
                eval();
            }
            opt.push(s[i]);
        }
    }   

    while(!opt.empty()){
        eval();
    }
    cout << num.top();

    return 0;
}
