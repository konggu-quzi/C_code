#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
// #6f5999   //#0d7272
void Cal_gradient_ramp_array( unsigned int *color,unsigned int start_RGB, unsigned int end_RGB)
{
	unsigned int R_length,G_length,B_length,Pixel_length;
	int temp,i,j,num;
	char flag,k;
	for ( i = 0; i < 800; i++)
	{
		color[i] = start_RGB;
	}
	/********************************************************************/
	temp = ((end_RGB & 0xFF0000) >> 16) - ((start_RGB & 0xFF0000) >> 16);
	if(temp < 0){

		flag = -1;
		R_length = -1*temp ;
		num = -65536;
	}else	{

		R_length = temp ;
		flag = 1;
		num = 65536;
	} 

	Pixel_length = 800/(R_length) ;
	temp = 0;
	for (i = 0; i < R_length+1 ; i++)
	{
		for(j=0 ; j < Pixel_length ; j++)
		{
			color[ i*Pixel_length + j ] = color[ i*Pixel_length + j ] + temp;
			if (  (i*(Pixel_length) +  j + 1 ) == Pixel_length*(R_length+1) )
			{
				k = 800 - Pixel_length*(R_length+1) ;
				while(k)
				{
					color[ i*Pixel_length + j + k] = (unsigned int)(color[ i*Pixel_length + j + k] + temp);
					k--;
				}
			}	
		}
		temp = temp + num;				
	}
	printf("R_length:%d Pixel_length: %d sum: %d flag:%hhd color[799]: %x\n",R_length,Pixel_length,temp,flag,color[799]);

	/****************************************************************************/
	temp = ((end_RGB & 0x00FF00) >> 8) - ((start_RGB & 0x00FF00) >> 8);
	if(temp < 0)
	{
		flag = -1;
		G_length = - temp;
		num = -256;
	}else	
	{
		G_length = temp;
		flag = 1;
		num = 256;
	} 

	Pixel_length = 800/(G_length) ;
	temp = 0;
	for (i = 0; i < G_length+1 ; i++)
	{
		for(j=0 ; j < Pixel_length ; j++)
		{
			color[ i*Pixel_length + j ] = color[ i*Pixel_length + j ] + temp;
			if (  (i*(Pixel_length) +  j + 1 ) == Pixel_length*(G_length+1) )
			{
				k = 800 - Pixel_length*(G_length+1) ;
				while(k)
				{
					color[ i*Pixel_length + j + k] = (unsigned int)(color[ i*Pixel_length + j + k] + temp);
					k--;
				}
			}	
		}
		temp = temp + num;				
	}
	printf("G_length:%d Pixel_length: %d sum: %d flag:%hhd color[799]: %x\n",G_length,Pixel_length,temp,flag,color[799]);
	/****************************************************************************/
	temp = ( end_RGB & 0x0000FF ) - ( start_RGB & 0x0000FF );
	if(temp < 0)
	{
		flag = -1;
		B_length = - temp;
		num = -1;
	}else	
	{
		B_length = temp;
		flag = 1;
		num = 1;
	} 
	Pixel_length = 800/(B_length) ;
	temp = 0;
	for (i = 0; i < B_length+1 ; i++)
	{
		for(j=0 ; j < Pixel_length ; j++)
		{
			color[ i*Pixel_length + j ] = color[ i*Pixel_length + j ] + temp;
			if (  (i*(Pixel_length) +  j + 1 ) == Pixel_length*(B_length+1) )
			{
				k = 800 - Pixel_length*(B_length+1) ;
				while(k)
				{
					color[ i*Pixel_length + j + k] = (unsigned int)(color[ i*Pixel_length + j + k] + temp);
					k--;
				}
			}	
		}
		temp = temp + num;				
	}
	printf("B_length:%d Pixel_length: %d sum: %d flag:%hhd color[799]: %x\n",B_length,Pixel_length,temp,flag,color[799]);
	for ( i = 0; i < 800; i++)
	{
		color[i] = color[i] & 0x00FFFFFF;
		printf("%x\n", color[i]);
	}
}

int main(void)
{
	int fd; 
	unsigned int color[800];  
	fd=open("/dev/fb0",O_RDWR);
	int x,y,i,j;
	unsigned int *p;

	
	p=(unsigned int *)mmap(NULL,800*480*4,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);

	Cal_gradient_ramp_array( color ,0x6f5999, 0x0d7272);

	printf("%x    %x\n",color[0],color[799]);
	for(y=0;y<480;y++)
	{           
		//printf("%d\n",y);                                                                                              	
		for(x=0;x<800;x++)
		{
			//if(y>=478)	printf("%d\n",x);      
			*(p+x+y*800)= color[x] ;					
		}

	}
	
	printf("%x    %x\n",color[0],color[799]);
	munmap(p,800*480*4);
	close(fd);
	return 0;

}
