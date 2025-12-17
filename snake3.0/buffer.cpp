#include "buffferr.h"
    void buffer::bufferr() {
        for (int i = 0; i < 24; ++i) {
            for (int j = 0; j < 9; ++j) {
                buf[j][i] = '.';
            }
        }
    }
    void buffer::drawonbuf(int x, int y, char symbol) {
        if (x >= -1 && x < 24 && y >= -1 && y < 9) {
            buf[y][x] = symbol;
        }
    }
    void buffer::onscreen() {
        CONSOLE_CURSOR_INFO visioncur;
        visioncur.bVisible = FALSE;
        visioncur.dwSize = 1;
        SetConsoleCursorInfo(hConsole, &visioncur);
        SetConsoleCursorPosition(hConsole, cursorPos);
        for (int i = 0; i < 9; ++i) {
            buf[i][24] = '\0';
            std::cout << buf[i] << "\n";

        }
    }