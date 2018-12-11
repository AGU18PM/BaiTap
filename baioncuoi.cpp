#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<string.h>

using namespace std;

class Day{
private:
	int Ngay;
	int Thang;
	int Nam;
public:
	void Nhap();
	void Xuat();
	void setDay(int d,int m,int y);
};

class Sach{
protected:
	string MaSach;
//	string NgayNhap;
	Day NgayNhap;
	string NXB;
	float DonGia;
	int SoLuong;
	float ThanhTien;
	string LoaiSach;
public:
	Sach();
	virtual void Nhap();
	virtual void Xuat();
	virtual void TinhTien() = 0;
	string GetLoaiSach();
	float GetThanhTien();
};

class SGK:public Sach{
private:
	string TinhTrang;
public:
	SGK();
	void Nhap();
	void Xuat();
	void TinhTien();
};

class STK:public Sach{

private:
	float Thue;
public:
	STK();
	void Nhap();
	void Xuat();
	void TinhTien();
};

class DS_Sach{
private:
	Sach *ds[1000];
	int SoLuong;
public:
	void Nhap();
	void Xuat();
	void TinhTongThanhTien_MoiLoai();
	void TB_Gia_STK();
	void Print_SGK();
};

int main(){
	DS_Sach a;
	a.Nhap();
	a.Xuat();
	a.TinhTongThanhTien_MoiLoai();
	a.TB_Gia_STK();
	cout<<"Thong tin sgk: "<<endl;
	a.Print_SGK();
//	Sach a;
//	a.Nhap();	
	return 1;
}

void Day::Nhap(){
	cout<<"Nhap ngay: "<<endl;
	cin>>Ngay;
	cout<<"Nhap thang: "<<endl;
	cin>>Thang;
	cout<<"Nhap nam: "<<endl;
	cin>>Nam;
}

void Day::setDay(int d, int m, int y){
	Ngay = d;
	Thang = m;
	Nam = y;
}

void Day::Xuat(){
	cout<<Ngay<<"/"<<Thang<<"/"<<Nam<<endl;
}

Sach::Sach(){
	MaSach = "";
	NgayNhap.setDay(00,00,00); // pt khoi tao co tham so
	NXB = "";
	DonGia = ThanhTien = 0;
	SoLuong = 0;
}

string Sach::GetLoaiSach(){
	return LoaiSach;
}

float Sach::GetThanhTien(){
	return ThanhTien;
}

void Sach::Nhap(){
	
	cout<<"Nhap ma sach: "<<endl;
	getline(cin,MaSach);
	cout<<"Nhap ngay nhap: "<<endl;
	NgayNhap.Nhap();
	cin.ignore();
	cout<<"Nhap ten NXB: "<<endl;
	getline(cin,NXB);
	cout<<"Nhap don gia: "<<endl;
	cin>>DonGia;
	cout<<"Nhap so luong: "<<endl;
	cin>>SoLuong;
}

void Sach::Xuat(){
	cout<<"Ma sach: "<<MaSach<<endl;
	cout<<"Ngay Nhap: ";
	NgayNhap.Xuat();
	cout<<"NXB: "<<NXB<<endl;
	cout<<"Don gia: "<<DonGia<<endl;
	cout<<"So luong: "<<SoLuong<<endl;
	cout<<"Thanh tien: "<<ThanhTien<<endl;
}

SGK::SGK():Sach(){
	LoaiSach = "SGK";
	TinhTrang = "";
}

void SGK::Nhap(){
	Sach::Nhap();
	int tmp = 0;
	do{
		cout<<"Nhap tinh trang: "<<endl;
		cout<<"1.Moi"<<endl<<"2.Cu"<<endl;
		cin >>tmp;
		if(tmp != 1 && tmp != 2)
			cout<<"Nhap sai!"<<endl;
	}while(tmp != 1 && tmp != 2);
	if(tmp == 1)
		TinhTrang = "moi";
	else 
		TinhTrang = "cu";
	TinhTien();
}

void SGK::Xuat(){
	Sach::Xuat();
	cout<<"Tinh trang: "<<TinhTrang<<endl;
}

void SGK::TinhTien(){
	if(TinhTrang == "moi")
		ThanhTien = DonGia * SoLuong;
	else
		ThanhTien = DonGia * SoLuong / 2;
}

STK::STK():Sach(){
	LoaiSach = "STK";
	Thue = 0;
}

void STK::Nhap(){
	Sach::Nhap();
	do{
		cout<<"Nhap thue(5 - 20): "<<endl;
		cin>>Thue;
		if(Thue<5||Thue>20)
			cout<<"Nhap sai!"<<endl;
	}while(Thue<5||Thue>20);
	Thue /= 100;
	TinhTien();
}

void STK::Xuat(){
	Sach::Xuat();
	cout<<"Thue: "<<Thue*100<<"%"<<endl;
}

void STK::TinhTien(){
	
	ThanhTien = SoLuong * DonGia + (DonGia * Thue);
}

void DS_Sach::Nhap(){
	cout<<"Nhap so luong sach: "<<endl;
	cin>>SoLuong;
	int ChonLoai = 0;
	for(int i  = 0; i < SoLuong; i++){
		do{
			cout<<"Chon loai Sach: "<<endl;
			cout<<"1.SGK"<<endl<<"2.STK"<<endl;
			cin>>ChonLoai;
			if(ChonLoai != 1 && ChonLoai != 2)
			cout<<"Nhap sai"<<endl;
		}while(ChonLoai != 1 && ChonLoai != 2);
		if(ChonLoai == 1)
			ds[i] = new SGK;
		else
			ds[i] = new STK;
		cin.ignore();
		ds[i]->Nhap();
	}
}

void DS_Sach::Xuat(){
	for(int i = 0; i < SoLuong; i++){
		cout<<"Thong tin sach thu: "<<i<<endl;
		ds[i]->Xuat();
	}
}

void DS_Sach::TinhTongThanhTien_MoiLoai(){
	float sumsgk = 0;
	float sumstk = 0;
	for(int i = 0; i < SoLuong; i++){
		if(ds[i]->GetLoaiSach() == "SGK")
			sumsgk+=ds[i]->GetThanhTien();
		else
			sumstk+=ds[i]->GetThanhTien();
	}
	cout<<"Tong tien cua sach giao khoa la: "<<sumsgk<<endl;
	cout<<"Tong tien cua sach tham khao la: "<<sumstk<<endl;
}

void DS_Sach::TB_Gia_STK(){

	float avg = 0;
	for(int i = 0; i < SoLuong; i++){
		if(ds[i]->GetLoaiSach()=="STK")
			avg+=ds[i]->GetThanhTien();
	}
	cout<<"Trung binh cong thanh tien cua STK la: ";
	printf("%.2f\n",avg/SoLuong);
}

void DS_Sach::Print_SGK(){
	for(int i = 0; i < SoLuong; i++){
		if(ds[i]->GetLoaiSach()=="SGK")
			ds[i]->Xuat();
	}
}




