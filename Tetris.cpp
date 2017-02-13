/*************************************************************************
	> File Name: Tetris.cpp
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Mon 11 Jul 2016 04:41:00 AM PDT
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<fstream>
#include"Tetris.h"
#include"Common.h"
#include<GL/glut.h>
using namespace std;

Game TetrisGame;
Figure FigureGame(rand()%NUM_FIGURE);

void HandleKeyPress(unsigned char key, int x, int y);

void Display(void);

void Update(int value);

void HandleKeyPress(unsigned char key, int x, int y){
	if(TetrisGame.getstatus()){
		switch(key){
			case 'a':
				FigureGame.Translate(-1,0);				
                glutPostRedisplay();
				break;
			case 's':
				FigureGame.Translate(0,-1);
                glutPostRedisplay();
				break;
			case 'd':
				FigureGame.Translate(1,0);
                glutPostRedisplay();
				break;
			case 'w':
				FigureGame.Rotate();
                glutPostRedisplay();
				break;
			default:
				break;
		}
	}
	else{
		switch(key){
			case 'n':
				TetrisGame.New();
                glutPostRedisplay();
				break;
			default:
				break;
		}
	}
}

void Display(void){
	glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
	if(TetrisGame.getstatus()){
		FigureGame.Draw();		
	}
	TetrisGame.Draw();
    glutSwapBuffers();
}

void Update(int value){
	if(TetrisGame.getstatus()){
		int move=FigureGame.Translate(0,-1);
		if(!move){
			TetrisGame.update(FigureGame);
			FigureGame.New(rand()%NUM_FIGURE);
		}
	}
    glutPostRedisplay();
    glutTimerFunc(500, Update, 0);
}

int main(int argc, char **argv) {
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( WINDOW_WIDTH+30, WINDOW_LEIGHT+30);
    glutInitWindowPosition( 50, 50 );
    glutCreateWindow( "Tetris's Game" );
    glClearColor( 0.0, 0.0, 0.0, 0.0 ) ;
    glMatrixMode(GL_MODELVIEW) ;  
    glLoadIdentity(); 
    gluOrtho2D(-50, (GLdouble)WINDOW_WIDTH+50, -50, (GLdouble)WINDOW_LEIGHT+50 );
    srand(time(NULL));
    glutDisplayFunc(Display);
    glutKeyboardFunc(HandleKeyPress);
    glutTimerFunc(500,Update,0);
    glutMainLoop();
}
