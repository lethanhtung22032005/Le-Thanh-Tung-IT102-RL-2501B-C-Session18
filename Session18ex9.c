#include <stdio.h>
#include <string.h>

struct Dish {
    int id;
    char name[50];
    float price;
};

void printMenu(struct Dish menu[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s: %.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

void insertDish(struct Dish menu[], int *count, int position) {
    if (*count >= 100 || position < 0 || position > *count) {
        printf("Vi tri khong hop le hoac mang da day\n");
        return;
    }
    struct Dish newDish;
    printf("Nhap ID: ");
    scanf("%d", &newDish.id);
    getchar();
    printf("Nhap ten: ");
    fgets(newDish.name, 50, stdin);
    newDish.name[strcspn(newDish.name, "\n")] = 0;
    printf("Nhap gia: ");
    scanf("%f", &newDish.price);
    for (int i = *count; i > position; i--) {
        menu[i] = menu[i - 1];
    }
    menu[position] = newDish;
    (*count)++;
}

void editDish(struct Dish menu[], int count, int position) {
    if (position < 0 || position >= count) {
        printf("Vi tri khong hop le\n");
        return;
    }
    printf("Nhap ten moi: ");
    getchar();
    fgets(menu[position].name, 50, stdin);
    menu[position].name[strcspn(menu[position].name, "\n")] = 0;
    printf("Nhap gia moi: ");
    scanf("%f", &menu[position].price);
}

void deleteDish(struct Dish menu[], int *count, int position) {
    if (position < 0 || position >= *count) {
        printf("Vi tri khong hop le\n");
        return;
    }
    for (int i = position; i < *count - 1; i++) {
        menu[i] = menu[i + 1];
    }
    (*count)--;
}

void sortDishes(struct Dish menu[], int count, int ascending) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (ascending ? (menu[j].price > menu[j + 1].price) : (menu[j].price < menu[j + 1].price)) {
                struct Dish temp = menu[j];
                menu[j] = menu[j + 1];
                menu[j + 1] = temp;
            }
        }
    }
}

int linearSearch(struct Dish menu[], int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(menu[i].name, name) == 0) return i;
    }
    return -1;
}

int binarySearch(struct Dish menu[], int count, char *name) {
    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (strcmp(menu[mid].name, name) == 0) return mid;
        if (strcmp(menu[mid].name, name) < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    struct Dish menu[100] = {
        {1, "Com rang", 25.0},
        {2, "Pho bo", 40.0},
        {3, "Bun cha", 35.0},
        {4, "Cha gio", 20.0},
        {5, "Mi xao", 30.0}
    };
    int count = 5, choice, subChoice, position;
    char searchName[50];

    do {
        printf("\nMENU\n1. In menu\n2. Them phan tu\n3. Sua phan tu\n4. Xoa phan tu\n5. Sap xep\n6. Tim kiem\n7. Thoat\nChon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: printMenu(menu, count); break;
            case 2:
                printf("Nhap vi tri chen: ");
                scanf("%d", &position);
                insertDish(menu, &count, position);
                break;
            case 3:
                printf("Nhap vi tri sua: ");
                scanf("%d", &position);
                editDish(menu, count, position);
                break;
            case 4:
                printf("Nhap vi tri xoa: ");
                scanf("%d", &position);
                deleteDish(menu, &count, position);
                break;
            case 5:
                printf("a. Giam dan theo price\nb. Tang dan theo price\nChon: ");
                getchar();
                scanf("%c", &subChoice);
                sortDishes(menu, count, subChoice == 'b');
                printMenu(menu, count);
                break;
            case 6:
                printf("Nhap ten can tim: ");
                fgets(searchName, 50, stdin);
                searchName[strcspn(searchName, "\n")] = 0;
                printf("a. Tim kiem tuyen tinh\nb. Tim kiem nhi phan\nChon: ");
                getchar();
                scanf("%c", &subChoice);
                int index = (subChoice == 'a') ? linearSearch(menu, count, searchName) : binarySearch(menu, count, searchName);
                if (index != -1) printf("Tim thay tai vi tri %d\n", index);
                else printf("Khong tim thay\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
