// Sử dụng mảng tìm tât cả các số nguyên tố từ 3 dên 100
#include<stdio.h>
#include<stdbool.h>
bool prime(int p){
for(int i=2; i < p; i++){
    if(p % i == 0)
    return 0;
}
return 1;
}
int main(){
    int Primes[50];
    int index=0;
   for(int i=2; i < 100; i++){
        if(prime(i)){
          Primes[index]= i;
           index++;
      }
   } 
   for (int i = 0;  i < index;  ++i )
         printf ("%i  ", Primes[i]);
}