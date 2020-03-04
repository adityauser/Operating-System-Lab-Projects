#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int tph,philname[20],status[20],howhung,hu[20],cho;
void one(){
	int pos,x,i;
	printf("\nAllow one philosopher to eat at a time\n");
	for(i=0;i<howhung;i++){
		printf("\nP%d is granted to eat",philname[hu[i]-1]);
		for(x=i+1;x<howhung;x++)
		printf("\nP%d is waiting",philname[hu[x]-1]);
	}
	printf("\n");
}
void two(){
	int i,j,s=0,t,r,x;
	printf("\nAllow two philosophers to eat at same time\n");
	for(i=0;i<howhung;i++)
	for(j=i+1;j<howhung;j++)
	if(abs(hu[i]-hu[j])>1&&abs(hu[i]-hu[j])!=4){
		printf("\nCombination %d \n",(s+1));
		t=hu[i];
		r=hu[j];
		s++;
		printf("\nP%d and P%d are granted to eat",philname[hu[i]-1],philname[hu[j]-1]);
		for(x=0;x<howhung;x++)
		if(hu[x]!=t&&hu[x]!=r)
		printf("\nP%d is waiting\n",philname[hu[x]-1]);
	}
}
int main(){
	printf("\nEnter the total number of philosophers :");
	scanf("%d",&tph);
	for(int i=0;i<tph;i++){
		philname[i]=(i+1);
		status[i]=1;
	}
	printf("How many are hungry : ");
	scanf("%d",&howhung);
	if(howhung==tph){
		printf("\nAll are hungry.. \n Deadlock stage will occur");
		exit(0);
	}
	else{
		for(int i=0;i<howhung;i++){
			printf("Enter philosopher %d position: ",i+1);
			scanf("%d",&hu[i]);
			status[hu[i]]=2;
		}
		do{
			printf("1. One at a time 2. Two at a time 3. Exit\nEnter your choice: ");
                        scanf("%d",&cho);
			switch(cho){
				case 1: one(); break;
				case 2: two(); break;
				case 3: exit(0);
				default: printf("Invalid option\n");
			}
			break;
		}while(1);
	}
}