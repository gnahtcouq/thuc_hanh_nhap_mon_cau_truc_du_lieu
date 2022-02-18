#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
typedef struct Node* Nodeptr;
struct SinhVien {
  char masv[10];
  char tensv[30];
  float diem, toan, ly, hoa, dtb;
};
struct Node {
  SinhVien data;
  Nodeptr link;
};
void khoiTao(Nodeptr& list);
int isEmpty(Nodeptr list);
void giaiPhong(Nodeptr& list);
Nodeptr tao_Node_SinhVien(SinhVien x);
Nodeptr themDau(Nodeptr& list, SinhVien x);
bool kiemTra_TrungMa(Nodeptr& list, char* ma);
void nhapDSSV(Nodeptr& list);
void xuatDSSV(Nodeptr list);
Nodeptr themCuoi(Nodeptr& list, SinhVien x);
Nodeptr tim_Sv_Masv(Nodeptr list, SinhVien x);
void xoaDau(Nodeptr& list);
void xoaCuoi(Nodeptr& list);
void xoa_Sv_Masv(Nodeptr& list, SinhVien sv);
void xoa_Sv_DiemDuoi5(Nodeptr& list);
void reverseList_SV(Nodeptr& list);
void splitList_SinhVien(Nodeptr list, Nodeptr& list1, Nodeptr& list2);
void nhapThemDiem(Nodeptr& list);
void sapXepDanhSach(Nodeptr& list);
void xuat_DSSVNew(Nodeptr list);

int main() {
  Nodeptr dssv, dssv1, dssv2;
  SinhVien sv;
  nhapDSSV(dssv);
  xuatDSSV(dssv);

  // Cau 3
  cout << "\nCau3. Nhap Ma SV can tim: ";
  cin.getline(sv.masv, 10);
  Nodeptr p = tim_Sv_Masv(dssv, sv);
  if (p == NULL)
    cout << "\nCau3. Khong tim thay";
  else {
    cout << "\nCau3. Co sinh vien: ";
    cout << setw(0) << p->data.masv << setw(15) << p->data.tensv << setw(20) << p->data.diem;
  }

  // Cau 4
  cout << "\nCau4. Danh sach sinh vien con lai sau khi xoa dau: " << endl;
  xoaDau(dssv);
  xuatDSSV(dssv);

  cout << "\nCau4. Danh sach sinh vien con lai sau khi xoa cuoi: " << endl;
  xoaCuoi(dssv);
  xuatDSSV(dssv);

  // Cau 5
  cout << "\nCau5. Nhap ma sinh vien can xoa: ";
  cin.getline(sv.masv, 10);
  xoa_Sv_Masv(dssv, sv);
  cout << "\nCau5. Danh sach sinh vien sau khi xoa: " << endl;
  xuatDSSV(dssv);

  cout << "\nCau5. Danh sach sinh vien sau khi xoa cac sinh vien co diem < 5 la: " << endl;
  xoa_Sv_DiemDuoi5(dssv);
  xuatDSSV(dssv);

  // BTVN Cau 1
  cout << "\nBTVN Cau1. Danh sach sinh vien sau khi dao nguoc la: " << endl;
  reverseList_SV(dssv);
  xuatDSSV(dssv);

  // BTVN Cau 2
  cout << "\nBTVN Cau2. Tach danh sach sinh vien";
  splitList_SinhVien(dssv, dssv1, dssv2);
  cout << "\nDanh sach sinh vien co diem < 5 la: " << endl;
  xuatDSSV(dssv1);
  cout << "\nDanh sach sinh vien co diem > 5 la: " << endl;
  xuatDSSV(dssv2);

  // BTVN Cau 3
  nhapThemDiem(dssv);
  sapXepDanhSach(dssv);
  cout << "Danh sach sinh vien sau khi sap xep lai la: " << endl;
  xuat_DSSVNew(dssv);

  cout << endl;
  giaiPhong(dssv);
  giaiPhong(dssv1);
  giaiPhong(dssv2);
  system("pause");
  return 0;
}

void khoiTao(Nodeptr& list) {
  list = NULL;
}
int isEmpty(Nodeptr list) {
  return list == NULL ? 1 : 0;
}
void giaiPhong(Nodeptr& list) {
  Nodeptr p = list;
  while (p != NULL) {
    list = list->link;
    delete p;
    p = list;
  }
}
Nodeptr tao_Node_Sv(SinhVien x) {
  Nodeptr p;
  p = new Node;
  p->data = x;
  p->link = NULL;
  return p;
}
//Ham Them 1 sinh vien
Nodeptr themDau(Nodeptr& list, SinhVien x) {
  Nodeptr p = tao_Node_Sv(x);
  p->link = list;
  list = p;
  return p;
}
bool kiemTra_TrungMa(Nodeptr& list, char* ma) {
  Nodeptr p = list;
  while (p != NULL) {
    if (strcmp(p->data.masv, ma) == 0)
      return true;
    p = p->link;
  }
  return false;
}
//Nhap DSSV
void nhapDSSV(Nodeptr& list) {
  //khoiTao(list);
  ////char x[10];
  SinhVien sv;
  khoiTao(list);
  do {
    cout << "\nNhap Ma SV (NHAP 0 DE THOAT): ";
    cin.getline(sv.masv, 10);
    while (kiemTra_TrungMa(list, sv.masv)) {
      cout << "Ma so sv bi trung";
      cout << "Nhap lai ma so sv: ";
      cin.getline(sv.masv, 10);
    }
    if (strcmp(sv.masv, "0") == 0) //NHAP MA SO = 0 DE THOAT
      break;
    cout << "Nhap Ten SV: ";
    cin.getline(sv.tensv, 30);
    do {
      cout << "Nhap Diem SV: ";
      cin >> sv.diem;
      if (sv.diem < 0 || sv.diem > 10)
        cout << "\nNhap sai. Hay nhap lai diem trong khoang tu (1->10)" << endl;
    } while (sv.diem < 0 || sv.diem > 10);
    cin.ignore();
    // themDau(list, sv);
    themCuoi(list, sv);
  } while (1);
}
void xuatDSSV(Nodeptr list) {
  cout << setw(0) << "MASV" << setw(15) << "TEN SV" << setw(20) << "Diem" << endl;
  while (list != NULL) {
    cout << setw(0) << list->data.masv << setw(15)
      << list->data.tensv << setw(20) << list->data.diem << endl;
    list = list->link;
  }
}

// Cau 2
Nodeptr themCuoi(Nodeptr& list, SinhVien x) {
  Nodeptr p = tao_Node_Sv(x);
  if (list == NULL) {
    list = p;
  }
  else {
    Nodeptr q = list;
    while (q->link != NULL) {
      q = q->link;
    }
    q->link = p;
  }
  return p;
}

// Cau 3
Nodeptr tim_Sv_Masv(Nodeptr list, SinhVien x) {
  Nodeptr p = list;
  while (p != NULL) {
    if (strcmp(p->data.masv, x.masv) == 0)
      return p;
    p = p->link;
  }
  return p;
}

// Cau 4
void xoaDau(Nodeptr& list) {
  Nodeptr p;
  if (list != NULL) {
    p = list;
    list = p->link;
    delete p;
  }
}
void xoaCuoi(Nodeptr& list) {
  Nodeptr p, before;
  p = list;
  before = list;
  if (p->link == NULL) {
    delete p;
    list = NULL;
  }
  else {
    while (p->link != NULL) {
      before = p;
      p = p->link;
    }
    if (p->link == NULL) {
      delete p;
      before->link = NULL;
    }
  }
}

// Cau 5
void xoa_Sv_Masv(Nodeptr& list, SinhVien sv) {
  if (strcmp(list->data.masv, sv.masv) == 0) {
    Nodeptr p = list;
    list = list->link;
    delete p;
  }
  else {
    Nodeptr p, before;
    p = list;
    before = list;
    while (p != NULL && strcmp(p->data.masv, sv.masv) != 0) {
      before = p;
      p = p->link;
    }
    if (p != NULL) {
      before->link = p->link;
      delete p;
    }
  }
}

void xoa_Sv_DiemDuoi5(Nodeptr& list) {
  if (list != NULL) {
    Nodeptr p = list, q;
    while (p != NULL) {
      if (p->data.diem < 5) {
        q = p->link;
        xoa_Sv_Masv(list, p->data);
        p = q;
      }
      else
        p = p->link;
    }
  }
}

// BTVN Cau 1
void reverseList_SV(Nodeptr& list) {
  if (list == NULL)
    return;
  Nodeptr curr = list;
  while (curr != NULL && curr->link != NULL) {
    Nodeptr next = curr->link;
    curr->link = next->link;
    next->link = list;
    list = next;
  }
}

// BTVN Cau 2
void splitList_SinhVien(Nodeptr list, Nodeptr& list1, Nodeptr& list2) {
  khoiTao(list1);
  khoiTao(list2);
  Nodeptr p = list;
  SinhVien dssv1, dssv2;
  while (p != NULL) {
    if (p->data.diem < 5) {
      dssv1 = p->data;
      themCuoi(list1, dssv1);
    }
    else {
      dssv2 = p->data;
      themCuoi(list2, dssv2);
    }
    p = p->link;
  }
}

// BTVN Cau 3
void nhapThemDiem(Nodeptr& list) {
  Nodeptr p = list;
  while (p != NULL) {
    cout << "Nhap them diem cho MSSV " << p->data.masv << endl;
    cout << "Nhap diem Toan: ";
    cin >> p->data.toan;
    cout << "Nhap diem Ly: ";
    cin >> p->data.ly;
    cout << "Nhap diem Hoa: ";
    cin >> p->data.hoa;
    p->data.dtb = (p->data.toan + p->data.ly + p->data.hoa) / 3;
    cout << "Diem trung binh cua sinh vien " << p->data.tensv << " la: " << p->data.dtb << endl;
    cout << endl;
    p = p->link;
  }
}
void sapXepDanhSach(Nodeptr& list) {
  for (Nodeptr pTmp = list; pTmp != NULL; pTmp = pTmp->link) {
    for (Nodeptr pTmp2 = pTmp->link; pTmp2 != NULL; pTmp2 = pTmp2->link) {
      if (pTmp->data.dtb > pTmp2->data.dtb) {
        SinhVien tmp = pTmp->data;
        pTmp->data = pTmp2->data;
        pTmp2->data = tmp;
      }
    }
  }
}
void xuat_DSSVNew(Nodeptr list) {
  cout << setw(0) << "MASV" << setw(15) << "TEN SV" << setw(20) << "Diem" << setw(25) << "DIEM TB" << endl;
  while (list != NULL) {
    cout << setw(0) << list->data.masv << setw(15) << list->data.tensv << setw(20) << list->data.diem << setw(25) << list->data.dtb << endl;
    list = list->link;
  }
}