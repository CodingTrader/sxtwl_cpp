#include "lunar.h"
#include "const.h"
#include "JD.h"
#include "eph.h"

//����
inline long double qi_accurate(long double W)
{ 
	long double t = XL::S_aLon_t(W) * 36525; 
	return t - dt_T(t) + 8.0f / 24.f;
}

inline long double so_accurate(long double W)
{ 
	long double t = XL::MS_aLon_t(W) * 36525;
	return t - dt_T(t) + 8.0f / 24.0f;
} //��˷


Month Lunar::yueLiCalc(int By, uint8_t Bm)
{
	Month month;
	int  Bd0, Bdn;

	//���������ʼ��;
	Time t;
	t.h = 12, t.m = 0, t.s = 0.1;
	t.Y = By; t.M = Bm; t.D = 1;

	//�������׵�������,����;
	Bd0 = (int)(JD::toJD(t)) - J2000;

	t.M++; if (t.M > 12) t.Y++, t.M = 1;
	//��������(����);
	Bdn = (int)(JD::toJD(t)) - J2000 - Bd0;

	//���µ�һ�������;
	int w0 = (Bd0 + J2000 + 1 + 7000000) % 7;
	month.y = By; //�������
	month.m = Bm; //�����·�

	//this.d0 = Bd0;
	//this.dn = Bdn;

	////�����������Ӧ��ũ����֧����
	int  c = By - 1984 + 12000;

	//����ɵ�֧
	month.yearGan = c % 10;
	month.yearZhi = c % 12;
	//����Ф
	month.ShX = c % 12;

	//���濪ʼ��ȡ���յ���Ϣ
	int  D, day, day2;
	long double w;
	std::vector<Day>& lun = month.days;

	//��ȡ������Ϣ
	for (int i = 0, j = 0; i < Bdn; i++)
	{
		Day day;
		day.d0 = Bd0 + i; //������,����ʱ12:00
		day.di = i;  //��������������
		day.y = By; //������
		day.m = Bm; //������
		day.dn = Bdn;   //����������
		day.week0 = w0; //���׵�����
		day.week = (w0 + i) % 7; //��ǰ�յ�����
		day.weeki = int((w0 + i) / 7); //�������ڵ������
		day.weekN = int((w0 + Bdn - 1) / 7) + 1;  //���µ�������	
		Time time = JD::JD2DD(day.d0 + J2000);
		day.d = time.D; //����������;

		//���d0���ڼ���ũ����Χ�����ټ���
		if (!mSSQ.ZQ.size() || day.d0 < mSSQ.ZQ[0] || day.d0 >= mSSQ.ZQ[24]) 
		{
			mSSQ.calcY(day.d0);
		}
			
		int mk = int2((day.d0 - mSSQ.HS[0]) / 30); 
		//ũ�������µ�����;
		if (mk < 13 && mSSQ.HS[mk + 1] <= day.d0)
		{
			mk++;
		}

		day.Ldi = day.d0 - mSSQ.HS[mk];   //��ũ�����׵ı�����,0��Ӧ��һ
		
		day.cur_dz = day.d0 - mSSQ.ZQ[0];   //�ඬ��������
		day.cur_xz = day.d0 - mSSQ.ZQ[12];  //������������
		day.cur_lq = day.d0 - mSSQ.ZQ[15];  //�����������
		day.cur_mz = day.d0 - mSSQ.ZQ[11];  //��â�ֵ�����
		day.cur_xs = day.d0 - mSSQ.ZQ[13];  //��С�������
		if (day.d0 == mSSQ.HS[mk] || day.d0 == Bd0) { //�µ���Ϣ
			day.Lmc = mk; //������
			day.Ldn = mSSQ.dx[mk]; //�´�С
			day.Lleap = (mSSQ.leap&&mSSQ.leap == mk); //��״��
			day.Lmc2 = mk < 13 ? mk + 1 : -1; //�¸�������,�жϳ�ϦʱҪ�õ�
		}
		else {
			Day day2 = lun[i - 1];
			day.Lmc = day2.Lmc, day.Ldn = day2.Ldn;
			day.Lleap = day2.Lleap, day.Lmc2 = day2.Lmc2;
		}
		int qk = int2((day.d0 - mSSQ.ZQ[0] - 7) / 15.2184); 
		
		//������ȡֵ��Χ��0-23
		if (qk < 23 && day.d0 >= mSSQ.ZQ[qk + 1])
		{
			qk++; 
		}
			
		day.qk = -1;
		if (day.d0 == mSSQ.ZQ[qk])
		{
			day.qk = qk;		
		}
	

		//day.yxmc = day.yxjd = day.yxsj = '';//��������,����ʱ��(������),����ʱ�䴮
		//day.jqmc = day.jqjd = day.jqsj = '';//��������,����ʱ��(������),����ʱ�䴮

		//��֧���괦��
		//������Ϊ�綨����
		D = mSSQ.ZQ[3] + (day.d0 < mSSQ.ZQ[3] ? -365 : 0) + 365.25 * 16 - 35; //������Ϊ�綨����
		day.Lyear = (int)(D / 365.2422 + 0.5); //ũ������(10����,1984������)
		//���¼��������³�һ������
		D = mSSQ.HS[2]; //һ���3����Ϊ����
		for (j = 0; j < 14; j++) { //�Ҵ���
			//���µ�index = 3
			if (mSSQ.ym[j] != 2 || mSSQ.leap == j&&j) continue;
			D = mSSQ.HS[j];
			if (day.d0 < D) { D -= 365; break; } //����������һ������
		}
		D = D + 5810;  //������괺����1984��ƽ������(��������)�����������
		day.Lyear0 = (int)(D / 365.2422 + 0.5); //ũ������(10����,1984������)

		//��֧����(����)
		D = day.Lyear + 12000;
		day.Lyear2.tg = D % 10;
		day.Lyear2.dz = D % 12;
		
		//��֧����(����)
		D = day.Lyear0 + 12000;  
		day.Lyear3.tg = D % 10;
		day.Lyear3.dz = D % 12;
		
		//��֧����(����)
		day.Lyear4 = day.Lyear0 + 1984 + 2698; //�Ƶۼ���

		 //���´���,1998��12��7(��ѩ)��ʼ�������н�������,0Ϊ����
		mk = int2((day.d0 - mSSQ.ZQ[0]) / 30.43685); 
		//��Դ�ѩ����������,mk��ȡֵ��Χ0-12
		if (mk < 12 && day.d0 >= mSSQ.ZQ[2 * mk + 1])
		{
			mk++;
		}

		D = mk + int2((mSSQ.ZQ[12] + 390) / 365.2422) * 12 + 900000; //�����1998��12��7(��ѩ)������,900000Ϊ��������
		day.Lmonth = D % 12;	
		day.Lmonth2.tg = D % 10;
		day.Lmonth2.dz = D % 10;

		////����,2000��1��7������
		D = day.d0 - 6 + 9000000;
		day.Lday2.tg = D % 10;
		day.Lday2.dz = D % 12;
		
		//����
		mk = int2((day.d0 - mSSQ.ZQ[0] - 15) / 30.43685); 
		//���������µ�����,(���j=13,day.d0���ᳬ����14������)
		if (mk < 11 && day.d0 >= mSSQ.ZQ[2 * mk + 2]) mk++;
		day.XiZ = (mk + 12) % 12;
		////����
		//daya.getHuiLi(day.d0, day);
		////����
		//day.A = day.B = day.C = ''; day.Fjia = 0;
		//daya.getDayName(day, day); //����
		//dayb.getDayName(day, day); //ũ��



		lun.push_back(day);
	}
	//����������������Ĵ���
	long double d, xn, jd2 = Bd0 + dt_T(Bd0) - (8.0 / 24.0);
	//�������
	w = XL::MS_aLon(jd2 / 36525, 10, 3);
	w = int2((w - 0.78) / PI * 2) * PI / 2;
	do {
		d = so_accurate(w);
		D = int2(d + 0.5);
		xn = int2(w / pi2 * 4 + 4000000.01) % 4;
		w += pi2 / 4;
		if (D >= Bd0 + Bdn) break;
		if (D < Bd0) continue;
		Day& ob = lun[D - Bd0];
		ob.yxmc = xn; //ȡ����������
		ob.yxjd = d;
		ob.yxsj = JD::timeStr(d);
	} while (D + 5 < Bd0 + Bdn);

	//��������
	w = XL::S_aLon(jd2 / 36525, 3);
	w = int2((w - 0.13) / pi2 * 24) *pi2 / 24;
	do {
		d = qi_accurate(w);
		D = int2(d + 0.5);
		xn = int2(w / pi2 * 24 + 24000006.01) % 24;
		w += pi2 / 24;
		if (D >= Bd0 + Bdn) break;
		if (D < Bd0) continue;
		Day& ob = lun[D - Bd0];
		ob.jqmc = xn; //ȡ�ý�������
		ob.jqjd = d;
		ob.jqsj = JD::timeStr(d);
	} while (D + 12 < Bd0 + Bdn);
	return month;
}