#include "buffferr.h"
#include "game.h"
#include "snake.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>


void game::startGame() {
    snakecl snake;
    buffer buf;
    bool flag = false;
    snake.fruitfunc();
    double frametame = 0.0f;
    while (!flag) {
        bool flag2 = true;
        clock_t start = clock();
        buf.bufferr();
        snake.snakewall(&flag);
        if (flag) {
            snake.gameover(&flag);
            break;
        }
            for (int i = 0; i < snake.getxvostlen(); ++i) {
                buf.drawonbuf(snake.getxvostx(i), snake.getxvosty(i), 'o');
            }
        buf.drawonbuf(snake.GetsnakeX(),snake.GetsnakeY(), '0');
        for (int v = 0; v < snake.getvxvostlen(); ++v) {
            buf.drawonbuf(snake.getvxvostx(v), snake.getvxvosty(v), 'v');
        }
        buf.drawonbuf(snake.vsnakx(), snake.vsnaky(), 'V');
        snake.snakewasd();
        buf.drawonbuf(snake.Getfruitx(), snake.Getfruity(), 'F');
        snake.stolk();
        std::cout << snake.GetsnakeSchet();
        std::cout << snake.GetsnakeScore();
        std::cout << "\n";
        std::cout << "Your record is: " << snake.savescore(flag2);
        std::cout << "\n";
        std::cout << snake.Getsnakevschet();
        std::cout << snake.getvsnakeScore();
        //std::cout << snake.GetcontrolFps();
        flag2 = false;
        //snake.GetfruitXY();
        snake.exitgame(&flag);
        buf.onscreen();
        clock_t end = clock();
        frametame += (double)(end - start) / CLOCKS_PER_SEC;
        if (frametame >= snake.GetcontrolFps()){
            snake.snakelogic();
            snake.xvostupdate(snake.Getoldsx(), snake.Getoldsy());
            snake.simplebot();
            snake.vxvostupdate(snake.vgetoldsnakx(),snake.vgetoldsnaky());
            frametame = 0.0f;
        }
    }  
}