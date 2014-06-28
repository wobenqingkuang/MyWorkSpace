#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define N 111
void denglu();
void charger_denglu();
void seller_denglu();
void seller5_denglu();
void seller4_denglu();
void seller3_denglu();
void seller2_denglu();
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
//商品编号、商品名称、商品售出数量、单价、单类商品总金额及日销售总金额。
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
int quan=0,shouchu=0;
void return_confirm(void)
 { 
	printf("\n按任意键返回……\n");
getch(); 
}
void page_title(char *menu_item)  
 
{ 
 system("cls"); 

printf("\t\t\t************欢迎使用超市收银系统**********\n\n- %s -\n\n",menu_item);
} 
void open_goods(FILE *fp)//打开文件
{
	fp=fopen("goods.txt","a+");
}
void fscanf1_goods(FILE *fp,int n,struct GOODS *goods)//读取文件函数
{
	int i;
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",goods[i].num,goods[i].price,goods[i].amount);
		fscanf(fp,"%s",goods[i].name,goods[i].mfrs,goods[i].buyer,goods[i].beizhu);
	}
}
void fprintf1_goods(FILE *fp,int n,struct GOODS *goods)//把结构体GOODS写入文件
{
		int i;
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%d\n",goods[i].num,goods[i].price,goods[i].amount);
		fprintf(fp,"%s\n",goods[i].name,goods[i].mfrs,goods[i].buyer,goods[i].beizhu);
	}
}
void fprintf2_goods(FILE *fp,int n,struct GOODS1 *goods)//把结构体GOODS1写入文件
{
		int i;
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%d\n",goods[i].num,goods[i].price,goods[i].amount);
		fprintf(fp,"%s\n",goods[i].name,goods[i]);
	}
}
void fscanf2_goods(FILE *fp,int n,struct GOODS1 *goods)//读取文件函数到GOODS1
{
	int i;
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d",goods[i].num,goods[i].price,goods[i].amount);
		fscanf(fp,"%s\n",goods[i].name,goods[i]);
	}
}
void goods_add(void) //增加商品
{ int n; 
FILE *fp;
fp=fopen("goods.txt","a+");
 for(n=quan;n<100;n++) 
 { 
page_title("注册新商品");
 printf("商品号:");
    scanf("%d",&goods[n].num);
if(goods[n].num==0) break;
 printf("商品名:");
 scanf("%s",&goods[n].name);
printf("商品单价:");
scanf("%d",&goods[n].price);
 printf("入库商品数量:");
 scanf("%d",&goods[n].amount);
 printf("生产厂商:");
 scanf("%s",&goods[n].mfrs);  
 printf("采购员名称");
 scanf("%s",&goods[n].buyer);
printf("备注信息");
scanf("%s",&goods[n].beizhu);
fprintf(fp,"%d\t",goods[n].num,goods[n].price,goods[n].amount);
fprintf(fp,"***%s\n",goods[n].name,goods[n].mfrs,goods[n].buyer,goods[n].beizhu);
quan++;
}
 fclose(fp);
return_confirm();
}
void goods_del()//删除商品
{
	FILE *fp;
	int n,num,i,amount;
	fp=fopen("goods.txt","r+");
fscanf1_goods(fp,100,goods);

   page_title("删除商品");
   printf("请输入所要删除的商品的编号：");
   scanf("%d",&num);
	printf("请输入所要删除的商品的数量：");
scanf("%d",&amount);
for(n=0;n<1000;n++)
{
	if(goods[n].num==num)break;
}
if(amount<goods[n].amount)
goods[n].amount=goods[n].amount-amount;
else if(amount=goods[n].amount)
{
       for(i=n;i<100;i++)   
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
	   
   printf("该商品已删除.\n");
}
fprintf1_goods(fp,100,goods);
return_confirm();
}
void goods_search()//商品查询
{ 
	FILE *fp;
	int n,i=1,j=0;
	char nam[30];
  fp=fopen("goods.txt","r+");
fscanf1_goods(fp,100,goods);
  page_title("商品查询");
   printf("请输入商品名:");
  scanf("%s",nam);
   for(n=0;n<100;n++)
  {  if((strcmp(goods[n].name,nam)==0))
   {  printf("序号:%d\t",goods[n].num);
      printf("商品名:%s\t",goods[n].name);
	  printf("价格:%d\t",goods[n].price);
	  printf("数量：%d\t",goods[n].amount);
	  i=0;
	}
   }
   if(i==1)
	   printf("无该商品信息\n");
   fclose(fp);
return_confirm();
}
void goods_sell() //商品查询
{	
   FILE *fp,*fp1;
   int sum=0,n=1,k,num,money,i,j=0;
   page_title("商品出售");
   fp=fopen("goods_sell.txt","r+");
	fp1=fopen("goods.txt","r+");
 fscanf1_goods(fp,100,goods);
 fscanf2_goods(fp1,100,allsell);
   for(k=0;n!=0;k++)
   {
	   printf("请输入所要售出商品的编号：");
	   scanf("%d",&num);
	   if(n==0)break;
	   printf("请输入数量:");
	   scanf("%d",&n);
	  for(i=0;i<100;i++)
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
			printf("%s %d %d\n",allsell[i].name ,allsell[i].price,allsell[i].amount);
			 shouchu++;
			 j++;
		   }
	   }
   }
   printf("总金额：%d\n",sum);
   printf("请输入付款：");
   scanf("%d",&money);
   printf("找零：%d\n",money-sum);
   return_confirm();
   fprintf1_goods(fp1,100,goods);
   fprintf2_goods(fp,100,allsell);
   fclose(fp);
	fclose(fp1);
}

void goods_change()//商品修改
{
	int n,i;
	FILE *fp;
fp=fopen("goods.txt","r+");
fscanf1_goods(fp,100,goods);
   page_title("修改商品信息");
   printf("请输入要修改的商品编号:");  
   scanf("%d",&i);                 
   for(n=0;n<100;n++)
   {  if(goods[n].num==i)
	  { printf("修改商品名：");  
         scanf("%s",goods[n].name); 
    	printf("修改生产厂商：");
      	  scanf("%s",goods[n].mfrs);
       printf("修改采购员名称：");  
         scanf("%s",goods[n].buyer);
       printf("修改总数：");  
    	  scanf("%d",&goods[n].amount);
		printf("修改价格：");
		scanf("%d",&goods[n].price);
		printf("修改备注：");
		scanf("%d",&goods[n].beizhu);
		printf("修改商品信息成功.\n");
	 } 
   } 
   printf("\n没有找到相关记录.\n");
fprintf1_goods(fp,100,goods);
fclose(fp);
}  
void goods_information()//商品信息管理界面
{
menu:page_title("商品信息管理");
	printf("1. 添加商品 \t\t2. 删除商品\n");
	printf("3.商品信息修改 \t\t4.商品信息查询\n");
	printf("5.返回上一级\t\t6.退出");
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
void seller_menu()//收银员操作菜单界面
{
menu:page_title("收银员操作菜单");
	printf("1. 商品信息管理 \t\t2. 商品销售\n");
	printf("3.日销售记录统计 \t\t4.返回上一级\n");
	printf("5.退出\n");
	switch(getch())
	 {
		case '1' :  goods_information();   break;
		case '2' :  goods_sell();   break;
		case '3' :  sell_record();   break;
		case '4' :  seller1_denglu();	break;
		case '5' :	exit(0);
		
	 }goto menu;
}
void seller1_denglu()//收银员登陆
{
	int n,m,i,num;
page_title("收银员登录");
	printf("请输入你的编号：");
	scanf("%d",&num);
	printf("请输入账号：");
	scanf("%d",&n);
	printf("请输入密码");
	scanf("%d",&m);
	for(i=0;i<10;i++)
	{
		if(ren[i].num==num)break;
	}
	if(n==ren[i].zhanghao&&m==ren[i].mima)
		printf("登录成功");
	else
	{
		printf("登录错误，请重新登录");
	seller1_denglu();
	}
seller_menu();
}


void charger_denglu()//管理员登录
{
	int n,m;
	printf("请输入账号：数字账号:");
	scanf("%d",&n);
	printf("请输入数字密码");
	scanf("%d",&m);
	if(n==N&&m==N)
	{
		printf("登录成功");
		manner_denglu();
	}
	else
	{
		printf("登录错误，密码和账号不匹配，请重新登录");
		charger_denglu();
	}
}
void sell_record()//出售商品查询
{
	FILE * fp;
	int i;
	int sum=0;
	page_title("日销售记录统计");
	
	fp=fopen("goods_sell.txt","r");
	fscanf2_goods(fp,100,allsell);
	
	//显示当前所销售的所有商品信息，包括商品编号、商品名称、商品售出数量、单价、单类商品总金额及日销售总金额。
	for(i=0;i<shouchu;i++)
	{
		printf("商品编号:%d\n商品名称:%s\n商品售出数量%d\n单价%d\n单类商品总金额%d\n",allsell[i].num,allsell[i].name,allsell[i].price,allsell[i].amount,allsell[i].allprice);
		sum=sum+allsell[i].allprice;
	}
	printf("日销售总金额%d\n",sum);
	fprintf2_goods(fp,100,allsell);
	fclose(fp);
return_confirm();
}
void denglu()//登录界面
{
menu:page_title("登录界面");
	 printf("1,收银员登录\t\t2,管理员登录\n");
	 printf("3.退出\n");
	 switch(getch())
	 {
	 case '1' :  seller1_denglu();   break;
		case '2' :  charger_denglu();   break;	
		case '3' :exit(0);
	 }
	 goto menu;
}
//1.用户资料打印 2.添加用户 3.删除用户 4.修改用户权限 5退出"
void manner_denglu()//系统管理员界面
{
	FILE *fp;
	menu:page_title("系统管理员界面");
		 fp=fopen("ren.txt","w+");
	printf("1.用户资料打印 \t\t2.添加用户\n");
	printf("3.删除用户 \t\t4.修改用户权限\n");
	printf("5.返回上一级\t\t6.退出");
	fwrite(ren,sizeof(struct SHOP),10,fp);
	fclose(fp);
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
void seller_change()//修改用户权限
	{
	FILE *fp;
	int num,m=1,n,i;
	fp=fopen("ren.txt","a+");
	fread(ren,sizeof(struct SHOP),10,fp);
	printf("请输入要修改用户的账号");
	scanf("%d",&num);
	for(i=0;i<10;i++)
	{
		if(ren[i].zhanghao==num)
		{
			for(m=0;m<3;m++)
			switch(ren[i].quanxian[m])
			{
				case '1' :  printf("1. 商品信息管理\n ") ;   break;
				case '2' :  printf("2. 商品销售\n") ;   break;
				case '3' :  printf("3.日销售记录统计\n") ;   break;
		
			}
		}
	}
	if(m=1)
	{
		printf("请重新登录");
		seller_change();
	}
	printf("请输入要删除权限的编号");
	scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		if(ren[i].zhanghao==num)
		{
			ren[i].quanxian[n]=0;
			
		}
	}
	fwrite(ren,sizeof(struct SHOP),10,fp);
}
int t=0;
void seller_add()//增加收银员
{	
	
	int i,n;
	FILE * fp;
	page_title("添加新销售员");
	if((fp=fopen("person.txt","w+"))==NULL)
		printf("cannot open this file\n");
		fread(&ren,sizeof(struct SHOP),10,fp);
	printf("输入新账号:\n(6~10)\n");
    scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		if(n==ren[i].zhanghao)
			seller_add();
	}
	ren[n].zhanghao=n;
	printf("设置新密码：\n");
	scanf("%d",&ren[n].mima);
	printf("新收银员编号:\n");
	scanf("%d",&ren[n].num);
	printf("账号：%d\n密码：%d\n用户编号：%d\n",ren[n].zhanghao,ren[n].mima,ren[n].num);
	fwrite(&ren,sizeof(struct SHOP),10,fp);
	fclose(fp);
}
//用户的账号、密码、角色、权限等信息。
void seller_put()//查询收银员信息
{
	int n,i;
	printf("输入用户账号");
	scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		if(n=ren[i].num)
		{
			printf("%d\n%d\n收银员%d\n",ren[i].zhanghao,ren[i].mima,ren[i].num);
		}
	}
}
void seller_del()//删除销售员
{
	
	int n,num,i;
   page_title("删除销售员");
   printf("请输入所要删除的销售员的编号：");
   scanf("%d",&num);

   for(n=0;n<10;n++)
   {  
	   if(ren[n].num==num)
	   {
       for(i=n;i<10;i++)   
	   {   
		   ren[i]=ren[i+1];
		}
	   }
	}
   printf("该人员已删除.\n");
return_confirm();
}

//1. 商品信息管理 2. 商品销售3.日销售记录统计 
main()
{
	denglu();
}
