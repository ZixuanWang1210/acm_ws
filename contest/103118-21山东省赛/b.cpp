#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define LL long long

const int N=2e5+10;
int n,L,R,a[2000001];
ULL seed;

LL sum;
struct edge{
    int from,to,w;
}e[N];

ULL xorsh(){
    ULL x = seed;
    x ^= x<<13;
    x ^= x>>7;
    x ^= x<<17;
    return seed = x;
}

int gen(){
    return xorsh()%(R-L+1)+L;
}

int main()
{
    cin >> n >> L >> R >> seed;
    for(int i=1; i<=n; i++){
        a[i] = gen();
        sum += a[i];
    }

    

    return 0;
}