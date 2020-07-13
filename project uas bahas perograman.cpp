#include<iostream>
#include<conio.h>
#include<iomanip>
#include <fstream>
#include <ctime>
using namespace std;
int pil,n,uang;
string jenis; 
string nama_pemesan,matauang;
int konversi;
struct makan{

	string nama_pemesan;
	string nama;
	int hrg;
	int jml;
	int total;
	int pesanan;
}pesanan[100];

struct pesan{
	string nama_pemesan;
	int th;
	int tunai;
	int kembali;
}p;


header(){
	cout<<"------------------------------------------------------------------"<<endl;
	cout<<"|"<<setw(40)<<"APLIKASI JUNK FOOD PAK KODAY"<<setw(25)<<"|"<<endl;
	cout<<"|"<<setw(65)<<"|"<<endl;
	cout<<"------------------------------------------------------------------"<<endl;
	
}

void menu_makan();
void laporan_pemesanan();


void bon(){
		time_t now=time(0);
    	char*time=ctime(&now);
    	
	system("bon.txt");
		ofstream cout;
		cout.open ("bon.txt");
			
		
        cout<<"\n \tJunkFOOD PAK AMIR";
        cout<<"\n     Jl.Raya PANJANG NO.3";
        cout<<"\n       Tlp.081297243952";
        cout<<"\n============================================================\n";
        
		for(int i=0;i<n;i++){
		
        cout<<p.nama_pemesan<<"\t\t "<<pesanan[i].nama<<"\t"<<pesanan[i].jml;
		cout<<"\tRp. "<<pesanan[i].total<<endl;
		}
 		cout<<"------------------------------------------------------------\n";
		cout<<"\t\tTotal   : "<<n<<"\t\tRp."<<p.th<<endl;
		cout<<"\t\tTunai   : "<<"\t\tRp."<<konversi<<endl;
		cout<<"\t\tkembali : "<<"\t\tRp."<<p.kembali<<endl;
        cout<<"\n============================================================\n";
 		cout<<"\t\t"<<time;
 		cout<<"------------------------------------------------------------\n";
	cout<<endl;
}
 
main(){

do{

	system("cls");
	header();
	
	cout<<"\n1.Pemesanan Menu Makanan\n2.Laporan Penjualan Harian\n"<<endl;
	cout<<"\nMasukan Pilihan (1-3) : ";cin>>pil;
	switch(pil){
		case 1:{
			menu_makan();
			break;
		}
		case 2:{
			laporan_pemesanan();	
			break;
		}
		
	}
}while(pil!=2);
	getch();
	
	return 0;
}


void menu_makan(){

	
	system("cls");
	
	
	header();
	
	
	cout<<"\t\t\tPEMESANAN MENU"<<endl<<endl;
	cout<<" --------------------------------------------------------"<<endl;
	cout<<" |\tMAKANAN"<<setw(16)<<"|"<<"\t\tMINUMAN\t\t|"<<endl;
	cout<<" |------------------------------------------------------|"<<endl;
	cout<<" | 1.  paket hemat"<<setw(13)<<"|"<<" 25.000\t\t\t|"<<endl;
	cout<<" | 2.  paket combo"<<setw(13)<<"|"<<" 32.000\t\t\t|"<<endl;
	cout<<" | 3.  paket super combo"<<setw(7)<<"|"<<" 37.000\t\t\t|"<<endl;
	cout<<" | 4.  paket kids"<<setw(14)<<"|"<<" 26.000\t\t\t|"<<endl;
	cout<<" | 5.  paket besar"<<setw(13)<<"|"<<" 42.000\t\t\t|"<<endl;
	cout<<" | 6.  paket super besar"<<setw(7)<<"|"<<" 50.000\t\t\t|"<<endl;
	cout<<" | 7.  ice coffee"<<setw(14)<<"|"<<" 10.000\t\t\t|"<<endl;
	cout<<" | 8.  Coca-Cola"<<setw(15)<<"|"<<" 5.000\t\t\t|"<<endl;
	cout<<" | 9.  Pepsi"<<setw(19)<<"|"<<" 5.000\t\t\t|"<<endl;
	cout<<" | 10. Fanta"<<setw(19)<<"|"<<" 6.000\t\t\t|"<<endl;
	cout<<" | 11. Lemon tea"<<setw(15)<<"|"<<" 8.000\t\t\t|"<<endl;
	cout<<" | 12. R&B"<<setw(21)<<"|"<<" 12.000\t\t\t|"<<endl;
	cout<<" --------------------------------------------------------"<<endl;
	
	
	
	cout<<"masukan banyaknya pesanan : ";cin>>n;
	for(int i=0;i<n;i++){
		
		cout<<"pesanan ke "<<i+1;
		cout<<"\nMasukan pesanan  : ";cin>>pesanan[i].pesanan;
		if(pesanan[i].pesanan==1){
			pesanan[i].nama="paket hemat";
			pesanan[i].hrg=25000;
		}else if(pesanan[i].pesanan==2){
			pesanan[i].nama="paket combo";
			pesanan[i].hrg=32000;
		}else if(pesanan[i].pesanan==3){
			pesanan[i].nama="paket super combo";
			pesanan[i].hrg=37000;
		}else if(pesanan[i].pesanan==4){
			pesanan[i].nama="paket kids";
			pesanan[i].hrg=26000;
		}else if(pesanan[i].pesanan==5){
			pesanan[i].nama="paket besar";
			pesanan[i].hrg=42000;
		}else if(pesanan[i].pesanan==6){
			pesanan[i].nama="paket super besar";
			pesanan[i].hrg=50000;
		}
		else if(pesanan[i].pesanan==7){
			pesanan[i].nama="ice coffe";
			pesanan[i].hrg=10000;
		}else if(pesanan[i].pesanan==8){
			pesanan[i].nama="coca cola";
			pesanan[i].hrg=5000;
		}
		else if(pesanan[i].pesanan==9){
			pesanan[i].nama="pepsi";
			pesanan[i].hrg=5000;
		}
		else if(pesanan[i].pesanan==10){
			pesanan[i].nama="fanta";
			pesanan[i].hrg=6000;
		}
		else if(pesanan[i].pesanan==11){
			pesanan[i].nama="coca cola";
			pesanan[i].hrg=8000;
		}
		else if(pesanan[i].pesanan==12){
			pesanan[i].nama="R&B";
			pesanan[i].hrg=12000;
		}
			
		cout<<"\nmasukan jumlah : ";cin>>pesanan[i].jml;
			
		pesanan[i].total = pesanan[i].hrg * pesanan[i].jml;
		p.th =p.th+pesanan[i].total;
		
	cout<<endl<<endl;	
	}
		cin.ignore();
	cout<<"nama pemesan : ";getline(cin,p.nama_pemesan);

		cout<<"total : "<<p.th<<endl<<endl<<endl;
		cout<<"masukan pembayaran dengan format NOMINALMATAUANG[YEN/WON/IDR/USD]";
		cout<<"\ntunai : ";cin>>p.tunai;cin>>jenis;
			
				 if(jenis =="yen"||jenis=="YEN"){
					konversi=  p.tunai * 128.8;
					matauang="YEN";
				}
				else if(jenis =="won"||jenis=="WON"){
					konversi= p.tunai * 11.833;
					matauang="WON";
				}
				else if(jenis =="usd"||jenis=="USD"){
					konversi= p.tunai * 14000;
					matauang="USD";
				}
				else if (jenis== "idr"|| jenis=="IDR"){
					konversi=p.tunai*1;
				}
				 p.kembali=konversi-p.th; 
			
			cout<<"Kembalian : " <<p.kembali; 
		cout<<endl;	
			
 		
	system("pause");
	bon();
system("pause");
	
}


void laporan_pemesanan(){
	system("cls");
	cout<<"\t\t\tLAPORAN PEMESANAN "<<endl<<endl;
	    cout<<" --------------------------------------------------------------------------------------------------------\n";
		cout<< setiosflags(ios::left) << setw(2) << "|";
	    cout<< setiosflags(ios::left) << setw(3) << "NO" ;
		cout<< setiosflags(ios::left) << setw(5)<<" | ";
	    cout<< setiosflags(ios::left) << setw(20) << "NAMA PEMESAN";
	    cout<< setiosflags(ios::left) << setw(5) << "|";
	    cout<< setiosflags(ios::left) << setw(23) << "PESANAN";
	    cout<< setiosflags(ios::left) << setw(2) << "|";
	    cout<< setiosflags(ios::left) << setw(15) << "JUMLAH PESANAN";
	    cout<< setiosflags(ios::left) << setw(3) << "|";
	    cout<< setiosflags(ios::left) << setw(12) << "PEMBAYARAN";
	    cout<< setiosflags(ios::left) << setw(3) << "|";
	    cout<< setiosflags(ios::left) << setw(12) << "KEMBELIAN";
	    cout<< setiosflags(ios::left) << setw(2) << "|"<<endl;
	    cout<<" --------------------------------------------------------------------------------------------------------\n";
	for(int i=0;i<n;i++){
	
		cout<< setiosflags(ios::left) << setw(2) << "|";
	    cout<< setiosflags(ios::left) << setw(3) <<i+1;
		cout<< setiosflags(ios::left) << setw(5)<<" | ";
	    cout<< setiosflags(ios::left) << setw(20) <<p.nama_pemesan;
	    cout<< setiosflags(ios::left) << setw(2) << "|";
	    cout<< setiosflags(ios::left) << setw(26) <<pesanan[i].nama;
	    cout<< setiosflags(ios::left) << setw(8) << "|";
	    cout<< setiosflags(ios::left) << setw(9) <<pesanan[i].jml;
	    cout<< setiosflags(ios::left) << setw(4) << "|";
	    cout<< setiosflags(ios::left) << setw(11) <<konversi;
	    cout<< setiosflags(ios::left) << setw(4) << "|";
	    cout<< setiosflags(ios::left) << setw(11) <<p.kembali;
	    cout<< setiosflags(ios::left) << setw(4) << "|"<<endl;
	cout<<" --------------------------------------------------------------------------------------------------------\n";
	
	
	
		
	}	
	cout<<endl;   
	
	system("pause");

	
}

