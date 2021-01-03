//
// Created by 胡思佳 on 2020/6/21.
//

#include "formatPrint.h"
#include "database.h"
#include<iostream>
using namespace std;
void formatPrint::formatPrintMenu() {
    cout<<"欢迎来到校园二手书交易系统!"<<endl;
    cout<<"今日公告:"<<originData::announcement<<endl;
    cout<<"1.登录"<<endl;
    cout<<"2.注册"<<endl;
    cout<<"0.退出"<<endl;
}
void formatPrint::invalidInput() {
    cout<<"输入无效"<<endl;

}

void formatPrint::formatExit() {
    cout<<"开心每一天,希望你的每一天都有书的陪伴"<<endl;
}
void formatPrint::format_sign_up(){
    cout<<"请在下面五行分别输入以下信息"<<endl
        <<"1.账号："<<endl
        <<"2.密码："<<endl
        <<"3.昵称："<<endl
        <<"4.电话："<<endl
        <<"5.交易密码："<<endl;
}
void formatPrint::format_sign_in() {
    cout<<"请在下面两行输入你的账号密码"<<endl;
}
void formatPrint::formatPrint_simple() {
    cout<<"欢迎来到校园二手书交易系统"<<endl
        <<"你可以选择以下操作"<<endl
        <<"1.查看正在售卖的书籍"<<endl
        <<"2.查看你的销售记录"<<endl
        <<"3.查看你的购买记录"<<endl
        <<"4.销售一本书"<<endl
        <<"5.购买一本书"<<endl
        <<"6.确认收货一本书"<<endl
        <<"0.退出"<<endl;
}

void formatPrint::formatPrint_admin() {
    cout<<"欢迎来到校园二手书交易系统"<<endl
        <<"你可以选择以下操作"<<endl
        <<"1.修改公告"<<endl
        <<"0.退出"<<endl;

}
