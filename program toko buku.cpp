#include<iostream>
#include<conio.h>

using namespace std;


string nama,buku_nama,kode_buku;
char pilih;
int n,pil,total,th,kembali,tunai;


struct buku{
	string nama_buku;
	char kode[5];
	int jumlah;
	int harga;
}input_buku['n'];

struct beli_buku{
	int banyak;
	int total;
}beli_buku['n'];



void header(){
	for(int i=0;i<90;i++){
		cout<<"=";
	}	
	cout<<"\n\t\t\t   SELAMAT DATANG DI ";
	cout<<"\n\t\t\tTOKO BUKU KARYA MAKMUR \n";
	for(int i=0;i<90;i++){
		cout<<"=";
	}
	cout<<endl;
}


void input(){
	system("cls");
	header();
	
	cout<<"Masukan Jumlah Buku yang ingin dimasukan : ";cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Data Buku Ke "<<i+1<<endl;
		cout<<"Masukan Kode buku \t: ";cin>>input_buku[i].kode;
		cout<<"Masukan Judul Buku \t: ";cin>>input_buku[i].nama_buku;
		cout<<"Masukan Jumlah Buku \t: ";cin>>input_buku[i].jumlah;
		cout<<"harga buku \t\t: Rp.";cin>>input_buku[i].harga;
		cout<<endl;		
	}
	
}


void tampil(){
	
	header();
	
	cout<<endl;
	cout<<"|Kode Buku\t|\tJudul Buku\t| Jumlah Buku\t|\tHarga\t\t|";
	cout<<"\n=================================================================================\n";
	for(int i=0;i<n;i++){
		cout<<"|"<<input_buku[i].kode<<"\t\t| "<<input_buku[i].nama_buku<<"\t\t|\t"<<input_buku[i].jumlah<<"\t|\t"<<input_buku[i].harga<<"\t\t|"<<endl;
			}
			cout<<endl;
	
}
 

void beli(){
	system("cls");
		
	tampil();
	cout<<endl;
	
	lagi:
		cout<<" Kode buku : "; cin>>buku_nama;
		for(int i=0; i<n; i++) 
		{
		
	
	 if(input_buku[i].kode == buku_nama) {
					
			cout<<" Judul buku  : "<<input_buku[i].nama_buku<<endl; //Output judul buku
            cout<<" harga buku  : "<<input_buku[i].harga<<endl;
            cout<<" Jumlah beli : ";cin>>beli_buku[i].banyak;
    			beli_buku[i].total=input_buku[i].harga*beli_buku[i].banyak;
	        	th=th+beli_buku[i].total;
	        	input_buku[i].jumlah-=beli_buku[i].banyak;
			
		cout<<endl;
	
		cout<<"Lakukan lagi y/t :";cin>>pilih;
	if(pilih=='y'){
		goto lagi;
	}
	else{
		cout<<" Total : "<<beli_buku[i].total<<endl;
		cout<<" Tunai : ";cin>>tunai;
		kembali=tunai-th;
		
		system("cls");
//        myfile<<"\n   TOKO BUKU KARYA MAKMUR";
//        myfile<<"\n     Jl.Raya PANJANG NO.3";
//        myfile<<"\n       Tlp.081297243952";
//        myfile<<"\n------------------------------------------------\n";
//        for(int j=i;j<i-n;j++){
//		
//        myfile<<input_buku[j].nama_buku<<"\t\t"<<beli_buku[j].banyak;
//		myfile<<"\tRp. "<<beli_buku[j].total<<endl;
//		}
//		myfile<<"\t\t--------------------------------------\n";
//		myfile<<"\t\tTotal : Rp."<<th<<endl;
//		myfile<<"\t\tTunai : Rp."<<tunai<<endl;
//		myfile<<"\t\tkembal :Rp."<<kembali<<endl;
//    	
	
           	
			   
	 		}
		}
	}
	
	}
	
	    
void rekap(){
	cout<<"\tHasil Rekap "<<endl<<endl;
	cout<<"|Judul Buku\t| Jumlah Buku terjual\t|\tHarga\t|";
	cout<<"\n=================================================================================\n";
	for(int i=0;i<n;i++){
	
	cout<<"|"<<input_buku[i].nama_buku<<"\t|\t"<<beli_buku[i].banyak<<"\t\t|\t"<<beli_buku[i].total<<"\t|"<<endl;
	
	
		
	}	
	cout<<endl;
}

int main(){
	

do{
	
	menu:
		system("cls");
			header();
				cout<<endl;
	
	cout<<" 1. Input Data Buku\n";
   	cout<<" 2. Daftar Buku \n";
    cout<<" 3. Pembelian Buku\n";
    cout<<" 4. Rekap Buku\n";
    cout<<" 5. penambahan stok buku\n";
    cout<<" 6. Keluar\n";
    cout<<" Masukan Pilihan Anda : "; cin>>pil; 
		
	switch(pil){
		case 1:{
			satu:
			input();
			cout<<"kembali ke menu [y/t] : ";cin>>pilih;
			if(pilih=='y'){
				goto menu;
			}
			else{
				goto satu;
			}
			break;
		}
		case 2:{
			system("cls");
			dua:
			tampil();
			cout<<"kembali ke menu [y/t] : ";cin>>pilih;
			if(pilih=='y'){
				goto menu;
			}
			else{
				goto dua;
			}
			
			break;
		}
		case 3:{
			tiga:
			tampil();
			beli();
			cout<<endl;
			cout<<"kembali ke menu [y/t] : ";cin>>pilih;
			if(pilih=='y'){
				goto menu;
			}
			else{
				goto tiga;
			}				
			break;
		}
		case 4:{
			empat:
			rekap();
			cout<<"kembali ke menu [y/t] : ";cin>>pilih;
			if(pilih=='y'){
				goto menu;
			}
			else{
				goto empat;
			}				
			
			break;
		}
		case 5:{
			lima :
			cout<<" masukan kode buku\t: "; cin>>kode_buku;
			for(int i=0; i<n; i++) 
			{
		
			if(input_buku[i].kode == kode_buku) {
					
			cout<<" Judul buku\t\t: "<<input_buku[i].nama_buku<<endl; //Output judul buku
            cout<<" masukan jumlah buku\t: ";cin>>n;
            input_buku[i].jumlah+=n;
        		}
    		}
        	cout<<"ingin coba lagi y/t : ";cin>>pilih;
			if(pilih=='y'){
				goto menu;
			}
			else{
				goto lima;
			}				
			
			break;
			}
		case 6:{
			cout<<"=========GOOD BYE=========";
			return 0;
			break;
		}
	}
	
	
	}while(pil!=6);
	
	getch();
}
