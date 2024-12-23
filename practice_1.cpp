#include <stdio.h>
#include <string.h>

// Struct to represent a book
typedef struct {
    char maSach[20];
    char tenSach[100];
    char tacGia[50];
    float giaTien;
    char theLoai[50];
} Sach;

// Function declarations
void nhapThongTinSach(Sach dsSach[], int *soLuong);
void hienThiSach(const Sach dsSach[], int soLuong);
void themSachTaiViTri(Sach dsSach[], int *soLuong);
void xoaSachTheoMa(Sach dsSach[], int *soLuong);
void capNhatSachTheoMa(Sach dsSach[], int soLuong);
void sapXepSachTheoGia(Sach dsSach[], int soLuong, int tangDan);
void timSachTheoTen(const Sach dsSach[], int soLuong);

int main() {
    Sach dsSach[100];
    int soLuong = 0;
    int luaChon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach.\n");
        printf("2. Hien thi thong tin sach.\n");
        printf("3. Them sach vao vi tri.\n");
        printf("4. Xoa sach theo ma sach.\n");
        printf("5. Cap nhat thong tin sach theo ma sach.\n");
        printf("6. Sap xep sach theo gia (tang/giam).\n");
        printf("7. Tim sach theo ten sach.\n");
        printf("8. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapThongTinSach(dsSach, &soLuong);
                break;
            case 2:
                hienThiSach(dsSach, soLuong);
                break;
            case 3:
                themSachTaiViTri(dsSach, &soLuong);
                break;
            case 4:
                xoaSachTheoMa(dsSach, &soLuong);
                break;
            case 5:
                capNhatSachTheoMa(dsSach, soLuong);
                break;
            case 6: {
                int tangDan;
                printf("Chon: 1-Tang, 0-Giam: ");
                scanf("%d", &tangDan);
                sapXepSachTheoGia(dsSach, soLuong, tangDan);
                break;
            }
            case 7:
                timSachTheoTen(dsSach, soLuong);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 8);

    return 0;
}

void nhapThongTinSach(Sach dsSach[], int *soLuong) {
    printf("Nhap so luong sach: ");
    scanf("%d", soLuong);

    for (int i = 0; i < *soLuong; i++) {
        printf("\nNhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%s", dsSach[i].maSach);
        printf("Ten sach: ");
        getchar(); // Clear newline
        fgets(dsSach[i].tenSach, sizeof(dsSach[i].tenSach), stdin);
        dsSach[i].tenSach[strcspn(dsSach[i].tenSach, "\n")] = 0;
        printf("Tac gia: ");
        fgets(dsSach[i].tacGia, sizeof(dsSach[i].tacGia), stdin);
        dsSach[i].tacGia[strcspn(dsSach[i].tacGia, "\n")] = 0;
        printf("Gia tien: ");
        scanf("%f", &dsSach[i].giaTien);
        printf("The loai: ");
        getchar();
        fgets(dsSach[i].theLoai, sizeof(dsSach[i].theLoai), stdin);
        dsSach[i].theLoai[strcspn(dsSach[i].theLoai, "\n")] = 0;
    }
}

void hienThiSach(const Sach dsSach[], int soLuong) {
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < soLuong; i++) {
        printf("\nSach %d:\n", i + 1);
        printf("Ma sach: %s\n", dsSach[i].maSach);
        printf("Ten sach: %s\n", dsSach[i].tenSach);
        printf("Tac gia: %s\n", dsSach[i].tacGia);
        printf("Gia tien: %.2f\n", dsSach[i].giaTien);
        printf("The loai: %s\n", dsSach[i].theLoai);
    }
}

void themSachTaiViTri(Sach dsSach[], int *soLuong) {
    if (*soLuong >= 100) {
        printf("Khong the them sach. Danh sach da du.\n");
        return;
    }

    int viTri;
    printf("Nhap vi tri muon them (0-%d): ", *soLuong);
    scanf("%d", &viTri);

    if (viTri < 0 || viTri > *soLuong) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = *soLuong; i > viTri; i--) {
        dsSach[i] = dsSach[i - 1];
    }

    printf("Nhap thong tin sach moi:\n");
    printf("Ma sach: ");
    scanf("%s", dsSach[viTri].maSach);
    printf("Ten sach: ");
    getchar();
    fgets(dsSach[viTri].tenSach, sizeof(dsSach[viTri].tenSach), stdin);
    dsSach[viTri].tenSach[strcspn(dsSach[viTri].tenSach, "\n")] = 0;
    printf("Tac gia: ");
    fgets(dsSach[viTri].tacGia, sizeof(dsSach[viTri].tacGia), stdin);
    dsSach[viTri].tacGia[strcspn(dsSach[viTri].tacGia, "\n")] = 0;
    printf("Gia tien: ");
    scanf("%f", &dsSach[viTri].giaTien);
    printf("The loai: ");
    getchar();
    fgets(dsSach[viTri].theLoai, sizeof(dsSach[viTri].theLoai), stdin);
    dsSach[viTri].theLoai[strcspn(dsSach[viTri].theLoai, "\n")] = 0;

    (*soLuong)++;
}

void xoaSachTheoMa(Sach dsSach[], int *soLuong) {
    char maSach[20];
    printf("Nhap ma sach muon xoa: ");
    scanf("%s", maSach);

    int timThay = 0;
    for (int i = 0; i < *soLuong; i++) {
        if (strcmp(dsSach[i].maSach, maSach) == 0) {
            timThay = 1;
            for (int j = i; j < *soLuong - 1; j++) {
                dsSach[j] = dsSach[j + 1];
            }
            (*soLuong)--;
            printf("Da xoa sach co ma %s.\n", maSach);
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sach co ma %s.\n", maSach);
    }
}

void capNhatSachTheoMa(Sach dsSach[], int soLuong) {
    char maSach[20];
    printf("Nhap ma sach muon cap nhat: ");
    scanf("%s", maSach);

    int timThay = 0;
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(dsSach[i].maSach, maSach) == 0) {
            timThay = 1;
            printf("Nhap thong tin moi cho sach:\n");
            printf("Ten sach: ");
            getchar();
            fgets(dsSach[i].tenSach, sizeof(dsSach[i].tenSach), stdin);
            dsSach[i].tenSach[strcspn(dsSach[i].tenSach, "\n")] = 0;
            printf("Tac gia: ");
            fgets(dsSach[i].tacGia, sizeof(dsSach[i].tacGia), stdin);
            dsSach[i].tacGia[strcspn(dsSach[i].tacGia, "\n")] = 0;
            printf("Gia tien: ");
            scanf("%f", &dsSach[i].giaTien);
            printf("The loai: ");
            getchar();
            fgets(dsSach[i].theLoai, sizeof(dsSach[i].theLoai), stdin);
            dsSach[i].theLoai[strcspn(dsSach[i].theLoai, "\n")] = 0;
            printf("Cap nhat thanh cong.\n");
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sach co ma %s.\n", maSach);
    }
}

void sapXepSachTheoGia(Sach dsSach[], int soLuong, int tangDan) {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if ((tangDan && dsSach[i].giaTien > dsSach[j].giaTien) ||
                (!tangDan && dsSach[i].giaTien < dsSach[j].giaTien)) {
                Sach temp = dsSach[i];
                dsSach[i] = dsSach[j];
                dsSach[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong.\n");
}

void timSachTheoTen(const Sach dsSach[], int soLuong) {
    char tenSach[100];
    printf("Nhap ten sach muon tim: ");
    getchar();
    fgets(tenSach, sizeof(tenSach), stdin);
    tenSach[strcspn(tenSach, "\n")] = 0;

    int timThay = 0;
    for (int i = 0; i < soLuong; i++) {
        if (strstr(dsSach[i].tenSach, tenSach) != NULL) {
            if (!timThay) {
                printf("\nKet qua tim kiem:\n");
            }
            timThay = 1;
            printf("\nMa sach: %s\n", dsSach[i].maSach);
            printf("Ten sach: %s\n", dsSach[i].tenSach);
            printf("Tac gia: %s\n", dsSach[i].tacGia);
            printf("Gia tien: %.2f\n", dsSach[i].giaTien);
            printf("The loai: %s\n", dsSach[i].theLoai);
        }
    }

    if (!timThay) {
        printf("Khong tim thay sach phu hop.\n");
    }
}

