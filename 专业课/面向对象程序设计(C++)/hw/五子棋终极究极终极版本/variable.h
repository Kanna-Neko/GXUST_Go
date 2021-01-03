#ifndef C__GAME_REVISE_VARIABLE_H
#define C__GAME_REVISE_VARIABLE_H
#include<string>
#include"dataBase.h"
using namespace std;
namespace originAndStore{
    //规定的输入文件名
    extern const string inputFileName;
//储存数据的数组，链式储存
    extern vector<PersonData>totalPerson;
//公告储存
    extern string announcement;
//管理员账户
    extern const string AdminId;
//管理员密码
    extern const string AdminPassword;
}
#endif //C__GAME_REVISE_VARIABLE_H
