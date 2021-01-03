#ifndef C__GAME_REVISE_MAP_H
#define C__GAME_REVISE_MAP_H
#include"chess.h"
#include<stack>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
namespace input {
    pair<int, int> enter();
    vector<string>split(const string&);
}
class Map {
public:
    Map();

    //显示当前战局
    void print();

    //下棋
    int operator+=(Chess);

    //悔棋
    bool regret();

private:
    //地图来保存棋子信息
    Chess map[25][30]{};
    //一个堆用来保存之前下的棋子
    stack<Chess> record;
    //判断是否获胜
    bool judge(Chess temp);
};
#endif //C__GAME_REVISE_MAP_H
