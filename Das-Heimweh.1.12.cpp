#include <iostream>
#include <clocale>
#include <ctime>		//	Random icin gereklidir
#include <iomanip>		//	Yüzde oranı küsürat hanesi ve setfill/setw için gereklidir
#include <thread>		//	sleep için gereklidr
#include <chrono>		//	+sleep icin gereklidir

using namespace std;

/*
	DAS HEIMWEH ~~
-	Yazilim Sanayicileri Dernegi (YASAD) Baskani Gonul Kamali'nin 2021 yilinda 30 bin yazilimcinin ulkeyi
	terk ettigi haberi uzerine, ayrica dolayisiyla diger Turk vatandaslari dusunulerek ara sira acilip
	oynanabilecek, illerin plaka kodlari sorulan bir oyundur.
-	Sorulacak soru sayisi kullanici tarafindan belirlenir. Iller rastgele sorulur.
-	Konaklanilan iller denk geldiginde yer yer o ille ilgili anilarin hatirlanmasi beklenir. O nedenle 10 saniye
	icerisinde bilinmesi gibi bir sure sinirlanmasi yoktur.
-	Marka degeri calismasi ile Almanca "Sila Hasreti" anlamina gelen sozcuk obegi secilmistir.
-	Oyun sonunda basari yuzdesi, Solo Test basari siralamasi ve Ilkogretim Kurumlari Yonetmeligine gore 3 farkli
	sekilde gosterilir.
-	Not: Oyun programi hazirlandiginda Turkiye'de 81 il bulunuyor, sayisi cogalirsa il arrayinin devamina eklenip
	while dongusundeki rand yuzdesinin yanindaki 81 sayisi degistirilerek uyum saglanabilir. Ancak sira degisimi
	yapilirsa string arrayi tekrar duzenlenmelidir.
*/


int main() {
	setlocale(LC_ALL, "tr_TR.ISO-8859-9");
	int soru = 1, rastgele = 0, kacSoru = 5, dogruSayisi = 0, yanlisSayisi = 0, plakaCevap = 0;
	float sonuc = 0;
	string ilCevap;
	srand(time(0));


	//	KAPAK
	cout << "\t\t" << (char)15 << "-----------------------------------------------" << (char)15 << endl;
	cout << "\t\t|  DAS HEIMWEH               Serkan SARP @ 2023 |" << endl;
	cout << "\t\t" << char(15) << "-----------------------------------------------" << (char)15 << endl << endl;
	cout << "\t\tSeçtiğiniz kadar soru sayısıyla sınanarak Türkiye'den iller ve plaka kodları ile" << endl;
	cout << "\t\tsınandığınız, başarı oranınızla kendinizi test ettiğiniz programdır." << endl << endl;

	//	IL ARRAYI
	string il[82] = { "0","Adana","Adıyaman","Afyon","Ağrı","Amasya","Ankara","Antalya","Artvin","Aydın","Balıkesir",
						"Bilecik","Bingöl","Bitlis","Bolu","Burdur","Bursa","Çanakkale","Çankırı","Çorum","Denizli",
						"Diyarbakır","Edirne","Elazığ","Erzincan","Erzurum","Eskişehir","Gaziantep","Giresun","Gümüşhane","Hakkari",
						"Hatay","Isparta","İçel","İstanbul","İzmir","Kars","Kastamonu","Kayseri","Kırklareli","Kırşehir",
						"Kocaeli","Konya","Kütahya","Malatya","Manisa","Maraş","Mardin","Muğla","Muş","Nevşehir",
						"Niğde","Ordu","Rize","Sakarya","Samsun","Siirt","Sinop","Sivas","Tekirdağ","Tokat",
						"Trabzon","Tunceli","Urfa","Uşak","Van","Yozgat","Zonguldak","Aksaray","Bayburt","Karaman",
						"Kırıkkale","Batman","Şırnak","Bartın","Ardahan","Iğdır","Yalova","Karabük","Kilis","Osmaniye",
						"Düzce" };

	// Kaç soru soralım?
	cout << "\t\tKendinizi kaç soruyla sınamak istediğinizi giriniz (Yüksek sayı = hassas sonuç): "; cin >> kacSoru;
	cout << "\033[2J\033[1;1H";		//	Ekran temizliği için ansi kaçış kodu (linux+windows)

	// Yarışma
	while (soru <= kacSoru) {
		cout << "\tDAS HEIMWEH" << endl << "\t................." << endl << "\tSORU " << soru << endl;
		rastgele = rand() % (81 - 1 + 1) + 1;
		cout << "\t" << il[rastgele] << ": ";
		cin >> plakaCevap;
		if (plakaCevap == rastgele) {
			cout << "\tDoğru!" << endl;
			dogruSayisi++;
		}
		else {
			cout << "\tYanlış, doğrusu " << setfill('0') << setw(2) << rastgele << endl;
			yanlisSayisi++;
		}soru++;
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "\033[2J\033[1;1H";		//	Ekran temizliği için ansi kaçış kodu (linux+windows)
	}


	// Hesap 
	cout << "\tDAS HEIMWEH               Serkan SARP @ 2023" << endl << "\t............................................" << endl;
	cout << "\t- " << kacSoru << " soruda " << dogruSayisi << " doğru / " << yanlisSayisi << " yanlış" << endl;
	sonuc = dogruSayisi * 100 / (float)kacSoru;
	cout << "\t  % " << fixed << setprecision(2) << sonuc << " başarılı oldunuz." << endl << endl;

	cout << "\t- Solo Test'e göre ";

	if (sonuc < 11.12) { cout << "Beyinsiz"; }
	else if (sonuc < 22.23) { cout << "Gerizekalı"; }
	else if (sonuc < 33.34) { cout << "Aptal"; }
	else if (sonuc < 44.45) { cout << "Tecrübesiz"; }
	else if (sonuc < 55.56) { cout << "Normal"; }
	else if (sonuc < 66.67) { cout << "Başarılı"; }
	else if (sonuc < 77.78) { cout << "Kurnaz"; }
	else if (sonuc < 88.89) { cout << "Zeki"; }
	else { cout << "Bilgin"; }
	cout << " derecesindesiniz.\n\t- İlköğretim Kurumları Yönetmeliğine göre ";

	if (sonuc < 45) { cout << "(1) Başarısız"; }
	else if (sonuc < 55) { cout << "(2) Geçer"; }
	else if (sonuc < 69) { cout << "(3) Orta"; }
	else if (sonuc < 85) { cout << "(4) İyi"; }
	else { cout << "(5) Pekiyi"; }
	cout << " not aldınız." << endl << endl;

	cout << "\t- Yüksek sonuçlar için kendinizi sınamaya devam edebilir,\n\t  hassas sonuçlar için soru sayısını yüksek tutabilirsiniz." << endl << endl;

	cout << endl; return 0;
}
