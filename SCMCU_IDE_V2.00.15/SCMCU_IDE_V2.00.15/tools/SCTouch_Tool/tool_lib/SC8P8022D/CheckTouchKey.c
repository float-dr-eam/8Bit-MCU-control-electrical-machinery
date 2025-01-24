/**************************************************************************
* SC8P8022系列MCU触摸按键检测库函数
* 文 件 名：CheckTouchKey.c
* 修改日期：2018/05/25
* 修改人员：luo
* 版 本 号：V1.0
**************************************************************************/
#include "CheckTouchKey.h"			//此包含放在最前面
//---------------------------------------------------
#include <sc.h>






#ifdef	ENABLE_IIC
unsigned char I2C_Read1bYTE(unsigned char ack);		//用于触摸仿真工具
unsigned char I2C_Write1bYTE(unsigned char data);
void I2C_WriteStop();
void I2C_WriteStart();
#endif

unsigned int TKdata[4];

/**************************************************************************
* 函数名称：
* 函数功能：
* 入口参数：无
* 出口参数：无
* 备    注：
**************************************************************************/

unsigned int Key_Test()
{	
	unsigned char	cnt=0;
	#ifdef	C_KEY_1
	KEYCON0 = 0;
	KEYCON1 = 0;
	KEYCON0 = Table_KeyCap[cnt];		//使能电容口，选择是否并联电容
	KEYCON1 = Table_KeyChannel[cnt];	//设置检测通道
	KEYCON0 |= 0x1;
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[0] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif
	
	cnt++;
	#ifdef	C_KEY_2
	KEYCON0 = 0;
	KEYCON1 = 0;
	KEYCON0 = Table_KeyCap[cnt];		//使能电容口，选择是否并联电容
	KEYCON1 = Table_KeyChannel[cnt];	//设置检测通道
	KEYCON0 |= 0x1;						//开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[1] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif
	
	cnt++;
	#ifdef	C_KEY_3
	KEYCON0 = 0;
	KEYCON1 = 0;
	KEYCON0 = Table_KeyCap[cnt];		//使能电容口，选择是否并联电容
	KEYCON1 = Table_KeyChannel[cnt];	//设置检测通道
	KEYCON0 |= 0x1;						 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[2] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif
		
	cnt++;
	#ifdef	C_KEY_4
	KEYCON0 = 0;
	KEYCON1 = 0;
	KEYCON0 = Table_KeyCap[cnt];		//使能电容口，选择是否并联电容
	KEYCON1 = Table_KeyChannel[cnt];	//设置检测通道
	KEYCON0 |= 0x1;						 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[3] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	
	
	

	return 0;
															
}

/**************************************************************************
* 函数名称：
* 函数功能：IIC送数据程序
* 入口参数：无
* 出口参数：
* 备    注：
**************************************************************************/
void CheckTouchKey_F()
{
	#ifdef	ENABLE_IIC
		unsigned char checksum = 0;
	#endif	
	
	asm("clrwdt");
	
	#ifdef	C_KEY_1
	checksum += 1;
	#endif
	
	#ifdef	C_KEY_2
	checksum += 1;
	#endif	
	
	#ifdef	C_KEY_3
	checksum += 1;
	#endif	
	
	#ifdef	C_KEY_4
	checksum += 1;
	#endif	
	
									
	if (checksum)		//如果定义了按键
	{
		
		Key_Test();		//检测按键值
		
		
		checksum *= 3;		//在此之前的checksum表示按键个数
		checksum += 2;		//在此之后的checksum表示校验和
		//-----------------与软件通讯规则为   0xA0+数据个数+数据+检验和------------------
		I2C_WriteStart();
		I2C_Write1bYTE(0xa0);							//建立连接的命令
		I2C_Write1bYTE(checksum);						//数据个数为  X*2+2  X表示按键个数
		
		#ifdef	C_KEY_1
		I2C_Write1bYTE(1);
		I2C_Write1bYTE(TKdata[0] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[0]>>8) & 0xff);	  		//键值数据高位
		checksum += 1;
		checksum += (TKdata[0] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[0]>>8) & 0xff);		
		#endif
		
		#ifdef	C_KEY_2
		I2C_Write1bYTE(2);
		I2C_Write1bYTE(TKdata[1] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[1]>>8) & 0xff);	  		//键值数据高位
		checksum += 2;
		checksum += (TKdata[1] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[1]>>8) & 0xff);		
		#endif		
		
		#ifdef	C_KEY_3
		I2C_Write1bYTE(3);
		I2C_Write1bYTE(TKdata[2] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[2]>>8) & 0xff);	  		//键值数据高位
		checksum += 3;
		checksum += (TKdata[2] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[2]>>8) & 0xff);		
		#endif		
		
		#ifdef	C_KEY_4
		I2C_Write1bYTE(4);
		I2C_Write1bYTE(TKdata[3] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[3]>>8) & 0xff);	  		//键值数据高位
		checksum += 4;
		checksum += (TKdata[3] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[3]>>8) & 0xff);		
		#endif		
		
			
		I2C_Write1bYTE(checksum);						//发校验和
		I2C_WriteStop();								//结束					
	}	
	
}	

/**************************************************************************
对外输出函数
**************************************************************************/	
void CheckTouchKey()
{
	CheckTouchKey_F();
}
	
	
	
	
	
	
	
/*********************************************************************	
 IIC函数
	
*********************************************************************/


//起始信号-在SCL为高电平时，SDA线上发生从高到低的电平变化
void I2C_WriteStart()
{
	I2C_SDA_IO = 0;
	I2C_SCL_IO = 0;
	I2C_WaitMoment();
	
	I2C_SDA = 1;			//先将SDA=1，以准备在SCL=1时，将SDA=0
	I2C_SCL = 1;			//时钟总线拉高
	I2C_WaitMoment();
	I2C_SDA = 0;			//SCL=1时，将SDA拉低即产生启动信号
	
	I2C_WaitMoment();
	I2C_SCL = 0;			//将SCL=0，完成启动信号操作
	I2C_WaitMoment();
}

//结束信号-在SCL为高电平时，SDA线上发生从低到高的电平变化
void I2C_WriteStop()
{
	I2C_SDA_IO = 0;
	I2C_SCL_IO = 0;
	I2C_WaitMoment();
	
	I2C_SDA = 0;			//先将SDA=0，以准备在SCL=1时，将SDA=1
	I2C_SCL = 1;			//时钟总线拉高
	I2C_WaitMoment();
	I2C_SDA = 1;			//SCL=1时，将SDA拉高即产生停止信号
	
	I2C_WaitMoment();
	I2C_SCL = 0;			//将SCL=0，完成启动信号操作
	I2C_WaitMoment();
}

/***********************************************************
函数功能：模拟IIC主机发送8位数据
入口参数：data-待发送数据
函数返回：返回ack应答信号
备    注：IIC协议ack应答信号为低有效
***********************************************************/
unsigned char I2C_Write1bYTE(unsigned char data)
{
	unsigned char i = 8;
	I2C_SDA_IO = 0;
	I2C_SCL_IO = 0;
	do
	{
		I2C_SCL = 0;
		if(data&0x80)
			I2C_SDA = 1;
		else
			I2C_SDA = 0;
		
		I2C_SCL = 1;		//时钟线做一个上升沿，将一位数据写入
		data <<= 1;
	}
	while(--i);
	I2C_SCL = 0;
	
	I2C_SDA_IO = 1;			//置为输入口接收应答信号

	I2C_WaitMoment();
	I2C_SCL = 1;			//做个上升沿准备读应答信号
	I2C_WaitMoment();
	
	i = I2C_SDA;
	I2C_SCL = 0;
	I2C_SDA_IO = 0;
	return i;
}

/***********************************************************
函数功能：模拟IIC主机接收8位数据
入口参数：ack-应答信号
函数返回：接收到的数据
备    注：IIC协议ack应答信号为低有效
***********************************************************/
unsigned char I2C_Read1bYTE(unsigned char ack)
{
	unsigned char i,data;
	I2C_SDA_IO = 1;
	I2C_SCL_IO = 1;
	I2C_WaitMoment();
	
	while(!I2C_SCL);				//等待从机准备好数据释放时钟
	I2C_SCL_IO = 0;
	I2C_SCL = 0;
	I2C_WaitMoment();
	
	data <<= 1;
	if(I2C_SDA) data |= 0x1;
	
	
	for(i = 0; i < 7; i++)
	{
		I2C_SCL = 1;
		data <<= 1;
		if(I2C_SDA) data |= 0x1;
		I2C_SCL = 0;
	}
	
	I2C_SDA_IO = 0;
	
	if(ack)I2C_SDA = 1;			//是否需要更多的数据
	else I2C_SDA = 0;
	
	I2C_WaitMoment();
	I2C_SCL = 1;
	I2C_WaitMoment();
	I2C_SCL = 0;
	return data;
}

void I2C_WaitMoment()
{
	asm("nop");
	asm("nop");
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		

