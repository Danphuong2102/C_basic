//Tính tổng các số chia hết cho 3 và 5 trong đoạn [a,b].
#include<stdio.h>
int main(){
    int a, b;
    int sum;
    printf("so chia hest cho 3 va 5: ");
    scanf("%d%d",&a,&b);
    while (a<=b){
        if(a%3==0 && a%5==0){
        printf("so chia het cho 3 va 5 la: %d\n", a);
        sum+=a;
        }
        a++;
    }
        printf("Tong la: %d\n", sum);
         

}