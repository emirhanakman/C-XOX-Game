#include <iostream> // Kullan�c�dan de�er almam�z� sa�layan k�t�phane.
#include<time.h> // zaman saya� k�t�phanemiz.
#include<stdlib.h> // RAndom i�in kulland���m�z k�t�phane.

using namespace std;

char bolge[10] = {'0','1','2','3','4','5','6','7','8','9'};  // 9 tane XOX b�lgesi olu�turuyoruz.

// Yapay zeka oynama say�s� :
int yzsira = 1;

// Zorluk -> Kolay : 0 || Orta : 1 || Zor : 2
int zorluk = 1; // zorluk seviyesi.

// Oyunu Bitiren olup olmad���n� kontrol eder :

bool bitirenvar = false;  // Oyun basladiginde bitireni degerini sifirla. ( Oyun basladiginda bitiren olamaz. )

void zeminciz(){
 // XOX oyunun taban� olan 9 b�lge olu�turuyoruz.
    cout << endl << bolge[1] << " | " << bolge[2] << " | " << bolge[3] << endl  //  B�lge 1 | B�lge 2 | B�lge 3
                 << "- | - | -" << endl
                 << bolge[4] << " | " << bolge[5] << " | " << bolge[6] << endl  // B�lge 4 | B�lge 5 | B�lge 6
                 << "- | - | -" << endl
                 << bolge[7] << " | " << bolge[8] << " | " << bolge[9] << endl << endl ; // B�lge 7 / B�lge 8 / B�lge 9

}

bool kontrol(int yer){
// Yeri kontrol et.  Yer X'e ve 0'a e�it de�ilse oyuna devam et. 
    return ((bolge[yer] != 'X' && bolge[yer] != 'O' ? true : false));

}

int rndsayi(int sayi = 9){//Random say� olu�tur 9 de�erini ver.

    return (rand() % sayi + 1);

}

int rndkontrol(int rnd, int sayi = 9){// XOX alanlar�nda 1 ile 9 aras�nda (9 B�lgemiz var XOX'de) rastgele say� olu�turuyor.

    if(kontrol(rnd)){

        return rnd;// 

    }else{ 

        return (rndkontrol(rndsayi(sayi)));//
// Olu�turulan Rastgele say� de�eri daha �nce  olu�turulmu� mu diye kontrol ediyor.
    }

}

int caprazolasilik(int bolge1, int bolge2, int yer){ // �apraz olarak XXX veya OOO gelme olas�l���n� kontrol ediyor.

    if(((bolge[bolge1] == 'X' && bolge[bolge2] == 'X') || (bolge[bolge1] == 'O' && bolge[bolge2] == 'O')) && (bolge[yer] != 'X' && bolge[yer] != 'O'))
        return yer;
 // B�lge1 = X   ve  B�lge2 = X veya B�lge1 = 0 ve B�lge2 = 0      ve   B�lge e�it de�ilse X'e   ve B�lge e�it de�ilse 0'a.
     // Uygun yer bulunamad�ysa :
    return 0; // de�eri d�nd�r.
}

int zeka(){ 
// Zeka b�l�m�. Bu b�l�mde yapay zekan�n, kullan�c� hamle yapt�ktan sonra hangi alanlar� se�ece�ini, dolu-bo� alanlar� ay�rt edebilece�ini ve ona g�re hamle yapaca��n�n kodlar� yaz�l�d�r.

    // Olas�l�klar:

    // Dikey Olas�l�klar : -------------------------------------------------------------------------------------------------------------------

    // 1,2,3 ve 4,5,6 ayn� cins doluysa 7,8,9'a koy.
    for(int a = 1,b = 4, c = 7; a <= 3;a++,b++,c++){
        if(((bolge[a] == 'X' && bolge[b] == 'X') || (bolge[a] == 'O' && bolge[b] == 'O')) && (bolge[c] != 'X' && bolge[c] != 'O'))
            return c;
    }

    // 7,8,9 ve 4,5,6 ayn� cins doluysa 1,2,3'a koy.
    for(int a = 7,b = 4, c = 1; a <= 9;a++,b++,c++){
        if(((bolge[a] == 'X' && bolge[b] == 'X') || (bolge[a] == 'O' && bolge[b] == 'O')) && (bolge[c] != 'X' && bolge[c] != 'O'))
            return c;
    }

    // 1,2,3 ve 7,8,9 ayn� cins doluysa 4,5,6'a koy.
    for(int a = 1,b = 7, c = 4; a <= 3;a++,b++,c++){
        if(((bolge[a] == 'X' && bolge[b] == 'X') || (bolge[a] == 'O' && bolge[b] == 'O')) && (bolge[c] != 'X' && bolge[c] != 'O'))
            return c;
    }


    // Yatay Olas�l�klar : ----------------------------------------------------------------------------------------------------------------------------


    // 1,4,7 ve 2,4,8 ayn� cins doluysa 3,6,9'a koy.

    for(int a = 1; a <= 7; a += 3){
        if(((bolge[a] == 'X' && bolge[a+1] == 'X') || (bolge[a] == 'O' && bolge[a+1] == 'O')) && (bolge[a+2] != 'X' && bolge[a+2] != 'O'))
            return (a+2);
    }

    // 2,5,8 ve 3,6,9 ayn� cins doluysa 1,4,7'a koy.

    for(int a = 2; a <= 8; a += 3){
        if(((bolge[a] == 'X' && bolge[a+1] == 'X') || (bolge[a] == 'O' && bolge[a+1] == 'O')) && (bolge[a-1] != 'X' && bolge[a-1] != 'O'))
            return (a-1);
    }

    // 1,4,7 ve 3,6,9 ayn� cins doluysa 2,5,8'a koy.

    for(int a = 1; a <= 7; a += 3){
        if(((bolge[a] == 'X' && bolge[a+2] == 'X') || (bolge[a] == 'O' && bolge[a+2] == 'O')) && (bolge[a+1] != 'X' && bolge[a+1] != 'O'))
            return (a+1);
    }


    // �apraz Olas�l�klar : -------------------------------------------------------------------------------------------------------------------------

    // 1 - 5 -> 9
    if(caprazolasilik(1,5,9) != 0)
        return caprazolasilik(1,5,9);

    // 3 - 5 -> 7
    if(caprazolasilik(3,5,7) != 0)
        return caprazolasilik(3,5,7);

    // 5 - 9 -> 1
    if(caprazolasilik(5,9,1) != 0)
        return caprazolasilik(5,9,1);

    // 7 - 5 -> 3
    if(caprazolasilik(7,5,3) != 0)
        return caprazolasilik(7,5,3);

    // 1 - 9 -> 5
    if(caprazolasilik(1,9,5) != 0)
        return caprazolasilik(1,9,5);

    // 3 - 7 -> 5
    if(caprazolasilik(3,7,5) != 0)
        return caprazolasilik(3,7,5);


    // E�er ZOR seviye se�iliyse ve bir olas�l�k yoksa k��eye oyna :
    int rnd = rndkontrol(rndsayi(4));

    switch(rnd){

        case 1:
            return 1;
            break;
        case 2:
            return 3;
            break;
        case 3:
            return 7;
            break;
        case 4:
            return 9;
            break;
        default:
            cout << "Bir Hata Olu�tu : E�er zor se�iliyse ve bir olas�l�k yoksa k��eye oyna." << endl;
            break;

    }

    // Hi�bir olas�l�k yoksa rastgele se� :
    return rndkontrol(rndsayi());;

}

void yapayzeka(){ // Yapay zekan�n oyun hamlesi bu metotun i�erisinde:

    if(yzsira == 1){

        // Zor se�ilmediyse ilk oyunda rastgele yer se� :
        if(zorluk != 2) {

            int rnd = rndsayi();

            if (kontrol(rnd)) {
                bolge[rnd] = 'O';
            } else {
                yapayzeka();
            }

        }else {

            if((bolge[5] != 'X' && bolge[5] != 'O')){
                // Orta Bo�sa :
                bolge[5] = 'O';
            }else{
                // Orta Bo� De�ilse :
                bolge[zeka()] = 'O';}

        }
    }else{

        bolge[zeka()] = 'O';

    }

    // E�er kolay se�ilmi�se hep raskele oynar :
    if(zorluk != 0)
    yzsira++;

}

void oyna(char oyuncu){

    if(oyuncu == 'X'){// Kullan�c� .

        int yer;

        cout << "Sira X'de : X'i Yerlestireceginiz Alan Numarasini Yaziniz."; // Kullan�c�n�n s�ras�.

            cin >> yer;  

        if(kontrol(yer)){// Kullan�c� hamle yapaca�� alan� se�iyor. E�er  o alan bo� ise oraya X de�erini veriyor.

            bolge[yer] = 'X';

        }else{   // O alana daha �nce de�er verilmi�se Hatal� Giri� uyar�s� al�yor.

            cout << "Hatal� Giri� !" << endl;  
            oyna('X');

        }

    }else{

        cout << "Sira O'da ..." << endl ;  

        yapayzeka();  // 0'lar� Yapay Zeka Kontrol Ediyor.Yapay Zeka metodunda i�lem ger�ekle�iyor.

    }

}

void kimbitirdi(int yer){
 // Oyunu kimin kazand���n�n tespiti ; 
    if(bolge[yer] == 'X') {  // X Kullanici idi. Kullanici 3 yanyana,dikey veya capraz koymayi basardiysa kullanici kazandi.
        cout << "Kazanan : X\n! Tebrikler Siz Kazandiniz.. !" << endl; 
    } else{  // Degilse Gulsen'in yapay zekasi kazandi :)))
        cout << "Kazanan : O\n! Gulsen'in Yapay Zekasi Kazandi . !" << endl;  
    }

    bitirenvar = true; // BitirenVar metodunu aktiflestir. 

}

bool bittimi(){//Bitti mi kontrolunu sa�l�yor.

    // Yatay Kontrol
    for(int i = 1; i <= 7; i += 3){
        if((bolge[i] == 'X' && bolge[i+1] == 'X' && bolge[i+2] == 'X') || (bolge[i] == 'O' && bolge[i+1] == 'O' && bolge[i+2] == 'O')) {
            kimbitirdi(i+1);
            return true;  // Yatay olarak XXX ya da 000 yan yana geldiyse. 
            /*
			1 2 3          
			4 5 6           Bu alanlarda 123 veya 456 veya 789 alanlar�n�n yanyana X ya da 0 olmas�n� kontrol eden if d�ng�s� yukar�da yaz�l�d�r.
			7 8 9 
			*/ 
        }
    }

    // Dikey Kontrol
    for(int i = 1; i <= 9; i++){
        if((bolge[i] == 'X' && bolge[i+3] == 'X' && bolge[i+6] == 'X') || (bolge[i] == 'O' && bolge[i+3] == 'O' && bolge[i+6] == 'O')){
            kimbitirdi(i+3);
            return true;
        }/*
			1 2 3          
			4 5 6           Bu alanlarda 147 veya 258 veya 369 alanlar�n�n dikey olarak X ya da 0 olmas�n� kontrol eden if d�ng�s� yukar�da yaz�l�d�r.
			7 8 9 
			*/ 
    }

    // �apraz Kontrol :
    if((bolge[1] == 'X' && bolge[5] == 'X' && bolge[9] == 'X') || (bolge[1] == 'O' && bolge[5] == 'O' && bolge[9] == 'O')){
        kimbitirdi(5);
        return true;
    }

    if((bolge[3] == 'X' && bolge[5] == 'X' && bolge[7] == 'X') || (bolge[3] == 'O' && bolge[5] == 'O' && bolge[7] == 'O')){
        kimbitirdi(5);
        return true;
    }
/*
			1 2 3          
			4 5 6           Bu alanlarda 159 veya 357  alanlar�n�n �apraz olarak X ya da 0 olmas�n� kontrol eden if d�ng�s� yukar�da yaz�l�d�r.
			7 8 9 
			*/ 
    return false;

}

void zorluksor(){  // Kullan�c�ya zorluk sorusu sorman�n metotu.

    cout << endl << "0 - Kolay \n1 - Orta \n2 - Zor" << endl << "Zorluk Seviyesini Seciniz :" ; // 0 ise kolay, 1 ise orta 2 ise zor.

    char zorluksecimi = '3';

    cin >> zorluksecimi;

    switch(zorluksecimi){
        case '0':
            zorluk = 0;
            break;
        case '1':
            zorluk = 1;  // 1,2 veya 3 girmek zorundas�n. Ba�ka say� ve rakamda Hatal� Giri� Uyar�s� verir.
            break;
        case '2':
            zorluk = 2;
            break;
        default:
            cout << "Hatali Giris !" << endl;  // Hatal� giri� uyar�s�. Verilen kriterlere uymad���ndan dolay� hata verdiriyoruz. 1-2-3 de�eri istiyoruz.
            zorluksor();
            break;
    }


}

int main() {

    int tur = 1;

    srand(time(NULL));  // Oyuna ba�lad���m�z andan bitirdi�imiz s�reye kadar zaman sayac�m�z var. Oyunu a�ar a�maz saya� ba�l�yor.

   

    cout << endl << "Yapay Zeka X-O-X Oyunu " << endl; // Oyun ba�lad�. �lk iletimiz oyunun ad� oluyor.

    zorluksor();

    // Oyun :

    cout << endl << "Oyun Basladi Basarilar..!" << endl; // Oyun ba�lad� mesaj�m�z.

    do{ 

        zeminciz(); // 123 456 789 say�lar�n� ekrana yazd�ran metot.

        oyna(tur%2 != 0 ? 'X' : 'O');

        tur++;

        if(bittimi()){
            break; // Oyn bitti mi ?
        }else{};

    }while(tur <= 9); // 9 tane hamle say�s�n� while d�ng�s� ile kontrol ediyor.

    zeminciz();// 123 456 789 say�lar�n� ekrana yazd�ran metot.

    if(!bitirenvar) // E�er BitirenVar Metodundan oyunBitti sonucu gelmediyse oyun berabere bitti.
        cout << "Guzel oyundu\n! Berabere !\n";  // Oyunda yeterli hamle say�n kalmad�ysa, Yani yeni�emediysek Oyun Bitti Berabere uyar�s� ver.
    cout << "Oyun Bitti ! " ;

}
