#include <stdio.h>
#include <fcntl.h>

void game(void);
void nextCard(int*, int *,int *);
void writing(char *, int, int);


char answer[2];



int main(void){
	printf("Новая игра (N). Выход(Q).\n");
	read(0, &answer[0], 2);
	switch(answer[0])
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
	char que[2];
	int i=0;
		


	nextCard(&cards, &queue[0], &fd);

	while(isGame)
	{	
		nextCard(&cards, &queue[0], &fd);
		writing(&amount[0], cards, length);
		printf("Хотите получить еще одну карту?(y/n)\n");		
		read(0, &que[0], 2);
		switch(que[0])
		{
			case 'y':
				break;
			case 'n':
				isGame=0;
				break;
		}
	} 
}

void writing(char *s,int printingCards, int stringEnd){
	printf("Получено %i карт\n", printingCards);
	
}


void nextCard(int *cards, int *q, int *fd){
	
	(*cards)++;
	unsigned char a;
	int z=0;
	read(*fd,&a,1);
	do{
		if (*(q+z)== 0)
		{
			*(q+z)=(int)a;
			z=0;
		}
		else ++z;
	}
	while(z);
}

