#include "Thang_DH52007101_B2_H.h"
void nhapMonHoc(MonHoc& mh) {
	cout << "\n Nhap ma MH: ";
	cin >> mh.mamh;
	cout << "\n Nhap ten MH: ";
	cin.ignore();
	cin.getline(mh.tenmh, 30);
	cout << "\n Nhap so tin chi: ";
	cin >> mh.sotc;
}
void xuatMonHoc(MonHoc mh) {
	cout << "Ma MH" << "\t" << "TenMH" << "\t\t" << "SoTC" << endl;
		cout << mh.mamh << "\t" << mh.tenmh << "\t\t" <<
		mh.sotc << endl;
}

// Cau 2
void nhapDanhSachMonHoc(DanhSachMonHoc& ds) {
	cout << "\n Nhap so luong mon hoc: ";
	cin >> ds.so;
	cout << "\n Nhap thong tin tung mon hoc";
	for (int i = 0; i < ds.so; i++) {
		cout << "\n Thong tin mon hoc thu: " << i + 1 << endl;
		nhapMonHoc(ds.data[i]);
	}
}
void xuatDanhSachMonHoc(DanhSachMonHoc ds) {
	cout << "\n Danh sach cac mon hoc: " << endl;
	cout << "\n MaMH \t TenMH \t SoTC" << endl;
	for (int i = 0; i < ds.so; i++)
		xuatMonHoc(ds.data[i]);
}

// Cau 3
void them_MonHoc_ViTri(DanhSachMonHoc& ds, int vt, MonHoc mh) {
	if (vt<0 || vt>ds.so)
		cout << "\nVi tri khong hop le";
	else {
		for (int i = ds.so - 1; i >= vt; i--)
			ds.data[i + 1] = ds.data[i];
		ds.data[vt] = mh;
		ds.so++;
	}
}

// Cau 4a
void xoa_MonHoc_ViTri(DanhSachMonHoc& ds, int vt) {
	if (vt<0 || vt>ds.so)
		cout << "\nVi tri khong hop le";
	else {
		for (int i = vt + 1; i <= ds.so; i++)
			ds.data[i - 1] = ds.data[i];
		ds.so--;
	}
}
// Cau 4b
void xoa_ViTri_K(DanhSachMonHoc& ds, int k) {
	for (k = 0; k < ds.so; k++) {
		ds.data[k] = ds.data[k + 1];
		ds.so--;
	}
}
void xoa_maMonHoc(DanhSachMonHoc& ds, char* mamh) {
	for (int i = 0; i < ds.so; i++) {
		if (strcmp(ds.data[i].mamh, mamh) == 0)
			xoa_ViTri_K(ds, i);
	}
}

// Cau 5
// Giai thich: lenh strcmp dung de so sanh 2 chuoi voi nhau neu khong bang 0 thi chay bang 0 thi dung
int timKiemTuanTu(DanhSachMonHoc ds, char* ma) {
	int i = 0;
	while (i < ds.so && strcmp(ds.data[i].mamh, ma) != 0) {

		i++;
		if (i == ds.so)
			return -1;//Khong tim thay
		return i;
	}
}

// Cau 6a
void selectionSort(DanhSachMonHoc& ds) {
	MonHoc a;
	int min;
	for (int i = 0; i < ds.so - 1; i++) {
		min = i;
		for (int j = i + 1; j < ds.so; j++)
			if (ds.data[j].sotc < ds.data[min].sotc)
				min = j;
		a = ds.data[i];
		ds.data[i] = ds.data[min];
		ds.data[min] = a;
	}
}
// Cau 6b
void insertionSort(DanhSachMonHoc& ds) {
	MonHoc a;
	for (int i = 0; i < ds.so - 1; i++) {
		for (int j = i + 1; j < ds.so; j++) {
			if (ds.data[i].sotc < ds.data[j].sotc) {
				a = ds.data[i];
				ds.data[i] = ds.data[j];
				ds.data[j] = a;
			}
		}
	}
}