//Copyright [2017-09-22] by [��˼�á������Ρ�����������һ�ơ������] from [Class 2016215109 And 2016215110 from BUPT International School] 
//All rights reserved. 
//Version 5.0.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define size 81
#define row 81
#define column 81
struct Customer{
    char ID[11];	//�˿�ID
    char Name[81];	//����
    char Gender[7];	//�Ա�
    char Phone[12];	//�绰
    char Password[81];	//����
    char Email[81];	//����
    char Addr[81];	//�ջ���ַ
    float Balance;	//�˻����
}CUST,cust[81],customer[81];

struct Item{
    char Num[7];   //��Ʒ���
    char Market[81];  //��������
    char SaleStart[81];//�ۿۿ�ʼ
    char SaleEnd[81];//�ۿ۽���
    float SellPrice;//�ۼ�
    float PurchasePrice;//�����۸�
    float SalePrice;//�ۿۼ�
    int Sales;
    int Stock;
    char Name[81];
    int Discount;
}goods[81],temp[81],sort;

struct Cart{
    char Num[7];      //��Ʒ���
    char Name[81];   //��Ʒ����
    char Market[81];   // ��������
    char SaleStart[81];  //�ۿۿ�ʼ
    char SaleEnd[81];   //�ۿ۽���
    float SellPrice;    //����
    float SalePrice;    //�ۿۼ�
    int Stock;          //���
    char CUSTID[81];
	int Sales;       
}CART[81];

struct Order{
    char Num[7];      //�������
    char Name[81];    //��Ʒ����
    char Market[81];  //��������
    char SaleStart[81];//�ۿۿ�ʼ
    char SaleEnd[81];//�ۿ۽���
    float SellPrice;  //�ۼ�
    float PurchasePrice;//�����۸�
    float SalePrice;//�ۿۼ�
    int Sales;
    int Stock;//���
    int Amount;
    char SaleDay[81];
    char ID[11];
    char OrderNum[30];
    int Pay;
    float Total;
    float FinalPrice;
}order[81];

struct mag{
    char magid[81];//����ԱID
    char code[81];//����Ա����
    char market[81];//����Ա��������
    char name[81];//����Ա����
    char email[81];//����Ա����
}manager[50];//����Ա�ṹ��

int LoginStatus=0;
int ItemNum;
int TempNum;

/*�˿ͺ���*/
int ReadGoods();//��ȡ��Ʒ����
int ReadOrder();//��ȡ����

void Customer();// �˿͹���
void Administration();
void CUSTLogin();//�˿͵�½�ȶ��û�������
void CUSTLoginSuccess();//�˿͵�½�ɹ�ѡ����
void SearchItem();//��Ʒ��ѯ
void Add2Cart();//���빺�ﳵ
void CARTFUNC();//���ﳵ���� 
void DeleteLine(int);//ɾ���ļ�ĳ�� 
void Order();//�û���������
int Pay(int);//��ʾ�û��Ѹ��δ�����
void NotPay();//��ʾδ��������û�ѡ�����
void Paying(int);//����
void CancelPay();//ȡ������
void Info();
void SignUp();//�˿�ע��
int IsEmail(char *str);//�ж������ʽ�Ϸ���
void SearchItemName();//����Ʒ������
void SearchMarketName();//������������
void SearchDiscount();//ɸѡ�ۿ���Ʒ
void SearchPrice();// �۸�����
void SearchSales();//��������
void All2Temp();
void Delect();
void CheckTime();
//*******************************************************************����Ա����*********************************************************************************//
void login();//����Ա��¼
void comeIn();//����
void readManagerFile();//��ȡ����Ա��Ϣ

void ordermanage();//��������
void readOrderFile();//��ȡ������Ϣ��order
void searchOrderInfor();//�����в�ѯ��Ʒ����
void calOrderInfor();//ͳ�ƶ�����Ϣ
void ToTemp();//��ȡ������Ϣ��temp

void TurnOverView();//ͳ��Ӫҵ��
void SalesRank();//����������Ʒ����
void TurnOverRank();//��Ӫҵ�����Ʒ����
void ProfitView();//�ж�������ߺ������Ʒ
void UnSoldNStock();//

void goodsmanage();//��Ʒ����
void readCommodityFile();//��ȡ��Ʒ��Ϣ��commodity
void searchgoods();//������Ʒ��Ϣ
void addgoods();//�����Ʒ


void personalmanage();//������Ϣ����
void codeRevise();//�޸�����
void emailRevise(); //�޸�����


char option;//ÿһ��ѡ��ʱ�ı���
int managerNum;//����Ա����
int goodsNum;//��Ʒ��
int orderNum;//������1
int yourNum;
char market[size];//��½�����Ա���ڳ���

/*������ */
int main(){
    char option;
    printf ("-------���ϳ��й���ϵͳ-------\n");
    while(1)
    {
        printf("\t1. ���ǹ˿�\n");
        printf("\t2. ���ǹ���Ա\n");
        printf("\t0. �˳�����\n");
        printf("\t����������ѡ��");
        rewind(stdin);
        scanf("%c",&option);
        switch(option)
        {
            case '1':
                Customer();
                break;
            case '2':
                login();
                break;
            case '0':
                return(0);
            default:
                printf ("\t���������������������\n\n");
        }
    }
}

/*��������*/
int ReadGoods(){//��ȡ��Ʒ�����ļ�
    FILE *fp;
    fp = fopen("good.txt","r");
    if(fp==NULL){
        printf("��������Ʒ����\n");
        getchar();
        exit(1);}
    for (ItemNum=0;!feof(fp);ItemNum++){//д��ṹ��
        fscanf(fp,"%s%s%s%f%f%d%d%f%s%s%d\n"
               ,goods[ItemNum].Name,goods[ItemNum].Num,goods[ItemNum].Market,&goods[ItemNum].SellPrice
               ,&goods[ItemNum].PurchasePrice,&goods[ItemNum].Sales,&goods[ItemNum].Stock,&goods[ItemNum].SalePrice
               ,goods[ItemNum].SaleStart,goods[ItemNum].SaleEnd,&goods[ItemNum].Discount);
    }
    fclose(fp);
    CheckTime();//ɸѡ�����ۿ�
    return (ItemNum);
}

int ReadOrder(){//��ȡ�����ļ�
    int i=0;
    FILE *outFile;
    outFile=fopen("order.txt","r");
    while(fscanf(outFile,"%s %s %s %s %s %f %f %f %d %d %d %s %s %s %d %f",order[i].Num,order[i].Name,order[i].Market,order[i].SaleStart,order[i].SaleEnd,&order[i].SellPrice,&order[i].PurchasePrice,&order[i].SalePrice,&order[i].Sales,&order[i].Stock,&order[i].Amount,order[i].SaleDay,order[i].ID,order[i].OrderNum,&order[i].Pay,&order[i].Total)!=EOF)
    {
        i++;
    }
    return (i);
}

void Customer(){//�˿͹��ܽ���
    char option;
    system("cls");
    printf("\t1. ��½\n");
    printf("\t2. ע��\n");
    printf("\t3. ��Ʒ��ѯ\n");
    printf("\t0. �˳�����\n");
    printf("\t����������ѡ��");
    while(1)
    {
        rewind(stdin);
        scanf("%c",&option);
        switch(option)
        {
            case '1':
                CUSTLogin();//�˿͵�½
                break;
            case '2':
                SignUp();//ע��
                break;
            case '3':
                SearchItem();//��Ʒ��ѯ
                break;
            case '0':
                exit(0); //�˳�����
            default:
                printf ("\t���������������������\n\n");
                break;
        }
    }
}

void CUSTLogin(){//�˿͵�¼ȷ���û���������
    char CheckID[11];
    char CheckPassword[81];
    int i=0,j=0;
    char CustID[11],name[81],gender[7],phone[12],pass[81],email[81],addr[81];
    float balance;
    FILE *CID;
    CID = fopen("CustomerID.txt","r");
    if(CID==NULL){
        printf("�������û�����\n");
        getchar();
        exit(1);
	}
    system("cls");
    printf("***��¼ϵͳ***\n");
    printf("����������ID��");
    rewind(stdin);
    scanf("%s",CheckID);
    while(fscanf(CID, "%s%s%s%s%s%s%s%f\n",CustID,name,gender,phone,pass,email,addr,&balance) != EOF){
        if (strcmp(CheckID,CustID)==0){
            strcpy(CUST.ID,CustID);
            strcpy(CUST.Name,name);
            strcpy(CUST.Gender,gender);
            strcpy(CUST.Phone,phone);
            CUST.Balance=balance;
            strcpy(CUST.Email,email);
            strcpy(CUST.Password,pass);
            strcpy(CUST.Addr,addr);
            break;
        }
        if(feof(CID)){
            printf("�������ID�����ڣ���ע������µ�½.\n���س�����");
            getchar();
            getchar();
            return Customer();
        }
    }
    
    fclose(CID);
    printf("����������:");
    scanf("%s",CheckPassword);
    while(strcmp(CheckPassword,pass)!=0)
    {
        printf("������Ч\n");
        printf("�������������� :");
        scanf("%s",CheckPassword);
    }
    CUSTLoginSuccess();
}

void CUSTLoginSuccess(){//�˿͵�½�ɹ���ʾ�˵�
    char option;
    LoginStatus = 1;
    system("cls");
    printf("\t�˿����ã�\n");
    printf("\t1. ��Ʒ��ѯ\n");
    printf("\t2. ���ﳵ\n");
    printf("\t3. ������ѯ\n");
    printf("\t4. ������Ϣ�޸�\n");
    printf("\t0. �˳�����\n");
    printf("\t����������ѡ��");
    rewind(stdin);
    while(1){
        scanf("%c",&option);
        switch(option){
            case '1':
                SearchItem();//��Ʒ��ѯ
                break;
            case '2':
                CARTFUNC();//���ﳵ
                break;
            case '3':
                Order();
                break;
            case '4':
                Info();//������Ϣ�޸�
                break;
            case '0':
                exit(1);
            default:
                printf ("\t����������������������:");
        }
    }
}

void SignUp(){//�˿�ע��
    FILE *CID;
    char id[11],name[81],gender[81],phone[81],password[81],email[81],addr[81];
    char GetGender='0';
    float balance;
    int length,i,j=1;
    system("cls");
    //ע��ID
    while(j){
        printf("������Ҫע���ID(6-10λ��ĸ�����ֵ����)��\n");
        rewind(stdin);
        scanf("%s",id);
        length=strlen(id);
        if (length<6||length>10){
            printf("��������ȷ���ȵ�ID\n\n");
            j=1;
        }
        else{
            for (i=0;i<length;i++){
                if(isalnum(id[i])){
                    j=0;
                    continue;}
                else {
                    printf("��������ĸ��������ɵĺϷ�ID\n");
                    j=1;
                    break;
                }
            }
        }
    }
    
    //ע������
    printf("���������룺");
    rewind(stdin);
    scanf("%s",password);
    
    //ע������
    printf("����������������");
    rewind(stdin);
    scanf("%s",name);
    
    //ѡ���Ա�
    printf("����������ѡ�������Ա�(1.����	2.Ů��)��");
    while(GetGender=='0'){
        rewind(stdin);
        scanf("%c",&GetGender);
        switch(GetGender){
            case '1':
                strcpy(gender,"Male");
                break;
            case '2':
                strcpy(gender,"Female");
                break;
            default:
                printf("��������Ч����ѡ��:");
                GetGender = '0';
        }
    }
    
    //ע��绰
    printf("����������11λ�绰���룺");
    j=1;
    while(j) {
        rewind(stdin);
        scanf("%s",phone);
        length=strlen(phone);
        if (length!=11){
            printf("�绰�����������������룺");
            j=1;
        }
        else{
            j=0;
        }
    }
    
    //ע������
    printf("�������������䣨***@***.***����");
    while(1){
        rewind(stdin);
        scanf("%s",email);
        if(IsEmail(email))
            break;
        else
            printf("�����ʽ����ȷ������������:") ;
    }
    
    
    //ע���ַ
    printf("���������ĵ�ַ ��");
    rewind(stdin);
    scanf("%s",addr);
    
    //�˻���ֵ
    printf("��Ϊ�����˻���ֵ ��");
    rewind(stdin);
    scanf("%f",&balance);
    
    CID = fopen("CustomerID.txt","a+");
    fprintf(CID, "%s %s %s %s %s %s %s %.2f\n",id,name,gender,phone,password,email,addr,balance);
    fclose(CID);
    printf("\nע��ɹ�������س�������һҳ");
    getchar();
    getchar();
    return Customer();
}

int IsEmail(char *str){//��֤�����ʽ����
    char a1[32]={0};
    char a2[32]={0};
    char a3[32]={0};
    char a4[32]={0};
    if(sscanf(str,"%[a-zA_Z0-9_-]@%[a-zA-Z0-9._-]",a1,a2) < 2)
    {
        return 0;
    }
    if(sscanf(a2,"%[a-zA_Z0-9_-].%[a-zA_Z0-9_-.]",a3,a4) <2)
    {
        return 0;
    }
    int i = 1;
    char c;
    
    while((c=a4[i])!='\0')
    {
        if(c == '.'&&a4[i-1] == '.')
            return 0;
        ++i;
    }
    
    if(a4[0] == '.' || a4[i-1] =='.')
        return 0;
    return 1;
}

void SearchItem(){//��Ʒ��ѯ��ʽѡ��
    char option;
    system("cls");
    ReadGoods();
    printf ("****��Ʒ��ѯ****\n");
    printf ("1.������Ʒ���Ʋ�ѯ\n");
    printf ("2.���ݳ������Ʋ�ѯ\n");
    printf ("3.���ݼ۸�����������Ʒ\n");
    printf ("4.������������������Ʒ\n");
    printf ("0.������һ��\n");
    printf ("����������ѡ��");
    while(1)
    {
        rewind(stdin);
        scanf("%c",&option);
        switch(option)
        {
            case '1':
                SearchItemName();//������Ʒ���Ʋ�ѯ
                break;
            case '2':
                SearchMarketName();//���ݳ������Ʋ�ѯ
                break;
            case '3':
                All2Temp();
                SearchPrice();
                break;
            case '4':
                All2Temp();
                SearchSales();
            case '0':
                return CUSTLoginSuccess();
            default:
                printf ("����������������������:");
        }
    }
}

void Add2Cart(){//���빺�ﳵ
    FILE *cart;
    char option[7];
    int i;
    printf("\n----------------------------------------------------------");
    printf("\n������Ʒ��ż��빺�ﳵ\n����'1'ɸѡ�ۿ���Ʒ\n����'2'���۸�����\n����'3'����������\n����'0'������һҳ\n������ѡ�");
    rewind(stdin);
    scanf("%s",option);
    if(strncmp(option,"1",1)==0) {
        SearchDiscount(); //�ۿ���Ϣɸѡ
    }
    if(strncmp(option,"2",1)==0) {
        SearchPrice();//�۸�����
    }
    if(strncmp(option,"3",1)==0) {
        SearchSales();//��������
    }
    if(strncmp(option,"0",1)==0) {
        return SearchItem();//������Ʒ��ѯ
    }
    if (LoginStatus==0){//δ��¼����
        printf("\n����δ��½�����¼���ٽ��в�����\n");
        printf("����س����ص�½����");
        getchar();
        getchar();
        return Customer();
    }
    for(i=0;i<ItemNum;i++){
        if(strncmp(option,goods[i].Num,6)!=0){ //�������Ʒ���δ����
            continue;}
        if(strncmp(option,goods[i].Num,6)==0){ //�������Ʒ��ŷ���
            cart=fopen("cart.txt","a+");
            fprintf(cart,"%s %s %s %s %s %.2f %.2f %d %d %s\n"
                    ,goods[i].Num,goods[i].Name,goods[i].Market,goods[i].SaleStart,goods[i].SaleEnd
                    ,goods[i].SellPrice,goods[i].SalePrice,goods[i].Sales,goods[i].Stock,CUST.ID
                    );
            fclose(cart);
            printf("�ɹ����빺�ﳵ���س�������һҳ");
            getchar();
            getchar();
            return SearchItem();
        }
    }
    //�������Ʒ��Ų�����
    printf("���������Ʒ��Ų����ڣ�����س�����");
    getchar();
    getchar();
    return SearchItem();//������Ʒ��ѯ
}

void SearchItemName(){//��Ʒ��������
    char name[81];//��Ʒ����
    char option[7];
    int i,j=0;
    
    system("cls");
    printf ("****��������Ʒ���ƽ���������");
    rewind(stdin);
    scanf("%s",name);
    printf("| ��Ʒ�� |��Ʒ���|��������| �ۼ� |����|���|�ۿۼ� |  �ۿۿ�ʼʱ��  |  �ۿ۽���ʱ��  |\n");
    for(i=0;i<ItemNum;i++){
        if(strncmp(name,goods[i].Name,10)!=0)
            continue;
        else{	//��ʾƥ����
            printf("%-10s %-7s %-8s %-7.2f %-4d %-4d %-7.2f %-16s %-16s\n"
                   ,goods[i].Name,goods[i].Num,goods[i].Market,goods[i].SellPrice
                   ,goods[i].Sales,goods[i].Stock,goods[i].SalePrice
                   ,goods[i].SaleStart,goods[i].SaleEnd);
            temp[j]=goods[i];
            j++;
            TempNum=j;
        }
    }
    if(j==0){ //���������
        printf("\n����������Ʒ��δ�ϼܣ�����س��ص���һҳ");
        getchar();
        getchar();
        return SearchItem();//������Ʒ��ѯ
    }
    Add2Cart();
}

void SearchMarketName(){//������������
    FILE *cart;
    char name[81];//��������
    char option[7];
    int i,j=0;
    
    system("cls");
    printf ("****�����볬�����ƽ���������");
    rewind(stdin);
    scanf("%s",name);
    printf("| ��Ʒ�� |��Ʒ���|��������| �ۼ� |����|���|�ۿۼ� |  �ۿۿ�ʼʱ��  |  �ۿ۽���ʱ��  |\n");
    for(i=0;i<ItemNum;i++){
        if(strncmp(name,goods[i].Market,10)!=0)
            continue;
        else{	//��ʾƥ����
            printf("%-10s %-7s %-8s %-7.2f %-4d %-4d %-7.2f %-16s %-16s\n"
                   ,goods[i].Name,goods[i].Num,goods[i].Market,goods[i].SellPrice
                   ,goods[i].Sales,goods[i].Stock,goods[i].SalePrice
                   ,goods[i].SaleStart,goods[i].SaleEnd);
            temp[j]=goods[i];
            j++;
            TempNum=j;
        }
    }
    if(j==0){ //���������
        printf("\n�������ĳ�����δ��פ��ϵͳ������س��ص���һҳ");
        getchar();
        getchar();
        return SearchItem();//������Ʒ��ѯ
    }
    Add2Cart();
}

void SearchDiscount(){//�ۿ���Ϣɸѡ
    int i,j=0;
    system("cls");
    printf ("****��ѯ�ۿ���Ʒ****\n");
    printf("| ��Ʒ�� |��Ʒ���|��������| �ۼ� |����|���|�ۿۼ� |  �ۿۿ�ʼʱ��  |  �ۿ۽���ʱ��  |\n");
    for(i=0;i<TempNum;i++){
        if(temp[i].Discount==0)
            continue;
        else{	//��ʾƥ����
            printf("%-10s %-7s %-8s %-7.2f %-4d %-4d %-7.2f %-16s %-16s\n"
                   ,temp[i].Name,temp[i].Num,temp[i].Market,temp[i].SellPrice
                   ,temp[i].Sales,temp[i].Stock,temp[i].SalePrice
                   ,temp[i].SaleStart,temp[i].SaleEnd);
            j++;
        }
    }
    if(j==0){ //���������
        printf("����������Ʒ���ۿ���Ϣ������س�������һҳ");
        getchar();
        getchar();
        return SearchItem();//������Ʒ��ѯ
    }
    Add2Cart();
}
void SearchPrice(){// �۸�����
    int i,j;
    system("cls");
    printf ("****���۸�����****\n");
    printf("| ��Ʒ�� |��Ʒ���|��������| �ۼ� |����|���|�ۿۼ� |  �ۿۿ�ʼʱ��  |  �ۿ۽���ʱ��  |\n");
    for (i = 0; i < TempNum - 1; i++)
        for (j = 0; j < TempNum - 1 - i; j++)
            if (temp[j].SellPrice > temp[j+1].SellPrice) {
                sort = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = sort;
            }
    for(i=0 ; i<TempNum ; i++)
        printf("%-10s %-7s %-8s %-7.2f %-4d %-4d %-7.2f %-16s %-16s\n"
               ,temp[i].Name,temp[i].Num,temp[i].Market,temp[i].SellPrice
               ,temp[i].Sales,temp[i].Stock,temp[i].SalePrice
               ,temp[i].SaleStart,temp[i].SaleEnd);
    return Add2Cart();
}
void SearchSales(){//��������
    int i,j;
    system("cls");
    printf ("****����������****\n");
    printf("| ��Ʒ�� |��Ʒ���|��������| �ۼ� |����|���|�ۿۼ� |  �ۿۿ�ʼʱ��  |  �ۿ۽���ʱ��  |\n");
    for (i = 0; i < TempNum - 1; i++)
        for (j = 0; j < TempNum - 1 - i; j++)
            if (temp[j].Sales > temp[j+1].Sales) {
                sort = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = sort;
            }
    for(i=0 ; i<TempNum ; i++)
        printf("%-10s %-7s %-8s %-7.2f %-4d %-4d %-7.2f %-16s %-16s\n"
               ,temp[i].Name,temp[i].Num,temp[i].Market,temp[i].SellPrice
               ,temp[i].Sales,temp[i].Stock,temp[i].SalePrice
               ,temp[i].SaleStart,temp[i].SaleEnd);
    return Add2Cart();
}
void All2Temp(){
    int i;
    for(i=0;i<ItemNum;i++){
        temp[i]=goods[i];
    }
    TempNum=ItemNum;
}

//**���ﳵ**//
void CARTFUNC(){
    FILE *cart,*order,*good;
    char idnum[7],option;
    int numpack,decision,a=1,i=1,j=0,k=0,Pay=0;
    float Total;
    while(i==1)
    {
        printf("\t***���ﳵ***\n");
        printf("|��Ʒ���| ��Ʒ�� | �������� |  �ۿۿ�ʼʱ��  |  �ۿ۽���ʱ��  | �ۼ� |�ۿۼ�| ��� |\n");
        cart=fopen("cart.txt","a+");
        while(fscanf(cart,"%s%s%s%s%s%f%f%d%d%s",CART[j].Num,CART[j].Name,CART[j].Market,CART[j].SaleStart,
                     CART[j].SaleEnd,&CART[j].SellPrice,&CART[j].SalePrice,&CART[j].Sales,&CART[j].Stock,CART[j].CUSTID)!=EOF)
        {
            if(strncmp(CART[j].CUSTID,CUST.ID,6)==0)
                printf(" %-7s %-10s %-8s %-16s %-17s %-7.2f %-7.2f %-4d\n",CART[j].Num,CART[j].Name,CART[j].Market,
                       CART[j].SaleStart,CART[j].SaleEnd,CART[j].SellPrice,CART[j].SalePrice,CART[j].Stock);
            else{
                continue;
            }
            j++;
        }   //�жϸù˿͵Ĺ��ﳵ����ʾ������Ʒ
        fclose(cart);
        printf("\n1.ѡ�����빺�����Ʒ\n2.����\n");
        printf("����������ѡ�\n");
        rewind(stdin);
        scanf("%c",&option);
        switch(option)
        {
            case'1':
                break;
            case'2':
                CUSTLoginSuccess();
                break;
            default:
                printf("��������\n");
                a=0;
                CARTFUNC();
                break;
        }      //ѡ����һ���ж�
        
        
        printf("\n��������ȷ����Ʒ���:\n");
        rewind(stdin);
        scanf("%s",idnum);
        while(a==1){
            if(strcmp(idnum,CART[j].Num)==0)
            { break;	}
            else{
                j--;
                while(j<0){
                    system("cls");
                    
                    printf("���������Ʒ�����ڣ��밴�س�������ѡ��\n");
                    getchar();
                    getchar();
                    a=0;
                    return CARTFUNC();
                    break;
                }}
            
        }            //ѡ����ȷ����Ʒ
        while(1){
            printf("���������빺�����Ʒ����:\n");
            scanf("%d",&numpack);
            rewind(stdin);
            if(numpack>CART[j].Stock)
            {
                printf("��治�㣬����ʣ%d\n",CART[j].Stock);
            }
            else
                break;
		}      //ѡ����ȷ����Ʒ����
        
        Total=(float)numpack*CART[j].SalePrice;
        order=fopen("order.txt","a+");
        good=fopen("good.txt","r");
        while(fscanf(good,"%s %s %s %f %f %d %d %f %s %s %d",goods[k].Name,goods[k].Num,goods[k].Market,
                     &goods[k].SellPrice,&goods[k].PurchasePrice,&goods[k].Sales,&goods[k].Stock,&goods[k].SalePrice,
                     goods[k].SaleStart,goods[k].SaleEnd,&goods[k].Discount)!=EOF)
        {
            k++;
        }
        while(a==1){
            if(strcmp(idnum,goods[k].Num)==0)
            { break;	}
            else{
                k--;
                while(k<0){
                    system("cls");
                    printf("���������Ʒ�����ڣ��밴�س�������ѡ��\n");
                    getchar();
                    getchar();
                    a=0;
                    return CARTFUNC();
                    break;
                }
            } //��ȡ��Ʒ��Ϣ
        }
        DeleteLine(j); 
        //��������
		time_t rawtime;
		struct tm *info;
		char Ordertime[80],Ordernum[80],buffer[80];
		int j;
		
		time( &rawtime );
		info = localtime( &rawtime );
		strftime(Ordertime,44,"%Y:%m:%d:%H:%M",info);
		strftime(Ordernum,44,"%Y%m%d%H%M",info);
		
	    fprintf(order,"%s %s %s %s %s %.2f %.2f %.2f %d %d %d %s %s %s%s %d %.2f\n",goods[k].Num,goods[k].Name,
		goods[k].Market,goods[k].SaleStart,goods[k].SaleEnd,goods[k].SellPrice,
				goods[k].PurchasePrice,goods[k].SalePrice,goods[k].Sales,goods[k].Stock,
				numpack,Ordertime,CUST.ID,CUST.ID,Ordernum,Pay,Total);
	        
	    fclose(order);
        
        printf("1.����\n2.��������\n");
        scanf("%d",&decision);
        rewind(stdin);
        i=decision;
        system("cls");
    }
    Order();
}

//**��������**//
void Order()
{
    printf("\t��ӭ�����������棡\n");
    printf("\t1.�鿴�Ѹ����\n");
    printf("\t2.�鿴δ�����\n");
    printf("\t3.����\n");
    printf("\t����������ѡ��:");
    rewind(stdin);
    scanf("%c",&option);
    while(1)
    {
        switch(option)
        {
            case '1':
                Pay(1);
                break;
            case '2':
                NotPay();
                break;
            case '3':
                CUSTLoginSuccess();
            default:
                printf("\t��������������������룺");
                rewind(stdin);
                scanf("%c",&option);
                
        }
    }
    
}

//��ʾ�Ѹ���/δ���������

int Pay(int a)
{
    int i=0;
    int j=0;
    int k=0;
    float OrderTotal=0;//�����ܽ��
    int OrderAmount=0;//�ļ��ж�������
    int GoodNum=0;//�ļ�����Ʒ����
    int OrderMinus=0;//�ļ��ж��������������ж�û����ض���ʱ��ȥ
    //���붩������
    OrderAmount=ReadOrder();
    OrderMinus=ReadOrder();
    //��ȡ��Ʒ��Ϣ�ļ�������discount�ı��ֵ���ж����ռ۸��Ƿ����
    GoodNum=ReadGoods();
    for(i=0;i<OrderAmount;i++)
    {
        for(j=0;j<GoodNum;j++)
        {
            if((strcmp(order[i].Name,goods[j].Name)==0)&&(strcmp(order[i].Market,goods[j].Market)==0)&&(goods[j].Discount==0))
                order[i].FinalPrice=goods[j].SellPrice;
            if((strcmp(order[i].Name,goods[j].Name)==0)&&(strcmp(order[i].Name,goods[j].Name)==0)&&(goods[j].Discount==1))
                order[i].FinalPrice=goods[j].SalePrice;
        }
    }
    //����Ѹ��δ�����
    for(j=0;j<OrderAmount;j++)
    {
        if(j<k)
            continue;
        
        if((strcmp(CUST.ID,order[j].ID)==0)&&(order[j].Pay==a))
        {
            OrderTotal=order[j].Amount*order[j].FinalPrice;
            printf("\t��Ʒ���  ��Ʒ    ����   ����    \n");
            printf("\t%-9s %-8s %-5d %-8.2f \n",order[j].Num,order[j].Name,order[j].Amount,order[j].FinalPrice);
            if(k==OrderAmount-1)//����ö����ǵ���һ����Ʒ���ļ���ĩ
            {
                printf("\t������ţ�%s ",order[k].OrderNum);
                printf("\t�������ڣ�%s ",order[k].SaleDay);
                printf("\t�����ܼۣ�%.2f\n",OrderTotal);
                printf("\n");
            }
            
            for(k=j+1;k<OrderAmount;k++)
            {
                
                if(strcmp(order[k].OrderNum,order[j].OrderNum)==0)
                {
                    if(k==OrderAmount-1)//����ö������һ����Ʒ���ļ���ĩ
                    {
                        printf("\t%-9s %-8s %-5d %-8.2f\n",order[k].Num,order[k].Name,order[k].Amount,order[k].FinalPrice);
                        OrderTotal+=order[k].Amount*order[k].FinalPrice;
                        printf("\t������ţ�%s ",order[k-1].OrderNum);
                        printf("\t�������ڣ�%s ",order[k-1].SaleDay);
                        printf("\t�����ܼۣ�%.2f\n",OrderTotal);
                        printf("\n");
                    }
                    else
                    {
                        printf("\t%-9s %-8s %-5d %-8.2f\n",order[k].Num,order[k].Name,order[k].Amount,order[k].FinalPrice);
                        OrderTotal+=order[k].Amount*order[k].FinalPrice;
                    }
                }
                else
                {
                    printf("\t������ţ�%s ",order[k-1].OrderNum);
                    printf("\t�������ڣ�%s ",order[k-1].SaleDay);
                    printf("\t�����ܼۣ�%.2f\n",OrderTotal);
                    printf("\n");
                    break;
                }
                
            }
            
        }
        else
            OrderMinus--;
    }
    
    //�ж��Ƿ�û����ض���
    if (OrderMinus==0)
    {
        printf("\t��û����صĶ������������²�ѯ\n\n");
        Order();
    }
    if(a==1)
    {
        printf("\t���������������һ����");
        rewind(stdin);
        getchar ();
        system("cls");
        Order();
    }
    return  OrderAmount;
}

//δ�����
void NotPay()
{
    int OrderAmount=0;//�ļ��ж�������
    OrderAmount=Pay(0);//���δ�����
    printf("\t1.����\n");
    printf("\t2.ȡ������\n");
    printf("\t3.������һ��\n");
    printf("\t����������ѡ��Ĳ�������:");
    rewind(stdin);
    scanf("%c",&option);
    while(1)//�����������һֱѭ��
    {
        switch(option)
        {
            case '1':
                Paying(OrderAmount);
                break;
            case '2':
                CancelPay();
                break;
            case '3':
                system("cls");
                Order();
                break;
            default:
                printf("\t��������������������룺");
                rewind(stdin);
                scanf("%c",&option);
        }
    }
    
}

//����
void Paying(int OrderAmount)
{
    char PayNum[81];//�����û�����Ķ�����
    int CustomerNum=0;//�ļ����û�����
    int GoodNum=0;//�ļ�����Ʒ����
    int i=0;
    int j=0,k=0;
    int count[20];//���ڼ�¼�ļ��ж��������û����붩������ͬ�Ľṹ�����
    int CountNum=0;
    float OrderTotal=0;//�����ܶ�
    FILE *outFile1;
    FILE *inFile1;
    FILE *inFile2;
    FILE *inFile3;
    //��ȡ�ͻ���Ϣ�ļ�
    outFile1=fopen("CustomerID.txt","r");
    while(fscanf(outFile1,"%s %s %s %s %s %s %s %f",customer[i].ID,customer[i].Name,customer[i].Gender,customer[i].Phone,customer[i].Password,customer[i].Email,customer[i].Addr,&customer[i].Balance)!=EOF)
    {
        i++;
    }
    CustomerNum=i;
    fclose(outFile1);
    //��ȡ��Ʒ��Ϣ�ļ�
    GoodNum=ReadGoods();
    //��λ��ؿͻ�
    for(j=0;j<CustomerNum;j++)
    {
        if (strcmp(CUST.ID,customer[j].ID)==0)
            break;
        
    }/*DANGEROUS j*/
    
    printf("\t������������������һ�������ţ�����:acb123199702251307��:");
    rewind(stdin);
    scanf("%s",PayNum);
    //������֤
    i=0;
    for(k=0;k<OrderAmount;k++)
    {
        if(strcmp(order[k].OrderNum,PayNum)!=0)
            i++;
    }
    while(i==OrderAmount)
    {
        printf("\t��������һ������Ķ����ţ����������룺");
        rewind(stdin);
        scanf("%s",PayNum);
        i=0;
        for(k=0;k<OrderAmount;k++)
        {
            if(strcmp(order[k].OrderNum,PayNum)!=0)
                i++;
        }
    }
    
    //�ҳ�����������û�������ͬ�ģ������ܼۣ��޸�֧��״̬����¼���
    int b=0;
    for(i=0;i<OrderAmount;i++)
    {
        if(strcmp(order[i].OrderNum,PayNum)==0)
        {
            OrderTotal+=order[i].Amount*order[i].FinalPrice;
            order[i].Pay=1;
            count[b++]=i;
        }
        
    }
    CountNum=b;
    //�ۿ�
    customer[j].Balance-=OrderTotal;
    if(customer[j].Balance<0)
    {
    	printf("�������㣡������������\n");
    	printf("������س�������������\n");
    	getchar();
    	getchar();
    	CUSTLoginSuccess();
	}
    //�����仯���CustomerID.txt
    inFile1=fopen("CustomerID.txt","w");
    for(k=0;k<CustomerNum;k++)
    {
        fprintf(inFile1,"%s %s %s %s %s %s %s %.2f\n",customer[k].ID,customer[k].Name,customer[k].Gender,customer[k].Phone,customer[k].Password,customer[k].Email,customer[k].Addr,customer[k].Balance);
    }
    fclose(inFile1);
    //�����仯���order.txt
    inFile2=fopen("order.txt","w");
    for(i=0;i<OrderAmount;i++)
    {
        
        fprintf(inFile2,"%s %s %s %s %s %.2f %.2f %.2f %d %d %d %s %s %s %d %.2f\n",order[i].Num,order[i].Name,order[i].Market,order[i].SaleStart,order[i].SaleEnd,order[i].SellPrice,order[i].PurchasePrice,order[i].SalePrice,order[i].Sales,order[i].Stock,order[i].Amount,order[i].SaleDay,order[i].ID,order[i].OrderNum,order[i].Pay,order[i].Total);
    }
    fclose(inFile2);
    //�޸���Ʒ��������
    for(i=0;i<GoodNum;i++)
    {
        for(k=0;k<CountNum;k++)
        {
            j=count[k];
            if((strcmp(order[j].Name,goods[i].Name)==0)&&(strcmp(order[j].Market,goods[i].Market)==0))
            {
                goods[i].Sales+=order[j].Amount;
                goods[i].Stock-=order[j].Amount;
            }
        }
    }
    //�����仯���good.txt
    inFile3=fopen("good.txt","w");
    for(i=0;i<GoodNum;i++)
    {
        
        fprintf(inFile3,"%s %s %s %.2f %.2f %d %d %.2f %s %s %d\n",goods[i].Name,goods[i].Num,goods[i].Market,goods[i].SellPrice,goods[i].PurchasePrice,goods[i].Sales,goods[i].Stock,goods[i].SalePrice,goods[i].SaleStart,goods[i].SaleEnd,goods[i].Discount);
    }
    fclose(inFile3);
    
    printf("\t�������֧��\n");
    printf("\t1.��������\n");
    printf("\t2.����\n");
    printf("\t����������ѡ��:");
    rewind(stdin);
    scanf("%c",&option);
    while(1)
    {
        switch(option)
        {
            case '1':
                Paying(OrderAmount);
                break;
            case '2':
                system("cls");
                Order();
                break;
            default:
                printf("\t��������������������룺");
                rewind(stdin);
                scanf("%c",&option);
        }
    }
    
}

//ȡ������
void CancelPay()
{
    char PayNum[81];//�����û�����Ķ������
    int i=0;
    int k=0;
    int OrderAmount=0;//�ļ��ж�������
    FILE *inFile;
    //���붩��
    OrderAmount=ReadOrder();
    //�û�����
    printf("\t���������������һ�������ţ���:acb123199702251307��:");
    rewind(stdin);
    scanf("%s",PayNum);
    
    //������֤
    i=0;
    for(k=0;k<OrderAmount;k++)
    {
        if(strcmp(order[k].OrderNum,PayNum)!=0)
            i++;
    }
    while(i==OrderAmount)
    {
        printf("\t��������һ������Ķ����ţ����������룺");
        rewind(stdin);
        scanf("%s",PayNum);
        i=0;
        for(k=0;k<OrderAmount;k++)
        {
            if(strcmp(order[k].OrderNum,PayNum)!=0)
                i++;
        }
    }
    //���ȡ����Ķ����ļ�
    inFile=fopen("order.txt","w");
    for(k=0;k<OrderAmount;k++)
    {
        if(strcmp(order[k].OrderNum,PayNum)!=0)
        {
            fprintf(inFile,"%s %s %s %s %s %.2f %.2f %.2f %d %d %d %s %s %s %d %.2f\n",order[k].Num,order[k].Name,order[k].Market,order[k].SaleStart,order[k].SaleEnd,order[k].SellPrice,order[k].PurchasePrice,order[k].SalePrice,order[k].Sales,order[k].Stock,order[k].Amount,order[k].SaleDay,order[k].ID,order[k].OrderNum,order[k].Pay,order[k].Total);
        }
        
    }
    
    
    fclose(inFile);
    printf("\t%sȡ���ɹ���\n",PayNum);
    printf("\t1.����ȡ������\n");
    printf("\t2.����\n");
    printf("\t����������ѡ��:");
    rewind(stdin);
    scanf("%c",&option);
    while(1)
    {
        switch(option)
        {
            case '1':
                CancelPay();
                break;
            case '2':
                system("cls");
                Order();
                break;
            default:
                printf("\t��������������������룺");
                rewind(stdin);
                scanf("%c",&option);
        }
    }
}


//**������Ϣ�޸�**//
void Info(){
    //�޸��õĺ���
    void altphone();//�޸ĵ绰
    void altcode();//�޸�����
    void altmail();//�޸�����
    void altaddress();//�޸ĵ�ַ
    //
    FILE*CustomerID;
    int a=1;
    char option;
    
    printf("****������Ϣ�޸�****\n");
    printf("\t1.�޸ĵ绰\n");
    printf("\t2.�޸�����\n");
    printf("\t3.�޸�����\n");
    printf("\t4.�޸ĵ�ַ\n");
    printf("\t5.����\n");
    printf("��ѡ����ȷ�����֣�");
    while(a==1)
    {
        rewind(stdin);
        scanf("%c",&option);
        switch(option)
        {
            case '1':
                a=0;
                altphone();
                break;
            case '2':
                altcode();
                a=0;
                break;
            case '3':
                a=0;
                altmail();
                break;
            case '4':
                altaddress();
                break;
            case '5':
                a=0;
                CUSTLoginSuccess();
                break;
            default:
                printf("\t����������� ����������:");
                break;
        }
    }
}

//�޸ĵ绰����//

void altphone(){
    FILE*CustomerID;
    char phonenum[12];
    int i=1,length;
    
    system("cls");
    printf("���ĵ绰�����ǣ� %s",CUST.Phone);
    printf("\n�������µĵ绰����:");
    while(i==1){
        rewind(stdin);
        scanf("%s",phonenum);
        length=strlen(phonenum);
        if (length!=11){
            printf("�绰�����������������룺");
            i=1;
        }
        else{
            i=0;
        }
    }   //�жϵ绰��ʽ
    
    
    Delect();
    CustomerID=fopen("CustomerID.txt","a+");
    strcpy(CUST.Phone,phonenum);
    fprintf(CustomerID,"%s %s %s %s %s %s %s %.2f\n",CUST.ID,CUST.Name,CUST.Gender,
            CUST.Phone,CUST.Password,CUST.Email,CUST.Addr,CUST.Balance);
    fclose(CustomerID);
    
    printf("�޸ĳɹ���\n");
    
    Info();
	   
}
//�޸�����//
void altcode(){
    FILE*CustomerID;
    char code[81];
    
    printf("Your code is %s",CUST.Password);
    printf("\nPlease input your new password:");
    rewind(stdin);
    scanf("%s",code);
    Delect();
    CustomerID=fopen("CustomerID.txt","a+");
    strcpy(CUST.Password,code);
    fprintf(CustomerID,"%s %s %s %s %s %s %s %.2f\n",CUST.ID,CUST.Name,CUST.Gender,
            CUST.Phone,CUST.Password,CUST.Email,CUST.Addr,CUST.Balance);
    fclose(CustomerID);
    printf("�޸ĳɹ����밴�س��������µ�¼\n");
    getchar();
    getchar();
    CUSTLogin();
}
//�޸�����//
void  altmail(){
    FILE*CustomerID;
    char  mail[81];
    printf("Your Email is %s",CUST.Email);
    printf("\nPlease input your new Email:");
    while(1){
        rewind(stdin);
        scanf("%s",mail);
        if(IsEmail(mail))
            break;
        else
            printf("�����ʽ����ȷ������������:") ;
    }
    Delect();
    CustomerID=fopen("CustomerID.txt","a+");
    strcpy(CUST.Email,mail);
    fprintf(CustomerID,"%s %s %s %s %s %s %s %.2f\n",CUST.ID,CUST.Name,CUST.Gender,
            CUST.Phone,CUST.Password,CUST.Email,CUST.Addr,CUST.Balance);
    fclose(CustomerID);
    printf("�޸ĳɹ���\n");
    Info();
}
//�޸ĵ�ַ//
void altaddress(){
    FILE *CustomerID;
    char  address[81];
    
    printf("Your address is %s",CUST.Addr);
    printf("\nPlease input your new address:");
    scanf("%s",address);
    Delect();
    CustomerID=fopen("CustomerID.txt","a+");
    strcpy(CUST.Addr,address);
    fprintf(CustomerID,"%s %s %s %s %s %s %s %.2f\n",CUST.ID,CUST.Name,CUST.Gender,
            CUST.Phone,CUST.Password,CUST.Email,CUST.Addr,CUST.Balance);
    fclose(CustomerID);
    printf("�޸ĳɹ���\n");
    Info();
}

//ɾ��ԭ�û���Ϣ//
void  Delect(){
    FILE*CustomerID,*fp;
    int j=0,a=0,b=0,t=0;
    char CustID[11],name[81],gender[7],phone[12],pass[81],email[81],addr[81];
    float balance;
    CustomerID=fopen("CustomerID.txt","r");
    while(fscanf(CustomerID,"%s%s%s%s%s%s%s%f",cust[j].ID,cust[j].Name,cust[j].Gender,
                 cust[j].Phone,cust[j].Password,cust[j].Email,cust[j].Addr,&cust[j].Balance)!=EOF)
    {
        j++;
    }
    fclose(CustomerID);
    fp=fopen("CustomerID.txt","w");
    for(a=0;a<j;a++)
    {
        if(strcmp(CUST.ID,cust[a].ID)!=0)
        {t++;}
        else
            break;
    }
    
    for(b=a;b<j;b++)
    {
        cust[b]=cust[b+1];
    }
    j=j-1;
    
    
    for(;j>0;j--)
    {
        fprintf(fp,"%s %s %s %s %s %s %s %.2f\n",cust[j-1].ID,cust[j-1].Name,cust[j-1].Gender,
                cust[j-1].Phone,cust[j-1].Password,cust[j-1].Email,cust[j-1].Addr,cust[j-1].Balance);
    }
    fclose(fp);//ɾ��ԭ�пͻ���Ϣ
    j=j+1;
}

//************************************************************����Ա����********************************************************************//
void readCommodityFile()//
{
    FILE *op2;
    op2=fopen("good.txt","r");
    
    if(op2==NULL)
    {
        printf("�ļ������ˣ�");
        getchar();
        exit(1);
    }
    
    for(goodsNum=0;!feof(op2);goodsNum++)
        fscanf(op2,"%s%s%s%f%f%d%d%f%s%s%d\n",goods[goodsNum].Name,goods[goodsNum].Num,goods[goodsNum].Market,&goods[goodsNum].SellPrice
               ,&goods[goodsNum].PurchasePrice,&goods[goodsNum].Sales
               ,&goods[goodsNum].Stock,&goods[goodsNum].SalePrice
               ,goods[goodsNum].SaleStart,goods[goodsNum].SaleEnd,&goods[goodsNum].Discount);
    
    fclose(op2);
}

//*��ȡ����Ա��Ϣ����*//
void readManagerFile()
{
    FILE *op1;
    op1=fopen("manager.txt","r");
    
    if(op1==NULL)
    {
        printf("�ļ�������");
        getchar();
        exit(1);
    }
    for(managerNum=0;!feof(op1);managerNum++)
    {
        fscanf(op1,"%s%s%s%s%s\n",manager[managerNum].magid,manager[managerNum].market,manager[managerNum].name,manager[managerNum].email,manager[managerNum].code);
    }
    
    
    fclose(op1);
}

void readOrderFile()////
{
    FILE *op3;
    
    op3=fopen("order.txt","r");
    
    if(op3==NULL)
    {
        printf("�ļ������ˣ�");
        getchar();
        exit(1);
    }
    
    for(orderNum=0;!feof(op3);orderNum++)
        fscanf(op3,"%s%s%s%s%s%f%f%f%d%d%d%s%s%s%d%f\n",order[orderNum].Num,order[orderNum].Name,order[orderNum].Market,order[orderNum].SaleStart,order[orderNum].SaleEnd,&order[orderNum].SellPrice,&order[orderNum].PurchasePrice,&order[orderNum].SalePrice,&order[orderNum].Sales,&order[orderNum].Stock,&order[orderNum].Amount,order[orderNum].SaleDay,order[orderNum].ID,order[orderNum].OrderNum,&order[orderNum].Pay,&order[orderNum].Total);
    fclose(op3);
}

//*��¼����*//
void login()
{
    char id[size],code[size];//����ID������//
    int i;//ѭ����ӱ���//
    system("cls");
    printf("****����Ա��¼****\n");
    readManagerFile();
    while(1)
    {
        printf("����ID��6-10�����ֺ���ĸ����ɣ�����������ID��");
        rewind(stdin);
        gets(id);
        while(strcmp(id,manager[i].magid)!=0)
        {
            i++;
            if(i==managerNum)
            {
                system("cls");
                printf("�Բ���������ID��Ч,");
                printf("���������� :");
                rewind(stdin);
                gets(id);
                i=0;
            }
        }
        
        printf("�������ID��ȷ������������:");
        rewind(stdin);
        gets(code);
        while(strcmp(code,manager[i].code)!=0)
        {
            system("cls");
            printf("�Բ����������������");
            printf("���������� :");
            rewind(stdin);
            gets(code);
        }
        break;
    }
    yourNum=i;
    printf("����Ա���ɹ���½");
    strcpy(market,manager[i].market);
    printf("%s����,",market);
    printf("�밴�س�������\n");
    rewind(stdin);
    getchar();
    system("cls");//����//
    comeIn();//����//
}

//*�������Ա���溯��*//
void comeIn()
{
    printf ("1.���붩������\n");
    printf ("2.������Ʒ����\n");
    printf("3.������Ϣ����\n");
    printf("4.�˳�\n");
    printf ("����������ѡ��");
    while(1)
    {
        rewind(stdin);
        scanf("%c",&option);
        switch(option)
        {
            case '1':
                ordermanage();//���붩������//
                break;
            case '2':
                goodsmanage();//������Ʒ����//
                break;
            case '3':
                personalmanage(); //���������Ϣ����//
            case '4':
                exit(1);
                break;
            default:
                printf ("����������������������:");
        }
    }
}

//*��������*//
void ordermanage()
{
    char option;
    system("cls");
    printf ("****��������****\n");
    printf ("1.�鿴�û��������\n");
    printf ("2.ͳ���û�������Ϣ\n");
    printf("3.������һ��\n");
    printf ("����������ѡ��");
    while(1)
    {
        rewind(stdin);
        scanf("%c",&option);
        switch(option)
        {
            case '1':
                searchOrderInfor();//�鿴�û��������
                break;
            case '2':
                calOrderInfor();//ͳ���û�������Ϣ
                break;
            case '3':
                comeIn();//�����ϼ�
                break;
            default:
                printf("------------------------------------------------------\n");
                printf("������������������\n");
                rewind(stdin);
                getchar();
                system("cls");
                ordermanage();
        }
    }
}

//*����������Ϣ����*//
void searchOrderInfor()
{
    int i=0,j;
    char goodName[size];
    readOrderFile();//��ȡ������Ϣ//
    printf("����������Ҫ���ҵ���Ʒ:");
    rewind(stdin);
    gets(goodName);
    printf("\n    �������          ��������          ��Ʒ���        ��Ʒ����         ��Ʒ����         ���� \n");
    
    for(j=0;j<orderNum;)
    {
        if((strcmp(goodName,order[j].Name)==0)&&(strcmp(market,order[j].Market)==0))
        {
            printf("%s %5s %10s %15s %15d %15.2f\n",order[j].OrderNum,order[j].SaleDay,order[j].Num,order[j].Name,order[j].Amount,order[j].SellPrice);
            j++;
            i++;
            continue;
        }
        
        if((strcmp(goodName,order[j].Name)!=0)||(strcmp(market,order[j].Market)!=0))
        {
            j++;
            continue;
        }
    }
    
    if(i==0){ //���������
        printf("-------------------------------------------------------\n");
        printf("����������Ʒ�����ڣ�����س�������һҳ��");
        rewind(stdin);
        getchar();
        system("cls");
        ordermanage();
    }
    
    printf("-------------------------------------------------------");
    printf("\n����س��ص���һҳ");
    rewind(stdin);
    getchar();
    ordermanage();//���ض����������//
    
}

//*ͳ�ƶ�����Ϣ*//
void calOrderInfor()
{
    char option;
    system("cls");
    printf ("****ͳ���û�������Ϣ****\n");
    printf ("1.������Ӫҵ�ڼ��ڵ�Ӫҵ��\n");
    printf ("2.����������Ʒ��������\n");
    printf ("3.��Ӫҵ�����Ʒ��������\n");
    printf ("4.��ʾ������ߺ�������͵���Ʒ\n");
    printf ("5.�ж������ͽ���\n");
    printf("6.������һ��\n");
    printf ("����������ѡ��");
    
    while(1)
    {
        rewind(stdin);
        scanf("%c",&option);
        switch(option)
        {
            case '1':
                system("cls");
                TurnOverView();//ͳ��Ӫҵ��
                break;
            case '2':
                SalesRank();//����������
                break;
            case '3':
                TurnOverRank();//��Ӫҵ������
                break;
            case '4':
                ProfitView();//��ʾ������ߺ���͵���Ʒ
                break;
            case '5':
                UnSoldNStock();//�ж������ͽ���
                break;
            case '6':
                return ordermanage();	//�����ϼ�
                break;
            default:
                printf ("����������������������:");
        }
        
        
    }
    
}

//*ͳ��Ӫҵ�� *//
void TurnOverView()
{
    int j;//ѭ������
    int Amount;
    float SellPrice;
    float total=0.00;
    readOrderFile();
    for(j=0;j<orderNum;)
    {
        if((order[j].Pay==1)&&(strcmp(market,order[j].Market)==0))
        {
            SellPrice=order[j].SellPrice;
            Amount=order[j].Amount;
            total+=SellPrice*Amount;
            j++;
            continue;
        }
        
        
        j++;
        
        
    }
    printf("%s��Ӫҵ��Ϊ:%5.2f\n",market,total);
    printf("-------------------------------------------------------");
    printf("\n����س��ص���һҳ");
    rewind(stdin);
    getchar();
    return calOrderInfor();
    
    
    
}

//*����������*//
void SalesRank()
{
    ToTemp();
    int i,j;
    int Sales1,Sales2;
    system("cls");
    printf ("****��������С��������****\n");
    for (i = 0; i < goodsNum - 1; i++)
    {
        for (j = 0; j < goodsNum - 1 - i; j++)
        {
            Sales1=temp[j].Sales;
            Sales2=temp[j+1].Sales;
            if (Sales1> Sales2)
            {
                sort = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = sort;
            }
        }
    }
    
    printf("��Ʒ����   ��Ʒ���   ����    ��Ʒ�ۼ�    ����      ���     �ۿۼ�\n");
    for(i=0 ; i<goodsNum ; i++)
    {
        if(strcmp(market,temp[i].Market)==0)
            printf("%s %10s %9s %8.2f %8d %10d %10.2f\n"
                   ,temp[i].Name,temp[i].Num,temp[i].Market,temp[i].SellPrice
                   ,temp[i].Sales,temp[i].Stock,temp[i].SalePrice);
    }
    printf("-------------------------------------------------------");
    printf("\n����س����ص���һҳ");
    rewind(stdin);
    getchar();
    return calOrderInfor();
}

//*��Ӫҵ������*//
void TurnOverRank()
{
    ToTemp();
    int i,j;
    int Sales1,Sales2;
    float SellPrice1,SellPrice2,turnOver1,turnOver2;
    system("cls");
    printf ("****��Ӫҵ���С��������****\n");
    
    for (i = 0; i < goodsNum - 1; i++)
    {
        for (j = 0; j < goodsNum - 1 - i; j++)
        {
            SellPrice1=temp[j].SellPrice;
            SellPrice2=temp[j+1].SellPrice;
            Sales1=temp[j].Sales;
            Sales2=temp[j+1].Sales;
            turnOver1=SellPrice1*Sales1;
            turnOver2=SellPrice2*Sales2;
            if (turnOver1 > turnOver2)
            {
                sort = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = sort;
            }
        }
    }
    
    printf("��Ʒ����   ��Ʒ���   ����    ��Ʒ�ۼ�    ����      ���     �ۿۼ�\n");
    for(i=0 ; i<goodsNum ; i++)
    {
        if(strcmp(market,temp[i].Market)==0)
            printf("%s %10s %9s %8.2f %8d %10d %10.2f\n"
                   ,temp[i].Name,temp[i].Num,temp[i].Market,temp[i].SellPrice
                   ,temp[i].Sales,temp[i].Stock,temp[i].SalePrice);
    }
    printf("-------------------------------------------------------");
    printf("\n����س����ص���һҳ");
    rewind(stdin);
    getchar();
    return calOrderInfor();
}

void DeleteLine(int j){
	FILE *fin;
	fpos_t pos_w,pos_r,pos;
	int i,k;
	char *one_line;
	 
	one_line = (char *) malloc(1000*sizeof(char));
	 
	fin = fopen ("cart.txt","rb+");
	for (i=0;i<j;i++) fgets(one_line,999,fin);
	
	fgetpos (fin,&pos_w);
	fgets(one_line,999,fin); // delete
	fgetpos (fin,&pos_r);
	pos = pos_r;
	
	while (1 == 1)
	{
		fsetpos (fin,&pos);
		if (fgets(one_line,999,fin) ==NULL)
			break;
		fgetpos (fin,&pos_r);
		pos = pos_w;
		fsetpos (fin,&pos);
		fprintf(fin,"%s",one_line);
		fgetpos (fin,&pos_w);
		pos = pos_r;
	}
	pos = pos_w;
	fsetpos (fin,&pos);
	k = strlen(one_line);
	for (i=0;i<k;i++) fputc(0x20,fin);
	fclose(fin);
} 

//*��ȡ������Ϣ��Temp*//
void ToTemp()
{
    FILE *op2;
    op2=fopen("good.txt","r");
    
    if(op2==NULL)
    {
        printf("�ļ������ˣ�");
        rewind(stdin);
        getchar();
        exit(1);
    }
    
    for(goodsNum=0;!feof(op2);goodsNum++)
        fscanf(op2,"%s%s%s%f%f%d%d%f%s%s%d\n",temp[goodsNum].Name,temp[goodsNum].Num,temp[goodsNum].Market,&temp[goodsNum].SellPrice
               ,&temp[goodsNum].PurchasePrice,&temp[goodsNum].Sales
               ,&temp[goodsNum].Stock,&temp[goodsNum].SalePrice
               ,temp[goodsNum].SaleStart,temp[goodsNum].SaleEnd,&temp[goodsNum].Discount);
    
    
    fclose(op2);
}

//*��ʾ������ߺ���͵���Ʒ*//
void ProfitView()
{
    system("cls");
    readCommodityFile();
    int i,j;
    int commodityNum;
    float max,min;
    char commodity[row][column];
    char maxcommodity[size],mincommodity[size];
    float PurchasePrice[size],SellPrice[size],profit[size];
    int Sales[size];
    
    
    for(commodityNum=0,j=0;j<goodsNum;j++)
    {
        
		
		if(strcmp(market,goods[j].Market)==0)
        {
		strcpy(commodity[commodityNum],goods[j].Name);
		PurchasePrice[commodityNum]=goods[j].PurchasePrice;
        SellPrice[commodityNum]=goods[j].SellPrice;
        Sales[commodityNum]=goods[j].Sales;
        profit[commodityNum]=(float)(Sales[commodityNum]*(SellPrice[commodityNum]-PurchasePrice[commodityNum]));
        commodityNum++;
        }
        
    }

    max=profit[0];
    min=profit[0];
	strcpy(maxcommodity,commodity[0]);
	strcpy(mincommodity,commodity[0]);
	
	for(i=1;i<commodityNum;i++)
        {
		
			if(profit[i]>=max)
        		{
            	max=profit[i];
                }
        
        	if(profit[i]<=min)
        		{
            	min=profit[i];
    			}
        }
        

        
    for(i=0;i<commodityNum;i++)
        {
        	if(profit[i]==max)
        	{
        	strcpy(maxcommodity,commodity[i]);
			printf("������ߵ���Ʒ��:%s \n",maxcommodity);	
			}
		}
		
	printf("---------------------------------------------------------------------\n");
			
	for(i=0;i<commodityNum;i++)
        {	
			if(profit[i]==min)
			{
			strcpy(mincommodity,commodity[i]);
			printf("������͵���Ʒ��:%s \n",mincommodity);	
			}
		}
    
    printf("-------------------------------------------------------");
    printf("\n����س��ص���һҳ");
    rewind(stdin);
    getchar();
    return calOrderInfor();
    
}

//*�ж������ͽ���*//
void UnSoldNStock()
{
    system("cls");
    readCommodityFile();
    int i,j;
    int commodityNum=0;
    char commodity[row][column];
    int Sales[size],Stock[size];
	float YON[size];
    
    for(commodityNum=0,j=0;j<goodsNum;j++)
    {
        
		if(strcmp(market,goods[j].Market)==0)
        {
		strcpy(commodity[commodityNum],goods[j].Name);
		Stock[commodityNum]=goods[j].Stock;
        Sales[commodityNum]=goods[j].Sales;
        YON[commodityNum]=(float)Sales[commodityNum]/(Sales[commodityNum]+Stock[commodityNum]);
        commodityNum++;
        }
        
    }
    
    printf("��Ҫ��������Ʒ�У�"); 
	for(i=0;i<commodityNum;i++)
    {
		if(YON[i]>=0.5)
		{
		printf("%s ",commodity[i]);
		} 
	}
		
	printf("\n��������Ʒ�У�");
	for(i=0;i<commodityNum;i++)
    {	
		if(YON[i]<=0.3)
		{ 
		printf("%s ",commodity[i]);
		} 
		
	}
	
	printf("\n-------------------------------------------------------");
    printf("\n����س����ص���һҳ");
    rewind(stdin);
    getchar();
    return calOrderInfor();
}

//*��Ʒ����*//
void goodsmanage()
{
    char option;
    system("cls");
    printf ("****��Ʒ����****\n");
    printf ("1.��ѯ�ϼ���Ʒ��Ϣ\n");
    printf ("2.�����Ʒ\n");
    printf("3.������һ��\n");
    printf ("����������ѡ��");
    while(1)
    {
        rewind(stdin);
        scanf("%c",&option);
        switch(option)
        {
            case '1':
                searchgoods();//��ѯ�ϼ���Ʒ��Ϣ
                break;
            case '2':
                addgoods();//�����Ʒ
                break;
            case '3':
                comeIn();//�����ϼ�
                break;
            default:
                printf("------------------------------------------------------\n");
                printf("���������밴�س���������\n");
                rewind(stdin);
                getchar();
                system("cls");
                goodsmanage();
        }
    }
}


//*��ѯ�ϼ���Ʒ��Ϣ*//
void searchgoods()
{
    int i=0,j;
    char goodName[size];
    readCommodityFile();//��ȡ������Ϣ//
    printf("����������Ҫ���ҵ���Ʒ:");
    rewind(stdin);
    gets(goodName);
    printf("---------------------------------------------------------------------------------------------------------------\n");
    printf("\n��Ʒ����       ��Ʒ���         ��������        ��Ʒ����        ��Ʒ������         ����      ���     �ۿۼ� \n");
    
    for(j=0;j<goodsNum;)
    {
        if((strcmp(goodName,goods[j].Name)==0)&&(strcmp(market,goods[j].Market)==0))
        {
            printf("%s %15s %15s %15.2f %15.2f %15d %9d %10.2f\n",goods[j].Name,goods[j].Num,goods[j].Market,goods[j].SellPrice,goods[j].PurchasePrice,goods[j].Sales,goods[j].Stock,goods[j].SalePrice);
            j++;
            i++;
            continue;
        }
        
        if((strcmp(goodName,goods[j].Name)!=0)||(strcmp(market,goods[j].Market)!=0))
        {
            j++;
            continue;
        }
        
    }
    
    if(i==0){ //���������
        printf("-------------------------------------------------------\n");
        printf("����������Ʒ�����ڣ�����س�������һҳ��");
        rewind(stdin);
        getchar();
        system("cls");
        goodsmanage();
    }
    
    printf("-------------------------------------------------------");
    printf("\n����س��ص���һҳ");
    rewind(stdin);
    getchar();
    goodsmanage();//���ض����������//
}

//*�����Ʒ*//
void addgoods()
{
    FILE *op2;
    op2=fopen("good.txt","r");
    
    if(op2==NULL)
    {
        printf("�ļ������ˣ�");
        rewind(stdin);
        getchar();
        exit(1);
    }
    
    for(goodsNum=0;!feof(op2);goodsNum++)
        fscanf(op2,"%s%s%s%f%f%d%d%f%s%s%d\n",goods[goodsNum].Name,goods[goodsNum].Num,goods[goodsNum].Market,&goods[goodsNum].SellPrice
               ,&goods[goodsNum].PurchasePrice,&goods[goodsNum].Sales
               ,&goods[goodsNum].Stock,&goods[goodsNum].SalePrice
               ,goods[goodsNum].SaleStart,goods[goodsNum].SaleEnd,&goods[goodsNum].Discount);
    
    fclose(op2);
    
    char Name[size],goodsnum[size],SuperMarket[size],discountTimeOn[size],discountTimeOff[size];
    char option,option1;
    int Sales=0,Stock;
    int i=0,k=0,d=0;
    int length,length2,length3;
    int discount;
    float SellPrice,PurchasePrice,SalePrice,discountprice;
    
    system("cls");
    
    //�����ƷID
    printf("��������Ʒ�ţ���ʽΪ2λ��ĸ+4λ���֣�");
    fflush(stdin);
    gets(goodsnum);
    length=strlen(goodsnum);
    while(1)
    {
        
        while(length!=6)
        {
            printf("��������ȷ���ȵ���Ʒ��\n");
            fflush(stdin);
            gets(goodsnum);
            length=strlen(goodsnum);
        }
        
        for(i=0;i<goodsNum;i++)
        {
            if (isalpha(goodsnum[0])&&isalpha(goodsnum[1])&&isdigit(goodsnum[2])&&isdigit(goodsnum[3])&&isdigit(goodsnum[4])&&isdigit(goodsnum[5])&&(strcmp(goods[i].Num,goodsnum)!=0))
            {
                k++;
                continue;
            }
            
            printf("��������ȷ��ʽ����Ʒ��\n");
            fflush(stdin);
            gets(goodsnum);
            break;
        }
        
        if(k==goodsNum)
            break;
        
    }
    printf("���ѳɹ������Ʒ���\n");
    
    //�����Ʒ����
    printf("��������Ʒ���ƣ�");
    while(1)
    {
        fflush(stdin);
        gets(Name);
        for (i=0;i<goodsNum;i++)
        {
            if (strcmp(Name,goods[i].Name)==0)
            {
                break;
            }
            
            d++;
        }
        if(d==goodsNum)
        {
            printf("���ѳɹ�������ơ�\n");
            break;
        }
        
        printf("���������Ʒ�����Ѵ��ڣ�����������: \n");
    }
    
    //�����Ʒ��������
    strcpy(SuperMarket,market);
    
    
    //�����Ʒ����
    printf("��������Ʒ�����۸� ");
    rewind(stdin);
    scanf("%f",&PurchasePrice);
    
    //�����Ʒ����
    printf("��������Ʒ���۵��ۣ�");
    rewind(stdin);
    scanf("%f",&SellPrice);
    
    //�����Ʒ�ۿۼ�
    printf("��ѡ����Ʒ�Ƿ����ۿۡ�1.���ۿ� 2.���ۿ�\n");
    rewind(stdin);
    scanf("%c",&option1);
    switch(option1)
    {
        case '1':
            discount=1;
            printf("��������Ʒ�ۿۼۣ�");
            rewind(stdin);
            scanf("%f",&discountprice);
            break;
            
        case '2':
            discount=0;
            break;
            
        default:
            printf("������1��2\n");
            
    }
    
    //�����Ʒ����
    
    while(1)
    {
        printf("��治��Ϊ��ֵ����������Ӹ���Ʒ�Ŀ�棺");
        fflush(stdin);
        scanf("%d",&k);
        if(k>=0)
        {
			Stock=k;
        	printf("����ѳɹ����\n");
        	break;
    	}
    }
    
    //��Ʒ�ۿۿ�ʼʱ��
    printf("��������Ʒ�ۿۿ�ʼʱ�䣬��ʽΪyyyy:mm:dd:hh:mm�����û���ۿۣ�����д0000:00:00:00:00\n");
    printf("�����룺");
    rewind(stdin);
    scanf("%s",discountTimeOn);
    length2=strlen(discountTimeOn);
    while(length2!=16)
    {
        printf("��������ȷ���ȵ�ʱ��: \n");
        rewind(stdin);
        gets(discountTimeOn);
        length2=strlen(discountTimeOn);
    }
    
    
    while(1)
    {
        if(isdigit(discountTimeOn[0])&&isdigit(discountTimeOn[1])&&isdigit(discountTimeOn[2])&&isdigit(discountTimeOn[3])
           &&isdigit(discountTimeOn[5])&&isdigit(discountTimeOn[6])&&isdigit(discountTimeOn[8])&&isdigit(discountTimeOn[9])
           &&isdigit(discountTimeOn[11])&&isdigit(discountTimeOn[12])&&isdigit(discountTimeOn[14])&&isdigit(discountTimeOn[15])
           &&discountTimeOn[4]==':'&&discountTimeOn[7]==':'&&discountTimeOn[10]==':'&&discountTimeOn[13]==':')
            printf("���ѳɹ�������Ʒ�ۿۿ�ʼʱ�䡣\n");
        break;
        
        
        
        printf("������ĸ�ʽ��������������: ");
        rewind(stdin);
        gets(discountTimeOn);
        
        
    }
    
    //��Ʒ�ۿ۽���ʱ��
    printf("��������Ʒ�ۿ۽���ʱ�䣬��ʽΪyyyy:mm:dd:hh:mm�����û���ۿۣ�����д0000:00:00:00:00\n");
    printf("�����룺 ");
    rewind(stdin);
    scanf("%s",discountTimeOff);
    length3=strlen(discountTimeOff);
    while(length3!=16)
    {
        printf("��������ȷ���ȵ�ʱ��: \n");
        rewind(stdin);
        gets(discountTimeOff);
        length2=strlen(discountTimeOn);
    }
    
    while(1)
    {
        if(isdigit(discountTimeOff[0])&&isdigit(discountTimeOff[1])&&isdigit(discountTimeOff[2])&&isdigit(discountTimeOff[3])
           &&isdigit(discountTimeOff[5])&&isdigit(discountTimeOff[6])&&isdigit(discountTimeOff[8])&&isdigit(discountTimeOff[9])
           &&isdigit(discountTimeOff[11])&&isdigit(discountTimeOff[12])&&isdigit(discountTimeOff[14])&&isdigit(discountTimeOff[15])
           &&discountTimeOff[4]==':'&&discountTimeOff[7]==':'&&discountTimeOff[10]==':'&&discountTimeOff[13]==':')
            printf("���ѳɹ�������Ʒ�ۿ۽���ʱ�䡣\n");
        break;
        
        printf("������ĸ�ʽ�������������롣\n");
        rewind(stdin);
        gets(discountTimeOff);
        
        
    }
    
    //�������޸ġ�ȡ��
    printf("����������ѡ�񷢲����޸Ļ�ȡ����1.���� 2.�޸� 3.ȡ��\n");
    rewind(stdin);
    scanf("%c",&option);
    switch(option)
    {
        case '1':
            op2=fopen("good.txt","a+");
            fprintf(op2, "%s %s %s %.2f %4.2f %d %d %4.2f %s %s %d\n",Name,goodsnum,SuperMarket,SellPrice,PurchasePrice,Sales,Stock,discountprice,discountTimeOn,discountTimeOff,discount);
            fclose(op2);
            printf("\n���ѳɹ������Ʒ��");
            break;
            
        case '2':
            return addgoods();
            break;
            
        case '3':
            return goodsmanage();
            break;
            
        default:
            printf("------------------------------------------------------\n");
            printf("���������밴�س���������\n");
            rewind(stdin);
            getchar();
            system("cls");
            goodsmanage();
    }
}

//*������Ϣ����*//
void personalmanage()
{
    char option;
    system("cls");
    printf ("****������Ϣ����****\n");
    printf ("1.�޸�����\n");
    printf ("2.�޸�����\n");
    printf("3.������һ��\n");
    printf ("����������ѡ��");
    while(1)
    {
        rewind(stdin);
        scanf("%c",&option);
        switch(option)
        {
            case '1':
                codeRevise(); //�޸�����
                break;
            case '2':
                emailRevise();//�޸�����
                break;
            case '3':
                comeIn();//�����ϼ�
                break;
            default:
                printf("------------------------------------------------------\n");
                printf("���������밴�س���������\n");
                rewind(stdin);
                getchar();
                system("cls");
                personalmanage();
        }
    }
}


//*�޸�����*//
void codeRevise()
{
    FILE *op1;
    op1=fopen("manager.txt","r");
    
    if(op1==NULL)
    {
        printf("�ļ�������");
        rewind(stdin);
        getchar();
        exit(1);
    }
    for(managerNum=0;!feof(op1);managerNum++)
    {
        fscanf(op1,"%s%s%s%s%s\n",manager[managerNum].magid,manager[managerNum].market,manager[managerNum].name,manager[managerNum].email,manager[managerNum].code);
    }
    
    fclose(op1);
    
    int i;
    char NewCode[size];
    system("cls");
    printf("�������µ����룺");
    rewind(stdin);
    gets(NewCode);
    strcpy(manager[yourNum].code,NewCode);
    fopen("manager.txt","w+");
    for(i=0;i<managerNum;i++)
    {
        fprintf(op1,"%s %s %s %s %s\n",manager[i].magid,manager[i].market,manager[i].name,manager[i].email,manager[i].code);
    }
    
    fclose(op1);
    printf("*���������޸ĳɹ�*\n");
    printf("-------------------------------------------------------");
    printf("\n����س����ص���һҳ");
    rewind(stdin);
    getchar();
    return personalmanage();
}
 
//*�޸�����*//
void emailRevise()
{
   	FILE *op1;
    op1=fopen("manager.txt","r");
    
    if(op1==NULL)
    {
        printf("�ļ�������");
        rewind(stdin);
        getchar();
        exit(1);
    }
    for(managerNum=0;!feof(op1);managerNum++)
    {
        fscanf(op1,"%s%s%s%s%s\n",manager[managerNum].magid,manager[managerNum].market,manager[managerNum].name,manager[managerNum].email,manager[managerNum].code);
    }
    
    fclose(op1);
    
    int i;
    char NewEmail[size];
    system("cls");
    printf("�������µ����䣺");
    rewind(stdin);
    gets(NewEmail);
    
    if(IsEmail(NewEmail))
    {
        strcpy(manager[yourNum].email,NewEmail);
        fopen("manager.txt","w+");
        for(i=0;i<managerNum;i++)
        {
            fprintf(op1,"%s %s %s %s %s\n",manager[i].magid,manager[i].market,manager[i].name,manager[i].email,manager[i].code);
        }
        
        fclose(op1);
        printf("*���������޸ĳɹ�*\n");
        printf("-------------------------------------------------------");
        printf("\n����س����ص���һҳ");
        rewind(stdin);
        getchar(); 
        return personalmanage();
    }
    
    else
        printf("*������������ʽ��������������*\n");
    getchar();
    getchar();
    return 	emailRevise();
    
}

//�ж��ۿ��Ƿ�����Ч���� 
void CheckTime(){
    FILE *op;
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    int j;
    
    time( &rawtime );
    info = localtime( &rawtime );
    strftime(buffer,80,"%Y:%m:%d:%H:%M",info);
    for(j=0;j<ItemNum;j++){
    	while(goods[j].Discount==1){
	        if (strcmp(buffer,goods[j].SaleStart)>=0 && strcmp(buffer,goods[j].SaleEnd)<=0){
	            goods[j].Discount = 1;
				break;}
	        else{
	            goods[j].Discount = 0;
				break;}
        }
    }
}



