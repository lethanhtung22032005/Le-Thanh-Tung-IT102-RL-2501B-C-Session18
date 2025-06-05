#include <stdio.h>  

struct Student {  
    char name[50];  
    int age;  
    char phoneNumber[15];  
};  

int main() {  
    struct Student student;  

   
    printf("Nhap ten sinh vien: ");  
    fgets(student.name, sizeof(student.name), stdin);  
    
    printf("Nhap tuoi sinh vien: ");  
    scanf("%d", &student.age);  
    
    printf("Nhap so dien thoai: ");  
    scanf("%s", student.phoneNumber);  

  
    printf("\nThong tin sinh vien:\n");  
    printf("Ten: %s", student.name);  
    printf("Tuoi: %d\n", student.age);  
    printf("So dien thoai: %s\n", student.phoneNumber);  

    return 0;  
}
