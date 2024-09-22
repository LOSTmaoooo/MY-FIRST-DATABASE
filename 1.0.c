#include<stdio.h>
#include<string.h>

struct good {
	char name;
	int price;
	int num;
};
	


int main()
{
	good channel[32];//创建数组 
	
	char name,choice; //物品名称 ，buy/store选择                                                                    
	
	int num, location, price = 0;
	
	while (1)
	{
		printf("buy or store") ;
		scanf("%c",choice);
	//	switch(choice)
		printf("%s",choice)	;
	 } 
	 
	 
	 
	 
	printf("位置，物品，数量，单价（数据间需要空格分开）\n");
	scanf("%d %c %d %d",&location,&name,&num,&price);
	
	char result[128];
	result[0] = '\0';
	for (int i = 0; i < num; i++)
	{
		result[i] = name;
	}
	result[num] = '\0';
//重复名字显示个数 
	printf("%d:%s %d", location, result, price);



	return 0;                                   
}                                                
