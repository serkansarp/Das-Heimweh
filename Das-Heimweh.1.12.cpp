#include <iostream>
#include <clocale>
#include <ctime>		//	Random icin gereklidir
#include <iomanip>		//	Y�zde oran� k�s�rat hanesi ve setfill/setw i�in gereklidir
#include <windows.h>	//	cls ve Sleep icin gereklidir

using namespace std;

/*
	DAS HEIMWEH ~~
-	Turkiye disinda yasayan yazilimcilar (ve dolayisiyla diger Turk vatandaslari) dusunulerek ara sira acilip
	oynanabilecek, illerin plaka kodlari sorulan bir oyundur.
-	Sorulacak soru sayisi kullanici tarafindan belirlenir. Iller rastgele sorulur.
-	Konaklanilan iller denk geldiginde yer yer o ille ilgili anilarin hatirlanmasi beklenir. O nedenle sure
	sinirlanmasi yoktur.
-	Marka degeri calismasi ile Almanca "Sila Hasreti" anlamina gelen sozcuk obegi secilmistir.
-	Oyun sonunda basari yuzdesi, Solo Test basari siralamasi ve Ilkogretim Kurumlari Yonetmeligine gore 3 farkli
	sekilde gosterilir.
-	Not: Oyun programi hazirlandiginda Turkiye'de 81 il bulunuyor, sayisi cogalirsa il arrayinin devamina eklenip
	while dongusundeki rand yuzdesinin yanindaki 81 sayisi degistirilerek uyum saglanabilir. Ancak sira degisimi
	yapilirsa string arrayi tekrar duzenlenmelidir.
*/


int main() {
	setlocale(LC_ALL, "Turkish");
	int soru = 1, rastgele = 0, kacSoru = 5, dogruSayisi = 0, yanlisSayisi = 0, plakaCevap = 0;
	float sonuc = 0;
	string ilCevap;
	srand(time(0));


	//	KAPAK
	cout << "\t\t" << (char)15 << "-----------------------------------------------" << (char)15 << endl;
	cout << "\t\t|  DAS HEIMWEH               Serkan SARP @ 2023 |" << endl;
	cout << "\t\t" << char(15) << "-----------------------------------------------" << (char)15 << endl << endl;
	cout << "\t\tSe�ti�iniz kadar soru say�s�yla s�nanarak T�rkiye'den iller ve plaka kodlar� ile" << endl;
	cout << "\t\ts�nand���n�z, ba�ar� oran�n�zla kendinizi test etti�iniz programd�r." << endl << endl;

	//	IL ARRAYI
	string il[82] = { "0","Adana","Ad�yaman","Afyon","A�r�","Amasya","Ankara","Antalya","Artvin","Ayd�n","Bal�kesir",
						"Bilecik","Bing�l","Bitlis","Bolu","Burdur","Bursa","�anakkale","�ank�r�","�orum","Denizli",
						"Diyarbak�r","Edirne","Elaz��","Erzincan","Erzurum","Eski�ehir","Gaziantep","Giresun","G�m��hane","Hakkari",
						"Hatay","Isparta","��el","�stanbul","�zmir","Kars","Kastamonu","Kayseri","K�rklareli","K�r�ehir",
						"Kocaeli","Konya","K�tahya","Malatya","Manisa","Mara�","Mardin","Mu�la","Mu�","Nev�ehir",
						"Ni�de","Ordu","Rize","Sakarya","Samsun","Siirt","Sinop","Sivas","Tekirda�","Tokat",
						"Trabzon","Tunceli","Urfa","U�ak","Van","Yozgat","Zonguldak","Aksaray","Bayburt","Karaman",
						"K�r�kkale","Batman","��rnak","Bart�n","Ardahan","I�d�r","Yalova","Karab�k","Kilis","Osmaniye",
						"D�zce" };

	// Ka� soru soral�m?
	cout << "\t\tKendinizi ka� soruyla s�namak istedi�inizi giriniz (Y�ksek say� = hassas sonu�): "; cin >> kacSoru;
	system("cls");

	// Yar��ma
	while (soru <= kacSoru) {
		cout << "\tDAS HEIMWEH" << endl << "\t................." << endl << "\tSORU " << soru << endl;
		rastgele = rand() % (81 - 1 + 1) + 1;
		cout << "\t" << il[rastgele] << ": ";
		cin >> plakaCevap;
		if (plakaCevap == rastgele) {
			cout << "\tDo�ru!" << endl;
			dogruSayisi++;
		}
		else {
			cout << "\tYanl��, do�rusu " << setfill('0') << setw(2) << rastgele << endl;
			yanlisSayisi++;
		}soru++;
		Sleep(1000);
		system("cls");
	}


	// Hesap 
	cout << "\tDAS HEIMWEH               Serkan SARP @ 2023" << endl << "\t............................................" << endl;
	cout << "\t- " << kacSoru << " soruda " << dogruSayisi << " do�ru / " << yanlisSayisi << " yanl��" << endl;
	sonuc = dogruSayisi * 100 / (float)kacSoru;
	cout << "\t  % " << fixed << setprecision(2) << sonuc << " ba�ar�l� oldunuz." << endl << endl;

	cout << "\t- Solo Test'e g�re ";

	if (sonuc < 11.12) { cout << "Beyinsiz"; }
	else if (sonuc < 22.23) { cout << "Gerizekal�"; }
	else if (sonuc < 33.34) { cout << "Aptal"; }
	else if (sonuc < 44.45) { cout << "Tecr�besiz"; }
	else if (sonuc < 55.56) { cout << "Normal"; }
	else if (sonuc < 66.67) { cout << "Ba�ar�l�"; }
	else if (sonuc < 77.78) { cout << "Kurnaz"; }
	else if (sonuc < 88.89) { cout << "Zeki"; }
	else { cout << "Bilgin"; }
	cout << " derecesindesiniz.\n\t- �lk��retim Kurumlar� Y�netmeli�ine g�re ";

	if (sonuc < 45) { cout << "(1) Ba�ar�s�z"; }
	else if (sonuc < 55) { cout << "(2) Ge�er"; }
	else if (sonuc < 69) { cout << "(3) Orta"; }
	else if (sonuc < 85) { cout << "(4) �yi"; }
	else { cout << "(5) Pekiyi"; }
	cout << " not ald�n�z." << endl << endl;

	cout << "\t- Y�ksek sonu�lar i�in kendinizi s�namaya devam edebilir,\n\t  hassas sonu�lar i�in soru say�s�n� y�ksek tutabilirsiniz." << endl << endl;

	cout << endl; return 0;
}
