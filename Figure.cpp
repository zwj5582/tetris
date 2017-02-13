/*************************************************************************
	> File Name: Figure.cpp
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Mon 11 Jul 2016 12:24:44 AM PDT
 ************************************************************************/

#include"Common.h"
#include<stdio.h>
#include"Tetris.h"
#include<time.h>

extern Game TetrisGame;

Figure::Figure(){
	int numfigure=rand()%NUM_FIGURE;
	New(numfigure);
}

Figure::Figure(int numfigure){
	New(numfigure);
}

void Figure::New(const int numfigure){
	if(numfigure>=0&&numfigure<NUM_FIGURE){
		canRotate=(numfigure!=0);
		PosX=NUM_BLOCK_X/2;
		PosY=NUM_BLOCK_Y - 2;
		if(TetrisGame.getmap(PosX,PosY+1)==1&&TetrisGame.getstatus()){
			TetrisGame.setstatus(false);
			return;
		}
		for(int i=0;i<NUM_FIGURE_BLOCK;i++){
			data[i].setPosX(PosX+image[numfigure][i][0]);
			data[i].setPosY(PosY+image[numfigure][i][1]);
		}
	}
}

Figure::~Figure(){}

void Figure::Draw()const{
	for(int i=0;i<NUM_FIGURE_BLOCK;i++){
		data[i].Draw();
	}
}

bool Figure::Rotate(){
	if(!canRotate){
		return false;
	}
	for(int i=0;i<NUM_FIGURE_BLOCK;i++){
		if(!data[i].canRotate(PosX,PosY)){
			return false;
		}
	}
	for(int i=0;i<NUM_FIGURE_BLOCK;i++){
		data[i].Rotate(PosX,PosY);
	}
	return true;
}

bool Figure::Translate(const int offset_x,const int offset_y){
	for(int i=0;i<NUM_FIGURE_BLOCK;i++){
		if(!data[i].canTranslate(offset_x,offset_y)){
			return false;
		}
	}
	for(int i=0;i<NUM_FIGURE_BLOCK;i++){
		data[i].Translate(offset_x,offset_y);
	}
	setPosX(PosX+offset_x);
	setPosY(PosY+offset_y);
	return true;
}
