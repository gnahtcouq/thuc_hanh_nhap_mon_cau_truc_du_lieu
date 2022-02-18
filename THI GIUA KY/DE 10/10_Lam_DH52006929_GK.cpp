#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
#define MAX 100

struct CuaHang {
  char maCH[5];
  char tenCH[30];
  int soNha;
  char tenDuong[30];
  char phuong[10];
  char quan[10];
  char thanhPho[30];
};

struct DaySo {
  int n;
  CuaHang data[MAX];
};

typedef struct NODE* List;
struct NODE {
  CuaHang data;
  List link;
};

void nhap_MotCuaHang(CuaHang &ch);
void xuat_MotCuaHang(CuaHang ch);
void nhap_DanhSachCacCuaHang(DaySo &ds);
void xuat_DanhSachCacCuaHang(DaySo ds);
int demSoLuongCuaHangCuaThanhPho(DaySo ds, char *s);
void diChuyenThongTinCuaHangVaoDau(DaySo &ds, char *str);

void khoiTao(List &list);
List taoNode(CuaHang x);
List themCuoi(List &list, CuaHang x);
void giaiPhong(List &list);
void nhap_DSCH(List &list);
void xuat_DSCH(List l);
void tachDanhSachCuaHang(List list, List &list1, List &list2);
void xoaCuaHangDauTienThuocQuan(List &l, char *s);

int main() {
  CuaHang ch;
  DaySo ds;
  nhap_DanhSachCacCuaHang(ds);
  xuat_DanhSachCacCuaHang(ds);

  char str[30];
  cout << "\nNhap ten thanh pho can dem so luong CH: ";
  cin.getline(str, 30);
  int dem = demSoLuongCuaHangCuaThanhPho(ds, str);
  cout << "So luong cua hang co tai thanh pho " << str << " la " << dem << endl;

  char strr[5];
  cout << "\nNhap ma CH can di chuyen thong tin ve dau: ";
  cin.getline(strr, 5);
  diChuyenThongTinCuaHangVaoDau(ds, strr);
  cout << "\nDanh sach cua hang sau khi di chuyen thong tin";
  xuat_DanhSachCacCuaHang(ds);


  List ds1, ds2, ds3;
  nhap_DSCH(ds1);
  xuat_DSCH(ds1);
  tachDanhSachCuaHang(ds1, ds2, ds3);
  cout << "\nDanh sach cac cua hang thuoc thanh pho HCM";
  xuat_DSCH(ds2);
  cout << "\nDanh sach cac cua hang con lai";
  xuat_DSCH(ds3);

  char strrr[10];
  cout << "\nNhap quan can xoa cua hang dau tien: ";
  cin.ignore();
  cin.getline(strrr, 10);
  xoaCuaHangDauTienThuocQuan(ds1, strrr);
  cout << "\nDanh sach cac cua hang con lai la: ";
  xuat_DSCH(ds1);

  
  giaiPhong(ds1);
  giaiPhong(ds2);
  giaiPhong(ds3);
  system("pause");
  return 0;
}

void nhap_MotCuaHang(CuaHang &ch) {
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
  cin.getline(ch.phuong, 10);
  cout << "Nhap quan: ";
  cin.getline(ch.quan, 10);
  cout << "Nhap thanh pho: ";
  cin.getline(ch.thanhPho, 30);
  cout << endl;
}

void xuat_MotCuaHang(CuaHang ch) {
  cout << setw(5) << left << ch.maCH << "\t";
  cout << setw(30) << left << ch.tenCH << "\t";
  cout << setw(5) << left << ch.soNha << "\t";
  cout << setw(30) << left << ch.tenDuong << "\t";
  cout << setw(10) << left << ch.phuong << "\t";
  cout << setw(10) << left << ch.quan << "\t";
  cout << setw(30) << left << ch.thanhPho << "\t";
  cout << endl;
}

void nhap_DanhSachCacCuaHang(DaySo &ds) {
  cout << "\nNhap so luong CH: ";
  cin >> ds.n;
  cout << "\t\tNHAP THONG TIN TUNG CUA HANG";
  for (int i = 0; i < ds.n; i++) {
    cout << "\n\tCua Hang " << i + 1;
    nhap_MotCuaHang(ds.data[i]);
  }
}

void xuat_DanhSachCacCuaHang(DaySo ds) {
  cout << "\n\n\t THONG TIN CAC CUA HANG" << endl;
  cout << setfill('-');
  cout << setw(120) << "-" << endl;
  cout << setfill(' ');
  cout << setw(5) << left << "Ma CH" << "\t";
  cout << setw(30) << left << "Ten CH" << "\t";
  cout << setw(5) << left << "So nha" << "\t" ;
  cout << setw(30) << left << "Ten duong" << "\t";
  cout << setw(10) << left << "Phuong" << "\t";
  cout << setw(10) << left << "Quan" << "\t";
  cout << setw(30) << left << "Thanh pho" << endl;
  for (int i = 0; i < ds.n; i++) {
    xuat_MotCuaHang(ds.data[i]);
  }
}

// Cau 1b
int demSoLuongCuaHangCuaThanhPho(DaySo ds, char *s) {
  int dem = 0;
  for (int i = 0; i < ds.n; i++)
    if (strcmp(ds.data[i].thanhPho, s) == 0)
      dem++;
  return dem;
}

// Cau 1c
void diChuyenThongTinCuaHangVaoDau(DaySo &ds, char *str) {
  for (int i = 0; i < ds.n; i++) {
    if (strcmp(ds.data[i].maCH, str) == 0) {
      swap(ds.data[i], ds.data[0]);
    }
  }
}

// Cau 2
void khoiTao(List &list) {
  list = NULL;
}

List taoNode(CuaHang x) {
  List p;
  p = new NODE;
  p->data = x;
  p->link = NULL;
  return p;
}

List themCuoi(List &list, CuaHang x) {
  List p = taoNode(x);
  if (list == NULL) {
    list = p;
  }
  else {
    List q = list;
    while (q->link != NULL) {
      q = q->link;
    }
    q->link = p;
  }
  return p;
}

void giaiPhong(List &list) {
  List p = list;
  while (p != NULL) {
    list = list->link;
    delete p;
    p = list;
  }
}

void nhap_DSCH(List &l) {
  CuaHang ch;
  khoiTao(l);
  do {
    cout << "\nNhap ma CH (NHAP Q DE THOAT): ";
    cin >> ch.maCH;
    if (strcmp(ch.maCH, (char *)"Q") == 0)
      break;
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
    themCuoi(l, ch);
  } while (1);
}

void xuat_DSCH(List l) {
  cout << "\n\n\t THONG TIN CAC CUA HANG" << endl;
  cout << setfill('-');
  cout << setw(120) << "-" << endl;
  cout << setfill(' ');
  cout << setw(5) << left << "Ma CH" << "\t";
  cout << setw(30) << left << "Ten CH" << "\t";
  cout << setw(5) << left << "So nha" << "\t" ;
  cout << setw(30) << left << "Ten duong" << "\t";
  cout << setw(10) << left << "Phuong" << "\t";
  cout << setw(10) << left << "Quan" << "\t";
  cout << setw(30) << left << "Thanh pho" << endl;
  while (l != NULL) {
  cout << setw(5) << left << l->data.maCH << "\t";
  cout << setw(30) << left << l->data.tenCH << "\t";
  cout << setw(5) << left << l->data.soNha << "\t";
  cout << setw(30) << left << l->data.tenDuong << "\t";
  cout << setw(10) << left << l->data.phuong << "\t";
  cout << setw(10) << left << l->data.quan << "\t";
  cout << setw(30) << left << l->data.thanhPho << "\t";
  cout << endl;
  l = l->link;
  }
}

// Cau 2b
void tachDanhSachCuaHang(List list, List &list1, List &list2) {
  char *str = (char *)"HCM";
  khoiTao(list1);
  khoiTao(list2);
  List p = list;
  CuaHang ds1, ds2;
  while (p != NULL) {
    if (strcmp(p->data.thanhPho, str) == 0) {
      ds1 = p->data;
      themCuoi(list1, ds1);
    }
    else {
      ds2 = p->data;
      themCuoi(list2, ds2);
    }
    p = p->link;
  }
}

// Cau 2c
void xoaCuaHangDauTienThuocQuan(List &l, char *s) {
  if (strcmp(l->data.quan, s) == 0) {
    List p = l;
    l = l->link;
    delete p;
  }
  else {
    List p, before;
    p = l;
    before = l;
    while (p != NULL && strcmp(p->data.quan, s) != 0) {
      before = p;
      p = p->link;
    }
    if (p != NULL) {
      before->link = p->link;
      delete p;
    }
  }
}