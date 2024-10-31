#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class QLNV {
    private:
        string MNV;
        string Ten;
        string DT;
        string CCCD;
        string ViTri;
        string Luong;
        string Bank;
        static vector<QLNV> listQLNV;

    public:
        QLNV();
        QLNV(string _MNV, string _Ten, string _DT, string _CCCD, string _ViTri, string _Luong, string _Bank);

        // Getter và Setter cho các thuộc tính
        string getMNV() const;
        void setMNV(const string& _MNV);
        string getTen() const;
        void setTen(const string& _Ten);
        string getDT() const;
        void setDT(const string& _DT);
        string getCCCD() const;
        void setCCCD(const string& _CCCD);
        string getViTri() const;
        void setViTri(const string& _ViTri);
        string getLuong() const;
        void setLuong(const string& _Luong);
        string getBank() const;
        void setBank(const string& _Bank);

        void Them();
        void XuatDanhSach();
        void Xoa(const string& _MNV);
        void TimKiem(const string& _MNV);
        void Sua(const string& _MNV);
        void Readfile();
        void writefile();
        void SortMNV();
};

#endif // NHANVIEN_H