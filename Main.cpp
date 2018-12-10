#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class NhanVien {
protected:
	char MaSo[50];
	char Name[50];
	float Luong;
public:
	NhanVien();
	char *GetMaSo();
	float GetLuong();
	virtual void Nhap();
	virtual void Xuat();
	virtual void TinhTien() = 0;

};

class HopDong : public NhanVien {
private:
	float TienCong;
	float SoNgayLam;
public:
	HopDong();
	void Nhap();
	void Xuat();
	void TinhTien();
};

class BienChe : public NhanVien {
private:
	float HeSoLuong;
	float PhuCapCV;
public:
	BienChe();
	void Nhap();
	void Xuat();
	void TinhTien();
};

class DS_NhanVien {
private:
	NhanVien *ds[1000];
	int SoLuong;
public:
	void Nhap();
	void Xuat();
	float TinhTongLuong();
	float TB_Luong();
	void Search();
	void Search_Luong_Tren_5_trieu();
	void Search_Luong();
};

int main() {
	DS_NhanVien ds;
	ds.Nhap();
	ds.Xuat();
	//ds.Search();
	//cout << "Nhan vien co luong tren 5 trieu: " << endl;
	ds.Search_Luong();
	//ds.Search_Luong_Tren_5_trieu();
	system("pause");
	return 1;
}

#pragma region Methods of NhanVien
NhanVien::NhanVien() {
	strcpy(MaSo, "");
	strcpy(Name, "");
	Luong = 0;
}

float NhanVien::GetLuong() {
	return Luong;
}

char *NhanVien::GetMaSo() {
	return MaSo;
}

void NhanVien::Nhap() {
	cout << "Nhap ma so nhan vien: " << endl;
	cin >> MaSo;
	cin.ignore();
	cout << "Nhap ten nhan vien: " << endl;
	cin.getline(Name, 50);
}

void NhanVien::Xuat() {
	cout << "Ma so nhan vien: " << MaSo << endl;
	cout << "Ten nhan vien: " << Name << endl;
}


#pragma endregion

#pragma region Methods of HopDong
HopDong::HopDong() :NhanVien(){
	TienCong = 0;
	SoNgayLam = 0;
}

void HopDong::Nhap() {
	NhanVien::Nhap();
	do {
		cout << "Nhap tien cong 1 ngay(80.000 - 100.000): " << endl;
		cin >> TienCong;
		if (TienCong < 80000 || TienCong>150000)
			cout << "Ban da nhap sai, moi nhap lai!" << endl;
	} while (TienCong < 80000 || TienCong>150000);
	
	cout << "Nhap so ngay lam: " << endl;
	cin >> SoNgayLam;
	TinhTien();
}

void HopDong::TinhTien() {
	if (SoNgayLam > 24)
		Luong = SoNgayLam * TienCong*(float)1.2;
	else
		Luong = SoNgayLam * TienCong;
}

void HopDong::Xuat() {
	NhanVien::Xuat();
	cout << "So ngay lam: " << SoNgayLam << endl;
	cout << "Tien cong 1 ngay: " << TienCong << endl;
	printf("Luong: %.2f\n", Luong);
}

#pragma endregion

#pragma region Methods of BienChe
BienChe::BienChe() {
	HeSoLuong = 0;
	PhuCapCV = 0;
}

void BienChe::Nhap() {
	NhanVien::Nhap();
	do {
		cout << "Nhap he so luong: " << endl;
		cin >> HeSoLuong;
		if (HeSoLuong<1.0 || HeSoLuong>13.0)
			cout << "Nhap sai!" << endl;
	} while (HeSoLuong<1.0 || HeSoLuong>13.0);

	do {
		cout << "Nhap so phu cap: " << endl;
		cin >> PhuCapCV;
		if (PhuCapCV<0.0 || PhuCapCV>2.0)
			cout << "Nhap sai!" << endl;
	} while (PhuCapCV<0.0 || PhuCapCV>2.0);
	TinhTien();
}

void BienChe::TinhTien() {
	Luong = 1150000 * (HeSoLuong + PhuCapCV);
}

void BienChe::Xuat() {
	NhanVien::Xuat();
	cout << "He so luong: " << HeSoLuong << endl;
	cout << "Phu cap chuc vu: " << PhuCapCV << endl;
	printf("Luong: %.2f\n", Luong);
}
#pragma endregion

#pragma region Methods of DS_NhanVien
void DS_NhanVien::Nhap() {
	int loainv;
	cout << "Nhap so luong nhan vien: " << endl;
	cin >> SoLuong;
	for (int i = 0; i < SoLuong; i++) {
		loainv = 0;
		do {
			cout << "Chon loai nhan vien: " << endl;
			cout << "1. Bien che" << endl;
			cout << "2. Hop dong" << endl;
			cin >> loainv;
			if (loainv != 1 && loainv != 2)
				cout << "Ban nhap sai!" << endl;
		} while (loainv != 1 && loainv != 2);

		if (loainv == 1)
			ds[i] = new BienChe;
		else
			ds[i] = new HopDong;
		ds[i]->Nhap();
	}
}

void DS_NhanVien::Xuat() {
	for (int i = 0; i < SoLuong; i++)
		ds[i]->Xuat();
}

float DS_NhanVien::TinhTongLuong() {
	float sum = 0;
	for (int i = 0; i < SoLuong; i++) {
		sum += ds[i]->GetLuong();
	}
	return sum;
}

float DS_NhanVien::TB_Luong() {
	float sum = TinhTongLuong();
	float arg = sum / SoLuong;
	return arg;
}

void DS_NhanVien::Search() {
	char Key[30];
	cout << "Nhap ma so can tim: " << endl;
	cin >> Key;
	for (int i = 0; i < SoLuong; i++) {
		if (strcmp(ds[i]->GetMaSo(), Key) == 0) {
			ds[i]->Xuat();
			return;
		}
	}
	cout << "Khong co ma so can tim! " << endl;
}

void DS_NhanVien::Search_Luong_Tren_5_trieu(){
	int dem = 0;
	for (int i = 0; i < SoLuong; i++) {
		if (ds[i]->GetLuong() > 5000000) {
			ds[i]->Xuat();
			dem++;
		}

	}
	if (dem == 0)
		cout << "Khong co ai co luong tren 5 trieu ok!" << endl;
}

void DS_NhanVien::Search_Luong() {
	//nhap so luong can tim
	float LuongCT;
	int dem=0;
	cout << "Nhap luong can tim: " << endl;
	cin >> LuongCT;
	for (int i = 0; i < SoLuong; i++) {
		//neu luong can tim = luong 
		if (ds[i]->GetLuong() == LuongCT) {
			//thi xuat ra
			ds[i]->Xuat();
			dem++;
		}
			//k co thi xuat ra cau thong bao k co
	}
	if(dem==0)
	cout << "Khong co luong can tim" << endl;

}

#pragma endregion








