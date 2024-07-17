#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int phan_nguyen;
    int tu_so;
    int mau_so;
} HonSo;

// 1. Tao mang b chua gia tri hon so ngau nhien. Luu y mau khac 0.
void create_random_honso_array(HonSo* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i].phan_nguyen = rand() % 10; // Phan nguyen tu 0 den 9
        arr[i].tu_so = rand() % 10; // Tu so tu 0 den 9
        do {
            arr[i].mau_so = rand() % 9 + 1; // Mau so tu 1 den 9
        } while (arr[i].mau_so == 0);
    }
}

// 2. Xuat danh sach hon so
void print_honso_array(HonSo* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d/%d\n", arr[i].phan_nguyen, arr[i].tu_so, arr[i].mau_so);
    }
}

// 3. So sanh 2 hon so
int compare_honso(HonSo a, HonSo b) {
    int a_tu_so = a.phan_nguyen * a.mau_so + a.tu_so;
    int b_tu_so = b.phan_nguyen * b.mau_so + b.tu_so;
    int a_value = a_tu_so * b.mau_so;
    int b_value = b_tu_so * a.mau_so;
    if (a_value > b_value) return 1;
    else if (a_value < b_value) return -1;
    else return 0;
}

// 4. Chuyen hon so -> phan so
void honso_to_phanso(HonSo hs, int* tu_so, int* mau_so) {
    *tu_so = hs.phan_nguyen * hs.mau_so + hs.tu_so;
    *mau_so = hs.mau_so;
}

// 5. Chuyen phan so -> hon so
HonSo phanso_to_honso(int tu_so, int mau_so) {
    HonSo hs;
    hs.phan_nguyen = tu_so / mau_so;
    hs.tu_so = tu_so % mau_so;
    hs.mau_so = mau_so;
    return hs;
}

// 6. Tinh tong, hieu, tich, thuong 2 hon so
HonSo add_honso(HonSo a, HonSo b) {
    int tu_so_a, mau_so_a, tu_so_b, mau_so_b;
    honso_to_phanso(a, &tu_so_a, &mau_so_a);
    honso_to_phanso(b, &tu_so_b, &mau_so_b);
    int tu_so_result = tu_so_a * mau_so_b + tu_so_b * mau_so_a;
    int mau_so_result = mau_so_a * mau_so_b;
    return phanso_to_honso(tu_so_result, mau_so_result);
}

HonSo subtract_honso(HonSo a, HonSo b) {
    int tu_so_a, mau_so_a, tu_so_b, mau_so_b;
    honso_to_phanso(a, &tu_so_a, &mau_so_a);
    honso_to_phanso(b, &tu_so_b, &mau_so_b);
    int tu_so_result = tu_so_a * mau_so_b - tu_so_b * mau_so_a;
    int mau_so_result = mau_so_a * mau_so_b;
    return phanso_to_honso(tu_so_result, mau_so_result);
}

HonSo multiply_honso(HonSo a, HonSo b) {
    int tu_so_a, mau_so_a, tu_so_b, mau_so_b;
    honso_to_phanso(a, &tu_so_a, &mau_so_a);
    honso_to_phanso(b, &tu_so_b, &mau_so_b);
    int tu_so_result = tu_so_a * tu_so_b;
    int mau_so_result = mau_so_a * mau_so_b;
    return phanso_to_honso(tu_so_result, mau_so_result);
}

HonSo divide_honso(HonSo a, HonSo b) {
    int tu_so_a, mau_so_a, tu_so_b, mau_so_b;
    honso_to_phanso(a, &tu_so_a, &mau_so_a);
    honso_to_phanso(b, &tu_so_b, &mau_so_b);
    int tu_so_result = tu_so_a * mau_so_b;
    int mau_so_result = mau_so_a * tu_so_b;
    return phanso_to_honso(tu_so_result, mau_so_result);
}

// Sap xep mang hon so tang/giam dan theo Interchange Sort
void interchange_sort_honso(HonSo* arr, int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && compare_honso(arr[i], arr[j]) > 0) || (!ascending && compare_honso(arr[i], arr[j]) < 0)) {
                HonSo temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Sap xep mang hon so tang/giam dan theo Selection Sort
void selection_sort_honso(HonSo* arr, int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        int min_max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if ((ascending && compare_honso(arr[j], arr[min_max_idx]) < 0) || (!ascending && compare_honso(arr[j], arr[min_max_idx]) > 0)) {
                min_max_idx = j;
            }
        }
        HonSo temp = arr[min_max_idx];
        arr[min_max_idx] = arr[i];
        arr[i] = temp;
    }
}

// Sap xep mang hon so tang/giam dan theo Quick Sort
void quick_sort_honso(HonSo* arr, int left, int right, int ascending) {
    if (left >= right) return;
    HonSo pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if ((ascending && compare_honso(arr[j], pivot) < 0) || (!ascending && compare_honso(arr[j], pivot) > 0)) {
            i++;
            HonSo temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    HonSo temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    quick_sort_honso(arr, left, i, ascending);
    quick_sort_honso(arr, i + 2, right, ascending);
}

// Menu
int main() {
    srand(time(NULL));
    int n;
    printf("Nhap so luong phan tu trong mang hon so: ");
    scanf_s("%d", &n);
    HonSo* arr = (HonSo*)malloc(n * sizeof(HonSo));
    int choice;

    create_random_honso_array(arr, n);

    while (1) {
        printf("\nMenu:Bai2\n");
        printf("1. Tao mang hon so ngau nhien\n");
        printf("2. Xuat danh sach hon so\n");
        printf("3. So sanh hai hon so\n");
        printf("4. Chuyen hon so -> phan so\n");
        printf("5. Chuyen phan so -> hon so\n");
        printf("6. Tinh tong, hieu, tich, thuong hai hon so\n");
        printf("7. Sap xep tang/giam dan theo Interchange Sort\n");
        printf("8. Sap xep tang/giam dan theo Selection Sort\n");
        printf("9. Sap xep tang/giam dan theo Quick Sort\n");
        printf("10. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            create_random_honso_array(arr, n);
            printf("Mang hon so ngau nhien: \n");
            print_honso_array(arr, n);
            break;
        case 2:
            printf("Danh sach hon so: \n");
            print_honso_array(arr, n);
            break;
        case 3: {
            int index1, index2;
            printf("Nhap chi so cua hon so thu nhat: ");
            scanf_s("%d", &index1);
            printf("Nhap chi so cua hon so thu hai: ");
            scanf_s("%d", &index2);
            if (compare_honso(arr[index1], arr[index2]) == 0) {
                printf("Hai hon so bang nhau\n");
            }
            else if (compare_honso(arr[index1], arr[index2]) > 0) {
                printf("Hon so thu nhat lon hon hon so thu hai\n");
            }
            else {
                printf("Hon so thu nhat nho hon hon so thu hai\n");
            }
            break;
        }
        case 4: {
            int index, tu_so, mau_so;
            printf("Nhap chi so cua hon so: ");
            scanf_s("%d", &index);
            honso_to_phanso(arr[index], &tu_so, &mau_so);
            printf("Phan so tuong ung: %d/%d\n", tu_so, mau_so);
            break;
        }
        case 5: {
            int tu_so, mau_so;
            printf("Nhap tu so: ");
            scanf_s("%d", &tu_so);
            printf("Nhap mau so: ");
            scanf_s("%d", &mau_so);
            HonSo hs = phanso_to_honso(tu_so, mau_so);
            printf("Hon so tuong ung: %d %d/%d\n", hs.phan_nguyen, hs.tu_so, hs.mau_so);
            break;
        }
        case 6: {
            int index1, index2;
            printf("Nhap chi so cua hon so thu nhat: ");
            scanf_s("%d", &index1);
            printf("Nhap chi so cua hon so thu hai: ");
            scanf_s("%d", &index2);
            HonSo sum = add_honso(arr[index1], arr[index2]);
            HonSo diff = subtract_honso(arr[index1], arr[index2]);
            HonSo prod = multiply_honso(arr[index1], arr[index2]);
            HonSo quot = divide_honso(arr[index1], arr[index2]);
            printf("Tong: %d %d/%d\n", sum.phan_nguyen, sum.tu_so, sum.mau_so);
            printf("Hieu: %d %d/%d\n", diff.phan_nguyen, diff.tu_so, diff.mau_so);
            printf("Tich: %d %d/%d\n", prod.phan_nguyen, prod.tu_so, prod.mau_so);
            printf("Thuong: %d %d/%d\n", quot.phan_nguyen, quot.tu_so, quot.mau_so);
            break;
        }
        case 7:
            interchange_sort_honso(arr, n, 1);
            printf("Mang da sap xep tang dan theo Interchange Sort: \n");
            print_honso_array(arr, n);
            interchange_sort_honso(arr, n, 0);
            printf("Mang da sap xep giam dan theo Interchange Sort: \n");
            print_honso_array(arr, n);
            break;
        case 8:
            selection_sort_honso(arr, n, 1);
            printf("Mang da sap xep tang dan theo Selection Sort: \n");
            print_honso_array(arr, n);
            selection_sort_honso(arr, n, 0);
            printf("Mang da sap xep giam dan theo Selection Sort: \n");
            print_honso_array(arr, n);
            break;
        case 9:
            quick_sort_honso(arr, 0, n - 1, 1);
            printf("Mang da sap xep tang dan theo Quick Sort: \n");
            print_honso_array(arr, n);
            quick_sort_honso(arr, 0, n - 1, 0);
            printf("Mang da sap xep giam dan theo Quick Sort: \n");
            print_honso_array(arr, n);
            break;
        case 10:
            free(arr);
            return 0;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    }

    free(arr);
    return 0;
}
