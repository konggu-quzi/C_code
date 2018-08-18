#include <stdio.h>

int f1(void)
{
	printf("%s\t%d\n",__FUNCTION__ ,__LINE__);
}
int f2(void)
{
	printf("%s\t%d\n",__FUNCTION__ ,__LINE__);
}
int f3(void)
{
	printf("%s\t%d\n",__FUNCTION__ ,__LINE__);
}
int main(void)
{

	int (*f[3])(void) = {&f1,&f2,&f3};
	int ( * ( *ff )[3] )(void) = &f;
	printf("%p\t%p\n",*f,**ff);
	( *( (*ff)+0 ) )();
	( *( (*ff)+1 ) )();
	( *( (*ff)+2 ) )();
}
