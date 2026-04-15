#include <stdio.h>
#include <string.h>
void characterCount()
{
    char data[100];
    printf("Enter data: ");
    gets(data);
    printf("Framed Data: %d%s\n", strlen(data), data);
}

void characterStuffing()
{
    char data[100];
    int i;
    printf("Enter data: ");
    gets(data);
    printf("Framed Data: F");
    for(i = 0; i < strlen(data); i++)
    {
        if(data[i] == 'F' || data[i] == 'E')
            printf("E");
        printf("%c", data[i]);
    }
    printf("F\n");
}

void bitStuffing()
{
    char data[100];
    int i, count = 0;
    printf("Enter bit stream: ");
    gets(data);
    printf("Framed Data: 01111110");
    for(i = 0; i < strlen(data); i++)
    {
        if(data[i] == '1')
        {
            count++;
            printf("1");
            if(count == 5)
            {
                printf("0");
                count = 0;
            }
        }
        else
        {
            printf("0");
            count = 0;
        }
    }
    printf("01111110\n");
}

int main()
{
    int choice;
    printf("1. Character Count Framing\n");
    printf("2. Character Stuffing\n");
    printf("3. Bit Stuffing\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

    switch(choice)
    {
        case 1: characterCount(); break;
        case 2: characterStuffing(); break;
        case 3: bitStuffing(); break;
        default: printf("Invalid choice");
    }
    return 0;
}

