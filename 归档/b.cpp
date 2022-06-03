/*
##结构体指针与结构体变量用作函数参数区别：##
	结构体指针作为函数参数时，调用时传递的是指向一个结构体变量的指针（即
结构体变量的地址）；结构体变量作为函数参数时，调用时传递的结构体变量本身。
	即一个结构体A，当它的指针作为参数传入函数func，那么在func中可以通过指针
改变结构体的值，函数返回后，结构体的值被改变； 但是，当结构体变量作为
参数传入函数func时，在func函数中即使对他进行了修改，当函数返回时，结
构体本身并没有改变，因为修改的只是他的一个副本。
*/
#include <stdio.h>
 
/* 定义结构体类型Point */
typedef struct {
    char name[30];
    int count;
} Point;    
 
void fun1(Point  point) {
     point.x += 10;
     point.y += 10;
}
 
void fun2(Point *pPoint) {
    pPoint->x += 10;
    pPoint->y += 10;
}
 
void main( )
{
    Point p;
    p.x = 100;
    p.y = 200;
    
    /* 调用 fun1 */
    fun1(p);
    printf("x=%d, y=%d\r\n", p.x, p.y);
    
    /* 调用 fun2：取p的地址作为参数 */
    fun2(&p);
    printf("x=%d, y=%d\r\n", p.x, p.y);
}