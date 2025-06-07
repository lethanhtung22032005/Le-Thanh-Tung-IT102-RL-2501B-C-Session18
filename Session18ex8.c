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
    int insertPosition;

    printf("Nhap vi tri can chen (0-%d): ", studentCount);
    scanf("%d", &insertPosition);
    getchar();

    if (insertPosition < 0 || insertPosition > studentCount || studentCount >= 50) {
        printf("Vi tri chen khong hop le hoac mang da day\n");
        return 1;
    }

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

    for (int i = studentCount; i > insertPosition; i--) {
        students[i] = students[i - 1];
    }
    students[insertPosition] = newStudent;
    studentCount++;

    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }

    return 0;
}
