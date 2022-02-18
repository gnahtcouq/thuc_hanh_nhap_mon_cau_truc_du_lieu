#include "Thang_DH52007101_B2_H.h"

//Cau 1
void khoiTao(DaySo& x) {
    x.n = 0;
}
//Ham kiem tra rong
int isEmpty(DaySo x) {
    return (x.n == 0 ? 1 : 0);
}
//Ham kiem tra day
int isFull(DaySo x) {
    return (x.n == MAX ? 1 : 0);
}
//Ham tra ve so nut cua DS dac
int listSize(DaySo x) {
    return x.n;
}
/********Ham nhap day so vao ds DAC***********/
void doc_DanhSach(DaySo& x) {
    cout << "\n Nhap vao so phan tu cua DS: ";
    cin >> x.n;
    for (int i = 0; i < x.n; i++)
    {
        cout << "\n Nhap vao phan tu thu " << i + 1 << ": ";
        cin >> x.ds[i];
    }
}
/********Ham xuat ra DS DAC***************/
void xuat_DanhSach(DaySo x) {
    cout << "\n Phan tu trong DS: ";
    for (int i = 0; i < x.n; i++)
        cout << x.ds[i] << " ";
}
//Cau 2
void chen_ViTri(DaySo& x, int pos, int a) {
    if (pos < 0 || pos > listSize(x))
        cout << "\n Vi tri " << pos << " khong hop le";
    else if (isEmpty(x) == 1) {
        if (pos == 0) {
            x.ds[0] = a;
            x.n++;
        }
        else
            cout << "\n Vi tri khong hop le";
    }
    else if (isFull(x) == 1)
        cout << "\n Danh sach day";
    else {
        for (int i = listSize(x) - 1; i >= pos; i--)
            x.ds[i + 1] = x.ds[i];
        x.ds[pos] = a;
        x.n++;
    }
}

//Cau 3
void xoa_ViTri(DaySo& x, int pos) {
    int i;
    if (pos < 0 || pos > listSize(x) - 1)
        cout << "Vi tri" << pos << "khong hop le !";
    else if (isEmpty(x))
        cout << "DS bi rong";
    else {
        for (i = pos + 1; i <= listSize(x); i++)
            x.ds[i - 1] = x.ds[i];
        x.n--;
    }
}

//Cau 4
void xoa_GiaTri_K(DaySo& x, int k) {
    for (int i = 0; i < x.n; i++) {
        if (x.ds[i] == k) {
            for (int j = i; j < x.n - 1; j++)
                x.ds[j] = x.ds[j + 1];
            x.n--;
        }
    }
}
//Cau 5
int timKiem_TuanTu(DaySo x, int a) {
    int i = 0;
    while (i < x.n && x.ds[i] != a)
        i++;
    if (i == x.n)
        return -1; //Khong tim thay
    return i;
}
//Cau 6
void sapXep(DaySo& x) {
    for (int i = 0; i < x.n - 1; i++)
        for (int j = i + 1; j < x.n; j++)
            if (x.ds[j] < x.ds[i]) {
                int tam = x.ds[i];
                x.ds[i] = x.ds[j];
                x.ds[j] = tam;
            }
}
int timKiem_NhiPhan(DaySo x, int a) {
    int bottom = 0, top = x.n - 1;
    int mid;
    do {
        mid = (bottom + top) / 2;
        if (a == x.ds[mid])
            return mid;
        else if (a < x.ds[mid])
            top = mid - 1;
        else
            bottom = mid + 1;
    } while (bottom <= top);
    return -1;
}

//Cau 7