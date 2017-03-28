#include "JD.h"
#include "const.h"
#include <cstring>

long double JD::DD2JD(int y, uint8_t m, long double d)
{
 	int n = 0, G = 0;
	//�ж��Ƿ�Ϊ�����������1582*372+10*31+15
	if (y * 372 + m * 31 + (int)(d) >= 588829)
	{
		G = 1;
	}
	if (m <= 2)
	{
		m += 12, y--;
	}
	//�Ӱ�����
	if (G)
	{
		n = (int)(y / 100), n = 2 - n + int(n / 4);
	}
	return (int)(365.25*(y + 4716)) + (int)(30.6001*(m + 1)) + d + n - 1524.5;
}

Time JD::JD2DD(int jd)
{
	Time r;
	int D = (int)(jd + 0.5);
	float F = jd + 0.5 - D, c;  //ȡ����������������A��С������F
	if (D >= 2299161)
	{
		c = int((D - 1867216.25) / 36524.25), D += 1 + c - (int)(c / 4);
	}
	D += 1524;               r.Y = (int)((D - 122.1) / 365.25);//����
	D -= (int)(365.25*r.Y);   r.M = (int)(D / 30.601); //����
	D -= (int)(30.601*r.M);   r.D = D; //����
	if (r.M > 13)
	{
		r.M -= 13, r.Y -= 4715;
	}
	else
	{
		r.M -= 1, r.Y -= 4716;
	}
	//�յ�С��תΪʱ����
	F *= 24; r.h = (int)(F); F -= r.h;
	F *= 60; r.m = (int)(F); F -= r.m;
	F *= 60; r.s = F;
	return r;
}

long double JD::toJD(Time& time)
{
	return JD::DD2JD(time.Y, time.M, time.D + ((time.s / 60 + time.m) / 60 + time.h) / 24);
}

//��ȡjd�е�ʱ��(ȥ������);
std::string JD::timeStr(long double jd)
{
	int h, m, s;
	jd += 0.5; jd = (jd - int2(jd));
	s = int2(jd * 86400 + 0.5);
	h = int2(s / 3600); s -= h * 3600;
	m = int2(s / 60);   s -= m * 60;
	std::string ret = "";
	char buff[11];
	memset(buff, 0, 11);
	sprintf_s(buff, "0%d", h);
	ret.append(buff + strlen(buff) - 2);
	ret += ":";

	memset(buff, 0, 11);
	sprintf_s(buff, "0%d", m);
	ret.append(buff + strlen(buff) - 2);
	ret += ":";

	memset(buff, 0, 11);
	sprintf_s(buff, "0%d", s);
	ret.append(buff + strlen(buff) - 2);

	return ret;
}