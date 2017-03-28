#pragma once
#include <stdint.h>
#include <time.h>
#include <string>

struct Time
{
	int Y, M, D;
	double h, m, s;
};


class JD
{
public :
	//����ת������
	static long double DD2JD(int y, uint8_t m, long double d);
	static Time JD2DD(int jd);

	static long double toJD(Time& time);
	static std::string timeStr(long double jd);
};