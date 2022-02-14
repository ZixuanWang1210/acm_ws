#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{ 
    double x1,y1,x2,y2;

    cin>>x1>>y1;
    double sum=0;
    while(cin>>x1>>y1>>x2>>y2)
    {
        double dx=x1-x2;
        double dy=y1-y2;
        sum += sqrt(dx*dx +dy*dy)*2;
    }

    int m = round(sum/1000/20*60);
    int hour = m/60;
    m %=60;
    printf("%d:%02d",hour,m);
    cout<<endl;

    return 0;
}
