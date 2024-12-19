#include <stdio.h>
#include <string.h>

int la_ky_tu_dac_biet(char c) {
    if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126)) {
        return 1;
    }
    return 0;
}

int main() {
    char *chuoi = NULL;
    size_t kich_thuoc = 0;
    int lua_chon;

    while(1) {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &lua_chon);
        getchar();

        switch(lua_chon) {
            case 1:
                printf("Nhap vao chuoi: ");
                getline(&chuoi, &kich_thuoc, stdin);
                break;
            case 2:
                if(chuoi != NULL) {
                    printf("Chuoi ban da nhap: %s", chuoi);
                } else {
                    printf("Ban chua nhap chuoi\n");
                }
                break;
            case 3:
                if(chuoi != NULL) {
                    int so_chu_cai = 0;
                    for(int i = 0; i < strlen(chuoi); i++) {
                        if((chuoi[i] >= 'a' && chuoi[i] <= 'z') || (chuoi[i] >= 'A' && chuoi[i] <= 'Z')) {
                            so_chu_cai++;
                        }
                    }
                    printf("So luong chu cai trong chuoi: %d\n", so_chu_cai);
                } else {
                    printf("Ban chua nhap chuoi\n");
                }
                break;
            case 4:
                if(chuoi != NULL) {
                    int so_chu_so = 0;
                    for(int i = 0; i < strlen(chuoi); i++) {
                        if(chuoi[i] >= '0' && chuoi[i] <= '9') {
                            so_chu_so++;
                        }
                    }
                    printf("So luong chu so trong chuoi: %d\n", so_chu_so);
                } else {
                    printf("Ban chua nhap chuoi\n");
                }
                break;
            case 5:
                if(chuoi != NULL) {
                    int so_ky_tu_dac_biet = 0;
                    for(int i = 0; i < strlen(chuoi); i++) {
                        if(la_ky_tu_dac_biet(chuoi[i])) {
                            so_ky_tu_dac_biet++;
                        }
                    }
                    printf("So luong ky tu dac biet trong chuoi: %d\n", so_ky_tu_dac_biet);
                } else {
                    printf("Ban chua nhap chuoi\n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh\n");
                free(chuoi);
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai\n");
        }
    }

    return 0;
}

