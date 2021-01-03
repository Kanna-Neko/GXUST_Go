#include<string>
#include"dataBase.h"
using namespace std;
namespace originAndStore{
    //规定的输入文件名
    string inputFileName="Data.txt";
//储存数据的数组，链式储存
    vector<PersonData>totalPerson=vector<PersonData>();
//公告储存
    string announcement="欢迎来到五子棋游戏";
//管理员账户
    string AdminId="root";
//管理员密码
    string AdminPassword="happy2020";
}