//#include "XL.h"
//#include "const.h"
//#include <math.h>
//
//long double XL::S_aLon_t(long double W)
//{
//	long double t, v = 628.3319653318;
//	t = (W - 1.75347 - PI) / v; v = E_v(t); //v�ľ���0.03%�����ԭ��
//	t += (W - S_aLon(t, 10)) / v; v = E_v(t); //����һ��v��������߾���,����Ҳ����
//	t += (W - S_aLon(t, -1)) / v;
//	return t;
//}
//
////�����ٶ�,t��������,���С�����3
//long double XL::E_v(long double t)
//{
//	long double f = 628.307585*t;
//	return 628.332 + 21 * sin(1.527 + f) + 0.44 * sin(1.48 + f * 2)
//		+ 0.129*sin(5.82 + f)*t + 0.00055*sin(4.21 + f)*t*t;
//}
//
////̫���ӻƾ�
//long double XL::S_aLon(long double t, long double n) {  
//	return E_Lon(t, n) + nutationLon2(t) + gxc_sunLon(t) + PI; //ע�⣬������¶�����ܺ�ʱ
//};
//
//long double XL::E_Lon(long double t, long double n)
//{ 
//	return XL0_calc(0, 0, t, n);
//}
//
//long double XL::XL0_calc(long double xt, int zn, long double t, int n)
//{
//	static long double XL0_xzb[] = { //��������������
//		//��(����),γ(����), ��(10-6AU)
//		-0.08631, +0.00039, -0.00008,  //ˮ��
//		-0.07447, +0.00006, +0.00017,  //����
//		-0.07135, -0.00026, -0.00176,  //����
//		-0.20239, +0.00273, -0.00347,  //ľ��
//		-0.25486, +0.00276, +0.42926,  //����
//		+0.24588, +0.00345, -14.46266, //������
//		-0.95116, +0.02481, +58.30651  //������
//	};
//
//	t /= 10; //תΪ����ǧ����
//	int i, j, v = 0, tn = 1, c;
//	long double F = XL0[xt], n1, n2, N;
//	var n0, pn = zn * 6 + 1, N0 = F[pn + 1] - F[pn]; //N0��������
//	for (i = 0; i < 6; i++, tn *= t) {
//		n1 = F[pn + i], n2 = F[pn + 1 + i], n0 = n2 - n1;
//		if (!n0) continue;
//		if (n < 0) N = n2;  //ȷ������
//		else { N = int2(3 * n*n0 / N0 + 0.5) + n1;  if (i) N += 3;  if (N > n2) N = n2; }
//		for (j = n1, c = 0; j < N; j += 3) c += F[j] * Math.cos(F[j + 1] + t*F[j + 2]);
//		v += c*tn;
//	}
//	v /= F[0];
//	if (xt == 0) { //����
//		var t2 = t*t, t3 = t2*t; //ǧ�����ĸ��η�
//		if (zn == 0) v += (-0.0728 - 2.7702*t - 1.1019*t2 - 0.0996*t3) / rad;
//		if (zn == 1) v += (+0.0000 + 0.0004*t + 0.0004*t2 - 0.0026*t3) / rad;
//		if (zn == 2) v += (-0.0020 + 0.0044*t + 0.0213*t2 - 0.0250*t3) / 1000000;
//	}
//	else { //��������
//		var dv = XL0_xzb[(xt - 1) * 3 + zn];
//		if (zn == 0) v += -3 * t / rad;
//		if (zn == 2) v += dv / 1000000;
//		else      v += dv / rad;
//	}
//	return v;
//}
//
//
//
//
