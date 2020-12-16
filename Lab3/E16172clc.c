#include<stdio.h>
long long int myatoi(char argv[]);  //function ptotocal
long double myatof(char argv[]); // function protocal
int main(int argc ,char* argv[])
{     
	if(argc!=4){         //num of argc for error 
        fprintf(stderr,"ERROR: The number of arguments is wrong.\nUsage: ./clc -<input format> -<output format> <input>\n");
    }else if (!((argv[1][1])=='B'||(argv[1][1])=='I'||(argv[1][1])=='F'||(argv[1][1])=='H'||(argv[1][1])=='D')){     // input argc for error
        fprintf(stderr,"ERROR: The input argument is wrong.\nPossible input arguments are -B, -H, -I, -F and -D.\n");
    }else if(!((argv[2][1])=='B'||(argv[2][1])=='I'||(argv[2][1])=='F'||(argv[2][1])=='H'||(argv[2][1])=='D')) {   // out put argc for error 
        fprintf(stderr,"ERROR: The output argument is wrong.\nPossible output arguments are -B, -H, -I, -F and -D.\n");
    }else if((argv[1][1])=='B'&&(argv[2][1])=='B') {     //binary to binary convertion  start
        int i=0;
        int t=0;
        
         for(i;argv[3][i]!='\0';i++){
             if((argv[3][i]!='0')&&(argv[3][i]!='1')){
                 fprintf(stderr,"ERROR: Input format error at location %d.\n",i);        //error location printing 
                 return 0;
             } 
         }
         if((argv[3][32]=='\0')||(argv[3][64]=='\0')){                //binaryvlue printing
             for(t;argv[3][t]!='\0';t++){
                 fprintf(stdout,"%c",argv[3][t]);
             }
         }else{
             fprintf(stderr,"ERROR: The input size is wrong.\n");         // else that size is wrong 
			return 0;
         }
          fprintf(stdout,"\n");   // after result new line 
    }else if((argv[1][1])=='B'&&(argv[2][1])=='I') {        //Here binary to integer converting stat                  
			 long long int  decimalval = 0, max_int = 2147483648;
			long long int binaryval;
			int t=0,r=0,i=0;            // loop incresments
			for(i;argv[3][i]!='\0';i++){
             if((argv[3][i]!='0')&&(argv[3][i]!='1')){
                 fprintf(stderr,"ERROR: Input format error at location %d.\n",i);        //error location printing 
                 return 0;
             	} 
        	}
			if(argv[3][32]=='\0'){   //size condition 
				if(argv[3][0]=='0'){           // positive sing condition 
					for(t;argv[3][t]!='\0';t++){
						
						if(argv[3][t]=='1'){
							decimalval=decimalval+max_int;
						}
						max_int=max_int/2;
					}
					fprintf(stdout,"%lld",decimalval) ;
				}else if (argv[3][0]=='1')              // negative value condition 
				{
					for(r;argv[3][r]!='\0';r++){
						
						if(argv[3][r]=='0'){
							decimalval=decimalval+max_int;
						}
						max_int=max_int/2;
					}
					fprintf(stdout,"%lld",-1*(decimalval+1)) ;            
				}
				
			}else
			{
				fprintf(stderr,"ERROR: The input size is wrong.\n");           //error size printing 
			}
        
    }else if((argv[1][1])=='B'&&(argv[2][1])=='F') {       //here binary to float convert start 
        int I =0;
         for(I;argv[3][I]!='\0';I++){
             if((argv[3][I]!='0')&&(argv[3][I]!='1')){
                 fprintf(stderr,"ERROR: Input format error at location %d.\n",I);        //error location printing 
                 return 0;
             	} 
        	}
            if((argv[3][32]=='\0')){         //size of binary condition 
                     int first_value;
                    int exponent_value=0;
                    int power;
                    long double power_value=1.0;
                    int max=128;
                    double min=0.5;
                    double desimal_value=0;
                    if(argv[3][0]=='0'){      // sing convert 
                        first_value=1;
                    }else{
                        first_value=-1;
                    }
                    for(int i=1;i<=8;i++){        //exponent part convert 
                        if(argv[3][i]=='1'){
                            exponent_value=exponent_value+max;
                        }
                        max=max/2;
                    }
                    power=exponent_value-127;    // geting power value 
                    for(int r=0;r<power;r++){
                        power_value=power_value*2;
                    }
                    for(int t=9;t<32;t++){       //mantrisa part convert 
                        if(argv[3][t]=='1'){
                            desimal_value=desimal_value+min;
                        }
                        min=min/2;
                    }
                    double flo_value=first_value*power_value*(desimal_value+1);
                            fprintf(stdout,"%0.2lf\n",flo_value);         // answer printing 
            }else if((argv[3][64]=='\0')){         // if that size 64 then error formet 
                fprintf(stderr,"ERROR: This conversion is not possible.\n");
            }else{
                   fprintf(stderr,"ERROR: The input size is wrong.\n");         // else that size is wrong 
			return 0;
            }
    }else if((argv[1][1])=='B'&&(argv[2][1])=='H') {     // here bin to hexa convert start 
        for(int n=0;argv[3][n]!='\0';n++){
			if((argv[3][n]!='1')&&(argv[3][n]!='0')){
				fprintf(stderr,"ERROR: Input format error at location %d.\n",n);
				return 0;
			}
		}
		if((argv[3][32]=='\0')||(argv[3][64]=='\0')){         //size condtion 
            fprintf(stdout,"0x");
			
			
			int i=0,u=0;
			if(argv[3][32]=='\0')    // if it is 32 bit 
			{
				for(int t=0;t<8;t++)
				{   int max=8;
					int desimal_value=0;
					

					for(i;i<u+4;i++)
					{
						if(argv[3][i]=='1'){
							desimal_value=desimal_value+max;
							//printf("\nd is %d ,max is %d ,i is %d\n u is %d",desimal_value,max,i,u);
						}
						max=max/2;
					}
					u=i;
					//printf("\n t is %d,i is %d\n",t,i);
					if(desimal_value<10){
						fprintf(stdout,"%d",desimal_value);    // here to hexa value printing start 
					}
					else if(desimal_value==10){
						fprintf(stdout,"A");
					}
					else if(desimal_value==11){
						fprintf(stdout,"B");
					}
					else if(desimal_value==12){
						fprintf(stdout,"C");
					}
					else if(desimal_value==13){
						fprintf(stdout,"D");
					}
					else if(desimal_value==14){
						fprintf(stdout,"E");
					}
					else if(desimal_value==15){
						fprintf(stdout,"F");
					}
				}
			}else if(argv[3][64]=='\0')  //if that is 64 bit then same as before but binary loop size only change 
			{
				for(int t=0;t<16;t++)
				{   int max=8;
					int desimal_value=0;

					for(i;i<u+4;i++)
					{
						if(argv[3][i]=='1'){
							desimal_value=desimal_value+max;
						}
						max=max/2;
					}
					u=i;
					if(desimal_value<10){
						fprintf(stdout,"%d",desimal_value);
					}
					else if(desimal_value==10){
						fprintf(stdout,"A");
					}
					else if(desimal_value==11){
						fprintf(stdout,"B");
					}
					else if(desimal_value==12){
						fprintf(stdout,"C");
					}
					else if(desimal_value==13){
						fprintf(stdout,"D");
					}
					else if(desimal_value==14){
						fprintf(stdout,"E");
					}
					else if(desimal_value==15){
						fprintf(stdout,"F");
					}
				}
			
			}
		fprintf(stdout,"\n");    //printing new line 

		}else{
			fprintf(stderr,"ERROR: The input size is wrong.\n");   // if it not print error 
			return 0;
		}
    }else if((argv[1][1])=='B'&&(argv[2][1])=='D') {       //binary to double convertion start 
         int I =0;
         for(I;argv[3][I]!='\0';I++){
             if((argv[3][I]!='0')&&(argv[3][I]!='1')){
                 fprintf(stderr,"ERROR: Input format error at location %d.\n",I);        //error location printing 
                 return 0;
             	} 
        	}
        if((argv[3][64]=='\0')){   // that should be 64 bit 
            int first_value;
        int exponent_value=0;
        int power;
        long double power_value=1.0;
        int max=1024;
        double min=0.5;
        double desimal_value=0;
        if(argv[3][0]=='0'){       //sing check 
            first_value=1;
        }else{
            first_value=-1;
        }
        for(int i=1;i<=11;i++){     //11 bit exponent 
            if(argv[3][i]=='1'){
                exponent_value=exponent_value+max;
            }
            max=max/2;
        }
        power=exponent_value-1023; //exponent power part 
        for(int r=0;r<power;r++){
            power_value=power_value*2;
        }
        for(int t=12;t<64;t++){
            if(argv[3][t]=='1'){
                desimal_value=desimal_value+min;
            }
            min=min/2;
        }
        double flo_value=first_value*power_value*(desimal_value+1);
               // printf("f is %d\n p is %d \n de is %lf\n powis %d\n",first_value,power_value,desimal_value,power);
                fprintf(stdout,"%lf\n",flo_value);

        }else if((argv[3][32]=='\0')){
                fprintf(stderr,"ERROR: This conversion is not possible.\n");
            }else{
                   fprintf(stderr,"ERROR: The input size is wrong.\n");         // else that size is wrong 
			return 0;
            }
    }else if((argv[1][1])=='I'&&(argv[2][1])=='I') {    //int to int convert start 
       long long int integer_value;
        int sign=1;
        int m=0;                      // this place sing check 
        if(argv[3][0]=='-'){
            sign=-1;
            m=m+1;	
        }
        integer_value=myatoi(argv[3]);     // geting int value 
         
        for( m;argv[3][m]!='\0' ;m++){
            if((argv[3][m]>=48)&&(argv[3][m]<=57)){
                if((-2147483648<=integer_value)&&(2147483648>integer_value)){       //size limt fot int 
                    }else{
                    fprintf(stderr,"ERROR: The input size is wrong.\n");
                    return 0;
                }
                }else{
                fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                return 0;
            }
        }
            
          fprintf(stdout,"%lld\n",integer_value);
    }else if((argv[1][1])=='I'&&(argv[2][1])=='B') {
             long long int integer_value;
            int sign=1;
            int m=0;
            if(argv[3][0]=='-'){
                sign=-1;
                m=m+1;	
            }
            integer_value=myatoi(argv[3]);
            
            for( m;argv[3][m]!='\0' ;m++){
                if((argv[3][m]>=48)&&(argv[3][m]<=57)){
                     if((-2147483648<=integer_value)&&(2147483648>integer_value)){
                        }else{
                        fprintf(stderr,"ERROR: The input size is wrong.\n");
                        return 0;
                    }
                    }else{
                    fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                    return 0;
                }
            }
        int integerValue; // integer value dicleartion
                int integerValue_2;
                int i,j=31;      // for loop and while loop variable dicleartion 
                int binaryArray[32];
                integerValue=myatoi(argv[3]);
                 
                if(argv[3][0]=='-'){
                
                    integerValue_2=((-1)*integerValue)-1; // makeing chage to negativeve values
                } else{
                    integerValue_2=integerValue;
                }             //char to int changing
               
                for (i=0;i<32;i++){          // for the 32 digit binaryval getiing procces
                    binaryArray[i]=integerValue_2%2;            //rimider storeing an array
                    integerValue_2=integerValue_2/2;
                } 
                if(integerValue<0){
                    for(int t=0;t<32;t++){
                        if(binaryArray[t]==1){
                            binaryArray[t]=0;
                        }else {
                            binaryArray[t]=1;
                        }
                    }
                }	
                while(j>=0)	{          //array printing loop 
                fprintf(stdout,"%d",binaryArray[j]);
                j=j-1;
                }
                fprintf(stdout,"\n");
    }else if((argv[1][1])=='I'&&(argv[2][1])=='F') {
        int sign=1;
        int m=0;
        if(argv[3][0]=='-'){
            sign=-1;
            m=m+1;	
        }
        long long int integer_value=myatoi(argv[3]);
         double float_value=(double)integer_value;
        for( m;argv[3][m]!='\0' ;m++){
            if((argv[3][m]>=48)&&(argv[3][m]<=57)){
                if((-2147483648<=integer_value)&&(2147483648>integer_value)){
                    }else{
                    fprintf(stderr,"ERROR: The input size is wrong.\n");
                    return 0;
                }
                }else{
                fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                return 0;
            }
        }
         fprintf(stdout,"%0.2lf\n",float_value);
    }else if((argv[1][1])=='I'&&(argv[2][1])=='H') {
        long long int integer_value;
        int sign=1;
        int m=0;
        if(argv[3][0]=='-'){
            sign=-1;
            m=m+1;	
        }
        integer_value=myatoi(argv[3]);
         
        for( m;argv[3][m]!='\0' ;m++){
            if((argv[3][m]>=48)&&(argv[3][m]<=57)){
                if((-2147483648<=integer_value)&&(2147483648>integer_value)){
                    }else{
                    fprintf(stderr,"ERROR: The input size is wrong.\n");
                    return 0;
                }
                }else{
                fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                return 0;
            }
        }
         int integerValue; // integer value dicleartion
                int integerValue_2;
                int i,j=31;      // for loop and while loop variable dicleartion 
                int binaryArray[32];
                int hexaArray[32];
                integerValue=myatoi(argv[3]);
                  
                if(argv[3][0]=='-'){
                
                    integerValue_2=((-1)*integerValue)-1; // makeing chage to negativeve values
                } else{
                    integerValue_2=integerValue;
                }             //char to int changing
               
                for (i=0;i<32;i++){          // for the 32 digit binaryval getiing procces
                    binaryArray[i]=integerValue_2%2;            //rimider storeing an array
                    integerValue_2=integerValue_2/2;
                } 
                if(integerValue<0){
                    for(int t=0;t<32;t++){
                        if(binaryArray[t]==1){
                            binaryArray[t]=0;
                        }else {
                            binaryArray[t]=1;
                        }
                    }
                }	
               while(j>=0)	{          //array printing loop 
               hexaArray[31-j]=binaryArray[j];
                j=j-1;
                }
                fprintf(stdout,"0x");
                int I=0,u=0;
                for(int T=0;T<8;T++)
				{   int max=8;
					int desimal_value=0;
					for(I;I<u+4;I++)
					{
						if(hexaArray[I]==1){
							desimal_value=desimal_value+max;
							//printf("\nd is %d ,max is %d ,i is %d\n u is %d",desimal_value,max,I,u);
						}
						max=max/2;
					}
					u=I;
					//printf("\n t is %d,i is %d\n",T,I);
                    
					if(desimal_value<10){
						fprintf(stdout,"%d",desimal_value);
					}
					else if(desimal_value==10){
						fprintf(stdout,"A");
					}
					else if(desimal_value==11){
						fprintf(stdout,"B");
					}
					else if(desimal_value==12){
						fprintf(stdout,"C");
					}
					else if(desimal_value==13){
						fprintf(stdout,"D");
					}
					else if(desimal_value==14){
						fprintf(stdout,"E");
					}
					else if(desimal_value==15){
						fprintf(stdout,"F");
					}
				}
                 fprintf(stdout,"\n");
    }else if((argv[1][1])=='I'&&(argv[2][1])=='D') {
             long long int integer_value;
        int sign=1;
        int m=0;
        if(argv[3][0]=='-'){
            sign=-1;
            m=m+1;	
        }
        integer_value=myatoi(argv[3]);
         
        for( m;argv[3][m]!='\0' ;m++){
            if((argv[3][m]>=48)&&(argv[3][m]<=57)){
                if((-2147483648<=integer_value)&&(2147483648>integer_value)){
                    }else{
                    fprintf(stderr,"ERROR: The input size is wrong.\n");
                    return 0;
                }
                }else{
                fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                return 0;
            }
        }    
        fprintf(stderr,"ERROR: This conversion is not possible.");
    }else if((argv[1][1])=='F'&&(argv[2][1])=='F') {
        int sign=1;
        int dot=0;
        int m=0;
        if(argv[3][0]=='-'){
                    sign=-1;
                    m=m+1;	
                }
                for( m;argv[3][m]!='\0' ;m++){
                    if(((argv[3][m]>=48)&&(argv[3][m]<=57))||(argv[3][m]==46)||(argv[3][m]=='\0')){
                        if((argv[3][m]==46)){
                            dot++;
                        }
                    }else{
                         fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                         return 0;
                    }
                    if(dot>1){
                        fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                        return 0;
                    }                }
        
        //printf("%s\n",argv[3]);
        long double val;
    val=myatof(argv[3]);
    fprintf(stdout,"%.2Lf\n",val);
        
    }else if((argv[1][1])=='F'&&(argv[2][1])=='B') {
                long double float_value,desimal_value;
				int array1[32],array2[32],array3[8],hexa_array[32];
				int p, exponent,b,exponent_value;
                int r,t=7,r1,t1=7,r2,r3,r4,r5,r6,r7,r8,r9,r10,dot=0,h,j=0;
                 int sign=1;
                int m=0;
                if(argv[3][0]=='-'){
                    sign=-1;
                    m=m+1;	
                }
                for( m;argv[3][m]!='\0' ;m++){
                    if(((argv[3][m]>=48)&&(argv[3][m]<=57))||(argv[3][m]==46)||(argv[3][m]=='\0')){
                        if((argv[3][m]==46)){
                            dot++;
                        }
                    }else{
                         fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                         return 0;
                    }
                    if(dot>1){
                        fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                        return 0;
                    }                }
				float_value=myatof(argv[3]);                    //char to int changing 
				int integer_value=(int)float_value;         // here casting to geting int part in float value 
				desimal_value=float_value-integer_value;               // here geting 0.  values
				if(float_value<0){        // here if our input is negative value we changing to positive for rest of operations are same as + number thats why     
					integer_value=-integer_value;
					desimal_value=-desimal_value;
				}
			
				int i;
				for( i=0;i<32;i++){                  // here int part converting as a binaryval
					array1[i]=integer_value%2;
					integer_value=integer_value/2;
					
					if(integer_value==0){                  // loop break condition 
						 b=i;            // here i store condition breaking i value 
						break;          
					}
				}
			 
				for(p=0;p<32;p++){                // here i converting 0. vlues in binary
					desimal_value=desimal_value*2;
					array2[p]=desimal_value/1;
					if(desimal_value>1.0000){                // while converting 0. value go 1. value here agine making that valu as a 0. value
						desimal_value=desimal_value-1;
					}
					
					if(desimal_value==1.0000){              // loop break condition 
						int z=p;                     // here I store condition breaking P value 
						break;
					}
				
				
				}
			
				if(float_value>0){               // here first stat float value printing as a binary 
					hexa_array[0]=0;          // if input is positive first digit is 0
				} else {
					  hexa_array[0]=1;   // if input negative first digit  is 1
				}
				if((i==0)&&(array1[0]==1)){            // here 1.1111 this format binary are changing
					exponent=0;            // here expont making value is 0
					exponent_value=127;             //ex1=ex+127
					for (r=0;r<8;r++){         // that ex1 vlue convert to binary
					array3[r]=exponent_value%2;
					exponent_value=exponent_value/2;
					} h=0;	
					while(t>=0)	{          // here print exponent value 
                    h=h+1;
					hexa_array[h]=array3[t];
					t=t-1;
					}if(23>=p){
                        for(r6=0;r6<=p;r6++){       // here .1110 like as values prining 
                            hexa_array[r6+9]=array2[r6];
                        }
                        for(r7=p+9;r7<31;r7++){        // here rest of 32 digit for filling zeros
                            array2[r7]=0;
                            hexa_array[r7]=array2[r7];
                        }
                    }else{
                        for(r6=0;r6<23;r6++){       // here .1110 like as values prining 
                            hexa_array[r6+9]=array2[r6];
                        }
                        int l;
                        if(array2[23]==1){
                            for(l=31;hexa_array[l]!=0;l--){
                                hexa_array[l]=0;
                            }
                            hexa_array[l]=1;
                        }
                    }
				}
				else if((i==0)&&(array1[0]==0)){    // this is 2ed possiblity 0.1101 like values converting 
					for(r2=0;r2<22;r2++){
						if (array2[r2]==1){
							r3=r2;                // here where it loop break that vlue r2 is storing 
							break;
						}
					}
					exponent=-(r3+1);          //for exponent value 
					exponent_value=127+exponent;           
					for (r1=0;r1<8;r1++){      // exponent convert into binary 
					array3[r1]=exponent_value%2;
					exponent_value=exponent_value/2;
					} 
                    h=0;
					while(t1>=0)	{          // exponent for binaray value printing
                    h=h+1; 
					hexa_array[h]=array3[t1];
					t1=t1-1;
					}
                    h=8;
                    if(23>=p){
                        for(r4=(r3+1);r4<=p;r4++){          //0.1101    values printing 
                            h=h+1;
                            hexa_array[h]=array2[r4];
                        }
                        for(r5=(p+1);r5<(25-p+r3);r5++){         // rest of 32 digits printing as 0 
                            array2[r5]=0;
                            h=h+1;
                            hexa_array[h]=array2[r5];
                        }
                    }else{
						if((p-r3)>23){
							for(r4=(r3+1);r4<=(r3+23);r4++){          //0.1101    values printing 
                            h=h+1;
                            hexa_array[h]=array2[r4];
                            } 
                            if(array2[r3+24]==1){
								//printf("\n%d\n",array2[r3+24]);
								int l;
								for(l=31;hexa_array[l]!=0;l--){
									hexa_array[l]=0;
								}
								hexa_array[l]=1;
							}
						}else{
							for(r4=(r3+1);r4<=p;r4++){          //0.1101    values printing 
                            h=h+1;
                            hexa_array[h]=array2[r4];
                        }
                        for(r5=(p+1);r5<(25-p+r3);r5++){         // rest of 32 digits printing as 0 
                            array2[r5]=0;
                            h=h+1;
                            hexa_array[h]=array2[r5];
                        }
						}
                       
                    }
				}
				else{                       // 3ed posibility 111.0101 like values converting 
					exponent=i;
					exponent_value=127+exponent;                // here exponent value converting
					for (r=0;r<8;r++){
					array3[r]=exponent_value%2;
					exponent_value=exponent_value/2;
					} 
                    h=0;	
					while(t>=0)	{
					 h=h+1; 
					hexa_array[h]=array3[t];             // exponent value prinrinting 
					t=t-1;
					}
                    h=8;
                    if(23>=i){
                        for(r10=i-1;r10>=0;r10--){               //.11000 like value printing 
                            h=h+1;
                            hexa_array[h]=array1[r10];
                        }
                        if(23-i>=p){
                            for(r8=0;r8<=p;r8++){               //.11000 like value printing 
                                h=h+1;
                                hexa_array[h]=array2[r8];
                            }
                            for(r9=1;r9<(23-p-i);r9++){        // here rest of value prining for 32 digit
                                array2[r9]=0;
                                h=h+1;
                                hexa_array[h]=array2[r9];
                            }
                        }else{
                            for(r8=0;r8<=23-i;r8++){               //.11000 like value printing 
                                h=h+1;
                                hexa_array[h]=array2[r8];
                            }
                        }
				}else{
                    for(r10=i-1;r10>i-24;r10--){               //.11000 like value printing 
                        h=h+1;
                            hexa_array[h]=array1[r10];
                        }
                        if(array1[i-24]==1){
                            int l=(31);
                            while(hexa_array[l]!=0){
                                hexa_array[l]=0;
                                 
                                l=l-1;
                                    }
                                    hexa_array[l]=1;
                        }
                }
                }
                int y=0;
                while(y<32){
                    fprintf(stdout,"%d",hexa_array[y]);
                    y=y+1;
                }
                fprintf(stdout,"\n");       
    }else if((argv[1][1])=='F'&&(argv[2][1])=='I') {
        int dot=0;
        int m=0;
        int sign=1;
        if(argv[3][0]=='-'){
             sign=-1;
             m=m+1;	
                }
        for(m;argv[3][m]!='\0' ;m++){
                    if(((argv[3][m]>=48)&&(argv[3][m]<=57))||(argv[3][m]==46)||(argv[3][m]=='\0')){
                        if((argv[3][m]==46)){
                            dot++;
                        }
                    }else{
                         fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                         return 0;
                    }
                    if(dot>1){
                        fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                        return 0;
                    }        
                 }
        double float_value=myatof(argv[3]);
        int integer_value=float_value;
        if(-2147483648!=integer_value){
            fprintf(stderr,"WARNING: There is a possibility for a precision loss.\n%d\n",integer_value);
        }else{
            fprintf(stderr,"ERROR: This conversion is not possible.\n");
        }
    }else if((argv[1][1])=='F'&&(argv[2][1])=='H') {
          long double float_value,desimal_value;
				int array1[32],array2[32],array3[8],hexa_array[32];
				int p, exponent,b,exponent_value;
                int r,t=7,r1,t1=7,r2,r3,r4,r5,r6,r7,r8,r9,r10,dot=0,h,j=0;
                 int sign=1;
                int m=0;
                if(argv[3][0]=='-'){
                    sign=-1;
                    m=m+1;	
                }
                for( m;argv[3][m]!='\0' ;m++){
                    if(((argv[3][m]>=48)&&(argv[3][m]<=57))||(argv[3][m]==46)||(argv[3][m]=='\0')){
                        if((argv[3][m]==46)){
                            dot++;
                        }
                    }else{
                         fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                         return 0;
                    }
                    if(dot>1){
                        fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                        return 0;
                    }                }
				float_value=myatof(argv[3]);                    //char to int changing 
				int integer_value=(int)float_value;         // here casting to geting int part in float value 
				desimal_value=float_value-integer_value;               // here geting 0.  values
				if(float_value<0){        // here if our input is negative value we changing to positive for rest of operations are same as + number thats why     
					integer_value=-integer_value;
					desimal_value=-desimal_value;
				}
			
				int i;
				for( i=0;i<32;i++){                  // here int part converting as a binaryval
					array1[i]=integer_value%2;
					integer_value=integer_value/2;
					
					if(integer_value==0){                  // loop break condition 
						 b=i;            // here i store condition breaking i value 
						break;          
					}
				}
			 
				for(p=0;p<32;p++){                // here i converting 0. vlues in binary
					desimal_value=desimal_value*2;
					array2[p]=desimal_value/1;
					if(desimal_value>1.0000){                // while converting 0. value go 1. value here agine making that valu as a 0. value
						desimal_value=desimal_value-1;
					}
					
					if(desimal_value==1.0000){              // loop break condition 
						int z=p;                     // here I store condition breaking P value 
						break;
					}
				
				
				}
			
				if(float_value>0){               // here first stat float value printing as a binary 
					hexa_array[0]=0;          // if input is positive first digit is 0
				} else {
					  hexa_array[0]=1;   // if input negative first digit  is 1
				}
				if((i==0)&&(array1[0]==1)){            // here 1.1111 this format binary are changing
					exponent=0;            // here expont making value is 0
					exponent_value=127;             //ex1=ex+127
					for (r=0;r<8;r++){         // that ex1 vlue convert to binary
					array3[r]=exponent_value%2;
					exponent_value=exponent_value/2;
					} h=0;	
					while(t>=0)	{          // here print exponent value 
                    h=h+1;
					hexa_array[h]=array3[t];
					t=t-1;
					}if(23>=p){
                        for(r6=0;r6<=p;r6++){       // here .1110 like as values prining 
                            hexa_array[r6+9]=array2[r6];
                        }
                        for(r7=p+9;r7<31;r7++){        // here rest of 32 digit for filling zeros
                            array2[r7]=0;
                            hexa_array[r7]=array2[r7];
                        }
                    }else{
                        for(r6=0;r6<23;r6++){       // here .1110 like as values prining 
                            hexa_array[r6+9]=array2[r6];
                        }
                        int l;
                        if(array2[23]==1){
                            for(l=31;hexa_array[l]!=0;l--){
                                hexa_array[l]=0;
                            }
                            hexa_array[l]=1;
                        }
                    }
				}
				else if((i==0)&&(array1[0]==0)){    // this is 2ed possiblity 0.1101 like values converting 
					for(r2=0;r2<22;r2++){
						if (array2[r2]==1){
							r3=r2;                // here where it loop break that vlue r2 is storing 
							break;
						}
					}
					exponent=-(r3+1);          //for exponent value 
					exponent_value=127+exponent;           
					for (r1=0;r1<8;r1++){      // exponent convert into binary 
					array3[r1]=exponent_value%2;
					exponent_value=exponent_value/2;
					} 
                    h=0;
					while(t1>=0)	{          // exponent for binaray value printing
                    h=h+1; 
					hexa_array[h]=array3[t1];
					t1=t1-1;
					}
                    h=8;
                    if(23>=p){
                        for(r4=(r3+1);r4<=p;r4++){          //0.1101    values printing 
                            h=h+1;
                            hexa_array[h]=array2[r4];
                        }
                        for(r5=(p+1);r5<(25-p+r3);r5++){         // rest of 32 digits printing as 0 
                            array2[r5]=0;
                            h=h+1;
                            hexa_array[h]=array2[r5];
                        }
                    }else{
						if((p-r3)>23){
							for(r4=(r3+1);r4<=(r3+23);r4++){          //0.1101    values printing 
                            h=h+1;
                            hexa_array[h]=array2[r4];
                            } 
                            if(array2[r3+24]==1){
								 
								int l;
								for(l=31;hexa_array[l]!=0;l--){
									hexa_array[l]=0;
								}
								hexa_array[l]=1;
							}
						}else{
							for(r4=(r3+1);r4<=p;r4++){          //0.1101    values printing 
                            h=h+1;
                            hexa_array[h]=array2[r4];
                        }
                        for(r5=(p+1);r5<(25-p+r3);r5++){         // rest of 32 digits printing as 0 
                            array2[r5]=0;
                            h=h+1;
                            hexa_array[h]=array2[r5];
                        }
						}
                       
                    }
				}
				else{                       // 3ed posibility 111.0101 like values converting 
					exponent=i;
					exponent_value=127+exponent;                // here exponent value converting
					for (r=0;r<8;r++){
					array3[r]=exponent_value%2;
					exponent_value=exponent_value/2;
					} 
                    h=0;	
					while(t>=0)	{
					 h=h+1; 
					hexa_array[h]=array3[t];             // exponent value prinrinting 
					t=t-1;
					}
                    h=8;
                    if(23>=i){
                        for(r10=i-1;r10>=0;r10--){               //.11000 like value printing 
                            h=h+1;
                            hexa_array[h]=array1[r10];
                        }
                        if(23-i>=p){
                            for(r8=0;r8<=p;r8++){               //.11000 like value printing 
                                h=h+1;
                                hexa_array[h]=array2[r8];
                            }
                            for(r9=1;r9<(23-p-i);r9++){        // here rest of value prining for 32 digit
                                array2[r9]=0;
                                h=h+1;
                                hexa_array[h]=array2[r9];
                            }
                        }else{
                            for(r8=0;r8<=23-i;r8++){               //.11000 like value printing 
                                h=h+1;
                                hexa_array[h]=array2[r8];
                            }
                        }
				}else{
                    for(r10=i-1;r10>i-24;r10--){               //.11000 like value printing 
                        h=h+1;
                            hexa_array[h]=array1[r10];
                        }
                        if(array1[i-24]==1){
                            int l=(31);
                            while(hexa_array[l]!=0){
                                hexa_array[l]=0;
                                //printf("\n%d\n",hexa_array[l]);
                                l=l-1;
                                    }
                                    hexa_array[l]=1;
                        }
                }
                }
               
                fprintf(stdout,"0x");
                  int I=0,u=0;
                for(int T=0;T<8;T++)
				{   int max=8;
					int desimal_value=0;
					for(I;I<u+4;I++)
					{
						if(hexa_array[I]==1){
							desimal_value=desimal_value+max;
							//printf("\nd is %d ,max is %d ,i is %d\n u is %d",desimal_value,max,I,u);
						}
						max=max/2;
					}
					u=I;
					//printf("\n t is %d,i is %d\n",T,I);
					if(desimal_value<10){
						fprintf(stdout,"%d",desimal_value);
					}
					else if(desimal_value==10){
						fprintf(stdout,"A");
					}
					else if(desimal_value==11){
						fprintf(stdout,"B");
					}
					else if(desimal_value==12){
						fprintf(stdout,"C");
					}
					else if(desimal_value==13){
						fprintf(stdout,"D");
					}
					else if(desimal_value==14){
						fprintf(stdout,"E");
					}
					else if(desimal_value==15){
						fprintf(stdout,"F");
					}
				}
				fprintf(stdout,"\n");
    }/*else if((argv[1][1])=='F'&&(argv[2][1])=='D') {
         
                 
    }*/else if((argv[1][1])=='H'&&(argv[2][1])=='H') {           // hex to hexa convert 
         for(int n=0;argv[3][n]!='\0';n++){
                    if(!((argv[3][n]>='A'&&argv[3][n]<='F')||(argv[3][n]>='0'&&argv[3][n]<='9'))){
                        fprintf(stderr,"ERROR: Input format error at location %d.\n",n);
                        return 0;
                    }
                }
                if((argv[3][8]=='\0')||(argv[3][16]=='\0')){
                   fprintf(stdout,"0x%s",argv[3]);
                }else{
			fprintf(stderr,"ERROR: The input size is wrong.\n");
			return 0;
		}
        fprintf(stdout,"\n");
        
    }else if((argv[1][1])=='H'&&(argv[2][1])=='B') {         // bin to hexa convert 
        for(int n=0;argv[3][n]!='\0';n++){
                    if(!((argv[3][n]>='A'&&argv[3][n]<='F')||(argv[3][n]>='0'&&argv[3][n]<='9'))){
                        fprintf(stderr,"ERROR: Input format error at location %d.\n",n);
                        return 0;
                    }
                }
             if((argv[3][8]=='\0')||(argv[3][16]=='\0')){
                    char hexVal[31];
                    
                    
                    for (int k=0; argv[3][k]!='\0'; k++){
                        hexVal[k]=argv[3][k];             // here store ever input digit as character 
                    } 
                    int g;
                    int base = 1; 
                    
                    long long int dec_val = 0; 
                    for (int i=0;argv[3][i]!='\0'  ; i++)         // here agine hexa to desimal changing procces but only one digit
                    {  
                        if (hexVal[i]>='0' && hexVal[i]<='9') 
                        { 
                            dec_val = (hexVal[i] - 48)*base; 
                        } 
                        else if (hexVal[i]>='A' && hexVal[i]<='F') 
                        { 
                            dec_val = (hexVal[i] - 55)*base;  
                            
                        }else if(hexVal[i]>='a' && hexVal[i]<='f') 
                        { 
                            dec_val = (hexVal[i] - 87)*base;  
                            
                        } 
            
                    int stored_dec_val,t,j=0;
                        int binary_array[4];
                        stored_dec_val=dec_val;           // here set early output  as input for the decimal to binaray procces
                        
                        for (t=3;t>-1;t--){
                            binary_array[t]=stored_dec_val%2;
                            stored_dec_val=stored_dec_val/2;
                        } 
                    
                        while(j<=3)	{
                        fprintf(stdout,"%d",binary_array[j]);           
                        j=j+1;
                        }
                        
                        
                        } 
                        fprintf(stdout,"\n");
                
                }else{
			fprintf(stderr,"ERROR: The input size is wrong.\n");
			return 0;
		}
    }else if((argv[1][1])=='H'&&(argv[2][1])=='I') {
        for(int n=0;argv[3][n]!='\0';n++){
                    if(!((argv[3][n]>='A'&&argv[3][n]<='F')||(argv[3][n]>='0'&&argv[3][n]<='9'))){
                        fprintf(stdout,"ERROR: Input format error at location %d.\n",n);
                        return 0;
                    }
                }
             if((argv[3][8]=='\0')||(argv[3][16]=='\0')){
                    char hexVal[31];
                    
                    
                    for (int k=0; argv[3][k]!='\0'; k++){
                        hexVal[k]=argv[3][k];             // here store ever input digit as character 
                    } 
                    int g;
                    int base = 1; 
                    
                    long long int dec_val = 0; 
                    int t=3,q=-1,N=3;
                     int binary_array[32];
                    for (int i=0;argv[3][i]!='\0'  ; i++)         // here agine hexa to desimal changing procces but only one digit
                    {  
                        if (hexVal[i]>='0' && hexVal[i]<='9') 
                        { 
                            dec_val = (hexVal[i] - 48)*base; 
                        } 
                        else if (hexVal[i]>='A' && hexVal[i]<='F') 
                        { 
                            dec_val = (hexVal[i] - 55)*base;  
                            
                        }else if(hexVal[i]>='a' && hexVal[i]<='f') 
                        { 
                            dec_val = (hexVal[i] - 87)*base;  
                            
                        } 
                            N=N+4;
                    int stored_dec_val;
                        //int binary_array[32];
                        stored_dec_val=dec_val;           // here set early output  as input for the decimal to binaray procces
                        
                        for (t;t>q;t--){
                            binary_array[t]=stored_dec_val%2;
                            stored_dec_val=stored_dec_val/2;
                        }
                        t=N;
                        q=t-4;
                        
                         
                    }
                   
                    long long int  decimalval = 0;
                    long long int  I = 2147483648;
                    int R=0,T=0;
                    if(binary_array[0]==0){
                        for(T;T<32;T++){
                            if(binary_array[T]==1){
							decimalval=decimalval+I;
                            }
                            I=I/2;
                        }
                        fprintf(stdout,"%lld\n",decimalval) ;
                    }else if(binary_array[0]==1){
                        for(R;R<32;R++){
                            if(binary_array[R]==0){
							decimalval=decimalval+I;
                            }
                            I=I/2;
                        }
                        fprintf(stdout,"%lld\n",-1*(decimalval+1)) ;
                    }
             }else{
			fprintf(stderr,"ERROR: The input size is wrong.\n");
			return 0;
		}
    }else if((argv[1][1])=='H'&&(argv[2][1])=='F') {
         for(int n=0;argv[3][n]!='\0';n++){
                    if(!((argv[3][n]>='A'&&argv[3][n]<='F')||(argv[3][n]>='0'&&argv[3][n]<='9'))){
                        fprintf(stderr,"ERROR: Input format error at location %d.\n",n);
                        return 0;
                    }
                }
             if((argv[3][8]=='\0')){
                    char hexVal[31];
                    
                    
                    for (int k=0; argv[3][k]!='\0'; k++){
                        hexVal[k]=argv[3][k];             // here store ever input digit as character 
                    } 
                    int g;
                    int base = 1; 
                    
                    long long int dec_val = 0; 
                    int t=3,q=-1,n=3;
                     int binary_array[32];
                    for (int i=0;argv[3][i]!='\0'  ; i++)         // here agine hexa to desimal changing procces but only one digit
                    {  
                        if (hexVal[i]>='0' && hexVal[i]<='9') 
                        { 
                            dec_val = (hexVal[i] - 48)*base; 
                        } 
                        else if (hexVal[i]>='A' && hexVal[i]<='F') 
                        { 
                            dec_val = (hexVal[i] - 55)*base;  
                            
                        }else if(hexVal[i]>='a' && hexVal[i]<='f') 
                        { 
                            dec_val = (hexVal[i] - 87)*base;  
                            
                        } 
                            n=n+4;
                    int stored_dec_val;
                        //int binary_array[32];
                        stored_dec_val=dec_val;           // here set early output  as input for the decimal to binaray procces
                        
                        for (t;t>q;t--){
                            binary_array[t]=stored_dec_val%2;
                            stored_dec_val=stored_dec_val/2;
                        }
                        t=n;
                        q=t-4;
                        
                         
                    }
                     
                    int first_value;
                    int exponent_value=0;
                    int power;
                    long double power_value=1;
                    int max=128;
                    double min=0.5;
                    double desimal_value=0;
                    if(binary_array[0]==0){
                        first_value=1;
                    }else{
                        first_value=-1;
                    }
                    for(int I=1;I<=8;I++){
                        if(binary_array[I]==1){
                            exponent_value=exponent_value+max;
                        }
                        max=max/2;
                    }
                    power=exponent_value-127;
                    for(int R=0;R<power;R++){
                        power_value=power_value*2;
                    }
                    for(int T=9;T<32;T++){
                        if(binary_array[T]==1){
                            desimal_value=desimal_value+min;
                        }
                        min=min/2;
                    }
                    double flo_value=first_value*power_value*(desimal_value+1);
                            fprintf(stdout,"%0.2lf\n",flo_value);

                
                }else if((argv[3][16]=='\0')){
                    fprintf(stderr,"ERROR: This conversion is not possible.\n");
                }else{
			fprintf(stderr,"ERROR: The input size is wrong.\n");
			return 0;
		}
    }else if((argv[1][1])=='H'&&(argv[2][1])=='D') {
        for(int n=0;argv[3][n]!='\0';n++){
                    if(!((argv[3][n]>='A'&&argv[3][n]<='F')||(argv[3][n]>='0'&&argv[3][n]<='9'))){
                        fprintf(stderr,"ERROR: Input format error at location %d.\n",n);
                        return 0;
                    }
                }
             if((argv[3][16]=='\0')){
                    char hexVal[31];
                    
                    
                    for (int k=0; argv[3][k]!='\0'; k++){
                        hexVal[k]=argv[3][k];             // here store ever input digit as character 
                    } 
                    int g;
                    int base = 1; 
                    
                    long long int dec_val = 0; 
                    int t=3,q=-1,n=3;
                     int binary_array[64];
                    for (int i=0;argv[3][i]!='\0'  ; i++)         // here agine hexa to desimal changing procces but only one digit
                    {  
                        if (hexVal[i]>='0' && hexVal[i]<='9') 
                        { 
                            dec_val = (hexVal[i] - 48)*base; 
                        } 
                        else if (hexVal[i]>='A' && hexVal[i]<='F') 
                        { 
                            dec_val = (hexVal[i] - 55)*base;  
                            
                        }else if(hexVal[i]>='a' && hexVal[i]<='f') 
                        { 
                            dec_val = (hexVal[i] - 87)*base;  
                            
                        } 
                            n=n+4;
                    int stored_dec_val;
                        //int binary_array[32];
                        stored_dec_val=dec_val;           // here set early output  as input for the decimal to binaray procces
                        
                        for (t;t>q;t--){
                            binary_array[t]=stored_dec_val%2;
                            stored_dec_val=stored_dec_val/2;
                        }
                        t=n;
                        q=t-4;
                        
                         
                    }
                    /*int j=0; 
                    while(j<32)	{
                        printf("%d",binary_array[j]);           
                        j=j+1;
                        }
                     printf("\n");*/
                    int first_value;
                    int exponent_value=0;
                    int power;
                    long double power_value=1;
                    int max=1024;
                    double min=0.5;
                    double desimal_value=0;
                    if(binary_array[0]==0){
                        first_value=1;
                    }else{
                        first_value=-1;
                    }
                    for(int I=1;I<=11;I++){
                        if(binary_array[I]==1){
                            exponent_value=exponent_value+max;
                        }
                        max=max/2;
                    }
                    power=exponent_value-1023;
                    for(int R=0;R<power;R++){
                        power_value=power_value*2;
                    }
                    for(int T=12;T<64;T++){
                        if(binary_array[T]==1){
                            desimal_value=desimal_value+min;
                        }
                        min=min/2;
                    }
                    double flo_value=first_value*power_value*(desimal_value+1);
                            fprintf(stdout,"%0.2lf",flo_value);

                
                }else if((argv[3][8]=='\0')){
                    fprintf(stderr,"ERROR: This conversion is not possible.\n");
                }else{
			fprintf(stderr,"ERROR: The input size is wrong.\n");
			return 0;
		}
    }else if((argv[1][1])=='D'&&(argv[2][1])=='D') {
        int sign=1;
        int dot=0;
        int m=0;
        if(argv[3][0]=='-'){
                    sign=-1;
                    m=m+1;	
                }
                for( m;argv[3][m]!='\0' ;m++){
                    if(((argv[3][m]>=48)&&(argv[3][m]<=57))||(argv[3][m]==46)||(argv[3][m]=='\0')){
                        if((argv[3][m]==46)){
                            dot++;
                        }
                    }else{
                         fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                         return 0;
                    }
                    if(dot>1){
                        fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                        return 0;
                    }                }
        
        //printf("%s\n",argv[3]);
        long double val;
         val=myatof(argv[3]);
         fprintf(stdout,"%Lf\n",val);
    }else if((argv[1][1])=='D'&&(argv[2][1])=='B') {
        long double float_value,desimal_value;
				int array1[64],array2[64],array3[11],hexa_array[64];
				int p, exponent,b,exponent_value;
                int r,t=10,r1,t1=10,r2,r3,r4,r5,r6,r7,r8,r9,r10,dot=0,h,j=0;
                 int sign=1;
                int m=0;
                if(argv[3][0]=='-'){
                    sign=-1;
                    m=m+1;	
                }
                for( m;argv[3][m]!='\0' ;m++){
                    if(((argv[3][m]>=48)&&(argv[3][m]<=57))||(argv[3][m]==46)||(argv[3][m]=='\0')){
                        if((argv[3][m]==46)){
                            dot++;
                        }
                    }else{
                         fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                         return 0;
                    }
                    if(dot>1){
                        fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                        return 0;
                    }                }
				float_value=myatof(argv[3]);                    //char to int changing 
				int integer_value=(int)float_value;         // here casting to geting int part in float value 
				desimal_value=float_value-integer_value;               // here geting 0.  values
				if(float_value<0){        // here if our input is negative value we changing to positive for rest of operations are same as + number thats why     
					integer_value=-integer_value;
					desimal_value=-desimal_value;
				}
			
				int i;
				for( i=0;i<64;i++){                  // here int part converting as a binaryval
					array1[i]=integer_value%2;
					integer_value=integer_value/2;
					
					if(integer_value==0){                  // loop break condition 
						 b=i;            // here i store condition breaking i value 
						break;          
					}
				}
			 
				for(p=0;p<64;p++){                // here i converting 0. vlues in binary
					desimal_value=desimal_value*2;
					array2[p]=desimal_value/1;
					if(desimal_value>1.0000){                // while converting 0. value go 1. value here agine making that valu as a 0. value
						desimal_value=desimal_value-1;
					}
					
					if(desimal_value==1.0000){              // loop break condition 
						int z=p;                     // here I store condition breaking P value 
						break;
					}
				
				
				}
			
				if(float_value>0){               // here first stat float value printing as a binary 
					hexa_array[0]=0;          // if input is positive first digit is 0
				} else {
					  hexa_array[0]=1;   // if input negative first digit  is 1
				}
				if((i==0)&&(array1[0]==1)){            // here 1.1111 this format binary are changing
					exponent=0;            // here expont making value is 0
					exponent_value=1023;             //ex1=ex+127
					for (r=0;r<12;r++){         // that ex1 vlue convert to binary
					array3[r]=exponent_value%2;
					exponent_value=exponent_value/2;
					} h=0;	
					while(t>=0)	{          // here print exponent value 
                    h=h+1;
					hexa_array[h]=array3[t];
					t=t-1;
					}if(52>=p){
                        for(r6=0;r6<=p;r6++){       // here .1110 like as values prining 
                            hexa_array[r6+12]=array2[r6];
                        }
                        for(r7=p+12;r7<63;r7++){        // here rest of 32 digit for filling zeros
                            array2[r7]=0;
                            hexa_array[r7]=array2[r7];
                        }
                    }else{
                        for(r6=0;r6<52;r6++){       // here .1110 like as values prining 
                            hexa_array[r6+12]=array2[r6];
                        }
                        int l;
                        if(array2[52]==1){
                            for(l=63;hexa_array[l]!=0;l--){
                                hexa_array[l]=0;
                            }
                            hexa_array[l]=1;
                        }
                    }
				}
				else if((i==0)&&(array1[0]==0)){    // this is 2ed possiblity 0.1101 like values converting 
					for(r2=0;r2<63;r2++){
						if (array2[r2]==1){
							r3=r2;                // here where it loop break that vlue r2 is storing 
							break;
						}
					}
					exponent=-(r3+1);          //for exponent value 
					exponent_value=1023+exponent;           
					for (r1=0;r1<12;r1++){      // exponent convert into binary     
					array3[r1]=exponent_value%2;
					exponent_value=exponent_value/2;
					} 
                    h=0;
					while(t1>=0)	{          // exponent for binaray value printing
                    h=h+1; 
					hexa_array[h]=array3[t1];
					t1=t1-1;
					}
                    h=11;
                    if(52>=p){
                        for(r4=(r3+1);r4<=p;r4++){          //0.1101    values printing 
                            h=h+1;
                            hexa_array[h]=array2[r4];
                        }
                        for(r5=(p+1);r5<(54-p+r3);r5++){         // rest of 32 digits printing as 0 
                            array2[r5]=0;
                            h=h+1;
                            hexa_array[h]=array2[r5];
                        }
                    }else{
						if((p-r3)>52){
							for(r4=(r3+1);r4<=(r3+52);r4++){          //0.1101    values printing 
                            h=h+1;
                            
                            hexa_array[h]=array2[r4];
                            } 
                            if(array2[r3+53]==1){
								
								int l;
								for(l=63;hexa_array[l]!=0;l--){
									hexa_array[l]=0;
								}
								hexa_array[l]=1;
							}
						}else{
							for(r4=(r3+1);r4<=p;r4++){          //0.1101    values printing 
                            h=h+1;
                            hexa_array[h]=array2[r4];
                            
                        }
                        for(r5=(p+10-r3);r5<(63);r5++){         // rest of 32 digits printing as 0 
                            array2[r5]=0;
                            h=h+1;
                            hexa_array[h]=array2[r5];
                        } 
                        
						}
                       
                    }
				}
				else{                       // 3ed posibility 111.0101 like values converting 
					exponent=i;
					exponent_value=1023+exponent;                // here exponent value converting
					for (r=0;r<12;r++){
					array3[r]=exponent_value%2;
					exponent_value=exponent_value/2;
					} 
                    h=0;	
					while(t>=0)	{
					 h=h+1; 
					hexa_array[h]=array3[t];             // exponent value prinrinting 
					t=t-1;
					}
                    h=11;
                    if(52>=i){
                        for(r10=i-1;r10>=0;r10--){               //.11000 like value printing 
                            h=h+1;
                            hexa_array[h]=array1[r10];
                        }
                        if(52-i>=p){
                            for(r8=0;r8<=p;r8++){               //.11000 like value printing 
                                h=h+1;
                                hexa_array[h]=array2[r8];
                            }
                            for(r9=1;r9<(52-p-i);r9++){        // here rest of value prining for 32 digit
                                array2[r9]=0;
                                h=h+1;
                                hexa_array[h]=array2[r9];
                            }
                        }else{
                            for(r8=0;r8<=52-i;r8++){               //.11000 like value printing 
                                h=h+1;
                                hexa_array[h]=array2[r8];
                            }
                        }
				}else{
                    for(r10=i-1;r10>i-53;r10--){               //.11000 like value printing 
                        h=h+1;
                            hexa_array[h]=array1[r10];
                        }
                        if(array1[i-53]==1){
                            int l=(63);
                            while(hexa_array[l]!=0){
                                hexa_array[l]=0;
                                //printf("\n%d\n",hexa_array[l]);
                                l=l-1;
                                    }
                                    hexa_array[l]=1;
                        }
                }
                }
                int y=0;
                while(y<64){
                    fprintf(stdout,"%d",hexa_array[y]);
                    y=y+1;
                }
                fprintf(stdout,"\n");
    }/*else if((argv[1][1])=='D'&&(argv[2][1])=='I') {
        
    }*/else if(((argv[1][1])=='D'&&(argv[2][1])=='F')||((argv[1][1])=='D'&&(argv[2][1])=='I')||((argv[1][1])=='F'&&(argv[2][1])=='D')) {
         int dot=0;
        int m=0;
        int sign=1;
        if(argv[3][0]=='-'){
             sign=-1;
             m=m+1;	
                }
        for(m;argv[3][m]!='\0' ;m++){
            if(((argv[3][m]>=48)&&(argv[3][m]<=57))||(argv[3][m]==46)||(argv[3][m]=='\0')){
                        if((argv[3][m]==46)){
                            dot++;
                        }
                    }else{
                         fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                         return 0;
                    }
             if(dot>1){
                        fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                        return 0;
                    }        
        }
        fprintf(stderr,"ERROR: This conversion is not possible.\n");
        return 0;
    }else if((argv[1][1])=='D'&&(argv[2][1])=='H') {
          long double float_value,desimal_value;
				int array1[64],array2[64],array3[11],hexa_array[64];
				int p, exponent,b,exponent_value;
                int r,t=10,r1,t1=10,r2,r3,r4,r5,r6,r7,r8,r9,r10,dot=0,h,j=0;
                 int sign=1;
                int m=0;
                if(argv[3][0]=='-'){
                    sign=-1;
                    m=m+1;	
                }
                for( m;argv[3][m]!='\0' ;m++){
                    if(((argv[3][m]>=48)&&(argv[3][m]<=57))||(argv[3][m]==46)||(argv[3][m]=='\0')){
                        if((argv[3][m]==46)){
                            dot++;
                        }
                    }else{
                         fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                         return 0;
                    }
                    if(dot>1){
                        fprintf(stderr,"ERROR: Input format error at location %d.\n",m);
                        return 0;
                    }                }
				float_value=myatof(argv[3]);                    //char to int changing 
				int integer_value=(int)float_value;         // here casting to geting int part in float value 
				desimal_value=float_value-integer_value;               // here geting 0.  values
				if(float_value<0){        // here if our input is negative value we changing to positive for rest of operations are same as + number thats why     
					integer_value=-integer_value;
					desimal_value=-desimal_value;
				}
			
				int i;
				for( i=0;i<64;i++){                  // here int part converting as a binaryval
					array1[i]=integer_value%2;
					integer_value=integer_value/2;
					
					if(integer_value==0){                  // loop break condition 
						 b=i;            // here i store condition breaking i value 
						break;          
					}
				}
			 
				for(p=0;p<64;p++){                // here i converting 0. vlues in binary
					desimal_value=desimal_value*2;
					array2[p]=desimal_value/1;
					if(desimal_value>1.0000){                // while converting 0. value go 1. value here agine making that valu as a 0. value
						desimal_value=desimal_value-1;
					}
					
					if(desimal_value==1.0000){              // loop break condition 
						int z=p;                     // here I store condition breaking P value 
						break;
					}
				
				
				}
			
				if(float_value>0){               // here first stat float value printing as a binary 
					hexa_array[0]=0;          // if input is positive first digit is 0
				} else {
					  hexa_array[0]=1;   // if input negative first digit  is 1
				}
				if((i==0)&&(array1[0]==1)){            // here 1.1111 this format binary are changing
					exponent=0;            // here expont making value is 0
					exponent_value=1023;             //ex1=ex+127
					for (r=0;r<12;r++){         // that ex1 vlue convert to binary
					array3[r]=exponent_value%2;
					exponent_value=exponent_value/2;
					} h=0;	
					while(t>=0)	{          // here print exponent value 
                    h=h+1;
					hexa_array[h]=array3[t];
					t=t-1;
					}if(52>=p){
                        for(r6=0;r6<=p;r6++){       // here .1110 like as values prining 
                            hexa_array[r6+12]=array2[r6];
                        }
                        for(r7=p+12;r7<63;r7++){        // here rest of 32 digit for filling zeros
                            array2[r7]=0;
                            hexa_array[r7]=array2[r7];
                        }
                    }else{
                        for(r6=0;r6<52;r6++){       // here .1110 like as values prining 
                            hexa_array[r6+12]=array2[r6];
                        }
                        int l;
                        if(array2[52]==1){
                            for(l=63;hexa_array[l]!=0;l--){
                                hexa_array[l]=0;
                            }
                            hexa_array[l]=1;
                        }
                    }
				}
				else if((i==0)&&(array1[0]==0)){    // this is 2ed possiblity 0.1101 like values converting 
					for(r2=0;r2<63;r2++){
						if (array2[r2]==1){
							r3=r2;                // here where it loop break that vlue r2 is storing 
							break;
						}
					}
					exponent=-(r3+1);          //for exponent value 
					exponent_value=1023+exponent;           
					for (r1=0;r1<12;r1++){      // exponent convert into binary 
					array3[r1]=exponent_value%2;
					exponent_value=exponent_value/2;
					} 
                    h=0;
					while(t1>=0)	{          // exponent for binaray value printing
                    h=h+1; 
					hexa_array[h]=array3[t1];
					t1=t1-1;
					}
                    h=11;
                    if(52>=p){
                        for(r4=(r3+1);r4<=p;r4++){          //0.1101    values printing 
                            h=h+1;
                            hexa_array[h]=array2[r4];
                        }
                        for(r5=(p+1);r5<(54-p+r3);r5++){         // rest of 32 digits printing as 0 
                            array2[r5]=0;
                            h=h+1;
                            hexa_array[h]=array2[r5];
                        }
                    }else{
						if((p-r3)>52){
							for(r4=(r3+1);r4<=(r3+52);r4++){          //0.1101    values printing 
                            h=h+1;
                            
                            hexa_array[h]=array2[r4];
                            } 
                            if(array2[r3+53]==1){
								
								int l;
								for(l=63;hexa_array[l]!=0;l--){
									hexa_array[l]=0;
								}
								hexa_array[l]=1;
							}
						}else{
							for(r4=(r3+1);r4<=p;r4++){          //0.1101    values printing 
                            h=h+1;
                            hexa_array[h]=array2[r4];
                            
                        }
                        for(r5=(p+10-r3);r5<(63);r5++){         // rest of 32 digits printing as 0 
                            array2[r5]=0;
                            h=h+1;
                            hexa_array[h]=array2[r5];
                        } 
                        
						}
                       
                    }
				}
				else{                       // 3ed posibility 111.0101 like values converting 
					exponent=i;
					exponent_value=1023+exponent;                // here exponent value converting
					for (r=0;r<12;r++){
					array3[r]=exponent_value%2;
					exponent_value=exponent_value/2;
					} 
                    h=0;	
					while(t>=0)	{
					 h=h+1; 
					hexa_array[h]=array3[t];             // exponent value prinrinting 
					t=t-1;
					}
                    h=11;
                    if(52>=i){
                        for(r10=i-1;r10>=0;r10--){               //.11000 like value printing 
                            h=h+1;
                            hexa_array[h]=array1[r10];
                        }
                        if(52-i>=p){
                            for(r8=0;r8<=p;r8++){               //.11000 like value printing 
                                h=h+1;
                                hexa_array[h]=array2[r8];
                            }
                            for(r9=1;r9<(52-p-i);r9++){        // here rest of value prining for 32 digit
                                array2[r9]=0;
                                h=h+1;
                                hexa_array[h]=array2[r9];
                            }
                        }else{
                            for(r8=0;r8<=52-i;r8++){               //.11000 like value printing 
                                h=h+1;
                                hexa_array[h]=array2[r8];
                            }
                        }
				}else{
                    for(r10=i-1;r10>i-53;r10--){               //.11000 like value printing 
                        h=h+1;
                            hexa_array[h]=array1[r10];
                        }
                        if(array1[i-53]==1){
                            int l=(63);
                            while(hexa_array[l]!=0){
                                hexa_array[l]=0;
                                //printf("\n%d\n",hexa_array[l]);
                                l=l-1;
                                    }
                                    hexa_array[l]=1;
                        }
                }
                }
               /* while(j<32)	{          //array printing loop 
                printf("%d",hexa_array[j]);
                j=j+1;
                }*/
                fprintf(stdout,"0x");
                  int I=0,u=0;
                for(int T=0;T<16;T++)
				{   int max=8;
					int desimal_value=0;
					for(I;I<u+4;I++)
					{
						if(hexa_array[I]==1){
							desimal_value=desimal_value+max;
							//printf("\nd is %d ,max is %d ,i is %d\n u is %d",desimal_value,max,I,u);
						}
						max=max/2;
					}
					u=I;
					//printf("\n t is %d,i is %d\n",T,I);
					if(desimal_value<10){
						fprintf(stdout,"%d",desimal_value);
					}
					else if(desimal_value==10){
						fprintf(stdout,"A");
					}
					else if(desimal_value==11){
						fprintf(stdout,"B");
					}
					else if(desimal_value==12){
						fprintf(stdout,"C");
					}
					else if(desimal_value==13){
						fprintf(stdout,"D");
					}
					else if(desimal_value==14){
						fprintf(stdout,"E");
					}
					else if(desimal_value==15){
						fprintf(stdout,"F");
					}
				}
				fprintf(stdout,"\n");
    }
}
 long long int myatoi(char argv[]){
long long int integer_value=0;
int i=0;
int sign=1;
if(argv[0]=='-'){
	sign=-1;
	i=i+1;	
}
for(i;argv[i]!='\0';++i){
    integer_value=((integer_value*10)+(argv[i]-'0'));
	//printf("%d\n",integer_value);
}
return integer_value*sign;
}
 long double myatof(char argv[]){
long long int integer_value=0;
int i=0;
double power=1;
int sign=1;
if(argv[0]=='-'){
	sign=-1;
	i=i+1;	
}
for(i;(argv[i]!='.')&&(argv[i]!='\0');++i){
    integer_value=((integer_value*10)+(argv[i]-'0'));
	//printf("is %lld\n",integer_value);
}
for (int j=i;j>=0;j--){
    if(argv[i]=='.'){
        for(int t=i+1;argv[t]!='\0';++t){
    //printf("argv is %d\n t is %d\n ",argv[t],t);
    integer_value=((integer_value*10)+(argv[t]-'0'));
    power=power*0.1;
	//printf("%lld\n",integer_value);
}
return integer_value*sign*power;
    }else{
        return integer_value*sign*power;
    }
}

}