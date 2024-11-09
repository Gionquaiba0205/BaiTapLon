#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct SanPham {
    int maSP;
    string tenSP;
    double gia;
    int soLuong;
};

class CuaHangVanPhongPham {
private:
    vector<SanPham> danhSachSP;
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
                    soLuongSPDaBan += soLuong;
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

    // Ham in hoa don
    void inHoaDon() {
        cout << "\n--- HOA DON ---\n";
        cout << "So luong san pham da ban: " << soLuongSPDaBan << endl;
        double tongDoanhThu = 0;
        
        for (int i = 0; i < danhSachSP.size(); i++) {
            int soLuongBan = danhSachSP[i].soLuong;
            double doanhThu = soLuongBan * danhSachSP[i].gia;
            tongDoanhThu += doanhThu;
        }
        
        cout << "Tong doanh thu: " << tongDoanhThu << " VND\n";
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
        cout << "9. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                int maSP, soLuong;
                string tenSP;
                double gia;
                
                while (true) {
        			cout << "Nhap ma san pham: ";
        			cin >> maSP;
        			if (cuaHang.kiemTraMaSPTrung(maSP)) {
            			cout << "Ma san pham da ton tai. Vui long nhap lai.\n";
        			} else {
            			break;
        			}
    			}
    
                cout << "Nhap ma san pham: ";
                cin >> maSP;
                cout << "Nhap ten san pham: ";
                cin.ignore();
                getline(cin, tenSP);
                cout << "Nhap gia san pham: ";
                cin >> gia;
                cout << "Nhap so luong san pham: ";
                cin >> soLuong;
                cuaHang.themSanPham(maSP, tenSP, gia, soLuong);
                break;
            } 
			case 2: {
				int maSP, soLuong;
                double gia;
                string tenSP;
                
                while (true) {
        			cout << "Nhap ma san pham: ";
        			cin >> maSP;
        			if (cuaHang.kiemTraMaSPTrung(maSP)) {
            			cout << "Ma san pham da ton tai. Vui long nhap lai.\n";
        			} else {
            			break;
        			}
    			}
    			
                cout << "Nhap ma san pham: ";
                cin >> maSP;
                cout << "Nhap ten san pham: ";
                cin.ignore();
                getline(cin, tenSP);
                cout << "Nhap gia san pham: ";
                cin >> gia;
                cout << "Nhap so luong san pham: ";
                cin >> soLuong;

                cuaHang.themDau(maSP, tenSP, gia, soLuong);
                break;	
			}
			case 3: {
				int maSP, soLuong;
                double gia;
                string tenSP;
                
                while (true) {
        			cout << "Nhap ma san pham: ";
        			cin >> maSP;
        			if (cuaHang.kiemTraMaSPTrung(maSP)) {
            			cout << "Ma san pham da ton tai. Vui long nhap lai.\n";
        			} else {
            			break;
        			}
    			}
                
                cout << "Nhap ma san pham: ";
                cin >> maSP;
                cout << "Nhap ma san pham: ";
                cin.ignore();
                getline(cin, tenSP);
                cout << "Nhap gia san pham: ";
                cin >> gia;
                cout << "Nhap so luong san pham: ";
                cin >> soLuong;

                cuaHang.themCuoi(maSP, tenSP, gia, soLuong);
				break;
			}
			case 4: {
				int maSP;
                cout << "Nhap ma san pham can xoa: ";
                cin >> maSP;
                cuaHang.xoaSanPham(maSP);
				break;
			}
            case 5:
                cuaHang.hienThiSanPham();
                break;
            case 6: {
                int maSP;
                cout << "Nhap ma san pham can tim: ";
                cin >> maSP;
                cuaHang.timKiemSanPham(maSP);
                break;
            }
            case 7: {
                int maSP, soLuong;
                cout << "Nhap ma san pham can ban: ";
                cin >> maSP;
                cout << "Nhap so luong san pham can ban: ";
                cin >> soLuong;
                cuaHang.banSanPham(maSP, soLuong);
                break;
            }
            case 8:
                cuaHang.inHoaDon();
                break;
            case 9:
                cout << "Chuong trinh ket thuc.\n";
                return 0;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    }
}

