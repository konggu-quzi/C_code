#include <stdio.h>
#include <string.h>

void Separate_unsigned_int(unsigned int N)
{
	int i=0,j=0,k=0;
	int i_len = N/5,j_len,len=0;
	for(i = 20; i >= 0; i--)
	{	
		j_len = N-(i*5);
		for (j=j_len/2; j >= 0; j--)
		{
			k = N-5*i-2*j;
			printf("%2d*1 + %2d*2 + %2d*5  =  %d\n",k,j,i,N );
			len++;
		}
	}
	printf("The %d of form is %d",N,len );
}

int main()
{
	unsigned int input;
	while(1)
	{
		printf("Plz input an +number:");
		while( (scanf("%d",&input)) != 1 && getchar() != '\n' )
		{	
			while( getchar() != '\n' );
			printf("invalued input,try again Plz!\n");		
		}
	      //printf("%s",input);
		Separate_unsigned_int(input);
		printf("\t\tpress enter to continue !");
		do
		{
			while( getchar() != '\n' );
		}while( getchar() != '\n' );
	}
	

}