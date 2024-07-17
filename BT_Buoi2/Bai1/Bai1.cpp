#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Tao mang mot chieu ngau nhien co so phan tu lon hon hoac bang 15
void create_random_array(int* arr, int n) {
    if (n < 15) n = 15;
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101; // So ngau nhien tu 0 den 100
    }
}

// 2. Tao mang chua toan so chan
int* create_even_array(int* arr, int n, int* new_n) {
    int* even_arr = (int*)malloc(n * sizeof(int));
    *new_n = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even_arr[(*new_n)++] = arr[i];
        }
    }
    return even_arr;
}

// 3. Tim kiem x trong a theo giai thuat tim kiem tuyen tinh Linear Search
int linear_search(int* arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// 4. Sap xep a tang dan/giam dan theo giai thuat Interchange Sort
void interchange_sort(int* arr, int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 5. Tim kiem x trong a theo giai thuat tim kiem Binary Search voi mang a da duoc sap tang
int binary_search(int* arr, int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// 6. Sap xep a tang dan theo giai thuat Selection Sort
void selection_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// 7. Sap xep a tang dan theo giai thuat Quick Sort
void quick_sort(int* arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    quick_sort(arr, left, i);
    quick_sort(arr, i + 2, right);
}

// Ham in mang
void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Menu
int main() {
    srand(time(NULL));
    int n;
    printf("Nhap so luong phan tu trong mang (>= 15): ");
    scanf_s("%d", &n);
    if (n < 15) n = 15;
    int* arr = (int*)malloc(n * sizeof(int));
    int choice, x, result;

    create_random_array(arr, n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tao mang mot chieu ngau nhien\n");
        printf("2. Tao mang chua toan so chan\n");
        printf("3. Tim kiem tuyen tinh\n");
        printf("4. Sap xep tang dan theo Interchange Sort\n");
        printf("5. Sap xep giam dan theo Interchange Sort\n");
        printf("6. Tim kiem nhi phan\n");
        printf("7. Sap xep tang dan theo Selection Sort\n");
        printf("8. Sap xep tang dan theo Quick Sort\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            create_random_array(arr, n);
            printf("Mang ngau nhien: ");
            print_array(arr, n);
            break;
        case 2: {
            int new_n;
            int* even_arr = create_even_array(arr, n, &new_n);
            printf("Mang chua toan so chan: ");
            print_array(even_arr, new_n);
            free(even_arr);
            break;
        }
        case 3:
            printf("Nhap gia tri can tim: ");
            scanf_s("%d", &x);
            result = linear_search(arr, n, x);
            if (result != -1) {
                printf("Gia tri %d nam o vi tri %d\n", x, result);
            }
            else {
                printf("Khong tim thay gia tri %d\n", x);
            }
            break;
        case 4:
            interchange_sort(arr, n, 1);
            printf("Mang da sap xep tang dan: ");
            print_array(arr, n);
            break;
        case 5:
            interchange_sort(arr, n, 0);
            printf("Mang da sap xep giam dan: ");
            print_array(arr, n);
            break;
        case 6:
            printf("Nhap gia tri can tim: ");
            scanf_s("%d", &x);
            selection_sort(arr, n);
            result = binary_search(arr, n, x);
            if (result != -1) {
                printf("Gia tri %d nam o vi tri %d\n", x, result);
            }
            else {
                printf("Khong tim thay gia tri %d\n", x);
            }
            break;
        case 7:
            selection_sort(arr, n);
            printf("Mang da sap xep tang dan theo Selection Sort: ");
            print_array(arr, n);
            break;
        case 8:
            quick_sort(arr, 0, n - 1);
            printf("Mang da sap xep tang dan theo Quick Sort: ");
            print_array(arr, n);
            break;
        case 9:
            free(arr);
            printf("Cam on vi da su dung chuong trinh. Tam biet <3\n");
            return 0;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    }

    free(arr);
    return 0;
}
