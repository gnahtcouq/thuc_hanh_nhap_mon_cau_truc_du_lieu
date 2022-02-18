#include<iostream>
using namespace std;
const int MAX = 50;
//Cau truc DS DAC
struct DaySo {
  int ds[MAX];
  int n; //So Phan tu ds dac
};
void khoiTao(DaySo& x);
int isEmpty(DaySo x);
int isFull(DaySo x);
int listSize(DaySo x);
void doc_DanhSach(DaySo& x);
void xuat_DanhSach(DaySo x);
void chen_ViTri(DaySo& x, int pos, int a);
void xoa_ViTri(DaySo& x, int pos);
void xoa_GiaTri_K(DaySo& x, int k);
int timKiem_TuanTu(DaySo x, int a);
void sapXep(DaySo& x);
int timKiem_NhiPhan(DaySo x, int a);
void nhapDanhSachSoNguyen(DaySo& x);
void xuatDanhSachSoNguyen(DaySo x);
int demSoLuongPhanTuTrongMang(DaySo x, int &a);
void xuatViTriXCoTrongMang(DaySo x, int &a);
void ghepHaiDanhSach(DaySo s1, DaySo s2, DaySo& s3);
void tachHaiDanhSachChanLe(DaySo s1, DaySo &dsChan, DaySo &dsLe);

int main() {
  // DaySo x;
  // khoiTao(x);
  // doc_DanhSach(x);
  // xuat_DanhSach(x);

  // // Cau 2
  // int pos, a, k;
  // cout << endl;
  // cout << "\nNhap vao phan tu can chen: ";
  // cin >> k;
  // cout << "Nhap vao vi tri can chen: ";
  // cin >> pos;
  // chen_ViTri(x, pos, k);
  // cout << "Danh sach sau khi chen la: ";
  // xuat_DanhSach(x);
  // cout << endl;

  // // Cau 3
  // cout << "\nNhap vi tri can xoa: ";
  // cin >> pos;
  // xoa_ViTri(x, pos);
  // cout << "Danh sach sau khi xoa la: ";
  // xuat_DanhSach(x);

  // // Cau 4
  // cout << endl;
  // cout << "\nNhap gia tri can xoa: ";
  // cin >> k;
  // xoa_GiaTri_K(x, k);
  // cout << "Danh sach sau khi xoa la: ";
  // xuat_DanhSach(x);

  // // Cau 5
  // cout << endl;
  // cout << "\nNhap phan tu can tim: ";
  // cin >> k;
  // int cau5 = timKiem_TuanTu(x, k);
  // if (cau5 == -1)
  //   cout << "Khong tim thay";
  // else
  //   cout << "Tim thay " << k << " tai vi tri thu " << cau5;

  // // Cau 6
  // cout << endl;
  // cout << "\nDay so sau khi sap xep tang dan: ";
  // sapXep(x);
  // xuat_DanhSach(x);

  // cout << "\nNhap phan tu can tim: ";
  // cin >> a;
  // int cau6 = timKiem_NhiPhan(x, a);
  // if (cau6 == -1)
  //   cout << "Khong tim thay";
  // else
  //   cout << "Tim thay";

  // Cau 7
  // DaySo y;
  // khoiTao(y);
  // nhapDanhSachSoNguyen(y);
  // xuatDanhSachSoNguyen(y);

  // int z;
  // cout << "\nNhap phan tu can dem: ";
  // cin >> z;
  // int cau7 = demSoLuongPhanTuTrongMang(y, z);
  // cout << "So luong phan tu " << z << " co trong mang la: " << cau7;
  // cout << "\nVi tri cua cac phan tu " << z << " co trong mang la: ";
  // xuatViTriXCoTrongMang(y, z);

  // BTVN
  DaySo s1, s2, s3, dsChan, dsLe;
  khoiTao(s1);
  khoiTao(s2);
  khoiTao(s3);
  khoiTao(dsChan);
  khoiTao(dsLe);
  nhapDanhSachSoNguyen(s1);
  nhapDanhSachSoNguyen(s2);
  cout << "\nDanh sach 1: ";
  xuatDanhSachSoNguyen(s1);
  cout << "\nDanh sach 2: ";
  xuatDanhSachSoNguyen(s2);
  ghepHaiDanhSach(s1, s2, s3);

  tachHaiDanhSachChanLe(s3, dsChan, dsLe);

  // system("pause");
  return 0;
}


//Hàm khoi tao
void khoiTao(DaySo& x) {
  x.n = 0;
}
//Ham kiem tra rong
int isEmpty(DaySo x) {
  return (x.n == 0 ? 1 : 0);
}
//Ham kiem tra day
int isFull(DaySo x) {
  return (x.n == MAX ? 1 : 0);
}
//Ham tra ve so nut cua DS dac
int listSize(DaySo x) {
  return x.n;
}

// Ham nhap day so vao danh sach dac
void doc_DanhSach(DaySo& x) {
  cout << "\nNhap vao so phan tu cua DS: ";
  cin >> x.n;
  for (int i = 0; i < x.n; i++) {
    cout << "Nhap vao phan tu thu " << i + 1 << " la: ";
    cin >> x.ds[i];
  }
}

// Ham xuat ra danh sach dac
void xuat_DanhSach(DaySo x) {
  for (int i = 0; i < x.n; i++)
    cout << x.ds[i] << " ";
}

// Cau 2
void chen_ViTri(DaySo& x, int pos, int a) {
  if (pos < 0 || pos > listSize(x))
    cout << "\n Vi tri " << pos << " khong hop le";
  else if (isEmpty(x) == 1) {
    if (pos == 0) {
      x.ds[0] = a;
      x.n++;
    }
    else
      cout << "\n Vi tri khong hop le";
  }
  else if (isFull(x) == 1)
    cout << "\n Danh sach day";
  else {
    for (int i = listSize(x) - 1; i >= pos; i--)
      x.ds[i + 1] = x.ds[i];
    x.ds[pos] = a;
    x.n++;
  }
}

// Cau 3
void xoa_ViTri(DaySo& x, int pos) {
  int i;
  if (pos<0 || pos>listSize(x) - 1)
    cout << "Vi tri" << pos << "khong hop le !";
  else if (isEmpty(x)) cout << "DS bi rong";
  else {
    for (i = pos + 1; i <= listSize(x); i++)
      x.ds[i - 1] = x.ds[i];
    x.n--;
  }
}

// Cau 4
void xoa_GiaTri_K(DaySo& x, int k) {
  for (int i = 0; i < x.n; i++) {
    if (x.ds[i] == k) {
      for (int j = i; j < x.n - 1; j++)
        x.ds[j] = x.ds[j + 1];
      x.n--;
    }
  }
}

// Cau 5
int timKiem_TuanTu(DaySo x, int a) {
  int i = 0;
  while (i < x.n && x.ds[i] != a)
    i++;
  if (i == x.n)
    return -1;//Khong tim thay
  return i;
}

// Cau 6
void sapXep(DaySo& x) {
  for (int i = 0; i < x.n - 1; i++)
    for (int j = i + 1; j < x.n;j++)
      if (x.ds[j] < x.ds[i]) {
        int tam = x.ds[i];
        x.ds[i] = x.ds[j];
        x.ds[j] = tam;
      }
}

int timKiem_NhiPhan(DaySo x, int a) {
  int bottom = 0, top = x.n - 1;
  int mid;
  do {
    mid = (bottom + top) / 2;
    if (a == x.ds[mid])
      return mid;
    else if (a < x.ds[mid])
      top = mid - 1;
    else bottom = mid + 1;
  } while (bottom <= top);
  return -1;
}

// Cau 7
void nhapDanhSachSoNguyen(DaySo& x) {
  cout << "\nNhap vao so phan tu cua DS: ";
  cin >> x.n;
  int temp;
  int i = 0;
  while (i < x.n) {
    cout << "Nhap vao phan tu thu " << i + 1 << " la: ";
    cin >> temp;
    if (temp > 0) {
      x.ds[i] = temp;
      i++;
    }
    else
      cout << "\nNhap sai. Hay nhap lai";
  }
}

void xuatDanhSachSoNguyen(DaySo x) {
  for (int i = 0; i < x.n; i++)
    cout << x.ds[i] << " ";
}

int demSoLuongPhanTuTrongMang(DaySo x, int &a) {
  int dem = 0;
  for (int i = 0; i < x.n; i++) {
    if (a == x.ds[i])
      dem++;
  }
  return dem;
}

void xuatViTriXCoTrongMang(DaySo x, int &a) {
  for (int i = 0; i < x.n; i++) {
    if (a == x.ds[i])
      cout << i << " ";
  }
}

// BTVN
void ghepHaiDanhSach(DaySo s1, DaySo s2, DaySo& s3) {
  s3.n = s1.n + s2.n;
  for (int i = 0; i < s1.n; i++)
    s3.ds[i] = s1.ds[i];
  for (int i = s1.n; i < s3.n; i++)
    s3.ds[i] = s2.ds[i - s1.n];
  cout << "\nDanh sach ket qua sau khi ghep 2 danh sach lai voi nhau la: ";
  for (int i = 0; i < s3.n; i++)
    cout << s3.ds[i] << " ";
}

void tachHaiDanhSachChanLe(DaySo s1, DaySo &dsChan, DaySo &dsLe) {
  int ndsChan = 0, ndsLe = 0;
  for (int i = 0; i < s1.n; i++) {
    if (s1.ds[i] % 2 == 0) {
      dsChan.ds[ndsChan] = s1.ds[i];
      ndsChan++;
    }
    else {
      dsLe.ds[ndsLe] = s1.ds[i];
      ndsLe++;
    }
  }
  cout << "\nDanh sach chan: ";
  for (int i = 0; i < ndsChan; i++)
    cout << dsChan.ds[i] << " ";
  cout << "\nDanh sach le: ";
  for (int i = 0; i < ndsLe; i++)
    cout << dsLe.ds[i] << " ";
}