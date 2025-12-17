#pragma once
#include <Windows.h>
#include <iostream>
class buffer {
private:
    char buf[9][25];
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPos = { 0, 0 };
public:
    void bufferr();
    void drawonbuf(int x, int y, char symbol);
    void onscreen();
};