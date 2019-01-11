#include <iostream>
#include <string>

using namespace std;

struct kereta {
	int no_kereta;
	string nama_kereta;
	int harga;
	string lokasi_berangkat;
};

struct rute {
	kereta krt;
	int jumlah_gerbong;
};

typedef rute infotype;
typedef struct tNode *address;
typedef struct tNode
{
	infotype Info;
	address Next;
}Node;

typedef Node *List; 


void CreateEmpty(List &L)
{
	L = NULL;
}

bool IsEmpty(List L)
{
	return(L == NULL);
}

bool IsOneElmt(List L)
{
	return(IsEmpty(L->Next));
}

void InsertFirst(List &L, address P)
{
	P->Next = L;
	L = P;
}

void InsertAfter(List &L, address Prec, address P)
{
	P->Next = Prec->Next;
	Prec->Next = P;
}

void InsertLast(List &L, address P)
{
	if (IsEmpty(L))             
		InsertFirst(L, P);
	else if (IsOneElmt(L))      
		InsertAfter(L, L, P);
	else
		InsertLast(L->Next, P);  
}

address Alokasi(infotype X)
{
	address P = new(Node);
	if (P == NULL)     
		return NULL;
	else           
	{
		P->Info = X;
		P->Next = NULL;
		return P;
	}
}
void PrintInfoKereta(kereta data_kereta[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "\nNo Kereta     : " << data_kereta[i].no_kereta;
		cout << "\nNama Kereta   : " << data_kereta[i].nama_kereta;
		cout << "\nStasius Berangkat   : " << data_kereta[i].lokasi_berangkat;
		cout << "\nHarga         : Rp" << data_kereta[i].harga;
		cout << "\n-------------------------------------------------------------------------------";
	}
	
}

void PrintInfoRute(List L, int n)
{
	if (IsEmpty(L))		
	{  
	}
	else			
	{
		cout << "\nNo Urut. " << n;
		cout << "\nNama Kereta\t: " << L->Info.krt.nama_kereta;
		cout << "\nHarga\t\t: " << L->Info.krt.harga;
		cout << "\nJumlah Gerbong\t: " << L->Info.jumlah_gerbong;
		cout << "\nLokasi Berangkat: " << L->Info.krt.lokasi_berangkat;
		cout << "\n----------->>>>>>>>>>>>>>>>>>>";
		PrintInfoRute(L->Next, n+1);
	}
}


void DelFirst(List &L)
{
	address P;
	P = L;
	L = L->Next;
	delete(P); 
}

void DelLast(List &L)
{
	if (IsOneElmt(L))
		DelFirst(L);
	else
		DelLast(L->Next);
}

void DelAt(List &L, address P)
{
	if (!IsEmpty(L))
	{
		if (L == P)
			DelFirst(L);
		else
			DelAt(L->Next, P);
	}
}

int countListEl(List L)
{

	int jmlel = 0;
	while (!IsEmpty(L))
	{
		++jmlel;
		L = L->Next;
	}
	return jmlel;
}

int main()
{
	int pil_menu = 0;
	int pil_no_menu = 0;
	int no_urut_menu_edit= 0;
	int no_urut_menu_delete = 0;
	rute perjalanan;

	List ListKereta;
	CreateEmpty(ListKereta);

	kereta data_kereta[5];
	
	data_kereta[0].no_kereta = 1;
	data_kereta[0].nama_kereta = "Trans Jogja";
	data_kereta[0].harga = 150000;
	data_kereta[0].lokasi_berangkat = "Yogyakarta";

	data_kereta[1].no_kereta = 2;
	data_kereta[1].nama_kereta = "Pasar Senen";
	data_kereta[1].harga = 120000;
	data_kereta[1].lokasi_berangkat = "Jakarta";

	data_kereta[2].no_kereta = 3;
	data_kereta[2].nama_kereta = "Gajayana";
	data_kereta[2].harga = 110000;
	data_kereta[2].lokasi_berangkat = "Malang";

	data_kereta[3].no_kereta = 4;
	data_kereta[3].nama_kereta = "Sembrani";
	data_kereta[3].harga = 200000;
	data_kereta[3].lokasi_berangkat = "Cirebon";

	data_kereta[4].no_kereta = 5;
	data_kereta[4].nama_kereta = "Argo Lawu";
	data_kereta[4].harga = 55000;
	data_kereta[4].lokasi_berangkat = "Solo";
	do
	{
		system("cls");
		cout << "===== PT.KAI INDONESIA =====\n\n";
		cout << "\n=====         M E N U            =====";
		cout << "\n1. Ambil Tiket Kereta Api";
		cout << "\n2. Lihat Data Tiket";
		cout << "\n3. Ubah Data Tiket";
		cout << "\n4. Hapus Tiket";
		cout << "\n5. Keluar ";
		cout << "\n======================================";
		cout << "\nMasukkan menu yang Anda inginkan: ";
		cin >> pil_menu;

		switch (pil_menu)
		{
		case 1:
			system("cls");
			cout << "===== Ambil Tiket Kereta Api =====";
			PrintInfoKereta(data_kereta);
			
			do
			{
				cout << "\nMasukkan nomor kereta yang anda inginkan: ";
				cin >> pil_no_menu;

				if (pil_no_menu < 1 || pil_no_menu > 5)
				{
					cout << "Nomor kereta tidak tersedia... \n";
				}
			} while (pil_no_menu < 1 || pil_no_menu > 5);
			
			
			if (pil_no_menu>=1 && pil_no_menu<=5)
			{
				cout << "Masukkan jumlah gerbong kereta : ";
				cin >> perjalanan.jumlah_gerbong;
				perjalanan.krt = data_kereta[pil_no_menu - 1];
				address ruteBaru = Alokasi(perjalanan);
				InsertLast(ListKereta, ruteBaru);

				cout << "\n\nTiket Berhasil Ditambahkan...";
			}
			else
			{
				cout << "\n Error....";
			}
			break;
		case 2:
			system("cls");
			cout << "=====  Data Tiket    =====";
			if (!IsEmpty(ListKereta))
			{
				cout << "\nData Tiket : ";
				PrintInfoRute(ListKereta, 1);
			}
			else
			{
				cout << "\nAnda belum mengambil tiket";
			}
			break;
		case 3:
			system("cls");
			cout << "=====    UBAH DATA TIKET     =====";
			if (!IsEmpty(ListKereta))
			{
				cout << "\nTiket yang Anda Pesan: ";
				PrintInfoRute(ListKereta, 1);

				do
				{
					cout << "\nMasukkan Urutan Yang Akan Diubah: ";
					cin >> no_urut_menu_edit;
				} while (no_urut_menu_edit>countListEl(ListKereta) || no_urut_menu_edit<1);
				cout << endl << endl;

				PrintInfoKereta(data_kereta);

				do
				{
					cout << "\nMasukkan nomor menu yang anda inginkan: ";
					cin >> pil_no_menu;

					if (pil_no_menu < 1 || pil_no_menu > 5)
					{
						cout << "Nomor Kereta Tidak Tersedia... \n";
					}
				} while (pil_no_menu < 1 || pil_no_menu > 5);


				if (pil_no_menu >= 1 && pil_no_menu <= 5)
				{
					cout << "Masukkan jumlah gerbong kereta : ";
					cin >> perjalanan.jumlah_gerbong;
					perjalanan.krt = data_kereta[pil_no_menu - 1];
					address ruteBaru = Alokasi(perjalanan);
					
					if (no_urut_menu_edit == 1)
					{
						address temp = ListKereta;
						ruteBaru->Next = temp->Next;
						ListKereta = ruteBaru;
						delete(temp);
					}
					else
					{
						address temp_prec = ListKereta;
						for (int i = 0; i < no_urut_menu_edit-2; i++)
						{
							temp_prec = temp_prec->Next;
						}
						ruteBaru->Next = temp_prec->Next->Next;
						address temp = temp_prec->Next;
						temp_prec->Next = ruteBaru;
						delete(temp);
					}

					cout << "\n\nUrutan perjalanan berhasil dirubah...";
				}
				#pragma endregion


			}
			else
			{
				cout << "\nAnda belum memiliki tiket untuk diubah";
			}
			break;
		case 4:
			system("cls");
			cout << "=====      Hapus data Tiket         =====";
			if (!IsEmpty(ListKereta))
			{
				cout << "\nDaftar Tiket: ";
				PrintInfoRute(ListKereta, 1);

				do
				{
					cout << "\nMasukkan no urut tiket yang akan dihapus: ";
					cin >> no_urut_menu_delete;
				} while (no_urut_menu_delete>countListEl(ListKereta) || no_urut_menu_delete<1);
				cout << endl << endl;

				address temp_del = ListKereta;
				for (int i = 0; i < no_urut_menu_delete-1; i++)
				{
					temp_del = temp_del->Next;
				}

				DelAt(ListKereta, temp_del);

				cout << "\n\nData tiket berhasil dihapus...";

			}
			else
			{
				cout << "\nBelum ada Tiket ";
			}
			break;
		case 5:
			system("cls");
			cout << "=====     SAMPAI JUMPA LAGI      =====";
			break;
		default:
			system("cls");
			cout << "===== Pilihan Tidak Ada =====";
			break;
		}
		
		cout << endl;
		system("pause");
	} while (pil_menu!=5);
	return 0;
}





