#include <iostream>
#include"map.h"
#include"chess.h"
#include"gameStart.h"
#include"formatPrint.h"
#include"dataOperate.h"
#include"variable.h"
using namespace std;
using input::enter;
int main() {
    originAndStore::pullDataToVector();
    int player1=0;
    int player2=0;
    //下面这个循环代表的是刚登陆界面的注册，登录
    while(true){
        //输出主界面
        formatPrint::formatMeun();
        string temp;
        cin>>temp;
        //判断是注册，还是登录，还是退出
        if(temp=="0"){
            //退出
            formatPrint::formatExit();
            exit(0);
        }
        else if(temp=="2"){
            //注册
            while(true){
                string Id;
                string password;
                formatPrint::formatSignUp();
                cin>>Id;
                int n = dataVerify::verifyIdFormat(Id);
                while(!n){//检验密码格式是否正确
                    cin>>Id;
                    n=dataVerify::verifyIdFormat(Id);
                }

                //验证用户名
                if(Id=="root"||dataFind::dataFindPerson(Id)!=-1){
                    cout<<"你注册的账号已存在"<<"请更换用户名"<<endl;
                    continue;
                }

                //输入密码
                cin>>password;
                int m = dataVerify::verifyPasswordFormat(password);
                while(!m){//检测密码格式是否正确
                    cin>>password;
                    m = dataVerify::verifyPasswordFormat(password);
                }
                cout<<"请验证你的密码"<<endl;
                //再次验证密码
                string again;
                cin>>again;
                if(password!=again){
                    cout<<"两次输入的密码不相同"<<endl;
                    //密码不同则再次进行注册
                    continue;
                }
                PersonData x(Id,password);
                //注册成功并添加数据
                dataOperate::addPerson(x);
                cout<<"注册成功"<<endl;
                originAndStore::StoreDataToFile();
                break;
            }
        }
        else if(temp=="1") {
            formatPrint::formatSignIn();
            //输入id和密码
            cin >> storeData::input_id1;
            cin >> storeData::input_password1;
            if (dataVerify::verifyPassword(storeData::input_id1, storeData::input_password1)) {
                player1=1;//保证账号1的正确性
                break;
            }
            else {
                cout << "账号或密码错误" << "请重头再来" << endl;
                continue;
            }
        }
        else{
            //除0，1，2外的输出则视为无效输出
            formatPrint::invalidInput();
            continue;
        }
    }
    if(storeData::input_id1==originAndStore::AdminId){
        //管理员账户
        string m;
        int n=1;
        while(n) {
            formatPrint::formatAdmin();
            string num;
            cin >> num;
            if (num == "1") {
                string news;
                cin >> news;
                originAndStore::announcement = news;
                originAndStore::StoreDataToFile();
                cout<<"继续进行管理员操作请按1"<<endl
                    <<"退出管理员操作请按0"<<endl;
                cin>>m;
            }
            else if (num == "2") {
                cout << "查看全部用户信息请按0" << endl
                     << "根据ID查看一个用户信息请按1" << endl;
                string x;
                cin >> x;
                if (x == "0") {           //查看所有用户信息
                    for (int i = 0; i < originAndStore::totalPerson.size(); ++i)
                        cout << "用户" << i + 1 << endl
                             << "用户名: " << originAndStore::totalPerson[i].getId() << endl
                             << "用户密码: " << originAndStore::totalPerson[i].getPassword() << endl
                             << "用户胜利场数: " << originAndStore::totalPerson[i].getWins() << endl
                             << "用户总游戏场数: " << originAndStore::totalPerson[i].getTotalGame() << endl;
                }
                else if (x == "1") {      //查看一个用户信息
                    string playerId;
                    cout << "请输入你要查找的ID账号信息" << endl;
                    cin >> playerId;
                    int n = dataFind::dataFindPerson(playerId);
                    if (n == -1) {
                        cout << "没有该用户" << endl;
                    }
                    else {
                        cout << "用户名: " << originAndStore::totalPerson[n].getId() << endl
                             << "用户密码: " << originAndStore::totalPerson[n].getPassword() << endl
                             << "用户胜利场数: " << originAndStore::totalPerson[n].getWins() << endl
                             << "用户总游戏场数: " << originAndStore::totalPerson[n].getTotalGame() << endl;
                    }
                }
                else {
                    formatPrint::invalidInput();
                }
                cout << "继续进行管理员操作请按1" << endl
                     << "退出管理员操作请按0" << endl;
                cin >> m;
            }
            else if (num == "3") {
                cout<<"请输入待删除用户ID"<<endl;
                string playerId;
                cin>>playerId;
                dataOperate::deletePerson(playerId);
                cout << "删除成功" << endl;
                cout<<"继续进行管理员操作请按1"<<endl
                    <<"退出管理员操作请按0"<<endl;
                originAndStore::StoreDataToFile();
                cin>>m;
            }
            else if(num=="4"){
                cout<<"修改用户胜利次数请按1"<<endl
                <<"修改用户的总游戏场数请按2"<<endl;
                string z;
                cin>>z;
                if(z=="1"){
                    cout<<"请在下面两行输入要修改的用户的ID和新的胜利场数"<<endl;
                    string id;
                    int NewWins;
                    cin>>id;
                    cin>>NewWins;
                    dataOperate::revisePersonWins(id,NewWins);
                }
                else if(z=="2"){
                    cout<<"请在下面两行输入要修改的用户的ID和新的总游戏场数"<<endl;
                    string id;
                    int totalGame;
                    cin>>id;
                    cin>>totalGame;
                    dataOperate::revisePersonTotals(id,totalGame);
                }
                else{
                    formatPrint::formatExit();
                }
                originAndStore::StoreDataToFile();
                cout<<"继续进行管理员操作请按1"<<endl
                    <<"退出管理员操作请按0"<<endl;
                cin>>m;
            }
            else {
                formatPrint::invalidInput();
                cout<<"继续进行管理员操作请按1"<<endl
                    <<"退出管理员操作请按0"<<endl;
                cin>>m;
            }
            while(true) {
                if (m == "1") {
                    n = 1;
                    break;
                } else if (m == "0") {
                    formatPrint::formatExit();
                    n = 0;
                    break;
                } else {
                    formatPrint::invalidInput();
                    cout << "请重新输入" << endl;
                    cin >> m;
                }
            }
        }

    }

    else {
        //普通账户
        string x;
        int y = 1;
        while (y) {
            formatPrint::formatSimple();
            string num;
            cin >> num;
            if (num == "1") {
                while (true) {
                    cout << "请输入第二个账户开始一起游戏吧！！！" << endl;
                    formatPrint::formatSignIn();
                    //输入id和密码
                    cin >> storeData::input_id2;
                    cin >> storeData::input_password2;
                    if (dataVerify::verifyPassword(storeData::input_id2, storeData::input_password2)
                        && storeData::input_id2 != storeData::input_id1 &&
                        storeData::input_id2 != originAndStore::AdminId) {
                        player2 = 1;//保证账号2的正确性
                        break;
                    }
                    else {
                        cout << "账号或密码错误" << "请重头再来" << endl;
                    }
                }
                if (player1 == 1 && player2 == 1) {
                    gameStart::gameStart();
                    while (true) {
                        cout << "继续游戏请按1" << endl;
                        cout << "退出游戏请按2" << endl;
                        int n;
                        cin >> n;
                        switch (n) {
                            case 1: {
                                gameStart::gameStart();
                                break;
                            }
                            case 2: {
                                formatPrint::formatExit();
                                break;
                            }
                        }
                        if (n == 2) {
                            break;
                        }
                    }
                }
                cout << "继续进行用户操作请按1" << endl
                     << "退出用户操作请按0" << endl;
                cin >> x;
            }
            else if (num == "2") {
                int n = dataFind::dataFindPerson(storeData::input_id1);
                if (n == -1) {
                    cout << "没有该用户" << endl;
                } else {
                    cout << "用户名: " << originAndStore::totalPerson[n].getId() << endl
                         << "用户密码: " << originAndStore::totalPerson[n].getPassword() << endl
                         << "用户胜利场数: " << originAndStore::totalPerson[n].getWins() << endl
                         << "用户总游戏场数: " << originAndStore::totalPerson[n].getTotalGame() << endl;
                }
                cout << "继续进行用户操作请按1" << endl
                     << "退出用户操作请按0" << endl;
                cin >> x;
            }
            else if (num == "3") {
                int n;
                if (originAndStore::totalPerson.size() > 10) {
                    n = 10;
                } else {
                    n = originAndStore::totalPerson.size();
                }
                vector<PersonData> ans(dataFind::dataFindListHigher(n));
                for (int i = 0; i < n; i++) {
                    cout << "NO:" << i + 1 << endl
                         << "用户名：" << ans[i].getId() << endl
                         << "胜利场数：" << ans[i].getWins() << endl << endl;
                }
                cout << "继续进行用户操作请按1" << endl
                     << "退出用户操作请按0" << endl;
                cin >> x;
            }
            else if (num == "4") {     //修改密码
                string NewPassword;
                cout << "请输入新的密码" << endl;
                cin >> NewPassword;
                dataOperate::revisePersonPassword(storeData::input_id1, NewPassword);
                originAndStore::StoreDataToFile();
                cout << "继续进行用户操作请按1" << endl
                     << "退出用户操作请按0" << endl;
                cin >> x;
            }
            else if (num == "5") {
                originAndStore::StoreDataToFile();
                formatPrint::formatExit();
                exit(0);
            }
            else {
                formatPrint::invalidInput();
                cout << "继续进行用户操作请按1" << endl
                     << "退出用户操作请按0" << endl;
                cin >> x;
            }

            while (true) {
                if (x == "1") {
                    y = 1;
                    break;
                } else if (x == "0") {
                    formatPrint::formatExit();
                    y = 0;
                    break;
                } else {
                    formatPrint::invalidInput();
                    cout << "请重新输入" << endl;
                    cin >> x;
                }
            }
        }
    }
    return 0;
}