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
    int searchId, found = 0;

    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &searchId);
    getchar();

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchId) {
            found = 1;
            printf("Nhap ten moi: ");
            fgets(students[i].name, 50, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;
            printf("Nhap tuoi moi: ");
            scanf("%d", &students[i].age);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi ID %d\n", searchId);
    }

    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }

    return 0;
}
