#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>

int my_strlen(const char *p)
{	
	int length=0;
	while( *(p+length) != '\0' )
	{
		if(!( *(p + length + 1) == '\0' && *(p + length) == '\n' )){
			length++;	
		}else		return length;
	}	
	return length;
}
void back_to_printf_string(const char *p)
{
	int length = my_strlen(p);
	printf("back_to_printf_string:	");
	for(int i=1; i <= length; i++ )
		printf("%c",*(p+length-i));
	printf("\n");
}

int main(void)
{
	char ch[100];
	char *input = ch;
	int length;
	int letter_count=0,space_count=0,number_count=0,other_letter_count=0;

	printf("Plz input an string:");
	fgets(ch,100,stdin);

	printf("The result of my_strlen() is %d\n",my_strlen(input));
	back_to_printf_string(input);	

	char *examine = ch;
	while( *examine != '\0' )
	{
		if( *examine == ' ' ){

			space_count++;

		}else if( (*examine >= 'A' && *examine <= 'Z') || (*examine >= 'a' && *examine <= 'z') ){

			letter_count++;

		}else if( *examine >= '0' && *examine <= '9' ){

			number_count++;

		}else{

			other_letter_count++;
		}
		examine++;
	}
	printf("letter_count:%2d space_count:%9d \nnumber_count:%2d other_letter_count:%2d\n", 
		letter_count , space_count , number_count , other_letter_count - 1);
	letter_count=0;space_count=0;number_count=0;other_letter_count=0;
	// bzero(ch,100);

	return 0;
}