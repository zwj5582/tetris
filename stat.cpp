/*************************************************************************
	> File Name: stat.cpp
	> Author: zhongwenjie
	> Mail: zwj5582@gmail.com 
	> Created Time: Wed 13 Jul 2016 09:16:30 PM PDT
 ************************************************************************/

#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;

#define OPEN_FILE "/home/zhongwenjie/code/lab2/Game.cpp"

int main(){
	struct stat file;
	int fd;
	if((fd=stat(OPEN_FILE,&file))==0){
		cout<<"节点号："<<file.st_ino<<endl;
		cout<<"权限："<<file.st_mode<<endl;
		cout<<"属主属组："<<file.st_uid<<":"<<file.st_gid<<endl;
	}
	else{
		cout<<"error"<<endl;
	}
	return 0;
}
