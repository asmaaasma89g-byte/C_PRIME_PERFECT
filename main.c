#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
 bool IS_PRIME(int x){
     bool prime;
     int i;
     if(x<=1){
        prime=false;
     }else{
     i=2;
     prime=true;
     while(i<=x/2 && prime==true){
        if(x%i==0){
          prime=false;
        }else{
        i++;
        }
     }
     }
     return prime;
}
 bool IS_PRIME_PEFECT(int x){
   bool perfect;
   int s,d;
   perfect=false;
   if(IS_PRIME(x)==true){
    s=0;
    while(x!=0){
        d=x%10;
        s=s+d;
        x=x/10;
    }
    if(IS_PRIME(s)==true){
        perfect=true;
    }else {perfect=false;
   }
}
     return perfect;
 }
 int main()
 { int i,n,j,max_p_p,nb_p;
 bool ex;
   int v1[100],v2[100];
   do{
  scanf("%d",&n);
   }while(n<=0 || n>100);
  for(i=0;i<n;i++){
        do{
        printf("v1[%d]=",i);
       scanf("%d",&v1[i]);
       ex=false;
       j=0;
       while(j<i && ex==false){
        if(v1[i]==v1[j]){
            ex=true;
        }else{
            j++;
        }
       }
   }while(ex==true || v1[i]<10);
  }

   for(i=0;i<n;i++){
    if(IS_PRIME(v1[i])==true){
       v2[i]=v1[i];
    }else {
        v2[i]=0;
    }
   }
   for(i=0;i<n;i++){
       printf("v2[%d]=%d \n",i,v2[i]);
   }
   max_p_p=0;
  nb_p=0;
   i=0;
   while(i<n ){
    if(v2[i]!=0){
        if(IS_PRIME_PEFECT(v1[i])==true){
            if(max_p_p<v1[i]){
                max_p_p=v1[i];
            }for(j=i;j<n-1;j++){
            v1[j]=v1[j+1];
            v2[j]=v2[j+1];
           } n=n-1;
        }else{nb_p=nb_p+1;
             i++;
        }
    }else { i++;}}
    for(i=0;i<n-1;i++){
        printf("v1[%d]=%d ",i,v1[i]);
    }
    printf("max_p_p=%d    ,  nb_p=%d",max_p_p,nb_p);
   return 0;

 }

