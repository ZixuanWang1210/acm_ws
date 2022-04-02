#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void lab1_start(){
    cout<<"**************************"<<endl;
    cout<<"*        小小计算器       *"<<endl;
    cout<<"**************************"<<endl;
    cout<<endl;
}

void lab2_base(){
    cout<<"***********************************"<<endl;
    cout<<"*          小小计算器             *"<<endl;
    cout<<"*          1 加法                 *"<<endl;
    cout<<"*          2 减法                 *"<<endl;
    cout<<"*          3 乘法                 *"<<endl;
    cout<<"*          4 除法                 *"<<endl;
    cout<<"*          5 取模运算             *"<<endl;
    cout<<"*          6 计算圆面积           *"<<endl;
    cout<<"***********************************"<<endl;

    cout<<"请输入操作编号"<<endl;
    int op; cin>>op;
    if(op!=6){
        cout<<"请分别输入a和b的值（以空格间隔）"<<endl;
        int a,b; cin>>a>>b;
    }
    if(op==1){
        cout<<"a+b的结果是： "<<a+b<<endl;
    }
    else if(op==2){
        cout<<"a-b的结果是： "<<a-b<<endl;
    }
    else if(op==3){
        cout<<"a*b的结果是： "<<a*b<<endl;
    }
    else if(op==4){
        cout<<"a/b的结果是： "<<a/b<<endl;
    }
    else if(op==5){
        cout<<"a%b的结果是： "<<a%b<<endl;
    }
    else if(op==6){
        const double PI=3.14;
        cout<<"请输入圆的半径"<<endl;
        int r; cin>>r;
        cout<<"圆面积整数结果是："<<r*PI<<endl;
        cout<<"圆面积："<<fixed<<setprecision(6)<<(double)r*PI<<endl;
    }
    else{
        cout<<"输入错误请重新输入"<<endl;
        lab2_base();
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    

    return 0;
}
