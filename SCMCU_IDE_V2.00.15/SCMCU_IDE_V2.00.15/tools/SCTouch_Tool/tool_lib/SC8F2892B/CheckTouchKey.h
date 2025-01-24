//---------------------------------------------------------

//�ܽŶ���
#define			I2C_SCL			RB1
#define			I2C_SDA			RB0
volatile bit  	I2C_SCL_IO		@((unsigned)&TRISB*8)+1;		//IB�ڷ�������
volatile bit  	I2C_SDA_IO		@((unsigned)&TRISB*8)+0;		//IB�ڷ�������

//---------------------------------------------------------------------------
//���������ڲ��Ƚ������˵�ѹѡ��
#define		C_KVREF_04		0x00		//0.4VDD
#define		C_KVREF_05		0x40		//0.5VDD
#define		C_KVREF_06		0x80		//0.6VDD
#define		C_KVREF_07		0xC0		//0.7VDD


//��������ʱ��ѡ��
#define		C_KCLK_SYS		0x00		//fsys
#define		C_KCLK_SYS2		0x10		//fsys/2
#define		C_KCLK_SYS4		0x20		//fsys/4
#define		C_KCLK_SYS8		0x30		//fsys/8

//�������ͨ��ѡ��
#define		C_KCHS0			C_KVREF|C_KCLK|0x00
#define		C_KCHS1			C_KVREF|C_KCLK|0x01
#define		C_KCHS2			C_KVREF|C_KCLK|0x02
#define		C_KCHS3			C_KVREF|C_KCLK|0x03
#define		C_KCHS4			C_KVREF|C_KCLK|0x04
#define		C_KCHS11		C_KVREF|C_KCLK|0x0B
#define		C_KCHS12		C_KVREF|C_KCLK|0x0C


//���߲�������ѡ��,ʹ�ܵ��ݿ�
#define		C_KCAP0 		0x00 | 0x2
#define		C_KCAP1 		0x08 | 0x2
#define		C_KCAP2 		0x10 | 0x2
#define		C_KCAP3 		0x18 | 0x2
#define		C_KCAP4 		0x20 | 0x2
#define		C_KCAP5 		0x28 | 0x2
#define		C_KCAP6 		0x30 | 0x2
#define		C_KCAP7 		0x38 | 0x2



//�ڲ��Ƚ����ο���ѹ�趨,������ֵ��ѡȡ
//C_KVREF_04	=>	0.4VDD
//C_KVREF_05	=>	0.5VDD
//C_KVREF_06	=>	0.6VDD
//C_KVREF_07	=>	0.7VDD
#define		C_KVREF			C_KVREF_05

//ת��ʱ���趨,������ֵ��ѡȡ,����ѡ��4��Ƶ
//C_KCLK_SYS	=>	ϵͳʱ��
//C_KCLK_SYS2	=>	ϵͳʱ�ӵ�2��Ƶ
//C_KCLK_SYS4	=>	ϵͳʱ�ӵ�4��Ƶ
//C_KCLK_SYS8	=>	ϵͳʱ�ӵ�8��Ƶ
#define		C_KCLK			C_KCLK_SYS4


//���ͨ���趨,ΪC_KCHS0��C_KCHS15����֮һ
//δ�趨��ͨ��Ĭ��ΪC_KCHS0
const unsigned char Table_KeyChannel[] = {
	C_KCHS0,		//����1��Ӧ����ͨ��
	C_KCHS1,		//����2��Ӧ����ͨ��
	C_KCHS2,		//����3��Ӧ����ͨ��
	C_KCHS3,		//����4��Ӧ����ͨ��
	C_KCHS4,		//����2��Ӧ����ͨ��
	C_KCHS11,		//����3��Ӧ����ͨ��
	C_KCHS12		//����4��Ӧ����ͨ��
};

//�ڲ���������ѡ��,��������������,�������Ϊ0,�ʵ�������ߵ�ֵ,��Χ:C_KCAP0��C_KCAP7
const unsigned char Table_KeyCap[] = {
	C_KCAP0,		//����1�ڲ���������
	C_KCAP0,		//����2�ڲ���������
	C_KCAP0,		//����3�ڲ���������
	C_KCAP0,		//����4�ڲ���������
	C_KCAP0,		//����5�ڲ���������
	C_KCAP0,		//����11�ڲ���������
	C_KCAP0			//����12�ڲ���������
};
//-----------------------------------------------------------------------------
//��������
void CheckTouchKey();

extern unsigned int  TKDATA0;			//������ֵ

unsigned char I2C_Read1bYTE(unsigned char ack);
unsigned char I2C_Write1bYTE(unsigned char data);
void I2C_WaitMoment();
void I2C_WriteStop();
void I2C_WriteStart();




///////////////////////////////////////////////////////////////////////////////////












void CheckTouchKey(void);		//��������

#endif




