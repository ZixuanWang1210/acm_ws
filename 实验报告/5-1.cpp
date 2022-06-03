#include<iostream>
using namespace std;

struct stu{
    char name[30];
    int class1;
    int class2;
    int class3;
} student[1000];

int n; 

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>student[i].name>>student[i].class1>>student[i].class2>>student[i].class2;
    }



    return 0;
}