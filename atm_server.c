/* Bai tap giua ky mon Ngon Ngu C
Chuong trinh mo phong hoat dong may ATM
|========================================|
|-- Chuong trinh Quan ly Tai Khoan ATM --|
|---------| Username: admin  |-----------|
|---------| Password: 557363 |-----------|
|========================================|*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

/* Struct INFO */
typedef struct
{
    char num[20];  /* so tai khoan */
    char pin[10];  /* ma PIN */
    char name[20]; /* ten chu tai khoan */
    long int balance; /* so du tai khoan */
    char  lasttime[30]; /* thoi diem giao dich lan cuoi */
    char notice[100];
    char status;
} INFO;

/* Protype */
void Excute();
void Run();
void Kill();
void Processing();
void Cancel();
void Menu1();
void Menu2();
char Menu3();
void Menu4(int k);
void Menu5();
void Input_box();
char Open_acc();
char View_acc();
char Active_value();
char Add_cash();
char Active_acc();
char Change_PIN();
char Change_passwd();
long Other_cash();
long Amount_cash();
INFO readFile(char id[10]);
void writeFile(char id[10], INFO temp);
void WriteLog(char id[10], INFO temp, long so, char key);
void Get_pass(char pw[10]);
void Get_time(char cur[30]);
void gotoxy( short x, short y ) ;

char ID[10];

int main(void)
{
    Excute();
    Run();
    Kill();
	return (0);
}

void Excute()
{
    system("title ATM Manage v1.0 by SFT");
    system("Color 0A");
    system("mode con: cols=54 lines=18");
    system("cls");
    printf("\nroot@atm:~#_ Excuting."); Sleep(200);
    printf(".");  Sleep(300);
    printf(".");  Sleep(300);
    printf(".");  Sleep(200);
    printf(".\n\n");
}

void Run()
{
    int temp1, temp2;
    do
    {
        Menu1();
        Menu2();
        temp1 = Menu3();
        Menu4(temp1);
        Menu5();
    }
    while (getch()!=27);
}

void Kill()
{
    system("cls");
    printf("\nroot@atm:~#_ ");
    Sleep(500);
    printf("\nroot@atm:~#_ Killing."); Sleep(200);
    printf(".");  Sleep(300);
    printf(".");  Sleep(300);
    printf(".");  Sleep(200);
    printf(".\n\n");
    exit(0);
}

void Processing()
{
    system("cls");   fflush(stdin);
    printf("\n���������������������������������������������������ͻ");
    printf("\n�                                                   �");
    printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
    printf("\n�                                                   �");
    printf("\n�   ���������������������������������������������   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�             VUI LONG DOI GIAY LAT                 �");
    printf("\n�                                                   �");
    printf("\n�              DANG XU LY.                          �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n���������������������������������������������������ͼ\n");
    Sleep(100);
    gotoxy(0,10);
    printf("�              DANG XU LY..                         �");
    Sleep(200);
    gotoxy(0,10);
    printf("�              DANG XU LY...                        �");
    Sleep(200);
    gotoxy(0,10);
    printf("�              DANG XU LY....                       �");
    Sleep(200);
    gotoxy(0,10);
	printf("�              DANG XU LY.....                      �");
    Sleep(200);
}

void Cancel()
{
            system("cls");   fflush(stdin);
            printf("\n���������������������������������������������������ͻ");
            printf("\n�                                                   �");
            printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
            printf("\n�                                                   �");
            printf("\n�   ���������������������������������������������   �");
            printf("\n�                                                   �");
            printf("\n�                GIAO DICH BI HUY BO                �");
            printf("\n�                                                   �");
            printf("\n�   BAN CO MUON THUC HIEN GIAO DICH KHAC KHONG ?    �");
            printf("\n�                               �����������������Ŀ �");
            printf("\n�                               � 1 � Co          � �");
            printf("\n�                               ������������������� �");
            printf("\n�                               �����������������Ŀ �");
            printf("\n�                               � 2 � Khong       � �");
            printf("\n�                               ������������������� �");
            printf("\n���������������������������������������������������ͼ\n");
            gotoxy(0,17);
}

void Menu1()
{
    system("cls");
    printf("\n���������������������������������������������������ͻ");
	printf("\n�                                                   �");
	printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
	printf("\n�                                                   �");
	printf("\n�   ���������������������������������������������   �");
	printf("\n�                                                   �");
	printf("\n�                                                   �");
	printf("\n�               CHUONG TRINH QUAN LY                �");
	printf("\n�                                                   �");
	printf("\n�            TAI KHOAN THE ATM TRA TRUOC            �");
	printf("\n�                                                   �");
	printf("\n�                                                   �");
	printf("\n�                                                   �");
	printf("\n�        Chia se co hoi - Hop tac thanh cong        �");
	printf("\n�                                                   �");
	printf("\n���������������������������������������������������ͼ\n");
	getch();
}

void Menu2()
{
    FILE *f;
    char pass[10],pw[10],flag=0;
    if (fopen("passwd","r+t")!=0)
    {
        f = fopen("passwd","r+t");
        fscanf(f,"%[^\t\n]s",pw);
        fclose(f);
    }
    else
    {
        strcpy(pw,"");
        strcpy(pw,"557363");
        f = fopen("passwd","w+t");
        fprintf(f,"%s",pw);
        fclose(f);
    }
    do
    {
        system("cls");   fflush(stdin);
        printf("\n���������������������������������������������������ͻ");
        printf("\n�                                                   �");
        printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
        printf("\n�                                                   �");
        printf("\n�   ���������������������������������������������   �");
        printf("\n�                                                   �");
        printf("\n�                                                   �");
        printf("\n�                                                   �");
        printf("\n�           Username:     ADMINISTRATOR             �");
        printf("\n�                                                   �");
        printf("\n�           Password:     ��������������            �");
        printf("\n�                                                   �");
        printf("\n�                                                   �");
        printf("\n�   Nhap mat khau. Enter de tiep tuc. ESC de thoat  �");
        printf("\n�                                                   �");
        printf("\n���������������������������������������������������ͼ\n");
        gotoxy(28,11);  Get_pass(pass);  fflush(stdin);
        if (strcmp(pass,pw)==0)
        {
            flag = 5;
            gotoxy(0,14);
            printf("�      Khop mat khau. Nhan Enter de tiep tuc...     �");
            gotoxy(0,17);
            getch();
            Processing();
        }
        else
        {
            flag += 1;
            gotoxy(0,14);
            printf("�   Mat khau sai. Enter de tiep tuc. ESC de thoat   �");
            gotoxy(0,17);
            if (getch()==27)
            {
                gotoxy(0,14);
                printf("�               Thoat Chuong trinh...               �");
                gotoxy(0,17);
                Sleep(1200);
                Kill();
            }
            if (flag==5)
            {
                gotoxy(0,14);
                printf("�    Ban da nhap sai 5 lan. Thoat Chuong trinh...   �");
                gotoxy(0,17);
                Sleep(1200);
                Kill();
            }

        }
    }
	while (flag<5);
}

char Menu3()
{
    char chon,flag=0;
    do
    {
        system("cls");   fflush(stdin);
        printf("\n���������������������������������������������������ͻ");
        printf("\n�                                                   �");
        printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
        printf("\n�                                                   �");
        printf("\n�   ���������������������������������������������   �");
        printf("\n�          XIN VUI LONG LUA CHON CHUC NANG          �");
        printf("\n� �����������������Ŀ          ������������������Ŀ �");
        printf("\n� � 1 � Mo TK       �          � 4 � Kich hoat    � �");
        printf("\n� �������������������          �������������������� �");
        printf("\n� �����������������Ŀ          ������������������Ŀ �");
        printf("\n� � 2 �Xem thongtin �          � 5 � Doi PIN      � �");
        printf("\n� �������������������          �������������������� �");
        printf("\n� �����������������Ŀ          ������������������Ŀ �");
        printf("\n� � 3 � Nap tien    �          � 6 � Mat khau ATM � �");
        printf("\n� �������������������          �������������������� �");
        printf("\n���������������������������������������������������ͼ\n");
        gotoxy(0,17);
        switch (getch())
        {
            case 49:
                fflush(stdin);
                flag=1;
                gotoxy(0,7);
                printf("� �����������������ͻ          ������������������Ŀ �");
                printf("\n� � 1 � Mo TK       �          � 4 � Kich hoat    � �");
                printf("\n� �����������������ͼ          �������������������� �");
                gotoxy(0,17);
                if (getch()==13)
                    return(flag);
                break;
            case 50:
                fflush(stdin);
                flag=2;
                gotoxy(0,10);
                printf("� �����������������ͻ          ������������������Ŀ �");
                printf("\n� � 2 �Xem thongtin �          � 5 � Doi PIN      � �");
                printf("\n� �����������������ͼ          �������������������� �");
                gotoxy(0,17);
                if (getch()==13)
                    return(flag);
                break;
            case 51:
                fflush(stdin);
                flag=3;
                gotoxy(0,13);
                printf("� �����������������ͻ          ������������������Ŀ �");
                printf("\n� � 3 � Nap tien    �          � 6 � Mat khau ATM � �");
                printf("\n� �����������������ͼ          �������������������� �");
                gotoxy(0,17);
                if (getch()==13)
                    return(flag);
                break;
            case 52:
                fflush(stdin);
                flag=4;
                gotoxy(0,7);
                printf("� �����������������Ŀ          ������������������ͻ �");
                printf("\n� � 1 � Mo TK       �          � 4 � Kich hoat    � �");
                printf("\n� �������������������          ������������������ͼ �");
                gotoxy(0,17);
                if (getch()==13)
                    return(flag);
                break;
            case 53:
                fflush(stdin);
                flag=5;
                gotoxy(0,10);
                printf("� �����������������Ŀ          ������������������ͻ �");
                printf("\n� � 2 �Xem thongtin �          � 5 � Doi PIN      � �");
                printf("\n� �������������������          ������������������ͼ �");
                gotoxy(0,17);
                if (getch()==13)
                    return(flag);
                break;
            case 54:
                fflush(stdin);
                flag=6;
                gotoxy(0,13);
                printf("� �����������������Ŀ          ������������������ͻ �");
                printf("\n� � 3 � Nap tien    �          � 6 � Mat khau ATM � �");
                printf("\n� �������������������          ������������������ͼ �");
                gotoxy(0,17);
                if (getch()==13)
                    return(flag);
                break;
            case 27:
                /* Nhan ESC de thoat khoi menu */
                flag=7;
                break;
        }
    }
	while (flag!=7);
	return(flag);
}

void Menu4(int k)
{
    int kk,t;
    do
    {
        switch (k)
        {
            case 1: ;
                t = Open_acc();
                if (t==1)
                {
                    kk = Menu3();  Menu4(kk);
                }
                k = 8;  break;
            case 2:
                t = View_acc();
                if (t==1)
                {
                    kk = Menu3();  Menu4(kk);
                }
                k = 8;  break;
            case 3:
                if (Add_cash()==1)
                {
                    kk = Menu3();  Menu4(kk);
                }
                k = 8;  break;
            case 4:
                if (Active_acc()==1)
                {
                    kk = Menu3();  Menu4(kk);
                }
                k = 8;  break;
            case 5:
                if (Change_PIN()==1)
                {
                    kk = Menu3();  Menu4(kk);
                }
                k = 8;  break;
            case 6:
                if (Change_passwd()==1)
                {
                    kk = Menu3();  Menu4(kk);
                }
                k = 8;  break;
            case 7: k = 8; break;
        }
    }
    while (k!=8);
}

void Menu5()
{
    system("cls");
    printf("\n���������������������������������������������������ͻ");
	printf("\n�                                                   �");
	printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
	printf("\n�                                                   �");
	printf("\n�   ���������������������������������������������   �");
	printf("\n�                                                   �");
	printf("\n�                                                   �");
	printf("\n�                    ADMINISTRATOR                  �");
	printf("\n�                                                   �");
	printf("\n�                KET THUC PHIEN QUAN LY             �");
	printf("\n�                                                   �");
	printf("\n�                                                   �");
	printf("\n�        Chia se co hoi - Hop tac thanh cong        �");
	printf("\n�                                                   �");
	printf("\n�       Nhan ESC lan nua de tat chuong trinh !      �");
	printf("\n���������������������������������������������������ͼ\n");
}

void Input_box()
{
    char id[10];
    do
    {
        system("cls");   fflush(stdin);
        printf("\n���������������������������������������������������ͻ");
        printf("\n�                                                   �");
        printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
        printf("\n�                                                   �");
        printf("\n�   ���������������������������������������������   �");
        printf("\n�                                                   �");
        printf("\n�                                                   �");
        printf("\n�                                                   �");
        printf("\n�               NHAP ID TAI KHOAN THE               �");
        printf("\n�                                                   �");
        printf("\n�              ID [001-100] :  ���������            �");
        printf("\n�                                                   �");
        printf("\n�                                                   �");
        printf("\n�              Vui long nhap 3 chu so ID            �");
        printf("\n�                                                   �");
        printf("\n���������������������������������������������������ͼ\n");
        gotoxy(34,11);  gets(id);  fflush(stdin);
        if ((Readf(id)==2)||(Readf(id)==1))
        {
            gotoxy(0,14);
            printf("�      ID da ton tai. Nhan Enter de nhap lai...     �");
            getch();
            gotoxy(0,14);
            printf("�              Vui long nhap 3 chu so ID            �");
            gotoxy(0,11);
            printf("�              ID [001-100] :  ���������            �");
        }
        else if (Readf(id)==0)
            {
                strcpy(ID,id);
                gotoxy(0,14);
                printf("�         ID hop le. Nhan Enter de tiep tuc...      �");
                gotoxy(0,17);
                getch();
            }
        else
            {
                gotoxy(0,14);
                printf("�      ID da ton tai. Nhan Enter de nhap lai...     �");
                getch();
                gotoxy(0,14);
                printf("�              Vui long nhap 3 chu so ID            �");
                gotoxy(0,11);
                printf("�              ID [001-100] :  ���������            �");
            }
    }
	while (Readf(id)!=0);
}

void Input_box_2()
{
    char id[10];
    do
    {
        system("cls");   fflush(stdin);
        printf("\n���������������������������������������������������ͻ");
        printf("\n�                                                   �");
        printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
        printf("\n�                                                   �");
        printf("\n�   ���������������������������������������������   �");
        printf("\n�                                                   �");
        printf("\n�                                                   �");
        printf("\n�                                                   �");
        printf("\n�               NHAP ID TAI KHOAN THE               �");
        printf("\n�                                                   �");
        printf("\n�              ID [001-100] :  ���������            �");
        printf("\n�                                                   �");
        printf("\n�                                                   �");
        printf("\n�              Vui long nhap 3 chu so ID            �");
        printf("\n�                                                   �");
        printf("\n���������������������������������������������������ͼ\n");
        gotoxy(34,11);  gets(id);  fflush(stdin);
        if (Readf(id)==0)
        {
            gotoxy(0,14);
            printf("�    ID khong hop le. Nhan Enter de nhap lai...     �");
            getch();
            gotoxy(0,14);
            printf("�              Vui long nhap 3 chu so ID            �");
            gotoxy(0,11);
            printf("�              ID [001-100] :  ���������            �");
        }
        else if ((Readf(id)==2)||(Readf(id)==1))
            {
                strcpy(ID,id);
                gotoxy(0,14);
                printf("�         ID hop le. Nhan Enter de tiep tuc...      �");
                gotoxy(0,17);
                getch();
            }
    }
	while (Readf(id)==0);
}

char Open_acc()
{
	FILE *f;
	INFO temp;
	char flag1=0, flag2=0, num[20], num2[20];
	Input_box();
    temp.balance = 0;
    do
    {
        system("cls");   fflush(stdin);
        printf("\n���������������������������������������������������ͻ");
        printf("\n�                                                   �");
        printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
        printf("\n�                                                   �");
        printf("\n�   ���������������������������������������������   �");
        printf("\n�                                                   �");
        printf("\n�               MO TAI KHOAN THE ATM                �");
        printf("\n�                                                   �");
        printf("\n�     So TK :         ��%s�����������������        �",ID);
        printf("\n�                                                   �");
        printf("\n�     Chu the :       ����������������������        �");
        printf("\n�                                                   �");
        printf("\n�   So tien ban dau : ����������������������        �");
        printf("\n�                                                   �");
        printf("\n�                                                   �");
        printf("\n���������������������������������������������������ͼ\n");
        while (strlen(num2)<11)
        {
            gotoxy(27,9);  gets(num2);  fflush(stdin);
            gotoxy(0,17);
            if (strlen(num2)<11)
            {
                gotoxy(0,15);
                printf("�           So TK phai bao gom 14 ky tu !           �");
                gotoxy(0,17);
                getch();
            }
        }
        flag1=1;
        gotoxy(0,15);
        printf("�       Ho ten chu the nen duoc viet in hoa !       �");
        gotoxy(24,11); gets(temp.name);  fflush(stdin);
        gotoxy(0,17);
        getch();
        while ((temp.balance>=0)&&(flag2!=1))
        {
            gotoxy(24,13); scanf("%ld",&temp.balance);  fflush(stdin);
            gotoxy(0,17);
            getch();
            if ((temp.balance<0)||(temp.balance>=1000000000000))
            {
                gotoxy(0,15);
                printf("�         Nhap so khong hop le. Nhap lai...         �");
                gotoxy(0,17);
                getch();
            }
            else flag2=1;
        }

    }
    while ((flag1!=1)&&(flag2!=1));
    strcpy(num,ID);
    strcat(num,num2);
    strcpy(temp.num,num);
	strcpy(temp.pin,"123456");
	temp.status = 1;
	strcpy(temp.lasttime,"");
	strcpy(temp.notice,"0");
	writeFile(ID,temp);
    gotoxy(0,15);
    printf("�  Mo tai khoan thanh cong ! Enter de tiep tuc...   �");
    gotoxy(0,17);
	getch();
	return (1);
}

char Active_value()
{
    FILE *f;
    INFO temp;
    char flag=0, flag2=0, num[60], name[60], status[20];
    Input_box_2();
    temp = readFile(ID);
    if (temp.status==2)
        strcpy(status,"Khoa");
    else strcpy(status,"OK");
    while (strlen(status)<23)
        strcat(status," ");
    strcpy(num,temp.num);
    while (strlen(num)<23)
        strcat(num," ");
    do
    {
        system("cls");   fflush(stdin);
        printf("\n���������������������������������������������������ͻ");
        printf("\n�                                                   �");
        printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
        printf("\n�                                                   �");
        printf("\n�   ���������������������������������������������   �");
        printf("\n�     So tai khoan  :       %s �",num);
        printf("\n�     Trang thai hien tai : %s �",status);
        printf("\n�                                                   �");
        printf("\n�           BAN CO MUON KHOA HAY KICH HOAT          �");
        printf("\n�                               �����������������Ŀ �");
        printf("\n�                               � 1 � Kich hoat   � �");
        printf("\n�                               ������������������� �");
        printf("\n�                               �����������������Ŀ �");
        printf("\n�                               � 2 � Khoa        � �");
        printf("\n�                               ������������������� �");
        printf("\n���������������������������������������������������ͼ\n");
        gotoxy(0,17);
        switch (getch())
        {
            case 49:
                fflush(stdin);
                flag=1;
                gotoxy(0,10);
                printf("�                               �����������������ͻ �");
                printf("\n�                               � 1 � Kich hoat   � �");
                printf("\n�                               �����������������ͼ �");
                gotoxy(0,17);
                if (getch()==13)
                    flag2 = 1;
                break;
            case 50:
                fflush(stdin);
                flag=2;
                gotoxy(0,13);
                printf("�                               �����������������ͻ �");
                printf("\n�                               � 2 � Khoa        � �");
                printf("\n�                               �����������������ͼ �");
                gotoxy(0,17);
                if (getch()==13)
                    flag2 = 1;
                break;
        }
    }
    while (flag2==0);
    return (flag);
}

char Active_acc()
{
    FILE *f;
    INFO temp;
    char status, flag=0, flag2 = 0, stt[60];
    status = Active_value();
    Processing();
    temp = readFile(ID);
    temp.status = status;
    writeFile(ID,temp);
    if (status==2)
        strcpy(stt,"KHOA TAI KHOAN THANH CONG");
    else strcpy(stt,"KICH HOAT TAI KHOAN THANH CONG");
    while (strlen(stt)<37)
        strcat(stt," ");
    do
    {
        system("cls");   fflush(stdin);
        printf("\n���������������������������������������������������ͻ");
        printf("\n�                                                   �");
        printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
        printf("\n�                                                   �");
        printf("\n�   ���������������������������������������������   �");
        printf("\n�                                                   �");
        printf("\n�      BAN DA %s �",stt);
        printf("\n�                                                   �");
        printf("\n�   BAN CO MUON THUC HIEN CHUC NANG KHAC KHONG ?    �");
        printf("\n�                               �����������������Ŀ �");
        printf("\n�                               � 1 � Co          � �");
        printf("\n�                               ������������������� �");
        printf("\n�                               �����������������Ŀ �");
        printf("\n�                               � 2 � Khong       � �");
        printf("\n�                               ������������������� �");
        printf("\n���������������������������������������������������ͼ\n");
        gotoxy(0,17);
        switch (getch())
        {
            case 49:
                fflush(stdin);
                flag=1;
                gotoxy(0,10);
                printf("�                               �����������������ͻ �");
                printf("\n�                               � 1 � Co          � �");
                printf("\n�                               �����������������ͼ �");
                gotoxy(0,17);
                if (getch()==13)
                    flag2 = 1;
                break;
            case 50:
                fflush(stdin);
                flag=2;
                gotoxy(0,13);
                printf("�                               �����������������ͻ �");
                printf("\n�                               � 2 � Khong       � �");
                printf("\n�                               �����������������ͼ �");
                gotoxy(0,17);
                if (getch()==13)
                    flag2 = 1;
                break;
        }
    }
    while (flag2==0);
    return (flag);
}

char Change_PIN()
{
    INFO temp;
    char flag=0,flag2=0,pin1[10],pin2[10];
    Input_box_2();
    temp = readFile(ID);
    system("cls");   fflush(stdin);
    printf("\n���������������������������������������������������ͻ");
    printf("\n�                                                   �");
    printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
    printf("\n�                                                   �");
    printf("\n�   ���������������������������������������������   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�              VUI LONG NHAP SO PIN MOI             �");
    printf("\n�                                                   �");
    printf("\n�                 ������������������                �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�               Vui long nhap 6 so PIN              �");
    printf("\n�                                                   �");
    printf("\n���������������������������������������������������ͼ\n");
    gotoxy(24,10);  Get_pass(pin1);  fflush(stdin);
    gotoxy(0,17);
    getch();
    system("cls");  fflush(stdin);
    printf("\n���������������������������������������������������ͻ");
    printf("\n�                                                   �");
    printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
    printf("\n�                                                   �");
    printf("\n�   ���������������������������������������������   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�           VUI LONG NHAP LAI SO PIN MOI            �");
    printf("\n�                                                   �");
    printf("\n�                 ������������������                �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�               Vui long nhap 6 so PIN              �");
    printf("\n�                                                   �");
    printf("\n���������������������������������������������������ͼ\n");
    gotoxy(24,10);  Get_pass(pin2);  fflush(stdin);
    gotoxy(0,17);
    getch();
    if ((strcmp(pin1,pin2)==0)&&(strcmp(pin1,temp.pin)!=0))
    {
        Processing();
        temp = readFile(ID);
        strcpy(temp.pin,pin1);
        Get_time(temp.lasttime);
        writeFile(ID,temp);
        do
        {
            system("cls");   fflush(stdin);
            printf("\n���������������������������������������������������ͻ");
            printf("\n�                                                   �");
            printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
            printf("\n�                                                   �");
            printf("\n�   ���������������������������������������������   �");
            printf("\n�                                                   �");
            printf("\n�            BAN DA DOI PIN THANH CONG              �");
            printf("\n�                                                   �");
            printf("\n�   BAN CO MUON THUC HIEN CHUC NANG KHAC KHONG ?    �");
            printf("\n�                               �����������������Ŀ �");
            printf("\n�                               � 1 � Co          � �");
            printf("\n�                               ������������������� �");
            printf("\n�                               �����������������Ŀ �");
            printf("\n�                               � 2 � Khong       � �");
            printf("\n�                               ������������������� �");
            printf("\n���������������������������������������������������ͼ\n");
            gotoxy(0,17);
            switch (getch())
            {
                case 49:
                    fflush(stdin);
                    flag=1;
                    gotoxy(0,10);
                    printf("�                               �����������������ͻ �");
                    printf("\n�                               � 1 � Co          � �");
                    printf("\n�                               �����������������ͼ �");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
                case 50:
                    fflush(stdin);
                    flag=2;
                    gotoxy(0,13);
                    printf("�                               �����������������ͻ �");
                    printf("\n�                               � 2 � Khong       � �");
                    printf("\n�                               �����������������ͼ �");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
            }
        }
        while (flag2==0);
    }
    else
    {
        temp = readFile(ID);
        Processing();
        do
        {
            system("cls");   fflush(stdin);
            printf("\n���������������������������������������������������ͻ");
            printf("\n�                                                   �");
            printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
            printf("\n�                                                   �");
            printf("\n�   ���������������������������������������������   �");
            printf("\n�                                                   �");
            printf("\n�             DOI PIN KHONG THANH CONG              �");
            printf("\n�                                                   �");
            printf("\n�                                                   �");
            printf("\n�   BAN CO MUON THUC HIEN CHUC NANG KHAC KHONG ?    �");
            printf("\n�                               �����������������Ŀ �");
            printf("\n�                               � 1 � Co          � �");
            printf("\n�                               ������������������� �");
            printf("\n�                               �����������������Ŀ �");
            printf("\n�                               � 2 � Khong       � �");
            printf("\n�                               ������������������� �");
            printf("\n���������������������������������������������������ͼ\n");
            gotoxy(0,17);
            switch (getch())
            {
                case 49:
                    fflush(stdin);
                    flag=1;
                    gotoxy(0,10);
                    printf("�                               �����������������ͻ �");
                    printf("\n�                               � 1 � Co          � �");
                    printf("\n�                               �����������������ͼ �");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
                case 50:
                    fflush(stdin);
                    flag=2;
                    gotoxy(0,13);
                    printf("�                               �����������������ͻ �");
                    printf("\n�                               � 2 � Khong       � �");
                    printf("\n�                               �����������������ͼ �");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
            }
        }
        while (flag2==0);
    }
	return (flag);
}

char View_acc()
{
	FILE *f;
	INFO temp;
	char sotien[60],num[60],name[60], lasttime[60], status[20], flag=0, flag2=0;
	Input_box_2();
	temp = readFile(ID);
	Processing();
	if (temp.status==2)
        strcpy(status,"Khoa");
    else strcpy(status,"OK");
    while (strlen(status)<7)
        strcat(status," ");
    sprintf(sotien,"%ld",temp.balance);
    fflush(stdin);
    strcpy(num,temp.num);
    while (strlen(num)<23)
        strcat(num," ");
    strcpy(name,temp.name);
    while (strlen(name)<23)
        strcat(name," ");
    strcat(sotien," VND");
    while (strlen(sotien)<23)
        strcat(sotien," ");
    strcpy(lasttime,temp.lasttime);
    if (strlen(lasttime)<3)
        strcpy(lasttime,"Chua su dung lan nao");
    while (strlen(lasttime)<23)
        strcat(lasttime," ");
    do
        {
            system("cls");   fflush(stdin);
            printf("\n���������������������������������������������������ͻ");
            printf("\n�                                                   �");
            printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
            printf("\n�                                                   �");
            printf("\n�   ���������������������������������������������   �");
            printf("\n�  THONG TIN TAI KHOAN         Trang thai : %s �",status);
            printf("\n�     Chu tai khoan :       %s �",name);
            printf("\n�     So tai khoan  :       %s �",num);
            printf("\n�     So du thuc te :       %s �",sotien);
            printf("\n�     Truy cap gan nhat :   %s �",lasttime);
            printf("\n�                                                   �");
            printf("\n�    BAN CO MUON THUC HIEN CHUC NANG KHAC KHONG     �");
            printf("\n� �����������������Ŀ           �����������������Ŀ �");
            printf("\n� � 1 � Co          �           � 2 � Khong       � �");
            printf("\n� �������������������           ������������������� �");
            printf("\n���������������������������������������������������ͼ\n");
            gotoxy(0,17);
            switch (getch())
            {
                case 49:
                    fflush(stdin);
                    flag=1;
                    gotoxy(0,13);
                    printf("� �����������������ͻ           �����������������Ŀ �");
                    printf("\n� � 1 � Co          �           � 2 � Khong       � �");
                    printf("\n� �����������������ͼ           ������������������� �");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        return(flag);
                    }
                    break;
                case 50:
                    fflush(stdin);
                    flag=2;
                    gotoxy(0,13);
                    printf("� �����������������Ŀ           �����������������ͻ �");
                    printf("\n� � 1 � Co          �           � 2 � Khong       � �");
                    printf("\n� �������������������           �����������������ͼ �");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        return(flag);
                    }
                    break;
            }
        }
        while (flag2==0);
}

char Add_cash()
{
    FILE *f;
    INFO temp;
    long cash, balance;
    char flag=0,flag2=0,sodutt[25],soducp[25], num[20], s[60], lasttime[30], sotien[20];
    Input_box_2();
    cash = Amount_cash();
    Processing();
    temp = readFile(ID);
    temp.balance += cash;
    Get_time(lasttime);
    fflush(stdin);
    sprintf(sotien,"%ld",cash);
    strcpy(s,"");
    strcat(s,"BAN VUA DUOC NAP SO TIEN: ");
    strcat(s,sotien);
    strcat(s,".");
    strcpy(temp.notice,s);
    fflush(stdin);
    WriteLog(ID,temp,cash,'+');
    balance = temp.balance - 50000;
    writeFile(ID,temp);
    sprintf(sodutt,"%ld",temp.balance);
    sprintf(soducp,"%ld",balance);
    fflush(stdin);
    strncat(num,temp.num,14);
    strcat(soducp," VND");
    strcat(sodutt," VND");
    while (strlen(soducp)<23)
    {
        strcat(soducp," ");
    }
    while (strlen(sodutt)<23)
    {
        strcat(sodutt," ");
    }
    do
    {
        system("cls");   fflush(stdin);
        printf("\n���������������������������������������������������ͻ");
        printf("\n�                                                   �");
        printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
        printf("\n�                                                   �");
        printf("\n�   ���������������������������������������������   �");
        printf("\n�          SO DU TAI KHOAN   %s         �",num);
        printf("\n�     So du cho phep :      %s �",soducp);
        printf("\n�     So du thuc te  :      %s �",sodutt);
        printf("\n�   BAN CO MUON THUC HIEN CHUC NANG KHAC KHONG ?    �");
        printf("\n�                               �����������������Ŀ �");
        printf("\n�                               � 1 � Co          � �");
        printf("\n�                               ������������������� �");
        printf("\n�                               �����������������Ŀ �");
        printf("\n�                               � 2 � Khong       � �");
        printf("\n�                               ������������������� �");
        printf("\n���������������������������������������������������ͼ\n");
        gotoxy(0,17);
        switch (getch())
        {
            case 49:
                fflush(stdin);
                flag=1;
                gotoxy(0,10);
                printf("�                               �����������������ͻ �");
                printf("\n�                               � 1 � Co          � �");
                printf("\n�                               �����������������ͼ �");
                gotoxy(0,17);
                if (getch()==13)
                {
                    flag2 = 1;
                    return(flag);
                }
                break;
            case 50:
                fflush(stdin);
                flag=2;
                gotoxy(0,13);
                printf("�                               �����������������ͻ �");
                printf("\n�                               � 2 � Khong       � �");
                printf("\n�                               �����������������ͼ �");
                gotoxy(0,17);
                if (getch()==13)
                {
                    flag2 = 1;
                    return(flag);
                }
                break;
        }
    }
    while (flag2==0);
    return (flag);
}

long Other_cash()
{
    long money, flag=0;
    do
    {
        system("cls");   fflush(stdin);
        printf("\n���������������������������������������������������ͻ");
        printf("\n�                                                   �");
        printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
        printf("\n�                                                   �");
        printf("\n�   ���������������������������������������������   �");
        printf("\n�                                                   �");
        printf("\n�               VUI LONG NHAP SO TIEN               �");
        printf("\n�                                                   �");
        printf("\n�                                                   �");
        printf("\n�                 �����������������                 �");
        printf("\n�                                                   �");
        printf("\n�                                                   �");
        printf("\n�     Luu y: So tien phai la boi so cua 10.000      �");
        printf("\n�                                                   �");
        printf("\n�                (Nhan ESC de huy bo)               �");
        printf("\n���������������������������������������������������ͼ\n");
        gotoxy(20,10);  scanf("%ld",&money);  fflush(stdin);
        if ((money<50000)||(money>1000000000000))
        {
            gotoxy(0,10);
            printf("�                 �����������������                 �");
            gotoxy(0,14);
            printf("�   So tien khong hop le. Nhan Enter de nhap lai... �");
            gotoxy(0,17);
            if (getch()==27)
            {
                flag = 1;
                money = 0;
            }
        }
        else if ((money%10000==0)&&(money>=10000))
            {
                gotoxy(0,14);
                printf("�      So tien hop le. Nhan Enter de tiep tuc...    �");
                gotoxy(0,17);
                flag = 1;
                if (getch()==27)
                {
                    flag = 1;
                    money = 0;
                }
            }
            else
            {
                gotoxy(0,10);
                printf("�                 �����������������                 �");
                gotoxy(0,14);
                printf("�   So tien khong hop le. Nhan Enter de nhap lai... �");
                gotoxy(0,17);
                if (getch()==27)
                {
                    flag = 1;
                    money = 0;
                }
            }
    }
	while (flag!=1);
	return (money);
}

long Amount_cash()
{
    INFO temp;
    long flag;
    char flag2=0;
    do
    {
        system("cls");   fflush(stdin);
        printf("\n���������������������������������������������������ͻ");
        printf("\n�                                                   �");
        printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
        printf("\n�                                                   �");
        printf("\n�   ���������������������������������������������   �");
        printf("\n�       XIN VUI LONG LUA CHON SO TIEN - VND         �");
        printf("\n� �����������������Ŀ          ������������������Ŀ �");
        printf("\n� � 1 �    50.000   �          � 4 �    500.000   � �");
        printf("\n� �������������������          �������������������� �");
        printf("\n� �����������������Ŀ          ������������������Ŀ �");
        printf("\n� � 2 �   100.000   �          � 5 �  1.000.000   � �");
        printf("\n� �������������������          �������������������� �");
        printf("\n� �����������������Ŀ          ������������������Ŀ �");
        printf("\n� � 3 �   200.000   �          � 6 �   So Khac    � �");
        printf("\n� �������������������          �������������������� �");
        printf("\n���������������������������������������������������ͼ\n");
        gotoxy(0,17);
        switch (getch())
        {
                case 49:
                    fflush(stdin);
                    flag=50000;
                    gotoxy(0,7);
                    printf("� �����������������ͻ          ������������������Ŀ �");
                    printf("\n� � 1 �    50.000   �          � 4 �    500.000   � �");
                    printf("\n� �����������������ͼ          �������������������� �");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        if ((flag%10000==0)&&(flag>=10000)&&(flag<1000000000000))
                            return(flag);
                        else return(0);
                    }
                    break;
                case 50:
                    fflush(stdin);
                    flag=100000;
                    gotoxy(0,10);
                    printf("� �����������������ͻ          ������������������Ŀ �");
                    printf("\n� � 2 �   100.000   �          � 5 �  1.000.000   � �");
                    printf("\n� �����������������ͼ          �������������������� �");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        if ((flag%10000==0)&&(flag>=10000)&&(flag<1000000000000))
                            return(flag);
                        else return(0);
                    }
                    break;
                case 51:
                    fflush(stdin);
                    flag=200000;
                    gotoxy(0,13);
                    printf("� �����������������ͻ          ������������������Ŀ �");
                    printf("\n� � 3 �   200.000   �          � 6 �   So Khac    � �");
                    printf("\n� �����������������ͼ          �������������������� �");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        if ((flag%10000==0)&&(flag>=10000)&&(flag<1000000000000))
                            return(flag);
                        else return(0);
                    }
                    break;
                case 52:
                    fflush(stdin);
                    flag = 500000;
                    gotoxy(0,7);
                    printf("� �����������������Ŀ          ������������������ͻ �");
                    printf("\n� � 1 �    50.000   �          � 4 �    500.000   � �");
                    printf("\n� �������������������          ������������������ͼ �");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        if ((flag%10000==0)&&(flag>=10000)&&(flag<1000000000000))
                            return(flag);
                        else return(0);
                    }
                    break;
                case 53:
                    fflush(stdin);
                    flag = 1000000;
                    gotoxy(0,10);
                    printf("� �����������������Ŀ          ������������������ͻ �");
                    printf("\n� � 2 �   100.000   �          � 5 �  1.000.000   � �");
                    printf("\n� �������������������          ������������������ͼ �");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        if ((flag%10000==0)&&(flag>=10000)&&(flag<1000000000000))
                            return(flag);
                        else return(0);
                    }
                    break;
                case 54:
                    fflush(stdin);
                    flag=6;
                    gotoxy(0,13);
                    printf("� �����������������Ŀ          ������������������ͻ �");
                    printf("\n� � 3 �   200.000   �          � 6 �   So Khac    � �");
                    printf("\n� �������������������          ������������������ͼ �");
                    gotoxy(0,17);
                    if (getch()==13)
                    {
                        flag2 = 1;
                        flag = Other_cash();
                        return(flag);
                    }
                    break;
            }
        }
        while (flag2==0);
	return (flag);
}

char Change_passwd()
{
    FILE *f;
    char pw[20], pin[20], pin1[20], pin2[20], flag=0, flag2=0;
    if (fopen("passwd","r+t")!=0)
    {
        f = fopen("passwd","r+t");
        fscanf(f,"%[^\t\n]s",pin);
        fclose(f);
    }
    else
    {
        strcpy(pin,"");
        strcpy(pin,"557363");
        f = fopen("passwd","w+t");
        fprintf(f,"%s",pin);
        fclose(f);
    }
    system("cls");   fflush(stdin);
    printf("\n���������������������������������������������������ͻ");
    printf("\n�                                                   �");
    printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
    printf("\n�                                                   �");
    printf("\n�   ���������������������������������������������   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�              VUI LONG NHAP MAT KHAU MOI           �");
    printf("\n�                                                   �");
    printf("\n�                 ������������������                �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n���������������������������������������������������ͼ\n");
    gotoxy(24,10);  Get_pass(pin1);  fflush(stdin);
    gotoxy(0,17);
    getch();
    system("cls");  fflush(stdin);
    printf("\n���������������������������������������������������ͻ");
    printf("\n�                                                   �");
    printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
    printf("\n�                                                   �");
    printf("\n�   ���������������������������������������������   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�            VUI LONG NHAP LAI MAT KHAU MOI         �");
    printf("\n�                                                   �");
    printf("\n�                 ������������������                �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n�                                                   �");
    printf("\n���������������������������������������������������ͼ\n");
    gotoxy(24,10);  Get_pass(pin2);  fflush(stdin);
    gotoxy(0,17);
    getch();
    if ((strcmp(pin1,pin2)==0)&&(strcmp(pin1,pin)!=0))
    {
        Processing();
        strcpy(pw,pin1);
        f = fopen("passwd","w+t");
        fprintf(f,"%s",pw);
        fclose(f);
        do
        {
            system("cls");   fflush(stdin);
            printf("\n���������������������������������������������������ͻ");
            printf("\n�                                                   �");
            printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
            printf("\n�                                                   �");
            printf("\n�   ���������������������������������������������   �");
            printf("\n�                                                   �");
            printf("\n�          BAN DA DOI MAT KHAU THANH CONG           �");
            printf("\n�                                                   �");
            printf("\n�   BAN CO MUON THUC HIEN CHUC NANG KHAC KHONG ?    �");
            printf("\n�                               �����������������Ŀ �");
            printf("\n�                               � 1 � Co          � �");
            printf("\n�                               ������������������� �");
            printf("\n�                               �����������������Ŀ �");
            printf("\n�                               � 2 � Khong       � �");
            printf("\n�                               ������������������� �");
            printf("\n���������������������������������������������������ͼ\n");
            gotoxy(0,17);
            switch (getch())
            {
                case 49:
                    fflush(stdin);
                    flag=1;
                    gotoxy(0,10);
                    printf("�                               �����������������ͻ �");
                    printf("\n�                               � 1 � Co          � �");
                    printf("\n�                               �����������������ͼ �");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
                case 50:
                    fflush(stdin);
                    flag=2;
                    gotoxy(0,13);
                    printf("�                               �����������������ͻ �");
                    printf("\n�                               � 2 � Khong       � �");
                    printf("\n�                               �����������������ͼ �");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
            }
        }
    while (flag2==0);
    }
    else
    {
        Processing();
        do
        {
            system("cls");   fflush(stdin);
            printf("\n���������������������������������������������������ͻ");
            printf("\n�                                                   �");
            printf("\n�   K-Bank  �  NGAN HANG HOC VIEN KY THUAT MAT MA   �");
            printf("\n�                                                   �");
            printf("\n�   ���������������������������������������������   �");
            printf("\n�                                                   �");
            printf("\n�           DOI MAT KHAU KHONG THANH CONG           �");
            printf("\n�                                                   �");
            printf("\n�                                                   �");
            printf("\n�   BAN CO MUON THUC HIEN CHUC NANG KHAC KHONG ?    �");
            printf("\n�                               �����������������Ŀ �");
            printf("\n�                               � 1 � Co          � �");
            printf("\n�                               ������������������� �");
            printf("\n�                               �����������������Ŀ �");
            printf("\n�                               � 2 � Khong       � �");
            printf("\n�                               ������������������� �");
            printf("\n���������������������������������������������������ͼ\n");
            gotoxy(0,17);
            switch (getch())
            {
                case 49:
                    fflush(stdin);
                    flag=1;
                    gotoxy(0,10);
                    printf("�                               �����������������ͻ �");
                    printf("\n�                               � 1 � Co          � �");
                    printf("\n�                               �����������������ͼ �");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
                case 50:
                    fflush(stdin);
                    flag=2;
                    gotoxy(0,13);
                    printf("�                               �����������������ͻ �");
                    printf("\n�                               � 2 � Khong       � �");
                    printf("\n�                               �����������������ͼ �");
                    gotoxy(0,17);
                    if (getch()==13)
                        flag2 = 1;
                    break;
            }
        }
        while (flag2==0);
    }
    return (flag);
}

int Readf(char id[3])
{
    FILE *f;
    INFO temp;
    char fn[10];
    /* Generation Filename */
    strcpy(fn,"acc");
    strcat(fn,id);
    strcat(fn,".dat");
    /* End */

    /* Check file */
    if (fopen(fn,"rb")!=0)
        {
            temp = readFile(id);
            if (temp.status==1)
                return(1);
            else if(temp.status==2)
                return(2);
        }
    else return(0);
}

INFO readFile(char id[10])
{
    FILE *f;
    INFO temp;
    char fn[10];
    /* Generation Filename */
    strcpy(fn,"acc");
    strcat(fn,id);
    strcat(fn,".dat");
    /* End */

    /* Read file */
    f = fopen(fn,"r+b");
    fread(&temp,sizeof(INFO),1,f);
    fclose(f);
    return temp;
}

void writeFile(char id[10], INFO temp)
{
    FILE *f;
    char fn[10];
    /* Generation Filename */
    strcpy(fn,"acc");
    strcat(fn,id);
    strcat(fn,".dat");
    /* End */

    /* Write file */
    f = fopen(fn,"w+b");
    fwrite(&temp,sizeof(INFO),1,f);
    fclose(f);
}

void WriteLog(char id[10], INFO temp, long so, char key)
{
    FILE *f;
    char fn[10], lasttime[30];
    /* Generation Filename */
    strcpy(fn,"acc");
    strcat(fn,id);
    strcat(fn,"_log.data");
    /* End */

    /* Write file */
    Get_time(lasttime);
    while (strlen(lasttime)<20)
        strcat(lasttime," ");
    f = fopen(fn,"a+t");
    fprintf(f,"%20s  %c  %10ld VND\n",lasttime,key,so);
    fclose(f);
}

void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;
    SetConsoleCursorPosition( hStdout, position ) ;
}

void Get_pass(char pw[])
{
	int x=0,t;
	do
	{
		t = getch();
		if ((t>=32 && t<=57)||(t>=65 && t<=90)||(t>=97 && t<=122))
		{
			putch('*');
			pw[x]=t;
            x++;
        }
    }
    while (t!=13);
	pw[x]='\0';
}

void Get_time(char cur[])
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char current[]="",temp[10],ss;
    sprintf(temp,"%d",tm.tm_hour);
    strcat(current,temp);
    strcat(current,":");
    sprintf(temp,"%d",tm.tm_min);
    strcat(current,temp);
    strcat(current,":");
    ss = tm.tm_sec;
    sprintf(temp,"%d",ss);
    strcat(current,temp);
    strcat(current," ");
    sprintf(temp,"%d",tm.tm_mday);
    strcat(current,temp);
    strcat(current,"/");
    sprintf(temp,"%d",tm.tm_mon+1);
    strcat(current,temp);
    strcat(current,"/");
    sprintf(temp,"%d",tm.tm_year + 1900);
    strcat(current,temp);
    strcpy(cur,current);
}
