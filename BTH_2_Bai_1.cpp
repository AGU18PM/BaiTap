#include<iostream>
#include<stdio.h>


using namespace std;

class PhanSo {
	private:
		int TuSo,MauSo;
	//	float GiaTri;
		float UocChung_LN;
	public:
		PhanSo();
		PhanSo(int tu, int mau);
	//	~PhanSo();
		void Nhap();
		void Xuat();
//		void TinhGiaTri();
		void RutGon();
		bool operator == (PhanSo a); // true false
		int operator != (PhanSo a);
		bool operator > (PhanSo a);
		bool operator >=(PhanSo a);
		bool operator < (PhanSo a);
		void UCLN();
		void QuyDong(PhanSo &a);

};

int main(){
	PhanSo a,b;
	a.Nhap();
	b.Nhap();
	a.Xuat();
	b.Xuat();
	//if(a==b)
//		cout<<"dung"<<endl;
//	else
//		cout<<"Sai"<<endl;
//	if(a!=b)
//		cout<<"Dung"<<endl;
//	else 
//		cout<<"Sai"<<endl;
//	if(a>b)
//		cout<<"Dung"<<endl;
//	else
//		cout<<"sai"<<endl;
//	if(a<b)
//		cout<<"cc ne"<<endl;
//	else
//		cout<<"cl ne"<<endl;
//	
	if (a >=b)
	cout<<"dung"<<endl;
	else
	cout<<"sai"<<endl;
	a.Xuat();
	b.Xuat();
	
	return 1;
}

PhanSo::PhanSo(){
	TuSo=0;
	MauSo = 0;
//	GiaTri = 0;
	UocChung_LN = 0;
}

PhanSo::PhanSo(int tu, int mau){
	TuSo = tu;
	MauSo = mau;
}

//PhanSo::~PhanSo(){
//	cout<<"Huy";
//}

void PhanSo::Nhap(){
	cout<<"Nhap tu so: "<<endl;
	cin>>TuSo;
	cout<<"Nhap mau so: "<<endl;
	cin>>MauSo;
	
	RutGon();
}

void PhanSo::Xuat()
{
	cout<<"Tu: "<<TuSo<<endl<<"Mau: "<<MauSo<<endl;
	cout<<"UCLN"<<UocChung_LN<<endl;
}

void PhanSo::QuyDong(PhanSo &a){
	//int Tutg = TuSo;
	int Mautg = MauSo;

	if(MauSo != a.MauSo)
	{
		TuSo*=a.MauSo;
		MauSo*=a.MauSo;
		a.TuSo *= Mautg;
		a.MauSo *= Mautg;
	}
}


void PhanSo::UCLN(){
	int a,b;
	a = TuSo;
	b = MauSo;
	if(a == 0)
		UocChung_LN = b;
	while(a!=b){
		if(a>b)
			a-=b;
		else
			b-=a;
	}
	UocChung_LN = a;
}

void PhanSo::RutGon(){
	UCLN();
	TuSo /= UocChung_LN;
	MauSo /= UocChung_LN;
}

bool PhanSo::operator ==(PhanSo a){
	if(a.TuSo == TuSo && a.MauSo == MauSo)
		return 1;
	return 0;
	
}

int PhanSo::operator !=(PhanSo a){
	if(a.TuSo != TuSo || a.MauSo != MauSo)
		return 1;
	return 0;
}



bool PhanSo::operator >(PhanSo a){
	PhanSo b(TuSo,MauSo);
	b.QuyDong(a);
	if(b.TuSo > a.TuSo)
		return 1;
	return 0;
}

bool PhanSo::operator <(PhanSo a){
	PhanSo b(TuSo,MauSo);
	b.QuyDong(a);
	if(b.TuSo <a.TuSo)
	return 1;
	return 0;
}
bool PhanSo::operator >=(PhanSo a){
	PhanSo b(TuSo,MauSo);
	b.QuyDong(a);	
	if(b.TuSo>=a.TuSo)
	return 1;
	return 0;
}












asdsadsada[ldkpksajdklpasjdlksmdkpaldnlasdmsadnasidhsbnd]
