#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
 int nf,N;
 int no_tr=0;
 srand(time(NULL));
 printf("Enter the number of frames : ");
 scanf("%d",&nf);
 printf("\nEnter the Window Size : ");
 scanf("%d",&N);
 int i=1;
 while(i<=nf)
 {
	 int x=0;
	 for(int j=i;j<i+N && j<=nf;j++)
	 {
	    printf("\nSent Frame %d", j);
	    no_tr++;
	 }
	 
	 for(int j=i;j<i+N && j<=nf;j++)
	 {
	     int flag = rand()%2;
	     if(!flag)
	         {
	            printf("\nAcknowledgment for Frame %d received.",j);
	            x++;
	         }
	     else
	         {   
			 	printf("\nFrame %d Not Received. ",j);
	            printf("Retransmitting Window");
	            break;
	         }
	 }
	 i+=x;
 }
 printf("\n\nTotal number of transmissions : %d",no_tr);
 return 0;
}

