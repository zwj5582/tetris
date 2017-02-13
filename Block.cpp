/*************************************************************************
	> File Name: Block.cpp
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Sun 10 Jul 2016 08:37:38 PM PDT
 ************************************************************************/

#include<stdio.h>
#include"Tetris.h"
#include"Common.h"

extern Game TetrisGame;

Block::Block(){
	PosX=NUM_BLOCK_X/2;
	PosY=NUM_BLOCK_Y-1;
}

Block::~Block(){}

void Block::Draw()const{
	int left=PosX*(BLOCK_SIZE+BLOCK_SPACING)-BLOCK_SPACING;
	int right=left+BLOCK_SIZE;
	int bottom=PosY*(BLOCK_SIZE+BLOCK_SPACING)-BLOCK_SPACING;
	int top=bottom+BLOCK_SIZE;
	glBegin(GL_QUADS);
    glColor3d(1,1,1);
    glVertex3f(left, top, 0);
    glVertex3f(right, top, 0);
    glVertex3f(right, bottom, 0);
    glVertex3f(left, bottom, 0);
    glEnd();
}

bool Block::canRotate(const int figure_x,const int figure_y)const{
	int offsetX=PosX-figure_x;
	int offsetY=PosY-figure_y;
	if(!offsetX&&!offsetY){
		return true;
	}
	int nextPosX=figure_x-offsetY;
	int nextPosY=figure_y+offsetX;
	if(TetrisGame.getmap(nextPosX,nextPosY)!=EMPTY){
		return false;
	}
	int tmpX[3],tmpY[3];
	tmpX[0]=figure_x+offsetX-offsetY;
	tmpY[0]=figure_y+offsetX+offsetY;
	if(abs(offsetX)>1||abs(offsetY)>1){
		tmpX[1]=(tmpX[0]+PosX)/2;
		tmpX[2]=(tmpX[0]+figure_x-offsetY)/2;
		tmpY[1]=(tmpY[0]+PosY)/2;
		tmpY[2]=(tmpY[0]+figure_y+offsetX)/2;
		if(TetrisGame.getmap(tmpX[1],tmpY[1])!=EMPTY||TetrisGame.getmap(tmpX[2],tmpY[2])!=EMPTY){
			return false;
		}
	}
	else if(abs(offsetX)==1&&abs(offsetY)==1){
		tmpX[1]=(tmpX[0]+PosX)/2;
		tmpY[1]=(tmpY[0]+PosY)/2;
		if(TetrisGame.getmap(tmpX[1],tmpY[1])!=EMPTY){
			return false;
		}
	}
	else if(TetrisGame.getmap(tmpX[0],tmpY[0])!=EMPTY){
		return false;
	}
	return true;
}

bool Block::Rotate(const int figure_x,const int figure_y){
	if(!canRotate(figure_x,figure_y)){
		return false;
	}
	int offsetX=PosX-figure_x;
	int offsetY=PosY-figure_y;
	int nextPosX=figure_x-offsetY;
	int nextPosY=figure_y+offsetX;
	setPosX(nextPosX);
	setPosY(nextPosY);
	return true;
}

bool Block::canTranslate(const int offset_x,const int offset_y)const{
	int newPosX=PosX+offset_x;
	int newPosY=PosY+offset_y;
	if(TetrisGame.getmap(newPosX,newPosY)!=EMPTY){
		return false;
	}
	return true;
}

bool Block::Translate(const int offset_x,const int offset_y){
	int nextPosX=PosX+offset_x,nextPosY=PosY+offset_y;
	if(!canTranslate(offset_x,offset_y)){
		return false;
	}
	setPosX(nextPosX);
	setPosY(nextPosY);
	return true;
}

