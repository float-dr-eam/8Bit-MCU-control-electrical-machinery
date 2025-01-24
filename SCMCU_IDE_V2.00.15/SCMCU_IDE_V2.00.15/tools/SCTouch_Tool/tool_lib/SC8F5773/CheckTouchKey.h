//---------------------------------------------------------
//管脚定义
#define			I2C_SCL			RB1
#define			I2C_SDA			RB0
volatile bit  	I2C_SCL_IO		@((unsigned)&TRISB*8)+1;		//IB口方向设置
volatile bit  	I2C_SDA_IO		@((unsigned)&TRISB*8)+0;		//IB口方向设置


//下面是触摸内部一些控制位的宏定义,无需更改
//触摸按键内部比较器正端电压选择
#define		C_KVREF_04		0x00		//0.4VDD
#define		C_KVREF_05		0x40		//0.5VDD
#define		C_KVREF_06		0x80		//0.6VDD
#define		C_KVREF_07		0xC0		//0.7VDD


//触摸按键时钟选择
#define		C_KCLK_SYS		0x00		//fsys
#define		C_KCLK_SYS2		0x10		//fsys/2
#define		C_KCLK_SYS4		0x20		//fsys/4
#define		C_KCLK_SYS8		0x30		//fsys/8

//内部比较器参考电压设定,在下列值中选取
//C_KVREF_04	=>	0.4VDD
//C_KVREF_05	=>	0.5VDD
//C_KVREF_06	=>	0.6VDD
//C_KVREF_07	=>	0.7VDD
#define		C_KVREF			C_KVREF_05

//转换时钟设定,在下列值中选取,建议选择4/8分频
//C_KCLK_SYS	=>	系统时钟
//C_KCLK_SYS2	=>	系统时钟的2分频
//C_KCLK_SYS4	=>	系统时钟的4分频
//C_KCLK_SYS8	=>	系统时钟的8分频
#define		C_KCLK			C_KCLK_SYS4

//触摸检测通道选择
#define		C_KCHS0			C_KVREF|C_KCLK|0x00
#define		C_KCHS1			C_KVREF|C_KCLK|0x01
#define		C_KCHS2			C_KVREF|C_KCLK|0x02
#define		C_KCHS3			C_KVREF|C_KCLK|0x03
#define		C_KCHS4			C_KVREF|C_KCLK|0x04
#define		C_KCHS5			C_KVREF|C_KCLK|0x05
#define		C_KCHS6			C_KVREF|C_KCLK|0x06
#define		C_KCHS7			C_KVREF|C_KCLK|0x07

//触摸数字滤波时钟选择
#define		C_LVBO_SYS0		0x00		//fsys
#define		C_LVBO_SYS1		0x20		//fsys/2
#define		C_LVBO_SYS2		0x40		//fsys/4
#define		C_LVBO_SYS3		0x60		//fsys/8
#define		C_LVBO_SYS4		0x80		//fsys
#define		C_LVBO_SYS5		0xA0		//fsys/2
#define		C_LVBO_SYS6		0xC0		//fsys/4
#define		C_LVBO_SYS7		0xE0		//fsys/8

#define		C_LVBO			C_LVBO_SYS0

#define		C_KEYCON2		C_LVBO |0x08

//---------------------------------------------------------------------------
extern unsigned int  TKDATA0;           //按键旧值


//-----------------------------------------------------------------------------
//函数声明
void CheckTouchKey();
unsigned char I2C_Read1bYTE(unsigned char ack);
unsigned char I2C_Write1bYTE(unsigned char data);
void I2C_WaitMoment();
void I2C_WriteStop();
void I2C_WriteStart();
void CheckTouchKey(void);		//触摸函数

#endif




