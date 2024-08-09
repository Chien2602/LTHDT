#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <windows.h>

#define KEY_NONE -1

int whereX();
int whereY();
void gotoXY(int x, int y);
void SetColor(WORD color);
void ShowCur(bool CursorVisibility);
int inputKey();

#endif // MYLIB_H
