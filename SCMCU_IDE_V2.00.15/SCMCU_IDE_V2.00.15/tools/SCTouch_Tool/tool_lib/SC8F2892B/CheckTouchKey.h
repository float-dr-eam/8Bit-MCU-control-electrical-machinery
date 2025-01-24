//---------------------------------------------------------

//管脚定义
#define			I2C_SCL			RB1
#define			I2C_SDA			RB0
volatile bit  	I2C_SCL_IO		@((unsigned)&TRISB*8)+1;		//IB口方向设置
volatile bit  	I2C_SDA_IO		@((unsigned)&TRISB*8)+0;		//IB口方向设置

//---------------------------------------------------------------------------
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

//触摸检测通道选择
#define		C_KCHS0			C_KVREF|C_KCLK|0x00
#define		C_KCHS1			C_KVREF|C_KCLK|0x01
#define		C_KCHS2			C_KVREF|C_KCLK|0x02
#define		C_KCHS3			C_KVREF|C_KCLK|0x03
#define		C_KCHS4			C_KVREF|C_KCLK|0x04
#define		C_KCHS11		C_KVREF|C_KCLK|0x0B
#define		C_KCHS12		C_KVREF|C_KCLK|0x0C


//口线并联电容选择,使能电容口
#define		C_KCAP0 		0x00 | 0x2
#define		C_KCAP1 		0x08 | 0x2
#define		C_KCAP2 		0x10 | 0x2
#define		C_KCAP3 		0x18 | 0x2
#define		C_KCAP4 		0x20 | 0x2
#define		C_KCAP5 		0x28 | 0x2
#define		C_KCAP6 		0x30 | 0x2
#define		C_KCAP7 		0x38 | 0x2



//内部比较器参考电压设定,在下列值中选取
//C_KVREF_04	=>	0.4VDD
//C_KVREF_05	=>	0.5VDD
//C_KVREF_06	=>	0.6VDD
//C_KVREF_07	=>	0.7VDD
#define		C_KVREF			C_KVREF_05

//转换时钟设定,在下列值中选取,建议选择4分频
//C_KCLK_SYS	=>	系统时钟
//C_KCLK_SYS2	=>	系统时钟的2分频
//C_KCLK_SYS4	=>	系统时钟的4分频
//C_KCLK_SYS8	=>	系统时钟的8分频
#define		C_KCLK			C_KCLK_SYS4


//检测通道设定,为C_KCHS0至C_KCHS15其中之一
//未设定的通道默认为C_KCHS0
const unsigned char Table_KeyChannel[] = {
	C_KCHS0,		//按键1对应触摸通道
	C_KCHS1,		//按键2对应触摸通道
	C_KCHS2,		//按键3对应触摸通道
	C_KCHS3,		//按键4对应触摸通道
	C_KCHS4,		//按键2对应触摸通道
	C_KCHS11,		//按键3对应触摸通道
	C_KCHS12		//按键4对应触摸通道
};

//内部并联电容选择,用来调整长短线,以最长的线为0,适当调大短线的值,范围:C_KCAP0至C_KCAP7
const unsigned char Table_KeyCap[] = {
	C_KCAP0,		//按键1内部并联电容
	C_KCAP0,		//按键2内部并联电容
	C_KCAP0,		//按键3内部并联电容
	C_KCAP0,		//按键4内部并联电容
	C_KCAP0,		//按键5内部并联电容
	C_KCAP0,		//按键11内部并联电容
	C_KCAP0			//按键12内部并联电容
};
//-----------------------------------------------------------------------------
//函数声明
void CheckTouchKey();

extern unsigned int  TKDATA0;			//按键旧值

unsigned char I2C_Read1bYTE(unsigned char ack);
unsigned char I2C_Write1bYTE(unsigned char data);
void I2C_WaitMoment();
void I2C_WriteStop();
void I2C_WriteStart();




///////////////////////////////////////////////////////////////////////////////////












void CheckTouchKey(void);		//触摸函数

#endif




