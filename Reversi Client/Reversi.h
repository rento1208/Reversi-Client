#pragma once
#include <DxLib.h>

class Reversi
{
public:
	Reversi();
	~Reversi();
	void Draw();
	bool CanPut(int x, int y);
	void Put(int x, int y, int color);
	

private:
	int board[8][8]; //盤面の状態を表す2次元配列。0は空、1は黒、2は白
	int cellSize; //1マスの大きさ
	int OffsetX;   //盤面の左上のX座標
	int OffsetY;   //盤面の左上のY座標
	int currentTurn;   // 1 = 黒, 2 = 白
	int myColor;       // 自分の色
};