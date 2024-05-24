#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//玩家赢返回*
//电脑赢返回#
//平局返回Q
//继续游戏返回C
char IsWin(char board[ROW][COL],int row,int col);