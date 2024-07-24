#include <stdio.h>
#include <stdlib.h>

typedef struct HonSo {
    int nguyen; // Phan nguyen
    int tu; // Tu so
    int mau; // Mau so
} ;

int timKiemTuyenTinh(HonSo b[], int kichThuoc, HonSo x) {
    for (int i = 0; i < kichThuoc; i++) {
        if (b[i].nguyen == x.nguyen && b[i].tu == x.tu && b[i].mau == x.mau) {
            return i;
        }
    }
    return -1;
}

void sapXepChanLe(HonSo b[], int kichThuoc) {
    int i, j;
    HonSo tam;
    for (i = 0; i < kichThuoc - 1; i++) {
        for (j = 0; j < kichThuoc - i - 1; j++) {
            if (b[j].nguyen % 2 != 0 && b[j + 1].nguyen % 2 == 0) {
                tam = b[j];
                b[j] = b[j + 1];
                b[j + 1] = tam;
            }
        }
    }
}

int soSanhHonSo(HonSo a, HonSo b) {
    if (a.nguyen != b.nguyen)
        return a.nguyen - b.nguyen;
    else
        return (a.tu * b.mau) - (b.tu * a.mau);
}

int timKiemNhiPhan(HonSo b[], int kichThuoc, HonSo x) {
    int trai = 0, phai = kichThuoc - 1;
    while (trai <= phai) {
        int giua = trai + (phai - trai) / 2;
        int soSanh = soSanhHonSo(b[giua], x);
        if (soSanh == 0)
            return giua;
        if (soSanh < 0)
            trai = giua + 1;
        else
            phai = giua - 1;
    }
    return -1;
}

void chiaMang(HonSo b[], int kichThuoc, int s1[], int s2[], int* kichThuoc1, int* kichThuoc2) {
    *kichThuoc1 = 0;
    *kichThuoc2 = 0;
    for (int i = 0; i < kichThuoc; i++) {
        s1[(*kichThuoc1)++] = b[i].nguyen;
        s2[(*kichThuoc2)++] = b[i].tu / b[i].mau;
    }
}

void xoaPhanTu(HonSo b[], int* kichThuoc, int k) {
    if (k < 0 || k >= *kichThuoc) return;
    for (int i = k; i < *kichThuoc - 1; i++) {
        b[i] = b[i + 1];
    }
    (*kichThuoc)--;
}

void chenPhanTu(HonSo b[], int* kichThuoc, HonSo x, int k) {
    if (k < 0 || k > *kichThuoc) return;
    for (int i = *kichThuoc; i > k; i--) {
        b[i] = b[i - 1];
    }
    b[k] = x;
    (*kichThuoc)++;
}

void taoMangPhanSo(HonSo b[], int kichThuoc, float c[]) {
    for (int i = 0; i < kichThuoc; i++) {
        c[i] = (b[i].nguyen * b[i].mau + b[i].tu) / (float)b[i].mau;
    }
}

HonSo tongMang(HonSo b[], int kichThuoc) {
    HonSo tong = { 0, 0, 1 }; // Khoi tao tong la 0
    for (int i = 0; i < kichThuoc; i++) {
        tong.nguyen += b[i].nguyen;
        tong.tu = tong.tu * b[i].mau + b[i].tu * tong.mau;
        tong.mau *= b[i].mau;
    }
    return tong;
}

HonSo timMax(HonSo b[], int kichThuoc) {
    HonSo max = b[0];
    for (int i = 1; i < kichThuoc; i++) {
        if (soSanhHonSo(b[i], max) > 0) {
            max = b[i];
        }
    }
    return max;
}

HonSo timMin(HonSo b[], int kichThuoc) {
    HonSo min = b[0];
    for (int i = 1; i < kichThuoc; i++) {
        if (soSanhHonSo(b[i], min) < 0) {
            min = b[i];
        }
    }
    return min;
}

void inViTriPhanNguyenChan(HonSo b[], int kichThuoc) {
    for (int i = 0; i < kichThuoc; i++) {
        if (b[i].nguyen % 2 == 0) {
            printf("Vi tri %d co phan nguyen chan\n", i);
        }
    }
}

void inViTriMaxMin(HonSo b[], int kichThuoc) {
    int viTriMax = 0, viTriMin = 0;
    for (int i = 1; i < kichThuoc; i++) {
        if (soSanhHonSo(b[i], b[viTriMax]) > 0) {
            viTriMax = i;
        }
        if (soSanhHonSo(b[i], b[viTriMin]) < 0) {
            viTriMin = i;
        }
    }
    printf("Phan tu lon nhat o vi tri %d\n", viTriMax);
    printf("Phan tu nho nhat o vi tri %d\n", viTriMin);
}

void inMang(HonSo b[], int kichThuoc) {
    for (int i = 0; i < kichThuoc; i++) {
        printf("%d %d/%d ", b[i].nguyen, b[i].tu, b[i].mau);
    }
    printf("\n");
}

int main() {
    HonSo b[100]; // Mang vi du
    int kichThuoc = 0; // Kich thuoc hien tai cua mang
    int s1[100], s2[100], kichThuoc1, kichThuoc2;
    float c[100];

    int luaChon;
    do {
        printf("\nMenu:\n");
        printf("1. Nhap mang hon so\n");
        printf("2. In mang hon so\n");
        printf("3. Tim kiem tuyen tinh x\n");
        printf("4. Sap xep mang (chan truoc, le sau)\n");
        printf("5. Tim kiem nhi phan x\n");
        printf("6. Chia mang thanh s1 va s2\n");
        printf("7. Xoa phan tu tai vi tri k\n");
        printf("8. Chen phan tu x tai vi tri k\n");
        printf("9. Tao mang phan so\n");
        printf("10. Tinh tong cac phan tu\n");
        printf("11. Tim phan tu lon nhat/nho nhat\n");
        printf("12. In vi tri phan nguyen chan\n");
        printf("13. In vi tri phan tu lon nhat/nho nhat\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &luaChon);

        switch (luaChon) {
        case 1: {
            printf("Nhap so luong hon so: ");
            scanf_s("%d", &kichThuoc);
            for (int i = 0; i < kichThuoc; i++) {
                printf("Nhap hon so thu %d (nguyen tu mau): ", i + 1);
                scanf_s("%d %d %d", &b[i].nguyen, &b[i].tu, &b[i].mau);
            }
            break;
        }
        case 2: {
            printf("Mang hon so: ");
            inMang(b, kichThuoc);
            break;
        }
        case 3: {
            HonSo x;
            printf("Nhap hon so x (nguyen tu mau): ");
            scanf_s("%d %d %d", &x.nguyen, &x.tu, &x.mau);
            int index = timKiemTuyenTinh(b, kichThuoc, x);
            if (index != -1)
                printf("Tim thay x tai vi tri %d\n", index);
            else
                printf("Khong tim thay x\n");
            break;
        }
        case 4: {
            sapXepChanLe(b, kichThuoc);
            printf("Da sap xep mang\n");
            inMang(b, kichThuoc);
            break;
        }
        case 5: {
            HonSo x;
            printf("Nhap hon so x (nguyen tu mau): ");
            scanf_s("%d %d %d", &x.nguyen, &x.tu, &x.mau);
            int index = timKiemNhiPhan(b, kichThuoc, x);
            if (index != -1)
                printf("Tim thay x tai vi tri %d\n", index);
            else
                printf("Khong tim thay x\n");
            break;
        }
        case 6: {
            chiaMang(b, kichThuoc, s1, s2, &kichThuoc1, &kichThuoc2);
            printf("Da chia mang thanh s1 va s2\n");
            printf("s1: ");
            for (int i = 0; i < kichThuoc1; i++) printf("%d ", s1[i]);
            printf("\ns2: ");
            for (int i = 0; i < kichThuoc2; i++) printf("%d ", s2[i]);
            printf("\n");
            break;
        }
        case 7: {
            int k;
            printf("Nhap vi tri k: ");
            scanf_s("%d", &k);
            xoaPhanTu(b, &kichThuoc, k);
            printf("Da xoa phan tu tai vi tri %d\n", k);
            inMang(b, kichThuoc);
            break;
        }
        case 8: {
            HonSo x;
            int k;
            printf("Nhap hon so x (nguyen tu mau): ");
            scanf_s("%d %d %d", &x.nguyen, &x.tu, &x.mau);
            printf("Nhap vi tri k: ");
            scanf_s("%d", &k);
            chenPhanTu(b, &kichThuoc, x, k);
            printf("Da chen phan tu x tai vi tri %d\n", k);
            inMang(b, kichThuoc);
            break;
        }
        case 9: {
            taoMangPhanSo(b, kichThuoc, c);
            printf("Da tao mang phan so:\n");
            for (int i = 0; i < kichThuoc; i++) {
                printf("%f ", c[i]);
            }
            printf("\n");
            break;
        }
        case 10: {
            HonSo tong = tongMang(b, kichThuoc);
            printf("Tong cac phan tu: %d %d/%d\n", tong.nguyen, tong.tu, tong.mau);
            break;
        }
        case 11: {
            HonSo max = timMax(b, kichThuoc);
            HonSo min = timMin(b, kichThuoc);
            printf("Phan tu lon nhat: %d %d/%d\n", max.nguyen, max.tu, max.mau);
            printf("Phan tu nho nhat: %d %d/%d\n", min.nguyen, min.tu, min.mau);
            break;
        }
        case 12: {
            inViTriPhanNguyenChan(b, kichThuoc);
            break;
        }
        case 13: {
            inViTriMaxMin(b, kichThuoc);
            break;
        }
        }
    } while (luaChon != 0);

    return 0;
}