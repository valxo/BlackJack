#include <stdio.h>
#include <fcntl.h>

void game(void);
void nextCard(int, int *,int *);
void writing(char *, int, int);


char answer;



int main(void){
	printf("Новая игра (N). Выход(Q).\n");
	scanf("%c", &answer);
	switch(answer)
	{	
		case 'N':
			game();
			break;
		case 'Q':
			return 0;
	}
	return 0;
}

void game(){
	int fd=open("/dev/urandom", O_RDONLY);
	int isGame=1;
	int length=0;
	int cards=0;
	char amount[200];
	int queue[10];
		


	nextCard(cards, &queue[0], &fd);

	while(isGame){
		nextCard(cards, &queue[0], &fd);
		writing(&amount[0], cards, length);
	}
	printf("Хотите получить еще одну карту?\n");
	scanf("%c", &answer);
	switch(answer)
	{
		case 'y':
			break;
		case 'n':
			isGame=0;
			break;
	}
}

void writing(char *s,int printingCards, int stringEnd){
	printf("Получено %i карт%c\n", printingCards, printingCards<4 ? 'ы': ' ');
	
}


void nextCard(int cards, int *q, int *fd){
	
	cards++;
	unsigned char a;
	int z=0;
	read(*fd,&a,1);
	do{
		if (*(q+z)== 0)
		{
			*(q+z)=(int)a;
		}
		else ++z;
	}
	while(z);
}

