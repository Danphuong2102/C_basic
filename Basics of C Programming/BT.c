#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 10

typedef struct {
    char name[50];
    float score;
    char gender[10];
    int class_name;
} Student;

void bubbleSortByName(Student arr[], int n); 

void bubbleSortByScore(Student arr[], int n); 

void findTopScores(Student arr[], int n); 

void printStudents(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\t%f\t%s\t%d\n", arr[i].name, arr[i].score, arr[i].gender, arr[i].class_name);
    }
}

int main() {
    int n;
    Student students[MAX];
    clock_t start, end;
    double cpu_time_used;
    
    printf("Nhap so hoc sinh: ");
    scanf("%d", &n);
    getchar(); 
    
    for (int i = 0; i < n; i++) {
        printf("Nhap ten:\n ");
        scanf("%s", students[i].name);
        students[i].name[strcspn(students[i].name, "\n")] = 0;
    
        printf("Nhap diem:\n ");
        scanf("%f", &students[i].score);
        
        printf("Nhap gioi tinh (Nam/Nu):\n ");
        getchar();
        scanf("%c", &students[i].gender);
        students[i].gender[strcspn(students[i].gender, "\n")] = 0;
        
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

void bubbleSortByName(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

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

void findTopScores(Student arr[], int n) {
    int maxMale = -1, maxFemale = -1, maxOverall = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].gender, "Nam") == 0 && arr[i].score > maxMale) {
            maxMale = arr[i].score;
        }
        if (strcmp(arr[i].gender, "Nu") == 0 && arr[i].score > maxFemale) {
            maxFemale = arr[i].score;
        }
        if (arr[i].score > maxOverall) {
            maxOverall = arr[i].score;
        }
    }
    printf("Diem cao nhat cua Nam: %d\n", maxMale);
    printf("Diem cao nhat cua Nu: %d\n", maxFemale);
    printf("Diem cao nhat trong lop: %d\n", maxOverall);
}

