#include <iostream>
#include <string>
#include <vector>
#include "data.h"
using namespace std;
int main() {
    string flag;
    string account;
    string password;
    data_store::pull_data();
    //登录阶段
    while(true){
        cout<<"欢迎来到学生成绩管理系统"<<endl
            <<"1.学生登录"<<endl
            <<"2.老师登录"<<endl
            <<"3.管理员登录"<<endl;
        cin>>flag;
        if(flag=="1"){
            //学生登录
            cout<<"请输入账号和密码"<<endl;
            cin>>account>>password;
            int index=tool::find_student_index(account);
            if(index==-1){
                cout<<"账号或密码错误"<<endl;
                continue;
            }else{
                if(data_store::total_student[index].get_password()==password){
                    cout<<"登录成功"<<endl;
                    break;
                }else{
                    cout<<"账号或密码错误"<<endl;
                    continue;
                }
            }
        }else if(flag=="2"){
            //老师登录
            cout<<"请输入账号密码"<<endl;
            cin>>account>>password;
            int index=tool::find_teacher_index(account);
            if(index==-1){
                cout<<"账号或密码错误"<<endl;
                continue;
            }else{
                if(data_store::total_teacher[index].get_password()==password){
                    cout<<"登录成功"<<endl;
                    break;
                }else{
                    cout<<"账号或密码错误"<<endl;
                    continue;
                }
            }
        }else if(flag=="3"){
            //管理员登录
            cout<<"请输入账号密码"<<endl;
            cin>>account>>password;
            if(account==data_store::admin_account&&password==data_store::admin_password){
                cout<<"登录成功"<<endl;
                break;
            }else{
                cout<<"登录失败"<<endl;
            }
        }else{
            cout<<"违法输入"<<endl;
            continue;
        }
    }
    //操作阶段
    while(true) {
        if (flag == "1") {
            //学生界面
            int index = tool::find_student_index(account);
            cout << "你可以查看自己的成绩" << endl
                 << "1.数学" << endl
                 << "2.英语" << endl
                 << "3.c++" << endl
                 << "4.电子电路基础" << endl
                 << "5.数字逻辑" << endl
                 << "6.体育" << endl
                 << "7.总成绩" << endl
                 << "8.平均成绩" << endl
                 << "9.同时列出以上选项" << endl
                 << "10.修改密码" << endl
                 << "0.退出" << endl;
            string temp;
            cin >> temp;
            if (temp == "1") {
                cout << "数学:" << data_store::total_student[index].get_grade(0) << endl;
            } else if (temp == "2") {
                cout << "英语:" << data_store::total_student[index].get_grade(1) << endl;
            } else if (temp == "3") {
                cout << "c++:" << data_store::total_student[index].get_grade(2) << endl;
            } else if (temp == "4") {
                cout << "电子电路基础:" << data_store::total_student[index].get_grade(3) << endl;
            } else if (temp == "5") {
                cout << "数字逻辑:" << data_store::total_student[index].get_grade(4) << endl;
            } else if (temp == "6") {
                cout << "体育:" << data_store::total_student[index].get_grade(5) << endl;
            } else if (temp == "7") {
                cout << "总成绩:" << data_store::total_student[index].get_all_grade() << endl;
            } else if (temp == "8") {
                cout << "平均成绩:" << data_store::total_student[index].get_aver() << endl;
            } else if (temp == "9") {
                cout << "account:" << data_store::total_student[index].get_account() << endl;
                cout << "password:" << data_store::total_student[index].get_password() << endl;
                cout << "Id:" << data_store::total_student[index].get_id() << endl;
                cout << "name:" << data_store::total_student[index].get_name() << endl;
                cout << "sex:" << data_store::total_student[index].get_sex() << endl;
                cout << "数学:" << data_store::total_student[index].get_grade(0) << endl;
                cout << "英语:" << data_store::total_student[index].get_grade(1) << endl;
                cout << "c++:" << data_store::total_student[index].get_grade(2) << endl;
                cout << "电子电路基础:" << data_store::total_student[index].get_grade(3) << endl;
                cout << "数字逻辑:" << data_store::total_student[index].get_grade(4) << endl;
                cout << "体育:" << data_store::total_student[index].get_grade(5) << endl;
                cout << "总成绩:" << data_store::total_student[index].get_all_grade() << endl;
                cout << "平均成绩:" << data_store::total_student[index].get_aver() << endl;
            } else if (temp == "10") {
                string new_password, again_password;
                cout << "请输入新密码" << endl;
                cin >> new_password;
                cout << "请重复输入新密码" << endl;
                cin >> again_password;
                if (new_password == again_password) {
                    data_store::total_student[index].alter_password(new_password);
                } else {
                    cout << "两次密码不相同,少侠请从头来过" << endl;
                    continue;
                }
            } else if (temp == "0") {
                cout << "bye～" << endl;
                break;
            } else {
                cout << "违法输入" << endl;
                continue;
            }
        } else if (flag == "2") {
            //教师界面
            int index = tool::find_teacher_index(account);
            cout << "1.增加学生信息" << endl
                 << "2.删除学生信息" << endl
                 << "3.查找学生信息" << endl
                 << "4.修改学生信息" << endl
                 << "0.exit" << endl;
            string temp;
            cin >> temp;
            if (temp == "1") {
                cout << "请输入学生的账号,密码,ID,姓名,性别,6门学科成绩";
                string new_account;
                string new_password;
                string new_id;
                string new_name;
                string new_sex;
                int grade[6];
                cin >> new_account >> new_password >> new_id >> new_name >> new_sex;
                cin >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> grade[4] >> grade[5];
                bool judge = teacher::add_student_account(new_account, new_password, new_id, new_name, new_sex, grade);
                if (judge) {
                    cout << "添加成功" << endl;
                } else {
                    cout << "添加失败" << endl;
                }
                data_store::store_data();
                data_store::pull_data();
                continue;
            } else if (temp == "2") {
                //删除学生信息
                cout << "请输入需要删除学生的账户" << endl;
                string input_account;
                cin >> input_account;
                bool judge = teacher::delete_student_account(account);
                if (judge) {
                    cout << "删除成功" << endl;
                } else {
                    cout << "删除失败" << endl;
                }
                data_store::store_data();
                data_store::pull_data();
                continue;
            } else if (temp == "3") {
                //查找学生信息
                cout << "请输入查询学生的账户" << endl;
                string input_account;
                cin >> input_account;
                int index_student = tool::find_student_index(input_account);
                if (index_student == -1) {
                    cout << "账号错误" << endl;
                } else {
                    cout << "account:" << data_store::total_student[index_student].get_account() << endl;
                    cout << "password:" << data_store::total_student[index_student].get_password() << endl;
                    cout << "Id:" << data_store::total_student[index_student].get_id() << endl;
                    cout << "name:" << data_store::total_student[index_student].get_name() << endl;
                    cout << "sex:" << data_store::total_student[index_student].get_sex() << endl;
                    cout << "数学:" << data_store::total_student[index_student].get_grade(0) << endl;
                    cout << "英语:" << data_store::total_student[index_student].get_grade(1) << endl;
                    cout << "c++:" << data_store::total_student[index_student].get_grade(2) << endl;
                    cout << "电子电路基础:" << data_store::total_student[index_student].get_grade(3) << endl;
                    cout << "数字逻辑:" << data_store::total_student[index_student].get_grade(4) << endl;
                    cout << "体育:" << data_store::total_student[index_student].get_grade(5) << endl;
                    cout << "总成绩:" << data_store::total_student[index_student].get_all_grade() << endl;
                    cout << "平均成绩:" << data_store::total_student[index_student].get_aver() << endl;
                }
            } else if (temp == "4") {
                //修改学生信息
                cout << "请输入查询学生的账户" << endl;
                string input_account;
                cin >> input_account;
                int index_student = tool::find_student_index(input_account);
                if (index_student == -1) {
                    cout << "账号错误" << endl;
                } else {
                    string x;
                    cout << "1.password" << endl
                         << "2.ID" << endl
                         << "3.name" << endl
                         << "4.sex" << endl
                         << "5.数学成绩" << endl
                         << "6.英语成绩" << endl
                         << "7.c++成绩" << endl
                         << "8.电子电路成绩" << endl
                         << "9.数字逻辑成绩" << endl
                         << "10.体育成绩" << endl
                         << "0.退出" << endl;
                    cin >> x;
                    if (x == "1") {
                        cout << "请输入新密码";
                        string new_password;
                        cin >> new_password;
                        data_store::total_student[index_student].alter_password(new_password);
                    } else if (x == "2") {
                        cout << "请输入新ID" << endl;
                        string new_ID;
                        cin >> new_ID;
                        data_store::total_student[index_student].alter_id(new_ID);
                    } else if (x == "3") {
                        cout << "请输入新name" << endl;
                        string new_name;
                        cin >> new_name;
                        data_store::total_student[index_student].alter_name(new_name);
                    } else if (x == "4") {
                        cout << "请输入新sex" << endl;
                        string new_sex;
                        cin >> new_sex;
                        data_store::total_student[index_student].alter_sex(new_sex);
                    } else if (x == "5") {
                        cout << "请输入新数学成绩" << endl;
                        int new_point;
                        cin >> new_point;
                        data_store::total_student[index_student].alter_grade(grade_name::math, new_point);
                    } else if (x == "6") {
                        cout << "请输入新英语成绩" << endl;
                        int new_point;
                        cin >> new_point;
                        data_store::total_student[index_student].alter_grade(grade_name::english, new_point);
                    } else if (x == "7") {
                        cout << "请输入新c++成绩" << endl;
                        int new_point;
                        cin >> new_point;
                        data_store::total_student[index_student].alter_grade(grade_name::cpp, new_point);
                    } else if (x == "8") {
                        cout << "请输入新电子电路逻辑" << endl;
                        int new_point;
                        cin >> new_point;
                        data_store::total_student[index_student].alter_grade(grade_name::digital_circuit, new_point);
                    } else if (x == "9") {
                        cout << "请输入新数字逻辑成绩" << endl;
                        int new_point;
                        cin >> new_point;
                        data_store::total_student[index_student].alter_grade(grade_name::digital_logic, new_point);
                    } else if (x == "10") {
                        cout << "请输入新体育成绩" << endl;
                        int new_point;
                        cin >> new_point;
                        data_store::total_student[index_student].alter_grade(grade_name::PE, new_point);
                    } else if (x == "0") {
                        continue;
                    } else {
                        cout << "非法输入" << endl;
                    }
                    data_store::store_data();
                    data_store::pull_data();
                    continue;
                }
            } else if (temp == "0") {
                cout << "bye～" << endl;
                break;
            } else {
                cout << "非法输入" << endl;
                continue;
            }
        } else {
            //管理员界面
            cout << "1.增加老师信息" << endl
                 << "2.删除老师信息" << endl
                 << "3.查找老师信息" << endl
                 << "4.修改老师信息" << endl
                 << "0.exit" << endl;
            string temp;
            cin >> temp;
            if (temp == "1") {
                //添加老师信息
                cout << "请输入老师的账号,密码,姓名，电话";
                string new_account;
                string new_password;
                string new_name;
                string new_tel;
                cin >> new_account >> new_password >> new_name >> new_tel;
                bool judge = admin_operate::add_teacher_account(new_account, new_password, new_name, new_tel);
                if (judge) {
                    cout << "添加成功" << endl;
                } else {
                    cout << "添加失败" << endl;
                }
                data_store::store_data();
                data_store::pull_data();
                continue;
            } else if (temp == "2") {
                //删除老师信息
                cout << "请输入需要删除老师的账户" << endl;
                string input_account;
                cin >> input_account;
                bool judge =admin_operate::delete_teacher_account(input_account);
                if (judge) {
                    cout << "删除成功" << endl;
                } else {
                    cout << "删除失败" << endl;
                }
                data_store::store_data();
                data_store::pull_data();
                continue;
            } else if (temp == "3") {
                //查找老师信息
                cout << "请输入查询老师的账户" << endl;
                string input_account;
                cin>>input_account;
                teacher x=admin_operate::view_teacher_info(input_account);
                if(x.get_account()==""){
                    cout<<"查找失败"<<endl;
                }else{
                    cout<<"账号:"<<x.get_account()<<endl
                        <<"密码:"<<x.get_password()<<endl
                        <<"姓名:"<<x.get_name()<<endl
                        <<"电话:"<<x.get_tel()<<endl;
                }
            }else if(temp=="4"){
                //修改老师账户
                cout<<"请输入老师账户"<<endl;
                string input_account;
                cin>>input_account;
                teacher x=admin_operate::view_teacher_info(input_account);
                if(x.get_account()==""){
                    cout<<"查找失败"<<endl;
                }else{
                    cout<<"1.修改密码"<<endl;
                    cout<<"2.修改姓名"<<endl;
                    cout<<"3.修改电话"<<endl;
                    cout<<"0.退出"<<endl;
                    string option;
                    cin>>option;
                    if(option=="1"){
                        cout<<"请输入你的新密码"<<endl;
                        string new_password;
                        cin>>new_password;
                        data_store::total_teacher[tool::find_teacher_index(input_account)].alter_password(new_password);
                    }else if(option=="2"){
                        cout<<"请输入你的新姓名"<<endl;
                        string new_name;
                        cin>>new_name;
                        data_store::total_teacher[tool::find_teacher_index(input_account)].alter_name(new_name);
                    }else if(option=="3"){
                        cout<<"请输入你的新电话"<<endl;
                        string new_tel;
                        cin>>new_tel;
                        data_store::total_teacher[tool::find_teacher_index(input_account)].alter_tel(new_tel);
                    }else if(option=="0"){
                        cout<<"Ok"<<endl;
                    }else{
                        cout<<"无效输入"<<endl;
                        continue;
                    }
                    data_store::store_data();
                    data_store::pull_data();
                    continue;
                }
            }else if(temp=="0"){
                cout<<"bye~"<<endl;
                break;
            }else{
                cout<<"违法输入"<<endl;
                continue;
            }
        }
    }
    return 0;
}
