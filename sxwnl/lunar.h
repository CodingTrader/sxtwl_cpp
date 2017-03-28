#pragma once
#include <stdint.h>
#include "SSQ.h"

struct  GZ
{
	uint8_t tg;
	uint8_t dz;
};

struct Day
{
	int d0;   //������
	int di; //��������������
	int y;   //������
	uint8_t m; //������
	int d; 
	int dn;   //���ڹ����µ�����
	uint8_t week0; //���׵�����
	uint8_t week;  //��ǰ�յ�������
	uint8_t weeki; //�������ڵ������
	uint8_t weekN; //���µ�������

	uint8_t Ldi;  //��ũ�����׵ı�����,0��Ӧ��һ
	int cur_dz;  //�ඬ��������
	int cur_xz; //������������
	int cur_lq;//�����������
	int cur_mz ;  //��â�ֵ�����
	int cur_xs;  //��С�������

	uint8_t Lmc;  //�����µ��·�
	uint8_t Ldn;  //�����µ�����
	bool Lleap; //�ǲ�������������
	int8_t Lmc2; //�¸��µ��·ݣ���������Ϊ-1

	int8_t qk;  //��������������Ϊ-1

	int Lyear;  //ũ������(10����,1984������)
	int Lyear0;  //ũ������(10����,1984������)
	GZ Lyear2; //��֧����(����)
	GZ Lyear3; //��֧����(����)
	int Lyear4;

	uint8_t Lmonth;
	GZ Lmonth2;   //����ɵ�֧

	GZ Lday2;

	uint8_t XiZ; //����
	uint8_t jqmc; //��������
	uint8_t jqjd;
	std::string jqsj;  //����ʱ��

	uint8_t yxmc; //��������
	uint8_t yxjd;
	std::string yxsj; //����ʱ��
};

struct Month
{
	int y; //�������
	uint8_t m; //�����·�
	//����Ф
	uint8_t ShX;
	uint8_t yearGan;
	uint8_t yearZhi;
	std::vector<Day> days;
};


class Lunar
{
public:
	Month yueLiCalc(int By, uint8_t Bm);
private:
	SSQ mSSQ;
};