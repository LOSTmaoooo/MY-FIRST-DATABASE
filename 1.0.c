#include<stdio.h>
#include<string.h>

struct good {
	char name;
	int price;
	int num;
};
	


int main()
{
	good channel[32];//�������� 
	
	char name,choice; //��Ʒ���� ��buy/storeѡ��                                                                    
	
	int num, location, price = 0;
	
	while (1)
	{
		printf("buy or store") ;
		scanf("%c",choice);
	//	switch(choice)
		printf("%s",choice)	;
	 } 
	 
	 
	 
	 
	printf("λ�ã���Ʒ�����������ۣ����ݼ���Ҫ�ո�ֿ���\n");
	scanf("%d %c %d %d",&location,&name,&num,&price);
	
	char result[128];
	result[0] = '\0';
	for (int i = 0; i < num; i++)
	{
		result[i] = name;
	}
	result[num] = '\0';
//�ظ�������ʾ���� 
	printf("%d:%s %d", location, result, price);



	return 0;                                   
}                                                
