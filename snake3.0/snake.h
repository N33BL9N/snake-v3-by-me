#pragma once
#include <string>

class snakecl {
private:
    double snakex = 12.0f;
    double snakey = 4.0f;
    int dir = 4;  // STOP
    int fruitx;
    int fruity;
    int score = 0;
    int vscore = 0;
    std::string schet = "score:";
    int stopgame = 0;
    char snake = '0';
    int xvostx[33],xvosty[33];
    int vxvostx[33],vxvosty[33];
    int xvostlen = 0;
    int vxvostlen = 0;
    int speedd = 125;
    int record;
    int oldx = 0;
    int oldy = 0;
    int oldvx = 0;
    int oldvy = 0;
    double vsnakex = 10.0f;
    double vsnakey = 2.0f;
    double controlfps;

public:
    snakecl();
    void xvostgrow();
    void vxvostgrow();
    void xvostupdate(int oldsnakex, int oldsnakey);
    void vxvostupdate(int voldsnakex, int voldsnakey);
    int getvxvostx(int i);
    int getvxvosty(int i);
    int getvxvostlen();
    int getxvostx(int i);
    int getxvosty(int i);
    int getxvostlen();
    void snakelogic();
    void snakewasd();
    void simplebot();
    void gameover(bool* flag);
    void snakewall(bool* flag);
    void fruitfunc();
    void speed();
    void stolk();
    int savescore(bool flag);
    void exitgame(bool* flag);

    // Геттеры
    int GetsnakeX() const;
    int GetsnakeY() const;
    int GetsnakeScore() const;
    int Getfruitx() const;
    int Getfruity() const;
    int Getoldsx() const;
    int Getoldsy() const;
    int getvsnakeScore() const;
    int vsnaky();
    int vsnakx();
    int vgetoldsnakx();
    int vgetoldsnaky();
    std::string GetsnakeSchet() const;
    std::string Getsnakevschet() const;
    double GetcontrolFps();
};
