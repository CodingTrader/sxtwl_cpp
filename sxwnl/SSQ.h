#pragma once
#include <vector>
typedef enum
{
	QType,   //��
	SType	 //˷
} QSType;

class SSQ
{
public:
	SSQ();
	~SSQ();
	int calc(long double jd, QSType type);
	//�ϸ߾�����;
	long double qi_high(long double);
	//�ϸ߾���˷
	long double so_high(long double);
	long double so_low(long double W);
	long double qi_low(long double W);

	void calcY(int jd);

	std::string jieya(std::string s);

	std::vector<long double>* suoKB;
	std::vector<long double>* qiKB;


	std::vector<long double> ZQ;
	long double ZQ_pe1, ZQ_pe2;
	std::vector<int> HS;
	std::vector<int> ym;
	std::vector<int> dx;
	int leap;
	std::string SB, QB;
};
