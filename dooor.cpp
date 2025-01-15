#include<stdio.h>
#include<algorithm> 
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_USERS 50

struct Com {
    char name[15];
    char tel[12];
    char id[20];
    char time[20];
}com[MAX_USERS];
struct Bui_A{
	char name[15];
    char tel[12];
    char id[20];
    char time[20];
}A[MAX_USERS];
struct Bui_B{
	char name[15];
    char tel[12];
    char id[20];
    char time[20];
}B[MAX_USERS];
static int n1=0;
static int n2=0;
static int n3=0; 

FILE *c; // С�����ڴ洢��Ϣ
FILE *b_a; // ¥�Ŵ洢��Ϣ
FILE *b_b; // ¥�Ŵ洢��Ϣ

void menu(); // �ܲ˵�
void admin_password(); // ����Ա��������
void admin_menu(); // ����Ա�˵�
void admin_update(); // ����Ա�ڲ��û�����
void admin_delete(); // ����Աɾ���û�
void admin_output();//����Ա��ʾ�Ǽ��û� 
void admin_cha();//�޸��û���Ϣ 
void out_com();
void out_building();
void out_A();
void out_B();
void admin_sort();//ʱ������ 
void sort_com();
void sort_building();
void sort_A();
void sort_B();
void community();//С������ 
void building();
void A_add(); // A¥����
void B_add(); // B¥����
void per_delete();//����ɾ�� 
void __community(); //С���ż��� 
void __building();//¥�ż��� 
void __A();//A�� 
void __B();//B�� 
void empty(); //��� 
void empty_com();//���С���Ǽ� 
void empty_building();//���¥�Ǽ� 
void empty__A();//���A 
void empty__B();//���B 
void cha_com(); 
void cha_building();
void cha_A();
void cha_B();


void user_menu();
void user_password(); // �û����뿨�Ŵ�С����
void user_building(); // �û�ѡ��¥��
void user_A(); // �û���A¥��
void user_B(); // �û���B¥��
void com_time(); 
void A_time(); // A¥����ʱ��
void B_time(); // B¥����ʱ��
void readfile_com();
void readfile_A(); // ��ȡ�ļ�
void readfile_B();
void writefile_com();
void writefile_A(); // д���ļ�
void writefile_B();





void readfile_com() {
    if((c=fopen("com.txt","r"))==NULL){
		printf("\t\t\t��ʧ�ܣ�δ��ѯ���ļ���\n");
        exit(0);
    }
    while(!feof(c) && fread(&com[n1],sizeof(struct Com),1,c)){
    		n1++;
		}
}
void readfile_A() {
    if((b_a=fopen("A.txt","r"))==NULL){
		printf("\t\t\t��ʧ�ܣ�δ��ѯ���ļ���\n");
        exit(0);
    }
    while(!feof(b_a) && fread(&A[n2],sizeof(struct Bui_A),1,b_a)){
    		n2++;
		}
}
void readfile_B() {
    if((b_b=fopen("B.txt","r"))==NULL){
		printf("\t\t\t��ʧ�ܣ�δ��ѯ���ļ���\n");
        exit(0);
    }
    while(!feof(b_b) && fread(&B[n3],sizeof(struct Bui_B),1,b_b)){
    		n3++;
		}
}



void writefile_com(){
    if ((c=fopen("com.txt","w"))==NULL){
        printf("\t\t\t��ʧ��");
    }for(int i=0;i<n1;i++){
        if(fwrite(&com[i],sizeof(struct Com),1,c)!=1){
            printf("\t\t\t�ļ�����ʧ��\n");
        }
    }
	fclose(c);
}
void writefile_A(){
    if ((b_a=fopen("A.txt","w"))==NULL){
        printf("\t\t\t��ʧ��");
    }for(int i=0;i<n2;i++){
        if(fwrite(&A[i],sizeof(struct Bui_A),1,b_a)!=1){
            printf("\t\t\t�ļ�����ʧ��\n");
        }
    }
	fclose(b_a);
}
void writefile_B(){
    if ((b_b=fopen("B.txt","w"))==NULL){
        printf("\t\t\t��ʧ��");
    }for(int i=0;i<n3;i++){
        if(fwrite(&B[i],sizeof(struct Bui_B),1,b_b)!=1){
            printf("\t\t\t�ļ�����ʧ��\n");
        }
    }
	fclose(b_b);
}










void menu() {
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t    ��ӭʹ���Ž�����ϵͳ��  \t**\n");//�Ű����� 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.����Ա��¼\t\t**\n");
        printf("\t\t\t**\t\t2.�û���¼\t\t**\n");
        printf("\t\t\t**\t\t3.�˳�ϵͳ\t\t**\n");        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//����һ��*
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                admin_password();
                break;
            case 2:
                user_password();
                break;
            case 3:
                writefile_com();
                writefile_A();
                writefile_B();
                printf("\t\t\t��л���ʣ��˳��С�\n");
                exit(0);
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }
}

void admin_password() {
    int count = 3;
    char ps[10];
    printf("����������:\n");
    fgets(ps, 10, stdin);
    ps[strcspn(ps, "\n")] = 0; // ȥ�����з�
    while (count && strcmp(ps, "123456") != 0) {
        printf("\n�����������������(ʣ��%d��)��", count );
        fgets(ps, 10, stdin);
        ps[strcspn(ps, "\n")] = 0; // ȥ�����з�
        if (strcmp(ps, "123456") == 0)
            break;
        count--;
    }
    if (count == 0) {
        printf("\n��������������ޣ������˳�\n");
        system("pause");
        exit(0);
    }
    admin_menu();
}

void admin_menu() {
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t     ��ӭʹ�ù���Աģ�飡\t**\n");//�Ű����� 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.�Ǽ��û���\t\t**\n");
        printf("\t\t\t**\t\t2.ע���û���\t\t**\n");
        printf("\t\t\t**\t\t3.��ʾ�û��� \t\t**\n"); 
        printf("\t\t\t**\t\t4.�����¼   \t\t**\n");
        printf("\t\t\t**\t\t5.�޸��û��� \t\t**\n");
        printf("\t\t\t**\t\t6.�˳�\t\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                admin_update();
                break;
            case 2:
                admin_delete();
                break;
            case 3:
            	admin_output();
				break;
			case 4:
				admin_sort(); 
			case 5:
				admin_cha(); 
            case 6:
                writefile_com();
                writefile_A();
                writefile_B();
                printf("\t\t\t��л���ʣ��˳��С�\n");
                system("pause");
				menu();
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }
}

void admin_update() {
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t ѡ���������ӵ��ſ�����\t\t**\n");
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.С����\t\t**\n");
        printf("\t\t\t**\t\t2.¥��\t\t\t**\n");//�Ű����� 
        printf("\t\t\t**\t\t3.�˳�\t\t\t**\n");//�Ű�����        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//����һ��* 
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                community();
                break;
            case 2:
                building();
                break;
            case 3:
                printf("�˳��С�\n");
                return;
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }
}

void community() {
    system("cls");
    printf("\t\t\t\t******С�����ŵǼ�******\n");//�Ű� 
    printf("\n");
    printf("\t\t\t\t    ���������û���Ϣ\n\n");//�Ű� 
    printf("\t\t\t\t    �������û�������");//�Ű� 
    scanf("%s", com[n1].name);
    printf("\t\t\t\t    �������û��绰��");//�Ű� 
    scanf("%s", com[n1].tel);
    printf("\t\t\t\t    �������û�С���ſ��ţ�");//�Ű� 
    scanf("%s", com[n1].id);
    n1++;
    int choice;
    printf("\n\t\t\t\t    �Ƿ������ӣ�����-1/��-2��\n");//�Ű棬ǰ�����ӿհ���
    scanf("%d", &choice);
    fflush(stdin);
    switch (choice) {
        case 1:
            community();
            break;
        case 2:
            writefile_com();
            return ;
        default:
            printf("����������������룡\n");
    }
}

void building() {
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t    ѡ���������ӵ�¥��\t\t**\n");//�Ű� 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.A¥\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t2.B¥\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t3.�˳�\t\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//��* 
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                A_add();
                break;
            case 2:
                B_add();
                break;
            case 3:
                printf("�˳��С�\n");
                return;
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }
}

void A_add() {
    system("cls");
    printf("\t\t\t\t******A¥���ŵǼ�******\n");//�Ű� 
    printf("\n");
    printf("\t\t\t\t    ���������û���Ϣ\n\n");//�Ű� 
    printf("\t\t\t\t    �������û�������");//�Ű� 
    scanf("%s", A[n2].name);
    printf("\t\t\t\t    �������û��绰��");//�Ű� 
    scanf("%s", A[n2].tel);
    printf("\t\t\t\t    �������û�A¥�ſ��ţ�");//�Ű� 
    scanf("%s", A[n2].id);
    n2++;
    int choice;
    printf("\n\t\t\t\t    �Ƿ������ӣ�����-1/��-2��\n");//�����Ű�
    scanf("%d", &choice);
    fflush(stdin);
    switch (choice) {
        case 1:
            A_add();
            break;
        case 2:
            readfile_A(); 
            return ;
        default:
            printf("����������������룡\n");
    }
}

void B_add() {
    system("cls");
    printf("\t\t\t\t******B¥���ŵǼ�******\n");//ͬA¥ 
    printf("\n");
    printf("\t\t\t\t    ���������û���Ϣ\n\n");
    printf("\t\t\t\t    �������û�������");
    scanf("%s", B[n3].name);
    printf("\t\t\t\t    �������û��绰��");
    scanf("%s", B[n3].tel);
    printf("\t\t\t\t    �������û�B¥�ſ��ţ�");
    scanf("%s", B[n3].id);
    n3++;
    int choice;
    printf("\n\t\t\t\t    �Ƿ������ӣ�����-1/��-2��\n");
    scanf("%d", &choice);
    fflush(stdin);
    switch (choice) {
        case 1:
            B_add();
            break;
        case 2:
            readfile_B(); 
            return ;
        default:
            printf("����������������룡\n");
    }
}


void admin_delete(){
	system("cls");
	int choice;
	while(1){
		printf("\t\t\t******��ӭʹ��ɾ������******\n");
		printf("\n\t\t\t\t1.ɾ������\n");
		printf("\t\t\t\t2.�����/¥�������ã���\n");
		printf("\t\t\t\t3.�˳��ù���\n\n") ;//����
		printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice){
			case 1:{
				per_delete(); 
				break;
			}
			case 2:{
				empty();
				break;
			}
			case 3:{
				printf("�˳��С�"); 
				return;
			}
			default:{
				printf("����������������룡"); 
			}
		} 
		system("pause");
		system("cls");
	}
	return;	
}

void per_delete() {
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t   ѡ������ɾ�����û��ſ�  \t**\n");//�Ű� 
        printf("\t\t\t**                      \t\t**\n");//
        printf("\t\t\t**\t\t1.С����\t\t**\n");
        printf("\t\t\t**\t\t2.¥��\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t3.�˳�\t\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//��* 
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                __community();
                break;
            case 2:
                __building();
                break;
            case 3:
                printf("�˳��С�\n");
                return;
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }
}

void __community() {
    system("cls");
    char nam[15];
    int choice;
    printf("����������ɾ�����û�������ȫ����:\n");
    scanf("%s", nam);
    for (int i = 0; i < n1; i++) {
        if (strcmp(com[i].name, nam) == 0) {
            printf("\t\t\t��ȷ��Ҫɾ�������û���\n");
            printf("\n");
            printf("\t\t**********************************\n");
            printf("\t\t\t������%s\n", com[i].name);
            printf("\t\t\t�绰��%s\n", com[i].tel);
            printf("\t\t\t���ţ�%s\n", com[i].id);
            printf("\t\t**********************************\n");
            printf("\t\t\tȷ��ɾ�����޷��ָ���������-1/��-2��\n");
            scanf("%d", &choice);
            fflush(stdin);
            switch (choice) {
                case 1:
                    for (int j = i; j < n1 - 1; j++) {
                        com[j] = com[j + 1];
                    }
                    n1--;
                    printf("\t\t\tɾ���ɹ���\n");
                    return;
                case 2:
                    printf("�˳��С�\n");
                    return;
            }
        }
    }
    printf("δ�ҵ����û���\n");
}

void __building() {
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t    ѡ������ɾ�����ſ�  \t**\n");//�Ű� 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t  1.A¥\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t  2.B¥\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t  3.�˳�\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//��*
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                __A();
                break;
            case 2:
                __B();
                break;
            case 3:
                printf("�˳��С�\n");
                return;
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }
}


void __A() {
    system("cls");
    char nam[15];
    int choice;
    printf("����������ɾ�����û�������ȫ����:\n");
    scanf("%s", nam);
    for (int i = 0; i < n2; i++) {
        if (strcmp(A[i].name, nam) == 0) {
            printf("\t\t\t��ȷ��Ҫɾ�������û���\n");
            printf("\n");
            printf("\t\t**********************************\n");
            printf("\t\t\t������%s\n", A[i].name);
            printf("\t\t\t�绰��%s\n", A[i].tel);
            printf("\t\t\t���ţ�%s\n", A[i].id);
            printf("\t\t**********************************\n");
            printf("\t\t\tȷ��ɾ�����޷��ָ���������-1/��-2��\n");
            scanf("%d", &choice);
            fflush(stdin);
            switch (choice) {
                case 1:
                    for (int j = i; j < n2 - 1; j++) {
                        A[j] = A[j + 1];
                    }
                    n1--;
                    printf("\t\t\tɾ���ɹ���\n");
                    return;
                case 2:
                    printf("�˳��С�\n");
                    return;
            }
        }
    }
    printf("δ�ҵ����û���\n");
}


void __B() {
    system("cls");
    char nam[15];
    int choice;
    printf("����������ɾ�����û�������ȫ����:\n");
    scanf("%s", nam);
    for (int i = 0; i < n3; i++) {
        if (strcmp(B[i].name, nam) == 0) {
            printf("\t\t\t��ȷ��Ҫɾ�������û���\n");
            printf("\n");
            printf("\t\t**********************************\n");
            printf("\t\t\t������%s\n", B[i].name);
            printf("\t\t\t�绰��%s\n", B[i].tel);
            printf("\t\t\t���ţ�%s\n", B[i].id);
            printf("\t\t**********************************\n");
            printf("\t\t\tȷ��ɾ�����޷��ָ���������-1/��-2��\n");
            scanf("%d", &choice);
            fflush(stdin);
            switch (choice) {
                case 1:
                    for (int j = i; j < n3 - 1; j++) {
                        B[j] = B[j + 1];
                    }
                    n1--;
                    printf("\t\t\tɾ���ɹ���\n");
                    return;
                case 2:
                    printf("�˳��С�\n");
                    return;
            }
        }
    }
    printf("δ�ҵ����û���\n");
}


void empty(){
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t  ѡ��������յ�С��/¥�� \t**\n");//�Ű� 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.С����\t\t**\n");
        printf("\t\t\t**\t\t2.¥��\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t3.�˳�\t\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//��*
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                empty_com();
                break;
            case 2:
                empty_building();
                break;
            case 3:
                printf("�˳��С�\n");
                return;
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }	
}
void empty_com(){
	int choice; 
	system("cls");
	printf("\t\t\tȷ��ɾ�����޷��ָ���������-1/��-2��\n");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice){
		case 1:{
			fclose(c);
			if((c=fopen("com.txt","w"))==NULL){
				printf("\t\t\t�ļ������ڣ�ɾ��ʧ�ܡ�\n");
				readfile_com();
			}
			n1=0;
			printf("\t\t\tɾ���ɹ���\n");
			return;
		}
		case 2:{
			printf("�˳��С�"); 
			return;
		}
	} 	
}
void empty_building(){
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t      ѡ��������յ���  \t**\n");//�Ű� 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t  1.A¥\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t  2.B¥\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t  3.�˳�\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//��*
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                empty__A();
                break;
            case 2:
                empty__B();
                break;
            case 3:
                printf("�˳��С�\n");
                return;
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }	
}
void empty__A(){
	int choice; 
	system("cls");
	printf("\t\t\tȷ��ɾ�����޷��ָ���������-1/��-2��\n");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice){
		case 1:{
			fclose(b_a);
			if((b_a=fopen("A.txt","w"))==NULL){
				printf("\t\t\t�ļ������ڣ�ɾ��ʧ�ܡ�\n");
				readfile_A();
			}
			n2=0;
			printf("\t\t\tɾ���ɹ���\n");
			return;
		}
		case 2:{
			printf("�˳��С�"); 
			return;
		}
	} 	
}
void empty__B(){
	int choice; 
	system("cls");
	printf("\t\t\tȷ��ɾ�����޷��ָ���������-1/��-2��\n");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice){
		case 1:{
			fclose(b_b);
			if((b_b=fopen("B.txt","w"))==NULL){
				printf("\t\t\t�ļ������ڣ�ɾ��ʧ�ܡ�\n");
				readfile_B();
			}
			n3=0;
			printf("\t\t\tɾ���ɹ���\n");
			return;
		}
		case 2:{
			printf("�˳��С�"); 
			return;
		}
	} 	
}


void admin_output(){
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t  ѡ��������ʾ��С��/¥�� \t**\n");//�Ű� 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.С����\t\t**\n");
        printf("\t\t\t**\t\t2.¥��\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t3.�˳�\t\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//��*
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                out_com();
                break;
            case 2:
                out_building();
                break;
            case 3:
                printf("�˳��С�\n");
                return;
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }	
}
void out_com(){
	system("cls"); 
	printf("\t\t\t\t******С����******\n");
	printf("\t-------------------------------------------------\n");
	if(n1!=0){
		for(int i=0;i<n1;i++){
			printf("\t\t\t����:%s\n",com[i].name); 
			printf("\t\t\t�绰:%s\n",com[i].tel); 
			printf("\t\t\t����:%s\n",com[i].id); 
			printf("\t\t\t����С������ʱ�䣺%s\n",com[i].time) ;
			printf("\t-------------------------------------------------\n");
		}
	}else{
		printf("\t\t\t�޴洢����\n");
		printf("\t-------------------------------------------------\n");
	}
	return; 
	
}

void out_building(){
	system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t     ѡ��������ʾ����  \t\t**\n");//�Ű� 
        printf("\t\t\t**                      \t\t**\n"); 
        printf("\t\t\t**\t\t 1.A¥\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t 2.B¥\t\t\t**\n");//�Ű�
        printf("\t\t\t**\t\t 3.�˳�\t\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//��* 
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                out_A();
                break;
            case 2:
                out_B();
                break;
            case 3:
                printf("�˳��С�\n");
                return;
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }	
}
void out_A(){
	system("cls"); 
	printf("\t\t\t\t******A¥��******\n");
	printf("\t-------------------------------------------------\n");
	if(n2!=0){
		for(int i=0;i<n2;i++){
			printf("\t\t\t����:%s\n",A[i].name); 
			printf("\t\t\t�绰:%s\n",A[i].tel); 
			printf("\t\t\t����:%s\n",A[i].id); 
			printf("\t\t\t����A¥����ʱ�䣺%s\n",A[i].time) ;
			printf("\t-------------------------------------------------\n");
		}
	}else{
		printf("\t\t\t�޴洢����\n");
		printf("\t-------------------------------------------------\n");
	}
	return; 
		
} 
void out_B(){
	system("cls"); 
	printf("\t\t\t\t******B¥��******\n");
	printf("\t-------------------------------------------------\n");
	if(n3!=0){
		for(int i=0;i<n3;i++){
			printf("\t\t\t����:%s\n",B[i].name); 
			printf("\t\t\t�绰:%s\n",B[i].tel); 
			printf("\t\t\t����:%s\n",B[i].id); 
			printf("\t\t\t����B¥����ʱ�䣺%s\n",B[i].time) ;
			printf("\t-------------------------------------------------\n");
		}
	}else{
		printf("\t\t\t�޴洢����\n");
		printf("\t-------------------------------------------------\n");
	}
	return; 
		
}

void admin_sort(){
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t    С��/¥�ſ���ʱ���¼ \t**\n");//�Ű� 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t  1.С����\t\t**\n");
        printf("\t\t\t**\t\t  2.¥��\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t  3.�˳�\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//��* 
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                sort_com();
                break;
            case 2:
                sort_building();
                break;
            case 3:
                printf("�˳��С�\n");
                system("pause");
                admin_menu();
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }	
} 

void sort_com(){
	Com m;
	for(int i=0;i<n1-1;i++){
		for(int j=0;j<n1-1-i;j++){
			if(strcmp(com[j].time,com[j+1].time)<0){
				m=com[j];
				com[j]=com[j+1];
				com[j+1]=m; 
			}
		}
	}
	system("cls"); 
	printf("\t\t\t\t******�������С����¼******\n");
	printf("\t-------------------------------------------------\n");
	if(n1!=0){
		for(int i=0;i<n1;i++){
			if(strlen(com[i].time)!=0){
				printf("\t\t\t����:%s\n",com[i].name); 
				printf("\t\t\t�绰:%s\n",com[i].tel); 
				printf("\t\t\tС������:%s\n",com[i].id); 
				printf("\t\t\tʱ��:%s\n",com[i].time); 
				printf("\t-------------------------------------------------\n");
			}
			
		}
	}else{
		printf("\t\t\t�޴洢����\n");
		printf("\t-------------------------------------------------\n");
	} 
	return; 
}

void sort_building(){
	system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t      ¥�ſ���ʱ���¼  \t**\n");//�Ű� 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t  1.A¥\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t  2.B¥\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t  3.�˳�\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//��* 
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                sort_A();
                break;
            case 2:
                sort_B();
                break;
            case 3:
                printf("�˳��С�\n");
                return;
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }	
}

void sort_A(){
	Bui_A m;
	for(int i=0;i<n2-1;i++){
		for(int j=0;j<n2-1-i;j++){
			if(strcmp(A[j].time,A[j+1].time)<0){
				m=A[j];
				A[j]=A[j+1];
				A[j+1]=m; 
			}
		}
	}
	system("cls"); 
	printf("\t\t\t\t******�������С����¼******\n");
	printf("\t-------------------------------------------------\n");
	if(n2!=0){
		for(int i=0;i<n2;i++){
			if(strlen(A[i].time)!=0){
				printf("\t\t\t����:%s\n",A[i].name); 
				printf("\t\t\t�绰:%s\n",A[i].tel); 
				printf("\t\t\tС������:%s\n",A[i].id); 
				printf("\t\t\tʱ��:%s\n",A[i].time); 
				printf("\t-------------------------------------------------\n");
			}
			
		}
	}else{
		printf("\t\t\t�޴洢����\n");
		printf("\t-------------------------------------------------\n");
	} 
	return; 
	
}
void sort_B(){
	Bui_B m;
	for(int i=0;i<n3-1;i++){
		for(int j=0;j<n3-i-1;j++){
			if(strcmp(B[j].time,B[j+1].time)<0){
				m=B[j];
				B[j]=B[j+1];
				B[j+1]=m; 
			}
		}
	}
	system("cls"); 
	printf("\t\t\t\t******�������B¥��¼******\n");
	printf("\t-------------------------------------------------\n");
	if(n1!=0){
		for(int i=0;i<n3;i++){
			if(strlen(B[i].time)!=0){
				printf("\t\t\t����:%s\n",B[i].name); 
				printf("\t\t\t�绰:%s\n",B[i].tel); 
				printf("\t\t\tС������:%s\n",B[i].id); 
				printf("\t\t\tʱ��:%s\n",B[i].time); 
				printf("\t-------------------------------------------------\n");
			}
			
		}
	}else{
		printf("\t\t\t�޴洢����\n");
		printf("\t-------------------------------------------------\n");
	} 
	return; 
}

void admin_cha(){
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t    ��ѡ������Ҫ�޸ĵĿ� \t**\n");//�Ű� 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.С����\t\t**\n");
        printf("\t\t\t**\t\t2.¥��\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t3.�˳�\t\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//��* 
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                cha_com();
                break;
            case 2:
                cha_building();
                break;
            case 3:
                printf("�˳��С�\n");
                system("pause");
				admin_menu();
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }		
}
void cha_com(){
	int choice;
	char nam[15];
	printf("\t\t\t������Ҫ�޸ĵ��û�������ȫ����:\n");
	scanf("%s",nam);
	if(n1==0){
		printf("\t\t\t���û���Ϣ���޷������޸ġ�\n");
		return; 
	}
	for(int i=0;i<n1;i++){
		if(strcmp(com[i].name,nam) == 0){
			printf("\n");
			printf("\t\t**********************************\n");
			printf("\t\t\t������%s\n",com[i].name);
			printf("\t\t\t�绰��%s\n",com[i].tel);
			printf("\t\t\t���ţ�%s\n",com[i].id);
			printf("\t\t**********************************\n");
			printf("\t\t\t����Ҫ�޸ĸ��û���ʲô��Ϣ������֧����ʾ����ţ�\n");
			printf("\t\t\t1.����\n");
			printf("\t\t\t2.�绰\n"); 
			printf("\t\t\t3.����\n"); 
			printf("\t\t\t4.�˳�\n"); 
			scanf("%d",&choice);
			fflush(stdin); 
			switch(choice){
				case 1:{
					printf("\t\t\t������������\n");
					scanf("%s",&com[i].name);
					printf("�ѽ�������Ϊ%s��\n",com[i].name);
					system("pause");
					admin_menu();
					break;
				}
				case 2:{
					printf("\t\t\t������绰��\n");
					scanf("%s",&com[i].tel);
					printf("�ѽ��绰��Ϊ%s��\n",com[i].tel);
					system("pause");
					admin_menu();
					break;
				}
				case 3:{
					printf("\t\t\t�����뿨�ţ�\n");
					scanf("%s",&com[i].id);
					printf("�ѽ����֤�Ÿ�Ϊ%s��\n",com[i].id);
					system("pause");
					admin_menu();
					break;
				}
				case 4:{
					return; 
				}
			}
		}
	} 	
}
void cha_building(){
	system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t  ��ѡ������Ҫ�޸ĵ�¥��  \t**\n");//�Ű� 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t  1.A¥\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t  2.B¥\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t  3.�˳�\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//��* 
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                cha_A();
                break;
            case 2:
                cha_B();
                break;
            case 3:
                printf("�˳��С�\n");
                return;
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }	
}
void cha_A(){
	system("cls");
	int choice;
	char nam[15];
	printf("\t\t\t������Ҫ�޸ĵ��û�������ȫ����:\n");
	scanf("%s",nam);
	if(n2==0){
		printf("\t\t\t���û���Ϣ���޷������޸ġ�\n");
		return; 
	}
	for(int i=0;i<n2;i++){
		if(strcmp(A[i].name,nam) == 0){
			printf("\n");
			printf("\t\t**********************************\n");
			printf("\t\t\t������%s\n",A[i].name);
			printf("\t\t\t�绰��%s\n",A[i].tel);
			printf("\t\t\t���ţ�%s\n",A[i].id);
			printf("\t\t**********************************\n");
			printf("\t\t\t����Ҫ�޸ĸ��û���ʲô��Ϣ������֧����ʾ����ţ�\n");
			printf("\t\t\t1.����\n");
			printf("\t\t\t2.�绰\n"); 
			printf("\t\t\t3.����\n"); 
			printf("\t\t\t4.�˳�\n"); 
			scanf("%d",&choice);
			fflush(stdin); 
			switch(choice){
				case 1:{
					printf("\t\t\t������������\n");
					scanf("%s",&A[i].name);
					printf("�ѽ�������Ϊ%s��\n",A[i].name);
					system("pause");
					admin_menu();
					break;
				}
				case 2:{
					printf("\t\t\t������绰��\n");
					scanf("%s",&A[i].tel);
					printf("�ѽ��绰��Ϊ%s��\n",A[i].tel);
					system("pause");
					admin_menu();
					break;
				}
				case 3:{
					printf("\t\t\t�����뿨�ţ�\n");
					scanf("%s",&A[i].id);
					printf("�ѽ����֤�Ÿ�Ϊ%s��\n",A[i].id);
					system("pause");
					admin_menu();
					break;
				}
				case 4:{
					return; 
				}
			}
		}
	} 		
	
} 
void cha_B(){
	system("cls");
	int choice;
	char nam[15];
	printf("\t\t\t������Ҫ�޸ĵ��û�������ȫ����:\n");
	scanf("%s",nam);
	if(n3==0){
		printf("\t\t\t���û���Ϣ���޷������޸ġ�\n");
		return; 
	}
	for(int i=0;i<n3;i++){
		if(strcmp(B[i].name,nam) == 0){
			printf("\n");
			printf("\t\t**********************************\n");
			printf("\t\t\t������%s\n",B[i].name);
			printf("\t\t\t�绰��%s\n",B[i].tel);
			printf("\t\t\t���ţ�%s\n",B[i].id);
			printf("\t\t**********************************\n");
			printf("\t\t\t����Ҫ�޸ĸ��û���ʲô��Ϣ������֧����ʾ����ţ�\n");
			printf("\t\t\t1.����\n");
			printf("\t\t\t2.�绰\n"); 
			printf("\t\t\t3.����\n"); 
			printf("\t\t\t4.�˳�\n"); 
			scanf("%d",&choice);
			fflush(stdin); 
			switch(choice){
				case 1:{
					printf("\t\t\t������������\n");
					scanf("%s",&B[i].name);
					printf("�ѽ�������Ϊ%s��\n",B[i].name);
					system("pause");
					admin_menu();
					break;
				}
				case 2:{
					printf("\t\t\t������绰��\n");
					scanf("%s",&B[i].tel);
					printf("�ѽ��绰��Ϊ%s��\n",B[i].tel);
					system("pause");
					admin_menu();
					break;
				}
				case 3:{
					printf("\t\t\t�����뿨�ţ�\n");
					scanf("%s",&B[i].id);
					printf("�ѽ����֤�Ÿ�Ϊ%s��\n",B[i].id);
					system("pause");
					admin_menu();
					break;
				}
				case 4:{
					return; 
				}
			}
		}
	} 	
	
}












void user_password() {
    system("cls");
    char id[20];
    printf("\t\t��ӭ��������С������ҵ���������Ŀ��Ŵ�С����\n");
    scanf("%s", id);
    for (int i = 0; i < n1; i++) {
        if (strcmp(com[i].id, id) == 0) {
            time_t now = time(NULL);
    		strftime(com[i].time, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    		printf("��ӭ�ؼң�С�����Ѵ򿪣�ʱ�䣺%s\n", com[i].time);
			system("pause");
			user_menu();
        }
    }
    printf("������Ч�������ԡ�\n");
    system("pause");
}

void user_menu() {
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t      ��ӭʹ���û�ģ�飡\t**\n");//�Ű� 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.��¥��\t\t**\n");
        printf("\t\t\t**\t\t2.�˳�\t\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//��*
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                user_building();
                break;
            case 2:
                system("pause");
            	menu();
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }
}

void user_building() {
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t      ��ѡ������¥��\t\t**\n");//�Ű� 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t  1.A¥\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t  2.B¥\t\t\t**\n");//�Ű� 
        printf("\t\t\t**\t\t  3.�˳�\t\t**\n");//�Ű�        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//��* 
        printf("������������ʵ�ģ�����:����֧����ʾ����ţ�\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                user_A();
                break;
            case 2:
                user_B();
                break;
            case 3:
                system("pause");
            	menu();
            default:
                printf("����������������롣\n");
        }
        system("pause");
        system("cls");
    }
}

void user_A() {
    system("cls");
    char id[20];
    printf("����������A¥�ſ��ţ�\n");
    scanf("%s", id);
    for (int i = 0; i < n2; i++) {
        if (strcmp(A[i].id, id) == 0) {
            time_t now = time(NULL);
    		strftime(A[i].time, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    		printf("��ӭ�ؼң�A¥���Ѵ򿪣�ʱ�䣺%s\n", A[i].time);
    		writefile_A();
    		system("pause");
            menu();
        }
    }
    printf("������Ч�������ԡ�\n");
}

void user_B() {
    system("cls");
    char id[20];
    printf("����������B¥�ſ��ţ�\n");
    scanf("%s", id);
    for (int i = 0; i < n3; i++) {
        if (strcmp(B[i].id, id) == 0) {
            time_t now = time(NULL);
    		strftime(B[i].time, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    		printf("��ӭ�ؼң�B¥���Ѵ򿪣�ʱ�䣺%s\n", B[i].time);
    		writefile_B();
    		system("pause");
    		menu();
        }
    }
    printf("������Ч�������ԡ�\n");
}




int main() {
    readfile_com();
    readfile_A();
    readfile_B();
    while(1){
    	menu();
	}
    return 0;
}
