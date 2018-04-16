#include<stdio.h>
#include<stdlib.h>
int check(char[3][3],int);
int winner(int,int);
void display(char[3][3]);
int main()
{
	char a[3][3]={'.','.','.','.','.','.','.','.','.'};
	int i,j,f,h,z=0;
	printf("\n \t\t: Tic Tac Tio :\t\n\n\t made by !! Shanu Dey !!\n");
	
	while(z<=9){
	z++;
	first:
		f=1;
		printf("\n First player \n Enter row and column no : ");
		scanf("%d%d",&i,&j);
		if(a[i][j]=='O'||a[i][j]=='x')
		{
			printf("\n it is already filled try again");
			goto first;
		}
		else
		{
			a[i][j]='O';
			display(a);	
			h=check(a,f);
		}
	if(h==3)
	break;
	
	second:
		f=2;
		printf("\nSecond Player \n Enter row and column no : ");
		scanf("%d%d",&i,&j);
		if(a[i][j]=='O'||a[i][j]=='x')
		{
			printf("\n it is already filled try again");
			goto second;
		}
		else
		{
			a[i][j]='x';
			display(a);	
			h=check(a,f);
		}

	if(h==3)
	break;
	
}
}
int check(char a[3][3],int f)
{
	int i,j,c,d,g;
	switch(1)
	{
		case 1:
			for(i=0;i<3;i++)
			{
				c=0;
				d=0;
				for(j=0;j<3;j++)
				{
					if(a[i][j]=='O')
						c++;
					if(a[i][j]=='x')
						d++;
				}
				if(c==3||d==3)
				{
					g=winner(c,d);
					break;
				}
			
			}
		
		case 2:
			c=0;
			d=0;
			for(i=0;i<3;i++)
			{
				if(a[i][i]=='O')
						c++;
				if(a[i][i]=='x')
						d++;
			}
			
			if(c==3||d==3)
				{
					g=winner(c,d);
					break;
				}
				
		case 3:
			if(a[0][2]=='O'&&a[1][1]=='O'&&a[2][0]=='O')
				c=3;
			if(a[0][2]=='x'&&a[1][1]=='x'&&a[2][0]=='x')
				d=3;
			if(c==3||d==3)
				{
					g=winner(c,d);
					break;
				}
		case 4:
			for(i=0;i<3;i++)
			{
				c=0;
				d=0;
				for(j=0;j<3;j++)
				{
					if(a[j][i]=='O')
						c++;
					if(a[j][i]=='X')
						d++;
				}
				if(c==3||d==3)
				{
					g=winner(c,d);
					break;
				}
			}
			
		
	}
return g;

}
int winner(int c,int d)
{
	if(c==3)
	{
		printf(" \nFirst player is winner !!");
		return c;
	}
	if(d==3)
	{
		printf(" \nSecond player is winner !!");
		return d;
	}
}
void display(char a[3][3])
{
	int i,j;
	printf("\n");
	printf("\n _________________________ \n");
	for(i=0;i<3;i++)
	{
		
		for(j=0;j<3;j++)
		
			printf(" | %c\t ",a[i][j]);
		printf("|\n _________________________ \n");
	}
}
