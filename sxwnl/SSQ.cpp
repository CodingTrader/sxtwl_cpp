#include "SSQ.h"
#include "const.h"
#include "eph.h"
SSQ::SSQ()
{

	std::string  suoS = "", qiS = "";
	// 619-01-21��ʼ16598��˷�������� d0=1947168
	suoS = "EqoFscDcrFpmEsF2DfFideFelFpFfFfFiaipqti1ksttikptikqckstekqttgkqttgkqteksttikptikq2fjstgjqttjkqttgkqt";
	suoS += "ekstfkptikq2tijstgjiFkirFsAeACoFsiDaDiADc1AFbBfgdfikijFifegF1FhaikgFag1E2btaieeibggiffdeigFfqDfaiBkF";
	suoS += "1kEaikhkigeidhhdiegcFfakF1ggkidbiaedksaFffckekidhhdhdikcikiakicjF1deedFhFccgicdekgiFbiaikcfi1kbFibef";
	suoS += "gEgFdcFkFeFkdcfkF1kfkcickEiFkDacFiEfbiaejcFfffkhkdgkaiei1ehigikhdFikfckF1dhhdikcfgjikhfjicjicgiehdik";
	suoS += "cikggcifgiejF1jkieFhegikggcikFegiegkfjebhigikggcikdgkaFkijcfkcikfkcifikiggkaeeigefkcdfcfkhkdgkegieid";
	suoS += "hijcFfakhfgeidieidiegikhfkfckfcjbdehdikggikgkfkicjicjF1dbidikFiggcifgiejkiegkigcdiegfggcikdbgfgefjF1";
	suoS += "kfegikggcikdgFkeeijcfkcikfkekcikdgkabhkFikaffcfkhkdgkegbiaekfkiakicjhfgqdq2fkiakgkfkhfkfcjiekgFebicg";
	suoS += "gbedF1jikejbbbiakgbgkacgiejkijjgigfiakggfggcibFifjefjF1kfekdgjcibFeFkijcfkfhkfkeaieigekgbhkfikidfcje";
	suoS += "aibgekgdkiffiffkiakF1jhbakgdki1dj1ikfkicjicjieeFkgdkicggkighdF1jfgkgfgbdkicggfggkidFkiekgijkeigfiski";
	suoS += "ggfaidheigF1jekijcikickiggkidhhdbgcfkFikikhkigeidieFikggikhkffaffijhidhhakgdkhkijF1kiakF1kfheakgdkif";
	suoS += "iggkigicjiejkieedikgdfcggkigieeiejfgkgkigbgikicggkiaideeijkefjeijikhkiggkiaidheigcikaikffikijgkiahi1";
	suoS += "hhdikgjfifaakekighie1hiaikggikhkffakicjhiahaikggikhkijF1kfejfeFhidikggiffiggkigicjiekgieeigikggiffig";
	suoS += "gkidheigkgfjkeigiegikifiggkidhedeijcfkFikikhkiggkidhh1ehigcikaffkhkiggkidhh1hhigikekfiFkFikcidhh1hit";
	suoS += "cikggikhkfkicjicghiediaikggikhkijbjfejfeFhaikggifikiggkigiejkikgkgieeigikggiffiggkigieeigekijcijikgg";
	suoS += "ifikiggkideedeijkefkfckikhkiggkidhh1ehijcikaffkhkiggkidhh1hhigikhkikFikfckcidhh1hiaikgjikhfjicjicgie";
	suoS += "hdikcikggifikigiejfejkieFhegikggifikiggfghigkfjeijkhigikggifikiggkigieeijcijcikfksikifikiggkidehdeij";
	suoS += "cfdckikhkiggkhghh1ehijikifffffkhsFngErD1pAfBoDd1BlEtFqA2AqoEpDqElAEsEeB2BmADlDkqBtC1FnEpDqnEmFsFsAFn";
	suoS += "llBbFmDsDiCtDmAB2BmtCgpEplCpAEiBiEoFqFtEqsDcCnFtADnFlEgdkEgmEtEsCtDmADqFtAFrAtEcCqAE1BoFqC1F1DrFtBmF";
	suoS += "tAC2ACnFaoCgADcADcCcFfoFtDlAFgmFqBq2bpEoAEmkqnEeCtAE1bAEqgDfFfCrgEcBrACfAAABqAAB1AAClEnFeCtCgAADqDoB";
	suoS += "mtAAACbFiAAADsEtBqAB2FsDqpFqEmFsCeDtFlCeDtoEpClEqAAFrAFoCgFmFsFqEnAEcCqFeCtFtEnAEeFtAAEkFnErAABbFkAD";
	suoS += "nAAeCtFeAfBoAEpFtAABtFqAApDcCGJ";

	//1645-09-23��ʼ7567������������
	qiS = "FrcFs22AFsckF2tsDtFqEtF1posFdFgiFseFtmelpsEfhkF2anmelpFlF1ikrotcnEqEq2FfqmcDsrFor22FgFrcgDscFs22FgEe";
	qiS += "FtE2sfFs22sCoEsaF2tsD1FpeE2eFsssEciFsFnmelpFcFhkF2tcnEqEpFgkrotcnEqrEtFermcDsrE222FgBmcmr22DaEfnaF22";
	qiS += "2sD1FpeForeF2tssEfiFpEoeFssD1iFstEqFppDgFstcnEqEpFg11FscnEqrAoAF2ClAEsDmDtCtBaDlAFbAEpAAAAAD2FgBiBqo";
	qiS += "BbnBaBoAAAAAAAEgDqAdBqAFrBaBoACdAAf1AACgAAAeBbCamDgEifAE2AABa1C1BgFdiAAACoCeE1ADiEifDaAEqAAFe1AcFbcA";
	qiS += "AAAAF1iFaAAACpACmFmAAAAAAAACrDaAAADG0";



	SB = jieya(suoS);  //��˷�������ѹ
	QB = jieya(qiS);   //�����������ѹ


	//˷ֱ����ϲ���
	long double suoKBTmp[] = {
		1457698.231017,29.53067166, // -721-12-17 h=0.00032 ����������
		1546082.512234,29.53085106, // -479-12-11 h=0.00053 ������ս��
		1640640.735300,29.53060000, // -221-10-31 h=0.01010 �������غ�
		1642472.151543,29.53085439, // -216-11-04 h=0.00040 �������غ�

		1683430.509300,29.53086148, // -104-12-25 h=0.00313 ���顤����־(̫����)ƽ��ƽ˷
		1752148.041079,29.53085097, //   85-02-13 h=0.00049 ���顤����־(�ķ���)
		1807665.420323,29.53059851, //  237-02-12 h=0.00033 ���顤����־(������)
		1883618.114100,29.53060000, //  445-01-24 h=0.00030 ���顤����־(�γ���Ԫ����)
		1907360.704700,29.53060000, //  510-01-26 h=0.00030 ���顤����־(���֮������)
		1936596.224900,29.53060000, //  590-02-10 h=0.01010 ���顤����־(������)
		1939135.675300,29.53060000, //  597-01-24 h=0.00890 ���顤����־(��ҵ��)
		1947168.00//  619-01-21
	};

	suoKB = new std::vector<long double>(suoKBTmp, suoKBTmp + sizeof(suoKBTmp) / sizeof(long double));

	long double qiKBTmp[] = {
		1640650.479938,15.21842500, // -221-11-09 h=0.01709 �������غ�
		1642476.703182,15.21874996, // -216-11-09 h=0.01557 �������غ�

		1683430.515601,15.218750011, // -104-12-25 h=0.01560 ���顤����־(̫����)ƽ��ƽ˷ �ع���=365.25000
		1752157.640664,15.218749978, //   85-02-23 h=0.01559 ���顤����־(�ķ���) �ع���=365.25000
		1807675.003759,15.218620279, //  237-02-22 h=0.00010 ���顤����־(������) �ع���=365.24689
		1883627.765182,15.218612292, //  445-02-03 h=0.00026 ���顤����־(�γ���Ԫ����) �ع���=365.24670
		1907369.128100,15.218449176, //  510-02-03 h=0.00027 ���顤����־(���֮������) �ع���=365.24278
		1936603.140413,15.218425000, //  590-02-17 h=0.00149 ���顤����־(������) �ع���=365.24220
		1939145.524180,15.218466998, //  597-02-03 h=0.00121 ���顤����־(��ҵ��) �ع���=365.24321
		1947180.798300,15.218524844, //  619-02-03 h=0.00052 �����顤��־(����Ԫ��)ƽ����˷ �ع���=365.24460
		1964362.041824,15.218533526, //  666-02-17 h=0.00059 �����顤��־(�����) �ع���=365.24480
		1987372.340971,15.218513908, //  729-02-16 h=0.00096 �����顤��־(������,������) �ع���=365.24433
		1999653.819126,15.218530782, //  762-10-03 h=0.00093 �����顤��־(�����) �ع���=365.24474
		2007445.469786,15.218535181, //  784-02-01 h=0.00059 �����顤��־(��Ԫ��,������) �ع���=365.24484
		2021324.917146,15.218526248, //  822-02-01 h=0.00022 �����顤��־(������) �ع���=365.24463
		2047257.232342,15.218519654, //  893-01-31 h=0.00015 �����顤��־(������) �ع���=365.24447
		2070282.898213,15.218425000, //  956-02-16 h=0.00149 ���������־(������) �ع���=365.24220
		2073204.872850,15.218515221, //  964-02-16 h=0.00166 ��ʷ������־(Ӧ����) �ع���=365.24437
		2080144.500926,15.218530782, //  983-02-16 h=0.00093 ��ʷ������־(ǬԪ��) �ع���=365.24474
		2086703.688963,15.218523776, // 1001-01-31 h=0.00067 ��ʷ������־(������,������) �ع���=365.24457
		2110033.182763,15.218425000, // 1064-12-15 h=0.00669 ��ʷ������־(������) �ع���=365.24220
		2111190.300888,15.218425000, // 1068-02-15 h=0.00149 ��ʷ������־(������) �ع���=365.24220
		2113731.271005,15.218515671, // 1075-01-30 h=0.00038 ������(��Ԫ��) �ع���=365.24438
		2120670.840263,15.218425000, // 1094-01-30 h=0.00149 ��ʷ������־ �ع���=365.24220
		2123973.309063,15.218425000, // 1103-02-14 h=0.00669 ������(ռ����) �ع���=365.24220
		2125068.997336,15.218477932, // 1106-02-14 h=0.00056 ��ʷ������־(��Ԫ��) �ع���=365.24347
		2136026.312633,15.218472436, // 1136-02-14 h=0.00088 ��ʷ������־(ͳԪ��,Ǭ����,������) �ع���=365.24334
		2156099.495538,15.218425000, // 1191-01-29 h=0.00149 ��ʷ������־(��Ԫ��) �ع���=365.24220
		2159021.324663,15.218425000, // 1199-01-29 h=0.00149 ��ʷ������־(ͳ����) �ع���=365.24220
		2162308.575254,15.218461742, // 1208-01-30 h=0.00146 ��ʷ������־(������) �ع���=365.24308
		2178485.706538,15.218425000, // 1252-05-15 h=0.04606 ���v�� �ع���=365.24220
		2178759.662849,15.218445786, // 1253-02-13 h=0.00231 ������ �ع���=365.24270
		2185334.020800,15.218425000, // 1271-02-13 h=0.00520 ��ʷ������־(������) �ع���=365.24220
		2187525.481425,15.218425000, // 1277-02-12 h=0.00520 ������ �ع���=365.24220
		2188621.191481,15.218437494, // 1280-02-13 h=0.00015 Ԫʷ����־(���ؾ���ʱ��) �ع���=365.24250
		2322147.76// 1645-09-21
	};

	qiKB = new std::vector<long double>(qiKBTmp, qiKBTmp + sizeof(qiKBTmp) / sizeof(long double));
}

SSQ::~SSQ()
{
	delete suoKB;
	delete qiKB;
}

void str_replace(std::string & str, const std::string strsrc, const std::string strdst)
{
	std::string::size_type pos = 0;//λ��
	std::string::size_type srclen = strsrc.size();//Ҫ�滻���ַ�����С
	std::string::size_type dstlen = strdst.size();//Ŀ���ַ�����С
	while ((pos = str.find(strsrc, pos)) != std::string::npos)
	{
		str.replace(pos, srclen, strdst);
		pos += dstlen;
	}
}


std::string SSQ::jieya(std::string s) { //��˷��ѹ��
	std::string o = "0000000000", o2 = o + o;
	str_replace(s, "J", "00");
	str_replace(s, "I", "000");
	str_replace(s, "H", "0000");
	str_replace(s, "G", "00000");
	str_replace(s, "t", "02");
	str_replace(s, "s", "002");
	str_replace(s, "r", "0002");
	str_replace(s, "q", "00002");
	str_replace(s, "p", "000002");
	str_replace(s, "o", "0000002");
	str_replace(s, "n", "00000002");
	str_replace(s, "m", "000000002");
	str_replace(s, "l", "0000000002");
	str_replace(s, "k", "01");
	str_replace(s, "j", "0101");
	str_replace(s, "i", "001");
	str_replace(s, "h", "001001");
	str_replace(s, "g", "0001");
	str_replace(s, "f", "00001");
	str_replace(s, "e", "000001");
	str_replace(s, "d", "0000001");
	str_replace(s, "c", "00000001");
	str_replace(s, "b", "000000001");
	str_replace(s, "a", "0000000001");
	str_replace(s, "A", o2 + o2 + o2);
	str_replace(s, "B", o2 + o2 + o);
	str_replace(s, "C", o2 + o2);
	str_replace(s, "D", o2 + o);
	str_replace(s, "E", o2);
	str_replace(s, "F", o);
	return s;
}

int  SSQ::calc(long double jd, QSType qs)
{
	jd += 2451545;
	int i, D;
	std::string n;
	std::vector<long double> B = *suoKB;
	long double pc = 14;
	//����������˷
	if (qs == QType)
	{
		B = *qiKB, pc = 7;
	}

	long double f1 = B[0] - pc, f2 = B[B.size() - 1] - pc, f3 = 2436935;

	if (jd < f1 || jd >= f3)
	{
		//ƽ��˷�����׸�֮ǰ��ʹ���ִ������㷨��1960.1.1�Ժ�ʹ���ִ������㷨 (��һ���ֵ�����qi_high��so_high,������������֧��)
		if (qs == QType)
		{
			return (int)(qi_high((int)((jd + pc - 2451259) / 365.2422 * 24) * PI / 12) + 0.5); //2451259��1999.3.21,̫���ӻƾ�Ϊ0,����.��������
		}
		else
		{
			return (int)(so_high((int)((jd + pc - 2451551) / 29.5306) * PI * 2) + 0.5); //2451551��2000.1.7���Ǹ�˷��,�ƾ���Ϊ0.��˷����
		}
	}

	if (jd >= f1 && jd < f2) { //ƽ����ƽ˷
		for (i = 0; i < B.size(); i += 2)  if (jd + pc < B[i + 2]) break;
		D = B[i] + B[i + 1] * (int)((jd + pc - B[i]) / B[i + 1]);
		D = (int)(D + 0.5);
		if (D == 1683460) D++; //���ʹ��̫��������-103��1��24�յ�˷��,����õ�����23��,��������Ϊ24��(ʵ��)���������Բ�Ӱ��-103�������������ʹ���غ������õ�����24�գ�����D���ᱻִ�С�
		return D - 2451545;
	}

	if (jd >= f2 && jd < f3) { //������˷
		if (qs == QType) {
			D = (int)(qi_low((int)((jd + pc - 2451259) / 365.2422 * 24) * PI / 12) + 0.5); //2451259��1999.3.21,̫���ӻƾ�Ϊ0,����.��������
			n = QB.substr((int)((jd - f2) / 365.2422 * 24), 1); //�Ҷ�������ֵ
		}
		else {
			D = (int)(so_low((int)((jd + pc - 2451551) / 29.5306) * PI * 2) + 0.5); //2451551��2000.1.7���Ǹ�˷��,�ƾ���Ϊ0.��˷����
			n = SB.substr((int)((jd - f2) / 29.5306), 1); //�Ҷ�˷����ֵ
		}
		if (n == "1") return D + 1;
		if (n == "2") return D - 1;
		return D;
	}
}


long double SSQ::qi_high(long double W)
{
	long double t = XL::S_aLon_t2(W) * 36525;
	t = t - dt_T(t) + 8.0 / 24.0;
	long double v = fmod(t + 0.5, 1) * 86400;
	if (v < 1200 || v >86400 - 1200) t = XL::S_aLon_t(W) * 36525 - dt_T(t) + 8.0 / 24.0;
	return  t;
}


long double SSQ::so_high(long double W)
{ //�ϸ߾���˷
	long double t = XL::MS_aLon_t2(W) * 36525;
	t = t - dt_T(t) + 8.0 / 24.0;
	long double v = fmod(t + 0.5, 1) * 86400;
	if (v < 1800 || v >86400 - 1800) t = XL::MS_aLon_t(W) * 36525 - dt_T(t) + 8.0 / 24.0;
	return  t;
}

long double SSQ::so_low(long double W) { //�;��ȶ�˷����,��2000����600�������2Сʱ����(�ԱȹŴ�������׼�ܶ�)
	long double v = 7771.37714500204;
	long double t = (W + 1.08472) / v, L;
	t -= (-0.0000331*t*t
		+ 0.10976 *cos(0.785 + 8328.6914*t)
		+ 0.02224 *cos(0.187 + 7214.0629*t)
		- 0.03342 *cos(4.669 + 628.3076*t)) / v
		+ (32 * (t + 1.8)*(t + 1.8) - 20) / 86400 / 36525;
	return t * 36525 + 8.0 / 24.0;
}

long double SSQ::qi_low(long double W) { //������С��30���ӣ�ƽ��5��
	long double t, L, v = 628.3319653318;
	t = (W - 4.895062166) / v; //��һ�ι���,���2������
	t -= (53 * t*t + 334116 * cos(4.67 + 628.307585*t) + 2061 * cos(2.678 + 628.3076*t)*t) / v / 10000000; //�ڶ��ι���,���2Сʱ����

	L = 48950621.66 + 6283319653.318*t + 53 * t*t //ƽ�ƾ�
		+ 334166 * cos(4.669257 + 628.307585*t) //������Բ�������չ��
		+ 3489 * cos(4.6261 + 1256.61517*t) //������Բ�������չ��
		+ 2060.6 * cos(2.67823 + 628.307585*t) * t  //һ�β�����
		- 994 - 834 * sin(2.1824 - 33.75705*t); //���в����¶�����

	t -= (L / 10000000 - W) / 628.332 + (32 * (t + 1.8)*(t + 1.8) - 20) / 86400 / 36525;
	return t * 36525 + 8.0 / 24.0;
}


void SSQ::calcY(int jd) { //ũ�����������,�ɶ���ũ��,��Ч��Χ����������֮��(����һ <= d < ������)
	std::vector<long double>& A = ZQ;
	std::vector<int>& B = HS;  //������,���º�˷��(����)
	int i, k;
	long double W, w;

	//�������
	W = int2((jd - 355 + 183) / 365.2422)*365.2422 + 355;  //355��2000.12����,�õ��Ͽ���jd�Ķ�������ֵ
	if (calc(W, QType) > jd)
	{
		W -= 365.2422;
	}

	//25������ʱ��(����ʱ��),�Ӷ�����ʼ����һ�������Ժ�;
	A.clear();
	for (i = 0; i < 25; i++)
	{	
		int t = calc(W + 15.2184*i, QType);
		A.push_back(t);
	}
			
	ZQ_pe1 = calc(W - 15.2, QType); ZQ_pe2 = calc(W - 30.4, QType); //�������,ȷ��һ���������·ݵġ�����ȫ������������
															//����"��˷"�����»ƾ���w
	w = calc(A[0], SType); //��Ͽ���������˷��
	if (w > A[0])
	{
		w -= 29.53;
	}

	//��������˷,����14���µ�ʼĩ
	B.clear();
	for (i = 0; i < 15; i++)
	{
		B.push_back( calc(w + 29.5306*i, SType) );
	}
		

	//�´�С
	leap = 0;
	dx.clear();
	ym.clear();
	for (i = 0; i < 14; i++) {
		dx.push_back( HS[i + 1] - HS[i] ); //�´�С
		ym.push_back(i);  //�����ʼ��
	}


	//-721����-104��ĺ���¼��½�����,��˷�йأ������޹�
	int YY = int2((ZQ[0] + 10 + 180) / 365.2422) + 2000; //ȷ�����
	if (YY >= -721 && YY <= -104) {
		int ns[12];
		int yy;
		for (i = 0; i < 3; i++) {
			yy = YY + i - 1;
			//����������, ��������, �½�
			if (yy >= -721) ns[i] = calc(1457698 - J2000 + int2(0.342 + (yy + 721)*12.368422)*29.5306, SType), ns[i + 3] = 'ʮ��', ns[i + 6] = 2;  //������,lyΪ-722.12.17
			if (yy >= -479) ns[i] = calc(1546083 - J2000 + int2(0.500 + (yy + 479)*12.368422)*29.5306, SType), ns[i + 3] = 'ʮ��', ns[i + 6] = 2;  //ս����,lyΪ-480.12.11
			if (yy >= -220) ns[i] = calc(1640641 - J2000 + int2(0.866 + (yy + 220)*12.369000)*29.5306, SType), ns[i + 3] = '���', ns[i + 6] = 11; //�غ���,lyΪ-221.10.31
		}

		int nn, f1;
		for (i = 0; i < 14; i++) {
			for (nn = 2; nn >= 0; nn--) if (HS[i] >= ns[nn]) break;
			f1 = int2((HS[i] - ns[nn] + 15) / 29.5306); //���»���
			if (f1 < 12) ym[i] = (f1 + ns[nn + 6]) % 12; else ym[i] = ns[nn + 3];
		}
		return;
	}


	//����������ȷ������,(��˷��Ϸ�,����Դ���ж�����ʼ�ĵ�����˷)
	if (B[13] <= A[24]) { //��13�µ���ĩû�г�������(��������),˵�����꺬��13����
		for (i = 1; B[i + 1] > A[2 * i] && i < 13; i++); //��13�������ҵ�1��û���������·�
		leap = i;
		for (; i < 14; i++) ym[i]--;
	}

	//����ת��(�½�����)
	for (i = 0; i < 14; i++) {
		int Dm = HS[i] + J2000, v2 = ym[i]; //Dm��һ��������,v2Ϊ�½����
		int mc = v2 % 12; //�½���Ӧ��Ĭ�������ƣ�����ʮһ,����ʮ��,����Ϊ������
		if (Dm >= 1724360 && Dm <= 1729794) mc = (v2 + 1) % 12; //  8.01.15�� 23.12.02 ����Ϊʮ��,����˳��
		else if (Dm >= 1807724 && Dm <= 1808699) mc = (v2 + 1) % 12; //237.04.12��239.12.13 ����Ϊʮ��,����˳��
		else if (Dm >= 1999349 && Dm <= 1999467) mc = (v2 + 2) % 12; //761.12.02��762.03.30 ����Ϊ����,����˳��
		else if (Dm >= 1973067 && Dm <= 1977052) { if (v2 % 12 == 0) mc = 2; if (v2 == 2) mc = 2; } //689.12.18��700.11.15 ����Ϊ����,����Ϊһ��,��������

		if (Dm == 1729794 || Dm == 1808699) mc = 'ʰ��'; //239.12.13��23.12.02��Ϊʮ����,Ϊ������������ʮ���£��˴�����

		ym[i] = mc;
	}
}

