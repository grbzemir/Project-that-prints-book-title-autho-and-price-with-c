#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


// fflush() fonksiyonu Çıkış akışları için, akışın arabelleğindeki yazılmamış veriyi ilgili çıkış aygıtına yazar.



struct kitap
{
    char ad[20];
    char yazar[20];
    int fiyat;
    char konu[20];
    int sayfa;
    char yayinevi[20];
};

int m=0;
int n=0;
int sayac=0;
int secim=0;
struct kitap kitaplar[100];

void sirala_konu();
void sirala_fiyat();
void bul_konu();
void bul_fiyat();

void main(void)
{
    void bilgi_al(void);
    void menu(void);

    system("cls");
    system("color 0a");
    bilgi_al();
    menu();
}

void bilgi_al(void)
{
    printf("Kac kitap gireceksiniz: \n");
    scanf("%d",&sayac);
    fflush(stdin);

    for(n=0;n<sayac;n++)
    {
       system("cls");

       printf("\n Bilgileri giriniz:");
       printf("\n ******************");

       printf("\n %i. Kitap Bilgileri",n+1);

       printf("\n Kitabin adi: ");
       gets(kitaplar[n].ad);
       fflush(stdin);
       
       printf("\n Kitabin yazarinin adi: ");
       gets(kitaplar[n].yazar);
       fflush(stdin);
       
       printf("\n Kitabin fiyatini giriniz: ");
       scanf("%d",&kitaplar[n].fiyat);
       fflush(stdin);

      printf("\n Kitabin konusunu giriniz:");
      gets(kitaplar[n].konu);
      fflush(stdin);

      printf("\n Kitabin sayfasini giriniz:");
      scanf("%d",&kitaplar[n].sayfa);
      fflush(stdin);

      printf("\n Kitabin yayin evini giriniz:");
      gets(kitaplar[n].yayinevi);
      fflush(stdin);

    }
}

void menu(void)
{
    do
    {

     printf("\n\n MENU");
     printf("\n ******");
     
     printf("\n 1.Konusuna gore sirala");
     printf("\n 2.Fiyata gore sirala");
     printf("\n 3.Konusuna gore bul");
     printf("\n 4.Fiyata gore bul");
     printf("\n 5.Cikis");

     printf("\n\n Seciminizi giriniz: ");
     scanf("%d",&secim);
     fflush(stdin);


     switch (secim)
     {
        case 1:
            sirala_konu();
            break;
        case 2:
            sirala_fiyat();
            break;
        case 3:
            bul_konu();
            break;
        case 4:
            bul_fiyat();
            break;
        case 5:
            exit(0);
            break;
     }

    }
    while(secim!=5);
     
   
}

void yazdirlistele(void)
{
    printf("\n no \t ad \t yazar \t fiyat \t konu \t sayfa \t yayinevi");
    printf("\n *********************************************************");

    for(n=0;n<sayac;n++)
    {
        printf("\n %d \t %s \t %s \t %d \t %s \t %d \t %s",n+1,kitaplar[n].ad,kitaplar[n].yazar,kitaplar[n].fiyat,kitaplar[n].konu,kitaplar[n].sayfa,kitaplar[n].yayinevi);
    }
}

void sirala_konu(void)
{
    char temp[20];

    for(m=0;m<sayac-1;m++)
    {
        for(n=m+1;n<sayac;n++)
        {
            if(strcmp(kitaplar[m].konu,kitaplar[n].konu)>0)
            {
                strcpy(temp,kitaplar[m].konu);
                strcpy(kitaplar[m].konu,kitaplar[n].konu);
                strcpy(kitaplar[n].konu,temp);
            }
        }
    }
    yazdirlistele();
}

void sirala_fiyat(void)
{
    int temp;

    for(m=0;m<sayac-1;m++)
    {
        for(n=m+1;n<sayac;n++)
        {
            if(kitaplar[m].fiyat>kitaplar[n].fiyat)
            {
                temp=kitaplar[m].fiyat;
                kitaplar[m].fiyat=kitaplar[n].fiyat;
                kitaplar[n].fiyat=temp;
            }
        }
    }
    yazdirlistele();
}

void bul_konu(void)
{
    char konus[20];
    char ses = 'e';

    system("cls");
    printf("\n Aramak istediginiz konuyu giriniz: ");
    gets(konus);
    fflush(stdin);

    for(n=0;n<sayac;n++)
    {
        if (strcmp(konus,kitaplar[n].konu)==0)
        {
            printf("\n no \t ad \t yazar \t fiyat \t konu \t sayfa \t yayinevi");
            printf("\n *********************************************************");
            printf("\n %d \t %s \t %s \t %d \t %s \t %d \t %s",n+1,kitaplar[n].ad,kitaplar[n].yazar,kitaplar[n].fiyat,kitaplar[n].konu,kitaplar[n].sayfa,kitaplar[n].yayinevi);
        
         ses = 'h';
         break;

        }
            
        }
    if(ses == 'e')
    
        printf("\n Aradiginiz konu bulunamadi");
    }

void bul_fiyat(void)
{
    int dusukfiyat=0;
    int yukseklfiyat=0;

    system("cls");

    printf("minimum fiyat giriniz: ");
    scanf("%d",&dusukfiyat);
    fflush(stdin);

    printf("maksimum fiyat giriniz: ");
    scanf("%d",&yukseklfiyat);
    fflush(stdin);


    for(n=0;n<sayac;n++)
    {
        if (kitaplar[n].fiyat>=dusukfiyat && kitaplar[n].fiyat<=yukseklfiyat)
        {
            printf("\n no \t ad \t yazar \t fiyat \t konu \t sayfa \t yayinevi");
            printf("\n *********************************************************");
            printf("\n %d \t %s \t %s \t %d \t %s \t %d \t %s",n+1,kitaplar[n].ad,kitaplar[n].yazar,kitaplar[n].fiyat,kitaplar[n].konu,kitaplar[n].sayfa,kitaplar[n].yayinevi);
        
         break;

        }
  
        }
    }

