#include "JD.h"
#include <iostream>
#include<vector>
#include <conio.h>
#include "const.h"
#include "lunar.h"
#include "eph.h"
#include "SSQ.h"
int main()
{

	static const char* Gan[] = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" };
	static const char* Zhi[] = { "��", "��", "��", "î", "��", "��", "��", "δ", "��", "��", "��", "��" };
	static const char* ShX[] = { "��", "ţ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��" };
	static const char* numCn[] = { "��", "һ", "��", "��", "��", "��", "��", "��", "��", "��", "ʮ" }; //��������
	static const char* jqmc[] = { "����", "С��", "��", "����", "��ˮ", "����", "����", "����", "����", "����", "С��", "â��", "����", "С��", "����", "����", "����", "��¶", "���", "��¶", "˪��", "����", "Сѩ", "��ѩ" };
	static const char* ymc[] = { "ʮһ", "ʮ��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ʮ" }; //������,����
	static const char*  rmc[] = { "��һ", "����", "����", "����", "����", "����", "����", "����", "����", "��ʮ", "ʮһ", "ʮ��", "ʮ��", "ʮ��", "ʮ��", "ʮ��", "ʮ��", "ʮ��", "ʮ��", "��ʮ", "إһ", "إ��", "إ��", "إ��", "إ��", "إ��", "إ��", "إ��", "إ��", "��ʮ", "ئһ" };


	Lunar lunar;
    Month month = lunar.yueLiCalc(2017, 2);
	
	std::cout  << month.y << "��"  << (int)month.m << "��" << std::endl;
	std::cout << Gan[month.yearGan] << Zhi[month.yearZhi] << "��" << std::endl;
	std::cout << "��Ф��" << ShX[month.ShX] << std::endl;


	std::vector<Day>& days = month.days;
	for (auto it = days.begin(); it != days.end(); ++it)
	{
		Day& day = (*it);
		std::cout << "===================================================" << std::endl;;
		std::cout << "������" << day.y << "��" << (int)day.m << "��" << day.d << "��" << std::endl;
		if (day.Lleap)
		{
			std::cout << "��" << ymc[day.Lmc] << "��" << rmc[day.Ldi] << "��" << std::endl;
		}
		else
		{
			std::cout << ymc[day.Lmc] << "��" << rmc[day.Ldi] << "��" << std::endl;
		}
		
		std::cout << "������:JD" << J2000 + day.d0 << std::endl;
		std::cout << "����" << numCn[day.week] << std::endl;
		
		std::cout << Gan[day.Lyear2.tg] << Zhi[day.Lyear2.dz] << "��" 
			<< Gan[day.Lmonth2.tg] << Zhi[day.Lmonth2.dz] << "��"
			<< Gan[day.Lday2.tg] << Zhi[day.Lday2.dz] << "��"
			<< std::endl;
		
		std::cout << "�ඬ��" << day.cur_dz << "��" << std::endl;
		std::cout << "������" << day.cur_xz << "��" << std::endl;
		std::cout << "������" << day.cur_lq << "��" << std::endl;
		std::cout << "��â��" << day.cur_mz << "��" << std::endl;
		std::cout << "��С��" << day.cur_xs << "��" << std::endl;
	


	}

	getchar();
}