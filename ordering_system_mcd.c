
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ppn 0.10

// struct untuk menyimpan
// detail user(Signup details)

char fileName[]="akun.txt";

struct details {
	char uname[100];
	char password[100];
	char email[100];
};

struct details s[100];

void signup(), account_check(), login(), ending();
int mainmenu(), validate(), validasi();

int flag = 1, i, j = 0, count = 0, caps = 0;
int small = 0, special = 0, numbers = 0;
int success = 0, x, option;
char temp_name[100], temp_password1[100],temp_password2 [100], temp_email[100], temp_mobile[100];
int duplikat, check_mail, check_pass;
char read_name[100], read_email[100], read_pass[100];

int main()
{
	while (1) {
      system("color 0b");
      system("pause");
      system("cls");
      printf("\t\t\t\t+====================================================+\n");
      printf("\t\t\t\t                    WELCOME TO MCDONALDS    \n");
      printf("\t\t\t\t+====================================================+\n");
      printf("\t\t\t\t                    SILAHKAN LOGIN DAHULU             \n");
      printf("\t\t\t\t                        1. Signup                     \n");
      printf("\t\t\t\t                        2. Login                      \n");
      printf("\t\t\t\t=====================================================+\n");
      printf("\t\t\t\t                        0. Keluar                     \n");
      printf("\t\t\t\t+====================================================+\n");
      printf("\t\t\t\tmasukkan pilihan anda:");
      scanf("%d", &option);
		switch (option) {
		case 1: {
			signup();
			break;
		}
		case 2: {
			login();
			break;
		}
		case 0: {
			ending();
			exit(0);
			return 0;
		}
		default: {
			printf("\n\t\t\t\tmasukkan pilihan dengan benar!\n");
			break;
		}
		}
	}
}

// fungsi untuk membuat user baru
void signup()
{
   system("color 0b");
   system("cls");
   printf("\t\t\t\t+====================================================+\n");
   printf("\t\t\t\t                 silahkan masukkan data anda           \n");
   printf("\t\t\t\t+=====================================================+\n");

	printf("\t\t\t\tName : ");
	scanf("%s", temp_name);

	printf("\t\t\t\tEmail : ");
	scanf("%s", temp_email);
         printf("\n\n\n\t\t\t\t*Please Enter the strong password\n");
         printf("\t\t\t\tyour password must contain ");
         printf("atleast one uppercase,\n");
         printf("\t\t\t\tLowercase, Number and ");
         printf("special character\n\n");
   printf("\t\t\t\tEnter Password : ");
	scanf("%s", temp_password1);
	printf("\t\t\t\tConfirm Password :");
	scanf("%s", temp_password2);
   printf("\n\n\n\t\t\t\t*hanya Masukkan 12 digit angka no hp\n");

   printf("\n\t\t\t\tNo Telepon : ");
	scanf("%s", temp_mobile);


	// memanggil fungsi validasi
	x = validate();
	if (x == 1){
		account_check();
      system("pause");
		login();
	}
   getchar();
}

// fungsi untuk validasi user dan
// dan proses pada signup
int validate()
{
   system("color 0b");
   	// validasi inputan untuk variabel nama
	for (i = 0; temp_name[i] != '\0'; i++) {
		if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z')
			|| (temp_name[i] >= 'A'
				&& temp_name[i] <= 'Z'))) {
			printf("\n\t\t\t\t*masukkan nama anda dengan benar!\n");
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		count = 0;

		// validasi inputan untuk variabel email
		for (i = 0;temp_email[i] != '\0'; i++) {
			if (temp_email[i] == '@'|| temp_email[i] == '.')
				count++;
		}
		if (count >= 2&& strlen(temp_email) >= 5) {
			// validasi inputan pasword dan akan
			// akan di cek kecocokannya dengan
			// konfirmasi password 
			if (!strcmp(temp_password1,
						temp_password2)) {
				if (strlen(temp_password1) >= 8
					&& strlen(temp_password1) <= 12) {
					caps = 0;
					small = 0;
					numbers = 0;
					special = 0;
					for (i = 0; temp_password1[i] != '\0';
						i++) {
						if (temp_password1[i] >= 'A'
							&& temp_password1[i] <= 'Z')
							caps++;
						else if (temp_password1[i] >= 'a'
								&& temp_password1[i]
										<= 'z')
							small++;
						else if (temp_password1[i] >= '0'
								&& temp_password1[i]
										<= '9')
							numbers++;
						else if (temp_password1[i] == '@'
								|| temp_password1[i] == '&'
								|| temp_password1[i] == '#'
								|| temp_password1[i]== '*'
                                || temp_password1[i]
										== '_') 
                                
							special++;
					}
					if (caps >= 1 && small >= 1
						&& numbers >= 1 && special >= 1) {
							// validasi inputan untuk variabel no.telepon
							if (strlen(temp_mobile) == 12) {

								for (i = 0; i < 12; i++) {
									if (temp_mobile[i]
											>= '0'
										&& temp_mobile[i]
											<= '9') {
										success = 1;
									}
									else {
										printf("\n\n\t\t\t\tMasukkan no.telepon anda dengan benar!\n\n");
										return 0;
										break;
									}
								}

								//ketika sukses akan assign dengan value 1, satukali setiap inputan benar 
								if (success == 1)
									return 1;
							}
							else {
								printf("\n\n\t\t\t\tMasukkan 12 digit angka no hp\n");
								return 0;
							}
						}
						
					else {
						printf("\n\t\t\t\tPlease Enter the");
						printf("strong password, Your ");
						printf("password must contain ");
						printf("atleast one uppercase, ");
						printf("Lowercase, Number and ");
						printf("special character\n\n");
						return 0;
					}

				}
            
				else {
					printf("\n\t\t\t\tPanjang password setidaknya harus 8 hingga 12 karakter\n\n");
					return 0;
				}
				}
			else {
				printf("\n\t\t\t\tPassword tidak cocok\n\n");
				return 0;
			}
			}
         else {
            printf("\n\t\t\t\tMasukkan alamat E-mail anda dengan benar\n\n");   
            return 0;
         }
        
		}
	}

// fungsi untuk mengecek apakah akun sudah terdaftar atau tidak
void account_check()
{
   system("color 0b");
   FILE *regis;

	regis = fopen (fileName, "r");
   duplikat = 0;
   while(!feof(regis)){
      fscanf(regis,"%[^#]#%[^#]#%[^\n]\n", &read_name, &read_email, &read_pass);
      check_mail = strcmp(temp_email, read_email);
      if (check_mail==0) {
         duplikat+=1;
         break;
      } else {
         duplikat+=2;
      }
   }
   fclose(regis);

   regis=fopen("akun.txt","a");
   if(duplikat%2==0){
      fprintf(regis, "%s#%s#%s\n", temp_name, temp_email, temp_password2);
      puts("\n\t\t\t\tAkun Anda berhasil terdaftar!");
   }else{
      printf ("\n\t\t\t\tEmail yang Anda gunakan sudah terdaftar!");
   }
   printf ("\n\t\t\t\tSilahkan melakukan login \n\n\n");
   fclose(regis);
}

// Fungsi untuk melakukan login 
void login()
{
   system("color 0b");
   FILE *record;
   record = fopen(fileName, "r");

	if (record == NULL){
		printf ("Error, tidak terdapat file untuk menyimpan akun\n");
		printf ("Silahkan daftarkan akun Anda terlebih dahulu! (tekan enter)\n");
		getchar();
		system("cls");
		mainmenu();
	}
   system("cls");
	printf("\t\t\t\t+====================================================+\n");
   printf("\t\t\t\t                silahkan login ke akun anda           \n");
   printf("\t\t\t\t+====================================================+\n");

	printf("\t\t\t\tEnter Your Email: ");
	scanf("%s", temp_email);
	printf("\t\t\t\tEnter Your Password: ");
	scanf("%s", temp_password2);

   record = fopen ("akun.txt", "r");
   duplikat = 0;
   while(!feof(record)){
      fscanf(record,"%[^#]#%[^#]#%[^\n]\n", &read_name, &read_email, &read_pass);
      check_mail = strcmp(temp_email, read_email);
      check_pass = strcmp(temp_password2, read_pass);
      if (check_mail==0 && check_pass==0) {
         duplikat+=1;
         break;
      } else {
         duplikat+=2;
      }
   }
   fclose(record);

   if(duplikat%2==0){
      printf("\n\n\t\t\t\tEmail atau Password tidak valid! ");
      printf("\n\t\t\t\tPastikan Email dan Password sudah cocok dan sudah terdaftar!!\n\n");
      system("pause");
      main();
   }else{
      printf("\n\t\t\t\tWelcome %s, ", read_name);
      printf("Your are successfully ");
      printf("logged in\n\n ");
      system("pause");
      mainmenu();
   }
}


void ending(){
   system("cls");
   printf("\t\t\t\t+====================================================+\n");
   printf("\t\t\t\t                    TERIMA KASIH                      \n");
   printf("\t\t\t\t+====================================================+\n");
}


int validasi(int x){
    system("color 0b");
    double pil = 5;
    int hasil;
    int i = 0;
    do{ 
        pil = scanf("%d", &hasil);
        if (pil < 1){   
            getchar();
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t                    input salah !                     \n");
                printf("\t\t\t\t             masukkan pilihan ulang !                 \n");
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t\t\tpilih ==>                                           ");

        }
        
        else if (x == 1){
            if (hasil > 1 || hasil < 0){
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t                    input salah !                     \n");
                printf("\t\t\t\t             masukkan pilihan ulang!                  \n");
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t\t\tpilih ==>                                           ");
            }
            else {
                i = 1;
            }  
        }
        else if(x == 2){
            if (hasil < 1 || hasil > 2){
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t                    input salah !                     \n");
                printf("\t\t\t\t             masukkan pilihan ulang!                  \n");
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t\t\tpilih ==>                                           ");
                
            }
            else{
                i = 1;
            }
        }
        else if (x == 3) {
            if (hasil > 9 || hasil < 1){
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t                    input salah !                     \n");
                printf("\t\t\t\t             masukkan pilihan ulang!                  \n");
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t\t\tpilih ==>                                           ");
            }
            else{
                i = 1;
            }
        }
        else if(x == 4){
            if (hasil < 1 || hasil > 14){
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t                    input salah !                     \n");
                printf("\t\t\t\t             masukkan pilihan ulang!                  \n");
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t\t\tpilih ==>                                           ");
            }
            else{
                i = 1;
            }
        }

         else if(x == 5){
            if (hasil < 1 || hasil > 19){
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t                    input salah !                     \n");
                printf("\t\t\t\t             masukkan pilihan ulang!                  \n");
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t\t\tpilih ==>                                           ");
            }
            else{
                i = 1;
            }
        }
        else if(x == 6){
            if (hasil < 1 || hasil > 11){
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t                    input salah !                     \n");
                printf("\t\t\t\t             masukkan pilihan ulang!                  \n");
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t\t\tpilih ==>");
            }
            else{
                i = 1;
            }
        }
         else if(x == 7){
            if (hasil < 1 || hasil > 5){
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t                    input salah !                     \n");
                printf("\t\t\t\t             masukkan pilihan ulang!                  \n");
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t\t\tpilih ==>");
            }
            else{
                i = 1;
            }
        }
         else if(x == 8){
            if (hasil < 1 || hasil > 23){
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t                    input salah !                     \n");
                printf("\t\t\t\t             masukkan pilihan ulang!                  \n");
                printf("\t\t\t\t+====================================================+\n");
                printf("\t\t\t\t\t\tpilih ==>");
            }
            else{
                i = 1;
            }
        }
        else{
            i = 1;
        } 
    } while (i != 1);

    return hasil;
}

int mainmenu(){
system("cls");
system("color 0b");
int  hargabreakfast[11]    ={13000, 20000, 22500, 25500, 26500, 33000, 28000, 21364, 7727, 16500, 10909}, i=0;
int  hargadagingsapi[9]    ={30000, 32500, 22500, 31000, 35000, 25000, 24000, 33000, 21000}, j=0;
int  hargaayam[19]         ={38000, 32000, 44000, 46000, 154000, 199000, 42000, 38000, 32000, 46500, 44000, 38000, 106000, 155000, 25000, 14500, 26000, 10000, 13500}, k=0;
int  hargaikan[5]          ={25000, 28000, 32000, 36000, 27000}, l=0;
int  hargaminuman[19]      ={13000, 20000, 23000, 24000, 19500, 23500, 20000, 21000, 8000, 13000, 8000, 8000, 22000, 11000, 12000, 12000, 15000, 17500, 9500}, m=0;
int  hargamakananpenutup[11] ={13000, 14000, 14000, 16500, 18500, 12500, 12500, 11000, 11000, 11000, 22000}, n=0;
int  hargahappymeal[5]     ={38000, 35500, 39500, 22500,25500}, o=0;
int  hargafamily[6]        ={102000, 102000, 102000, 102000, 87000, 87000}, p=0;
int  hargaMcCafe[23]       ={16500, 15000, 16500, 15000, 21000, 15500, 16500, 16500, 18000, 17000, 17000, 17500, 19500, 17000, 19000, 14000, 13500, 13500, 14000, 14000, 14000, 16000, 20000}, q=0;
int  pilih, payment, menu,makanan,minuman,hpenutup, jumlah,jumlah2,jumlah3, total, bayar, kurang, bonus, pajak, kembali,saldo, ulang;
char meja,layanan[100],food3[100],food[100],food2[100];

awal :
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t                 Welcome to MCDonalds                 \n");
printf("\t\t\t\t               Jl. Kampus Unud JImbaran               \n");
printf("\n");
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t                   Menu McDonald's                    \n");
printf("\t\t\t\t+====================================================+\n");
printf("\n");
printf("\t\t\t\tpilih menu yang anda inginkan\n\n");
printf("\t\t\t\t1. makanan\n");
printf("\t\t\t\t2. daging Sapi\n");
printf("\t\t\t\t3. Ayam\n");
printf("\t\t\t\t4. ikan\n");
printf("\t\t\t\t5. Minuman\n");
printf("\t\t\t\t6. makanan penutup\n");
printf("\t\t\t\t7. Happy Meal \n");
printf("\t\t\t\t8. Packet family\n");
printf("\t\t\t\t9. McCafe\n");
printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(3);


switch (menu) {
case 1:
system("cls");
breakfast:
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t   Menu Breakfast  \t\t\t harga                         \n");
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t1. Egg and Cheese Muffin\t\tRp.13000\n");
printf("\t\t\t\t2. Chicken Muffin   \t\t\tRp.20000\n");
printf("\t\t\t\t3. Sausage McMuffin\t\t\tRp.225000 \n");
printf("\t\t\t\t4. Egg mcMuffin   \t\t\tRp.225000 \n");
printf("\t\t\t\t5. Chicken Muffin with Egg\t\tRp.25500\n");
printf("\t\t\t\t6. Sausage McMuffin with Egg\t\tRp.26500\n");
printf("\t\t\t\t7. Sausage Wrap   \t\t\tRp.20000\n");
printf("\t\t\t\t8. Big makanan  \t\t\tRp.33000\n");
printf("\t\t\t\t9. makanan Wrap \t\t\tRp.22000\n");
printf("\t\t\t\t10. Hotcakes 3 pcs\t\t\tRp.22500\n");
printf("\t\t\t\t11. Hotcakes 2 pcs\t\t\tRp.21364\n");
printf("\t\t\t\t12. Hashbrown     \t\t\tRp.7727\n");
printf("\t\t\t\t13. Nasi Uduk Mcd \t\t\tRp.16500 \n");
printf("\t\t\t\t14. Bubur ayam McD\t\t\tRp.10909\n");
printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(4);


if (menu==1) {
   strcpy(food, "Egg and Cheese Muffin");
   i = 0;
}
else if(menu==2) {
   strcpy(food, "Chicken Muffin");
   i = 1;
}
else if (menu==3) {
   strcpy(food, "Sausage McMuffin");
   i = 2;
}
else if  (menu==4) {
   strcpy(food, " Egg mcMuffin");
   i = 2;
}
else if  (menu==5) {
   strcpy(food, "Chicken Muffin with Egg");
   i = 3;
}
else if (menu==6) {
   strcpy(food, "Sausage McMuffin with Egg");
   i = 4;
}
else if(menu==7) {
   strcpy(food, "Sausage Wrap");
   i = 2;
}
else if (menu==8) {
   strcpy(food, "Big makanan");
   i = 5;
}
else if  (menu==9) {
   strcpy(food, "makanan Wrap ");
   i = 2;
}
else if  (menu==10) {
   strcpy(food, "Hotcakes 3 pcs");
   i = 2;
}
else if (menu==11) {
   strcpy(food, "Hotcakes 2 pcs"); 
    i = 7;
}
else if  (menu==12) {
   strcpy(food, "Hashbrown");
   i = 8;
}
else if  (menu==13) {
   strcpy(food, "Nasi Uduk Mcd"); 
   i = 9;
}
else if (menu==14) {
   strcpy(food, "Bubur ayam McD");
   i = 10;
}
else{
    ending();
}


printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah);

makanan = jumlah * hargabreakfast[i];
printf("\t\t\t\t%s * %d : %d\n\n",food,jumlah, makanan);
total = makanan;
printf("\t\t\t\tIngin pesan minuman?\n");
printf("\t\t\t\t1. Ya\n");
printf("\t\t\t\t2. Tidak\n");
printf("\t\t\t\tMasukan Pilihan : ");
ulang = validasi(2);

    if (ulang==1) {
        goto drink;
    }
    else if (ulang==2) {
        goto hitung;
    }

drink :
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t   Menu minuman \t\t harga                         \n");
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t1. Pinneple Punch Fizz\t\tRp.13000\n");
printf("\t\t\t\t2. Aplle Fizz\t\t\tRp.20000\n");
printf("\t\t\t\t3. McFreeze Bluberry\t\tRp.23000 \n");
printf("\t\t\t\t4. Mcfreeze fanta Grape\t\tRp.24000 \n");
printf("\t\t\t\t5. McFreeze Apple\t\tRp.19500\n");
printf("\t\t\t\t6.Creamy mcfreeze bluberry\tRp.23500\n");
printf("\t\t\t\t7. Creamy McFeeze fanta Grape\tRp.20000\n");
printf("\t\t\t\t8.Creamy McFreeze Apple\t\tRp.21000\n");
printf("\t\t\t\t9. Fruit Tea Lemon\t\tRp.8000\n");
printf("\t\t\t\t10. Coca Cola\t\t\tRp.13000\n");
printf("\t\t\t\t11. Sprite\t\t\tRp.8000\n");
printf("\t\t\t\t12. Fanta\t\t\tRp.8000\n");
printf("\t\t\t\t13.Coca Cola Mcfloat\t\tRp.22000\n");
printf("\t\t\t\t14. Fanta McFloat\t\tRp.11000\n");
printf("\t\t\t\t15. Hot Coffe\t\t\tRp.12000\n");
printf("\t\t\t\t16. Hot Tea\t\t\tRp.12000\n");
printf("\t\t\t\t17. Iced coffe \t\t\tRp.15000\n");
printf("\t\t\t\t18.iced Coffe Float\t\tRp.17500\n");
printf("\t\t\t\t19. air mineral\t\t\tRp.9500\n");

printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(5);

if (menu==1) {
   strcpy(food2, "Pinneple Punch Fizz");
   m = 0;
}
else if(menu==2) {
   strcpy(food2, "Aplle Fizz");
   m = 1;
}
else if (menu==3) {
   strcpy(food2, "McFreeze Bluberry");
   m = 2;
}
else if  (menu==4) {
   strcpy(food2, "  Mcfreeze fanta Grape ");
   m = 3;
}
else if  (menu==5) {
   strcpy(food2, "McFreeze Apple");
   m = 4;
}
else if (menu==6) {
   strcpy(food2, "Creamy mcfreeze bluberry");
   m = 5;
}
else if(menu==7) {
   strcpy(food2, " Creamy McFeeze fanta Grape");
   m = 6;
}
else if (menu==8) {
   strcpy(food2, " Creamy McFreeze Apple ");
   m = 7;
}
else if  (menu==9) {
   strcpy(food2, " Fruit Tea Lemon");
   m = 8;
}
else if(menu==10) {
   strcpy(food2,  "Coca Cola");
   m = 9;
}
else if (menu==11) {
   strcpy(food2, "Sprite");
   m = 10;
}
else if  (menu==12) {
   strcpy(food2, " Fanta");
   m = 11;
}
else if  (menu==13) {
   strcpy(food2, " Coca Cola Mcfloat");
   m = 12;
}
else if (menu==14) {
   strcpy(food2, "Fanta McFloat");
   m = 13;
}
else if(menu==15) {
   strcpy(food2, " Hot Coffe");
   m = 14;
}
else if (menu==16) {
   strcpy(food2, " hot tea");
   m = 15;
}
else if  (menu==17) {
   strcpy(food2, "Iced coffe ");
   m = 16;
}
else if (menu==18) {
   strcpy(food2, "iced coffe float");
   m = 17;
}
else if(menu==19) {
   strcpy(food2, "air mineral ");
   m = 18;
}
else{
    ending();
}

printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah2);

minuman = jumlah2 * hargaminuman[m];
printf("\t\t\t\t%s * %d : %d\n\n",food2,jumlah2,minuman);
printf("\t\t\t\tIngin pesan menu penutup?\n");
printf("\t\t\t\t1. Ya\n");
printf("\t\t\t\t2. Tidak\n");
printf("\t\t\t\tMasukan Pilihan : ");
ulang = validasi(2);

    if (ulang==1) {
        goto hidanganpenutup;
    }
    else if (ulang==2) {
        goto hitung2;
    }

hidanganpenutup:
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t   Menu penutup  \t\t\t harga                         \n");
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t1. Choco Marsmellow Pie\t\t\tRp.13000\n");
printf("\t\t\t\t2. Drak ChoconMcFlurry with oreo\tRp.14000\n");
printf("\t\t\t\t3. Drak ChoconMcFlurry with crunch\tRp.14000 \n");
printf("\t\t\t\t4. Vanlilla Black waffle Cone\t\tRp.16500 \n");
printf("\t\t\t\t5. Apple pie\t\t\t\tRp.18500\n");
printf("\t\t\t\t6. McFlurry feat Oreo\t\t\tRp.12500\n");
printf("\t\t\t\t7. Mcflurry choco\t\t\tRp.12500\n");
printf("\t\t\t\t8. Strawberry sundae\t\t\tRp.11000\n");
printf("\t\t\t\t9. Chocolate sundae\t\t\tRp.11000\n");
printf("\t\t\t\t10.Icecream Cone\t\t\tRp.11000\n");
printf("\t\t\t\t11.Choco Top\t\t\t\tRp.22000\n");

printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(6);

if (menu==1) {
   strcpy(food3, "Choco Marsmellow Pie");
   n = 0;
}
else if(menu==2) {
   strcpy(food3, "Drak ChoconMcFlurry with oreo");
   n = 1;
}
else if (menu==3) {
   strcpy(food3, "Drak ChoconMcFlurry with crunch");
   n = 2;
}
else if  (menu==4) {
   strcpy(food3, " Vanlilla Black waffle Cone");
   n = 3;
}
else if  (menu==5) {
   strcpy(food3, "Apple pie");
   n = 4;
}
else if (menu==6) {
   strcpy(food3, "McFlurry feat Oreo");
   n = 5;
}
else if(menu==7) {
   strcpy(food3, " Mcflurry choco");
   n = 6;
}
else if (menu==8) {
   strcpy(food3, " Strawberry sundae ");
   n = 7;
}
else if  (menu==9) {
   strcpy(food3, "Chocolate sundae");
   n = 8;
}
else if(menu==10) {
   strcpy(food3,  "Icecream Cone ");
   n = 9;
}
else if (menu==11) {
   strcpy(food3, "Choco Top");
   n = 10;
}

else{
    ending();
}

printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah3);
hpenutup = jumlah3 * hargamakananpenutup[n];
printf("\t\t\t\t%s * %d : %d\n\n",food3,jumlah3, hpenutup);
total = hpenutup;
goto hitung3;
break;
case 2:
system("cls");
dagingsapi :
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t   Menu Daging sapi  \t\t\t harga                         \n");
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t1. beef Prosprtity Burger\t\tRp.30000\n");
printf("\t\t\t\t2. Big mac\t\t\t\tRp.32500\n");
printf("\t\t\t\t3. Triple Cheese Burger\t\t\tRp.22500 \n");
printf("\t\t\t\t4. double Cheese burger  \t\tRp.31000 \n");
printf("\t\t\t\t5. Cheese Burger Deluxe\t\t\tRp.35000\n");
printf("\t\t\t\t6. cheese burger with Egg\t\tRp.25000\n");
printf("\t\t\t\t7. Cheese burger   \t\t\tRp.34000\n");
printf("\t\t\t\t8. Beef Burger deluxe  \t\t\tRp.33000\n");
printf("\t\t\t\t9. Beef Burger\t\t\t\tRp.21000\n");
printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(3);

if (menu==1) {
   strcpy(food, "beef Prosprtity Burger");
   j = 0;
}
else if(menu==2) {
   strcpy(food, "Big mac");
   j = 1;
}
else if (menu==3) {
   strcpy(food, "Triple Cheese Burger");
   j = 2;
}
else if  (menu==4) {
   strcpy(food, "double Cheese burger");
   j = 3;
}
else if  (menu==5) {
   strcpy(food, "Cheese Burger Deluxe");
   j = 4;
}
else if (menu==6) {
   strcpy(food, "cheese burger with Egg");
   j  = 5;
}
else if(menu==7) {
   strcpy(food, " Cheese burger");
   j = 6;
}
else if (menu==8) {
   strcpy(food, " Beef Burger deluxe ");
   j = 7;
}
else if  (menu==9) {
   strcpy(food, " Beef Burger");
   j = 8;
}
else{
    ending();
}
printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah);

makanan = jumlah * hargadagingsapi[j];
printf("\t\t\t\t%s * %d : %d\n\n",food,jumlah, makanan);
total = makanan;
printf("\t\t\t\tIngin pesan minuman?\n");
printf("\t\t\t\t1. Ya\n");
printf("\t\t\t\t2. Tidak\n");
printf("\t\t\t\tMasukan Pilihan : ");
ulang = validasi(2);

    if (ulang==1) {
        goto drink2;
    }
    else if (ulang==2) {
        goto hitung;
    }

drink2 :
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t   Menu minuman \t\t harga                         \n");
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t1. Pinneple Punch Fizz\t\tRp.13000\n");
printf("\t\t\t\t2. Aplle Fizz\t\t\tRp.20000\n");
printf("\t\t\t\t3. McFreeze Bluberry\t\tRp.23000 \n");
printf("\t\t\t\t4. Mcfreeze fanta Grape\t\tRp.24000 \n");
printf("\t\t\t\t5. McFreeze Apple\t\tRp.19500\n");
printf("\t\t\t\t6.Creamy mcfreeze bluberry\tRp.23500\n");
printf("\t\t\t\t7. Creamy McFeeze fanta Grape\tRp.20000\n");
printf("\t\t\t\t8.Creamy McFreeze Apple\t\tRp.21000\n");
printf("\t\t\t\t9. Fruit Tea Lemon\t\tRp.8000\n");
printf("\t\t\t\t10. Coca Cola\t\t\tRp.13000\n");
printf("\t\t\t\t11. Sprite\t\t\tRp.8000\n");
printf("\t\t\t\t12. Fanta\t\t\tRp.8000\n");
printf("\t\t\t\t13.Coca Cola Mcfloat\t\tRp.22000\n");
printf("\t\t\t\t14. Fanta McFloat\t\tRp.11000\n");
printf("\t\t\t\t15. Hot Coffe\t\t\tRp.12000\n");
printf("\t\t\t\t16. Hot Tea\t\t\tRp.12000\n");
printf("\t\t\t\t17. Iced coffe \t\t\tRp.15000\n");
printf("\t\t\t\t18.iced Coffe Float\t\tRp.17500\n");
printf("\t\t\t\t19. air mineral\t\t\tRp.9500\n");



printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(5);

if (menu==1) {
   strcpy(food2, "Pinneple Punch Fizz");
   m = 0;
}
else if(menu==2) {
   strcpy(food2, "Aplle Fizz");
   m = 1;
}
else if (menu==3) {
   strcpy(food2, "McFreeze Bluberry");
   m = 2;
}
else if  (menu==4) {
   strcpy(food2, "  Mcfreeze fanta Grape ");
   m = 3;
}
else if  (menu==5) {
   strcpy(food2, "McFreeze Apple");
   m = 4;
}
else if (menu==6) {
   strcpy(food2, "Creamy mcfreeze bluberry");
   m = 5;
}
else if(menu==7) {
   strcpy(food2, " Creamy McFeeze fanta Grape");
   m = 6;
}
else if (menu==8) {
   strcpy(food2, " Creamy McFreeze Apple ");
   m = 7;
}
else if  (menu==9) {
   strcpy(food2, " Fruit Tea Lemon");
   m = 8;
}
else if(menu==10) {
   strcpy(food2,  "Coca Cola");
   m = 9;
}
else if (menu==11) {
   strcpy(food2, "Sprite");
   m = 10;
}
else if  (menu==12) {
   strcpy(food2, " Fanta");
   m = 11;
}
else if  (menu==13) {
   strcpy(food2, " Coca Cola Mcfloat");
   m = 12;
}
else if (menu==14) {
   strcpy(food2, "Fanta McFloat");
   m = 13;
}
else if(menu==15) {
   strcpy(food2, " Hot Coffe");
   m = 14;
}
else if (menu==16) {
   strcpy(food2, " hot tea");
   m = 15;
}
else if  (menu==17) {
   strcpy(food2, "Iced coffe ");
   m = 16;
}
else if (menu==18) {
   strcpy(food2, "iced coffe float");
   m = 17;
}
else if(menu==19) {
   strcpy(food2, "air mineral ");
   m = 18;
}
else{
    ending();
}

printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah2);

minuman = jumlah2 * hargaminuman[m];
printf("\t\t\t\t%s * %d : %d\n\n",food2,jumlah2,minuman);
goto hitung2;
break;
case 3:
system("cls");
Ayam :
printf("\t\t\t\t+==========================================================+\n");
printf("\t\t\t\t   Menu Ayam  \t\t\t\t\t harga                              \n");
printf("\t\t\t\t+==========================================================+\n");
printf("\t\t\t\t1. PaNas Spesial Ayam McD Kimchi\t\tRp.38000\n");
printf("\t\t\t\t2. PaNas 1 Ayam McD Kimchi\t\t\tRp.32000\n");
printf("\t\t\t\t3. PaNas 2 Ayam McD Kimchi\t\t\tRp.44000 \n");
printf("\t\t\t\t4. PaNas 2 with french Fries Ayam McD Kimchi  \t\tRp.46000 \n");
printf("\t\t\t\t5. Pamer 5 Ayam McD Kimchi\t\t\tRp.154000\n");
printf("\t\t\t\t6. Pamer 7 Ayam McD Kimchi\t\t\tRp.199000\n");
printf("\t\t\t\t7. ayam Crispy McD   \t\t\t\tRp.42000\n");
printf("\t\t\t\t8. Ayam Spicy McD  \t\t\t\tRp.38000\n");
printf("\t\t\t\t9. PaNas 1\t\t\t\t\tRp.32000\n");
printf("\t\t\t\t10. PaNas 2 with Fries \t\t\t\tRp.46500\n");
printf("\t\t\t\t11. PaNas 2 with Rice\t\t\t\tRp.44000\n");
printf("\t\t\t\t12. PaNas Special\t\t\t\tRp.38000\n");
printf("\t\t\t\t13. PaMer 5\t\t\t\t\tRp.106000\n");
printf("\t\t\t\t14. PaMer 7\t\t\t\t\tRp.155000\n");
printf("\t\t\t\t15. Chicken Burger deluxe\t\t\tRp.25000\n");
printf("\t\t\t\t16. Chicken Burger\t\t\t\tRp.14500\n");
printf("\t\t\t\t17.  McNuggets \t\t\t\t\tRp.26000\n");
printf("\t\t\t\t18. Spicy Chicken Bites\t\t\t\tRp.10000\n");
printf("\t\t\t\t19. Chicken Fingers\t\t\t\tRp.13500\n");



printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(5);

if (menu==1) {
   strcpy(food, "PaNas Spesial Ayam McD Kimchi");
   k = 0;
}
else if(menu==2) {
   strcpy(food, "PaNas 1 Ayam McD Kimchic");
   k = 1;
}
else if (menu==3) {
   strcpy(food, "PaNas 2 Ayam McD Kimchi");
   k = 2;
}
else if  (menu==4) {
   strcpy(food, " PaNas 2 with french Fries Ayam McD Kimchi");
   k = 3;
}
else if  (menu==5) {
   strcpy(food, "Pamer 5 Ayam McD Kimchi");
   k = 4;
}
else if (menu==6) {
   strcpy(food, "Pamer 7 Ayam McD Kimchi");
   k = 5;
}
else if(menu==7) {
   strcpy(food, " ayam Crispy McD ");
   k = 6;
}
else if (menu==8) {
   strcpy(food, " Ayam Spicy McD ");
   k = 7;
}
else if  (menu==9) {
   strcpy(food, "  PaNas 1");
   k = 8;
}
else if(menu==10) {
   strcpy(food, "PaNas 2 with Fries");
   k = 9;
}
else if (menu==11) {
   strcpy(food, "PaNas 2 with Rice");
   k = 10;
}
else if  (menu==12) {
   strcpy(food, " PaNas Special");
   k = 11;
}
else if  (menu==13) {
   strcpy(food, "PaMer 5");
   k = 12;
}
else if (menu==14) {
   strcpy(food, "PaMer 7");
   k = 13;
}
else if(menu==15) {
   strcpy(food, "Chicken Burger deluxe ");
   k = 14;
}
else if (menu==16) {
   strcpy(food, "  McNuggets");
   k = 15;
}
else if  (menu==17) {
   strcpy(food, "Spicy Chicken Bites");
   k = 16;
}
else if (menu==18) {
   strcpy(food, "PaMer 7");
   k = 17;
}
else if(menu==19) {
   strcpy(food, "Chicken Fingers ");
   k = 18;
}
else{
    ending();
}
printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah);

makanan = jumlah * hargaayam[k];
printf("\t\t\t\t%s * %d : %d\n\n",food,jumlah, makanan);
total = makanan;
printf("\t\t\t\tIngin pesan minuman?\n");
printf("\t\t\t\t1. Ya\n");
printf("\t\t\t\t2. Tidak\n");
printf("\t\t\t\tMasukan Pilihan : ");
ulang = validasi(2);

    if (ulang==1) {
        goto drink3;
    }
    else if (ulang==2) {
        goto hitung;
    }

drink3 :
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t   Menu minuman \t\t harga                         \n");
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t1. Pinneple Punch Fizz\t\tRp.13000\n");
printf("\t\t\t\t2. Aplle Fizz\t\t\tRp.20000\n");
printf("\t\t\t\t3. McFreeze Bluberry\t\tRp.23000 \n");
printf("\t\t\t\t4. Mcfreeze fanta Grape\t\tRp.24000 \n");
printf("\t\t\t\t5. McFreeze Apple\t\tRp.19500\n");
printf("\t\t\t\t6.Creamy mcfreeze bluberry\tRp.23500\n");
printf("\t\t\t\t7. Creamy McFeeze fanta Grape\tRp.20000\n");
printf("\t\t\t\t8.Creamy McFreeze Apple\t\tRp.21000\n");
printf("\t\t\t\t9. Fruit Tea Lemon\t\tRp.8000\n");
printf("\t\t\t\t10. Coca Cola\t\t\tRp.13000\n");
printf("\t\t\t\t11. Sprite\t\t\tRp.8000\n");
printf("\t\t\t\t12. Fanta\t\t\tRp.8000\n");
printf("\t\t\t\t13.Coca Cola Mcfloat\t\tRp.22000\n");
printf("\t\t\t\t14. Fanta McFloat\t\tRp.11000\n");
printf("\t\t\t\t15. Hot Coffe\t\t\tRp.12000\n");
printf("\t\t\t\t16. Hot Tea\t\t\tRp.12000\n");
printf("\t\t\t\t17. Iced coffe \t\t\tRp.15000\n");
printf("\t\t\t\t18.iced Coffe Float\t\tRp.17500\n");
printf("\t\t\t\t19. air mineral\t\t\tRp.9500\n");



printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(5);

if (menu==1) {
   strcpy(food2, "Pinneple Punch Fizz");
   m = 0;
}
else if(menu==2) {
   strcpy(food2, "Aplle Fizz");
   m = 1;
}
else if (menu==3) {
   strcpy(food2, "McFreeze Bluberry");
   m = 2;
}
else if  (menu==4) {
   strcpy(food2, "  Mcfreeze fanta Grape ");
   m = 3;
}
else if  (menu==5) {
   strcpy(food2, "McFreeze Apple");
   m = 4;
}
else if (menu==6) {
   strcpy(food2, "Creamy mcfreeze bluberry");
   m = 5;
}
else if(menu==7) {
   strcpy(food2, " Creamy McFeeze fanta Grape");
   m = 6;
}
else if (menu==8) {
   strcpy(food2, " Creamy McFreeze Apple ");
   m = 7;
}
else if  (menu==9) {
   strcpy(food2, " Fruit Tea Lemon");
   m = 8;
}
else if(menu==10) {
   strcpy(food2,  "Coca Cola");
   m = 9;
}
else if (menu==11) {
   strcpy(food2, "Sprite");
   m = 10;
}
else if  (menu==12) {
   strcpy(food2, " Fanta");
   m = 11;
}
else if  (menu==13) {
   strcpy(food2, " Coca Cola Mcfloat");
   m = 12;
}
else if (menu==14) {
   strcpy(food2, "Fanta McFloat");
   m = 13;
}
else if(menu==15) {
   strcpy(food2, " Hot Coffe");
   m = 14;
}
else if (menu==16) {
   strcpy(food2, " hot tea");
   m = 15;
}
else if  (menu==17) {
   strcpy(food2, "Iced coffe ");
   m = 16;
}
else if (menu==18) {
   strcpy(food2, "iced coffe float");
   m = 17;
}
else if(menu==19) {
   strcpy(food2, "air mineral ");
   m = 18;
}
else{
    ending();
}

printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah2);

minuman = jumlah2 * hargaminuman[m];
printf("\t\t\t\t%s * %d : %d\n\n",food2,jumlah2,minuman);
goto hitung2;
break;
case 4:
system("cls");
ikan :
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t   Menu ikan   \t\t\t\t harga                           \n");
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t1. Fish prosperity Burger\t\tRp.25000\n");
printf("\t\t\t\t2. Fish Snack Wrap\t\t\tRp.28000\n");
printf("\t\t\t\t3. Fish Fillet Burger\t\t\tRp.32000 \n");
printf("\t\t\t\t4. Honey Garlic Fish rice mcd \t\tRp.36000 \n");
printf("\t\t\t\t5. Rica-rica fish Rice McD\t\tRp.27000\n");
printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(5);

if (menu==1) {
   strcpy(food, "Fish prosperity Burger");
   l = 0;
}
else if(menu==2) {
   strcpy(food, "Fish Snack Wrap");
   l = 1;
}
else if (menu==3) {
   strcpy(food, "Fish Fillet Burger");
   l = 2;
}
else if  (menu==4) {
   strcpy(food, " Honey Garlic Fish rice mcd ");
   l = 3;
}
else if  (menu==5) {
   strcpy(food, "Rica-rica fish Rice McD");
   l = 4;
}
else{
    ending();
}

printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah);

makanan = jumlah * hargaikan[l];
printf("\t\t\t\t%s * %d : %d\n\n",food,jumlah, makanan);
total = makanan;
printf("\t\t\t\tIngin pesan minuman?\n");
printf("\t\t\t\t1. Ya\n");
printf("\t\t\t\t2. Tidak\n");
printf("\t\t\t\tMasukan Pilihan : ");
ulang = validasi(2);

    if (ulang==1) {
        goto drink4;
    }
    else if (ulang==2) {
        goto hitung;
    }

drink4 :
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t   Menu minuman \t\t harga                         \n");
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t1. Pinneple Punch Fizz\t\tRp.13000\n");
printf("\t\t\t\t2. Aplle Fizz\t\t\tRp.20000\n");
printf("\t\t\t\t3. McFreeze Bluberry\t\tRp.23000 \n");
printf("\t\t\t\t4. Mcfreeze fanta Grape\t\tRp.24000 \n");
printf("\t\t\t\t5. McFreeze Apple\t\tRp.19500\n");
printf("\t\t\t\t6.Creamy mcfreeze bluberry\tRp.23500\n");
printf("\t\t\t\t7. Creamy McFeeze fanta Grape\tRp.20000\n");
printf("\t\t\t\t8.Creamy McFreeze Apple\t\tRp.21000\n");
printf("\t\t\t\t9. Fruit Tea Lemon\t\tRp.8000\n");
printf("\t\t\t\t10. Coca Cola\t\t\tRp.13000\n");
printf("\t\t\t\t11. Sprite\t\t\tRp.8000\n");
printf("\t\t\t\t12. Fanta\t\t\tRp.8000\n");
printf("\t\t\t\t13.Coca Cola Mcfloat\t\tRp.22000\n");
printf("\t\t\t\t14. Fanta McFloat\t\tRp.11000\n");
printf("\t\t\t\t15. Hot Coffe\t\t\tRp.12000\n");
printf("\t\t\t\t16. Hot Tea\t\t\tRp.12000\n");
printf("\t\t\t\t17. Iced coffe \t\t\tRp.15000\n");
printf("\t\t\t\t18.iced Coffe Float\t\tRp.17500\n");
printf("\t\t\t\t19. air mineral\t\t\tRp.9500\n");
printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(5);

if (menu==1) {
   strcpy(food2, "Pinneple Punch Fizz");
   m = 0;
}
else if(menu==2) {
   strcpy(food2, "Aplle Fizz");
   m = 1;
}
else if (menu==3) {
   strcpy(food2, "McFreeze Bluberry");
   m = 2;
}
else if  (menu==4) {
   strcpy(food2, "  Mcfreeze fanta Grape ");
   m = 3;
}
else if  (menu==5) {
   strcpy(food2, "McFreeze Apple");
   m = 4;
}
else if (menu==6) {
   strcpy(food2, "Creamy mcfreeze bluberry");
   m = 5;
}
else if(menu==7) {
   strcpy(food2, " Creamy McFeeze fanta Grape");
   m = 6;
}
else if (menu==8) {
   strcpy(food2, " Creamy McFreeze Apple ");
   m = 7;
}
else if  (menu==9) {
   strcpy(food2, " Fruit Tea Lemon");
   m = 8;
}
else if(menu==10) {
   strcpy(food2,  "Coca Cola");
   m = 9;
}
else if (menu==11) {
   strcpy(food2, "Sprite");
   m = 10;
}
else if  (menu==12) {
   strcpy(food2, " Fanta");
   m = 11;
}
else if  (menu==13) {
   strcpy(food2, " Coca Cola Mcfloat");
   m = 12;
}
else if (menu==14) {
   strcpy(food2, "Fanta McFloat");
   m = 13;
}
else if(menu==15) {
   strcpy(food2, " Hot Coffe");
   m = 14;
}
else if (menu==16) {
   strcpy(food2, " hot tea");
   m = 15;
}
else if  (menu==17) {
   strcpy(food2, "Iced coffe ");
   m = 16;
}
else if (menu==18) {
   strcpy(food2, "iced coffe float");
   m = 17;
}
else if(menu==19) {
   strcpy(food2, "air mineral ");
   m = 18;
}
else{
    ending();
}

printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah2);

minuman = jumlah2 * hargaminuman[m];
printf("\t\t\t\t%s * %d : %d\n\n",food2,jumlah2,minuman);
goto hitung2;
break;
case 5:
system("cls");
minuman :
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t   Menu minuman \t\t harga                         \n");
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t1. Pinneple Punch Fizz\t\tRp.13000\n");
printf("\t\t\t\t2. Aplle Fizz\t\t\tRp.20000\n");
printf("\t\t\t\t3. McFreeze Bluberry\t\tRp.23000 \n");
printf("\t\t\t\t4. Mcfreeze fanta Grape\t\tRp.24000 \n");
printf("\t\t\t\t5. McFreeze Apple\t\tRp.19500\n");
printf("\t\t\t\t6.Creamy mcfreeze bluberry\tRp.23500\n");
printf("\t\t\t\t7. Creamy McFeeze fanta Grape\tRp.20000\n");
printf("\t\t\t\t8.Creamy McFreeze Apple\t\tRp.21000\n");
printf("\t\t\t\t9. Fruit Tea Lemon\t\tRp.8000\n");
printf("\t\t\t\t10. Coca Cola\t\t\tRp.13000\n");
printf("\t\t\t\t11. Sprite\t\t\tRp.8000\n");
printf("\t\t\t\t12. Fanta\t\t\tRp.8000\n");
printf("\t\t\t\t13.Coca Cola Mcfloat\t\tRp.22000\n");
printf("\t\t\t\t14. Fanta McFloat\t\tRp.11000\n");
printf("\t\t\t\t15. Hot Coffe\t\t\tRp.12000\n");
printf("\t\t\t\t16. Hot Tea\t\t\tRp.12000\n");
printf("\t\t\t\t17. Iced coffe \t\t\tRp.15000\n");
printf("\t\t\t\t18.iced Coffe Float\t\tRp.17500\n");
printf("\t\t\t\t19. air mineral\t\t\tRp.9500\n");



printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(5);

if (menu==1) {
   strcpy(food, "Pinneple Punch Fizz");
   m = 0;
}
else if(menu==2) {
   strcpy(food, "Aplle Fizz");
   m = 1;
}
else if (menu==3) {
   strcpy(food, "McFreeze Bluberry");
   m = 2;
}
else if  (menu==4) {
   strcpy(food, "  Mcfreeze fanta Grape ");
   m = 3;
}
else if  (menu==5) {
   strcpy(food, "McFreeze Apple");
   m = 4;
}
else if (menu==6) {
   strcpy(food, "Creamy mcfreeze bluberry");
   m = 5;
}
else if(menu==7) {
   strcpy(food, " Creamy McFeeze fanta Grape");
   m = 6;
}
else if (menu==8) {
   strcpy(food, " Creamy McFreeze Apple ");
   m = 7;
}
else if  (menu==9) {
   strcpy(food, " Fruit Tea Lemon");
   m = 8;
}
else if(menu==10) {
   strcpy(food,  "Coca Cola");
   m = 9;
}
else if (menu==11) {
   strcpy(food, "Sprite");
   m = 10;
}
else if  (menu==12) {
   strcpy(food, " Fanta");
   m = 11;
}
else if  (menu==13) {
   strcpy(food, " Coca Cola Mcfloat");
   m = 12;
}
else if (menu==14) {
   strcpy(food, "Fanta McFloat");
   m = 13;
}
else if(menu==15) {
   strcpy(food, " Hot Coffe");
   m = 14;
}
else if (menu==16) {
   strcpy(food, " hot tea");
   m = 15;
}
else if  (menu==17) {
   strcpy(food, "Iced coffe ");
   m = 16;
}
else if (menu==18) {
   strcpy(food, "iced coffe float");
   m = 17;
}
else if(menu==19) {
   strcpy(food, "air mineral ");
   m = 18;
}
else{
    ending();
}

printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah);

makanan = jumlah * hargaminuman[m];
printf("\t\t\t\t%s * %d : %d\n\n",food,jumlah, makanan);
total = makanan;
goto hitung;
break;
case 6:
system("cls");
makananpenutup :
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t   Menu penutup  \t\t\t harga                         \n");
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t1. Choco Marsmellow Pie\t\t\tRp.13000\n");
printf("\t\t\t\t2. Drak ChoconMcFlurry with oreo\tRp.14000\n");
printf("\t\t\t\t3. Drak ChoconMcFlurry with crunch\tRp.14000 \n");
printf("\t\t\t\t4. Vanlilla Black waffle Cone\t\tRp.16500 \n");
printf("\t\t\t\t5. Apple pie\t\t\t\tRp.18500\n");
printf("\t\t\t\t6. McFlurry feat Oreo\t\t\tRp.12500\n");
printf("\t\t\t\t7. Mcflurry choco\t\t\tRp.12500\n");
printf("\t\t\t\t8. Strawberry sundae\t\t\tRp.11000\n");
printf("\t\t\t\t9. Chocolate sundae\t\t\tRp.11000\n");
printf("\t\t\t\t10.Icecream Cone\t\t\tRp.11000\n");
printf("\t\t\t\t11.Choco Top\t\t\t\tRp.22000\n");

printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(6);

if (menu==1) {
   strcpy(food, "Choco Marsmellow Pie");
   n = 0;
}
else if(menu==2) {
   strcpy(food, "Drak ChoconMcFlurry with oreo");
   n = 1;
}
else if (menu==3) {
   strcpy(food, "Drak ChoconMcFlurry with crunch");
   n = 2;
}
else if  (menu==4) {
   strcpy(food, " Vanlilla Black waffle Cone");
   n = 3;
}
else if  (menu==5) {
   strcpy(food, "Apple pie");
   n = 4;
}
else if (menu==6) {
   strcpy(food, "McFlurry feat Oreo");
   n = 5;
}
else if(menu==7) {
   strcpy(food, " Mcflurry choco");
   n = 6;
}
else if (menu==8) {
   strcpy(food, " Strawberry sundae ");
   n = 7;
}
else if  (menu==9) {
   strcpy(food, "Chocolate sundae");
   n = 8;
}
else if(menu==10) {
   strcpy(food,  "Icecream Cone ");
   n = 9;
}
else if (menu==11) {
   strcpy(food, "Choco Top");
   n = 10;
}

else{
    ending();
}

printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah);

makanan = jumlah * hargamakananpenutup[n];
printf("\t\t\t\t%s * %d : %d\n\n",food,jumlah, makanan);
total = makanan;
goto hitung;
break;
case 7:
system("cls");
happyMeal :
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t   Menu Happy Meal  \t\t\t harga                         \n");
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t1. Happy meal Egg & Cheese Muffin\t\tRp.38000\n");
printf("\t\t\t\t2. HAppy Meal 4 pcs McNuggets\t\tRp.35500\n");
printf("\t\t\t\t3. Happy Meal chicken Burgerh\t\tRp.39500 \n");
printf("\t\t\t\t4. Happy Meal Ayam McD\t\t\tRp.225000 \n");
printf("\t\t\t\t5. Happy meal beef burger\t\tRp.25500\n");
printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(7);

if (menu==1) {
   strcpy(food, "Happy meal Egg & Cheese Muffin");
   o = 0;
}
else if(menu==2) {
   strcpy(food, "HAppy Meal 4 pcs McNuggets");
   o = 1;
}
else if (menu==3) {
   strcpy(food, "Happy Meal chicken Burger");
   o = 2;
}
else if  (menu==4) {
   strcpy(food, " Happy Meal Ayam McD");
   o = 4;
}
else if  (menu==5) {
   strcpy(food, "Happy meal beef burger");
   o = 4;
}
else{
    ending();
}
printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah);

makanan = jumlah * hargahappymeal[o];
printf("\t\t\t\t%s * %d : %d\n\n",food,jumlah, makanan);
total = makanan;
goto hitung;
break;
case 8:
system("cls");
paketFamily:
printf("\t\t\t\t+=================================================================================================+\n");
printf("\t\t\t\t   Menu Happy Meal  \t\t\t\t\t\t harga                                                             \n");
printf("\t\t\t\t+=================================================================================================+\n");
printf("\t\t\t\t1. family weekend breakfast Hapy Meal Ayam McD dan Mainan\t\t\tRp.102000\n");
printf("\t\t\t\t2. family Weekend Breakfast happy meqal Egg & Cheese Muffin dan Mainan \t\t\tRp.102000\n");
printf("\t\t\t\t3. Family Time breakfast Bertiga happy Meal Ayam McD\t\t\t\tRp.102000 \n");
printf("\t\t\t\t4. family Time Breakfast bertiga happy Meal egg & Cheese Muffin\t\t\t\tRp.102000 \n");
printf("\t\t\t\t5. Family Time Bertiga Happy Meal Beef Burger\t\t\t\t\tRp.87000\n");
printf("\t\t\t\t5. Family Time Bertiga Happy Meal Ayam McD\t\t\t\t\tRp.87000\n");

printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(7);

if (menu==1) {
   strcpy(food, "family weekend breakfast Hapy Meal Ayam McD dan Mainan");
   p = 0;
}
else if(menu==2) {
   strcpy(food, "family Weekend Breakfast happy meqal Egg & Cheese Muffin dan Mainan");
   p = 1;
}
else if (menu==3) {
   strcpy(food, "Family Time breakfast Bertiga happy Meal Ayam McD");
   p = 2;
}
else if  (menu==4) {
   strcpy(food, " family Time Breakfast bertiga happy Meal egg & Cheese Muffin");
   p = 3;
}
else if  (menu==5) {
   strcpy(food, " Family Time Bertiga Happy Meal Beef Burger");
   p = 4;
}
else if  (menu==6) {
   strcpy(food, " Family Time Bertiga Happy Meal Ayam McD");
   p = 5;
}
else{
    ending();
}

printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah);

makanan = jumlah * hargafamily[p];
printf("\t\t\t\t%s * %d : %d\n\n",food,jumlah, makanan);
total = makanan;
goto hitung;
break;
case 9:
system("cls");
McCafe:
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t   Menu McCafe \t\t\t\t harga                         \n");
printf("\t\t\t\t+====================================================+\n");
printf("\t\t\t\t1. Iced  Himalayan Tea\t\t\tRp.16500\n");
printf("\t\t\t\t2. Himalayan Tea Frappe\t\t\tRp.15000\n");
printf("\t\t\t\t3. Iced Himalayan Latte\t\t\tRp.16500 \n");
printf("\t\t\t\t4. Himalayan Latte frappe\t\tRp.15000 \n");
printf("\t\t\t\t5. Affogato\t\t\t\tRp.21000\n");
printf("\t\t\t\t6. Hot Matcha Latte\t\t\tRp.15500\n");
printf("\t\t\t\t7. iced Matcha latte \t\t\tRp.16500\n");
printf("\t\t\t\t8. Iced cafe Matcha Fushion\t\tRp.16500\n");
printf("\t\t\t\t9. Matcha Frappe\t\t\tRp.18000\n");
printf("\t\t\t\t10.Tasseo Lemon Grass \t\t\tRp.17000\n");
printf("\t\t\t\t11.Tasseo java jasmine\t\t\tRp.17000\n");
printf("\t\t\t\t12.Tasseo Pure Green\t\t\tRp.17500\n");
printf("\t\t\t\t13.Espresso\t\t\t\tRp.19500\n");
printf("\t\t\t\t14.Machiato\t\t\t\tRp.17000\n");
printf("\t\t\t\t15.Long Black Coffe \t\t\tRp.19000\n");
printf("\t\t\t\t16. Flat White \t\t\t\tRp.14000\n");
printf("\t\t\t\t17. caffe Latte \t\t\tRp.13500\n");
printf("\t\t\t\t18.Cappuccino\t\t\t\tRp.13500\n");
printf("\t\t\t\t19.Banana Muffin\t\t\tRp.14000\n");
printf("\t\t\t\t20. Choco Chip Muffin\t\t\tRp.14000\n");
printf("\t\t\t\t21.Choco Lover \t\t\t\tRp.14000\n");
printf("\t\t\t\t22.Chicken Curry Puff\t\t\tRp.16000\n");
printf("\t\t\t\t23.klepon cake\t\t\t\tRp.20000\n");


printf("\t\t\t\tMasukan Pilihan : ");
menu = validasi(8);

if (menu==1) {
   strcpy(food, "Iced  Himalayan Tea");
   q = 0;
}
else if(menu==2) {
   strcpy(food, "Himalayan Tea Frappe");
   q = 1;
}
else if (menu==3) {
   strcpy(food, "Iced Himalayan Latte");
   q = 2;
}
else if  (menu==4) {
   strcpy(food, "Himalayan Latte frappe");
   q = 3;
}
else if  (menu==5) {
   strcpy(food, "Affogato");
   q = 4;
}
else if (menu==6) {
   strcpy(food, "Hot Matcha Latte");
   q = 5;
}
else if(menu==7) {
   strcpy(food, " iced Matcha latte");
   q = 6;
}
else if (menu==8) {
   strcpy(food, "Iced cafe Matcha Fushion");
   q = 7;
}
else if  (menu==9) {
   strcpy(food, "  Matcha Frappe");
   q = 8;
}
else if(menu==10) {
   strcpy(food,  "Tasseo Lemon Grass ");
   q = 9;
}
else if (menu==11) {
   strcpy(food, "Tasseo java jasmine");
   q = 10;
}
else if  (menu==12) {
   strcpy(food, " Tasseo Pure Green");
   q = 11;
}
else if  (menu==13) {
   strcpy(food, "Espresso");
   q = 12;
}
else if (menu==14) {
   strcpy(food, ".Machiato");
   q = 13;
}
else if(menu==15) {
   strcpy(food, "Long Black Coffe");
   q = 14;
}
else if (menu==16) {
   strcpy(food, "Flat White");
   q = 15;
}
else if  (menu==17) {
   strcpy(food, "caffe Latte ");
   q = 16;
}
else if (menu==18) {
   strcpy(food, "Cappuccino");
   q = 17;
}
else if(menu==19) {
   strcpy(food, "Banana Muffin ");
   q = 18;
}
else if(menu==20) {
   strcpy(food, "Choco Chip Muffin");
   q = 19;
}
else if (menu==21) {
   strcpy(food, "Choco Lover");
   q = 20;
}
else if  (menu==22) {
   strcpy(food, ".Chicken Curry Puff ");
   q = 21;
}
else if (menu==23) {
   strcpy(food, "klepon cake");
   q = 22;
}
else{
    ending();
}

printf("\t\t\t\tmasukkan jumlah pesanan :");
scanf("%d", &jumlah);

makanan = jumlah * hargaMcCafe[q];
printf("\t\t\t\t%s * %d : %d\n\n",food,jumlah, makanan);
total = makanan;
goto hitung;
break;
default :
    printf("\t\t\t\t+====================================================+\n");
    printf("\t\t\t\t                    input salah !                     \n");
    printf("\t\t\t\t+====================================================+\n");
    getchar();
}


hitung :
    printf("\n\t\t\t\t\t Konfirmasi Pesanan anda\n\n");

    printf("\n\t\t\t\t\t%s Dengan Nomor meja %d \n\n",layanan,meja);
    printf("\t\t\t\t%s * %d : %d\n\n",food, jumlah, makanan);
    total=makanan + ppn;
    printf("\t\t\t\tTotal Pembayaran : %d\n ",total);

    printf("\t\t\t\tlanjut atau tidak?\n");
    printf("\t\t\t\t1. Ya\n");
    printf("\t\t\t\t2. Tidak\n");
    printf("\t\t\t\tMasukan Pilihan : ");
    scanf("%d",&ulang);
        if (ulang==1) {
            goto bayarmakanan;
        }
        else if (ulang==2) {
        ending();
        }
    bayarmakanan:
        printf("\t\t\t\tUang yang dibayar : ");
        scanf("%d",&bayar);
        if (bayar<total) {
            printf("\n\t\t\t\tTolong bayar sesuai/melebihi total\n");
            goto bayarmakanan;
        }
        else {}
        kembali = bayar-total;
        printf("\t\t\t\tKembali : %d\n\n",kembali);

        printf("\t\t\t\tApa anda ingin pesan lagi?\n");
        printf("\t\t\t\t1. Ya\n");
        printf("\t\t\t\t2. Tidak\n");
        printf("\t\t\t\tMasukan Pilihan : ");
        scanf("%d",&ulang);
        if (ulang==1) {
            mainmenu();
        }
        else if (ulang==2) {
        goto struk;
        }
hitung2 :
    printf("\n\t\t\t\t\tKonfirmasi pesanan anda\n\n");

    printf("\n\t\t\t\t\t%s Dengan Nomor meja %d \n\n",layanan,meja);
    printf("\t\t\t\t%s * %d : %d\n\n",food, jumlah, makanan);
    printf("\t\t\t\t%s * %d : %d\n\n",food2, jumlah2, minuman);
    total= makanan + minuman + ppn ;
    printf("\t\t\t\tTotal Pembayaran : %d\n ",total);

    printf("\t\t\t\tlanjut atau tidak?\n");
    printf("\t\t\t\t1. Ya\n");
    printf("\t\t\t\t2. Tidak\n");
    printf("\t\t\t\tMasukan Pilihan : ");
    scanf("%d",&ulang);
        if (ulang==1) {
            goto bayar2;
        }
        else if (ulang==2) {
        ending();
        }
    bayar2:
        printf("\t\t\t\tJumlah Uang pembayaran : ");
        scanf("%d",&bayar);
        if (bayar<total) {
            printf("\n\t\t\t\tTolong bayar sesuai/melebihi total\n");
            goto bayar2;
        }
        else {}
        kembali=bayar-total;
        printf("\t\t\t\tKembali : %d\n\n",kembali);

        printf("\t\t\t\tApa anda ingin pesan lagi?\n");
        printf("\t\t\t\t1. Ya\n");
        printf("\t\t\t\t2. Tidak\n");
        printf("\t\t\t\tMasukan Pilihan : ");
        scanf("%d",&ulang);
        if (ulang==1) {
            goto awal;
        }
        else if (ulang==2) {
        goto struk2;
        }

hitung3 :

    system("cls");
    printf("\n\t\t\t\t\tKonfirmasi Pesanan anda\n\n");
    printf("\n\t\t\t\t\t%s Dengan Nomor meja %d \n\n",layanan,meja);
    printf("\t\t\t\t%s * %d : %d\n\n",food, jumlah, makanan);
    printf("\t\t\t\t%s * %d : %d\n\n",food2, jumlah2, minuman);
    printf("\t\t\t\t%s * %d : %d\n\n",food3, jumlah3, hpenutup);
    total= makanan + minuman + hpenutup + ppn ;
    printf("\t\t\t\tTotal Pembayaran : %d\n ",total);
    printf("\t\t\t\tlanjut atau tidak?\n");
    printf("\t\t\t\t1. Ya\n");
    printf("\t\t\t\t2. Tidak\n");
    printf("\t\t\t\tMasukan Pilihan : ");
    scanf("%d",&ulang);
        if (ulang==1) {
            goto bayar3;
        }
        else if (ulang==2) {
        ending();
        }

    bayar3:
        printf("\t\t\t\tjumlah uang pembayaran :");
        scanf("%d",&bayar);
        if (bayar<total) {
            printf("\n\t\t\t\tTolong bayar sesuai total\n");
            goto bayar3;
        }
        else {}
        kembali=bayar-total;
        printf("\t\t\t\tKembali : %d\n\n",kembali);

        printf("\t\t\t\tApa anda ingin pesan lagi?\n");
        printf("\t\t\t\t1. Ya\n");
        printf("\t\t\t\t2. Tidak\n");
        printf("\t\t\t\tMasukan Pilihan : ");
        scanf("%d",&ulang);
        if (ulang==1) {
            goto awal;
        }
        else if (ulang==2) {
        goto struk3;
        }

struk :
system("pause");
system("cls");
printf("\t\t\t\t+======================================================================+\n");
printf("\t\t\t\t                            struk pembayaran                            \n");
printf("\t\t\t\t+======================================================================+\n");
printf("\n");
printf("\n\t\t\t\t\t\t\t%s Dengan Nomor meja %d \n\n",layanan,meja);
printf("\n\t\t\t\t %s * %d\t\t\t\t: Rp. %d",food, jumlah, makanan);
printf("\n\t\t\t\t pajak\t\t\t\t\t\t\t: Rp. %f",ppn);
printf("\n\t\t\t\t total\t\t\t\t\t\t\t: Rp. %d", total);
printf("\n\t\t\t\t Jumlah Uang Pembayaran\t\t\t\t\t: Rp. %d",bayar);
printf("\n\t\t\t\t Kembalian\t\t\t\t\t\t: Rp. %d",kembali);
printf("\n");
printf("\n\t\t\t\t\t\t\tTerima kasih atas kunjungannya\n\n");
printf("\n\t\t\t\t+=====================================================================+\n");

struk2 :
system("pause");
system("cls");
printf("\t\t\t\t+======================================================================+\n");
printf("\t\t\t\t                            struk pembayaran                            \n");
printf("\t\t\t\t+======================================================================+\n");
printf("\n");
printf("\n\t\t\t\t\t\t\t%s Dengan Nomor meja %d \n\n",layanan,meja);
printf("\n\t\t\t\t %s * %d\t\t\t\t: Rp. %d",food, jumlah, makanan);
printf("\n\t\t\t\t %s * %d\t\t\t\t: Rp. %d",food2, jumlah2, minuman);
printf("\n\t\t\t\t pajak\t\t\t\t\t\t\t: Rp. %f",ppn);
printf("\n\t\t\t\t total\t\t\t\t\t\t\t: Rp. %d", total);
printf("\n\t\t\t\t Jumlah Uang Pembayaran\t\t\t\t\t: Rp. %d",bayar);
printf("\n\t\t\t\t Kembalian\t\t\t\t\t\t: Rp. %d",kembali);
printf("\n");
printf("\n\t\t\t\t\t\t\tTerima kasih atas kunjungannya\n\n");
printf("\n\t\t\t\t+=====================================================================+\n");

struk3 :
system("pause");
system("cls");
printf("\t\t\t\t+======================================================================+\n");
printf("\t\t\t\t                            struk pembayaran                            \n");
printf("\t\t\t\t+======================================================================+\n");
printf("\n");
printf("\n\t\t\t\t\t\t\t%s Dengan Nomor meja %d \n\n",layanan,meja);
printf("\n\t\t\t\t %s * %d\t\t\t\t: Rp. %d",food, jumlah, makanan);
printf("\n\t\t\t\t %s * %d\t\t\t\t: Rp. %d",food2, jumlah2, minuman);
printf("\n\t\t\t\t %s * %d\t\t\t\t: Rp. %d",food3, jumlah3, hpenutup);
printf("\n\t\t\t\t pajak\t\t\t\t\t\t\t: Rp. %f",ppn);
printf("\n\t\t\t\t total\t\t\t\t\t\t\t: Rp. %d", total);
printf("\n\t\t\t\t Jumlah Uang Pembayaran\t\t\t\t\t: Rp. %d",bayar);
printf("\n\t\t\t\t Kembalian\t\t\t\t\t\t: Rp. %d",kembali);
printf("\n");
printf("\n\t\t\t\t\t\t\tTerima kasih atas kunjungannya\n\n");
printf("\n\t\t\t\t+=====================================================================+\n");
return 0;
}
