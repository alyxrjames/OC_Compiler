#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc,char* argv[]){

	string command = "/usr/bin/cpp test.cpp";

	char buffer[1024];
	FILE* foo = popen(command.c_str(),"r");

	while(fgets(buffer,sizeof(buffer),foo)!=NULL){

		printf("\n%s",buffer);
	}





	return 0;
}
