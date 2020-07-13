#include <Windows.h>
#include<iostream>
#include<conio.h>
#include<iomanip>
#include <fstream>
using namespace std;

int pil;
int N=5;
struct login{
	
	string username;
	string pass;
	
}login1;

struct regis{
	string nama_depan;
	string nama_belakang;
	string username;
	string pass;
	regis *next;
}registrasi;
 
struct mahasiswa{
	string nama;
	string jurusan;
	string  nim;
	bool keluar;
	mahasiswa *next;
};   

mahasiswa *head=NULL;
mahasiswa *tail=NULL;


void login();
void registrasi1();
void menu();
void input(string,string, string);
void tampil();
void edit( string ,string,string,string);
void hapus( string);
void cetak();
void program();

header(){
	cout<<"=====================================================================================\n";
    cout<<" \t\tSISTEM MAHASISWA\n";
    cout<<"=====================================================================================\n";
}

int main(){
	
	menu();
	
		
	getch ();
}

void cetak(){
	system("DAFTAR.txt");
	ofstream myfile;
	myfile.open ("DAFTAR.txt");
	mahasiswa *temp=new mahasiswa;
	temp=head;
     	int i = 1;
 	
  		myfile<<"\t\t\t DAFTAR MAHASISWA  \n\n";
  		myfile<<"-------------------------------------------------------------------------------------\n";
  		myfile<< setiosflags(ios::left) << setw(3) << "|";
	    myfile<< setiosflags(ios::left) << setw(5) << "NO" ;
		myfile<< setiosflags(ios::left) << setw(10)<<" | ";
	    myfile<< setiosflags(ios::left) << setw(10) << "NIM";
	    myfile<< setiosflags(ios::left) << setw(8) << "|";
	    myfile<< setiosflags(ios::left) << setw(20) << "NAMA";
	    myfile<< setiosflags(ios::left) << setw(8) << "|";
	    myfile<< setiosflags(ios::left) << setw(20) << "JURUSAN";
	    myfile<< setiosflags(ios::left) << setw(20) << "|"<<endl;
	    myfile<<"-------------------------------------------------------------------------------------\n";
	  while(temp != NULL) {
    	if(temp->keluar) {
    	myfile<< setiosflags(ios::left) << setw(3) << "|";
	    myfile<< setiosflags(ios::left) << setw(5) << i;
		myfile<< setiosflags(ios::left) << setw(5)<<" | ";
	    myfile<< setiosflags(ios::left) << setw(15) <<temp->nim;
	    myfile<< setiosflags(ios::left) << setw(2) << "|";
	    myfile<< setiosflags(ios::left) << setw(26) <<temp->nama;
	    myfile<< setiosflags(ios::left) << setw(3) << "|";
	    myfile<< setiosflags(ios::left) << setw(25) << temp->jurusan;
	    myfile<< setiosflags(ios::left) << setw(20) << "|"<< endl;
      	i++;
    	
		}
    	temp = temp->next;
  	}
  	 myfile.close();
}

void program(){
	
    string nama_mahasiswa,Jurusan;
	string NIM,NIMbaru;
	int pil;
    char yn;    
    do{
	
        system("CLS");
        header();
        cout<<"1. Input Mahasiswa \n";
        cout<<"2. Daftar Mahasiswa\n";
        cout<<"3. Edit Mahasiswa\n";
        cout<<"4. Hapus Mahasiswa\n";
        cout<<"5. Logout\n";
        cout<<"=====================================================================================\n";
        cout<<"Pilih (1-5) : ";
        cin>>pil;
        switch(pil){
            case 1:{
			system("cls");
			header();
				cout<<"\nMasukan Data Mahasiswa \n"<<endl;
				cout<<"masukan nim \t\t : ";cin>>NIM;
				cin.ignore();
    			mahasiswa *temp = head;
			    int  berhasil = 0;
    			while(temp != NULL) {
    				if(temp->keluar){
      					if(temp->nim ==NIM ) {
       			 		berhasil = 1;
  						}
	  				}
	  				temp = temp->next;
  				}
  				if (berhasil==1){
                    cout<<"\t\tNIM SUDAH TERDAFTAR"<<endl<<" \tSilahkan Masukan Ulang\n\t\t\tTekan Enter"<<endl;
                    system("pause");
                    program();
            	}
				cout<<"masukan nama mahasiswa \t : ";getline(cin,nama_mahasiswa);
    			cout<<"masukan jurusan \t : ";getline(cin,Jurusan);
            	input(NIM,nama_mahasiswa,Jurusan);
				
				cout<<"\n\tData Tersimpan"<<endl;
				system("pause");
				break;
				}
			
			case 2:{
				system("cls");
				header();
				tampil();
				cout<<"Ingin Mencetak [y/n] : ";cin>>yn;
					if(yn=='y'||yn=='Y'){
						cetak();
					}
					else{
						system("pause");
					}
				break;
			}
			case 3:{
				system("cls");
				header();
				tampil();
				
				cout<<"masukan nim \t\t : ";cin>>NIM;
				cout<<endl;
				mahasiswa *temp = head;
			    int  berhasil = 1;
    			while(temp != NULL) {
    				if(temp->keluar){
      					if(temp->nim !=NIM ) {
       			 		berhasil = 0;
  						}
	  				}
	  				temp = temp->next;
  				}
  				if (berhasil==0){
                    cout<<"\t\tNIM TIDAK DITEMUKAN"<<endl<<" \t\tSilahkan Masukan Ulang\n\t\t\Tekan Enter"<<endl;
                    system("pause");
                    program();
            	}
				cout<<"masukan NIM \t\t : ";cin>>NIMbaru;
    			cin.ignore();
				cout<<"masukan nama mahasiswa \t : ";getline(cin,nama_mahasiswa);
    			cout<<"masukan jurusan \t : ";getline(cin,Jurusan);
				
				cout<<endl;
				cout<<"\nApa Data Sudah Benar ? [y/n]: ";cin>>yn;
                    if (yn=='y'|| yn=='Y'){
                        
						edit(NIM,NIMbaru,nama_mahasiswa,Jurusan);
                        
						system("pause");
                    }
                    else{
                    	program();
					}				
				break;
			}
			case 4:{
				system("cls");
				header();
				tampil();
				cout<<"masukan NIM \t: ";cin>>NIM;
				
				cout<<"\nYakin ingin menghapus ? [y/n]: ";cin>>yn;
                    if (yn== 'y'){
                        hapus(NIM);
						system("pause");
                    }
                    else{
                    	program();
					}
			
				break;
			}
			case 5:{
				cout<<"\n\n\t**********TERIMA KASIH**********"<<endl;
				exit(0);
				break;
			}
		
		}
	}
		while(pil!=5);	
		
}


void login(){
	system("cls");
	cout<<"LOGIN"<<endl<<endl;
	
	cout<<"Masukan Username \t: ";cin>>login1.username;
	cout<<"Masukan Password \t: ";cin>>login1.pass;
	
	if(login1.username==registrasi.username && login1.pass==registrasi.pass){
		Sleep(800);
		cout<<"..........................";
		Sleep(500);
		cout<<".........................\n";
		
		cout<<"\t\tLOGIN SUKSES"<<endl;
		Sleep(500);
		program();
	}
	else{
		cout<<"\t\nLOGIN GAGAL PERIKSA KEMBALI USERNAME DAN PASSWORD ANDA\n";
		system("pause");
		menu();
		
	}
}

void menu(){
system("cls");
	cout<<"=============WELLCOME============="<< endl;
	cout<<"1.LOGIN\n2.REGISTRASI\n";
	cout<<"Masukan perintah : ";cin>>pil;
	
		if(pil==1){
			login();
		}
		else if(pil==2){
			registrasi1();
		}
		else{
			cout<<"PERINTAH YANG ANDA MASUKAN SALAH"<<endl;
		}
		
}


void registrasi1(){
	system("cls");
	cout<<"\tREGISTRASI"<<endl<<endl;
	cout<<"Masukan Nama Depan \t: ";cin>>registrasi.nama_depan;
	cout<<"Masukan Nama Belakang \t: ";cin>>registrasi.nama_belakang;
	cout<<"Masukan Usename anda \t: ";cin>>registrasi.username;
	cout<<"Masukan Password anda \t: ";cin>>registrasi.pass;

	cout<<"\t\tREGISTRASI SUKSES\t\t"<<endl;
	cout<<"\n\t\tTekan Enter"<<endl;
	system("pause");
	menu();
}

void input(string NIM,string nama_mahasiswa,string Jurusan){
		
  mahasiswa *temp = new mahasiswa;
 
  
  temp->nim=NIM;
  temp->nama=nama_mahasiswa;
  temp->jurusan=Jurusan;
  temp->keluar = true;
  temp->next = NULL;
  	
	if(head == NULL) {
  	  head = temp;
      tail = temp;
  	}
	else {
    
	tail->next = temp;
    tail = temp;
  }
}
	
void tampil(){
	mahasiswa *temp=new mahasiswa;
	temp=head;
 	int i = 1;
  	cout <<"\n\t\t\t DAFTAR MAHASISWA  \n\n";
  		cout<<"-------------------------------------------------------------------------------------\n";
  		cout<< setiosflags(ios::left) << setw(3) << "|";
	    cout<< setiosflags(ios::left) << setw(5) << "NO" ;
		cout<< setiosflags(ios::left) << setw(10)<<" | ";
	    cout<< setiosflags(ios::left) << setw(10) << "NIM";
	    cout<< setiosflags(ios::left) << setw(8) << "|";
	    cout<< setiosflags(ios::left) << setw(20) << "NAMA";
	    cout<< setiosflags(ios::left) << setw(8) << "|";
	    cout<< setiosflags(ios::left) << setw(20) << "JURUSAN";
	    cout<< setiosflags(ios::left) << setw(20) << "|";
	    cout<<"-------------------------------------------------------------------------------------\n";
	  while(temp != NULL) {
    	if(temp->keluar) {
    	cout<< setiosflags(ios::left) << setw(3) << "|";
	    cout<< setiosflags(ios::left) << setw(5) << i;
		cout<< setiosflags(ios::left) << setw(5)<<" | ";
	    cout<< setiosflags(ios::left) << setw(15) <<temp->nim;
	    cout<< setiosflags(ios::left) << setw(2) << "|";
	    cout<< setiosflags(ios::left) << setw(26) <<temp->nama;
	    cout<< setiosflags(ios::left) << setw(3) << "|";
	    cout<< setiosflags(ios::left) << setw(25) << temp->jurusan;
	    cout<< setiosflags(ios::left) << setw(20) << "|"<< endl;
      	i++;
    	
		}
    	temp = temp->next;
  	}
}
	
	
void edit(string NIM,string NIMbaru,string nama_mahasiswa,string Jurusan){
	mahasiswa *temp = head;
    bool berhasil = false;
    while(temp != NULL) {
    if(temp->keluar){
      if(temp->nim == NIM) {
        temp->nim=NIMbaru;
		temp->nama= nama_mahasiswa;
        temp->jurusan=Jurusan;
        berhasil = true;
  		}
	  }
	  temp = temp->next;
  }
  cout << (berhasil? "\n\tData Berhasil Di Ubah" : "\n\tData Gagal dihapus") << endl;
}
	
	
void hapus(string NIM){	
	mahasiswa *temp = head;
	bool berhasil = false;
	while(temp != NULL) {
    
	if(temp->keluar) {
      if(temp->nim == NIM) {
		temp->keluar = false;
        berhasil = true;
         
	  }
    
	}
    temp = temp->next;
  }
   cout << (berhasil? "\n\tData Berhasil Di Hapus" : "\n\tData Tidak Ditemukan") << endl;
}	

