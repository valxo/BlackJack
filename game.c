#include <stdio.h>

int main(void){
	char a;
	
	printf("Новая игра (N). Выход(Q).\n");
	scanf("%c", &a);
	switch(a)
	{	
		case 'N':
			break;
		case 'Q':
			return 0;
	}
	return 0;
}
