// Sử dụng các câu lênh trong string. Đảo kí tự của chuỗi được nhập từ bàn phím 
#include<stdio.h>
#include<string.h>
int main() {
    char chuoi1[100], chuoi2[100], chuoi_noi[200];
    
    printf("Chuoi thu 1 la: ");
    fgets(chuoi1, sizeof(chuoi1), stdin);// sử dụng fget để nhập chuỗi từ bàn phím
   // scanf("%s", strin);
    size_t len1 = strlen(chuoi1);
    if (len1 > 0 && chuoi1[len1 - 1] == '\n') {
        chuoi1[len1 - 1] = '\0';
    }
    printf("Chuoi thu 2 la: ");
    fgets(chuoi2, sizeof(chuoi2), stdin);
    size_t len2 = strlen(chuoi2);
    if (len2 > 0 && chuoi2[len2 - 1] == '\n') {
        chuoi2[len2 - 1] = '\0';
    }
    
    strcpy(chuoi_noi, chuoi1);
    strcat(chuoi_noi, " ");
    strcat(chuoi_noi, chuoi2);
    printf("Chuoi noi la: %s\n", chuoi_noi);
    
    // Đảo ngược chuỗi nối
    printf("chuoi noi dao nguoc la: ");
    for (int i = strlen(chuoi_noi) - 1; i >= 0; i--) {
        putchar(chuoi_noi[i]);
    }
    printf("\n");
    
    return 0;
}
