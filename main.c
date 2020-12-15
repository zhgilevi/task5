#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void RevPrint(int a){
    if (a<10){
        printf("%d",a);
        return;
    }
    printf("%d",a%10);
 RevPrint(a/10);

}

int is_simple(int a,int del){

if (del==1)
    return 0;


if (a%del==0 && a!=del)
    return 1;

return is_simple(a,--del);

}


int f(int a,int b){


if (a<10)
    return a;

if (b<0){
    return a%10+f(a/10,b);
}

return (a%10+f(a/10,-1))==b;


}



void task4(){
int n;
printf("vvedite chislo\n");
scanf("%d",&n);
printf("cifri chisla v obratnom poryadke: ");
RevPrint(n);

printf("\n");
}



void task6(){

printf("vvedite chislo\n");
int n;
scanf("%d",&n);

int b=sqrt(n)+1;

int ans=is_simple(n,b);

if (ans)
    printf("sostavnoe\n");
else
    printf("prostoe\n");


}

void task7(){

printf("vvedite dva chisla\n");
int m,n;
scanf("%d%d",&m,&n);


int ans=f(m,n);


//printf("%d/n",digit);
if (ans)
    printf("summa cifr %d ravna %d\n",m,n);
else
    printf("summa cifr %d ne ravna %d\n",m,n);

}


int main()
{
    int request;
    while (1){
        printf("vvedite nomer zadachi(4,6,7) 0 dlya zaversheniya\n");
        scanf("%d",&request);
        if (request==4)
            task4();
        if (request==6)
            task6();
        if (request==7)
            task7();
        if (request==0)
            return 0;

    }
    return 0;
}
