#include <iostream>
#include <string.h>

using namespace std;

typedef unsigned long long ULL;
const int N = 2000010, base = 131;

char str[N];
ULL hl[N], hr[N], p[N];

ULL get(ULL h[], int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    int T = 1;
    while (scanf("%s", str + 1), strcmp(str + 1, "END"))
    {
        int n = strlen(str + 1);
        for (int i = n * 2; i; i -= 2)
        {
            str[i] = str[i / 2];
            str[i - 1] = 'a' + 26;
        }
        n *= 2;
        p[0] = 1;
        for (int i = 1, j = n; i <= n; i ++, j -- )
        {
            hl[i] = hl[i - 1] * base + str[i] - 'a' + 1; 
            hr[i] = hr[i - 1] * base + str[j] - 'a' + 1;
            p[i] = p[i - 1] * base;
        }

        int res = 1;
        for (int i = 1; i <= n; i ++ )
        {
            int len = res;
            if(res + i > n) break;
            while(1){
                if(len + i > n||i-len < 1) break;
                if (get(hl, i - len, i - 1) != get(hr, n - (i + len) + 1, n - (i + 1) + 1)) break;
                if()
                res = max(res, len);
                len ++;
            }
        }
        
        printf("Case %d: %d\n", T ++ , res);
    }

    return 0;
}
