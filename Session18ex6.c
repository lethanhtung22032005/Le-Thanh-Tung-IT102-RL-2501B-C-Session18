#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[12];
};

int main() {
    struct Student students[50] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Tran Thi B", 21, "0987654321"},
        {3, "Le Van C", 19, "0912345678"},
        {4, "Pham Thi D", 22, "0932145678"},
        {5, "Hoang Van E", 20, "0941234567"}
    };
    int studentCount = 5;

    struct Student newStudent;
    printf("Nhap ID sinh vien moi: ");
    scanf("%d", &newStudent.id);
    getchar();
    printf("Nhap ten sinh vien moi: ");
    fgets(newStudent.name, 50, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0;
    printf("Nhap tuoi sinh vien moi: ");
    scanf("%d", &newStudent.age);
    getchar();
    printf("Nhap so dien thoai sinh vien moi: ");
    fgets(newStudent.phoneNumber, 12, stdin);
    newStudent.phoneNumber[strcspn(newStudent.phoneNumber, "\n")] = 0;

    students[studentCount] = newStudent;
    studentCount++;

    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }

    return 0;
}
