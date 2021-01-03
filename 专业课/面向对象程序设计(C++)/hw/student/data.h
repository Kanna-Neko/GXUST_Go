//
// Created by 李欣燃 on 2020/7/5.
//

#ifndef STUDENT_DATA_H
#define STUDENT_DATA_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class base_data{
public:
    //返回账号
    string get_account();
    //返回密码
    string get_password();
    //修改密码
    void alter_password(string new_password);
protected:
    string account;
    string password;
};

class student: public base_data{
public:
    //构造函数
    student();
    student(string new_account,string new_password,string new_id,string new_name,string new_sex);
    //返回id
    string get_id();
    //返回姓名
    string get_name();
    //返回性别
    string get_sex();
    //返回成绩
    int get_grade(int n);
    //返回总成绩
    int get_all_grade();
    //给单科成绩赋值
    void alter_value(int n,int value);
    //查看平均分
    double get_aver();
    //修改id
    void alter_id(string new_id);
    //修改name
    void alter_name(string new_name);
    //修改sex
    void alter_sex(string new_sex);
    //修改成绩
    void alter_grade(int n,int value);
private:
    string id;
    string name;
    string sex;
    int grade[6];
};

namespace grade_name{
    const int math=0;
    const int english=1;
    const int cpp=2;
    const int digital_circuit=3;
    const int digital_logic=4;
    const int PE=5;
}
class teacher: public base_data{
public:
    //构造函数
    teacher();
    teacher(string new_account,string new_password,string new_name,string new_tel);
    //返回函数
    string get_name();
    string get_tel();
    //设置函数
    void alter_name(string new_name);
    void alter_tel(string new_tel);
    //增加学生
    static bool add_student_account(string account,string password,string id,string name,string sex,int grade[6]);
    //删除学生
    static bool delete_student_account(string account);
    //查看学生信息
    static student view_student_info(string account);
private:
    string name;
    string tel;
};

namespace data_store{
    extern vector<student>total_student;
    extern vector<teacher>total_teacher;
    const string admin_account="root";
    const string admin_password="123456";

    //储存函数
    void store_data();
    //提取函数
    void pull_data();
}

namespace tool{
    int find_student_index(string studnet_account);
    int find_teacher_index(string teacher_account);
}
namespace admin_operate{
    bool add_teacher_account(string account,string password,string name,string tel);
    bool delete_teacher_account(string account);
    teacher view_teacher_info(string account);
}
#endif //STUDENT_DATA_H
