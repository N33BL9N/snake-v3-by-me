
#include "snake.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
snakecl::snakecl() {
    controlfps = 0.2;
}
void snakecl::xvostgrow() {
    if (xvostlen < 33) {
        xvostlen++;
    }
    }
void snakecl::vxvostgrow() {
    if (vxvostlen < 33) {
        vxvostlen++;
    }
}
void snakecl::vxvostupdate(int voldsnakex, int voldsnakey) {
    for (int i = vxvostlen - 1; i > 0; --i) {
        vxvostx[i] = vxvostx[i - 1];
        vxvosty[i] = vxvosty[i - 1];
    }
    if (vxvostlen > 0) {
        vxvostx[0] = voldsnakex;
        vxvosty[0] = voldsnakey;
    }
}
int snakecl::getvxvostx(int i) {
    return vxvostx[i];
}
int snakecl::getvxvosty(int i) {
    return vxvosty[i];
}
int snakecl::getvxvostlen() {
    return vxvostlen;
}
void snakecl::xvostupdate(int oldsnakex, int oldsnakey) {
    for (int i = xvostlen - 1; i > 0; --i) {
        xvostx[i] = xvostx[i - 1];
        xvosty[i] = xvosty[i - 1];
    }
    if (xvostlen > 0) {
        xvostx[0] = oldsnakex;
        xvosty[0] = oldsnakey;
    }   
}
int snakecl::getxvostx(int i) {
       return xvostx[i];
      
}
int snakecl::getxvosty(int i) {
       return xvosty[i]; 
}
int snakecl::getxvostlen() {
    return xvostlen;
}
void snakecl::snakelogic() {
    oldx = snakex;
    oldy = snakey;
    oldvx = vsnakex;
    oldvy = vsnakey;
    if (dir == 0) {  // UP
        snakey--;
    }
    if (dir == 1) {  // DOWN
        snakey++;
    }
    if (dir == 2) {  // RIGHT
        snakex++;
    }
    if (dir == 3) {  // LEFT
        snakex--;
    }

}

void snakecl::snakewasd() {
    if (_kbhit()) {
        char tempkey = _getch();
        if (tempkey == 'w' || tempkey == 'W') {
            dir = 0;  // UP
        }
        if (tempkey == 'a' || tempkey == 'A') {
            dir = 3;  // LEFT
        }
        if (tempkey == 's' || tempkey == 'S') {
            dir = 1;  // DOWN
        }
        if (tempkey == 'D' || tempkey == 'd') {
            dir = 2;  // RIGHT
        }
        if (tempkey == 'X' || tempkey == 'x') {
            stopgame = 1;
        }
    }
}
void snakecl::simplebot() {
    if (vsnakey > fruity) {
        vsnakey -= 0.5f;
    }
    if (vsnakey < fruity) {
        vsnakey += 0.5f;
    }
    if (vsnakex < fruitx) {
        vsnakex += 0.5f;
    }
    if (vsnakex > fruitx) {
        vsnakex -= 0.5f;
    }
    if (vsnakex == snakex - 0.5 && vsnakey == snakey - 0.5) {
        vsnakex++;
        vsnakey++;
    }
}
void snakecl::gameover(bool* flag) {
    char b;
    *flag = true;
    system("cls");
    std::cout << "\033[" << 5 << ";" << 30 << "H";
    std::cout << "\u001b[31m" << "GAME OVER!!!\n\n";
    std::cout << "\033[" << 6 << ";" << 30 << "H";
    std::cout << "Your score is: " << score;
    std::cout << "\033[" << 7 << ";" << 30 << "H";
    std::cout << "Your record is: " << savescore(flag);
    std::cout << "\033[" << 8 << ";" << 30 << "H";
    std::cout << "write your last words: ";
    std::cin >> b;
}
void snakecl::snakewall(bool* flag) {
    if (snakex == 24|| snakex == -1) {
        gameover(flag);
    }
    if (snakey == 9 || snakey == -1) {
        gameover(flag);
    }
    for (int i = 1; i < xvostlen; ++i) {
        if (snakex == xvostx[i] && snakey == xvosty[i]) {
            gameover(flag);
        }
    }
    for (int i = 1; i < vxvostlen; ++i) {
        if (snakex == vxvostx[i] && snakey == vxvosty[i]) {
            gameover(flag);
        }
    }
    if (score == -10) {
        gameover(flag);
    }
    if (vscore == -10) {
        gameover(flag);
    }
    if (vsnakex == snakex&& vsnakey == snakey) {
        gameover(flag);
    }
}

void snakecl::fruitfunc() {
    fruitx = rand() % 24;  
    fruity = rand() % 9;   
}

void snakecl::speed() {
    controlfps -= 0.0020f;
}
void snakecl::stolk() {
    if (snakex == fruitx && snakey == fruity) {
        fruitfunc();
        score++;
        vscore--;
        xvostgrow();
        speed();
    }
    if (vsnakex == fruitx && vsnakey == fruity) {
        fruitfunc();
        vscore++;
        score--;
        vxvostgrow();
        speed();
    }
}
int snakecl::savescore(bool flag) {
    if(flag == true){
    int record2 = 0;
    if (record < score) record = score;
    std::ifstream infile("score.txt");
    if (infile.is_open()) {
        infile >> record2;
        infile.close();
        if(record2 < record){
            std::ofstream outfile("score.txt");
            if (outfile.is_open()) {
            outfile << record;
            outfile.close();
            return record;
            }
        }
    }
    return record2;
    }
}
void snakecl::exitgame(bool* flag) {
    if (stopgame == 1) {
        *flag = true;
    }
}

int snakecl::GetsnakeX() const {
    return snakex;
}

int snakecl::GetsnakeY() const {
    return snakey;
}

int snakecl::GetsnakeScore() const {
    return score;
}
int snakecl::Getfruitx() const {
    return fruitx;
}
int snakecl::Getfruity() const {
    return fruity;
}
int snakecl::Getoldsx() const {
    return oldx;
}
int snakecl::Getoldsy() const {
    return oldy;
}
int snakecl::getvsnakeScore() const {
    return vscore;
}
int snakecl::vsnaky(){
    return vsnakey;
}
int snakecl::vsnakx() {
    return vsnakex;
}
int snakecl::vgetoldsnakx() {
    return oldvx;
}
int snakecl::vgetoldsnaky() {
    return oldvy;
}
std::string snakecl::GetsnakeSchet() const {
    return schet;
}
std::string snakecl::Getsnakevschet() const{
    return "bad snake score: ";
}
double snakecl::GetcontrolFps() {
    return controlfps;
}