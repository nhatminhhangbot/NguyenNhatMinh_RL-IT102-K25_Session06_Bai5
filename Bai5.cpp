#include <stdio.h>
#include <string.h>

int main() {
    char dsMaPhieu[50][20];
    char dsMaSV[50][20];
    int dsSoNgay[50];
    double dsTienPhat[50];
    int dsTrangThai[50];
    int soLuong = 0;
    int choice;

    do {
        printf("================ HE THONG QUAN LY PHI PHAT (LIBRARY_WMS) ================\n");
        printf("1. Them moi phieu phat qua han\n");
        printf("2. Hien thi danh sach & Thong ke tai chinh\n");
        printf("3. Cap nhat phieu phat\n");
        printf("4. Xoa phieu phat (Da thanh toan)\n");
        printf("5. Thoat\n");
        printf("------------------------------------------------------------------------\n");
        printf("Chon chuc nang (1-5): ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        if (choice == 1) {
            if (soLuong >= 50) {
                printf("Danh sach da day! Khong the them moi.\n\n");
            } else {
                char tempMa[20];
                int trung = 0;
                printf("\n--- THEM MOI PHIEU PHAT ---\n");
                printf("Nhap ma phieu muon: ");
                scanf("%s", tempMa);
                while (getchar() != '\n');

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(dsMaPhieu[i], tempMa) == 0) {
                        trung = 1;
                        break;
                    }
                }

                if (trung) {
                    printf("[Loi] Ma phieu da ton tai!\n\n");
                } else {
                    strcpy(dsMaPhieu[soLuong], tempMa);
                    printf("Nhap ma sinh vien: ");
                    scanf("%s", dsMaSV[soLuong]);
                    while (getchar() != '\n');

                    do {
                        printf("Nhap so ngay qua han: ");
                        scanf("%d", &dsSoNgay[soLuong]);
                        while (getchar() != '\n');
                        if (dsSoNgay[soLuong] <= 0) {
                            printf("So ngay qua han phai lon hon 0!\n");
                        }
                    } while (dsSoNgay[soLuong] <= 0);

                    if (dsSoNgay[soLuong] <= 7) {
                        dsTienPhat[soLuong] = dsSoNgay[soLuong] * 5000.0;
                    } else {
                        dsTienPhat[soLuong] = (7 * 5000.0) + ((dsSoNgay[soLuong] - 7) * 10000.0);
                    }

                    dsTrangThai[soLuong] = 0;
                    soLuong++;
                    printf("[Thanh cong] Da them phieu phat %s. Tien phat: %.1f VND. Trang thai: Chua thanh toan.\n\n", tempMa, dsTienPhat[soLuong - 1]);
                }
            }
        } else if (choice == 2) {
            if (soLuong == 0) {
                printf("\nDanh sach phi phat dang rong!\n\n");
            } else {
                printf("\n--- DANH SACH PHIEU PHAT & THONG KE ---\n");
                printf("%-5s %-15s %-15s %-10s %-15s %-15s\n", "STT", "Ma Phieu", "Ma SV", "So Ngay", "Tien Phat", "Trang Thai");
                double tongThu = 0;
                double tongNo = 0;
                for (int i = 0; i < soLuong; i++) {
                    const char *tt = (dsTrangThai[i] == 1) ? "Da thanh toan" : "Chua thanh toan";
                    printf("%-5d %-15s %-15s %-10d %-15.1f %-15s\n", i + 1, dsMaPhieu[i], dsMaSV[i], dsSoNgay[i], dsTienPhat[i], tt);
                    if (dsTrangThai[i] == 1) {
                        tongThu += dsTienPhat[i];
                    } else {
                        tongNo += dsTienPhat[i];
                    }
                }
                printf("------------------------------------------------------------------------\n");
                printf("Tong tien da thu: %.1f VND\n", tongThu);
                printf("Tong tien du no: %.1f VND\n\n", tongNo);
            }
        } else if (choice == 3) {
            if (soLuong == 0) {
                printf("\nDanh sach phi phat dang rong!\n\n");
            } else {
                char tempMa[20];
                printf("\n--- CAP NHAT PHIEU PHAT ---\n");
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%s", tempMa);
                while (getchar() != '\n');

                int found = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(dsMaPhieu[i], tempMa) == 0) {
                        found = i;
                        break;
                    }
                }

                if (found == -1) {
                    printf("Khong tim thay ma phieu nay trong he thong!\n\n");
                } else {
                    int subChoice;
                    printf("1. Cap nhat so ngay qua han\n");
                    printf("2. Xac nhan thanh toan\n");
                    printf("Chon thao tac (1-2): ");
                    scanf("%d", &subChoice);
                    while (getchar() != '\n');

                    if (subChoice == 1) {
                        do {
                            printf("Nhap so ngay qua han moi: ");
                            scanf("%d", &dsSoNgay[found]);
                            while (getchar() != '\n');
                            if (dsSoNgay[found] <= 0) {
                                printf("So ngay qua han phai lon hon 0!\n");
                            }
                        } while (dsSoNgay[found] <= 0);

                        if (dsSoNgay[found] <= 7) {
                            dsTienPhat[found] = dsSoNgay[found] * 5000.0;
                        } else {
                            dsTienPhat[found] = (7 * 5000.0) + ((dsSoNgay[found] - 7) * 10000.0);
                        }
                        printf("[Thanh cong] Da cap nhat so ngay va tien phat moi.\n\n");
                    } else if (subChoice == 2) {
                        if (dsTrangThai[found] == 1) {
                            printf("Phieu nay da duoc thanh toan truoc do!\n\n");
                        } else {
                            dsTrangThai[found] = 1;
                            printf("[Thanh cong] Da xac nhan thanh toan phieu phat.\n\n");
                        }
                    } else {
                        printf("Lua chon khong hop le!\n\n");
                    }
                }
            }
        } else if (choice == 4) {
            if (soLuong == 0) {
                printf("\nDanh sach phi phat dang rong!\n\n");
            } else {
                char tempMa[20];
                printf("\n--- XOA PHIEU PHAT ---\n");
                printf("Nhap ma phieu muon can xoa: ");
                scanf("%s", tempMa);
                while (getchar() != '\n');

                int found = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(dsMaPhieu[i], tempMa) == 0) {
                        found = i;
                        break;
                    }
                }

                if (found == -1) {
                    printf("Khong tim thay ma phieu nay trong he thong!\n\n");
                } else {
                    if (dsTrangThai[found] == 0) {
                        printf("Khong the xoa phieu phat CHUA thanh toan de tranh meo mo so sach tai chinh!\n\n");
                    } else {
                        for (int i = found; i < soLuong - 1; i++) {
                            strcpy(dsMaPhieu[i], dsMaPhieu[i + 1]);
                            strcpy(dsMaSV[i], dsMaSV[i + 1]);
                            dsSoNgay[i] = dsSoNgay[i + 1];
                            dsTienPhat[i] = dsTienPhat[i + 1];
                            dsTrangThai[i] = dsTrangThai[i + 1];
                        }
                        soLuong--;
                        printf("[Thanh cong] Da xoa phieu phat khoi he thong.\n\n");
                    }
                }
            }
        } else if (choice == 5) {
            printf("Cam on ban da su dung he thong. Tam biet!\n");
        } else {
            printf("Lua chon khong hop le! Vui long chon lai tu 1 den 5.\n\n");
        }

    } while (choice != 5);

    return 0;
}
