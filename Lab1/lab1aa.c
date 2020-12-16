#include<stdio.h>
int main() {
	int t1,t2;
	printf("Enter the start time : \n");
	scanf("%d",&t1);
	printf("Enter the dueriation time : \n");
	scanf("%d",&t2);
	int h1,h2,m1,m2;
	h1=t1/100;
	m1=t1%100;
	if((h1>23)||(m1>59)) {
		printf("Input time is invalied \n");
		
	}else {
		h2=t2/100;
	m2=t2%100;
	if((h2>23)||(m2>59)) {
		printf("Input time is invalied \n");
	} else {
		int h3,m3,day;
	day=0;
	h3=h1+h2;
	m3=m1+m2;
	while (h3>23) {
		h3=h3-24;
		day=day+1;
		
	}
	while(m3>59){
		m3=m3-60;
		h3=h3+1;
	}
	printf("overflow day is %d \n",day);
	printf("End time is %d %d\n",h3,m3);
	return 0;
	}
	}
	
	
	

	
}