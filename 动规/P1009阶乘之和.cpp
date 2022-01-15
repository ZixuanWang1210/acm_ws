#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ull a[55];
int n;

struct bign
{
    int d[1005];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }
};

bign putt(bign a, string str){
    //string str; cin >> str;
    a.len=str.length();
    for(int i=0;i<a.len;i++){
        a.d[i]=str[a.len-1-i]-'0';
    }
    return a;
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

bign dabiao(){
    int date = 1;
    a[1] = date, a[0] = 1;
    bign ans;
    for(int i = 2; i <= n; i++){
        a[i] = a[i-1] * i;
        bign b;
        b = putt(b, to_string(a[i]));
        ans = add(b, ans);
    }
    return ans;
}

void print(bign a){
    for(int i = a.len - 1; i >= 0; i--){
        cout << a.d[i];
    }
    //cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    cin >> n;

    print(dabiao());

    return 0;
}
