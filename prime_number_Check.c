#include <stdio.h>
#include <math.h>

void examine_prime_number(unsigned int N)
{
	int i,j,flag = 1;
	for (i = 2; i <= N; i++)
	{	
		for (j = 2; j <= (int)sqrt(i); j++)
		{
			if(i%j == 0)
			{
				//printf("%d isn't a prime_number", N );
				flag = 0;
				break;
				//return;
			}	
		}
		if(flag)	printf("%4d", i );	
		flag =  1;
	}
}

int main(void)
{
	int input;
	while(1)
	{
		printf("Plz input an + number:");
		while( (scanf("%d",&input)) != 1 && getchar() != '\n' )
		{	
			while( getchar() != '\n' );
			printf("invalued input,try again Plz!\n");		
		}
		examine_prime_number(input);
		do
		{
			printf("\t\tpress enter to continue !");
			while( getchar() != '\n' );
		}while( getchar() != '\n' );
	}
	return 0;
}