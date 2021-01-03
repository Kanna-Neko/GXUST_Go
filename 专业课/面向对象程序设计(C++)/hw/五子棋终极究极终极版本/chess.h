#ifndef C__GAME_REVISE_CHESS_H
#define C__GAME_REVISE_CHESS_H
//储存单个棋子数据
class Chess {
    friend class Map;

public:
    Chess();
    //棋子的构造函数
    Chess(int x_, int y_, char temp);

private:
    char color{};
    int x{}, y{};
};
#endif //C__GAME_REVISE_CHESS_H
