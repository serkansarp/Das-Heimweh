#include <iostream>
#include <clocale>
#include <ctime>		//	Random icin gereklidir
#include <iomanip>		//	Yüzde oraný küsürat hanesi ve setfill/setw için gereklidir
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
	cout << "\t\tSeçtiðiniz kadar soru sayýsýyla sýnanarak Türkiye'den iller ve plaka kodlarý ile" << endl;
	cout << "\t\tsýnandýðýnýz, baþarý oranýnýzla kendinizi test ettiðiniz programdýr." << endl << endl;

	//	IL ARRAYI
	string il[82] = { "0","Adana","Adýyaman","Afyon","Aðrý","Amasya","Ankara","Antalya","Artvin","Aydýn","Balýkesir",
						"Bilecik","Bingöl","Bitlis","Bolu","Burdur","Bursa","Çanakkale","Çankýrý","Çorum","Denizli",
						"Diyarbakýr","Edirne","Elazýð","Erzincan","Erzurum","Eskiþehir","Gaziantep","Giresun","Gümüþhane","Hakkari",
						"Hatay","Isparta","Ýçel","Ýstanbul","Ýzmir","Kars","Kastamonu","Kayseri","Kýrklareli","Kýrþehir",
						"Kocaeli","Konya","Kütahya","Malatya","Manisa","Maraþ","Mardin","Muðla","Muþ","Nevþehir",
						"Niðde","Ordu","Rize","Sakarya","Samsun","Siirt","Sinop","Sivas","Tekirdað","Tokat",
						"Trabzon","Tunceli","Urfa","Uþak","Van","Yozgat","Zonguldak","Aksaray","Bayburt","Karaman",
						"Kýrýkkale","Batman","Þýrnak","Bartýn","Ardahan","Iðdýr","Yalova","Karabük","Kilis","Osmaniye",
						"Düzce" };

	// Kaç soru soralým?
	cout << "\t\tKendinizi kaç soruyla sýnamak istediðinizi giriniz (Yüksek sayý = hassas sonuç): "; cin >> kacSoru;
	system("cls");

	// Yarýþma
	while (soru <= kacSoru) {
		cout << "\tDAS HEIMWEH" << endl << "\t................." << endl << "\tSORU " << soru << endl;
		rastgele = rand() % (81 - 1 + 1) + 1;
		cout << "\t" << il[rastgele] << ": ";
		cin >> plakaCevap;
		if (plakaCevap == rastgele) {
			cout << "\tDoðru!" << endl;
			dogruSayisi++;
		}
		else {
			cout << "\tYanlýþ, doðrusu " << setfill('0') << setw(2) << rastgele << endl;
			yanlisSayisi++;
		}soru++;
		Sleep(1000);
		system("cls");
	}


	// Hesap 
	cout << "\tDAS HEIMWEH               Serkan SARP @ 2023" << endl << "\t............................................" << endl;
	cout << "\t- " << kacSoru << " soruda " << dogruSayisi << " doðru / " << yanlisSayisi << " yanlýþ" << endl;
	sonuc = dogruSayisi * 100 / (float)kacSoru;
	cout << "\t  % " << fixed << setprecision(2) << sonuc << " baþarýlý oldunuz." << endl << endl;

	cout << "\t- Solo Test'e göre ";

	if (sonuc < 11.12) { cout << "Beyinsiz"; }
	else if (sonuc < 22.23) { cout << "Gerizekalý"; }
	else if (sonuc < 33.34) { cout << "Aptal"; }
	else if (sonuc < 44.45) { cout << "Tecrübesiz"; }
	else if (sonuc < 55.56) { cout << "Normal"; }
	else if (sonuc < 66.67) { cout << "Baþarýlý"; }
	else if (sonuc < 77.78) { cout << "Kurnaz"; }
	else if (sonuc < 88.89) { cout << "Zeki"; }
	else { cout << "Bilgin"; }
	cout << " derecesindesiniz.\n\t- Ýlköðretim Kurumlarý Yönetmeliðine göre ";

	if (sonuc < 45) { cout << "(1) Baþarýsýz"; }
	else if (sonuc < 55) { cout << "(2) Geçer"; }
	else if (sonuc < 69) { cout << "(3) Orta"; }
	else if (sonuc < 85) { cout << "(4) Ýyi"; }
	else { cout << "(5) Pekiyi"; }
	cout << " not aldýnýz." << endl << endl;

	cout << "\t- Yüksek sonuçlar için kendinizi sýnamaya devam edebilir,\n\t  hassas sonuçlar için soru sayýsýný yüksek tutabilirsiniz." << endl << endl;

	cout << endl; return 0;
}
