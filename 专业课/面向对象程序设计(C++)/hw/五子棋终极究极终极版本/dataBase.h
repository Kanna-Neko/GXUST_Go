#ifndef C__GAME_REVISE_DATA_H
#define C__GAME_REVISE_DATA_H
#include<string>
#include<vector>
#include<map>
using namespace std;
class baseData{
public:
    baseData();
    baseData(string,string);
    string getId();
    string getPassword();
    void setId(string newId);//创建新账户
    void setPassword(string newPassword);//创建密码
    virtual bool isAdmin()=0;
protected:
    string id;
    string password;
};
class PersonData: public baseData{
public:
    bool operator <(const PersonData& x)const;
    PersonData();
    PersonData(string newId,string newPassword);
    int getWins();//返回胜利场数
    int getTotalGame();//返回总游戏场数
    double getWinProportion();//返回获胜比例
    void setNewWins(int newWins);//
    void setNewTotalGame(int newTotalGame);
    void setNewProportion(double newProportion);
    void winGame();//比赛获胜后修改相关数据
    void loseGame();//比赛失败后修改相关数据
    bool isAdmin();
private:
    int wins;
    int totalGame;
    double Proportion;
};
class admin: public baseData{
public:
    bool isAdmin();
};
namespace originAndStore{
    //直接填充origin命名空间的DataStore变量
    void pullDataToVector();
    //储存数据至文件
    void StoreDataToFile();
}
#endif //C__GAME_REVISE_DATA_H

