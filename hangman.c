#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void logo()
{
	printf("\n\t\t\t    :::::::::::::::::::::");
	printf("\n\t\t\t    ::                 ::");
	printf("\n\t\t\t    ::     HANGMAN     ::");
	printf("\n\t\t\t    ::                 ::");
	printf("\n\t\t\t    :::::::::::::::::::::");
}
void main()
{
	int i, c, count=0, flag=0, temp=0;
	char a[20], b[20], d='_', x, ch;
	system("cls");//clrscr();
	logo();
	printf("\n\t\tEnter number of character are used in movie :- ");
	scanf("%d", &c);
	printf("\n\t\t\tEnter movie :- ");
	for(i=0;i<c;i++)
	{
		ch = getch();
		a[i] = ch;
		ch = '*';
		printf("%c", ch);
	}
	printf("\n\n\n\t\t\t    *********************");
	printf("\n\t\t\t    .....................\n\t\t\t          ");
	for(i=0;i<c;i++)
	{
		printf("%c", d);
		b[i]=d;
	}
	printf("\n\t\t\t    .....................");
	printf("\n\t\t\t    *********************");

	while(count<c)
	{
		flag=0;
		printf("\n\n\n\n\t\tEnter any character from your key board ");
		x = getch();
		for(i=0;i<c;i++)
		{
			if(x==a[i])
			{
				b[i]=a[i];
				flag=1;
				temp++;
			}
		}
	system("cls");	//clrscr();
		logo();
		printf("\n\n\n\t\t\t    *********************");
		printf("\n\t\t\t    .....................\n\t\t\t          ");
		for(i=0;i<c;i++)
		{
			printf("%c", b[i]);
		}
		printf("\n\t\t\t    .....................");
		printf("\n\t\t\t    *********************");

		if(flag==0)
		{
			count++;
			printf("\n\n\t\t\t      %c is a wrong guess", x);
			printf("\n\t\t\t    you have %d more chance ", c-count);
			printf("\n\t\t\t    %d more word remaining", c-temp);
		}
		else
		{
			count++;
			printf("\n\n\t\t\t   *** you are correct ***");
			printf("\n\t\t\t    you have %d more chance ",c-count);
			printf("\n\t\t\t    %d more word remaining", c-temp);
		}

		if(temp==c)
		{
			break;
		}
	}
	if(temp==c)
	{
		printf("\n\n\n\t\t        :)  @*@*@* YOU WON *@*@*@  :)");
	}
	else
	{
		printf("\n\n\n\t\t        :( YOU LOSE :(");
		printf("\n\t\t        :( YOU ARE HANGED :(");
	}

	getch();
}
