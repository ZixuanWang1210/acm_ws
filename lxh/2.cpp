#include<bits/stdc++.h>
using namespace std;

int n, m; //n代表行号， m 代表列号 。a[第几行][第几列] 
int a[10][10]; //定义一个最大大小是10x10的二维数组。下标最多到a[9][9] 

int main(){
    cin >> n >> m;//c艹输入总共行号和列号 
    for(int i = 0; i < n; i++){//从第0行开始 
        for(int j = 0; j < m; j++){//从第一列开始 
            cin >> a[i][j];//输入当前要存的数，并保存在对应的数组位置中 
            if(a[i][j] >= 0) a[i][j] = 0;//如果大于等于0， 将该位变成 0 
            cout << a[i][j] << " ";//输出更新后的真实值 
        }
        cout << endl;//每一行输出一个换行; 
    }

    return 0;
}
