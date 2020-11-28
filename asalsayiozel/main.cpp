#include <iostream>
#include <string>
#include <chrono>
int asalsayicheck(int sayi){
    int arasayi,rakam;
    int toplam=0;
    arasayi=sayi;
    do{
        rakam=arasayi%10;
        arasayi=arasayi/10;
        toplam=toplam+rakam;
    }while(arasayi!=0);
    toplam=toplam+arasayi;
    if(sayi<=1){
        return 0;
    }else if(sayi!=2&&sayi%2==0){
        return 0;
    }else if(sayi!=5&&sayi%10==5){
        return 0;
    }else if(sayi!=3&&toplam%3==0){
        return 0;
    }else if(sayi%7==0){
        return 0;
    }
    for(int i=2;i<=(sayi/2);i++){
        if(sayi%i==0){
            return 0;
            break;
        }
    }return 1;
}
int adetliasalsayi(int cinadet){
    auto start = std::chrono::high_resolution_clock::now();
    short asalsayiadet;
    int adet=0;
    int sayi=1;
    do{
        sayi++;
        asalsayiadet=asalsayicheck(sayi);
        if(asalsayiadet==1){
            std::cout<<sayi<<" bir asal sayidir."<<std::endl;
            adet++;
        }
    }while(adet<cinadet);
    std::cout<<adet<<" adet asal sayi."<<std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    std::cout<<duration.count()<<" mikrosaniye surdu."<<std::endl;
    return 0;
}
int sayiyakadarasal(int sayiyakadar){
    auto start = std::chrono::high_resolution_clock::now();
    short asalsayikadar;
    int kadaradet=0;
    int sayikadar=1;
    do{
        sayikadar++;
        asalsayikadar=asalsayicheck(sayikadar);
        if(asalsayikadar==1){
            std::cout<<sayikadar<<" bir asal sayidir."<<std::endl;
            kadaradet++;
        }
    }while(sayikadar<sayiyakadar);
    std::cout<<kadaradet<<" adet asal sayi."<<std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    std::cout<<duration.count()<<" mikrosaniye surdu."<<std::endl;
    return 0;
}
int main()
{
    int mainadet;
    int mainkadar;
    std::string cevap;
    std::cout<<"Bir sayiya kadar olan asal sayilari mi, yoksa gireceginiz deger adedinde asal sayiyi mi gormek istersiniz? Adetli icin \"adet\", sayiya kadar olan icin ise \"kadar\" yaziniz."<<std::endl;
    std::cin>>cevap;
    if(cevap=="adet"){
        std::cout<<"Kac adet asal sayi yazilsin?"<<std::endl;
        std::cin>>mainadet;
        adetliasalsayi(mainadet);
        return 0;
    }else if(cevap=="kadar"){
        std::cout<<"Hangi sayiya kadar olan asal sayilar yazilsin?"<<std::endl;
        std::cin>>mainkadar;
        sayiyakadarasal(mainkadar);
        return 0;
    }else{
        std::cout<<"Lutfen gecerli bir cevap veriniz"<<std::endl;
        return 0;
    }
}
