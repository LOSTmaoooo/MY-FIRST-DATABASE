#include<stdio.h>
#include<string.h>//�ַ�����غ��� 
#include <unistd.h>//sleep����ʹ�� 

struct good {
    char obj[2]; // ��obj��Ϊ�ַ����飬�Ա�ʹ��strcpy
    int price;
    int num;
    int initial_num;
};

int main() 
{	
	struct good channel[16]={0}; // �������� channel ��������������

    char name, choice[8]; // ��Ʒ���� ��buy/storeѡ��

    int num, location, price = 0;



    while (1) 
	{
		system("cls"); // ��������
        printf("BUY or STORE\n");
        scanf("%s", choice);

        if (strcmp(choice, "BUY") == 0) 
		{
            int total = 0;
            system("cls"); // ��������
            printf("����ٻ����ξ���ѡ��\n");
            while (1) 
			{
                for (int i = 0; i < 16; i++) 
				{
                    if (channel[i].num > 0) // ֻ��ʾ�п�����Ʒ
					{ 
						printf("%d: %s x %d, ���ۣ�%d\n", i, channel[i].obj, channel[i].num, channel[i].price);
                    }
                }
                printf("��������ܺź͹������������磺3 2����\n");
                scanf("%d %d", &location, &num);

                if (location >= 0 && location < 16 && channel[location].num >= num)
				{
                    
                    channel[location].num -= num;// ���»����ϵ�����                  
                    total += channel[location].price * num;// �����ܼ�
                    if (total<0)
                    {
                    	printf("\n����˻������쳣���˻�ʧ�ܣ�����������ñ��ۻ���������ǻ���ʡʡ�ɣ���");
                    	channel[location].num += num;// ���ز���                
                    	total -= channel[location].price * num;// �ܼ۸�ԭ
						sleep(2); 
						
					}
					else
					{
						printf("�������� %d �� %s���ܼ�Ϊ %d\n", num, channel[location].obj, channel[location].price * num);
                    	
					}
                    printf("\n���Ҫ���ˣ������� 'END'\n\n�����ʱ�����빺���Ѿ�ѡ�е�ĳ����Ʒ��������'CONTINUE'�����ڹ���״̬�½�����дΪ����\n\n������������������'CONTINUE'\n\n");
                    
                    scanf("%s", choice);
                    if (strcmp(choice, "END") == 0) 
					{
                        printf("������������Ϊ��%d\n", total);
						int input=0;//����͵��θ��Ѷ�� 
						while(total>0) 
						{
							printf("��Ͷ��(1��2��5):");
							scanf("%d",&input);
							if(input==1||input==2||input==5)
							{
								total=total-input;
							}
							else
							{
								printf("ʹ�����޷�ʶ���money������1��2��5�����룡\n");
								sleep(1);
							} 
						}
						if(total==0)
						{
							system("cls");
							printf("лл�ݹˣ���ӭ�´ι��٣�");
							sleep(1); 
						}
						else
						{
							system("cls");
							printf("����%dԪ\n",-total);
							sleep(1); 
							printf("лл�ݹˣ���ӭ�´ι��٣�");
							sleep(3);
						} 
                        break;
                    }
                } 
				else
				{
                    printf("��Ʒ�������ܺ�������������ԡ�\n");
                    sleep(1); 
                }
            }
        } 
		else if (strcmp(choice, "STORE") == 0)
		{
            system("cls"); // ��������
			printf("���ܿտգ�������ͣ�\n");
            while (1) 
			{
                
                printf("λ�ã���Ʒ�����������ۣ����ݼ���Ҫ�ո�ֿ���\n");
                scanf("%d %c %d %d", &location, &name, &num, &price);
                
				if (channel[location].num == 0||strcmp(channel[location].obj, &name) == 0) // ���λ���Ƿ�Ϊ��	
				{
					strcpy(channel[location].obj, &name); // �����ַ�����Ҫstrcpy
                	channel[location].price = price;
                	channel[location].num += num;
					printf("��Ʒ�Ѵ洢��λ�� %d\n", location);
				}
                else
                {
                    printf("λ�� %d ���в�ͬ��Ʒ���޷��洢��\n", location);
				}
                printf("���Ҫ�������룬������ 'END'����������'CONTINUE'��\n");
                scanf("%s", choice);
                if (strcmp(choice, "END") == 0) 
				{
                    break;
                }
            }
                

                
                
        }
        
		else 
		{
            printf("�޷�ʶ������룬������BUY����STORE��\n");
            sleep(1); 
        }
    }

    return 0;
}
