#include <stdio.h>  
#include <string.h>  


struct Student {  
    char name[50];  
    int age;  
    char phoneNumber[15];  
};  

int main() {  
  
    struct Student student;  

    
    strcpy(student.name, "Nhathat");  
    student.age = 18;  
    strcpy(student.phoneNumber, "030906");  

    
    printf("Name: %s\n", student.name);  
    printf("Age: %d\n", student.age);  
    printf("Phone Number: %s\n", student.phoneNumber);  

    return 0;  
}
