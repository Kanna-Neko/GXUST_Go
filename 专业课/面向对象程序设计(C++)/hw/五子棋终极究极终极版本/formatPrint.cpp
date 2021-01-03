#include<iostream>
#include "formatPrint.h"
#include"variable.h"
void formatPrint::formatMeun() {//主菜单可视化
    cout<<"欢迎进入五子棋游戏"<<endl
        <<"今日公告："<<originAndStore::announcement<<endl;
    cout<<"登入游戏请输入1"<<endl
        <<"注册账号请输入2"<<endl
        <<"退出游戏请输入0"<<endl;
}

void formatPrint::formatExit() { //退出游戏时的输出信息
    cout<<"开心每一天,期待你的下一次游戏"<<endl;
}

void formatPrint::formatSignUp() {//sign up时的提示信息
    cout<<"请在下面2行输入你待注册的账号密码"<<endl<<
          "(请分别输入六位用英文字符表示的账号和六位用数字字符表示的密码)"<<endl;
}

void formatPrint::formatSignIn() { //sign in时的提示信息
    cout<<"请在下面2行输入你待登录的账号密码"<<endl;
}

void formatPrint::formatAdmin() {//管理员界面
    cout<<"管理员欢迎您"<<endl
        <<"1.修改公告"<<endl
        <<"2.根据id查询个人信息"<<endl
        <<"3.根据id删除用户"<<endl
        <<"4.修改用户信息"<<endl;
}

void formatPrint::formatSimple() { //普通用户界面
    cout<<"欢迎来到五子棋游戏"<<endl
        <<"1.开始游戏"<<endl
        <<"2.查看个人信息"<<endl
        <<"3.查看排行榜"<<endl
        <<"4.修改密码"<<endl
        <<"5.退出游戏"<<endl;
}

void formatPrint::invalidInput() {//输入无效
    cout<<"输入无效"<<endl;

}

void formatPrint::formatPersonData(PersonData player) {//输出个人信息
    cout<<"用户名: "<<player.getId()<<"用户密码: "<<player.getPassword()
    <<"获胜场数: "<<player.getWins()<<"总比赛场数: "<<player.getTotalGame()
    <<"获胜概率: "<<player.getWinProportion()<<endl;
}

void formatPrint::formatListData(vector<PersonData> ranks) {//输出排行榜信息
    for(int i=0;i<ranks.size();++i)
        cout<<i+1<<" "<<ranks[i].getWins()<<endl;
}