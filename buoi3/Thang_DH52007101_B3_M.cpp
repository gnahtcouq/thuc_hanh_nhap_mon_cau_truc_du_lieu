#include "Thang_DH52007101_B2_H.h"
int main() {
	MonHoc mh;
	DanhSachMonHoc ds;
	nhapMonHoc(mh);
	cout << "\n Mon hoc ban vua nhap: " << endl;
	xuatMonHoc(mh);

	// Cau 2
	nhapDanhSachMonHoc(ds);
	xuatDanhSachMonHoc(ds);

	// Cau 3
	int vt;
	cout << "\nNhap vi tri muon them vao: ";
	cin >> vt;
	nhapMonHoc(mh);
	them_MonHoc_ViTri(ds, vt, mh);
	cout << "\nDanh sach sau khi them: ";
	xuatDanhSachMonHoc(ds);

	// Cau 4a
	cout << "\nNhap vi tri can xoa: ";
	cin >> vt;
	xoa_MonHoc_ViTri(ds, vt);
	cout << "\nDanh sach sau khi xoa: ";
	xuatDanhSachMonHoc(ds);
	// Cau 4b
	char mamh[10];
	cout << "\nNhap ma MH can xoa: ";
	cin.ignore();
	cin.getline(mamh, 10);
	xoa_maMonHoc(ds, mamh);
	xuatDanhSachMonHoc(ds);

	// Cau 5
	cout << "\nNhap ma MH muon tim: ";
	cin >> mh.mamh;
	int k = timKiemTuanTu(ds, mh.mamh);
	if (k == -1)
		cout << "\nKhong co ma MH trong DS";
	else {
		cout << "\nCo mon hoc ban can tim: ";
		cout << endl;
		xuatMonHoc(ds.data[k]);
	}

	// Cau 6
	cout << "\nSap xep danh sach mon hoc theo so tin chi tang dan";
	selectionSort(ds);
	xuatDanhSachMonHoc(ds);

	cout << "\nSap xep danh sach mon hoc theo so tin chi giam dan";
	insertionSort(ds);
	xuatDanhSachMonHoc(ds);
	return 0;
}