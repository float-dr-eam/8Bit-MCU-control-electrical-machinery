#ifndef _TOUCHKEY_CONST_H_
#define _TOUCHKEY_CONST_H_

//��������ʱ�䶨��
const unsigned char C_OPTION_REG_ = 0x0A;		//���64msWDT����һ�μ�ⰴ��
												//=0x0B��Ϊ128ms���Ѽ��
												//��ѡWDT_DIV����0AΪ96ms���Ѽ��
const unsigned char KeyWakeUpEn = 0;

//�����Ǵ����ڲ�һЩ����λ�ĺ궨��,�������
//���������ڲ��Ƚ������˵�ѹѡ��

#define		C_KVREF_05		0x40		//0.5VDD
#define		C_KVREF_06		0x80		//0.6VDD
#define		C_KVREF_07		0xC0		//0.7VDD


//��������ʱ��ѡ��(�Ƽ�fhsi/4�����ϣ�
#define		C_KCLK_SYS2		0x00		//fhsi/2
#define		C_KCLK_SYS4		0x10		//fhsi/4
#define		C_KCLK_SYS8		0x20		//fhsi/8
#define		C_KCLK_SYS16	0x30		//fhsi/16

//�������ͨ��ѡ��
#define		C_KCHS0			C_KVREF|C_KCLK|0x00
#define		C_KCHS1			C_KVREF|C_KCLK|0x01
#define		C_KCHS2			C_KVREF|C_KCLK|0x02

#define		C_KCHS4			C_KVREF|C_KCLK|0x04

//������Ƶѡ��
#define		TP_EN			0X10		//ʹ����Ƶ����CE������

//�����˲�ѡ��
#define		CAP_LVBO		0X60		//Ĭ��4���˲����Դ�������û��Ӱ��

//������׼Դʹ��
#define		TKLDOEN			0X08		//ʹ�ܴ�����׼�����ӿ��Ʋ�����

//������׼ѡ��
#define		TKLDO_SEL		0X00		//ѡ��2V���ο���2.4VΪ0x02

#define		C_TP_LDO		CAP_LVBO|TP_EN|TKLDOEN|TKLDO_SEL|0X01



#endif