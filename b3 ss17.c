#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void daoNguocChuoi(char *chuoi) {
    int len = strlen(chuoi);
    for (int i = 0; i < len / 2; i++) {
        char temp = chuoi[i];
        chuoi[i] = chuoi[len - i - 1];
        chuoi[len - i - 1] = temp;
    }
}

int demSoLuongTu(char *chuoi) {
    int count = 0;
    char *token = strtok(chuoi, " \t\n");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }
    return count;
}

void chuyenHoaChuoi(char *chuoi) {
    while (*chuoi) {
        if (*chuoi >= 'a' && *chuoi <= 'z') {
            *chuoi = *chuoi - 'a' + 'A';
        }
        chuoi++;
    }
}

int main() {
    char *chuoi = NULL;
    size_t kichThuoc = 0;
    int luaChon;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        getchar();

        switch (luaChon) {
            case 1:
                printf("Nhap vao chuoi: ");
                getline(&chuoi, &kichThuoc, stdin);
                break;
            case 2:
                if (chuoi != NULL) {
                    char *chuoiCopy = strdup(chuoi);
                    daoNguocChuoi(chuoiCopy);
                    printf("Chuoi dao nguoc: %s", chuoiCopy);
                    free(chuoiCopy);
                } else {
                    printf("Ban chua nhap chuoi\n");
                }
                break;
            case 3:
                if (chuoi != NULL) {
                    char *chuoiCopy = strdup(chuoi);
                    int soTu = demSoLuongTu(chuoiCopy);
                    printf("So luong tu trong chuoi: %d\n", soTu);
                    free(chuoiCopy);
                } else {
                    printf("Ban chua nhap chuoi\n");
                }
                break;
            case 4:
                if (chuoi != NULL) {
                    char chuoiKhac[1000];
                    printf("Nhap vao chuoi khac: ");
                    fgets(chuoiKhac, sizeof(chuoiKhac), stdin);
                    chuoiKhac[strcspn(chuoiKhac, "\n")] = 0;

                    if (strlen(chuoiKhac) > strlen(chuoi)) {
                        printf("Chuoi khac dai hon chuoi ban dau\n");
                    } else if (strlen(chuoiKhac) < strlen(chuoi)) {
                        printf("Chuoi khac ngan hon chuoi ban dau\n");
                    } else {
                        printf("Hai chuoi co do dai bang nhau\n");
                    }
                } else {
                    printf("Ban chua nhap chuoi\n");
                }
                break;
            case 5:
                if (chuoi != NULL) {
                    char *chuoiCopy = strdup(chuoi);
                    chuyenHoaChuoi(chuoiCopy);
                    printf("Chuoi sau khi chuyen hoa: %s\n", chuoiCopy);
                    free(chuoiCopy);
                } else {
                    printf("Ban chua nhap chuoi\n");
                }
                break;
            case 6:
                if (chuoi != NULL) {
                    char chuoiKhac[1000];
                    printf("Nhap vao chuoi khac: ");
                    fgets(chuoiKhac, sizeof(chuoiKhac), stdin);
                    chuoiKhac[strcspn(chuoiKhac, "\n")] = 0;

                    chuoi = realloc(chuoi, strlen(chuoi) + strlen(chuoiKhac) + 1);
                    strcat(chuoi, chuoiKhac);
                    printf("Chuoi sau khi them: %s\n", chuoi);
                } else {
                    printf("Ban chua nhap chuoi ban dau\n");
                }
                break;
            case 7:
                printf("Thoat chuong trinh\n");
                free(chuoi);
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai\n");
        }
    }

    return 0;
}

