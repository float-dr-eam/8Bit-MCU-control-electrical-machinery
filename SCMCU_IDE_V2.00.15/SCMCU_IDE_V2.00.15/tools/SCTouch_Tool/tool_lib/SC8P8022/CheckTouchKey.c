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

unsigned int TKdata[16];

/**************************************************************************
* 函数名称：
* 函数功能：
* 入口参数：无
* 出口参数：无
* 备    注：
**************************************************************************/

unsigned int Key_Test()
{	
	#ifdef	C_KEY_1
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x50;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[0] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif
	
	#ifdef	C_KEY_2
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x51;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[1] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif
	
	#ifdef	C_KEY_3
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x52;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[2] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	

	#ifdef	C_KEY_4
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x53;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[3] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	
	
	#ifdef	C_KEY_5
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x54;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[4] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	
	
	#ifdef	C_KEY_6
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x55;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[5] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	
	
	#ifdef	C_KEY_7
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x56;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[6] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	
	
	#ifdef	C_KEY_8
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x57;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[7] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	
	
	#ifdef	C_KEY_9
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x58;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[8] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	
	
	#ifdef	C_KEY_10
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x59;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[9] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	

	#ifdef	C_KEY_11
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x5A;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[10] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	
	
	#ifdef	C_KEY_12
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x5B;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[11] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	
	
	#ifdef	C_KEY_13
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x5C;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[12] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	
	
	#ifdef	C_KEY_14
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x5D;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[13] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	
	
	#ifdef	C_KEY_15
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x5E;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[14] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
	KEYCON0 = 0x00;
	#endif	
	
	#ifdef	C_KEY_16
	KEYCON0 = 0x02;      //使能电容口，不并联电容
	KEYCON1 = 0x5F;		 //0.5VDD,FRES/2，通道1	
	KEYCON0 |= 0x01;	 //开始检测按键 .0位由0变为1开始检测
	while(!(KEYCON0&0x80));	//.7位为1检测完成
	TKdata[15] = ((KEYDATAH<<8) + KEYDATAL);				//获得键值
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
	
	#ifdef	C_KEY_5
	checksum += 1;
	#endif	
	
	#ifdef	C_KEY_6
	checksum += 1;
	#endif	
	
	#ifdef	C_KEY_7
	checksum += 1;
	#endif	
	
	#ifdef	C_KEY_8
	checksum += 1;
	#endif	
	
	#ifdef	C_KEY_9
	checksum += 1;
	#endif
	
	#ifdef	C_KEY_10
	checksum += 1;
	#endif	
	
	#ifdef	C_KEY_11
	checksum += 1;
	#endif	
	
	#ifdef	C_KEY_12
	checksum += 1;
	#endif	
	
	#ifdef	C_KEY_13
	checksum += 1;
	#endif	
	
	#ifdef	C_KEY_14
	checksum += 1;
	#endif	
	
	#ifdef	C_KEY_15
	checksum += 1;
	#endif	
	
	#ifdef	C_KEY_16
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
		
		#ifdef	C_KEY_5
		I2C_Write1bYTE(5);
		I2C_Write1bYTE(TKdata[4] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[4]>>8) & 0xff);	  		//键值数据高位
		checksum += 5;
		checksum += (TKdata[4] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[4]>>8) & 0xff);		
		#endif		
		
		#ifdef	C_KEY_6
		I2C_Write1bYTE(6);
		I2C_Write1bYTE(TKdata[5] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[5]>>8) & 0xff);	  		//键值数据高位
		checksum += 6;
		checksum += (TKdata[5] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[5]>>8) & 0xff);		
		#endif		
		
		#ifdef	C_KEY_7
		I2C_Write1bYTE(7);
		I2C_Write1bYTE(TKdata[6] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[6]>>8) & 0xff);	  		//键值数据高位
		checksum += 7;
		checksum += (TKdata[6] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[6]>>8) & 0xff);		
		#endif		
		
		#ifdef	C_KEY_8
		I2C_Write1bYTE(8);
		I2C_Write1bYTE(TKdata[7] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[7]>>8) & 0xff);	  		//键值数据高位
		checksum += 8;
		checksum += (TKdata[7] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[7]>>8) & 0xff);		
		#endif		
		
		#ifdef	C_KEY_9
		I2C_Write1bYTE(9);
		I2C_Write1bYTE(TKdata[8] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[8]>>8) & 0xff);	  		//键值数据高位
		checksum += 9;
		checksum += (TKdata[8] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[8]>>8) & 0xff);		
		#endif		
		
		#ifdef	C_KEY_10
		I2C_Write1bYTE(10);
		I2C_Write1bYTE(TKdata[9] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[9]>>8) & 0xff);	  		//键值数据高位
		checksum += 10;
		checksum += (TKdata[9] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[9]>>8) & 0xff);		
		#endif		
		
		#ifdef	C_KEY_11
		I2C_Write1bYTE(11);
		I2C_Write1bYTE(TKdata[10] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[10]>>8) & 0xff);	  		//键值数据高位
		checksum += 11;
		checksum += (TKdata[10] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[10]>>8) & 0xff);		
		#endif		
		
		#ifdef	C_KEY_12
		I2C_Write1bYTE(12);
		I2C_Write1bYTE(TKdata[11] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[11]>>8) & 0xff);	  		//键值数据高位
		checksum += 12;
		checksum += (TKdata[11] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[11]>>8) & 0xff);		
		#endif	
		
		#ifdef	C_KEY_13
		I2C_Write1bYTE(13);
		I2C_Write1bYTE(TKdata[12] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[12]>>8) & 0xff);	  		//键值数据高位
		checksum += 13;
		checksum += (TKdata[12] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[12]>>8) & 0xff);		
		#endif	
		
		#ifdef	C_KEY_14
		I2C_Write1bYTE(14);
		I2C_Write1bYTE(TKdata[13] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[13]>>8) & 0xff);	  		//键值数据高位
		checksum += 14;
		checksum += (TKdata[13] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[13]>>8) & 0xff);		
		#endif	
		
		#ifdef	C_KEY_15
		I2C_Write1bYTE(15);
		I2C_Write1bYTE(TKdata[14] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[14]>>8) & 0xff);	  		//键值数据高位
		checksum += 15;
		checksum += (TKdata[14] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[14]>>8) & 0xff);		
		#endif	
		
		#ifdef	C_KEY_16
		I2C_Write1bYTE(16);
		I2C_Write1bYTE(TKdata[15] & 0xff);        		//键值数据低位   
		I2C_Write1bYTE((TKdata[15]>>8) & 0xff);	  		//键值数据高位
		checksum += 16;
		checksum += (TKdata[15] & 0xff);					//检验和= 数据个数+键值数据的总和
		checksum += ((TKdata[15]>>8) & 0xff);		
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		

