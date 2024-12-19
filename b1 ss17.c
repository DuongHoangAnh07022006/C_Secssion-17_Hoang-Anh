#include <stdio.h>
#include <stdlib.h>
void nhapMang(int **arr, int *n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);
    *arr = (int*)malloc(*n * sizeof(int));
    if (*arr == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }
}
void hienThiMang(int *arr, int n) {
    if (n == 0) {
        printf("Mang rong.\n");
    } else {
        printf("Mang cac phan tu:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
int tinhDoDai(int n) {
    return n;
}
int tinhTong(int *arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i];
    }
    return tong;
}
int timPhanTuLonNhat(int *arr, int n) {
    if (n == 0) {
        return -1;
    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int main() {
    int *arr = NULL;
    int n = 0;
    int luaChon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");

        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang(&arr, &n);
                break;
            case 2:
                hienThiMang(arr, n);
                break;
            case 3:
                printf("Do dai mang la: %d\n", tinhDoDai(n));
                break;
            case 4:
                printf("Tong cac phan tu trong mang la: %d\n", tinhTong(arr, n));
                break;
            case 5:
                {
                    int max = timPhanTuLonNhat(arr, n);
                    if (max != -1) {
                        printf("Phan tu lon nhat trong mang la: %d\n", max);
                    } else {
                        printf("Mang rong, khong the tim phan tu lon nhat.\n");
                    }
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (luaChon != 6);
    free(arr);
    return 0;
}

