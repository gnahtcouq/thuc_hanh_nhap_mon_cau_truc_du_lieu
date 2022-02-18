#include "Thang_DH52007101_B4_H.h"
int main() {
	Nodeptr list;
	khoiTao(list);
	//nhap_DanhSach(list);
	//cout << "\nDSLK vua nhap: ";
	//// Cau 1a Su dung ky thuat chen dau
	//// Cau 1b Ham giaiPhong(Nodeptr &list) giai phong bo nho
	//// Cau 1c Khi nhap 10 8 7 9 20 thi xuat Ket qua: 20 9 7 8 10
	//xuat_DanhSach(list);

	// Cau 2
	nhap_DanhSach1(list);
	xuat_DanhSach(list);

	// Cau 3
	//int x;
	//cout << "\nNhap phan tu can tim x = ";
	//cin >> x;
	//if (tim_Node_X(list, x) == NULL)
	//	cout << "\nPhan tu can tim khong co trong danh sach";
	//else
	//	cout << "\nPhan tu can tim co trong danh sach";

	// Cau 4
	//chenSau(list);

	// Cau 5
	//xoa_Dau(list);
	//cout << "\nDSLK sau khi xoa phan tu dau: ";
	//xuat_DanhSach(list);
	//xoa_Cuoi(list);
	//cout << "\nDSLK sau khi xoa phan tu cuoi: ";
	//xuat_DanhSach(list);

	// Cau 6
	//int x;
	//cout << "\nNhap phan tu can xoa x = ";
	//cin >> x;
	//del_node_x(list, x);
	//xuat_DanhSach(list);

	// Cau 7
	//cout << "\nDSLK sau khi dao nguoc la: ";
	//daoNguocDSLK(list);
	//xuat_DanhSach(list);

	// BTVN
	// Cau 1
	//Nodeptr chan, le;
	//tachDSLKChanLe(list, chan, le);
	//cout << "\nDanh sach 1 chua cac phan tu la so chan: ";
	//xuat_DanhSach(chan);
	//cout << "\nDanh sach 2 chua cac phan tu la so le: ";
	//xuat_DanhSach(le);

	// Cau 2
	int x;
	cout << "\nNhap phan tu can xoa x = ";
	cin >> x;
	del_All_X(list, x);
	cout << "\nDanh sach con lai sau khi xoa het cac phan tu " << x << " la: ";
	xuat_DanhSach(list);

	giaiPhong(list);
	cout << endl;

	system("pause");
	return 0;
}