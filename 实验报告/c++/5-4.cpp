#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct student {
    int data;
    student *next;
} student;
student *create() {
    int data;
    student *p, *head, *q;
    p = (student *)malloc(sizeof(student));
    p->next = NULL;
    head = p;
    p = head;
    cout << "输入链表中的数据，负数表示停止" << endl;
    while (cin >> data && data > 0) {
        q = (student *)malloc(sizeof(student));
        q->data = data;
        q->next = NULL;
        p->next = q;
        p = q;
    }
    return head;
}
void output(student *head) {
    student *p;
    p = head->next;
    cout << "输出链表：" << endl;
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
}
int main() {
    student *head;
    head = create();
    output(head);
    return 0;
}
