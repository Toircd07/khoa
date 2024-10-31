#include "nhanvien.h"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
vector<QLNV> QLNV::listQLNV; // Khởi tạo biến tĩnh

QLNV::QLNV() {} // hàm khởi tạo mặc định

QLNV::QLNV(string _MNV, string _Ten, string _DT, string _CCCD, string _ViTri, string _Luong, string _Bank)
    : MNV(_MNV), Ten(_Ten), DT(_DT), CCCD(_CCCD), ViTri(_ViTri), Luong(_Luong), Bank(_Bank) {}

// Getter và Setter cho các thuộc tính
string QLNV::getMNV() const { return MNV; }
void QLNV::setMNV(const string& _MNV) { MNV = _MNV; }
string QLNV::getTen() const { return Ten; }
void QLNV::setTen(const string& _Ten) { Ten = _Ten; } //
string QLNV::getDT() const { return DT; }
void QLNV::setDT(const string& _DT) { DT = _DT; }
string QLNV::getCCCD() const { return CCCD; }
void QLNV::setCCCD(const string& _CCCD) { CCCD = _CCCD; }
string QLNV::getViTri() const { return ViTri; }
void QLNV::setViTri(const string& _ViTri) { ViTri = _ViTri; }
string QLNV::getLuong() const { return Luong; }
void QLNV::setLuong(const string& _Luong) { Luong = _Luong; }
string QLNV::getBank() const { return Bank; }
void QLNV::setBank(const string& _Bank) { Bank = _Bank; }

void QLNV::Them() {
    string _MNV, _Ten, _DT, _CCCD, _ViTri, _Luong, _Bank;
    cin.ignore(32767, '\n');
    cout << "Nhap ma nhan vien: "; getline(cin, _MNV);
    for (int i = 0; i < listQLNV.size(); i++) {
        if (listQLNV[i].MNV == _MNV) {
            cout << "Ma nhan vien da ton tai!" << endl;
            cout << "Nhap ma moi: ";
            getline(cin, _MNV);
            i = 0; // Đặt lại i để kiểm tra lại từ đầu
        }
    }
    cout << "Nhap ten nhan vien: "; getline(cin, _Ten);
    cout << "Nhap so dien thoai nhan vien: "; getline(cin, _DT);
    while (_DT.length() != 10) {
        cout << "So dien thoai khong hop le, nhap lai so dien thoai: ";
        getline(cin, _DT);
    }
    cout << "Nhap so can cuoc cong dan: "; getline(cin, _CCCD);
    while (_CCCD.length() != 12) {
        cout << "So CCCD khong hop le, nhap lai so CCCD: ";
        getline(cin, _CCCD);
    }
    cout << "Nhap vi tri nhan vien: "; getline(cin, _ViTri);
    cout << "Nhap luong nhan vien: "; getline(cin, _Luong);
    cout << "Nhap so tai khoan ngan hang cua nhan vien: "; getline(cin, _Bank);
    listQLNV.push_back(QLNV(_MNV, _Ten, _DT, _CCCD, _ViTri, _Luong, _Bank));
}

void QLNV::XuatDanhSach() {
    printf("+-----------------+------------------------------------------------------------+----------------+-------------------+--------------------+-------------------+--------------------------+\n");
    printf("| %-15s | %-58s | %-14s | %-17s | %-18s | %-17s | %-24s |\n", "Ma so nhan vien", "Ten nhan vien", "So dien thoai", "Can cuoc cong dan", "Vi tri nhan vien", "Luong nhan vien", "So tai khoan ngan hang");
    printf("+-----------------+------------------------------------------------------------+----------------+-------------------+--------------------+-------------------+--------------------------+\n");
    for (int i = 0; i < listQLNV.size(); i++) {
        printf("| %-15s | %-58s | %-14s | %-17s | %-18s | %-17s | %-24s |\n", listQLNV[i].MNV.c_str(), listQLNV[i].Ten.c_str(), listQLNV[i].DT.c_str(), listQLNV[i].CCCD.c_str(), listQLNV[i].ViTri.c_str(), listQLNV[i].Luong.c_str(), listQLNV[i].Bank.c_str());
    }
    printf("+-----------------+------------------------------------------------------------+----------------+-------------------+--------------------+-------------------+--------------------------+\n");
}

void QLNV::Xoa(const string& _MNV) {
    for (int i = 0; i < listQLNV.size(); i++) {
        if (listQLNV[i].MNV == _MNV) {
            listQLNV.erase(listQLNV.begin() + i);
            cout << "Xoa nhan vien thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
}

void QLNV::TimKiem(const string& _MNV) {
    printf("+-----------------+------------------------------------------------------------+----------------+-------------------+--------------------+-------------------+--------------------------+\n");
    printf("| %-15s | %-58s | %-14s | %-17s | %-18s | %-17s | %-24s |\n", "Ma so nhan vien", "Ten nhan vien", "So dien thoai", "Can cuoc cong dan", "Vi tri nhan vien", "Luong nhan vien", "So tai khoan ngan hang");
    printf("+-----------------+------------------------------------------------------------+----------------+-------------------+--------------------+-------------------+--------------------------+\n");
    for (int i = 0; i < listQLNV.size(); i++) {
        if (listQLNV[i].MNV == _MNV) {
            printf("| %-15s | %-58s | %-14s | %-17s | %-18s | %-17s | %-24s |\n", listQLNV[i].MNV.c_str(), listQLNV[i].Ten.c_str(), listQLNV[i].DT.c_str(), listQLNV[i].CCCD.c_str(), listQLNV[i].ViTri.c_str(), listQLNV[i].Luong.c_str(), listQLNV[i].Bank.c_str());
            printf("+-----------------+------------------------------------------------------------+----------------+-------------------+--------------------+-------------------+--------------------------+\n");
            return;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
}

void QLNV::Sua(const string& _MNV) {
    for (int i = 0; i < listQLNV.size(); i++) {
        if (listQLNV[i].MNV == _MNV) {
            string _Ten, _DT, _CCCD, _ViTri, _Luong, _Bank;
            cout << "Nhap ten nhan vien moi: "; getline(cin, _Ten);
            cout << "Nhap so dien thoai nhan vien moi: "; getline(cin, _DT);
            cout << "Nhap so can cuoc cong dan moi: "; getline(cin, _CCCD);
            cout << "Nhap vi tri nhan vien moi: "; getline(cin, _ViTri);
            cout << "Nhap luong nhan vien moi: "; getline(cin, _Luong);
            cout << "Nhap so tai khoan ngan hang cua nhan vien moi: "; getline(cin, _Bank);
            listQLNV[i].setTen(_Ten);
            listQLNV[i].setDT(_DT);
            listQLNV[i].setCCCD(_CCCD);
            listQLNV[i].setViTri(_ViTri);
            listQLNV[i].setLuong(_Luong);
            listQLNV[i].setBank(_Bank);
            cout << "Sua thong tin nhan vien thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
}

void QLNV::Readfile(){
    ifstream qlfile("data/Qlnv_list.csv");
    string header, line;
    string _MNV, _Ten, _DT, _CCCD, _ViTri, _Luong, _Bank;
    getline(qlfile, header);
    while(getline(qlfile, line)){
        stringstream str(line);
        if( getline(str,_MNV,',') && getline(str,_Ten,',') && getline(str,_DT,',') && getline(str,_CCCD,',') && getline(str,_ViTri,',') && getline(str,_Luong,',') && getline(str,_Bank)){
            listQLNV.push_back(QLNV(_MNV, _Ten, _DT, _CCCD, _ViTri, _Luong, _Bank));
        }
    }    
}

void QLNV::writefile(){
    ofstream outqlfile("data/Qlnv_list.csv");
    outqlfile << "Ma so nhan vien,Ten nhan vien,So dien thoai,Can cuoc cong dan,Vi tri nhan vien,Luong nhan vien,So tai khoan ngan hang" << endl;
    for( int i = 0; i < listQLNV.size(); i++){
        outqlfile << listQLNV[i].MNV << ","<< listQLNV[i].Ten << ","<< listQLNV[i].DT << ","<< listQLNV[i].CCCD << ","<< listQLNV[i].ViTri << ","<< listQLNV[i].Luong << ","<< listQLNV[i].Bank <<endl;
    }
}

bool cmp(QLNV a, QLNV b){
    return a.getMNV() < b.getMNV();
}

void QLNV::SortMNV(){
    sort(listQLNV.begin(), listQLNV.end(), cmp);
}
