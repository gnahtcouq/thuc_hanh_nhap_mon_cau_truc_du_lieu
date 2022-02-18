#include "Thang_DH52007101_B6_H.h"

int main() {
    Dlist list;
    khoi_Tao(list);
    nhap_Ds(list);
    cout << "\nXuat danh sach theo chieu thuan: ";
    xuat_Ds_Thuan(list);

    // Cau 1
    cout << "\nXuat danh sach theo chieu nguoc: ";
    xuat_Ds_Nguoc(list);

    // Cau 2
    // Cau 3
    cout << "\nDanh sach sau khi xoa dau: ";
    xoa_Dau(list);
    xuat_Ds_Thuan(list);

    // Cau 4
    cout << "\nDanh sach sau khi xoa cuoi: ";
    xoa_Cuoi(list);
    xuat_Ds_Thuan(list);

    // Cau 5
    int x;
    cout << "\nNhap phan tu can tim: ";
    cin >> x;
    int result = tim_Vitri_X(list, x);
    if (result == -2)
        cout << "Khong co phan tu can tim";
    else
        cout << "Phan tu can tim o vi tri: " << result;

    giaiPhong(list);

    // Cau 6
    List list2;
    khoiTaoC(list2);
    readListC(list2);
    printListC(list2);

    // Cau 7a
    xoa_DauC(list2);
    cout << "\nDSLK vong sau khi xoa dau: ";
    printListC(list2);

    // Cau 7b
    xoa_CuoiC(list2);
    cout << "\nDSLK vong sau khi xoa cuoi: ";
    printListC(list2);

    // Cau 8
    int x2;
    cout << "\nNhap phan tu can tim: ";
    cin >> x2;
    int result2 = tim_Giatri_X_C(list2, x2);
    if (result2 == 0)
        cout << "Tim thay";
    else
        cout << "Khong tim thay";

    giaiPhong2(list2);

    cout << endl;
    system("pause");
    return 0;
}