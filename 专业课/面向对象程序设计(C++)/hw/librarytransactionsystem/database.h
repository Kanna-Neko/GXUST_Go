//
// Created by 胡思佳 on 2020/6/23.
//
#ifndef LIBRARYTRANSACTIONSYSTEM_DATABASE_H
#define LIBRARYTRANSACTIONSYSTEM_DATABASE_H
#include<string>
#include<map>
#include<vector>
using namespace std;
class book{
public:
    book();
    book(string name,string aut,string puber,string pt,string lognum,string pr,string clas);
    string getBookName()const;
    string getAuthor() const;
    string getPublisher()const;
    string getPbTime()const;
    string getLoginNum()const;
    string getPrice()const;
    string getClassfy()const;
    string getStatus()const;
    void setStatus(string);
    void setBuyer(string);
    void setSeller(string);
    string getSeller();
    string getBuyer();
private:
    string bookName; /*书名*/
    string author; /*作者名*/
    string publisher; /*出版单位*/
    string pbTime; /*出版时间*/
    string loginNum; /*登陆号*/
    string price{}; /*价格*/
    string classfy; /*分类号*/
    string status;
    string buyer;
    string seller;
};
class personBase{
public:
    personBase();
    personBase(const string& a,const string& p);
    string get_account()const;
    string get_password()const;
    virtual bool isAdmin()const=0;
protected:
    string account;
    string password;
};
class simplePerson:public personBase{
public:
    bool isAdmin()const;
    simplePerson()=default;
    simplePerson(const string& a,const string& p):personBase(a,p){}
    string getNickname()const;
    string getTelephone()const;
    string getTransactionPassword()const;
    void setNickname(const string&);
    void setTelephone(const string&);
    void setTransactionPassword(const string&);
    void sellABook(book);
    void buyABook(book);
    void verify(const string& name);
    void viewSealingBook();
    void viewBuyingBook();
    static void signUp(string ac,string pass,string nick,string tele,string trans);
private:
    string nickname;
    string telephone;
    string transactionPassword;
    vector<book*>totalSell;
    vector<book*>totalBuy;
};
class admin:public personBase{
public:
    bool isAdmin()const;
};
namespace originData{
    extern map<string,book>totalBook;
    extern map<string,simplePerson>totalPerson;
    extern const string admin_id;
    extern const string admin_password;
    extern string announcement;
}
namespace bookStatus{
    extern const string selling;
    extern const string transacting;
    extern const string complete;
}
#endif //LIBRARYTRANSACTIONSYSTEM_DATABASE_H
