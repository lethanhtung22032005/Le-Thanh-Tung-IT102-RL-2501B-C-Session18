#include <stdio.h>  
#include <string.h>  

const int MAX_STUDENTS = 50;  

struct Student {  
    int id;  
    char name[50];  
    int age;  
    char phoneNumber[15];  
};  

int main() {  
    struct Student students[MAX_STUDENTS];  
    int numberOfStudents = 5;  

    for (int i = 0; i < numberOfStudents; i++) {  
        students[i].id = i + 1;  

        printf("Nhap thong tin cho sinh vien %d:\n", students[i].id);  

        printf("Ten: ");  
        getchar();  
        fgets(students[i].name, sizeof(students[i].name), stdin);  
        students[i].name[strcspn(students[i].name, "\n")] = '\0';  

        printf("Tuoi: ");  
        scanf("%d", &students[i].age);  

        printf("So dien thoai: ");  
        getchar();  
        fgets(students[i].phoneNumber, sizeof(students[i].phoneNumber), stdin);  
        students[i].phoneNumber[strcspn(students[i].phoneNumber, "\n")] = '\0';  
        
        printf("\n");  
    }  

    printf("Thong tin cac sinh vien:\n");  
    for (int i = 0; i < numberOfStudents; i++) {  
        printf("ID: %d\n", students[i].id);  
        printf("Ten: %s\n", students[i].name);  
        printf("Tuoi: %d\n", students[i].age);  
        printf("So dien thoai: %s\n", students[i].phoneNumber);  
        printf("------------------------\n");  
    }  

    return 0;  
}
