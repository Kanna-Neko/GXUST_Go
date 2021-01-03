//
// Created by 胡思佳 on 2020/6/23.
//

#include "database.h"
#include<iostream>
using namespace std;
book::book(string name, string aut, string puber, string pt, string lognum, string pr, string clas)
:bookName(name),author(aut),publisher(puber),pbTime(pt),loginNum(lognum),price(pr),classfy(clas),seller("0"),buyer("0"){}

void book::setBuyer(string person) {
    buyer=person;
}

void book::setSeller(string person) {
    seller=person;
}

void book::setStatus(string newStatus) {
    this->status=newStatus;
}

string book::getBookName() const {
    return bookName;
}

string book::getAuthor() const {
    return author;
}

string book::getPublisher() const {
    return publisher;
}

string book::getPbTime() const {
    return pbTime;
}

string book::getLoginNum() const {
    return loginNum;
}

string book::getPrice() const {
    return price;
}

string book::getStatus() const {
    return status;
}

string book::getClassfy() const {
    return classfy;
}

book::book() {
    price=0.0;
}

string book::getSeller() {
    return seller;
}

string book::getBuyer() {
    return buyer;
}

void simplePerson::setNickname(const string& name) {
    nickname=name;
}

void simplePerson::setTelephone(const string& phone) {
    telephone=phone;
}

void simplePerson::setTransactionPassword(const string &password) {
    transactionPassword=password;
}

void simplePerson::viewSealingBook() {
    if(totalSell.empty()){
        cout<<"无记录"<<endl;
    }else{
        for(auto iter=totalSell.begin();iter!=totalSell.end();iter++){
            cout<<"书名"<<(*iter)->getBookName()<<endl;
            cout<<"状态"<<(*iter)->getStatus()<<endl<<endl;
        }
    }
}

void simplePerson::sellABook(book newBook) {
    originData::totalBook[newBook.getBookName()]=newBook;
    originData::totalBook[newBook.getBookName()].setSeller(this->account);
    originData::totalBook[newBook.getBookName()].setStatus(bookStatus::selling);
    totalSell.push_back(&(originData::totalBook[newBook.getBookName()]));
}

bool simplePerson::isAdmin() const {
    return false;
}

void simplePerson::signUp(string ac, string pass, string nick, string tele, string trans) {
    simplePerson temp(ac,pass);
    temp.setNickname(nick);
    temp.setTransactionPassword(trans);
    temp.setTelephone(tele);
    originData::totalPerson[ac]=temp;
}

string simplePerson::getNickname() const {
    return nickname;
}

string simplePerson::getTelephone() const {
    return telephone;
}

string simplePerson::getTransactionPassword() const {
    return transactionPassword;
}

void simplePerson::buyABook(book selling_book) {
    cout<<"请输入交易密码"<<endl;
    string password;
    cin>>password;
    if(password!=transactionPassword){
        cout<<"交易密码错误"<<endl;
        return;
    }
    if(selling_book.getStatus()==bookStatus::selling){
        originData::totalBook[selling_book.getBookName()]=selling_book;
        originData::totalBook[selling_book.getBookName()].setBuyer(this->account);
        originData::totalBook[selling_book.getBookName()].setStatus(bookStatus::transacting);
        totalBuy.push_back(&(originData::totalBook[selling_book.getBookName()]));
    }else{
        cout<<"无效"<<endl;
    }
}

void simplePerson::viewBuyingBook() {
    if(totalBuy.empty()){
        cout<<"无记录"<<endl;
    }else{
        for(auto iter=totalBuy.begin();iter!=totalBuy.end();iter++){
            cout<<"书名"<<(*iter)->getBookName()<<endl;
            cout<<"状态"<<(*iter)->getStatus()<<endl<<endl;
        }
    }
}

void simplePerson::verify(const string &name) {
    if(originData::totalBook[name].getStatus()==bookStatus::transacting){
        originData::totalBook[name].setStatus(bookStatus::complete);
    }else{
        cout<<"无效";
    }
}

bool admin::isAdmin() const {
    return true;
}

personBase::personBase()=default;

personBase::personBase(const string &a, const string &p) {
    account=a;
    password=p;
}

string personBase::get_account() const {
    return account;
}

string personBase::get_password() const {
    return password;
}

namespace originData{
    map<string,book>totalBook;
    map<string,simplePerson>totalPerson;
    const string admin_id="root";
    const string admin_password="goodeveryday";
    string announcement;
}
namespace bookStatus{
    const string selling="selling";
    const string transacting="transacting";
    const string complete="complete";
}