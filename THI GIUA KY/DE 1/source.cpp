#include <iostream>
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

typedef struct Node* List;
struct Node {
  CuaHang data;
  List link;
};

int STRLEN(char *s);
int STRCMP(char *s1, char *s2);
int STRSTR(char *s1, char *s2);
void nhap_MotCuaHang(CuaHang &ch);
void xuat_MotCuaHang(CuaHang ch);
void nhap_DanhSachCacCuaHang(DaySo &ds);
void xuat_DanhSachCacCuaHang(DaySo ds);
int dem_SoLuongCuaHangChuaTen(DaySo ds);
void xoa_MotCuaHang(DaySo &ds, int pos);
void diChuyenThongTinCuaHangXuongCuoi(DaySo &ds, char *str);

void khoiTao(List &list);
List taoNode(CuaHang x);
List themCuoi(List &list, CuaHang x);
void giaiPhong(List &list);
void nhap_DSCH(List &list);
void xuat_DSCH(List l);
void sapXepDanhSachCuaHang(List &list);
void them_CuaHang(List &list);
void xuatMotCuaHang(List l);
void xuat_ThongTinTatCaCuaHangCuaQuan(List &list, char *str);

int main() {
  CuaHang ch;
  DaySo ds;
  nhap_DanhSachCacCuaHang(ds);
  xuat_DanhSachCacCuaHang(ds);

  int dem = dem_SoLuongCuaHangChuaTen(ds);
  cout << "\nSo luong cua hang co ten chua chuoi Tong Hop la " << dem << endl;

  cout << "\nNhap ma CH can di chuyen xuong cuoi: ";
  char str[5];
  cin.getline(str, 5);
  diChuyenThongTinCuaHangXuongCuoi(ds, str);
  cout << "\nDanh sach cua hang sau khi di chuyen";
  xuat_DanhSachCacCuaHang(ds);

  List ds1;
  nhap_DSCH(ds1);
  xuat_DSCH(ds1);

  sapXepDanhSachCuaHang(ds1);
  cout << "\n\nDanh sach cua hang sau khi sap xep: ";
  xuat_DSCH(ds1);

  them_CuaHang(ds1);
  cout << "\nDanh sach cua hang sau khi them la: ";
  xuat_DSCH(ds1);

  char stri[10];
  cout << "\n\nNhap quan can xuat thong tin tat ca cua hang: ";
  cin.getline(stri, 10);
  cout << "Thong tin cua tat ca cua hang tai quan " << stri;
  xuat_ThongTinTatCaCuaHangCuaQuan(ds1, stri);
  
  giaiPhong(ds1);
  system("pause");
  return 0;
}

int STRLEN(char *s) {
  int idx = 0;
  while (s[idx] != '\0') {
    idx++;
  }
  return idx;
}

int STRCMP(char *s1, char *s2) {
  int length_s1 = STRLEN(s1);
  int length_s2 = STRLEN(s2);
  int min = length_s1 < length_s2 ? length_s1 : length_s2;
  for (int i = 0; i < min; i++) {
    if (s1[i] < s2[i])
      return -1;
    else if (s1[i] > s2[i])
      return 1;
  }
  if (length_s1 > length_s2)
    return 1;
  else if (length_s1 < length_s2)
    return -1;
  return 0;
}

int STRSTR(char *s1, char *s2) {
  int length_s1 = STRLEN(s1);
  int length_s2 = STRLEN(s2);
  int start;
  bool check;
  for (int i = 0; i < length_s1; i++) {
    if (s1[i] == s2[0]) {
      start = i;
      check = true;
      int temp = start;
      for (int j = 1; j < length_s2; j++) {
        if (s1[++temp] != s2[j]) {
          check = false;
          break;
        }
      }
      if (check == true)
        return start;
    }
  }
  return -1;
}

// Cau 1
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
  cout << "\nMa CH: " << ch.maCH;
  cout << "\nTen CH: " << ch.tenCH;
  cout << "\nSo nha: " << ch.soNha;
  cout << "\nTen duong: " << ch.tenDuong;
  cout << "\nPhuong: " << ch.phuong;
  cout << "\nQuan: " << ch.quan;
  cout << "\nThanh pho: " << ch.thanhPho;
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
  for (int i = 0; i < ds.n; i++) {
    cout << "\n\tCua Hang " << i + 1;
    xuat_MotCuaHang(ds.data[i]);
  }
}

// Cau 1b
int dem_SoLuongCuaHangChuaTen(DaySo ds) {
  int dem = 0;
  for (int i = 0; i < ds.n; i++)
    if (STRSTR(ds.data[i].tenCH, (char *)"Tong Hop") != -1)
      dem++;
  return dem;
}

// Cau 1c
void xoa_MotCuaHang(DaySo &ds, int pos) {
  if (pos < 0 || pos > ds.n)
    cout << "\nNhap sai. Hay Nhap Lai";
  else {
    for (int i = pos + 1; i <= ds.n; i++)
      ds.data[i - 1] = ds.data[i];
    ds.n--;
  }
}

void diChuyenThongTinCuaHangXuongCuoi(DaySo &ds, char *str) {
  for (int i = 0; i < ds.n; i++) {
    if (STRCMP(ds.data[i].maCH, str) == 0) {
      CuaHang temp = ds.data[i];
      xoa_MotCuaHang(ds, i);
      ds.data[ds.n] = temp;
      ds.n++;
    }
  }
}

// Cau 2
void khoiTao(List &list) {
  list = NULL;
}

List taoNode(CuaHang x) {
  List p;
  p = new Node;
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
    cout << "\nNhap ma CH (NHAP 0 DE THOAT): ";
    cin >> ch.maCH;
    if (STRCMP(ch.maCH, (char *)"0") == 0)
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
  int idx = 1;
  while (l != NULL) {
    cout << "\n\n\tCua Hang " << idx++;
    cout << "\nMa CH: " << l->data.maCH;
    cout << "\nTen CH: " << l->data.tenCH;
    cout << "\nSo nha: " << l->data.soNha;
    cout << "\nTen Duong: " << l->data.tenDuong;
    cout << "\nPhuong: " << l->data.phuong;
    cout << "\nQuan: " << l->data.quan;
    cout << "\nThanh pho: " << l->data.thanhPho;
    l = l->link;
  }
}

void sapXepDanhSachCuaHang(List &list) {
  for (List pTmp = list; pTmp != NULL; pTmp = pTmp->link) {
    for (List pTmp2 = pTmp->link; pTmp2 != NULL; pTmp2 = pTmp2->link) {
      if (STRLEN(pTmp->data.thanhPho) > STRLEN(pTmp2->data.thanhPho)) {
        CuaHang tmp = pTmp->data;
        pTmp->data = pTmp2->data;
        pTmp2->data = tmp;
      }
    }
  }
}

void them_CuaHang(List &list) {
  CuaHang ch;
  List p = list;
  cout << "\n\nNhap ma CH can them: ";
  cin >> ch.maCH;
  cout << "Nhap ten CH can them: ";
  cin.ignore();
  cin.getline(ch.tenCH, 30);
  cout << "Nhap so nha can them: ";
  cin >> ch.soNha;
  cout << "Nhap ten duong can them: ";
  cin.ignore();
  cin.getline(ch.tenDuong, 30);
  cout << "Nhap phuong can them: ";
  cin.getline(ch.phuong, 10);
  cout << "Nhap quan can them: ";
  cin.getline(ch.quan, 10);
  cout << "Nhap thanh pho can them: ";
  cin.getline(ch.thanhPho, 30);
  cout << endl;
  themCuoi(list, ch);
  sapXepDanhSachCuaHang(list);
}

void xuatMotCuaHang(List l) {
  cout << "\nMa CH: " << l->data.maCH;
  cout << "\nTen CH: " << l->data.tenCH;
  cout << "\nSo nha: " << l->data.soNha;
  cout << "\nTen Duong: " << l->data.tenDuong;
  cout << "\nPhuong: " << l->data.phuong;
  cout << "\nQuan: " << l->data.quan;
  cout << "\nThanh pho: " << l->data.thanhPho;
  cout << "\n--------------------------------";
}

void xuat_ThongTinTatCaCuaHangCuaQuan(List &list, char *str) {
  for (List p = list; p != NULL; p = p->link)
    if (STRCMP(p->data.quan, str) == 0)
      xuatMotCuaHang(list);
}