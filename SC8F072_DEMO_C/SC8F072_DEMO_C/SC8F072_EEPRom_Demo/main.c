/**********************************************************

**********************************************************/

#include <sc.h>



void Memory_Write(unsigned char Addr,unsigned int Value);
void Memory_Read(unsigned char Addr);

void Program_Read(unsigned int P_Addr);

volatile unsigned int t,read_data;
volatile unsigned char datanum, data;
volatile unsigned char read_rom_data;

const unsigned char tmp1 @ 0x700 = 0xaa;	//定义滚码地址
const unsigned char tmp2 @ 0x701 = 0xaa;
const unsigned char tmp3 @ 0x702 = 0xaa;
const unsigned char tmp4 @ 0x703 = 0xaa;

void main()
{
	asm("nop");
	asm("clrwdt");
	TRISA = 0;
	data = 0;

	/***************** EECON1 *******************************************8
		Bit7 EEPGD: 程序/程序EEPROM选择位； 1= 操作程序存储器； 0= 操作程序EEPROM。 
		Bit6~Bit4 未用。 
		Bit3 WRERR: EEPROM错误标志位； 
			1= 写操作过早终止（正常工作期间的任何WDT复位或欠压复位）； 
			0= 写操作完成。 
		Bit2 WREN: EEPROM写使能位； 
			1= 允许写周期； 
			0= 禁止写入存储器。 
		Bit1 WR: 写控制位； 
			1= 启动写周期（写操作一旦完成由硬件清零该位，用软件只能将WR位置1，但不能清零）
			0= 写周期完成。 
		Bit0 RD: 读控制位； 
			1= 启动存储器读操作（由硬件清零RD，用软件只能将RD位置1，但不能清零）； 
			0= 不启动存储器读操作。
	***************************************************************************/
	
	while(1)
	{
		asm("clrwdt");
		for(datanum=0;datanum<32;datanum++)
		{
			Memory_Write(datanum,0x55aa);			//调用EEDATA写函数
			Memory_Read(datanum);					//调用EEDATA读函数
			if(0x55aa == read_data)
			{
				data++;
			}
			
		}
		if(data == 32)
		{
			RA0 = 1;
			data = 0;
		}
		else RA0 = 0;
		
		for(datanum=0;datanum<4;datanum++)
		{
			unsigned int read_addr = 0x0700;
			read_addr = read_addr + datanum;		//赋值滚码所在地址
			Program_Read(read_addr);				//调用PROGRAM读函数
			if(0xaa == read_rom_data)
			{
				data++;
			}
			
		}
		if(data == 4)
		{
			RA1 = 1;
			data = 0;
		}
		else RA1 = 0;
		
	}
}


/***********************************************
函数名称：Memory_Write
函数功能：写数据/程序寄存器
入口参数：Addr - 写入地址
          Value - 写入数值
出口参数：无
备注：
************************************************/
void Memory_Write(unsigned char Addr,unsigned int Value)
{
											//将要写入的地址放入EEADDR寄存器
	EEADR = Addr;
	EEPGD = 0;								//访问数据存储器
											
	EEDAT = Value & 0x00ff;					//将要写入的数据给EEPROM的数据寄存器
	EEDATH = (Value & 0xff00)>>8;
	
	WREN = 1;								//允许写周期
	GIE = 0;								//关闭中断
	
	while(GIE) GIE = 0;						//确保中断已关闭
		
	EECON2 = 0x55;							//给EECON2写入0x55
	EECON2 = 0xaa;							//给EECON2写入0xaa
	WR = 1;									//启动写周期
	asm("nop");								//写EEDATA的时候，CPU 会停止工作，写完才执行这条语句
	asm("nop");
	WREN = 0;								//禁止写入
	GIE = 1;								//开启中断							
	
}


/***********************************************
函数名称：Memory_Read
函数功能：读数据/程序寄存器
入口参数：Addr - 读取地址
出口参数：返回读取地址相应数值
备注：
************************************************/
void Memory_Read(unsigned char Addr)
{
									//将要写入的地址放入EEADDR寄存器
	EEADR = Addr;
	EEPGD = 0;						//访问数据存储器
	
	RD = 1;							//允许读操作
	asm("nop");						//读取数据必须加两个nop
	asm("nop");
	
	read_data = EEDAT;
	read_data = read_data | (int)(EEDATH<<8);
	
}

/***********************************************
函数名称：Program_Read
函数功能：读数据/程序寄存器
入口参数：Addr - 读取地址
出口参数：返回读取地址相应数值
备注：
************************************************/
void Program_Read(unsigned int P_Addr)
{
									//将要写入的低位地址放入EEADR寄存器
	EEADR = P_Addr & 0x00ff;
	EEADRH = (P_Addr & 0xff00)>>8;	//将要写入的高位地址放入EEADRH寄存器
	
	EEPGD = 1;						//访问程序存储器
	
	RD = 1;							//允许读操作
	asm("nop");						//读取数据必须加两个nop
	asm("nop");
	
	read_rom_data = EEDAT;
	
}
