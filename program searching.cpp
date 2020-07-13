#include <iostream>
#include <string.h>

using namespace std;



int jenis_vokal=0,jenis_konsonan=0,jenis_numerik=0,angka_jenis=0,vokal_jenis=0;
int ubah,ketemu=0,konsonan_jenis=0;
char kata[100],vokal[100],konsonan[100],angka[100],masuk;


main()

{


	cout<<"===== TUGAS PRAKTIKUM STRUKTUR DATA =====\n\n";

	cout<<"MASUKAN KARAKTER : ";

	cin.getline(kata,100);

	ubah=strlen(kata);

		for(int a=0;a<ubah;a++){

			if(kata[a] =='a' || kata[a] == 'A' ||
			   kata[a] =='i' || kata[a] == 'I' ||
			   kata[a] =='u' || kata[a] == 'I' ||
			   kata[a] =='e' || kata[a] == 'E' ||
			   kata[a] =='o' || kata[a] == 'O' )
			   {
				jenis_vokal++;

				vokal_jenis++;

				vokal[vokal_jenis]=kata[a];

				}

			else if(kata[a] == '1'  ||  kata[a]== '2'  ||
					kata[a] == '3'  ||  kata[a] == '4' ||
					kata[a] == '5'  ||  kata[a] == '6' ||
					kata[a] == '7'  ||  kata[a] == '8' ||
					kata[a] == '9' ||  kata[a] == '0')
	
					{

					jenis_numerik++;

					angka_jenis++;

					angka[angka_jenis]=kata[a];

					}

			else if	(kata[a]=='b'||kata[a]=='B'||kata[a]=='d'||kata[a]=='D'||kata[a]=='g'||kata[a]=='G'||
         			 kata[a]=='j'||kata[a]=='J'||kata[a]=='k'||kata[a]=='K'||kata[a]=='l'||kata[a]=='L'||
         			 kata[a]=='m'||kata[a]=='M'||kata[a]=='n'||kata[a]=='N'||kata[a]=='q'||kata[a]=='Q'||
       				 kata[a]=='r'||kata[a]=='R'||kata[a]=='s'||kata[a]=='S'||kata[a]=='t'||kata[a]=='T'||
      				 kata[a]=='u'||kata[a]=='U'||kata[a]=='V'||kata[a]=='v'||kata[a]=='w'||kata[a]=='W'||
       				 kata[a]=='x'||kata[a]=='X'||kata[a]=='y'||kata[a]=='Y'||kata[a]=='z'||kata[a]=='Z'||
      				 kata[a]=='P'||kata[a]=='p'||kata[a]=='c'||kata[a]=='C'||kata[a]=='f'||kata[a]=='F'||
					 kata[a]=='h'||kata[a]=='H')

					{

					jenis_konsonan++;

					konsonan_jenis++;

					konsonan[konsonan_jenis]=kata[a];

					}

			}
//huruf vokal

	cout<<" Jumlah karakter \t: "<<ubah<<endl;
	
	cout<<" Jumlah huruf vokal \t: "<<jenis_vokal<<" = ";
	
		for(int a=0;a<=vokal_jenis;a++){

			cout<<vokal[a]<<"  , ";

			}
	cout<<endl;


//konsonan huruf

	cout<<" Jumlah huruf konsonan \t: "<<jenis_konsonan<<" = ";

		for(int a=0;a<=konsonan_jenis;a++){

			cout<<konsonan[a]<<" ,";

	}

	cout<<endl;


//numerik

	cout<<" Jumlah Numerik  \t: "<<jenis_numerik<<" = ";

		for(int a=0;a<=angka_jenis;a++){

			cout<<angka[a]<<" , ";

	}

	cout<<endl;


//pencarian karakter
	cout<<" Masukan karakter dicari : ";cin>>masuk;
	
		for(int a=0;a<ubah;a++){

			if(kata[a] == masuk){

			ketemu=1;

		}

	}

	cout<<endl<<endl;

		if(ketemu==1){

			cout<<"karakter ditemukan";
			
				
			}
		

		else{

			cout<<"karakter tidak ditemukan\n";
		}	
	
return 0;

}
