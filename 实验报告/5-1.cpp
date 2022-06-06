#include <iostream>
using namespace std;
struct student {
    int num;
    char name[10];
    int grade_1;
    int grade_2;
    int grade_3;
    int avg_grade;
};
void pingjun(struct student *stu, int n) {
    for (int i = 0; i < n; i++) {
        stu[i].avg_grade = (stu[i].grade_1 + stu[i].grade_2 + stu[i].grade_3) / 3;
    }
}
int main() {
    int n = 0;
    cout << "请输入学生个数：";
    cin >> n;
    struct student *stu = (struct student *)malloc(sizeof(struct student) * (n + 2));
    for (int i = 0; i < n; i++) {
        cout << "请输入学号，姓名，成绩1，成绩2，成绩3" << endl;
        cin >> stu[i].num >> stu[i].name >> stu[i].grade_1 >> stu[i].grade_2 >> stu[i].grade_3;
    }
    pingjun(stu, n);
    for (int i = 0; i < n; i++) {
        cout << stu[i].num << " " << stu[i].name << " " << stu[i].grade_1 << " " << stu[i].grade_2
             << " " << stu[i].grade_3 << " " << stu[i].avg_grade << endl;
    }
    return 0;
}
