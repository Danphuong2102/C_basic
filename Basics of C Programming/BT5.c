// 1.Tìm ước chung lớn nhất của 2 số nguyên không âm và trả về kết quả.
// 2.Tìm giá trị tuyệt đối của 1 số và trả về kết quả (sử dụng kiểu dữ liệu float).
// 3.Tính căn bậc hai ( nếu là số âm đưa ra thông báo). 

#include<stdio.h>
#include<math.h>
int gcd (int a, int b){
    while(a!=b){
        if(a>b){
        a-=b;
         } else{
            b-=a;
        }
    }
    return a;
}
float gttd(float a){
    if(a<0)
    a = -a;
    return a;
}
float CBH(float a){
    if(a>0){
        float b = sqrt(a);
        printf("can bac hai cua 2 so la:%.3f", b);
    }else{
        printf("khong co căn bac hai\nn");
    }
   
}


int main(){
  int UCLN = gcd(200,465);
  printf(" hai so co UCLN la:%d\n",UCLN);
  float x = gttd (-60);
  printf("gia tri tuyet doi la: %.2f\n", x);
  CBH(64);

}