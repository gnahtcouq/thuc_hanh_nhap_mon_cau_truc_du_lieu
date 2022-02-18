#include<iostream>
#include<string.h>
using namespace std;
const int MAX = 50;
struct MonHoc {
	char mamh[10];
	char tenmh[30];
	int sotc;
};
struct DanhSachMonHoc {
	int so;
	MonHoc data[MAX];
};
void nhapMonHoc(MonHoc& mh);
void xuatMonHoc(MonHoc mh);

// Cau 2
void nhapDanhSachMonHoc(DanhSachMonHoc& ds);
void xuatDanhSachMonHoc(DanhSachMonHoc ds);

// Cau 3
void them_MonHoc_ViTri(DanhSachMonHoc& ds, int vt, MonHoc mh);

// Cau 4a
void xoa_MonHoc_ViTri(DanhSachMonHoc& ds, int vt);
// Cau 4b
void xoa_ViTri_K(DanhSachMonHoc& ds, int k);
void xoa_maMonHoc(DanhSachMonHoc& ds, char* mamh);

// Cau 5
int timKiemTuanTu(DanhSachMonHoc ds, char* ma);

// Cau 6a
void selectionSort(DanhSachMonHoc& ds);
// Cau 6b
void insertionSort(DanhSachMonHoc& ds);