/*************************************************************************
	> File Name: Tetris.h
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Sun 10 Jul 2016 07:33:25 PM PDT
 ************************************************************************/
#ifndef TETRIS_H
#define TETRIS_H
#include"Common.h"

class Block{
private:
	int PosX;
	int PosY;
public:
	Block();
	virtual ~Block();
	void Draw()const;
	bool canRotate(const int figure_x,const int figure_y)const;
	bool Rotate(const int figure_x,const int figure_y);
	bool Translate(const int setoff_x,const int setoff_y);
	bool canTranslate(const int setoff_x,const int setoff_y)const;
	inline int getPosX()const{return PosX;}
	inline int getPosY()const{return PosY;}
	inline void setPosX(int x){PosX=x;}
	inline void setPosY(int y){PosY=y;}
	Block& operator=(const Block& other){
		if(&other!=this){
			PosX=other.PosX;
			PosY=other.PosY;
		}
		return *this;
	}
};

class Figure{
private:
	int PosX,PosY;
	bool canRotate;
public:
	Block data[NUM_FIGURE_BLOCK];
public:
	Figure();
	Figure(int numfigure);
	~Figure();
	void New(int numfigure);
	void Draw()const;
	bool Rotate();
	bool Translate(const int setoff_x,const int setoff_y);
	inline int getPosX()const{return PosX;}
	inline int getPosY()const{return PosY;}
	inline void setPosX(int x){PosX=x;}
	inline void setPosY(int y){PosY=y;}
};

class Game{
private:
	int num_row,num_col;
	int map[MAX_BLOCK_NUM][MAX_BLOCK_NUM];
	bool status;
public:
	Game();
	virtual ~Game();
	void Draw()const;
	void New();
	void update(const Figure& figure);
	bool RowisFull(const int row)const;
	bool deleteRow(const int row);
	int getmap(const int row,const int col)const;
	bool getstatus()const{return status;}
	void setstatus(const bool newstatus){status=newstatus;}
};

#endif
