#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <ctime>
using namespace std;

struct SanPham {
    int maSP;
    string tenSP;
    double gia;
    int soLuong;
};

// Ham so sanh de sap xep tang dan (theo gia sp)
	bool soSanhTangDan(const SanPham& a, const SanPham& b) {
    return a.gia < b.gia;
	}

// Ham so sanh de sap xep giam dan (theo gia sp)
	bool soSanhGiamDan(const SanPham& a, const SanPham& b) {
    return a.gia > b.gia;
	}
	
// Ham so sanh de sap xep tang dan (theo ma sp
	bool soSanhMaTangDan(const SanPham& a, const SanPham& b) {
    return a.maSP < b.maSP;
	}

// Ham so sanh de sap xep giam dan (theo ma sp)
	bool soSanhMaGiamDan(const SanPham& a, const SanPham& b) {
    return a.maSP > b.maSP;
	}

class CuaHangVanPhongPham {
private:
    vector<SanPham> danhSachSP;
    double doanhThuHomNay = 0; // Doanh thu trong ngay hien tai
    vector<double> danhSachDoanhThu; // Luu doanh thu tu nhung ngay truoc
    time_t thoiGianBatDauNgay = time(0); // Thoi gian bat dau tinh doanh thu trong ngay
    vector<SanPham> danhSachSanPhamDaBan;
    string tenKhachHang;
    string diaChi;
    string soDienThoai;
    int soLuongSPDaBan;

public:
    CuaHangVanPhongPham() {
        soLuongSPDaBan = 0;
    }
    
    // Ham them san pham vao dau danh sach
    void themDau(int maSP, string tenSP, double gia, int soLuong) {
        SanPham sp = {maSP, tenSP, gia, soLuong};
        danhSachSP.insert(danhSachSP.begin(), sp);
        cout << "Da them san pham vao dau danh sach: " << tenSP << endl;
    }
    
    // Ham them san pham vao cuoi danh sach
    void themCuoi(int maSP, string tenSP, double gia, int soLuong) {
        SanPham sp = {maSP, tenSP, gia, soLuong};
        danhSachSP.push_back(sp);
        cout << "Dam them san pham vao cuoi danh sach: " << tenSP << endl;
    }

    // Ham them san pham
    void themSanPham(int maSP, string tenSP, double gia, int soLuong) {
        SanPham sp = {maSP, tenSP, gia, soLuong};
        danhSachSP.push_back(sp);
        cout << "Da them san pham: " << tenSP << endl;
    }
    
    // Ham xoa san pham khoi danh sach theo ma san pham
    void xoaSanPham(int maSP) {
        bool timThay = false;
        for (int i = 0; i < danhSachSP.size(); ++i) {
            if (danhSachSP[i].maSP == maSP) {
                danhSachSP.erase(danhSachSP.begin() + i);
                cout << "Da xoa san pham co ma: " << maSP << endl;
                timThay = true;
                break;
            }
        }
        if (!timThay) {
            cout << "Khong tim thay san pham co ma: " << maSP << endl;
        }
	} 
	
    // Ham hien thi danh sach san pham
    void hienThiSanPham() {
        cout << "\nDanh sach san pham trong cua hang:\n";
        cout << setw(10) << "Ma SP" << setw(20) << "Ten SP" << setw(10) << "Gia" << setw(15) << "So luong\n";
        
        for (int i = 0; i < danhSachSP.size(); i++) {
            cout << setw(10) << danhSachSP[i].maSP 
                 << setw(20) << danhSachSP[i].tenSP 
                 << setw(10) << danhSachSP[i].gia 
                 << setw(15) << danhSachSP[i].soLuong << endl;
        }
    }

    // Ham tim kiem theo ma san pham
    void timKiemSanPham(int maSP) {
        bool found = false;
        for (int i = 0; i < danhSachSP.size(); i++) {
            if (danhSachSP[i].maSP == maSP) {
                cout << "San pham tim thay:\n";
                cout << "Ma SP: " << danhSachSP[i].maSP 
                     << ", Ten SP: " << danhSachSP[i].tenSP 
                     << ", Gia: " << danhSachSP[i].gia 
                     << ", So luong: " << danhSachSP[i].soLuong << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Khong tim thay san pham voi ma SP: " << maSP << endl;
        }
    }

    // Ham ban san pham
    
    void banSanPham(int maSP, int soLuong) {
        for (int i = 0; i < danhSachSP.size(); i++) {
            if (danhSachSP[i].maSP == maSP) {
                if (danhSachSP[i].soLuong >= soLuong) {
                    danhSachSP[i].soLuong -= soLuong;
                    double tongTien = soLuong * danhSachSP[i].gia;
                    
                    doanhThuHomNay += tongTien; // Cap nhat doanh thu trong ngay
                    
                    soLuongSPDaBan += soLuong;
                    
                    // Them vao danh sach san pham da ban
                    danhSachSanPhamDaBan.push_back({maSP, danhSachSP[i].tenSP, danhSachSP[i].gia, soLuong});
                    
                    cout << "Da ban " << soLuong << " san pham " << danhSachSP[i].tenSP 
                         << " voi tong gia: " << tongTien << " VND\n";
                    return;
                } else {
                    cout << "So luong san pham trong kho khong du de ban.\n";
                    return;
                }
            }
        }
        cout << "Khong tim thay san pham da ban.\n";
    }
    
    // Ham nhap thong tin khach hang
    void nhapThongTinKhachHang() {
        cout << "Nhap ten khach hang: ";
        getline(cin >> ws, tenKhachHang);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap so dien thoai: ";
        getline(cin, soDienThoai);
    }

    // Ham in hoa don
    void inHoaDon() {	
    	cout << "\n--- HOA DON ---\n";
        cout << "Ten khach hang: " << tenKhachHang << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "So dien thoai: " << soDienThoai << endl;
        cout << "\nSan pham da ban:\n";
    	
    	cout << setw(20) << "San pham" << setw(15) << "So luong" << setw(15) << "Gia tien\n";
        double tongTien = 0;
        
        // Dung vong lap voi chi so de duyet danh sach san pham de ban
    	for (int i = 0; i < danhSachSanPhamDaBan.size(); ++i) {
        	cout << setw(20) << danhSachSanPhamDaBan[i].tenSP
             	<< setw(15) << danhSachSanPhamDaBan[i].soLuong 
             	<< setw(15) << danhSachSanPhamDaBan[i].gia * danhSachSanPhamDaBan[i].soLuong << " VND\n";
        	tongTien += danhSachSanPhamDaBan[i].gia * danhSachSanPhamDaBan[i].soLuong;
    	}
    
    	cout << "Tong tien: " << tongTien << " VND\n";
    
    	// Xoa danh sach san pham da ban sau khi in hoa don
    	danhSachSanPhamDaBan.clear();
    }
    
    // Ham sap xep san pham theo gio 	
	void sapXepTheoGia(bool tangDan) {
    	if (tangDan) {
        	// Sap xep theo thu tu tang dan
        	sort(danhSachSP.begin(), danhSachSP.end(), soSanhTangDan);
        	cout << "Danh sach san pham da duoc sap xep theo gia (tang dan).\n";
    	} else {
        	// Sap xep theo thu tu giam dan
        	sort(danhSachSP.begin(), danhSachSP.end(), soSanhGiamDan);
        	cout << "Danh sach san pham da duoc sap xep theo gia (giam dan).\n";
    	}
	}
	
	// Ham sap xep san pham theo ma
	void sapXepTheoMaSP(bool tangDan) {
    	if (tangDan) {
        	sort(danhSachSP.begin(), danhSachSP.end(), soSanhMaTangDan);
        	cout << "Danh sach san pham da duoc sap xep theo ma san pham (tang dan).\n";
    	} else {
        	sort(danhSachSP.begin(), danhSachSP.end(), soSanhMaGiamDan);
        	cout << "Danh sach san pham da duoc sap xep theo ma san pham (giam dan).\n";
    	}
	}
	
	// Ham tinh doanh thu trong ngay
	void tinhDoanhThuTrongNgay() {
    	time_t thoiGianHienTai = time(0);
    	double thoiGianTrenNgay = 24 * 60 * 60; // 24 gi? tính theo giây

    	if (difftime(thoiGianHienTai, thoiGianBatDauNgay) >= thoiGianTrenNgay) {
        	// Dua doanh thu hien tai vao danh sach doanh thu ngay truoc
        	danhSachDoanhThu.push_back(doanhThuHomNay);
        
        	// Reset doanh thu và cap nhat thoi gian bat dau ngay moi
        	doanhThuHomNay = 0;
        	thoiGianBatDauNgay = thoiGianHienTai;
    	}
	}
	
	// Ham in doanh thu
	void inDoanhThu(bool inHomNay) {
    	tinhDoanhThuTrongNgay(); // Kiem tra va reset doanh thu neu qua 24 gio

    	if (inHomNay) {
        	cout << "Doanh thu trong ngay hien tai: " << doanhThuHomNay << "\n";
    	} else {
    		if (danhSachDoanhThu.empty()) {
				cout << "Chua co doanh thu tu nhung ngay truoc.\n";
			} else {
        		cout << "Doanh thu tu nhung ngay truoc:\n";
        		for (int i = 0; i < danhSachDoanhThu.size(); i++) {
            		cout << "Ngay " << (i + 1) << ": " << danhSachDoanhThu[i] << "\n";
        		}	
    		}
		}	
	}
    
    // Ham check ma bi trung
    bool kiemTraMaSPTrung(int maSP) {
    	for (int i = 0; i < danhSachSP.size(); ++i) {
        	if (danhSachSP[i].maSP == maSP) {
            	return true;
        	}
    	}
    return false;
	}
	
	// Ham nhap mot so nguyen va kiem tra dieu kien
	int nhapSoNguyen(string thongBao, int min = INT_MIN, int max = INT_MAX) {
    	int giaTri;
    	while (true) {
        	cout << thongBao;
        	cin >> giaTri;
        	if (cin.fail() || giaTri < min || giaTri > max) {
            	cout << "Nhap khong hop le. Vui long nhap lai.\n";
            	cin.clear();            // Xoa trang thai loi cua cin
            	cin.ignore(INT_MAX, '\n'); // Bo qua ky tu con lai trong dong
        	} else {
            	return giaTri;
        	}
    	}
	}

    // Ham nhap mot so thuc va kiem tra dieu kien
    double nhapSoThuc(string thongBao, double min = 0.0) {
    	double giaTri;
    	while (true) {
        	cout << thongBao;
        	cin >> giaTri;
        	if (cin.fail() || giaTri < min) {
            	cout << "Nhap khong hop le. Vui long nhap lai.\n";
           		cin.clear();
            	cin.ignore(INT_MAX, '\n');
        	} else {
            	return giaTri;
        	}
    	}
	}

    // Ham nhap chuoi (ten san pham)
	string nhapChuoi(string thongBao) {
    	string chuoi;
    	cout << thongBao;
    	cin.ignore();
    	getline(cin, chuoi);
    	return chuoi;
	}
	
	// Ham kiem tra du lieu dau vao cho switch
	int nhapLuaChon() {
    	int luaChon;
    	while (true) {
        	cin >> luaChon;
        	if (cin.fail() || luaChon < 1 || luaChon > 12) { // Kiem tra neu gia tri ngoai pham vi 1-10
            	cout << "Lua chon khong hop le! Vui long nhap lai (1-12): ";
            	cin.clear(); // Xoa trang thai loi cua cin
            	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bo qua cac ki tu thua trong dong
        	} else {
            	return luaChon;
        	}
    	}
	}
		
};

int main() {
    CuaHangVanPhongPham cuaHang;
    cuaHang.themSanPham(100, "Thuoc", 2000, 50);
    cuaHang.themSanPham(101, "But bi", 3000, 200);
    cuaHang.themSanPham(102, "Giay A4", 1000, 50);
    cuaHang.themSanPham(103, "So tay", 8000, 30);
	cuaHang.themSanPham(104, "Tap", 5000, 100);
	
    int luaChon;
    while (true) {
        cout << "\nQUAN LY CUA HANG VAN PHONG PHAM\n";
        cout << "1. Them san pham\n";
        cout << "2. Them san pham vao dau danh sach\n";
        cout << "3. Them san pham vao cuoi danh sach\n";
        cout << "4. Xoa san pham khoi danh sach\n";
        cout << "5. Hien thi danh sach san pham\n";
        cout << "6. Tim kiem san pham\n";
        cout << "7. Ban san pham\n";
        cout << "8. In hoa don\n";
        cout << "9. Sap xep san pham theo gia\n";
        cout << "10. Sap xep san pham theo ma\n";
        cout << "11. In doanh thu\n";
        cout << "12. Thoat\n";
        cout << "Nhap lua chon: ";
        luaChon = cuaHang.nhapLuaChon();

switch (luaChon) {
            case 1: {
                int maSP = cuaHang.nhapSoNguyen("Nhap ma san pham: ", 1);
                if (cuaHang.kiemTraMaSPTrung(maSP)) {
                    cout << "Ma san pham da ton tai. Vui long nhap lai.\n";
                    break;
                }
                string tenSP = cuaHang.nhapChuoi("Nhap ten san pham: ");
                double gia = cuaHang.nhapSoThuc("Nhap gia san pham: ");
                int soLuong = cuaHang.nhapSoNguyen("Nhap so luong san pham: ", 1);
                cuaHang.themSanPham(maSP, tenSP, gia, soLuong);
                break;
            }
            case 2: {
                int maSP = cuaHang.nhapSoNguyen("Nhap ma san pham: ", 1);
                if (cuaHang.kiemTraMaSPTrung(maSP)) {
                    cout << "Ma san pham da ton tai. Vui long nhap lai.\n";
                    break;
                }
                string tenSP = cuaHang.nhapChuoi("Nhap ten san pham: ");
                double gia = cuaHang.nhapSoThuc("Nhap gia san pham: ");
                int soLuong = cuaHang.nhapSoNguyen("Nhap so luong san pham: ", 1);
                cuaHang.themDau(maSP, tenSP, gia, soLuong);
                break;
            }
            case 3: {
                int maSP = cuaHang.nhapSoNguyen("Nhap ma san pham: ", 1);
                if (cuaHang.kiemTraMaSPTrung(maSP)) {
                    cout << "Ma san pham da ton tai. Vui long nhap lai.\n";
                    break;
                }
                string tenSP = cuaHang.nhapChuoi("Nhap ten san pham: ");
                double gia = cuaHang.nhapSoThuc("Nhap gia san pham: ");
                int soLuong = cuaHang.nhapSoNguyen("Nhap so luong san pham: ", 1);
                cuaHang.themCuoi(maSP, tenSP, gia, soLuong);
                break;
            }
            case 4: {
                int maSP = cuaHang.nhapSoNguyen("Nhap ma san pham can xoa: ", 1);
                cuaHang.xoaSanPham(maSP);
                break;
            }
            case 5:
                cuaHang.hienThiSanPham();
                break;
            case 6: {
                int maSP = cuaHang.nhapSoNguyen("Nhap ma san pham can tim: ", 1);
                cuaHang.timKiemSanPham(maSP);
                break;
            }
            case 7: {
                int maSP = cuaHang.nhapSoNguyen("Nhap ma san pham can ban: ", 1);
                int soLuong = cuaHang.nhapSoNguyen("Nhap so luong san pham can ban: ", 1);
                cuaHang.banSanPham(maSP, soLuong);
                break;
            }
            case 8:
            	cuaHang.nhapThongTinKhachHang();
                cuaHang.inHoaDon();
                break;
            case 9: { 
    			int luaChonSapXep = cuaHang.nhapSoNguyen("Nhap 1 de sap xep gia san pham tang dan, 0 de sap xep giam dan: ", 0, 1);
    			cuaHang.sapXepTheoGia(luaChonSapXep == 1); // Neu nhap 1 thi sap xep giam dan
    			break; 
			}
			case 10: { 
            	int luaChonSapXepMa = cuaHang.nhapSoNguyen("Nhap 1 de sap xep ma san pham tang dan, 0 de sap xep giam dan: ", 0, 1);
            	cuaHang.sapXepTheoMaSP(luaChonSapXepMa == 1);
            	break;
        	}
        	case 11: { 
            	int luaChonInDoanhThu = cuaHang.nhapSoNguyen("Nhap 1 de in doanh thu trong ngay, 0 de in doanh thu tu nhung ngay truoc: ", 0, 1);
            	cuaHang.inDoanhThu(luaChonInDoanhThu == 1);
            	break;
        	}
			case 12: 	
                cout << "Chuong trinh ket thuc.\n";
                return 0;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }
}
