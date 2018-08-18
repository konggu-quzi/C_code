#include <stdio.h>
#include <string.h>

void	delet_onechar(char str[],char delet_char)
{	
	int flag_location=0, i;
	int length = strlen(str);
	while( flag_location != length )
	{
		if( str[ flag_location ] == delet_char )
		{
			i = flag_location;
			do
			{
				str[ i ] = str[ i+1 ];
				i++;
			}while( !( str[ i ] == '\0' && str[ i - 1 ] == '\0' ) );
			delet_onechar( str+flag_location , delet_char );
		}
		flag_location++;	
	}
	return;	
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("argc = %d Usage: %s <filename>\n",argc, argv[0]);
		return 0;
	}

	int length = strlen(argv[1]);
	char *str = argv[1];
	int i = 0;

	while( i != length )
	{	
		delet_onechar((str + i+1),*(str + i));
		i++;
	}

	printf("%s\n",argv[1]);
	return 0;
}