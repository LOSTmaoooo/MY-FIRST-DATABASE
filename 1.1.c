#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

struct good {
    char obj[2]; // ��obj��Ϊ�ַ����飬�Ա�ʹ��strcpy
    int price;
    int num;
};

int main() 
{
    struct good channel[16]={0}; // �������� channel ��������������

    char name, choice[8]; // ��Ʒ���� ��buy/storeѡ��

    int num, location, price = 0;

    //char result[128]; // result ������ʾ��AAAA
   // result[0] = '\0';

    while (1) 
	{
        printf("buy or store\n");
        scanf("%s", choice);

        if (strcmp(choice, "buy") == 0) 
		{
            int total = 0;
            printf("����ٻ����ξ���ѡ��\n");
            while (1) 
			{
                for (int i = 0; i < 16; i++) 
				{
                    if (channel[i].num > 0) // ֻ��ʾ�п�����Ʒ
					{ 
                        printf("%d:%s %d\n", i);
						for (int i = 0; i < num; i++)
						{
							 printf("%c",channel[i].obj[0]);
						}
						
                        printf(channel[i].price);
                    }
                }
                printf("��������ܺź͹������������磺3 2����");
                scanf("%d %d", &location, &num);

                if (location >= 0 && location < 16 && channel[location].num >= num)
				 {
                    
                    channel[location].num -= num;// ���»����ϵ�����

                    
                    total += channel[location].price * num;// �����ܼ�
                    printf("�������� %d �� %s���ܼ�Ϊ %d\n", num, channel[location].obj, channel[location].price * num);

                    printf("���Ҫ���ˣ������� 'END'�����������������\n");
                    scanf("%s", choice);
                    if (strcmp(choice, "END") == 0) 
					{
                        printf("������������Ϊ��%d\n", total);
                        break;
                    }
                } 
				else
				{
                    printf("��Ʒ�������ܺ�������������ԡ�\n");
                }
            }
        } 
		else if (strcmp(choice, "store") == 0)
		{
            printf("���ܿտգ�������ͣ�\n");
            while (1) 
			{
                printf("λ�ã���Ʒ�����������ۣ����ݼ���Ҫ�ո�ֿ���\n");
                scanf("%d %c %d %d", &location, &name, &num, &price);
                strcpy(channel[location].obj, &name); // �����ַ�����Ҫstrcpy
                channel[location].obj[1]="\0";
                channel[location].price = price;
                channel[location].num += num;

                printf("��Ʒ�Ѵ洢��λ�� %d\n", location);
                printf("���Ҫ�������룬������ 'END'�����������������\n");
                scanf("%s", choice);
                if (strcmp(choice, "END") == 0) 
				{
                    break;
                }
            }
        }
		else 
		{
            printf("�޷�ʶ������룬������buy����store��\n");
        }
    }

    return 0;
}
