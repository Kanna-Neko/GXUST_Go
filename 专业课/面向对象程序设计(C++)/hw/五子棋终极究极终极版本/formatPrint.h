#ifndef C__GAME_REVISE_FORMATPRINT_H
#define C__GAME_REVISE_FORMATPRINT_H
#include"dataBase.h"
namespace formatPrint{
    //主菜单可视化
    void formatMeun();
    //输出个人信息
    void formatPersonData(PersonData);
    //输出排行榜信息
    void formatListData(vector<PersonData>);
    //退出游戏时的输出信息
    void formatExit();
    //sign up时的提示信息
    void formatSignUp();
    //sign in时的提示信息
    void formatSignIn();
    //管理员界面
    void formatAdmin();
    //普通用户界面
    void formatSimple();
    //输入无效
    void invalidInput();
}
#endif //C__GAME_REVISE_FORMATPRINT_