#include "dataBase.h"
#include<fstream>
#include"variable.h"
#include<iostream>
#include "dataOperate.h"
using namespace std;

baseData::baseData() {
id="";
password="";
}
baseData::baseData(string newId, string newPassword) {
    id=newId;
    password=newPassword;
}
string baseData::getId() {
    return id;
}
string baseData::getPassword() {
    return password;
}

void baseData::setId(string newId) {
    id=newId;
}

void baseData::setPassword(string newPassword) {
    password=newPassword;
}

bool PersonData::isAdmin() {
    return false;
}

PersonData::PersonData() {
    id="";
    password="";
    wins=0;
    totalGame=0;
    Proportion=0;//#
}

PersonData::PersonData(string newId, string newPassword) : baseData(newId, newPassword) {
    id=newId;
    password=newPassword;
    wins=0;
    totalGame=0;
    Proportion=0.0;//#
}

int PersonData::getWins() {
    return wins;
}

int PersonData::getTotalGame() {
    return totalGame;
}

double PersonData::getWinProportion() {
     Proportion=(double)wins/totalGame;//#
    return Proportion;
}

void PersonData::setNewWins(int newWins) {
    wins=newWins;
}

void PersonData::setNewTotalGame(int newTotalGame) {
    totalGame=newTotalGame;
}
void PersonData::setNewProportion(double newProportion) {
    Proportion=newProportion;
}
void PersonData::winGame() {//比赛获胜后修改相关数据
    wins++;
    totalGame++;
}

void PersonData::loseGame() {//比赛失败后修改相关数据
    totalGame++;
}

bool PersonData::operator <(const PersonData& x)const {
    return wins>x.wins;
}


bool admin::isAdmin() {
    return true;
}

void originAndStore::pullDataToVector() {    //提取文件数据
    ifstream datafile;
    datafile.open(originAndStore::inputFileName,ifstream ::in);

    if(!datafile.is_open()){
        cout<<"Open Error!"<<endl;
        exit(0);
    }
    else{
        datafile>>originAndStore::announcement;
        string i,pa;
        int wi,to;
        while(true){
            datafile >> i >> pa >> wi >> to ;
            if(datafile.eof()){
                break;
            }
            PersonData x(i,pa);
            x.setNewWins(wi);
            x.setNewTotalGame(to);
            dataOperate::addPerson(x);
        }
    }
    datafile.close();
}

void originAndStore::StoreDataToFile() {//存储文件数据
    ofstream datafile;
    datafile.open(originAndStore::inputFileName, ostream::out|ostream::trunc);
    if(!datafile.is_open()){
        cout<<"Open Error!"<<endl;
        exit(2);
    }
    else {
        datafile << originAndStore::announcement << endl;
        for (int i = 0; i < originAndStore::totalPerson.size(); i++) {
            datafile << originAndStore::totalPerson[i].getId() << ' ' << originAndStore::totalPerson[i].getPassword()
                     << ' '<< originAndStore::totalPerson[i].getWins() << ' ' << originAndStore::totalPerson[i].getTotalGame()
                     << "\r\n";
        }
    }
    datafile.close();
}
