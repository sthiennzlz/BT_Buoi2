#include <stdio.h>
#include <stdlib.h>

void lietKeSoNguyenToNhoHonN(int n);
void tinhTongPhanTuChuSoDauLe(int arr[], int size);
void lietKeSoLanXuatHien(int arr[], int size);
void sapXepMang(int arr[], int size);
void dayConGiamDaiNhat(int arr[], int size);
void timSoNhoThuHai(int arr[], int size);
void timPhanTuChuaChuSo(int arr[], int size, int x);
void sapXepChanTangLeNguyenViTri(int arr[], int size);
void sapXepLeDauChanCuoi(int arr[], int size);
int laSoNguyenTo(int num);
int chuSoDauTien(int num);

int main() {
    int luaChon;
    int n, size, x;
    int arr[100];

    do {
        printf("\n--- MENU ---\n");
        printf("1. Liet ke cac so nguyen to nho hon n\n");
        printf("2. Tinh tong cac phan tu co chu so dau la chu so le\n");
        printf("3. Liet ke so lan xuat hien cua cac phan tu trong mang\n");
        printf("4. Sap xep mang co so chan tang dan, so le giam dan\n");
        printf("5. Tim day con giam dai nhat trong a\n");
        printf("6. Tim so nho thu 2 trong mang\n");
        printf("7. Tim cac phan tu chua cac chu so cua x\n");
        printf("8. Sap xep mang sao cho cac phan tu chan tang dan, cac phan tu le giu nguyen vi tri\n");
        printf("9. Sap xep mang: so le o dau mang, so chan o cuoi mang\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf_s("%d", &luaChon);

        switch (luaChon) {
        case 1:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            lietKeSoNguyenToNhoHonN(n);
            break;
        case 2:
            printf("Nhap kich thuoc mang: ");
            scanf_s("%d", &size);
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < size; i++) {
                scanf_s("%d", &arr[i]);
            }
            tinhTongPhanTuChuSoDauLe(arr, size);
            break;
        case 3:
            printf("Nhap kich thuoc mang: ");
            scanf_s("%d", &size);
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < size; i++) {
                scanf_s("%d", &arr[i]);
            }
            lietKeSoLanXuatHien(arr, size);
            break;
        case 4:
            printf("Nhap kich thuoc mang: ");
            scanf_s("%d", &size);
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < size; i++) {
                scanf_s("%d", &arr[i]);
            }
            sapXepMang(arr, size);
            break;
        case 5:
            printf("Nhap kich thuoc mang: ");
            scanf_s("%d", &size);
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < size; i++) {
                scanf_s("%d", &arr[i]);
            }
            dayConGiamDaiNhat(arr, size);
            break;
        case 6:
            printf("Nhap kich thuoc mang: ");
            scanf_s("%d", &size);
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < size; i++) {
                scanf_s("%d", &arr[i]);
            }
            timSoNhoThuHai(arr, size);
            break;
        case 7:
            printf("Nhap kich thuoc mang: ");
            scanf_s("%d", &size);
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < size; i++) {
                scanf_s("%d", &arr[i]);
            }
            printf("Nhap x: ");
            scanf_s("%d", &x);
            timPhanTuChuaChuSo(arr, size, x);
            break;
        case 8:
            printf("Nhap kich thuoc mang: ");
            scanf_s("%d", &size);
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < size; i++) {
                scanf_s("%d", &arr[i]);
            }
            sapXepChanTangLeNguyenViTri(arr, size);
            break;
        case 9:
            printf("Nhap kich thuoc mang: ");
            scanf_s("%d", &size);
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < size; i++) {
                scanf_s("%d", &arr[i]);
            }
            sapXepLeDauChanCuoi(arr, size);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Chuc nang khong hop le!\n");
        }
    } while (luaChon != 0);

    return 0;
}

void lietKeSoNguyenToNhoHonN(int n) {
    int found = 0;
    printf("Cac so nguyen to nho hon %d: ", n);
    for (int i = 2; i < n; i++) {
        if (laSoNguyenTo(i)) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co so nguyen to nao nho hon %d.\n", n);
    }
}

void tinhTongPhanTuChuSoDauLe(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (chuSoDauTien(arr[i]) % 2 != 0) {
            sum += arr[i];
        }
    }
    printf("Tong cac phan tu co chu so dau la chu so le: %d\n", sum);
}

void lietKeSoLanXuatHien(int arr[], int size) {
    int count[100] = { 0 };
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    printf("So lan xuat hien cua cac phan tu trong mang:\n");
    for (int i = 0; i < 100; i++) {
        if (count[i] > 0) {
            printf("%d: %d lan\n", i, count[i]);
        }
    }
}

void sapXepMang(int arr[], int size) {
    int even[100], odd[100];
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];
        }
        else {
            odd[oddCount++] = arr[i];
        }
    }

    // Sap xep mang chan tang dan
    for (int i = 0; i < evenCount - 1; i++) {
        for (int j = i + 1; j < evenCount; j++) {
            if (even[i] > even[j]) {
                int temp = even[i];
                even[i] = even[j];
                even[j] = temp;
            }
        }
    }

    // Sap xep mang le giam dan
    for (int i = 0; i < oddCount - 1; i++) {
        for (int j = i + 1; j < oddCount; j++) {
            if (odd[i] < odd[j]) {
                int temp = odd[i];
                odd[i] = odd[j];
                odd[j] = temp;
            }
        }
    }

    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < oddCount; i++) {
        printf("%d ", odd[i]);
    }
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");
}

void dayConGiamDaiNhat(int arr[], int size) {
    int lengths[100] = { 0 };
    int maxLength = 0;

    for (int i = 0; i < size; i++) {
        lengths[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i] && lengths[j] + 1 > lengths[i]) {
                lengths[i] = lengths[j] + 1;
            }
        }
        if (lengths[i] > maxLength) {
            maxLength = lengths[i];
        }
    }

    printf("Do dai cua day con giam dai nhat la: %d\n", maxLength);
}

void timSoNhoThuHai(int arr[], int size) {
    if (size < 2) {
        printf("Mang khong du phan tu de tim so nho thu 2.\n");
        return;
    }

    int first = INT_MAX, second = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MAX) {
        printf("Khong ton tai so nho thu 2.\n");
    }
    else {
        printf("So nho thu 2 trong mang la: %d\n", second);
    }
}

void timPhanTuChuaChuSo(int arr[], int size, int x) {
    int digit1 = x / 10;
    int digit2 = x % 10;

    printf("Cac phan tu chua cac chu so cua %d: ", x);
    for (int i = 0; i < size; i++) {
        int num = arr[i];
        int hasDigit1 = 0, hasDigit2 = 0;

        while (num > 0) {
            int digit = num % 10;
            if (digit == digit1) hasDigit1 = 1;
            if (digit == digit2) hasDigit2 = 1;
            num /= 10;
        }

        if (hasDigit1 && hasDigit2) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void sapXepChanTangLeNguyenViTri(int arr[], int size) {
    int even[100];
    int evenCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];
        }
    }

    // Sap xep mang chan tang dan
    for (int i = 0; i < evenCount - 1; i++) {
        for (int j = i + 1; j < evenCount; j++) {
            if (even[i] > even[j]) {
                int temp = even[i];
                even[i] = even[j];
                even[j] = temp;
            }
        }
    }

    printf("Mang sau khi sap xep: ");
    for (int i = 0, evenIndex = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", even[evenIndex++]);
        }
        else {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void sapXepLeDauChanCuoi(int arr[], int size) {
    int odd[100], even[100];
    int oddCount = 0, evenCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];
        }
        else {
            odd[oddCount++] = arr[i];
        }
    }

    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < oddCount; i++) {
        printf("%d ", odd[i]);
    }
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");
}

int laSoNguyenTo(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int chuSoDauTien(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}
