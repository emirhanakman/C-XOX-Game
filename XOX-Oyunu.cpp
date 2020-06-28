#include <iostream> // Kullanýcýdan deðer almamýzý saðlayan kütüphane.
#include<time.h> // zaman sayaç kütüphanemiz.
#include<stdlib.h> // RAndom için kullandýðýmýz kütüphane.

using namespace std;

char bolge[10] = {'0','1','2','3','4','5','6','7','8','9'};  // 9 tane XOX bölgesi oluþturuyoruz.

// Yapay zeka oynama sayýsý :
int yzsira = 1;

// Zorluk -> Kolay : 0 || Orta : 1 || Zor : 2
int zorluk = 1; // zorluk seviyesi.

// Oyunu Bitiren olup olmadýðýný kontrol eder :

bool bitirenvar = false;  // Oyun basladiginde bitireni degerini sifirla. ( Oyun basladiginda bitiren olamaz. )

void zeminciz(){
 // XOX oyunun tabaný olan 9 bölge oluþturuyoruz.
    cout << endl << bolge[1] << " | " << bolge[2] << " | " << bolge[3] << endl  //  Bölge 1 | Bölge 2 | Bölge 3
                 << "- | - | -" << endl
                 << bolge[4] << " | " << bolge[5] << " | " << bolge[6] << endl  // Bölge 4 | Bölge 5 | Bölge 6
                 << "- | - | -" << endl
                 << bolge[7] << " | " << bolge[8] << " | " << bolge[9] << endl << endl ; // Bölge 7 / Bölge 8 / Bölge 9

}

bool kontrol(int yer){
// Yeri kontrol et.  Yer X'e ve 0'a eþit deðilse oyuna devam et. 
    return ((bolge[yer] != 'X' && bolge[yer] != 'O' ? true : false));

}

int rndsayi(int sayi = 9){//Random sayý oluþtur 9 deðerini ver.

    return (rand() % sayi + 1);

}

int rndkontrol(int rnd, int sayi = 9){// XOX alanlarýnda 1 ile 9 arasýnda (9 Bölgemiz var XOX'de) rastgele sayý oluþturuyor.

    if(kontrol(rnd)){

        return rnd;// 

    }else{ 

        return (rndkontrol(rndsayi(sayi)));//
// Oluþturulan Rastgele sayý deðeri daha önce  oluþturulmuþ mu diye kontrol ediyor.
    }

}

int caprazolasilik(int bolge1, int bolge2, int yer){ // Çapraz olarak XXX veya OOO gelme olasýlýðýný kontrol ediyor.

    if(((bolge[bolge1] == 'X' && bolge[bolge2] == 'X') || (bolge[bolge1] == 'O' && bolge[bolge2] == 'O')) && (bolge[yer] != 'X' && bolge[yer] != 'O'))
        return yer;
 // Bölge1 = X   ve  Bölge2 = X veya Bölge1 = 0 ve Bölge2 = 0      ve   Bölge eþit deðilse X'e   ve Bölge eþit deðilse 0'a.
     // Uygun yer bulunamadýysa :
    return 0; // deðeri döndür.
}

int zeka(){ 
// Zeka bölümü. Bu bölümde yapay zekanýn, kullanýcý hamle yaptýktan sonra hangi alanlarý seçeceðini, dolu-boþ alanlarý ayýrt edebileceðini ve ona göre hamle yapacaðýnýn kodlarý yazýlýdýr.

    // Olasýlýklar:

    // Dikey Olasýlýklar : -------------------------------------------------------------------------------------------------------------------

    // 1,2,3 ve 4,5,6 ayný cins doluysa 7,8,9'a koy.
    for(int a = 1,b = 4, c = 7; a <= 3;a++,b++,c++){
        if(((bolge[a] == 'X' && bolge[b] == 'X') || (bolge[a] == 'O' && bolge[b] == 'O')) && (bolge[c] != 'X' && bolge[c] != 'O'))
            return c;
    }

    // 7,8,9 ve 4,5,6 ayný cins doluysa 1,2,3'a koy.
    for(int a = 7,b = 4, c = 1; a <= 9;a++,b++,c++){
        if(((bolge[a] == 'X' && bolge[b] == 'X') || (bolge[a] == 'O' && bolge[b] == 'O')) && (bolge[c] != 'X' && bolge[c] != 'O'))
            return c;
    }

    // 1,2,3 ve 7,8,9 ayný cins doluysa 4,5,6'a koy.
    for(int a = 1,b = 7, c = 4; a <= 3;a++,b++,c++){
        if(((bolge[a] == 'X' && bolge[b] == 'X') || (bolge[a] == 'O' && bolge[b] == 'O')) && (bolge[c] != 'X' && bolge[c] != 'O'))
            return c;
    }


    // Yatay Olasýlýklar : ----------------------------------------------------------------------------------------------------------------------------


    // 1,4,7 ve 2,4,8 ayný cins doluysa 3,6,9'a koy.

    for(int a = 1; a <= 7; a += 3){
        if(((bolge[a] == 'X' && bolge[a+1] == 'X') || (bolge[a] == 'O' && bolge[a+1] == 'O')) && (bolge[a+2] != 'X' && bolge[a+2] != 'O'))
            return (a+2);
    }

    // 2,5,8 ve 3,6,9 ayný cins doluysa 1,4,7'a koy.

    for(int a = 2; a <= 8; a += 3){
        if(((bolge[a] == 'X' && bolge[a+1] == 'X') || (bolge[a] == 'O' && bolge[a+1] == 'O')) && (bolge[a-1] != 'X' && bolge[a-1] != 'O'))
            return (a-1);
    }

    // 1,4,7 ve 3,6,9 ayný cins doluysa 2,5,8'a koy.

    for(int a = 1; a <= 7; a += 3){
        if(((bolge[a] == 'X' && bolge[a+2] == 'X') || (bolge[a] == 'O' && bolge[a+2] == 'O')) && (bolge[a+1] != 'X' && bolge[a+1] != 'O'))
            return (a+1);
    }


    // Çapraz Olasýlýklar : -------------------------------------------------------------------------------------------------------------------------

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


    // Eðer ZOR seviye seçiliyse ve bir olasýlýk yoksa köþeye oyna :
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
            cout << "Bir Hata Oluþtu : Eðer zor seçiliyse ve bir olasýlýk yoksa köþeye oyna." << endl;
            break;

    }

    // Hiçbir olasýlýk yoksa rastgele seç :
    return rndkontrol(rndsayi());;

}

void yapayzeka(){ // Yapay zekanýn oyun hamlesi bu metotun içerisinde:

    if(yzsira == 1){

        // Zor seçilmediyse ilk oyunda rastgele yer seç :
        if(zorluk != 2) {

            int rnd = rndsayi();

            if (kontrol(rnd)) {
                bolge[rnd] = 'O';
            } else {
                yapayzeka();
            }

        }else {

            if((bolge[5] != 'X' && bolge[5] != 'O')){
                // Orta Boþsa :
                bolge[5] = 'O';
            }else{
                // Orta Boþ Deðilse :
                bolge[zeka()] = 'O';}

        }
    }else{

        bolge[zeka()] = 'O';

    }

    // Eðer kolay seçilmiþse hep raskele oynar :
    if(zorluk != 0)
    yzsira++;

}

void oyna(char oyuncu){

    if(oyuncu == 'X'){// Kullanýcý .

        int yer;

        cout << "Sira X'de : X'i Yerlestireceginiz Alan Numarasini Yaziniz."; // Kullanýcýnýn sýrasý.

            cin >> yer;  

        if(kontrol(yer)){// Kullanýcý hamle yapacaðý alaný seçiyor. Eðer  o alan boþ ise oraya X deðerini veriyor.

            bolge[yer] = 'X';

        }else{   // O alana daha önce deðer verilmiþse Hatalý Giriþ uyarýsý alýyor.

            cout << "Hatalý Giriþ !" << endl;  
            oyna('X');

        }

    }else{

        cout << "Sira O'da ..." << endl ;  

        yapayzeka();  // 0'larý Yapay Zeka Kontrol Ediyor.Yapay Zeka metodunda iþlem gerçekleþiyor.

    }

}

void kimbitirdi(int yer){
 // Oyunu kimin kazandýðýnýn tespiti ; 
    if(bolge[yer] == 'X') {  // X Kullanici idi. Kullanici 3 yanyana,dikey veya capraz koymayi basardiysa kullanici kazandi.
        cout << "Kazanan : X\n! Tebrikler Siz Kazandiniz.. !" << endl; 
    } else{  // Degilse Gulsen'in yapay zekasi kazandi :)))
        cout << "Kazanan : O\n! Gulsen'in Yapay Zekasi Kazandi . !" << endl;  
    }

    bitirenvar = true; // BitirenVar metodunu aktiflestir. 

}

bool bittimi(){//Bitti mi kontrolunu saðlýyor.

    // Yatay Kontrol
    for(int i = 1; i <= 7; i += 3){
        if((bolge[i] == 'X' && bolge[i+1] == 'X' && bolge[i+2] == 'X') || (bolge[i] == 'O' && bolge[i+1] == 'O' && bolge[i+2] == 'O')) {
            kimbitirdi(i+1);
            return true;  // Yatay olarak XXX ya da 000 yan yana geldiyse. 
            /*
			1 2 3          
			4 5 6           Bu alanlarda 123 veya 456 veya 789 alanlarýnýn yanyana X ya da 0 olmasýný kontrol eden if döngüsü yukarýda yazýlýdýr.
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
			4 5 6           Bu alanlarda 147 veya 258 veya 369 alanlarýnýn dikey olarak X ya da 0 olmasýný kontrol eden if döngüsü yukarýda yazýlýdýr.
			7 8 9 
			*/ 
    }

    // Çapraz Kontrol :
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
			4 5 6           Bu alanlarda 159 veya 357  alanlarýnýn çapraz olarak X ya da 0 olmasýný kontrol eden if döngüsü yukarýda yazýlýdýr.
			7 8 9 
			*/ 
    return false;

}

void zorluksor(){  // Kullanýcýya zorluk sorusu sormanýn metotu.

    cout << endl << "0 - Kolay \n1 - Orta \n2 - Zor" << endl << "Zorluk Seviyesini Seciniz :" ; // 0 ise kolay, 1 ise orta 2 ise zor.

    char zorluksecimi = '3';

    cin >> zorluksecimi;

    switch(zorluksecimi){
        case '0':
            zorluk = 0;
            break;
        case '1':
            zorluk = 1;  // 1,2 veya 3 girmek zorundasýn. Baþka sayý ve rakamda Hatalý Giriþ Uyarýsý verir.
            break;
        case '2':
            zorluk = 2;
            break;
        default:
            cout << "Hatali Giris !" << endl;  // Hatalý giriþ uyarýsý. Verilen kriterlere uymadýðýndan dolayý hata verdiriyoruz. 1-2-3 deðeri istiyoruz.
            zorluksor();
            break;
    }


}

int main() {

    int tur = 1;

    srand(time(NULL));  // Oyuna baþladýðýmýz andan bitirdiðimiz süreye kadar zaman sayacýmýz var. Oyunu açar açmaz sayaç baþlýyor.

   

    cout << endl << "Yapay Zeka X-O-X Oyunu " << endl; // Oyun baþladý. Ýlk iletimiz oyunun adý oluyor.

    zorluksor();

    // Oyun :

    cout << endl << "Oyun Basladi Basarilar..!" << endl; // Oyun baþladý mesajýmýz.

    do{ 

        zeminciz(); // 123 456 789 sayýlarýný ekrana yazdýran metot.

        oyna(tur%2 != 0 ? 'X' : 'O');

        tur++;

        if(bittimi()){
            break; // Oyn bitti mi ?
        }else{};

    }while(tur <= 9); // 9 tane hamle sayýsýný while döngüsü ile kontrol ediyor.

    zeminciz();// 123 456 789 sayýlarýný ekrana yazdýran metot.

    if(!bitirenvar) // Eðer BitirenVar Metodundan oyunBitti sonucu gelmediyse oyun berabere bitti.
        cout << "Guzel oyundu\n! Berabere !\n";  // Oyunda yeterli hamle sayýn kalmadýysa, Yani yeniþemediysek Oyun Bitti Berabere uyarýsý ver.
    cout << "Oyun Bitti ! " ;

}
