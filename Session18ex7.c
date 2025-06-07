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
    char searchName[50];
    int found = 0;

    printf("Nhap ten sinh vien can xoa: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            found = 1;
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi ten %s\n", searchName);
    }

    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }

    return 0;
}
