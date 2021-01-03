#include "dataOperate.h"
#include<algorithm>
#include"variable.h"
void dataOperate::addPerson(PersonData temp) {//添加一个人的数据
    originAndStore::totalPerson.push_back(temp);
}

void dataOperate::deletePerson(string id) {//根据名字删除一个人
    int index=dataFind::dataFindPerson(id);
    originAndStore::totalPerson.erase(originAndStore::totalPerson.begin()+index);
}

void dataOperate::revisePersonWins(string id, int newWins) { //根据名字修改一个人的胜利次数
    int index=dataFind::dataFindPerson(id);
    originAndStore::totalPerson[index].setNewWins(newWins);
}

void dataOperate::revisePersonTotals(string id, int newTotalGame) { //根据名字修改一个人的总游戏数
    int index=dataFind::dataFindPerson(id);
    originAndStore::totalPerson[index].setNewTotalGame(newTotalGame);
}

void dataOperate::revisePersonPassword(string id, string newPassword) {//根据名字修改一个人的密码，需要做到输入的2个密码保持一致，否则重新输入新密码
    int index=dataFind::dataFindPerson(id);
    originAndStore::totalPerson[index].setPassword(newPassword);
}

void dataOperate::setAnnouncement(string newAnnouncement) {//设置公告
    originAndStore::announcement=newAnnouncement;
}

vector<PersonData>::size_type dataFind::dataFindPerson(string name) {//查找用户是否存在,存在则返回用户下标
    for(int i=0;i<originAndStore::totalPerson.size();i++){
        if(originAndStore::totalPerson[i].getId()==name){
            return i;
        }
    }
    return -1;
}

vector<PersonData> dataFind::dataFindListHigher(int n) {//返回前n个人的数组
    vector<PersonData>temp(originAndStore::totalPerson);
    sort(temp.begin(),temp.end());
    vector<PersonData>ans(temp.begin(),temp.begin()+n);
    return ans;
}

bool dataVerify::verifyPassword(string inputId, string inputPassword) {//检验账号和密码是否同时正确
    if(inputId==originAndStore::AdminId&&inputPassword==originAndStore::AdminPassword){
        return true;
    }
    int index=dataFind::dataFindPerson(inputId);
    if(index==-1){
        return false;
    }
    else{
        string password=originAndStore::totalPerson[index].getPassword();
        return inputPassword==password;
    }
}

bool dataVerify::verifyIsAdmin(string Id) {//检验是否是管理员
    if(Id=="root"){
        return true;
    }else{
        return false;
    }
}

bool dataVerify::verifyIdFormat(string Id){//检验ID格式是否正确
        int i;
        int flag;
        flag=1;
        if(Id.size()>6) {
            cout << "用户名格式错误，请重新输入";
            flag==0;
        }
        else {
            for (i = 0; i < 6; ++i) {
                if (Id[i] >= 'a' && Id[i] <= 'z' || Id[i] >= 'A' && Id[i] <= 'Z') {
                } else {
                    cout << "用户名输入格式错误,请重新输入";
                    break;
                }
            }
        }

        if(i==6&&flag==1)
           return true;
        else
            return false;
}
bool dataVerify::verifyPasswordFormat(string password) {//检验密码格式是否正确
    int i;
    int flag;
    flag=1;
    if(password.size()>6){
        cout<<"密码输入格式错误，请重新输入";
        flag=0;
    }
    for( i=0;i<6;++i) {
        if (password[i] < '0' || password[i] > '9' ) {
            cout << "密码输入格式错误,请重新输入";
            break;
        }
    }

    if(i==6&&flag==1)
        return true;
    else
        return false;
}