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
void nhapDanhSachMonHoc(DanhSachMonHoc& ds);
void xuatDanhSachMonHoc(DanhSachMonHoc ds);
void them_MonHoc_ViTri(DanhSachMonHoc& ds, int vt, MonHoc mh);
void xoa_MonHoc_ViTri(DanhSachMonHoc& ds, int vt);
void xoa_maMonHoc(DanhSachMonHoc &ds, char *mamh);

int main() {
  MonHoc mh;
  DanhSachMonHoc ds;
  // nhapMonHoc(mh);
  // cout << "\nMon hoc ban vua nhap: " << endl;
  // xuatMonHoc(mh);

  // Cau 2
  nhapDanhSachMonHoc(ds);
  xuatDanhSachMonHoc(ds);

  // Cau 3
  int vt;
  cout << "\nNhap vi tri MH can them: ";
  cin >> vt;
  cout << "Nhap thong tin mon hoc can them: " << endl;
  nhapMonHoc(mh);
  them_MonHoc_ViTri(ds, vt, mh);
  cout << "Danh sach MH sau khi them: ";
  xuatDanhSachMonHoc(ds);

  // Cau 4
  cout << "\nNhap vi tri MH can xoa: ";
  cin >> vt;
  xoa_MonHoc_ViTri(ds, vt);
  cout << "Danh sach MH sau khi xoa: ";
  xuatDanhSachMonHoc(ds);

  char mamh[10];
  cout << "\nNhap ma MH can xoa: ";
  cin.ignore();
  cin.getline(mamh, 10);
  xoa_maMonHoc(ds, mamh);
  cout << "Danh sach MH sau khi xoa: ";
  xuatDanhSachMonHoc(ds);

  return 0;
}


void nhapMonHoc(MonHoc& mh) {
  cout << "Nhap ma MH: ";
  cin >> mh.mamh;
  cout << "Nhap ten MH: ";
  cin.ignore();
  cin.getline(mh.tenmh, 30);
  cout << "Nhap so TC: ";
  cin >> mh.sotc;
}

void xuatMonHoc(MonHoc mh) {
  cout << "MaMH" << "\t" << "TenMH" << "\t\t" << "SoTC" << endl;
  cout << mh.mamh << "\t" << mh.tenmh << "\t\t" << mh.sotc << endl;
}

// Cau 2
void nhapDanhSachMonHoc(DanhSachMonHoc& ds) {
  cout << "\nNhap so luong MH: ";
  cin >> ds.so;
  cout << "\nNhap thong tin tung MH: ";
  for (int i = 0; i < ds.so; i++) {
    cout << "\nThong tin MH thu " << i + 1 << endl;
    nhapMonHoc(ds.data[i]);
  }
}

void xuatDanhSachMonHoc(DanhSachMonHoc ds) {
  cout << "\nDanh sach cac MH: " << endl;
  for (int i = 0; i < ds.so; i++)
    xuatMonHoc(ds.data[i]);
}

// Cau 3
void them_MonHoc_ViTri(DanhSachMonHoc& ds, int vt, MonHoc mh) {
  if (vt < 0 || vt > ds.so)
    cout << "\n Vi tri khong hop le";
  else {
    for (int i = ds.so - 1; i >= vt; i--)
      ds.data[i + 1] = ds.data[i];
    ds.data[vt] = mh;
    ds.so++;
  }
}

// Cau 4
void xoa_MonHoc_ViTri(DanhSachMonHoc& ds, int vt) {
  if (vt < 0 || vt > ds.so)
    cout << "\n vi tri khong hop le";
  else {
    for (int i = vt + 1; i <= ds.so; i++)
      ds.data[i - 1] = ds.data[i];
    ds.so--;
  }
}

void xoa_maMonHoc(DanhSachMonHoc &ds, char *mamh) {
  for (int i = 0; i < ds.so; i++) {
    if (strcmp(ds.data[i].mamh, mamh) == 0)
      xoa_MonHoc_ViTri(ds, i);
  }
}
