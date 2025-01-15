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

FILE *c; // 小区门内存储信息
FILE *b_a; // 楼门存储信息
FILE *b_b; // 楼门存储信息

void menu(); // 总菜单
void admin_password(); // 管理员输入密码
void admin_menu(); // 管理员菜单
void admin_update(); // 管理员内部用户更新
void admin_delete(); // 管理员删除用户
void admin_output();//管理员显示登记用户 
void admin_cha();//修改用户信息 
void out_com();
void out_building();
void out_A();
void out_B();
void admin_sort();//时间排序 
void sort_com();
void sort_building();
void sort_A();
void sort_B();
void community();//小区加人 
void building();
void A_add(); // A楼加人
void B_add(); // B楼加人
void per_delete();//单个删除 
void __community(); //小区门减人 
void __building();//楼门减人 
void __A();//A减 
void __B();//B减 
void empty(); //清空 
void empty_com();//清空小区登记 
void empty_building();//清空楼登记 
void empty__A();//清空A 
void empty__B();//清空B 
void cha_com(); 
void cha_building();
void cha_A();
void cha_B();


void user_menu();
void user_password(); // 用户输入卡号打开小区门
void user_building(); // 用户选择楼门
void user_A(); // 用户开A楼门
void user_B(); // 用户开B楼门
void com_time(); 
void A_time(); // A楼开门时间
void B_time(); // B楼开门时间
void readfile_com();
void readfile_A(); // 读取文件
void readfile_B();
void writefile_com();
void writefile_A(); // 写入文件
void writefile_B();





void readfile_com() {
    if((c=fopen("com.txt","r"))==NULL){
		printf("\t\t\t打开失败！未查询到文件。\n");
        exit(0);
    }
    while(!feof(c) && fread(&com[n1],sizeof(struct Com),1,c)){
    		n1++;
		}
}
void readfile_A() {
    if((b_a=fopen("A.txt","r"))==NULL){
		printf("\t\t\t打开失败！未查询到文件。\n");
        exit(0);
    }
    while(!feof(b_a) && fread(&A[n2],sizeof(struct Bui_A),1,b_a)){
    		n2++;
		}
}
void readfile_B() {
    if((b_b=fopen("B.txt","r"))==NULL){
		printf("\t\t\t打开失败！未查询到文件。\n");
        exit(0);
    }
    while(!feof(b_b) && fread(&B[n3],sizeof(struct Bui_B),1,b_b)){
    		n3++;
		}
}



void writefile_com(){
    if ((c=fopen("com.txt","w"))==NULL){
        printf("\t\t\t打开失败");
    }for(int i=0;i<n1;i++){
        if(fwrite(&com[i],sizeof(struct Com),1,c)!=1){
            printf("\t\t\t文件更新失败\n");
        }
    }
	fclose(c);
}
void writefile_A(){
    if ((b_a=fopen("A.txt","w"))==NULL){
        printf("\t\t\t打开失败");
    }for(int i=0;i<n2;i++){
        if(fwrite(&A[i],sizeof(struct Bui_A),1,b_a)!=1){
            printf("\t\t\t文件更新失败\n");
        }
    }
	fclose(b_a);
}
void writefile_B(){
    if ((b_b=fopen("B.txt","w"))==NULL){
        printf("\t\t\t打开失败");
    }for(int i=0;i<n3;i++){
        if(fwrite(&B[i],sizeof(struct Bui_B),1,b_b)!=1){
            printf("\t\t\t文件更新失败\n");
        }
    }
	fclose(b_b);
}










void menu() {
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t    欢迎使用门禁管理系统！  \t**\n");//排版问题 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.管理员登录\t\t**\n");
        printf("\t\t\t**\t\t2.用户登录\t\t**\n");
        printf("\t\t\t**\t\t3.退出系统\t\t**\n");        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多了一个*
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("\t\t\t感谢访问，退出中…\n");
                exit(0);
            default:
                printf("输入错误，请重新输入。\n");
        }
        system("pause");
        system("cls");
    }
}

void admin_password() {
    int count = 3;
    char ps[10];
    printf("请输入密码:\n");
    fgets(ps, 10, stdin);
    ps[strcspn(ps, "\n")] = 0; // 去除换行符
    while (count && strcmp(ps, "123456") != 0) {
        printf("\n密码错误！请重新输入(剩余%d次)：", count );
        fgets(ps, 10, stdin);
        ps[strcspn(ps, "\n")] = 0; // 去除换行符
        if (strcmp(ps, "123456") == 0)
            break;
        count--;
    }
    if (count == 0) {
        printf("\n错误次数超过上限，程序退出\n");
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
        printf("\t\t\t**\t     欢迎使用管理员模块！\t**\n");//排版问题 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.登记用户卡\t\t**\n");
        printf("\t\t\t**\t\t2.注销用户卡\t\t**\n");
        printf("\t\t\t**\t\t3.显示用户卡 \t\t**\n"); 
        printf("\t\t\t**\t\t4.最近记录   \t\t**\n");
        printf("\t\t\t**\t\t5.修改用户卡 \t\t**\n");
        printf("\t\t\t**\t\t6.退出\t\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("\t\t\t感谢访问，退出中…\n");
                system("pause");
				menu();
            default:
                printf("输入错误，请重新输入。\n");
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
        printf("\t\t\t**\t 选择您想增加的门卡类型\t\t**\n");
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.小区门\t\t**\n");
        printf("\t\t\t**\t\t2.楼门\t\t\t**\n");//排版问题 
        printf("\t\t\t**\t\t3.退出\t\t\t**\n");//排版问题        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多了一个* 
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("退出中…\n");
                return;
            default:
                printf("输入错误，请重新输入。\n");
        }
        system("pause");
        system("cls");
    }
}

void community() {
    system("cls");
    printf("\t\t\t\t******小区卡号登记******\n");//排版 
    printf("\n");
    printf("\t\t\t\t    请输入新用户信息\n\n");//排版 
    printf("\t\t\t\t    请输入用户姓名：");//排版 
    scanf("%s", com[n1].name);
    printf("\t\t\t\t    请输入用户电话：");//排版 
    scanf("%s", com[n1].tel);
    printf("\t\t\t\t    请输入用户小区门卡号：");//排版 
    scanf("%s", com[n1].id);
    n1++;
    int choice;
    printf("\n\t\t\t\t    是否继续添加？（是-1/否-2）\n");//排版，前面增加空白行
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
            printf("输入错误请重新输入！\n");
    }
}

void building() {
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t    选择您想增加的楼号\t\t**\n");//排版 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.A楼\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t2.B楼\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t3.退出\t\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多* 
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("退出中…\n");
                return;
            default:
                printf("输入错误，请重新输入。\n");
        }
        system("pause");
        system("cls");
    }
}

void A_add() {
    system("cls");
    printf("\t\t\t\t******A楼卡号登记******\n");//排版 
    printf("\n");
    printf("\t\t\t\t    请输入新用户信息\n\n");//排版 
    printf("\t\t\t\t    请输入用户姓名：");//排版 
    scanf("%s", A[n2].name);
    printf("\t\t\t\t    请输入用户电话：");//排版 
    scanf("%s", A[n2].tel);
    printf("\t\t\t\t    请输入用户A楼门卡号：");//排版 
    scanf("%s", A[n2].id);
    n2++;
    int choice;
    printf("\n\t\t\t\t    是否继续添加？（是-1/否-2）\n");//增行排版
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
            printf("输入错误请重新输入！\n");
    }
}

void B_add() {
    system("cls");
    printf("\t\t\t\t******B楼卡号登记******\n");//同A楼 
    printf("\n");
    printf("\t\t\t\t    请输入新用户信息\n\n");
    printf("\t\t\t\t    请输入用户姓名：");
    scanf("%s", B[n3].name);
    printf("\t\t\t\t    请输入用户电话：");
    scanf("%s", B[n3].tel);
    printf("\t\t\t\t    请输入用户B楼门卡号：");
    scanf("%s", B[n3].id);
    n3++;
    int choice;
    printf("\n\t\t\t\t    是否继续添加？（是-1/否-2）\n");
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
            printf("输入错误请重新输入！\n");
    }
}


void admin_delete(){
	system("cls");
	int choice;
	while(1){
		printf("\t\t\t******欢迎使用删除功能******\n");
		printf("\n\t\t\t\t1.删除个人\n");
		printf("\t\t\t\t2.清空门/楼卡（慎用！）\n");
		printf("\t\t\t\t3.退出该功能\n\n") ;//增行
		printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
				printf("退出中…"); 
				return;
			}
			default:{
				printf("输入错误请重新输入！"); 
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
        printf("\t\t\t**\t   选择您想删除的用户门卡  \t**\n");//排版 
        printf("\t\t\t**                      \t\t**\n");//
        printf("\t\t\t**\t\t1.小区门\t\t**\n");
        printf("\t\t\t**\t\t2.楼门\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t3.退出\t\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多* 
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("退出中…\n");
                return;
            default:
                printf("输入错误，请重新输入。\n");
        }
        system("pause");
        system("cls");
    }
}

void __community() {
    system("cls");
    char nam[15];
    int choice;
    printf("请输入您想删除的用户姓名（全名）:\n");
    scanf("%s", nam);
    for (int i = 0; i < n1; i++) {
        if (strcmp(com[i].name, nam) == 0) {
            printf("\t\t\t您确定要删除下列用户吗？\n");
            printf("\n");
            printf("\t\t**********************************\n");
            printf("\t\t\t姓名：%s\n", com[i].name);
            printf("\t\t\t电话：%s\n", com[i].tel);
            printf("\t\t\t卡号：%s\n", com[i].id);
            printf("\t\t**********************************\n");
            printf("\t\t\t确认删除？无法恢复！！（是-1/否-2）\n");
            scanf("%d", &choice);
            fflush(stdin);
            switch (choice) {
                case 1:
                    for (int j = i; j < n1 - 1; j++) {
                        com[j] = com[j + 1];
                    }
                    n1--;
                    printf("\t\t\t删除成功！\n");
                    return;
                case 2:
                    printf("退出中…\n");
                    return;
            }
        }
    }
    printf("未找到该用户。\n");
}

void __building() {
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t    选择您想删除的门卡  \t**\n");//排版 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t  1.A楼\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t  2.B楼\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t  3.退出\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多*
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("退出中…\n");
                return;
            default:
                printf("输入错误，请重新输入。\n");
        }
        system("pause");
        system("cls");
    }
}


void __A() {
    system("cls");
    char nam[15];
    int choice;
    printf("请输入您想删除的用户姓名（全名）:\n");
    scanf("%s", nam);
    for (int i = 0; i < n2; i++) {
        if (strcmp(A[i].name, nam) == 0) {
            printf("\t\t\t您确定要删除下列用户吗？\n");
            printf("\n");
            printf("\t\t**********************************\n");
            printf("\t\t\t姓名：%s\n", A[i].name);
            printf("\t\t\t电话：%s\n", A[i].tel);
            printf("\t\t\t卡号：%s\n", A[i].id);
            printf("\t\t**********************************\n");
            printf("\t\t\t确认删除？无法恢复！！（是-1/否-2）\n");
            scanf("%d", &choice);
            fflush(stdin);
            switch (choice) {
                case 1:
                    for (int j = i; j < n2 - 1; j++) {
                        A[j] = A[j + 1];
                    }
                    n1--;
                    printf("\t\t\t删除成功！\n");
                    return;
                case 2:
                    printf("退出中…\n");
                    return;
            }
        }
    }
    printf("未找到该用户。\n");
}


void __B() {
    system("cls");
    char nam[15];
    int choice;
    printf("请输入您想删除的用户姓名（全名）:\n");
    scanf("%s", nam);
    for (int i = 0; i < n3; i++) {
        if (strcmp(B[i].name, nam) == 0) {
            printf("\t\t\t您确定要删除下列用户吗？\n");
            printf("\n");
            printf("\t\t**********************************\n");
            printf("\t\t\t姓名：%s\n", B[i].name);
            printf("\t\t\t电话：%s\n", B[i].tel);
            printf("\t\t\t卡号：%s\n", B[i].id);
            printf("\t\t**********************************\n");
            printf("\t\t\t确认删除？无法恢复！！（是-1/否-2）\n");
            scanf("%d", &choice);
            fflush(stdin);
            switch (choice) {
                case 1:
                    for (int j = i; j < n3 - 1; j++) {
                        B[j] = B[j + 1];
                    }
                    n1--;
                    printf("\t\t\t删除成功！\n");
                    return;
                case 2:
                    printf("退出中…\n");
                    return;
            }
        }
    }
    printf("未找到该用户。\n");
}


void empty(){
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t  选择您想清空的小区/楼门 \t**\n");//排版 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.小区门\t\t**\n");
        printf("\t\t\t**\t\t2.楼门\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t3.退出\t\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多*
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("退出中…\n");
                return;
            default:
                printf("输入错误，请重新输入。\n");
        }
        system("pause");
        system("cls");
    }	
}
void empty_com(){
	int choice; 
	system("cls");
	printf("\t\t\t确认删除？无法恢复！！（是-1/否-2）\n");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice){
		case 1:{
			fclose(c);
			if((c=fopen("com.txt","w"))==NULL){
				printf("\t\t\t文件不存在，删除失败。\n");
				readfile_com();
			}
			n1=0;
			printf("\t\t\t删除成功！\n");
			return;
		}
		case 2:{
			printf("退出中…"); 
			return;
		}
	} 	
}
void empty_building(){
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t      选择您想清空的门  \t**\n");//排版 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t  1.A楼\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t  2.B楼\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t  3.退出\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多*
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("退出中…\n");
                return;
            default:
                printf("输入错误，请重新输入。\n");
        }
        system("pause");
        system("cls");
    }	
}
void empty__A(){
	int choice; 
	system("cls");
	printf("\t\t\t确认删除？无法恢复！！（是-1/否-2）\n");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice){
		case 1:{
			fclose(b_a);
			if((b_a=fopen("A.txt","w"))==NULL){
				printf("\t\t\t文件不存在，删除失败。\n");
				readfile_A();
			}
			n2=0;
			printf("\t\t\t删除成功！\n");
			return;
		}
		case 2:{
			printf("退出中…"); 
			return;
		}
	} 	
}
void empty__B(){
	int choice; 
	system("cls");
	printf("\t\t\t确认删除？无法恢复！！（是-1/否-2）\n");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice){
		case 1:{
			fclose(b_b);
			if((b_b=fopen("B.txt","w"))==NULL){
				printf("\t\t\t文件不存在，删除失败。\n");
				readfile_B();
			}
			n3=0;
			printf("\t\t\t删除成功！\n");
			return;
		}
		case 2:{
			printf("退出中…"); 
			return;
		}
	} 	
}


void admin_output(){
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t  选择您想显示的小区/楼门 \t**\n");//排版 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.小区门\t\t**\n");
        printf("\t\t\t**\t\t2.楼门\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t3.退出\t\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多*
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("退出中…\n");
                return;
            default:
                printf("输入错误，请重新输入。\n");
        }
        system("pause");
        system("cls");
    }	
}
void out_com(){
	system("cls"); 
	printf("\t\t\t\t******小区门******\n");
	printf("\t-------------------------------------------------\n");
	if(n1!=0){
		for(int i=0;i<n1;i++){
			printf("\t\t\t姓名:%s\n",com[i].name); 
			printf("\t\t\t电话:%s\n",com[i].tel); 
			printf("\t\t\t卡号:%s\n",com[i].id); 
			printf("\t\t\t进入小区最新时间：%s\n",com[i].time) ;
			printf("\t-------------------------------------------------\n");
		}
	}else{
		printf("\t\t\t无存储内容\n");
		printf("\t-------------------------------------------------\n");
	}
	return; 
	
}

void out_building(){
	system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t     选择您想显示的门  \t\t**\n");//排版 
        printf("\t\t\t**                      \t\t**\n"); 
        printf("\t\t\t**\t\t 1.A楼\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t 2.B楼\t\t\t**\n");//排版
        printf("\t\t\t**\t\t 3.退出\t\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多* 
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("退出中…\n");
                return;
            default:
                printf("输入错误，请重新输入。\n");
        }
        system("pause");
        system("cls");
    }	
}
void out_A(){
	system("cls"); 
	printf("\t\t\t\t******A楼门******\n");
	printf("\t-------------------------------------------------\n");
	if(n2!=0){
		for(int i=0;i<n2;i++){
			printf("\t\t\t姓名:%s\n",A[i].name); 
			printf("\t\t\t电话:%s\n",A[i].tel); 
			printf("\t\t\t卡号:%s\n",A[i].id); 
			printf("\t\t\t进入A楼最新时间：%s\n",A[i].time) ;
			printf("\t-------------------------------------------------\n");
		}
	}else{
		printf("\t\t\t无存储内容\n");
		printf("\t-------------------------------------------------\n");
	}
	return; 
		
} 
void out_B(){
	system("cls"); 
	printf("\t\t\t\t******B楼门******\n");
	printf("\t-------------------------------------------------\n");
	if(n3!=0){
		for(int i=0;i<n3;i++){
			printf("\t\t\t姓名:%s\n",B[i].name); 
			printf("\t\t\t电话:%s\n",B[i].tel); 
			printf("\t\t\t卡号:%s\n",B[i].id); 
			printf("\t\t\t进入B楼最新时间：%s\n",B[i].time) ;
			printf("\t-------------------------------------------------\n");
		}
	}else{
		printf("\t\t\t无存储内容\n");
		printf("\t-------------------------------------------------\n");
	}
	return; 
		
}

void admin_sort(){
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t    小区/楼门开放时间记录 \t**\n");//排版 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t  1.小区门\t\t**\n");
        printf("\t\t\t**\t\t  2.楼门\t\t**\n");//排版 
        printf("\t\t\t**\t\t  3.退出\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多* 
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("退出中…\n");
                system("pause");
                admin_menu();
            default:
                printf("输入错误，请重新输入。\n");
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
	printf("\t\t\t\t******最近进入小区记录******\n");
	printf("\t-------------------------------------------------\n");
	if(n1!=0){
		for(int i=0;i<n1;i++){
			if(strlen(com[i].time)!=0){
				printf("\t\t\t姓名:%s\n",com[i].name); 
				printf("\t\t\t电话:%s\n",com[i].tel); 
				printf("\t\t\t小区卡号:%s\n",com[i].id); 
				printf("\t\t\t时间:%s\n",com[i].time); 
				printf("\t-------------------------------------------------\n");
			}
			
		}
	}else{
		printf("\t\t\t无存储内容\n");
		printf("\t-------------------------------------------------\n");
	} 
	return; 
}

void sort_building(){
	system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t      楼门开放时间记录  \t**\n");//排版 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t  1.A楼\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t  2.B楼\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t  3.退出\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多* 
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("退出中…\n");
                return;
            default:
                printf("输入错误，请重新输入。\n");
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
	printf("\t\t\t\t******最近进入小区记录******\n");
	printf("\t-------------------------------------------------\n");
	if(n2!=0){
		for(int i=0;i<n2;i++){
			if(strlen(A[i].time)!=0){
				printf("\t\t\t姓名:%s\n",A[i].name); 
				printf("\t\t\t电话:%s\n",A[i].tel); 
				printf("\t\t\t小区卡号:%s\n",A[i].id); 
				printf("\t\t\t时间:%s\n",A[i].time); 
				printf("\t-------------------------------------------------\n");
			}
			
		}
	}else{
		printf("\t\t\t无存储内容\n");
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
	printf("\t\t\t\t******最近进入B楼记录******\n");
	printf("\t-------------------------------------------------\n");
	if(n1!=0){
		for(int i=0;i<n3;i++){
			if(strlen(B[i].time)!=0){
				printf("\t\t\t姓名:%s\n",B[i].name); 
				printf("\t\t\t电话:%s\n",B[i].tel); 
				printf("\t\t\t小区卡号:%s\n",B[i].id); 
				printf("\t\t\t时间:%s\n",B[i].time); 
				printf("\t-------------------------------------------------\n");
			}
			
		}
	}else{
		printf("\t\t\t无存储内容\n");
		printf("\t-------------------------------------------------\n");
	} 
	return; 
}

void admin_cha(){
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t    请选择您需要修改的卡 \t**\n");//排版 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.小区门\t\t**\n");
        printf("\t\t\t**\t\t2.楼门\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t3.退出\t\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多* 
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("退出中…\n");
                system("pause");
				admin_menu();
            default:
                printf("输入错误，请重新输入。\n");
        }
        system("pause");
        system("cls");
    }		
}
void cha_com(){
	int choice;
	char nam[15];
	printf("\t\t\t请输入要修改的用户姓名（全名）:\n");
	scanf("%s",nam);
	if(n1==0){
		printf("\t\t\t无用户信息，无法进行修改。\n");
		return; 
	}
	for(int i=0;i<n1;i++){
		if(strcmp(com[i].name,nam) == 0){
			printf("\n");
			printf("\t\t**********************************\n");
			printf("\t\t\t姓名：%s\n",com[i].name);
			printf("\t\t\t电话：%s\n",com[i].tel);
			printf("\t\t\t卡号：%s\n",com[i].id);
			printf("\t\t**********************************\n");
			printf("\t\t\t您需要修改该用户的什么信息？（仅支持显示的序号）\n");
			printf("\t\t\t1.姓名\n");
			printf("\t\t\t2.电话\n"); 
			printf("\t\t\t3.卡号\n"); 
			printf("\t\t\t4.退出\n"); 
			scanf("%d",&choice);
			fflush(stdin); 
			switch(choice){
				case 1:{
					printf("\t\t\t请输入姓名：\n");
					scanf("%s",&com[i].name);
					printf("已将姓名改为%s！\n",com[i].name);
					system("pause");
					admin_menu();
					break;
				}
				case 2:{
					printf("\t\t\t请输入电话：\n");
					scanf("%s",&com[i].tel);
					printf("已将电话改为%s！\n",com[i].tel);
					system("pause");
					admin_menu();
					break;
				}
				case 3:{
					printf("\t\t\t请输入卡号：\n");
					scanf("%s",&com[i].id);
					printf("已将身份证号改为%s！\n",com[i].id);
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
        printf("\t\t\t**\t  请选择您需要修改的楼门  \t**\n");//排版 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t  1.A楼\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t  2.B楼\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t  3.退出\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多* 
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("退出中…\n");
                return;
            default:
                printf("输入错误，请重新输入。\n");
        }
        system("pause");
        system("cls");
    }	
}
void cha_A(){
	system("cls");
	int choice;
	char nam[15];
	printf("\t\t\t请输入要修改的用户姓名（全名）:\n");
	scanf("%s",nam);
	if(n2==0){
		printf("\t\t\t无用户信息，无法进行修改。\n");
		return; 
	}
	for(int i=0;i<n2;i++){
		if(strcmp(A[i].name,nam) == 0){
			printf("\n");
			printf("\t\t**********************************\n");
			printf("\t\t\t姓名：%s\n",A[i].name);
			printf("\t\t\t电话：%s\n",A[i].tel);
			printf("\t\t\t卡号：%s\n",A[i].id);
			printf("\t\t**********************************\n");
			printf("\t\t\t您需要修改该用户的什么信息？（仅支持显示的序号）\n");
			printf("\t\t\t1.姓名\n");
			printf("\t\t\t2.电话\n"); 
			printf("\t\t\t3.卡号\n"); 
			printf("\t\t\t4.退出\n"); 
			scanf("%d",&choice);
			fflush(stdin); 
			switch(choice){
				case 1:{
					printf("\t\t\t请输入姓名：\n");
					scanf("%s",&A[i].name);
					printf("已将姓名改为%s！\n",A[i].name);
					system("pause");
					admin_menu();
					break;
				}
				case 2:{
					printf("\t\t\t请输入电话：\n");
					scanf("%s",&A[i].tel);
					printf("已将电话改为%s！\n",A[i].tel);
					system("pause");
					admin_menu();
					break;
				}
				case 3:{
					printf("\t\t\t请输入卡号：\n");
					scanf("%s",&A[i].id);
					printf("已将身份证号改为%s！\n",A[i].id);
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
	printf("\t\t\t请输入要修改的用户姓名（全名）:\n");
	scanf("%s",nam);
	if(n3==0){
		printf("\t\t\t无用户信息，无法进行修改。\n");
		return; 
	}
	for(int i=0;i<n3;i++){
		if(strcmp(B[i].name,nam) == 0){
			printf("\n");
			printf("\t\t**********************************\n");
			printf("\t\t\t姓名：%s\n",B[i].name);
			printf("\t\t\t电话：%s\n",B[i].tel);
			printf("\t\t\t卡号：%s\n",B[i].id);
			printf("\t\t**********************************\n");
			printf("\t\t\t您需要修改该用户的什么信息？（仅支持显示的序号）\n");
			printf("\t\t\t1.姓名\n");
			printf("\t\t\t2.电话\n"); 
			printf("\t\t\t3.卡号\n"); 
			printf("\t\t\t4.退出\n"); 
			scanf("%d",&choice);
			fflush(stdin); 
			switch(choice){
				case 1:{
					printf("\t\t\t请输入姓名：\n");
					scanf("%s",&B[i].name);
					printf("已将姓名改为%s！\n",B[i].name);
					system("pause");
					admin_menu();
					break;
				}
				case 2:{
					printf("\t\t\t请输入电话：\n");
					scanf("%s",&B[i].tel);
					printf("已将电话改为%s！\n",B[i].tel);
					system("pause");
					admin_menu();
					break;
				}
				case 3:{
					printf("\t\t\t请输入卡号：\n");
					scanf("%s",&B[i].id);
					printf("已将身份证号改为%s！\n",B[i].id);
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
    printf("\t\t欢迎光临青稞小区，请业主输入您的卡号打开小区门\n");
    scanf("%s", id);
    for (int i = 0; i < n1; i++) {
        if (strcmp(com[i].id, id) == 0) {
            time_t now = time(NULL);
    		strftime(com[i].time, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    		printf("欢迎回家！小区门已打开，时间：%s\n", com[i].time);
			system("pause");
			user_menu();
        }
    }
    printf("卡号无效，请重试。\n");
    system("pause");
}

void user_menu() {
    system("cls");
    int choice;
    while (1) {
        printf("\t\t\t******************************************\n");
        printf("\t\t\t**\t      欢迎使用用户模块！\t**\n");//排版 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t1.打开楼门\t\t**\n");
        printf("\t\t\t**\t\t2.退出\t\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多*
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("输入错误，请重新输入。\n");
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
        printf("\t\t\t**\t      请选择您的楼号\t\t**\n");//排版 
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t**\t\t  1.A楼\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t  2.B楼\t\t\t**\n");//排版 
        printf("\t\t\t**\t\t  3.退出\t\t**\n");//排版        
        printf("\t\t\t**                      \t\t**\n");
        printf("\t\t\t******************************************\n");//多* 
        printf("请输入您想访问的模块序号:（仅支持显示的序号）\n");
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
                printf("输入错误，请重新输入。\n");
        }
        system("pause");
        system("cls");
    }
}

void user_A() {
    system("cls");
    char id[20];
    printf("请输入您的A楼门卡号：\n");
    scanf("%s", id);
    for (int i = 0; i < n2; i++) {
        if (strcmp(A[i].id, id) == 0) {
            time_t now = time(NULL);
    		strftime(A[i].time, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    		printf("欢迎回家！A楼门已打开，时间：%s\n", A[i].time);
    		writefile_A();
    		system("pause");
            menu();
        }
    }
    printf("卡号无效，请重试。\n");
}

void user_B() {
    system("cls");
    char id[20];
    printf("请输入您的B楼门卡号：\n");
    scanf("%s", id);
    for (int i = 0; i < n3; i++) {
        if (strcmp(B[i].id, id) == 0) {
            time_t now = time(NULL);
    		strftime(B[i].time, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    		printf("欢迎回家！B楼门已打开，时间：%s\n", B[i].time);
    		writefile_B();
    		system("pause");
    		menu();
        }
    }
    printf("卡号无效，请重试。\n");
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
