#include <stdio.h>
#include <string>


int main(int argc, char * argv[]){
	int i = 1;
	//printf("%sthis is normal\n",i);
	printf("%*sand this is not\n",i*5,"");

	return 0;
}
