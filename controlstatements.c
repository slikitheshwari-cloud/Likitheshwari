#include <stdio.h>
void if_statement()
{
    int a=10,b=15;
    if(a>b)
    {
        printf("\n a is big");
    }
}
void ifelse_statement()
{
    int a=10,b=15;
    if(a>b)
    {
        printf("\n a is big");
    }
    else
    {
    printf("\n b is big");    
    }
    
}
void nestedstatement()
{
    int a=10;
    if(a>18)
    {
        printf("\n eligible to vote");
    }
     if(a==18)
     {
         printf("\n you can vote");
     }
    else
    {
     printf("\n your not eligible to vote");   
    } 
}
void elseif()
{
    int a=10,b=15,c=20;
    if(a>b&&a>c)
    {
        printf("\n a is big");
    }
    else if(b>c)
    {
        printf("\n enter b is big");
    }
    else{
        printf("\n c is big");
    }
}
void switchstatement()
{
    int n;
    printf("\n enter n value");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            printf("\n monday");
            break;
        case 2:
            printf("\n tuesday");
            break;
        case 3:
            printf("\n wednesday");
            break;
        default:
            printf("\n invalid number");
            break;
    }
}
void forstatement()
{
    int i=0;
    for(i=0;i<5;i++)
    {
        printf("%d",i);
    }
}
void whilestatement()
{
    int i=0;
    while(i<5)
    {
        printf("%d",i);
        i++;
    }
}
void dowhilestatement()
{
    int i;
    do
    {
     printf("whiles of i:%d",i);
     i++;
    }while(i<5);
}
void breakstatement()
{
    int i,key;
    key=3;
    for(i=0;i<=5;i++)
    {
      if(i==3)
      {
          printf("%d",i+1);
          break;
      }
    }
}
void continuestatement()
{
    int i,key;
    key=3;
    for(i=0;i<=5;i++)
    {
      if(i==3)
      {
          continue;
      }
      printf("%d",i);
    }
}
void gotostatement()
{
    int n=26;
    if(n%2==0)
    goto even;
    else
    goto odd;
    even:
    printf("\n even:%d",n);
    odd:
    printf("\n odd:%d",n);
}

int main()
{
    int ch,ch1;
    printf("\n***control statements***");
    printf("\n 1.conditional,2.Lopping,3.jumping");
    printf("\n enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("\n***conditonal***");
        printf("\n 1.if,2.ifelse,3.nested,4.elseif,5.switch");
        printf("\n enter your choice: ");
        scanf("%d",&ch1);
         switch(ch1)
        {
            case 1:
            if_statement();
            break;
            case 2:
            ifelse_statement();
            break;
            case 3:
            nestedstatement();
            break;
            case 4:
            elseif();
            break;
            case 5:
            switchstatement();
            break;
            default:
            printf("\n invalid number");
            break;
        }
        break;
        case 2:
        printf("\n Looping statements");
        printf("\n ***1.for,2.while,3.dowhile***");
        printf("\n enter your choice: ");
        scanf("%d",&ch1);
         switch(ch1)
         {
            case 1:
            forstatement();
            break;
            case 2:
            whilestatement();
            break;
            case 3:
            dowhilestatement();
            break;
            default:
            printf("\n invalid number");
            break;
         }
         break;
        case 3:
        printf("\n jumping statements");
        printf("1.break,2.continue,3.goto");
        printf("enter your choice: ");
        scanf("%d",&ch1);
         switch(ch1)
        {
            case 1:
            breakstatement();
            break;
            case 2:
            continuestatement();
            break;
            case 3:
            gotostatement();
            break;
            default:
            printf("\n invalid number");
            break;
        }
         break;
        default:
        printf("\n invalid number");
        break;
    }
    return 0;
}