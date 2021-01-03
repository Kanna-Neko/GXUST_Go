
#include "data.h"
#include <fstream>
string base_data::get_account() {
    return account;
}

string base_data::get_password() {
    return password;
}

void base_data::alter_password(string new_password) {
    password=new_password;
}

student::student() {
    id="";
    name="";
    sex="";
    for(int i=0;i<6;i++){
        grade[i]=0;
    }
}

student::student(string new_account, string new_password, string new_id, string new_name, string new_sex) {
    account=new_account;
    password=new_password;
    id=new_id;
    name=new_name;
    sex=new_sex;
}

string student::get_id() {
    return id;
}

string student::get_name() {
    return name;
}

string student::get_sex() {
    return sex;
}

int student::get_grade(int n) {
    return grade[n];
}

int student::get_all_grade() {
    int total=0;
    for(int i=0;i<6;i++){
        total+=grade[i];
    }
    return total;
}

void student::alter_value(int n, int value) {
    grade[n]=value;
}

double student::get_aver() {
    int total=get_all_grade();
    return (double)total/6;
}

void student::alter_id(string new_id) {
    id=new_id;
}

void student::alter_name(string new_name) {
    name=new_name;
}

void student::alter_sex(string new_sex) {
    sex=new_sex;
}

void student::alter_grade(int n, int value) {
    grade[n]=value;
}

teacher::teacher()=default;

teacher::teacher(string new_account, string new_password, string new_name, string new_tel) {
    account=new_account;
    password=new_password;
    name=new_name;
    tel=new_tel;
}

string teacher::get_name() {
    return name;
}

string teacher::get_tel() {
    return tel;
}

void teacher::alter_name(string new_name) {
    name=new_name;
}

void teacher::alter_tel(string new_tel) {
    tel=new_tel;
}

bool teacher::add_student_account(string account, string password, string id, string name, string sex, int *grade) {
    int index=tool::find_student_index(account);
    if(index!=-1){
        cout<<"已经存在该账户"<<endl;
        return false;
    }
    data_store::total_student.push_back(student(account,password,id,name,sex));
    for(int i=0;i<6;i++){
        data_store::total_student[data_store::total_student.size()-1].alter_value(i,grade[i]);
    }
    return true;
}

bool teacher::delete_student_account(string account) {
    int index=tool::find_student_index(account);
    if(index==-1){
        cout<<"不存在该账户"<<endl;
        return false;
    }else{
        data_store::total_student.erase(data_store::total_student.begin()+index);
        return true;
    }
}

student teacher::view_student_info(string account) {
    int index=tool::find_student_index(account);
    if(index==-1){
        cout<<"不存在该账户"<<endl;
        return student();
    }else{
        return data_store::total_student[index];
    }
}

namespace data_store{
    vector<student>total_student=vector<student>();
    vector<teacher>total_teacher=vector<teacher>();

}

void data_store::store_data() {
    const string file_name_student="student_data.txt";
    ofstream os(file_name_student,ofstream::out|ofstream::trunc);
    if(!os.is_open()){
        cerr<<"打开文件失败"<<endl;
    }
    for(int i=0;i<data_store::total_student.size();i++){
        os<<data_store::total_student[i].get_account()<<' '<<data_store::total_student[i].get_password()<<' '<<data_store::total_student[i].get_id()<<' '
            <<data_store::total_student[i].get_name()<<' '<<data_store::total_student[i].get_sex()<<' '<<data_store::total_student[i].get_grade(0)
            <<' '<<data_store::total_student[i].get_grade(1)<<' '<<data_store::total_student[i].get_grade(2)<<' '<<data_store::total_student[i].get_grade(3)
            <<' '<<data_store::total_student[i].get_grade(4)<<' '<<data_store::total_student[i].get_grade(5)<<endl;
    }
    os.close();
    const string file_name_teacher="teacher_data.txt";
    os.open(file_name_teacher,ofstream::out|ofstream::trunc);
    if(!os.is_open()){
        cerr<<"打开文件失败"<<endl;
    }
    for(int i=0;i<data_store::total_teacher.size();i++){
        os<<data_store::total_teacher[i].get_account()<<' '<<data_store::total_teacher[i].get_password()<<' '<<data_store::total_teacher[i].get_name()<<' '
                <<data_store::total_teacher[i].get_tel()<<endl;
    }
    os.close();
}

void data_store::pull_data() {
    data_store::total_teacher=vector<teacher>();
    data_store::total_student=vector<student>();
    ifstream is("student_data.txt",ifstream::in);
    if(!is.is_open()){
        cerr<<"打开文件错误!"<<endl;
        exit(0);
    }
    else{
        while(true){
            string a,b,c,d,e;
            int f,g,h,i,j,k;
            is>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k;
            student x(a,b,c,d,e);
            x.alter_grade(0,f);
            x.alter_grade(1,g);
            x.alter_grade(2,h);
            x.alter_grade(3,i);
            x.alter_grade(4,j);
            x.alter_grade(5,k);
            data_store::total_student.push_back(x);
            if(is.eof()){ break;}
        }
        is.close();
        is.open("teacher_data.txt",ifstream::in);
        if(!is.is_open()){
            cerr<<"打开文件错误!"<<endl;
            exit(0);
        }
        else {
            while (true) {
                string a,b,c,d;
                is>>a>>b>>c>>d;
                teacher x(a,b,c,d);
                data_store::total_teacher.push_back(x);
                if (is.eof()) { break; }
            }
        }
    }
    is.close();
}

int tool::find_student_index(string studnet_account) {
    for(int i=0;i<data_store::total_student.size();i++){
        if(data_store::total_student[i].get_account()==studnet_account){
            return i;
        }
    }
    return -1;
}

int tool::find_teacher_index(string teacher_account) {
    for(int i=0;i<data_store::total_teacher.size();i++){
        if(data_store::total_teacher[i].get_account()==teacher_account){
            return i;
        }
    }
    return -1;
}

bool admin_operate::add_teacher_account(string account, string password, string name, string tel) {
    int index=tool::find_teacher_index(account);
    if(index!=-1){
        cout<<"已经存在该账户"<<endl;
        return false;
    }else{
        data_store::total_teacher.push_back(teacher(account,password,name,tel));
        return true;
    }
}

bool admin_operate::delete_teacher_account(string account) {
    int index=tool::find_teacher_index(account);
    if(index==-1){
        cout<<"不存在该账户"<<endl;
        return false;
    }else{
        data_store::total_teacher.erase(data_store::total_teacher.begin()+index);
        return true;
    }
}

teacher admin_operate::view_teacher_info(string account) {
    int index=tool::find_teacher_index(account);
    if(index==-1){
        cout<<"无此账户"<<endl;
        return teacher();
    }
    return data_store::total_teacher[index];
}


