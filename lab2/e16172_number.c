#include<stdio.h>
int main(){
	int n;
	printf("Enter the number:  ");
	scanf("%d",&n);
	int sp,w1,w2,w3;
	sp=n%15;
	w1=n%5;
	w2=n%6;
	w3=n%18;
	char str1[15]="not special",str2[10]="notweird",str3[10]="notbig",str4[10]="notscery";
	if (sp==0) {
		str1[0] = 's';str1[1] = 'p';str1[2] = 'e';str1[3] = 'c';str1[4] = 'i';str1[5] = 'a';str1[6] = 'l';str1[7] = '\0';
	
	}
	if ((w1==0)&&(w2==0)&&(w3!=0)) {
		 str2[0] = 'w';str2[1] = 'e';str2[2] = 'i';str2[3] = 'r';str2[4] = 'd';str2[5] = '\0';
	
	}
	if(n>999){
		str3[0] = 'b';str3[1] = 'i';str3[2] = 'g';str3[3] = '\0';
	
	}
	if(((w1==0)&&(w2==0)&&(w3!=0))||(n>999)){
		 str4[0] = 's';str4[1] = 'c';str4[2] = 'e';str4[3] = 'r';str4[4] = 'y';str4[5] = '\0';
	
	}
	if(((w1==0)&&(w2==0)&&(w3!=0))||(n>999)){
		printf("%d is %s, %s and %s and %s.",n,str1,str2,str4,str3);
	}else{
		printf("%d is %s,%s",n,str1,str4);
	}
	
	return 0;
	
}