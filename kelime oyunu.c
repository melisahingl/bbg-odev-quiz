#include <stdio.h>
int main(){
    char D[4] = {'a','e','r','s'} ;
    char kelimeler[][5] = {"sera","ser","as","es"};
    char girilen[20];
    int puan, i, j, k, toplam, toplampuan, uzunluk, cikis, kontrol, kontrol2, sayac, bilinen_uzunluk, d_uzunluk, b_i ;
    int dizi_uzunlugu = sizeof(kelimeler)/sizeof(kelimeler[0]);
    char bilinen[20][7]={"\0"};

    printf("Oyun basliyor!\nYandaki harfleri birer kez kullanarak bir kelime tahmin et: ");

    for(d_uzunluk = 0; (D[d_uzunluk] != '\0'); ++d_uzunluk);   // gömülü D dizisinin uzunluğunu öğren
    for(i = 0 ; i < d_uzunluk ; i++){ // D'deki harfleri bastir
        printf("%c ", D[i]);}

    cikis = 0;
    toplampuan = 0;
    k = 0;

    while(cikis == 0){
        uzunluk = 0;
        puan = 0;
        toplam = 0;
        printf("\nTahminini yaz ya da oyundan cikmak istiyorsan 0 yaz.\n"); 
        scanf("%s", &girilen); // girdiyi al

        if(girilen[0] == '0'){ // girdi 0 ise oyunu bitir
            printf("Oyun bitti. Puaniniz: %d", toplampuan);
            cikis = 1;}
        
        else{ // girdi bir kelime ise;
            
            for(uzunluk = 0; (girilen[uzunluk] !='\0'); ++uzunluk); // kelimenin uzunluğunu öğren

            if(uzunluk<2){  //uzunluk kontrolü yap, kısaysa uyarı ver
                printf("\nTahmin ettiginiz kelimenin uzunlugu en az 2 olmalidir.");}       

            else{
                for(i = 0; i < uzunluk; i++){ //hatalı harf olup olmadığını öğren
                    for(j = 0; j < d_uzunluk; j++){
                        if(girilen[i] == D[j]){
                            toplam=toplam+1;}}}
                
                if(toplam != uzunluk){  //hatalı harf varsa uyarı bastır ve harf sayısı kadar puan kaybet
                    puan = uzunluk * (-1);
                    printf("\nHatali harf girdiniz. Puaniniz: %d", puan);}
                
                else{ //hatalı harf yoksa kelime dizide var mı kontrol et
                    kontrol = 0;
                    j = 0;
                    while(j < dizi_uzunlugu && kontrol == 0){        //dizinin her elemanını dön
                        sayac = 0;
                        for(i = 0; i < uzunluk; i++){              // kelimenin her harfini dön
                            if(girilen[i] == kelimeler[j][i]){    // kelimelerin harfleri eşit mi diye bak
                                    sayac = sayac + 1;}}         // harfler eşitse güncelle
                        
                        if(sayac == uzunluk){
                            kontrol = 1;}

                        j = j + 1;}

                    if(kontrol == 1){             
                        j = 0;
                        kontrol2 = 0;
                        bilinen_uzunluk = sizeof(bilinen) / sizeof(bilinen[0]);    // kullanıcının bildiği kelimelerin sayısı
                        while(j < bilinen_uzunluk && kontrol2 == 0){              // kelime dizide önceden var mı kontrol et
                            for(b_i=0 ; bilinen[j][b_i] != '\0' ; b_i++);
                            sayac = 0;
                            for(i = 0; i < uzunluk; i++){                       
                                if(girilen[i] == bilinen[j][i]){               
                                    sayac = sayac + 1;}}

                            if(sayac == uzunluk && b_i == uzunluk ){
                                kontrol2 = 1;}

                            j = j + 1;}

                        if(kontrol2 == 1){                  //kelime varsa - puan
                            puan = -1 * uzunluk;
                            printf("\nOnceki tahmini girdiniz! Puaniniz: %d", puan);}

                        else{
                            puan = uzunluk;
                            printf("\nDogru bildiniz! Puaniniz: %d", puan);
                            for(i = 0; i < uzunluk; i++){ 
                                bilinen[k][i] = girilen[i];}                          // kelime yoksa bilinen kelimeleri diziye ekleyelim
                            k = k + 1;}}

                    if(kontrol == 0){                                               //kelimeler dizinde kelime yoksa hata bastır ve - puan
                        puan = uzunluk * -1;
                        printf("\nKelime yok! Puaniniz: %d", puan);}}}}
        toplampuan = toplampuan + puan;}                                         //döngüden çıkınca toplam puanı bastır
    return 0;
}
