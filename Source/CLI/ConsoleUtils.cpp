#include "ConsoleUtils.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
//#include <ncurses.h>
#endif
#include <stdio.h>

namespace ConsoleUtils {

void InitScreen() {
    //initscr();
}

void Clear() {
#ifdef _WIN32
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD coord = {0, 0};
      DWORD count;
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      GetConsoleScreenBufferInfo(hStdOut, &csbi);
      FillConsoleOutputCharacter(hStdOut, ' ',
                                 csbi.dwSize.X * csbi.dwSize.Y,
                                 coord, &count);
      SetConsoleCursorPosition(hStdOut, coord);
#else
    write(1,"\E[H\E[2J",7);
#endif
}

void SetCursorPos(int x, int y) {
#ifdef _WIN32
    COORD Coord;

    Coord.X = x;
    Coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
#else
     printf("%c[%d;%df",0x1B,y,x);
    //printf("\033[%d;%dH", x+1, y+1);
    fflush(stdout);
    //move(x,y);
    //refresh();
#endif
}

}


