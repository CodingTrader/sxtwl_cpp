#pragma once

struct Vector3
{
	Vector3(long double x, long double y, long double z) :
		x(x), y(y), z(z)
	{

	};

	Vector3(Vector3& v) :
		x(v.x), y(v.y), z(v.z)
	{

	};

	Vector3() {};
	long double x, y, z;

	long double& operator [](const unsigned __int64 index)////����[]����������Ϊ��ֵ
	{
		if (index == 0)
		{
			return x;
		}
		switch (index)
		{
			case 0: return x;
			case 1: return y;
			case 2: return z;
		}

	}
	const long double& operator [](const unsigned __int64 index) const////����[]����������Ϊ��ֵ
	{
		switch (index)
		{
		case 0: return x;
		case 1: return y;
		case 2: return z;
		}
	}
};

struct Vector2
{
	Vector2(long double x, long double y) :
		x(x), y(y)
	{

	};
	Vector2() {};
	long double x, y;

	long double& operator [](const unsigned __int64 index)////����[]����������Ϊ��ֵ
	{
		if (index == 0)
		{
			return x;
		}
		switch (index)
		{
		case 0: return x;
		case 1: return y;		
		}

	}
	const long double& operator [](const unsigned __int64 index) const////����[]����������Ϊ��ֵ
	{
		switch (index)
		{
		case 0: return x;
		case 1: return y;	
		}
	}
};

//=================================��ѧ����=========================================

//�Գ���0-2PI�ĽǶ�תΪ0-2PI;
long double rad2mrad(long double v);
//�Գ���-PI��PI�ĽǶ�תΪ-PI��PI;
long double  rad2rrad(long double v);
//�ٽ�����(a�������������b���ľ���);
long double mod2(long double a, long double b);
//����תֱ������;
Vector3 llr2xyz(Vector3 JW);
//ֱ������ת��;
Vector3 xyz2llr(Vector3  xyz);
//����������ת;
Vector3 llrConv(Vector3 JW, long double E);
//�������תΪ��ƽ����;
Vector3 CD2DP(Vector3 z, long double L, long double fa, long double gst);
//��ǶȲ�;
long double j1_j2(long double J1, long double W1, long double J2, long double W2);
//��������ת��������,Z������������,A������������;
//��������ͨ�õ�������������ƽ�ƺ���,���Ǽ����н�����ʹ��;
Vector3  h2g(Vector3 z, Vector3 a);
//�Ӳ��(�����Ӳ�);
long double shiChaJ(long double gst, long double L, long double fa, long double J, long double W);

//���XL : ���»Ƶ�ƽ�ֵ����ꡢ�����ꡢ�ٶȡ���֪���ȷ���ʱ��ȷ���ļ���
namespace XL
{
	//=====================
	//��������(���������������)

	long double E_Lon(long double t, int n); //���򾭶ȼ���,����Date�ֵ�ƾ�,������������ȡ����
	long double M_Lon(long double t, int n);     //���򾭶ȼ���,����Date�ֵ�ƾ�,����������,n����������
	//�����ٶ�,t��������,���С�����3													//=========================
	long double E_v(long double t);


	//�����ٶȼ���,����������
	long double M_v(long double t);

	//=========================
	//�����ӻƾ��Ĳ�ֵ
	long double  MS_aLon(long double t, long double Mn, long double Sn);

	//̫���ӻƾ�
	long double S_aLon(long double t, long double n);

	//=========================
	//��֪������ƾ���ʱ��
	long double E_Lon_t(long double W);

	//��֪������ƾ���ʱ��
	long double M_Lon_t(long double W);

	//��֪�����ӻƾ�����ʱ��
	long double MS_aLon_t(long double W);

	//��֪̫���ӻƾ�����ʱ��
	long double S_aLon_t(long double W);
	
	//��֪�����ӻƾ�����ʱ��,���ٵ;���,������600��(ֻ�����˼�ǧ��)
	long double MS_aLon_t2(long double W);
	//��֪̫���ӻƾ�����ʱ��,���ٵ;���,���������600��
	long double  S_aLon_t2(long double  W);

	long double  moonIll(long double  t);

	//ת���ƽγ�ȼ��������ľ���,����վ���Ӱ뾶(����)
	long double moonRad(long double r, long double h);

	//����������ʱ��;���,tΪ������������ѧʱ
	Vector2 moonMinR(long double t, long double min);

	Vector3  moonNode(long double t, long double asc);

	//�����Զ��
	Vector2 earthMinR(long double t, long double min);
};


//=================================deltat T����=====================================
long double dt_T(long double t);
