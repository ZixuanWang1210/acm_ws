#include<bits/stdc++.h>
using namespace std ;
#define ll long long
const ll N = 2e5+9 ;
ll Max( ll a , ll b ){ return a>b?a:b ; } // 返回最大值
ll Abs( ll x ){ return x<0?-x:x ; } // 返回绝对值
ll a[ N ] , n , m ;
ll maxdis( ll x , ll y ){
    // 找到(i,j)离四个角最大的距离
    ll ans = Abs( x - 1 ) + Abs( y - 1 ) ;
    ans = Max( ans , Abs( x - 1 ) + Abs( m - y ) ) ;
    ans = Max( ans , Abs( n - x ) + Abs( y - 1 ) ) ;
    ans = Max( ans , Abs( n - x ) + Abs( m - y ) ) ;
    return ans ;
}
int main(){
    ll t ; cin >> t ;
    while( t-- ){
        ll cnt = 0 ; cin >> n >> m ;
        //把所有距离计算出来 ，cnt是距离的个数
        for( ll i = 1 ; i <= n ; i ++ )
            for( ll j = 1 ; j <= m ; j ++ )
                a[ ++cnt ] = maxdis( i , j ) ;
        sort( a+1 , a+1+cnt ) ;
        for( int i = 1 ; i <= n*m ; i ++ ) cout << a[ i ] << " " ;
        cout << "\n" ;
    }
return 0 ;
}
