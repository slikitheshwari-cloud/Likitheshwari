#include <stdio.h>
#include <string.h>

void integers()
{
    int n, i, flag = 0, key;
    int arr[50];  // FIXED

    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    printf("\nEnter integers: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            flag = 1;
            break;
        }
    }

    if(flag)
        printf("%d found at position %d\n", key, i + 1);
    else
        printf("%d not found\n", key);
}

void floatlinear()
{
    int n, i, flag = 0;
    float arr[50], key;  // FIXED

    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    printf("\nEnter floating values: ");
    for(i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    printf("\nEnter value to search: ");
    scanf("%f", &key);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            flag = 1;
            break;
        }
    }

    if(flag)
        printf("%f found at position %d\n", key, i + 1);
    else
        printf("%f not found\n", key);
}

void characters()
{
    int n, i, flag = 0;
    char arr[50], key;

    printf("\nEnter number of characters: ");
    scanf("%d", &n);

    printf("\nEnter characters: ");
    for(i = 0; i < n; i++)
        scanf(" %c", &arr[i]);

    printf("\nEnter character to search: ");
    scanf(" %c", &key);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            flag = 1;
            break;
        }
    }

    if(flag)
        printf("\n'%c' found at position %d\n", key, i + 1);
    else
        printf("\n'%c' not found\n", key);
}

void strings()
{
    int n, i, flag = 0;
    char arr[50][50], key[50];

    printf("\nEnter number of strings: ");
    scanf("%d", &n);

    printf("\nEnter strings: ");
    for(i = 0; i < n; i++)
        scanf("%s", arr[i]);

    printf("\nEnter string to search: ");
    scanf("%s", key);

    for(i = 0; i < n; i++)
    {
        if(strcmp(arr[i], key) == 0)
        {
            flag = 1;
            break;
        }
    }

    if(flag)
        printf("%s found at position %d\n", key, i + 1);
    else
        printf("%s not found\n", key);
}

int main()
{
    int choice;
    printf("\n1. Integer Searching \n2. Float Searching \n3. Character Searching \n4. String Searching");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
      switch(choice)
      {
         case 1: integers(); break;
         case 2: floatlinear(); break;
         case 3: characters(); break;
         case 4: strings(); break;
         default: printf("\nInvalid choice"); break;
       }
    }
    
	
}

