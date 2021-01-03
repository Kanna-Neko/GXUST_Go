#include"chess.h"
//初始化坐标和颜色
Chess::Chess(int x_, int y_, char temp) : x(x_ + 5), y(y_ + 5), color(temp) {}

//默认构造函数，随手写的，并没有用到
Chess::Chess() = default;