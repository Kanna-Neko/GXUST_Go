#ifndef C__GAME_REVISE_DATAOPERATE_H
#define C__GAME_REVISE_DATAOPERATE_H
#include<iostream>
#include<string>
#include"dataBase.h"
using namespace std;
namespace dataOperate{
    //添加一个人的数据
    void addPerson(PersonData);
    //根据名字删除一个人
    void deletePerson(string id);
    //根据名字修改一个人的胜利次数
    void revisePersonWins(string id,int newWins);
    //根据名字修改一个人的总游戏数
    void revisePersonTotals(string id,int newTotalGame);
    //根据名字修改一个人的密码，需要做到输入的2个密码保持一致，否则重新输入新密码
    void revisePersonPassword(string id,string newPassword);
    //设置公告
    void setAnnouncement(string newAnnouncement);
}
namespace dataVerify{
    //检验账号密码正确性
    bool verifyPassword(string inputId,string inputPassword);
    //检验是否是管理员
    bool verifyIsAdmin(string Id);
    //检验账号是否是正确的格式
    bool verifyIdFormat(string InputString);
    //检验密码是否是正确的格式
    bool verifyPasswordFormat(string password);
}
namespace dataFind{//查找功能
    //返回下标
    vector<PersonData>::size_type dataFindPerson(string name);
    //返回前n个人的数组
    vector<PersonData> dataFindListHigher(int n);
}
#endif //C__GAME_REVISE_DATAOPERATE_H
