/*************************************************************************
	> File Name: Game.cpp
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Mon 11 Jul 2016 01:32:21 AM PDT
 ************************************************************************/

#include"Common.h"
#include"Tetris.h"
#include<stdio.h>
#include<string.h>

extern Figure FigureGame;

void Game::New(){
	for(int i=0;i<num_row;i++){
		for(int j=0;j<num_col;j++){
			map[i][j]=EMPTY;
		}
	}
	FigureGame.New(rand()%NUM_FIGURE);
	status=true;
}

Game::Game(){
	num_col=WINDOW_WIDTH/(BLOCK_SIZE+BLOCK_SPACING);
	num_row=WINDOW_LEIGHT/(BLOCK_SIZE+BLOCK_SPACING);
	status=true;
}

Game::~Game(){}

void Game::Draw()const{
	glBegin(GL_LINE_LOOP);
	glColor3f(0.5,0.2,0.1);
	glVertex3f(0,0,0);
	glVertex3f(WINDOW_WIDTH-BLOCK_SIZE/2,0,0);
	glVertex3f(WINDOW_WIDTH-BLOCK_SIZE/2,WINDOW_LEIGHT,0);
	glVertex3f(0,WINDOW_LEIGHT,0);
	glEnd();
	if(status){
		Block block=Block();
		for(int i=0;i<num_row;i++){
			for(int j=0;j<num_col;j++){
				if(map[i][j]){
					block.setPosX(j);
					block.setPosY(i);
					block.Draw();
				}
			}
		}
	}
	else{
		char str[]="GAME OVER";
		int len;
		glRasterPos2f(WINDOW_WIDTH/2,WINDOW_LEIGHT/2);
		len=(int)strlen(str);
		for(int i=0;i<len;i++){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
		}
	}
}

void Game::update(const Figure& figure){
	for(int i=0;i<NUM_FIGURE_BLOCK;i++){
		map[figure.data[i].getPosY()][figure.data[i].getPosX()]=USED;
	}
	int num=figure.getPosY();
	for(int i=num+2;i>=num-2;--i){
		if(RowisFull(i)){
			deleteRow(i);
		}
	}
}

bool Game::RowisFull(const int row)const{
	if(row<0||row>=num_row){
		return false;
	}
	for(int i=0;i<num_col;i++){
		if(map[row][i]==EMPTY){
			return false;
		}
	}
	return true;
}

bool Game::deleteRow(const int row){
	if(row<0||row>=num_row){
		return false;
	}
	for(int i=row;i<num_row-2;i++){
		for(int j=0;j<num_col;j++){
			map[i][j]=map[i+1][j];
		}
	}
	for(int i=0;i<num_col;i++){
		map[num_row-1][i]=0;
	}
}

int Game::getmap(const int x,const int y)const{
	if(x<0||x>=num_col||y<0||y>=num_row){
		return -1;
	}
	return map[y][x];
}
