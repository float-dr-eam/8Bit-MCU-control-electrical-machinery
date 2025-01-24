/**********************************************************

**********************************************************/

#include <sc.h>



void Memory_Write(unsigned char Addr,unsigned int Value);
void Memory_Read(unsigned char Addr);

void Program_Read(unsigned int P_Addr);

volatile unsigned int t,read_data;
volatile unsigned char datanum, data;
volatile unsigned char read_rom_data;

const unsigned char tmp1 @ 0x700 = 0xaa;	//��������ַ
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
		Bit7 EEPGD: ����/����EEPROMѡ��λ�� 1= ��������洢���� 0= ��������EEPROM�� 
		Bit6~Bit4 δ�á� 
		Bit3 WRERR: EEPROM�����־λ�� 
			1= д����������ֹ�����������ڼ���κ�WDT��λ��Ƿѹ��λ���� 
			0= д������ɡ� 
		Bit2 WREN: EEPROMдʹ��λ�� 
			1= ����д���ڣ� 
			0= ��ֹд��洢���� 
		Bit1 WR: д����λ�� 
			1= ����д���ڣ�д����һ�������Ӳ�������λ�������ֻ�ܽ�WRλ��1�����������㣩
			0= д������ɡ� 
		Bit0 RD: ������λ�� 
			1= �����洢������������Ӳ������RD�������ֻ�ܽ�RDλ��1�����������㣩�� 
			0= �������洢����������
	***************************************************************************/
	
	while(1)
	{
		asm("clrwdt");
		for(datanum=0;datanum<32;datanum++)
		{
			Memory_Write(datanum,0x55aa);			//����EEDATAд����
			Memory_Read(datanum);					//����EEDATA������
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
			read_addr = read_addr + datanum;		//��ֵ�������ڵ�ַ
			Program_Read(read_addr);				//����PROGRAM������
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
�������ƣ�Memory_Write
�������ܣ�д����/����Ĵ���
��ڲ�����Addr - д���ַ
          Value - д����ֵ
���ڲ�������
��ע��
************************************************/
void Memory_Write(unsigned char Addr,unsigned int Value)
{
											//��Ҫд��ĵ�ַ����EEADDR�Ĵ���
	EEADR = Addr;
	EEPGD = 0;								//�������ݴ洢��
											
	EEDAT = Value & 0x00ff;					//��Ҫд������ݸ�EEPROM�����ݼĴ���
	EEDATH = (Value & 0xff00)>>8;
	
	WREN = 1;								//����д����
	GIE = 0;								//�ر��ж�
	
	while(GIE) GIE = 0;						//ȷ���ж��ѹر�
		
	EECON2 = 0x55;							//��EECON2д��0x55
	EECON2 = 0xaa;							//��EECON2д��0xaa
	WR = 1;									//����д����
	asm("nop");								//дEEDATA��ʱ��CPU ��ֹͣ������д���ִ���������
	asm("nop");
	WREN = 0;								//��ֹд��
	GIE = 1;								//�����ж�							
	
}


/***********************************************
�������ƣ�Memory_Read
�������ܣ�������/����Ĵ���
��ڲ�����Addr - ��ȡ��ַ
���ڲ��������ض�ȡ��ַ��Ӧ��ֵ
��ע��
************************************************/
void Memory_Read(unsigned char Addr)
{
									//��Ҫд��ĵ�ַ����EEADDR�Ĵ���
	EEADR = Addr;
	EEPGD = 0;						//�������ݴ洢��
	
	RD = 1;							//���������
	asm("nop");						//��ȡ���ݱ��������nop
	asm("nop");
	
	read_data = EEDAT;
	read_data = read_data | (int)(EEDATH<<8);
	
}

/***********************************************
�������ƣ�Program_Read
�������ܣ�������/����Ĵ���
��ڲ�����Addr - ��ȡ��ַ
���ڲ��������ض�ȡ��ַ��Ӧ��ֵ
��ע��
************************************************/
void Program_Read(unsigned int P_Addr)
{
									//��Ҫд��ĵ�λ��ַ����EEADR�Ĵ���
	EEADR = P_Addr & 0x00ff;
	EEADRH = (P_Addr & 0xff00)>>8;	//��Ҫд��ĸ�λ��ַ����EEADRH�Ĵ���
	
	EEPGD = 1;						//���ʳ���洢��
	
	RD = 1;							//���������
	asm("nop");						//��ȡ���ݱ��������nop
	asm("nop");
	
	read_rom_data = EEDAT;
	
}
