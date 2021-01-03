//
// Created by 胡思佳 on 2020/6/21.
//
#include "database.h"
#include "data_operate.h"
#include<fstream>
#include<iostream>

bool verify::verify_account(const string& input_id, const string& input_password) {
    if(input_id==originData::admin_id&&input_password==originData::admin_password){
        return true;
    }
    if(originData::totalPerson.find(input_id)==originData::totalPerson.end()){
        return false;
    }
    if(originData::totalPerson[input_id].get_password()==input_password){
        return true;
    }else{
        return false;
    }
}

vector<book> verify::get_selling_books() {
    vector<book>ans;
    for(auto iter=originData::totalBook.begin();iter!=originData::totalBook.end();iter++){
        if(iter->second.getStatus()==bookStatus::selling){
            ans.push_back(iter->second);
        }
    }
    return ans;
}

void dataOperate::revise_announcement(const string& new_announcement) {
    originData::announcement=new_announcement;
}

void dataOperate::store_data() {
    ofstream os("person.txt",ofstream::trunc|ofstream::out);
    if(!os.is_open()){
        std::cerr<<"error,文件打开错误"<<endl;
        exit(0);
    }
    for(auto iter=originData::totalPerson.begin();iter!=originData::totalPerson.end();iter++){
        os<<iter->second.get_account()<<' '<<iter->second.get_password()<<' '<<iter->second.getNickname()
            <<' '<<iter->second.getTelephone()<<' '<<iter->second.getTransactionPassword()<<endl;
    }
    os.close();
    os.open("book.txt",ofstream::trunc|ofstream::out);
    if(!os.is_open()){
        std::cerr<<"error,文件打开错误"<<endl;
        exit(0);
    }
    for(auto iter=originData::totalBook.begin();iter!=originData::totalBook.end();iter++){
        os<<iter->second.getBookName()<<' '<<iter->second.getAuthor()<<' '<<iter->second.getPublisher()<<' '
            <<iter->second.getPbTime()<<' '<<iter->second.getLoginNum()<<' '<<iter->second.getPrice()<<' '<<
            iter->second.getClassfy()<<' '<<iter->second.getStatus()<<' '<<iter->second.getSeller()<<' '<<iter->second.getBuyer()<<endl;
    }
    os.close();
    os.open("announcement.txt");
    if(!os.is_open()){
        std::cerr<<"error,文件打开错误"<<endl;
        exit(0);
    }
    os<<originData::announcement<<endl;
    os.close();
}

void dataOperate::pull_data() {
    ifstream io("announcement.txt");
    if(!io.is_open()){
        std::cerr<<"error,文件打开错误"<<endl;
        exit(0);
    }
    io>>originData::announcement;
    io.close();
    io.open("person.txt");
    if(!io.is_open()){
        std::cerr<<"error,文件打开错误"<<endl;
        exit(0);
    }
    while(io){
        string a,b,c,d,e;
        io>>a>>b>>c>>d>>e;
        simplePerson::signUp(a,b,c,d,e);
    }
    io.close();
    io.open("book.txt");
    if(!io.is_open()){
        std::cerr<<"error,文件打开错误"<<endl;
        exit(0);
    }
    while(io){
        string a,b,c,d,e;
        string f;
        string g,h,i,j;
        io>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
        book temp(a,b,c,d,e,f,g);
        originData::totalBook[temp.getBookName()]=temp;
        originData::totalBook[temp.getBookName()].setStatus(h);
        originData::totalBook[temp.getBookName()].setSeller(i);
        originData::totalBook[temp.getBookName()].setBuyer(j);
    }
    io.close();
}
