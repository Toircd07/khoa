


#include"nhanvien.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>


using namespace std;

int main(){
    int choice;
    string _MNV;
    QLNV x;
    x.Readfile();
    while(true){
        cout<<" Chuong trinh quan ly nhan vien" << endl;
        cout << " 1. Them nhan vien vao danh sach" << endl;
        cout << " 2. Sua thong tin nhan vien trong danh sach" << endl;
        cout << " 3. Xoa nhan vien khoi danh sach" << endl;
        cout << " 4. Hien danh sach nhan vien" << endl;
        cout << " 5. Tim kiem nhan vien trong danh sach" << endl;
        cout << " 6. Sap xep ma nhan vien theo thu tu tang dan" << endl; 
        cout << " 7. Luu lai danh sach" << endl;
        cout << " 0. Thoat khoi chuong trinh" << endl;
        cout << " Vui long bam so de chon chuc nang mong muon: ";
        cin >> choice;
        

        switch(choice){
            case 1:
                cout << "Nhap thong tin can them vao danh sach:" << endl;
                x.Them();
                break;
            case 2:
                cin.ignore();
                cout <<" Nhap ma nhan vien ban muon thay doi thong tin ban muon thay doi:" << endl;
                getline( cin, _MNV);
                x.Sua(_MNV);
                break;
            case 3:
            	cin.ignore();
                cout << " Nhap ma so nhan vien ban muon xoa:"<< endl;
                getline(cin, _MNV);
                x.Xoa(_MNV);
                break;
            case 4:
                cout << "Thong tin danh sach nhan vien la:" << endl;
                x.XuatDanhSach();
                break;
            case 5:
                cin.ignore();
                cout <<" Nhap ma so nhan vien ma ban muon tim kiem:" << endl;
                getline(cin, _MNV);
                x.TimKiem(_MNV);
                break;
            case 6:
                cout <<" Danh sach ma so nhan vien duoc sap xep tang dan la:" << endl;
                x.SortMNV();
                break;
            case 7:
                x.writefile();
                cout << " Thong tin da duoc luu:" << endl;
                break;
            case 0:
                return 0;

        }
    }
    return 0; 
}