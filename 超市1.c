#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define N 111
void denglu();
void charger_denglu();
void seller_denglu();
void seller1_denglu();
void seller_menu();
void goods_information();
void goods_change();
void goods_sell();
void goods_search(void);
void goods_del();
void goods_add(void);
void page_title(char *menu_item);
void return_confirm(void);
void sell_record();
void manner_denglu();
void seller_put();
void seller_change();
void seller_add();
void seller_del();
struct GOODS
{
	int num;
	char name[30];
	int price;
	int amount;
	char mfrs[20];
	char buyer[20];
	char beizhu[50];
}goods[100];
//��Ʒ��š���Ʒ���ơ���Ʒ�۳����������ۡ�������Ʒ�ܽ��������ܽ�
struct GOODS1
{
	int num;
	char name[30];
	int price;
	int amount;
	int allprice;
}allsell[100];
struct SHOP
{
	int zhanghao;
	int mima;
	int num;
	int quanxian[3];
}ren[10]={{1,1,1,{1,2,3}},{2,2,2,{1,2,3}},{3,3,3,{1,2,3}},{4,4,4,{1,2,3}}};
void return_confirm(void)
 { 
	printf("\n����������ء���\n");
getch(); 
}
void page_title(char *menu_item)  
 
{ 
 system("cls"); 

printf("\t\t\t************��ӭʹ�ó�������ϵͳ**********\n\n- %s -\n\n",menu_item);
} 
void open_goods(FILE *fp)//���ļ�
{
	fp=fopen("goods.txt","a+");
}
void fscanf1_goods(FILE *fp,int n,struct GOODS *goods)//��ȡ�ļ�����
{
	int i;
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d\t%d\t%d\n",&goods[i].num,&goods[i].price,&goods[i].amount);
		fscanf(fp,"%s\t%s\t%s\t%s\n",&goods[i].name,&goods[i].mfrs,&goods[i].buyer,&goods[i].beizhu);
	}
}
void fscanf2_goods(FILE *fp,int n,struct GOODS1 *goods)//��ȡ�ļ�������GOODS1
{
	int i;
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d\t%d\t%d\n",goods[i].num,goods[i].price,goods[i].amount);
		fscanf(fp,"%s\t%s\n",goods[i].name,goods[i].allprice);
	}
}
void fscanf3_goods(FILE *fp,int n,struct SHOP *goods)//��ȡ�ļ�����
{
	int i,j;
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d\t%d\t%d\n",&goods[i].num,&goods[i].zhanghao,&goods[i].mima);
		for(j=0;j<3;j++)
			fscanf(fp,"%d\t%d\t%d\n",&goods[i].quanxian[j]);
		
	}
}
void fprintf1_goods(FILE *fp,int n,struct GOODS *goods)//�ѽṹ��GOODSд���ļ�
{
		int i;
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%d\t%d\t%d\n",goods[i].num,goods[i].price,goods[i].amount);
		fprintf(fp,"%s\t%s\t%s\t%s\n",goods[i].name,goods[i].mfrs,goods[i].buyer,goods[i].beizhu);
	}
}
void fprintf2_goods(FILE *fp,int n,struct GOODS1 *goods)//�ѽṹ��GOODS1д���ļ�
{
		int i;
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%d\t%d\t%d\n",goods[i].num,goods[i].price,goods[i].amount);
		fprintf(fp,"%s\t%s\n",goods[i].name,goods[i].allprice);
	}
}
void fprintf3_goods(FILE *fp,int n,struct SHOP *goods)//��ȡ�ļ�����
{
	int i,j;
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%d\t%d\t%d\n",goods[i].num,goods[i].zhanghao,goods[i].mima);
		for(j=0;j<3;j++)
			fprintf(fp,"%d\t%d\t%d\n",goods[i].quanxian[j]);
		
	}
}
int quan,shouchu,ren1;
void goods_add(void) //������Ʒ
{ int n; 
FILE *fp,*fp1;
fp=fopen("goods.txt","a+");
fp1=fopen("quanj.txt","r");
fscanf(fp1,"%d\n%d\n%d\n",&quan,&shouchu,&ren1);
fclose(fp1);
fp1=fopen("quanj.txt","w");
 for(n=quan;n<100;n++) 
 { 
page_title("ע������Ʒ");
 printf("��Ʒ��:");
    scanf("%d",&goods[n].num);
if(goods[n].num==0) break;
 printf("��Ʒ��:");
 scanf("%s",&goods[n].name);
printf("��Ʒ����:");
scanf("%d",&goods[n].price);
 printf("�����Ʒ����:");
 scanf("%d",&goods[n].amount);
 printf("��������:");
 scanf("%s",&goods[n].mfrs);  
 printf("�ɹ�Ա����");
 scanf("%s",&goods[n].buyer);
printf("��ע��Ϣ");
scanf("%s",&goods[n].beizhu);
fprintf(fp,"%d\t%d\t%d\n",goods[n].num,goods[n].price,goods[n].amount);
fprintf(fp,"%s\t%s\t%s\t%s\n",goods[n].name,goods[n].mfrs,goods[n].buyer,goods[n].beizhu);
quan++;
}
 fclose(fp);
 fprintf(fp1,"%d\n%d\n%d\n",quan,shouchu,ren1);
 fclose(fp1);
return_confirm();
}
void goods_del()//ɾ����Ʒ
{
	FILE *fp,*fp1;
	int n,num,i,amount;
	fp=fopen("goods.txt","a+");
	fp1=fopen("quanj.txt","r");
fscanf1_goods(fp,100,goods);
fscanf(fp1,"%d\n%d\n%d\n",&quan,&shouchu,&ren1);
fclose(fp1);
	fp1=fopen("quanj.txt","w");
   page_title("ɾ����Ʒ");
   printf("��������Ҫɾ������Ʒ�ı�ţ�");
   scanf("%d",&num);
	printf("��������Ҫɾ������Ʒ��������");
scanf("%d",&amount);
for(n=0;n<1000;n++)
{
	if(goods[n].num==num)break;
}
if(amount<goods[n].amount)
goods[n].amount=goods[n].amount-amount;
else if(amount=goods[n].amount)
{
       for(i=n;i<quan;i++)   
	   {   goods[i].num=goods[i+1].num;
			goods[i].price=goods[i+1].price;
			goods[i].amount=goods[i+1].amount;
           strcpy(goods[i].name,goods[i+1].name);
		   //strcpy(goods[i].price,goods[i+1].price);
		   strcpy(goods[i].mfrs,goods[i+1].mfrs);
		   strcpy(goods[i].buyer,goods[i+1].buyer);
		   strcpy(goods[i].beizhu,goods[i+1].beizhu);
		   //strcpy(goods[i].amount,goods[i+1].amount);
		}
		quan--;	
	   
   printf("����Ʒ��ɾ��.\n");
}
fprintf1_goods(fp,100,goods);
fprintf(fp1,"%d\n%d\n%d\n",quan,shouchu,ren1);
fclose(fp);
fclose(fp1);
return_confirm();
}
void goods_search()//��Ʒ��ѯ
{ 
	FILE *fp,*fp1;
	int n,i=1,j=0;
	char nam[30];
  fp=fopen("goods.txt","r+");
  fp1=fopen("quanj.txt","r+");
fscanf1_goods(fp,quan,goods);
fscanf(fp1,"%d\n%d\n%d\n",&quan,&shouchu,&ren1);
  page_title("��Ʒ��ѯ");
   printf("��������Ʒ��:");
  scanf("%s",nam);
   for(n=0;n<quan;n++)
  {  if((strcmp(goods[n].name,nam)==0))
   {  printf("���:%d\t",goods[n].num);
      printf("��Ʒ��:%s\t",goods[n].name);
	  printf("�۸�:%d\t",goods[n].price);
	  printf("������%d\t",goods[n].amount);
	  i=0;
	}
   }
   if(i==1)
	   printf("�޸���Ʒ��Ϣ\n");
   fclose(fp);
   fclose(fp1);
return_confirm();
}
void goods_sell() //��Ʒ�۳�
{	
   FILE *fp,*fp1,*fp2;
   int sum=0,n,k,num,money,i;
   page_title("��Ʒ����");
   fp=fopen("goods_sell.txt","r+");
	fp1=fopen("goods.txt","r+");
	fp2=fopen("quanj.txt","r+");
 fscanf1_goods(fp,quan,goods);
 fscanf2_goods(fp1,shouchu,allsell);
 fscanf(fp2,"%d\n%d\n%d\n",&quan,&shouchu,&ren1);
 fclose(fp);
	fclose(fp1);
	fclose(fp2);
 fp=fopen("goods_sell.txt","w");
	fp1=fopen("goods.txt","w");
	fp2=fopen("quanj.txt","w");
   for(k=0;n!=0;k++)
   {
	   printf("��������Ҫ�۳���Ʒ�ı�ţ�");
	   scanf("%d",&num);
	   if(num==0)break;
	   printf("����������:");
	   scanf("%d",&n);
	  for(i=0;i<quan;i++)
	   {  
		   if(goods[i].num==num)
		   { 
			 allsell[shouchu].num=goods[i].num;
			 allsell[shouchu].amount=n;
			strcpy(allsell[shouchu].name,goods[i].name);
			allsell[shouchu].price=goods[i].price;
			allsell[shouchu].allprice=n*goods[i].price;
			 sum=sum+n*goods[i].price;
			 goods[i].amount=goods[i].amount-n;
			printf("%s %d %d\n",allsell[shouchu].name,allsell[shouchu].price,allsell[shouchu].amount);
			 shouchu++;
		   }
	   }
   }
   printf("�ܽ�%d\n",sum);
   printf("�����븶�");
   scanf("%d",&money);
   printf("���㣺%d\n",money-sum);
   
   fprintf(fp2,"%d\n%d\n%d\n",quan,shouchu,ren1);
   fprintf1_goods(fp1,quan,goods);
   fprintf2_goods(fp,shouchu,allsell);
   fclose(fp);
	fclose(fp1);
	fclose(fp2);
	printf("�ۻ�����");
	return_confirm();
}

void goods_change()//��Ʒ�޸�
{
	int n,i,a=0;
	FILE *fp,*fp1;
	fp1=fopen("quanj.txt","r+");
fp=fopen("goods.txt","r+");
fscanf1_goods(fp,quan,goods);
fclose(fp);
fp=fopen("goods.txt","w+");
fscanf(fp1,"%d\n%d\n%d\n",&quan,&shouchu,&ren1);
   page_title("�޸���Ʒ��Ϣ");
   printf("������Ҫ�޸ĵ���Ʒ���:");  
   scanf("%d",&i);                 
   for(n=0;n<quan;n++)
   {  if(goods[n].num==i)
	  { printf("�޸���Ʒ����");  
         scanf("%s",goods[n].name); 
    	printf("�޸��������̣�");
      	  scanf("%s",goods[n].mfrs);
       printf("�޸Ĳɹ�Ա���ƣ�");  
         scanf("%s",goods[n].buyer);
       printf("�޸�������");  
    	  scanf("%d",&goods[n].amount);
		printf("�޸ļ۸�");
		scanf("%d",&goods[n].price);
		printf("�޸ı�ע��");
		scanf("%d",&goods[n].beizhu);
		printf("�޸���Ʒ��Ϣ�ɹ�.\n");
		a=1;
	 } 
   } 
   if(a==0)
   printf("\nû���ҵ���ؼ�¼.\n");
fprintf1_goods(fp,100,goods);
fclose(fp);
fclose(fp1);
return_confirm();
}  
void goods_information()//��Ʒ��Ϣ�������
{
menu:page_title("��Ʒ��Ϣ����");
	printf("1. �����Ʒ \t\t2. ɾ����Ʒ\n");
	printf("3.��Ʒ��Ϣ�޸� \t\t4.��Ʒ��Ϣ��ѯ\n");
	printf("5.������һ��\t\t6.�˳�");
	switch(getch())
	 {
		case '1' :  goods_add() ;   break;
		case '2' :  goods_del();   break;
		case '3' :  goods_change();   break;
		case '4' :  goods_search();   break;
		case '5' : seller1_denglu();	break;
		case '6' :	exit(0);
	 }goto menu;
}
void seller1_denglu()//����Ա��½
{
	int n,m,i,a;
	FILE * fp,*fp1;
	fp=fopen("ren.txt","r+");
	fp1=fopen("quanj.txt","r+");
	fscanf(fp1,"%d\n%d\n%d\n",&quan,&shouchu,&ren1);
	fscanf3_goods(fp,ren1,ren);
page_title("����Ա��¼");
	printf("�������˺ţ�");
	scanf("%d",&n);
	printf("����������");
	scanf("%d",&m);
	for(i=0;i<ren1;i++)
	{
		if(ren[i].zhanghao==n)break;
	}
	if(m==ren[i].mima)
		printf("��¼�ɹ�");
	else
	{
		printf("��¼���������µ�¼");
	seller1_denglu();
	}

menu:page_title("����Ա�����˵�");
	printf("1. ��Ʒ��Ϣ���� \t\t2. ��Ʒ����\n");
	printf("3.�����ۼ�¼ͳ�� \t\t4.������һ��\n");
	printf("5.�˳�\n");
	printf("��ѡ�����");
	scanf("%d",&a);

	if(ren[i].quanxian[a-1]==a||a==4||a==5)
	{
	fclose(fp1);
	fclose(fp);
		switch(a)
	 {
		case 1:  goods_information();   break;
		case 2:  goods_sell();   break;
		case 3:  sell_record();   break;
		case 4:  seller1_denglu();	break;
		case 5:	exit(0);
		
	 }
		
	}goto menu;
	
	
}


void charger_denglu()//����Ա��¼
{
	int n,m;
	printf("�������˺ţ������˺�:");
	scanf("%d",&n);
	printf("��������������");
	scanf("%d",&m);
	if(n==N&&m==N)
	{
		printf("��¼�ɹ�");
		manner_denglu();
	}
	else
	{
		printf("��¼����������˺Ų�ƥ�䣬�����µ�¼");
		charger_denglu();
	}
}
void sell_record()//������Ʒ��ѯ
{
	FILE * fp,*fp1;
	int i;
	int sum=0;
	page_title("�����ۼ�¼ͳ��");
	fp1=fopen("quanj.txt","r+");
	fp=fopen("goods_sell.txt","r+");
	fscanf(fp1,"%d\n%d\n%d\n",&quan,&shouchu,&ren1);
	fscanf2_goods(fp,shouchu,allsell);
	//��ʾ��ǰ�����۵�������Ʒ��Ϣ��������Ʒ��š���Ʒ���ơ���Ʒ�۳����������ۡ�������Ʒ�ܽ��������ܽ�
	for(i=0;i<shouchu;i++)
	{
		printf("��Ʒ���:%d\n��Ʒ����:%s\n��Ʒ�۳�����%d\n����%d\n������Ʒ�ܽ��%d\n",allsell[i].num,allsell[i].name,allsell[i].price,allsell[i].amount,allsell[i].allprice);
		sum=sum+allsell[i].allprice;
	}
	printf("�������ܽ��%d\n",sum);
	fprintf2_goods(fp,shouchu,allsell);
	fclose(fp1);
	fclose(fp);
return_confirm();
}
void denglu()//��¼����
{
menu:page_title("��¼����");
	 printf("1,����Ա��¼\t\t2,����Ա��¼\n");
	 printf("3.�˳�\n");
	 switch(getch())
	 {
	 case '1' :  seller1_denglu();   break;
		case '2' :  charger_denglu();   break;	
		case '3' :exit(0);
	 }
	 goto menu;
}
//1.�û����ϴ�ӡ 2.����û� 3.ɾ���û� 4.�޸��û�Ȩ�� 5�˳�"
void manner_denglu()//ϵͳ����Ա����
{
//	FILE *fp;
	menu:page_title("ϵͳ����Ա����");
		// fp=fopen("ren.txt","r+");
	printf("1.�û����ϴ�ӡ \t\t2.����û�\n");
	printf("3.ɾ���û� \t\t4.�޸��û�Ȩ��\n");
	printf("5.������һ��\t\t6.�˳�");
//	fwrite(ren,sizeof(struct SHOP),10,fp);
//	fclose(fp);
	switch(getch())
	 {
		case '1' :  seller_put() ;   break;
		case '2' :  seller_add();   break;
		case '3' :  seller_del();   break;
		case '4' :  seller_change();   break;
		case '5' : denglu();	break;
	    case '6' :	exit(0);
	 }goto menu;
}
void seller_change()//�޸��û�Ȩ��
	{
	FILE *fp,*fp1;
	int num,m=1,n,i;
	fp1=fopen("quanj.txt","r+");
	fp=fopen("ren.txt","a+");
	fscanf(fp1,"%d\n%d\n%d\n",&quan,&shouchu,&ren1);
	fscanf3_goods(fp,ren1,ren);
fclose(fp);
fp=fopen("ren.txt","w+");
	printf("������Ҫ�޸��û����˺�");
	scanf("%d",&num);
	for(i=0;i<ren1;i++)
	{
		if(ren[i].zhanghao==num)
		{
			for(m=0;m<3;m++)
			switch(ren[i].quanxian[m])
			{
				case '1' :  printf("1. ��Ʒ��Ϣ����\n ") ;   break;
				case '2' :  printf("2. ��Ʒ����\n") ;   break;
				case '3' :  printf("3.�����ۼ�¼ͳ��\n") ;   break;
		
			}
		}
	}
	if(m=1)
	{
		printf("�����µ�¼");
		seller_change();
	}
	printf("������Ҫɾ��Ȩ�޵ı��");
	scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		if(ren[i].zhanghao==num)
		{
			ren[i].quanxian[n-1]=0;
			
		}
	}
fprintf3_goods(fp,ren1,ren);
fclose(fp);
fclose(fp1);
return_confirm();
}
void seller_add()//��������Ա
{	
	
	int i,n;
	FILE * fp,*fp1;
	page_title("���������Ա");
	fp=fopen("ren.txt","r+");
	fp1=fopen("quanj.txt","r+");
	fscanf(fp1,"%d\n%d\n%d\n",&quan,&shouchu,&ren1);
	fscanf3_goods(fp,ren1,ren);
fclose(fp1);
fp1=fopen("quanj.txt","w");
	printf("�������˺�:\n(6~10)\n");
    scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		if(n==ren[i].zhanghao)
		{
			printf("���˺��Ѵ���");
			seller_add();
		}
	}
	ren[ren1].zhanghao=n;
	printf("���������룺\n");
	scanf("%d",&ren[ren1].mima);
	printf("������Ա���:\n");
	scanf("%d",&ren[ren1].num);
	printf("�˺ţ�%d\n���룺%d\n�û���ţ�%d\n",ren[ren1].zhanghao,ren[ren1].mima,ren[ren1].num);
	for(i=1;i<=3;i++)
	{
	ren[ren1].quanxian[i]=i;
	}
	ren1++;
		fprintf3_goods(fp,ren1,ren);

	fprintf(fp1,"%d\n%d\n%d\n",quan,shouchu,ren1);
	fclose(fp);
	fclose(fp1);
return_confirm();
}
//�û����˺š����롢��ɫ��Ȩ�޵���Ϣ��
void seller_put()//��ѯ����Ա��Ϣ
{
	int i,n,a=0,m;
	FILE * fp,*fp1;
	page_title("���������Ա");
	fp=fopen("ren.txt","r+");
	fp1=fopen("quanj.txt","r+");
	fscanf(fp1,"%d\n%d\n%d\n",&quan,&shouchu,&ren1);
	fscanf3_goods(fp,ren1,ren);
	printf("�����û��˺�");
	scanf("%d",&n);
	for(i=0;i<ren1;i++)
	{
		if(n=ren[i].num)
		{
			printf("%d\n%d\n����Ա%d\n",ren[i].zhanghao,ren[i].mima,ren[i].num);
			printf("Ȩ����");
			for(m=0;m<3;m++)
			switch(ren[i].quanxian[m])
			{
				case '1' :  printf("1. ��Ʒ��Ϣ����\n ") ;   break;
				case '2' :  printf("2. ��Ʒ����\n") ;   break;
				case '3' :  printf("3.�����ۼ�¼ͳ��\n") ;   break;
		
			}
			a=1;
		}
	}
	if(a=1)
		printf("�޸��û�");
	fclose(fp);
	fclose(fp1);
	return_confirm();
}
void seller_del()//ɾ������Ա
{
	int i,n,a=0,num;
	FILE * fp,*fp1;
	page_title("���������Ա");
	fp=fopen("ren.txt","r+");
	fp1=fopen("quanj.txt","r+");
	fscanf(fp1,"%d\n%d\n%d\n",&quan,&shouchu,&ren1);
	fscanf3_goods(fp,ren1,ren);
fclose(fp);
fclose(fp1);
fp=fopen("ren.txt","w");
	fp1=fopen("quanj.txt","w");
   page_title("ɾ������Ա");
   printf("��������Ҫɾ��������Ա�ı�ţ�");
   scanf("%d",&num);
	for(n=0;n<10;n++)
   {  
	   if(ren[n].num==num)
	   {
       for(i=n;i<10;i++)   
	   {   
		   ren[i]=ren[i+1];
		}
	   a=1;
	   ren1--;
	   }
	}
	if(a=1)
   printf("����Ա��ɾ��.\n");
	else
		printf("�˺Ŵ���");
fprintf(fp1,"%d\n%d\n%d\n",quan,shouchu,ren1);
fscanf3_goods(fp,ren1,ren);
fclose(fp);
fclose(fp1);
return_confirm();
}

//1. ��Ʒ��Ϣ���� 2. ��Ʒ����3.�����ۼ�¼ͳ�� 
main()
{
	denglu();
}
