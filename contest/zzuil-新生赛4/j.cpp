#include <iostream>
#include <algorithm>

using namespace std;

const int N= 1000010;

int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main()
{
    // 
    get_primes(10000);
    st[2] = true;

    int t; cin >> t;
    
    int cnt = 0;
    while(t--){
        int a, b;
        cin >> a >> b;
        for(int i = a; i <= b; i++){
            if(st[i]){
                string s;
                s = to_string(i);
                if(s[0] == s[s.length() - 1]) cnt ++;
            }
        }
        cout << cnt << endl;            
    }

    return 0;
}
