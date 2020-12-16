

#include<stdio.h>
#include <math.h>
int main() {
	double a,b,c,y,R,IM,r1,r2,n;
	printf("Enter the a,b and values when aX^2+bX+C :  \n");
	scanf("%lf%lf%lf",&a,&b,&c);
	y=(b*b)-(4*a*c);
	if(y<0) {
		IM=sqrt(-y)/(2*a);
		R=-b/(2*a);
		if(R==0){
			printf("+%lfi and -%lfi",IM,IM);
		}else{
			printf("%lf+%lfi and %lf-%lfi",R,IM,R,IM);
		}
	} else if(y==0) {
		n=-b/(2*a);
		printf("%lf",n);
	}else{
		r1=sqrt(y)/(2*a);
		r2=-b/(2*a);
		printf("%lf and %lf",r2+r1,r2-r1);
	}
	return 0;
}