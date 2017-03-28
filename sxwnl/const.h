#pragma once
//PI
#define PI (3.141592653589793)

//�������뾶(ǧ��)
#define  cs_rEar (6378.1366) 
//ƽ���뾶
#define  cs_rEarA (0.99834*cs_rEar)
//���򼫳�뾶��
#define  cs_ba (0.99664719) 
//���򼫳�뾶�ȵ�ƽ��
#define  cs_ba2 (cs_ba*cs_ba)
//���ĵ�λ����(ǧ��)
#define  cs_AU (1.49597870691e8) 
//sin(̫���Ӳ�)
#define  cs_sinP (cs_rEar / cs_AU)  
//̫���Ӳ�
#define  cs_PI ( Math.asin(cs_sinP))
//����(����/��)
#define  cs_GS ( 299792.458) 
//ÿ���ĵ�λ�Ĺ���ʱ��(��������)
#define  cs_Agx ( cs_AU / cs_GS / 86400 / 36525) 
//#define  cs_xxHH ( new Array(116, 584, 780, 399, 378, 370, 367, 367)) //���ǻ������
//#define  xxName ( new Array('����', 'ˮ��', '����', '����', 'ľ��', '����', '������', '������', 'ڤ����'))
//ÿ���ȵĽ�����
#define  rad ( 180 * 3600 / PI) 
//ÿ���ȵĶ���
#define  radd ( 180 / PI)
#define  pi2 ( PI * 2)
#define  pi_2 ( PI / 2)
#define  J2000 ( 2451545)
//
#define  cs_k ( 0.2725076) //���������İ뾶��(���ڰ�Ӱ����)
#define  cs_k2 ( 0.2722810) //���������İ뾶��(���ڱ�Ӱ����)
#define  cs_k0 ( 109.1222)  //̫�������İ뾶��(��Ӧ959.64)
#define  cs_sMoon ( cs_k*cs_rEar*1.0000036*rad)  //���������Ӱ뾶����
#define  cs_sMoon2 ( cs_k2*cs_rEar*1.0000036*rad) //���������Ӱ뾶����
#define  cs_sSun ( 959.64) //����̫���Ӱ뾶����

//ת����
#define int2(v) ((int)(v))
//����
#define fmod2(v, n) ((v%n + n) % n)
