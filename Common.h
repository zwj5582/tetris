/*************************************************************************
	> File Name: Common.h
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Sun 10 Jul 2016 06:39:14 PM PDT
 ************************************************************************/

#ifndef COMMON_H
#define COMMON_H

#include<GL/glut.h>

#define NUM_FIGURE 7

#define NUM_FIGURE_BLOCK 4

#define BLOCK_SIZE 19

#define BLOCK_SPACING 1

#define MAX_BLOCK_NUM 100

#define WINDOW_WIDTH 350

#define WINDOW_LEIGHT 500

#define NUM_BLOCK_X WINDOW_WIDTH/(BLOCK_SIZE+BLOCK_SPACING)

#define NUM_BLOCK_Y WINDOW_LEIGHT/(BLOCK_SIZE+BLOCK_SPACING)

#define USED 1

#define EMPTY 0

#define RUNNING 1

#define LOST 0

const int image[NUM_FIGURE][NUM_FIGURE_BLOCK][2]={
	{
		//正方形
		{0,0},
		{0,1},
		{1,1},
		{1,0}
	},
	{
		//J形
		{0,1},
		{-1,1},
		{-1,0},
		{-1,-1}
	},
	{
		//L形
		{0,1},
		{1,1},
		{1,0},
		{1,-1}
	},
	{
		//I形
		{0,-1},
		{0,0},
		{0,1},
		{0,2},
	},
	{
		//S形
		{-1,1},
		{-1,0},
		{0,0},
		{0,-1}
	},
	{
		//Z形
		{0,1},
		{0,0},
		{-1,0},
		{-1,-1}
	},
	{
		//T形
		{-1,0},
		{0,0},
		{1,0},
		{0,1}
	}
};

#endif
