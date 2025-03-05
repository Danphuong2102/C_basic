//Hiển thị ra màn hình các số có chữ số 0 ở cuối từ 1 đến 1000
#include<stdio.h>
int main(){
    int a = 1;
    do{
        if(a % 10 == 0){
            printf("So co chu so 0 o cuoi la: %d\nn",a);
        }
        a++;
    } while(a <= 1000);
    return 0;
}
