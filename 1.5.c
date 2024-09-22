#include<stdio.h>
#include<string.h>//字符串相关函数 
#include <unistd.h>//sleep函数使用 

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
		system("cls"); // 清屏操作
        printf("BUY or STORE\n");
        scanf("%s", choice);

        if (strcmp(choice, "BUY") == 0) 
		{
            int total = 0;
            system("cls"); // 清屏操作
            printf("珍奇百货，任君挑选！\n");
            while (1) 
			{
                for (int i = 0; i < 16; i++) 
				{
                    if (channel[i].num > 0) // 只显示有库存的商品
					{ 
						printf("%d: %s x %d, 单价：%d\n", i, channel[i].obj, channel[i].num, channel[i].price);
                    }
                }
                printf("请输入货架号和购买数量（例如：3 2）：\n");
                scanf("%d %d", &location, &num);

                if (location >= 0 && location < 16 && channel[location].num >= num)
				{
                    
                    channel[location].num -= num;// 更新货架上的数量
                    total += channel[location].price * num;// 计算总价
                    printf("您购买了 %d 个 %s，总价为 %d\n", num, channel[location].obj, channel[location].price * num);
                    printf("如果要结账，请输入 'END'，否则按任意键并且回车继续：\n");
                    scanf("%s", choice);
                    if (strcmp(choice, "END") == 0) 
					{
                        printf("您的最终消费为：%d\n", total);
						int change=0,input=0;//找零和单次付费额度 
						while(total>0) 
						{
							printf("请投币(1或2或5):");
							scanf("%d",&input);
							if(input==1||input==2||input==5)
							{
								total=total-input;
							}
							else
							{
								printf("使用了无法识别的money，请用1或2或5来输入！\n");
								sleep(1);
							} 
						}
						if(total==0)
						{
							system("cls");
							printf("谢谢惠顾，欢迎下次光临！");
							sleep(1); 
						}
						else
						{
							system("cls");
							printf("找零%d元\n",change);
							sleep(1); 
							printf("谢谢惠顾，欢迎下次光临！");
						} 
                        break;
                    }
                } 
				else
				{
                    printf("商品不足或货架号输入错误，请重试。\n");
                    sleep(1); 
                }
            }
        } 
		else if (strcmp(choice, "STORE") == 0)
		{
            system("cls"); // 清屏操作
			printf("货架空空，请君入瓮！\n");
            while (1) 
			{
                printf("位置，物品，数量，单价（数据间需要空格分开）\n");
                scanf("%d %c %d %d", &location, &name, &num, &price);
                strcpy(channel[location].obj, &name); // 处理字符串需要strcpy
                channel[location].price = price;
                channel[location].num += num;

                printf("商品已存储在位置 %d\n", location);
                printf("如果要结束输入，请输入 'END'，否则按任意键并且回车继续：\n");
                scanf("%s", choice);
                if (strcmp(choice, "END") == 0) 
				{
                    break;
                }
            }
        }
		else 
		{
            printf("无法识别该输入，请输入BUY或者STORE！\n");
            sleep(1); 
        }
    }

    return 0;
}
