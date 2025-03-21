#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    float score;
    char gender[10];
    int class_name;
} Student;

void bubbleSortByName(Student arr[], int n); // Hàm sắp xếp tên học sinh theo Alphabet

void bubbleSortByScore(Student arr[], int n); // hàm sắp xếp điểm học sinh từ thấp đến cao 

void findTopScores(Student arr[], int n); // Hàm tìm kiếm học sinh nam/nữ điểm cao và điểm cao nhất 

void printStudents(Student arr[], int n); // Hàm in thông tin học sinh 

int main() {
    int n;
    Student students[10];
    clock_t start, end;
    double cpu_time_used;
    
    printf("Nhap so hoc sinh: ");
    scanf("%d", &n);
    getchar(); 
    for (int i = 0; i < n; i++) {
        printf("Nhap ten:\n ");
        scanf("%s", students[i].name);
       
        printf("Nhap diem:\n ");
        scanf("%f", &students[i].score);
        
        printf("Nhap gioi tinh (Nam/Nu):\n ");
        getchar();
        scanf("%c", &students[i].gender);
  
        printf("Nhap lop:\n ");
        scanf("%d", &students[i].class_name);
    }

    start = clock();
    bubbleSortByName(students, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nDanh sach sau khi sap xep theo ten:\n");
    printStudents(students, n);
    printf("Thoi gian thuc thi sap xep theo ten: %f giay\n", cpu_time_used);
    
    start = clock();
    bubbleSortByScore(students, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nDanh sach sau khi sap xep theo diem:\n");
    printStudents(students, n);
    printf("Thoi gian thuc thi sap xep theo diem: %f giay\n", cpu_time_used);
    
    findTopScores(students, n);
    
    return 0;
    
}
// Hàm sắp xếp tên học sinh theo AlphabetAlphabet
void bubbleSortByName(Student arr[], int n) {
   
    for (int i = 0; i < n - 1; i++) {
     
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].name > arr[j+1].name) {
                Student buffer = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buffer;  
            }
        }
    }
}
// Hàm sắp xếp điểm học sinhsinh từ thấp đến cao 
void bubbleSortByScore(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].score > arr[j + 1].score) {
                Student buffer = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buffer;
            }
        }
    }
}
// Hàm tìm kiếm học sinh nam/nữ điểm cao nhất và học sinh có điểm cao nhất.
void findTopScores(Student arr[], int n) {
    float maxMale, maxFemale, maxOverall;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].gender, "Nam") == 0 && arr[i+1].score > arr[i].score) {
            maxMale = arr[i+1].score;
        }
        if (strcmp(arr[i].gender, "Nu") == 0 && arr[i+1].score > arr[i].score) {
            maxFemale = arr[i+1].score;
        }
        if (arr[i+1].score > arr[i].score) {
            maxOverall = arr[i+1].score;
        }
    }
    printf("Diem cao nhat cua Nam: %d\n", maxMale);
    printf("Diem cao nhat cua Nu: %d\n", maxFemale);
    printf("Diem cao nhat trong lop: %d\n", maxOverall);
}
// Hàmàm in thông tin học sinh 
void printStudents(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\t%f\t%s\t%d\n", arr[i].name, arr[i].score, arr[i].gender, arr[i].class_name);
    }
}
