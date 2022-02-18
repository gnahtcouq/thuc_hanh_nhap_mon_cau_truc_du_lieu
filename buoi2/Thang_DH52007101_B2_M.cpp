#include "Thang_DH52007101_B2_H.h"


int main() {
    //Cau 1
    DaySo x;
    khoiTao(x); //Ham nay de khoi tao danh sach dac
    doc_DanhSach(x); //Ham nay de nhap day so vao danh sach dac
    xuat_DanhSach(x); //Ham nay de xuat danh sach dac
    if (isEmpty(x) == 0) //Ham nay de Kiem tra danh sach co rong hay khong, neu khong tra ve 1
        cout << "\nCau1. Danh sach rong";
    else
        cout << "\nCau1. Danh sach day";
    if (isFull(x) == 0) //Ham nay de Kiem tra danh sach co day hay khong, neu = MAX tra ve 1
        cout << "\nCau1. Danh sach khong day";
    else
        cout << "\nCau1. Danh sach day";
    cout << "\nCau1. Xac dinh so phan tu cua danh sach " << listSize(x); //Ham nay de Xac dinh so phan tu cua danh sach

    //Cau 2
    int pos, a, k;
    cout << "\nCau2. Nhap phan tu can chen: ";
    cin >> k;
    cout << "\nCau2. Nhap vi tri can chen: ";
    cin >> pos;
    chen_ViTri(x, pos, k);
    xuat_DanhSach(x);

    //Cau 3
    cout << "\nCau3. Nhap vi tri can xoa: ";
    cin >> pos;
    xoa_ViTri(x, pos);
    xuat_DanhSach(x);

    //Cau 4
    xoa_GiaTri_K(x, k);
    //Cau 5
    cout << "\nCau5. Nhap phan tu k can tim: ";
    cin >> k;
    pos = timKiem_TuanTu(x, k);
    if (pos == -1)
        cout << "\nCau5. Khong tim thay";
    else
        cout << "\nCau5. Tim thay " << k << " o vi tri " << pos;
    //Cau 6
    sapXep(x);
    cout << "\nCau6. Danh sach sau khi sap xep ";
    xuat_DanhSach(x);

    //Cau 7

    return 0;
}