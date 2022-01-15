#include<bits/stdc++.h>
//#define MAXN 1e3;
using namespace std;

struct bign
{
    int d[1005];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }
};

bign putt(bign a){
    string str; cin >> str;
    a.len=str.length();
    for(int i=0;i<a.len;i++){
        a.d[i]=str[a.len-1-i]-'0';
    }
    return a;
}

int compare(bign a, bign b){
    if(a.len > b.len) return 1;
    else if(a.len < b.len) return -1;
    else{
        for(int i = a.len - 1; i < a.len; i++){
            if(a.d[i] > b.d[i]) return 1;
            else if(a.d[i] < b.d[i]) return -1;
        }
        return 0;
    }
}

void print(bign a){
    for(int i = a.len - 1; i >= 0; i--){
        cout << a.d[i];
    }
    cout << endl;
}

bign add(bign a, bign b){
    bign c;
    int carry = 0; 
    for(int i = 0; i < a.len || i < b.len; i++){
        c.d[i] = a.d[i] + b.d[i] + carry;
        carry = c.d[i] / 10;
        c.d[c.len++] %= 10;
    }
    if(carry != 0) c.d[c.len++] = carry;
    return c;
}

bign sub(bign &a, bign &b){
    if(compare(a, b) == -1) swap(a, b);
    bign c;
    for(int i = 0; i < a.len || i < b.len; i++){
        if(a.d[i] < b.d[i]){
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0){
        c.len--;
    }
    return c;
}


int main(){
    bign a ;
    a = putt(a);
    bign b;
    b = putt(b);
    bign c;
    c = add(a, b);
    print(c);
    bign d;
    d = sub(a, b);
    print(d);
    return 0;
}