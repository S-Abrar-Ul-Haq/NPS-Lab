#include<stdio.h>
    #include<stdlib.h>
    void main() {
    	int data[7],rec[7],i,r1,r2,r3,c;
    	printf("Enter data bits:  ");
    	scanf("%d%d%d%d",&data[0],&data[1],&data[2],&data[4]);

    	data[6]=data[0]^data[2]^data[4];
    	data[5]=data[0]^data[1]^data[4];
    	data[3]=data[0]^data[1]^data[2];
	
	printf("\nThe redundant bits are: %d %d %d\n", data[3], data[5], data[6]);
    	printf("\nThe encoded bits are: ");
    	for (i=0;i<7;i++) {
    		printf("%d ",data[i]);
    	}


    	printf("\nEnter the received data bits: ");
    	for (i=0;i<7;i++) {
    		scanf("%d",&rec[i]);
    	}
    	r1=rec[6]^rec[4]^rec[2]^rec[0];
    	r2=rec[5]^rec[4]^rec[1]^rec[0];
    	r3=rec[3]^rec[2]^rec[1]^rec[0];
    	c=r3*4+r2*2+r1 ;

    	if(c==0) {
    		printf("No error, everything's fine\n");
    	} else {
    		printf("\nError at the postion: %d\nThe correct message is ",c);
    		if(rec[7-c]==0)
            {
                rec[7-c]=1;
            }
            else{
                rec[7-c]=0;

            }
    		for (i=0;i<7;i++) {
    			printf("%d ",rec[i]);
    		}
    	}
	printf("\n");
    	
    }
