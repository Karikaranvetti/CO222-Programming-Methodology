 #include<stdio.h>
#include <math.h>
int main () {
	int r,g,b;
	printf("Enter the coler :  ");
	scanf("%d%d%d",&r,&g,&b);
	int r1,g1,b1;
	r1=255-r;
	g1=255-g;
	b1=255-b;
	if ((abs(r-r1))<32){
		if(r<128){
			r1=r+128;
		}else{
			r1=r-128;
		}
	
	}
	if ((abs(g-g1))<32){
		if(g<128){
			g1=g+128;
		}else{
			g1=g-128;
		}
	
	}
	if ((abs(b-b1))<32){
		if(b<128){
			b1=b+128;
		}else{
			b1=b-128;
		}
	
	}
	printf("The complement: %d %d %d",r1,g1,b1);
	
	return 0;
	
}