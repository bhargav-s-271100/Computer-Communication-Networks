#include<stdio.h>
 
char* encrypt(char* text, int s)
{
 
    for (int i=0; text[i] != '\0';i++)
    {

        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = char(int(text[i]+s-65)%26 +65);
 
    else
        text[i] = char(int(text[i]+s-97)%26 +97);
    }
 
    return text;
}
 
char* decrypt(char* text, int s)
{
    
    for (int i=0;text[i] != '\0';i++)
    {

        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = char(int(text[i]-s-65+26)%26 +65);
 
    else
        text[i] = char(int(text[i]-s-97+26)%26 +97);
    }
 
    return text;
}

int main()
{
    char message[100];
	int key;
	
	printf("Enter a message to encrypt: ");
	gets(message);
	printf("Enter key: ");
	scanf("%d", &key);
	
	printf("Encrypted message: %s", encrypt(message, key));
	printf("\nDecrypted message: %s", decrypt(message, key));
	
    return 0;
}
