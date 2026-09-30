#include<stdio.h>
#define MAX_SIZE 50
int main(void) {
    int stock[MAX_SIZE] = {12, 7, 20, 5, 16};
    int n = 5;
    int choice;
    int value;
    int pos;
    char test;
    do {
        printf("=====================================================\n");
        printf("      CHUONG TRINH QUAN LY LUOT MUON SACH BOOKHUB  \n");
        printf("=====================================================\n");
        printf("1. Them so luot muon sach\n");
        printf("2. Sua so luot muon sach\n");
        printf("3. Xoa so luot muon sach\n");
        printf("4. Tim kiem so luot muon sach\n");
        printf("0. Thoat chuong trinh\n");
        printf("=====================================================\n");
        printf("Vui long nhap lua chon cua ban (0 - 4): ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                if (n >= MAX_SIZE) {
                    printf("Mang da day, khong the them!\n");
                    break;
                }
                printf("Nhap gia tri can them: ");
                scanf("%d",&value);
                printf("Nhap gia tri can chen (1 - %d): ",n + 1);
                scanf("%d",&pos);
                if (pos < 1 || pos > n + 1) {
                    printf("Vi tri chen khong hop le!\n");
                    break;
                }
                for (int i = n; i >= pos; i--) {
                    stock[i] = stock[i - 1];
                }
                stock[pos - 1] = value;
                n++;
                printf("Mang hien tai: [");
                for (int i = 0; i < n; i++) {
                    printf("%d", stock[i]);
                    if (i < n - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");
                break;


            case 2:
                int newValue;
                printf("Nhap vi tri can sua (1 - %d): ",n);
                scanf("%d",&pos);
                if (pos < 1 || pos > n) {
                    printf("Vi tri sua khong hop le!\n");
                    break;
                }
                printf("Nhap so luot muon sach moi: ");
                scanf("%d", &newValue);
                if (newValue < 0) {
                    printf("So luot muon sach khong hop le!\n");
                    break;
                }
                stock[pos - 1] = newValue;
                printf("Mang hien tai: [");
                for (int i = 0; i < n; i++) {
                    printf("%d", stock[i]);
                    if (i < n - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");
                break;

            case 3:
                if (n == 0) {
                    printf("Mang rong, khong the xoa!\n");
                    break;
                }
                printf("Nhap vi tri can xoa (1 - %d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Vi tri xoa khong hop le!\n");
                    break;
                }
                for (int i = pos-1; i < n - 1; i++) {
                    stock[i] = stock[i + 1];
                }
                n--;
                printf("Mang hien tai: [");
                for (int i = 0; i < n; i++) {
                    printf("%d", stock[i]);
                    if (i < n - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");
                break;

            case 4:
                int target;
                int count = 0;
                int foundPositions[MAX_SIZE];

                printf("Nhap gia tri can tim: ");
                scanf("%d", &target);
                for (int i = 0; i < n; i++) {
                    if (stock[i] == target) {
                        foundPositions[count] = i + 1;
                        count++;
                    }
                }
                if (count == 0) {
                    printf("Khong tim thay gia tri trong mang!\n");
                } else {
                    printf("========================================\n");
                    printf("            KET QUA TIM KIEM            \n");
                    printf("========================================\n");
                    printf("Gia tri can tim : %d\n", target);
                    printf("Vi tri          : ");
                    for (int i = 0; i < count; i++) {
                        printf("%d", foundPositions[i]);
                        if (i < count - 1) {
                            printf(", ");
                        }
                    }
                    printf("\n");
                    printf("So lan xuat hien: %d\n", count);
                    printf("========================================\n");
                }
                break;
            case 0:
                printf("Thoat chuong trinh thanh cong!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (choice != 0);
    return 0;
}