#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    game gameInstance;
    gameInstance.startGame();
    return 0;
}