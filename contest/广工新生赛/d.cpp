#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;
int q[12][12];
int n;


int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            cin >> q[i][j];
        }
    }
    
    int flag = 1; 
    int cnt = 1;
    for(int i = 1; i <= n; i++ )
    {
        for(int j = 1; j <= n; j ++)
        {
            
            if(q[i][j]!= cnt ++ ){
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    if (flag)
    {
        cout <<"YES" <<endl;
    }
    else
    {
        cout <<"NO" <<endl;
    }
    
}