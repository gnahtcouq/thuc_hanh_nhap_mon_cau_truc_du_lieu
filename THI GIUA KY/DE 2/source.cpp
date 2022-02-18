#include <iostream>
#include <math.h>
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
int kiemtraSNT(int n);
void xuat_ThongTinCuaHangCoSoNhaLaSNT(DaySo ds);
void daoNguocDanhSach(DaySo &ds);

void khoiTao(List &list);
List taoNode(CuaHang x);
List themCuoi(List &list, CuaHang x);
void giaiPhong(List &list);
void nhap_DSCH(List &list);
void xuat_DSCH(List l);
void sapXepDanhSachCuaHang(List &list);
void them_CuaHang(List &list);
int kiemTraDSLKTangDanTheoMaCH(List list);

int main() {
  CuaHang ch;
  DaySo ds;
  nhap_DanhSachCacCuaHang(ds);
  xuat_DanhSachCacCuaHang(ds);
  cout << "\nThong tin cua cac cua hang co so nha la SNT la: ";
  xuat_ThongTinCuaHangCoSoNhaLaSNT(ds);

  cout << "\nDanh sach sau khi dao nguoc la: ";
  daoNguocDanhSach(ds);

  List ds1;
  nhap_DSCH(ds1);
  xuat_DSCH(ds1);

  sapXepDanhSachCuaHang(ds1);
  cout << "\n\nDanh sach cua hang sau khi sap xep: ";
  xuat_DSCH(ds1);
  them_CuaHang(ds1);
  cout << "\nDanh sach cua hang sau khi them la: ";
  xuat_DSCH(ds1);

  int ketqua = kiemTraDSLKTangDanTheoMaCH(ds1);
  if (ketqua == 1)
    cout << "\nMa CH co duoc sap xep tang dan";
  else
    cout << "\nMa CH khong duoc sap xep tang dan";

  
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
int kiemtraSNT(int n) {
  if (n < 2)
    return 0; // Khong thoa
  else if (n > 2) {
    if (n % 2 == 0)
      return 0; // Khong thoa
    for (int i = 3;i <= (int)sqrt((double)n);i += 2) {
      if (n % i == 0)
        return 0; // Khong thoa
    }
  }
  return 1; // Thoa
}

void xuat_ThongTinCuaHangCoSoNhaLaSNT(DaySo ds) {
  for (int i = 0; i < ds.n; i++) {
    if (kiemtraSNT(ds.data[i].soNha) == 1)
      xuat_MotCuaHang(ds.data[i]);
  }
}

// Cau 1c
void daoNguocDanhSach(DaySo &ds) {
  int i, j = ds.n - 1;
  for (i = 0; i < ds.n / 2; i++) {
    CuaHang temp = ds.data[i];
    ds.data[i] = ds.data[j];
    ds.data[j] = temp;
    j--;
  }
  for (i = 0; i < ds.n; i++) {
    xuat_MotCuaHang(ds.data[i]);
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
      if (STRLEN(pTmp->data.tenCH) < STRLEN(pTmp2->data.tenCH)) {
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

int kiemTraDSLKTangDanTheoMaCH(List list) {
  for (List pTmp = list; pTmp != NULL; pTmp = pTmp->link) {
    for (List pTmp2 = pTmp->link; pTmp2 != NULL; pTmp2 = pTmp2->link) {
      if (STRLEN(pTmp->data.maCH) < STRLEN(pTmp2->data.maCH))
        return 1;
    }
  }
  return 0;
}