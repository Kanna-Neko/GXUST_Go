#ifndef C__GAME_REVISE_GAMESTART_H
#define C__GAME_REVISE_GAMESTART_H
#include<iostream>
#include<string>
#include"map.h"
#include"chess.h"

using namespace std;
using input::enter;
namespace gameStart {
    void gameStart();
}
namespace storeData {
    extern string input_id1;
    extern string input_password1;
    extern string input_id2;
    extern string input_password2;
}
#endif //C__GAME_REVISE_GAMESTART_H
