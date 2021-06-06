#include<stdio.h>
#include<conio.h>
int main(void)
{
int data[50],div[16],rem[16];
int datalen, divlen, i,j,k;
int ch;
printf("Enter the data: ");	// To take input array
i = 0;
while((ch = fgetc(stdin))!= '\n') // This loop stores the input data in the array data
{
if (ch == '1')
data[i] = 1;
else
data[i] = 0;
i++;
}
datalen = i;	//Length of input message/data
printf("\nEnter the divisor: ");	//Polynomial divisor
i = 0;
while((ch = fgetc(stdin)) != '\n')	// This loop stores the input polynomial/divisor
{
if(ch == '1')
div[i] = 1;
else
div[i] = 0;
i++;
}
divlen = i;	//Length of the divider
for(i = datalen ; i < datalen + divlen - 1 ; i++) //Appending zeros to the data for binary division
data[i] = 0;
datalen = datalen + divlen - 1;	//modified data length
for(i = 0 ; i < divlen ; i++)
rem[i] = data[i];	// Considering small array for division
k = divlen-1;
while(k < datalen)	// length of divider should be smaller than the length of dividend
{
if(rem[0] == 1)	// If the first bit is 1, do xOR operation of dividend and divisor
{
for(i = 0 ; i < divlen ; i++)
rem[i] = rem[i] ^ div[i];
}
else	// If first bit is not zero
{
if(k == datalen-1)	//Check the condition for division
break;	// Exit the while loop
for(i = 0 ; i < divlen-1 ; i++) // to consider the next part of the data left shift once
{
rem[i] = rem[i+1];
printf("%d",rem[i]);
}
rem[i] = data[++k];	//stores the next bit
printf("%d\n",rem[i]);
 }
}
j=1;
for(i = datalen - divlen + 1 ; i < datalen ; i++)	// Replacing appended )'s with the check sum
data[i] = rem[j++];
printf("\nThe data to be sent is\n");	//Display output
 for(i = 0 ; i < datalen ; i++)
printf("%d",data[i]);
getch();
return 0;
}
