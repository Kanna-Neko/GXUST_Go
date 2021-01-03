#include"map.h"
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<map>
using namespace std;

Map::Map() = default;
//切割字符串的函数
vector<string>input::split(const string& temp) {
    string::size_type pos1,pos2;
    vector<string>ans;
    pos2 = temp.find(' ');
    pos1 = 0;
    while(string::npos != pos2)
    {
        ans.push_back(temp.substr(pos1, pos2-pos1));

        pos1 = pos2 + 1;
        pos2 = temp.find(' ', pos1);
    }
    if(pos1 != temp.size())
        ans.push_back(temp.substr(pos1));
    return ans;
}
pair<int, int> input::enter() {
    string temp;
    getline(cin,temp);
    string y_string,x_string;
    vector<string>splitstring=split(temp);
    if(splitstring.size()!=2){
        return pair<int,int>(-1,-1);
    }else{
        y_string=splitstring[0];
        x_string=splitstring[1];
    }
    bool key{};
    for (auto iter = y_string.begin(); iter != y_string.end(); iter++) {
        if (!(*iter <= '9' && *iter >= '0')) {
            key = true;
        }
    }
    if (key) {
        return pair<int, int>(-1, -1);
    }
    int y = strtol(y_string.c_str(), nullptr, 10);
    for (auto iter = x_string.begin(); iter != x_string.end(); iter++) {
        if (!(*iter <= '9' && *iter >= '0')) {
            key = true;
        }
    }
    if (key) {
        return pair<int, int>(-1, -1);
    }
    int x = strtol(x_string.c_str(), nullptr, 10);
    return pair<int, int>{x,y};
}

//x,y不得大于15，20
//此函数是下棋的作用，传递棋子的信息
int Map::operator+=(Chess temp) {
    if (temp.x >= 20 || temp.y >= 25 || temp.x <= 4 || temp.y <= 4) {
        return 0;
    }
    if (this->map[temp.x][temp.y].color == '\0') {
        this->map[temp.x][temp.y] = temp;
        if (judge(temp)) {
            cout << "congratulate!" << endl;
            return 2;
        }
        //将棋子的信息丢入栈中
        record.push(temp);
        return 1;
    } else {
        return 0;
    }
}

//打印棋盘状态
void Map::print() {
    cout << "  _________________________________________" << endl;
    for (int i = 19; i >= 5; i--) {
        printf("%02d", i - 5);
        cout << '|';
        for (int j = 5; j < 25; j++) {
            if (map[i][j].color == '\0') {
                cout << '_';
            }
            else {
                cout << map[i][j].color;
            }
            cout << '|';
        }
        cout << endl;
    }
    cout << "   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9\n";
}

//悔棋，从堆中将上个棋子的位置提取出来
bool Map::regret() {
    if (!this->record.empty()) {
        Chess x = this->record.top();
        this->map[x.x][x.y] = Chess();
        this->record.pop();
        return true;
    } else {
        cout << "sorry,You haven't played chess" << endl;
        return false;
    }
}

bool Map::judge(Chess temp) {
    int left = 0, right = 0, up = 0, down = 0, left_up = 0, right_up = 0, left_down = 0, right_down = 0;
    for (int i = 0; i < 5; i++) {
        if (this->map[temp.x - i][temp.y].color == temp.color) {
            left++;
        }
        else {
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (this->map[temp.x + i][temp.y].color == temp.color) {
            right++;
        }
        else {
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (this->map[temp.x][temp.y - i].color == temp.color) {
            up++;
        }
        else {
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (this->map[temp.x][temp.y + i].color == temp.color) {
            down++;
        } else {
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (this->map[temp.x + i][temp.y + i].color == temp.color) {
            right_down++;
        } else {
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (this->map[temp.x - i][temp.y - i].color == temp.color) {
            left_up++;
        } else {
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (this->map[temp.x - i][temp.y + i].color == temp.color) {
            right_up++;
        } else {
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (this->map[temp.x + i][temp.y - i].color == temp.color) {
            left_down++;
        } else {
            break;
        }
    }
    return up + down >= 6 || right + left >= 6 || right_up + left_down >= 6 || right_down + left_up >= 6;
}

