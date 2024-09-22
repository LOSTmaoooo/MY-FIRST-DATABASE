#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct good {
    char obj[2]; // 将obj改为字符数组，以便使用strcpy
    int price;
    int num;
};

int main() 
{
    struct good channel[16]={0}; // 创建数组 channel 即货架整体数据

    char name, choice[8]; // 物品名称 ，buy/store选择

    int num, location, price = 0;

    //char result[128]; // result 用于显示如AAAA
   // result[0] = '\0';

    while (1) 
	{
        printf("buy or store\n");
        scanf("%s", choice);

        if (strcmp(choice, "buy") == 0) 
		{
            int total = 0;
            printf("珍奇百货，任君挑选！\n");
            while (1) 
			{
                for (int i = 0; i < 16; i++) 
				{
                    if (channel[i].num > 0) // 只显示有库存的商品
					{ 
                        printf("%d:%s %d\n", i);
						for (int i = 0; i < num; i++)
						{
							 printf("%c",channel[i].obj[0]);
						}
						
                        printf(channel[i].price);
                    }
                }
                printf("请输入货架号和购买数量（例如：3 2）：");
                scanf("%d %d", &location, &num);

                if (location >= 0 && location < 16 && channel[location].num >= num)
				 {
                    
                    channel[location].num -= num;// 更新货架上的数量

                    
                    total += channel[location].price * num;// 计算总价
                    printf("您购买了 %d 个 %s，总价为 %d\n", num, channel[location].obj, channel[location].price * num);

                    printf("如果要结账，请输入 'END'，否则按任意键继续：\n");
                    scanf("%s", choice);
                    if (strcmp(choice, "END") == 0) 
					{
                        printf("您的最终消费为：%d\n", total);
                        break;
                    }
                } 
				else
				{
                    printf("商品不足或货架号输入错误，请重试。\n");
                }
            }
        } 
		else if (strcmp(choice, "store") == 0)
		{
            printf("货架空空，请君入瓮！\n");
            while (1) 
			{
                printf("位置，物品，数量，单价（数据间需要空格分开）\n");
                scanf("%d %c %d %d", &location, &name, &num, &price);
                strcpy(channel[location].obj, &name); // 处理字符串需要strcpy
                channel[location].obj[1]="\0";
                channel[location].price = price;
                channel[location].num += num;

                printf("商品已存储在位置 %d\n", location);
                printf("如果要结束输入，请输入 'END'，否则按任意键继续：\n");
                scanf("%s", choice);
                if (strcmp(choice, "END") == 0) 
				{
                    break;
                }
            }
        }
		else 
		{
            printf("无法识别该输入，请输入buy或者store。\n");
        }
    }

    return 0;
}
