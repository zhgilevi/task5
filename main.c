#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int RevPrint(int a,int digit){
int cur_dig=1;
for (int i=0;i<digit;i++){
    cur_dig*=10;
}

if (a/10==0){
    return a;
}

return a%10*cur_dig+RevPrint(a/10,--digit);

}

int is_simple(int a,int del){

if (del==1)
    return 0;


if (a%del==0 && a!=del)
    return 1;

return is_simple(a,--del);

}


int f(int a,int b,int digit){


if (a<10)
    return a;


int c=1;


for (int i=1;i<digit;i++){
    c*=10;
}

if (a>=c && a<c*10)
    return (a%10+f(a/10,b,digit))==b;


return a%10+f(a/10,b,digit);




}



void task4(){
int n;
printf("vvedite chislo\n");
scanf("%d",&n);
int digit=(n==0),cp=n;
while (cp>0){
    cp/=10;
    digit++;
}

int ans=RevPrint(n,--digit);
printf("chislo v obratnom poryadke: %d\n",ans);
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

int cp=m,digit=(cp==0);
while (cp>0){
    digit++;
    cp/=10;
}

int ans=f(m,n,digit);


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
