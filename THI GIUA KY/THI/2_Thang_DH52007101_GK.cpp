#include <iostream>
#include <string.h>
#include <string>
using namespace std;
#define MAX 100

struct CuaHang {
  char maCH[5];
  char tenCH[30];
  int soNha;
  char tenDuong[30];
  char phuong[30];
  char quan[10];
  char thanhPho[30];
};
typedef struct CuaHang CUAHANG;
struct DaySo {
  int soLuong;
  CuaHang data[MAX];
};
typedef struct DaySo DAYSO;
void nhapCuaHang(CUAHANG& ch);
void xuatCuaHang(CUAHANG ch);
void nhapDanhSachCuaHang(DAYSO& ds);
void xuatDanhSachCuaHang(DAYSO ds);
int demSoLuongCuaHangCoTaiPhuongX(DAYSO ds, char *tenphuong);
void xoaCuaHangViTri(DAYSO& ds, int vitri);
void xoaTenCuaHang(DAYSO &ds, char *tench);

struct Node {
  CUAHANG data;
  Node* pNext;
};
typedef struct Node NODE;
struct List {
  NODE* pHead;
  NODE* pTail;
};
typedef struct List LIST;
void khoiTao(LIST& l);
NODE* taoNode(CUAHANG data);
void themCuoi(LIST& l, NODE* p);
void nhap(LIST& l);
void xuat(LIST l);
void giaiPhong(LIST& l);
int demSoLuongCuaHangChuaTen(LIST l);

int main() {
  CUAHANG ch;
  DAYSO ds;
  nhapDanhSachCuaHang(ds);
  xuatDanhSachCuaHang(ds);

  char tenphuong[30];
  cout << "\nNhap phuong can dem: ";
  cin.getline(tenphuong, 30);
  int dem = demSoLuongCuaHangCoTaiPhuongX(ds, tenphuong);
  cout << "Danh sach cua hang co tai phuong do la: " << dem << endl;

  char tench[30];
  cout << "\nNhap ten CH can xoa: ";
  cin.getline(tench, 30);
  xoaTenCuaHang(ds, tench);
  cout << "Danh sach CH sau khi xoa: ";
  xuatDanhSachCuaHang(ds);

  LIST l;
  nhap(l);
  xuat(l);
  int dem2 = demSoLuongCuaHangChuaTen(l);
  cout << "\nSo luong cua hang chua ten Bach Hoa la: " << dem2; 
  giaiPhong(l);
  return 0;
}

void nhapCuaHang(CUAHANG& ch) {
  cout << "\nNhap ma CH: ";
  cin >> ch.maCH;
  cout << "Nhap ten CH: ";
  cin.ignore();
  cin.getline(ch.tenCH, 30);
  cout << "Nhap so nha: ";
  cin >> ch.soNha;
  cout << "Nhap ten duong: ";
  cin.ignore();
  cin.getline(ch.tenDuong, 30);
  cout << "Nhap phuong: ";
  cin.getline(ch.phuong, 30);
  cout << "Nhap quan: ";
  cin.getline(ch.quan, 10);
  cout << "Nhap thanh pho: ";
  cin.getline(ch.thanhPho, 30);
  cout << endl;
}

void xuatCuaHang(CUAHANG ch) {
  cout << "\nMa CH: " << ch.maCH;
  cout << "\nTen CH: " << ch.tenCH;
  cout << "\nSo nha: " << ch.soNha;
  cout << "\nTen duong: " << ch.tenDuong;
  cout << "\nPhuong: " << ch.phuong;
  cout << "\nQuan: " << ch.quan;
  cout << "\nThanh pho: " << ch.thanhPho;
  cout << endl;
}

void nhapDanhSachCuaHang(DAYSO& ds) {
  cout << "\nNhap so luong CH: ";
  cin >> ds.soLuong;
  cout << "\nNhap thong tin tung CH: ";
  for (int i = 0; i < ds.soLuong; i++) {
    cout << "\n------- Thong Tin Cua Hang Thu " << i + 1 << " -------\n";
    nhapCuaHang(ds.data[i]);
  }
}

void xuatDanhSachCuaHang(DAYSO ds) {
  for (int i = 0; i < ds.soLuong; i++) {
    cout << "\n------- Thong Tin Cua Hang Thu " << i + 1 << " -------\n";
    xuatCuaHang(ds.data[i]);
  }
}

// Cau 1b
int demSoLuongCuaHangCoTaiPhuongX(DAYSO ds, char *tenphuong) {
  int dem = 0;
  for (int i = 0; i < ds.soLuong; i++) {
    if (strcmp(ds.data[i].phuong, tenphuong) == 0) {
      dem++;
    }
  }
  return dem;
}

// Cau 1c
void xoaCuaHangViTri(DAYSO& ds, int vitri) {
  if (vitri < 0 || vitri > ds.soLuong)
    cout << "\nVi tri khong hop le";
  else {
    for (int i = vitri + 1; i <= ds.soLuong; i++)
      ds.data[i - 1] = ds.data[i];
    ds.soLuong--;
  }
}

void xoaTenCuaHang(DAYSO &ds, char *tench) {
  for (int i = 0; i < ds.soLuong; i++) {
    if (strcmp(ds.data[i].tenCH, tench) == 0) {
      xoaCuaHangViTri(ds, i);
    }
  }
}

// Cau 2
void khoiTao(LIST& l) {
  l.pHead = l.pTail = NULL;
}

NODE* taoNode(CUAHANG data) {
  NODE* p = new NODE;
  if (p == NULL) {
    return NULL;
  }
  p->data = data;
  p->pNext = NULL;
  return p;
}

void themCuoi(LIST& l, NODE* p) {
  if (l.pHead == NULL) {
    l.pHead = l.pTail = p;
  }
  else {
    l.pTail->pNext = p;
    l.pTail = p;
  }
}

void nhap(LIST& l) {
  khoiTao(l);
  int n;
  cout << "\nNhap so luong CH: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    CUAHANG data;
    nhapCuaHang(data);
    NODE* p = taoNode(data);
    themCuoi(l, p);
  }
}

void xuat(LIST l) {
  int dem = 1;
  for (NODE* p = l.pHead; p != NULL; p = p->pNext) {
    cout << "\n------- Thong Tin Cua Hang Thu " << dem++ << " -------\n";
    xuatCuaHang(p->data);
  }
}

void giaiPhong(LIST& l) {
  NODE* p;
  while (l.pHead != NULL) {
    p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;
  }
}

// Cau 2c
int demSoLuongCuaHangChuaTen(LIST l) {
  char str[] = "Bach Hoa";
  int dem = 0;
  for (NODE* p = l.pHead; p != NULL; p = p->pNext) {
    if (strcmp(p->data.tenCH, str))
      dem++;
  }
  return dem;
}