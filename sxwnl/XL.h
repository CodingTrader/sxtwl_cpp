#pragma once

class XL
{
public:
	//��֪̫���ӻƾ�����ʱ��
	static long double S_aLon_t(long double W);

	//�����ٶ�,t��������,���С�����3
	static long double E_v(long double t);

	//̫���ӻƾ�
	static long double S_aLon(long double t, long double n);

	//���򾭶ȼ���,����Date�ֵ�ƾ�,������������ȡ����
	static long double E_Lon(long double t, long double n);

	//xt����,zn�����,t����������,n��������
	static long double XL0_calc(long double xt, int zn, long double t, int n);


};