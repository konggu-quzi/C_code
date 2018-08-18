#include <stdio.h>
#include <string.h>


int IP_Check(const char *IP)
{
	int length;
	int i=0,j=0;
	int ten_six_flag = 0,ten_flag = 0;
	int start = 0,end = 0;
	int len = 0,sum = 0,k = 10;
	char abs;
	
	length = strlen(IP);
//	printf("IP-length is %d\n",length);
		
	printf("%s is ", IP);
	while(*(IP+i) != '\0')
	{
		if(*(IP+i) != '.')
		{	
			if( *(IP+i) <= 'F' && *(IP+i) >= 'A' )
			{			
				ten_six_flag = 1;
			}	
		}else	j++;		
		i++;
	}
	if(j != 3)
	{
		printf("wrong IP  1 ");
		return 1;
	}
	i = 0;	
//	printf("%d  %d\n",ten_flag,ten_six_flag);

	while(*(IP+i) != '\0')
	{
			
		if(*(IP+i) == '.' || *(IP+i+1) == '\0')
		{
			//printf(" %d ",i);
			int a = 0;
			if(*(IP+i+1) == '\0')
			{
				end = i+1;
				a = 1;
			}
			else end = i;

			len =end - start;
			//printf(" %d ",len);
			if( len > 3 || (ten_six_flag == 1 && len >= 3) )
			{	
				printf("wrong IP  2 ");
				return 1;
			}

			sum = 0;
			if(ten_six_flag)	k = 16;			
			for(j=1;j<=len;j++)
			{
				if( *(IP+i-j+a) <= 'F' && *(IP+i-j+a) >= 'A' )	abs =  'A' - 10;
				else abs = '0';	
				if(j == 1)
					sum = sum + (*(IP+i-j+a)-abs)*1;
				else if(j == 2)
					sum = sum + (*(IP+i-j+a)-abs)*k;
				else if(j == 3)
					sum = sum + (*(IP+i-j+a)-abs)*100;
			}
			//printf(" %d ",sum);

			if(sum > 255)
			{
				printf("wrong IP 3 ");
				return 1;
			}
			start = i+1;	
		}
		i++;
	}
	i=0;

	printf("crect IP ");
	return 1;
}

int main(void)
{
	char *IP1 = "192.168.0.1.";	
	char *IP2 = "192.256.0.1";	
	char *IP3 = "A0.1FC.0.1";
	char *IP4 = "A0.GC.0.1";
	char *IP5 = "195.FC.0.1";
	
	char input[20];
	
	while(1)
	{
		printf("Plz input an IP_address:");
		while( (scanf("%s",input)) != 1 && getchar() != '\n' )
		{	
			while( getchar() != '\n' );
			printf("invalued input,try again Plz!\n");		
		}
	      //printf("%s",input);
		IP_Check(input);	
		printf("\tpress enter to continue !");
		do
		{
			while( getchar() != '\n' );
		}while( getchar() != '\n' );
	}	
	// IP_Check(IP1);		
	// IP_Check(IP2);
	// IP_Check(IP3);
	// IP_Check(IP4);
	// IP_Check(IP5);
	//printf("%s \n", IP1 );
	
	return 0;
}
