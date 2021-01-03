#include <iostream>
#include <fstream>
#include "formatPrint.h"
#include "database.h"
#include "data_operate.h"
using namespace std;
int main() {
    dataOperate::pull_data();
    string account;
    string password;
    while(true){
        string temp;
        formatPrint::formatPrintMenu();
        cin>>temp;
        if(temp=="1"){
            formatPrint::format_sign_in();
            cin>>account;
            cin>>password;
            if(verify::verify_account(account,password)){
                break;
            }else{
                cout<<"账号或密码错误"<<endl;
                continue;
            }
        }else if(temp=="2"){
            while(true) {
                formatPrint::format_sign_up();
                string account;
                string password;
                string nickname;
                string telephone;
                string transaction;
                cin>>account;
                if (originData::totalPerson.find(account) != originData::totalPerson.end()) {
                    cout << "账号已存在" << endl;
                    continue;
                }
                cin>>password;
                cin>>nickname;
                cin>>telephone;
                cin>>transaction;
                //验证密码
                string again;
                cout<<"请验证登录密码"<<endl;
                cin>>again;
                if(again==password){
                    simplePerson::signUp(account,password,nickname,telephone,transaction);
                    dataOperate::store_data();
                    dataOperate::pull_data();
                    break;
                }else{
                    cout<<"密码错误"<<endl;
                    continue;
                }
            }
        }else if(temp=="0"){
            formatPrint::formatExit();
            dataOperate::store_data();
            exit(0);
        }else{
            formatPrint::invalidInput();
            continue;
        }
    }
    if(account==originData::admin_id){
        while(1){
            formatPrint::formatPrint_admin();
            string a;
            cin>>a;
            if(a=="1"){
                cout<<"请输入公告内容"<<endl;
                string x;
                cin>>x;
                dataOperate::revise_announcement(x);
                dataOperate::store_data();
                dataOperate::pull_data();
                cout<<"修改成功"<<endl;
            }else if(a=="0"){
                formatPrint::formatExit();
                exit(0);
            }else{
                formatPrint::invalidInput();
                continue;
            }
        }
    }else{
        while(true){
            formatPrint::formatPrint_simple();
            string judge;
            cin>>judge;
            if(judge=="1"){
                vector<book> ans=verify::get_selling_books();
                if(ans.empty()){
                    cout<<"无记录"<<endl;
                }else{
                    for(int i=0;i<ans.size();i++){
                        cout<<"书名："<<ans[i].getBookName()<<' '<<"作者："<<ans[i].getAuthor()<<endl
                            <<"价格："<<ans[i].getPrice()<<' '<<"卖家："<<ans[i].getSeller()<<endl;
                    }
                }
                continue;
            }else if(judge=="2"){
                originData::totalPerson[account].viewSealingBook();
                continue;
            }else if(judge=="3"){
                originData::totalPerson[account].viewBuyingBook();
                continue;
            }else if(judge=="4"){
                cout<<"请输入该书的各项信息"<<endl
                    <<"书名，作者名，出版单位，出版时间，登录号，价格，分类号"<<endl;
                string bookname,author,publisher,pbtime,loginnum,classfy;
                string price;
                cin>>bookname>>author>>publisher>>pbtime>>loginnum>>price>>classfy;
                book temp(bookname,author,publisher,pbtime,loginnum,price,classfy);
                originData::totalPerson[account].sellABook(temp);
                dataOperate::store_data();
                dataOperate::pull_data();
                continue;
            }else if(judge=="5"){
                cout<<"请输入书的名字";
                string bookname;
                cin>>bookname;
                if(originData::totalBook.find(bookname)==originData::totalBook.end()){
                    cout<<"没有这本书"<<endl;
                    continue;
                }
                originData::totalPerson[account].buyABook(originData::totalBook[bookname]);
                dataOperate::store_data();
                dataOperate::pull_data();
                continue;
            }else if(judge=="6"){
                cout<<"请输入书名";
                string bookname;
                cin>>bookname;
                originData::totalPerson[account].verify(originData::totalBook[bookname].getBookName());
                dataOperate::store_data();
                dataOperate::pull_data();
                continue;
            }else if(judge=="0"){
                formatPrint::formatExit();
                dataOperate::pull_data();
                dataOperate::store_data();
                exit(0);
            }else{
                formatPrint::invalidInput();
            }
        }
    }
    return 0;
}