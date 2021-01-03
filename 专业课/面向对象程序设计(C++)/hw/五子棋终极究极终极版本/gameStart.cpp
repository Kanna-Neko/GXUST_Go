#include"gameStart.h"
#include "dataOperate.h"
#include"dataBase.h"
#include<iostream>
#include"variable.h"
namespace storeData{
    string input_id1;
    string input_password1;
    string input_id2;
    string input_password2;
}
void gameStart::gameStart() {
    cout << "悔棋请按99 99"<<endl
         <<"退出游戏请按100 100"<<endl;
    Map map;
    map.print();
    cin.ignore(100,'\n');
    for (int i = 0;; i++) {
        pair<int, int> key = enter();
        int x = key.first;
        int y = key.second;
        if (x == -1 && y == -1) {
            i++;
            cout << "invalid\n";
            continue;
        }
        if(x==100&&y==100){
            if(i%2==0){
                cout<<storeData::input_id1<<"用户退出了"<<endl
                    <<storeData::input_id2<<"获得胜利"<<endl;
                if (i % 2 == 1) {
                    cout << storeData::input_id1 << " is ";
                    int m = dataFind::dataFindPerson(storeData::input_id1);
                    originAndStore::totalPerson[m].winGame();
                    int n = dataFind::dataFindPerson((storeData::input_id2));
                    originAndStore::totalPerson[n].loseGame();
                    originAndStore::StoreDataToFile();
                }
                else {
                    cout << storeData::input_id2 << " is ";
                    int m = dataFind::dataFindPerson(storeData::input_id2);
                    originAndStore::totalPerson[m].winGame();
                    int n = dataFind::dataFindPerson((storeData::input_id1));
                    originAndStore::totalPerson[n].loseGame();
                    originAndStore::StoreDataToFile();
                }
                cout << "Winner" << endl;
                break;
            }
        }
        if (x == 99 && y == 99) {
            map.regret();
            map.print();
            i++;
            continue;
        }
        int judge;
        if (i % 2 == 0) {
            judge = map += (Chess(x, y, 'O'));
        } else {
            judge = map += (Chess(x, y, 'X'));
        }
        if (judge == 0) {
            i++;
            map.print();
            cout << "invalid" << endl;
            continue;
        }
        else if (judge == 2) {
            map.print();
            if (i % 2 == 0) {
                cout << storeData::input_id1 << " is ";
                int m = dataFind::dataFindPerson(storeData::input_id1);
                originAndStore::totalPerson[m].winGame();
                int n = dataFind::dataFindPerson((storeData::input_id2));
                originAndStore::totalPerson[n].loseGame();
                originAndStore::StoreDataToFile();
            }
            else {
                cout << storeData::input_id2 << " is ";
                int m = dataFind::dataFindPerson(storeData::input_id2);
                originAndStore::totalPerson[m].winGame();
                int n = dataFind::dataFindPerson((storeData::input_id1));
                originAndStore::totalPerson[n].loseGame();
                originAndStore::StoreDataToFile();
            }
            cout << "Winner" << endl;
            break;
        }
        map.print();
    }

}
