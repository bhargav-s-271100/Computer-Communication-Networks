#include<stdio.h>
#include <time.h>
#include <cstdlib>
#include<ctime>
#include <unistd.h>
#define RESPONSE_TIME 5

using namespace std;

// Timer class to count the time taken for receiver to respond and check if there is a timeout
class timer 
{
    private:
    	unsigned long begTime;
     
    public:
    	void start() 
			{
    			begTime = clock();
    		}
		unsigned long elapsedTime() 
			{
      			return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
    		}
   		bool isTimeout(unsigned long seconds)
			{
	      		return seconds > RESPONSE_TIME;
	     	}
};

// Function to display an n-bit frame
void display_frame(int arr[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%d", arr[i]);
}

int main()
{
	int frames[][6] = {{0,1,0,1,1,0},{0,0,0,1,1,1},{1,1,1,0,0,0},{0,0,0,0,0,0},{1,1,1,1,1,1}}; // the 5 frames to be sent
	int Sn = 0, prev_Sn = 0;
	srand(time(NULL));
	timer t;
	printf("There are 5 frames to be sent\n");
	int count = 0;
	bool delay = false;
	printf("Sender\t\t\t\t\tReceiver\n");
	do
	{
		bool timeout = false;
		printf("Sending frame: {%d : ", count+1);
		display_frame(frames[count], 6);
		printf("}");
		t.start();
		if(rand()%2)
	    {
	        int to = 24600 + rand()%(64000 - 24600)  + 1;
	        for(int i=0;i<64000;i++)
	            for(int j=0;j<to;j++) {} 
	    }
	    else
	    	Sn = (rand()%2)?1:0;
	    	
	    if(!t.isTimeout(t.elapsedTime()) && Sn != prev_Sn) //The frame is received correctly
	    {
	    	printf("\t\tReceived frame: {%d : ", count+1);
	    	display_frame(frames[count], 6);
	    	printf("}");
		}
	    else if(!t.isTimeout(t.elapsedTime()) && Sn == prev_Sn)
	    {
	    	printf("\t\tReceived frame is Corrupted. Resending frame.\n"); //The frame received is corrupted
	    	printf("\n");
	    	prev_Sn = Sn;
	    	continue;
		}
		else if(t.isTimeout(t.elapsedTime())) //The frame is not received
		{
			printf("\t\tFrame not received. Resending frame.\n");
	    	printf("\n");
	    	prev_Sn = Sn;
	    	continue;
		}
		prev_Sn = Sn;
		printf("\n");
		count++;	
	}while(count<5);

	return 0;
}
