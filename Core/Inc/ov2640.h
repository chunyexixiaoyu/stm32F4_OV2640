//Ӱ����(ZGT)
#ifndef _OV2640_H_
#define _OV2640_H_
#include "main.h"
//�Զ��庯��
/*-------------SCCB-----------------*/
void SCCB_Start(void);
void SCCB_Stop(void);
void SCCB_No_Ack(void);
unsigned char SCCB_WR_Byte(unsigned char dat);
unsigned char SCCB_RD_Byte(void);
unsigned char SCCB_WR_Reg(unsigned char reg,unsigned char data);
unsigned char SCCB_RD_Reg(unsigned char reg);
void SCCB_Init(void);
/*-------------OV2640-----------------*/
uint8_t OV2640_Init(void);//��ʼ��OV2640��Ĭ�ϳ�ʼ�������1600*1200ͼƬ
void OV2640_JPEG_Mode(void);//OV2640�л�JPEGģʽ
void OV2640_RGB565_Mode(void);//OV2640�л�REB565ģʽ
void OV2640_Auto_Exposure(unsigned char level);//OV2640�Զ��ع�ȼ�����0~4
void OV2640_Light_Mode(unsigned char mode);//��ƽ������0~4
void OV2640_Color_Saturation(unsigned char sat);//ɫ������0~4
void OV2640_Brightness(unsigned char bright);//��������0~4
void OV2640_Contrast(unsigned char contrast);//�Աȶ�����0~4
void OV2640_Special_Effects(unsigned char eft);//��Ч����0~6
void OV2640_Color_Bar(unsigned char sw);//�������ԣ�1������0�ر�
void OV2640_Window_Set(unsigned int sx,unsigned int sy,unsigned int width,unsigned int height);
unsigned char OV2640_OutSize_Set(uint16_t width,uint16_t height);
unsigned char OV2640_ImageWin_Set(unsigned int offx,unsigned int offy,unsigned int width,unsigned int height);
unsigned char OV2640_ImageSize_Set(unsigned int width,unsigned int height);

//OV2640���豸ID
#define SCCB_ID   			0X60  			//OV2640��ID

//����OV2640��PWDN��RESET��PG9��PG15����ز���
#define OV2640_PWDN_1 HAL_GPIO_WritePin(OV2640_PWDN_GPIO_Port,OV2640_PWDN_Pin,GPIO_PIN_SET)//PWDN=1
#define OV2640_PWDN_0 HAL_GPIO_WritePin(OV2640_PWDN_GPIO_Port,OV2640_PWDN_Pin,GPIO_PIN_RESET)//PWDN=0

#define OV2640_RST_1 HAL_GPIO_WritePin(OV2640_RESET_GPIO_Port,OV2640_RESET_Pin,GPIO_PIN_SET)//RESET=1
#define OV2640_RST_0 HAL_GPIO_WritePin(OV2640_RESET_GPIO_Port,OV2640_RESET_Pin,GPIO_PIN_RESET)//RESET=0

//����SDA��SCL��������PD7��PD6����ز���
#define SCCB_SDA_IN()  {GPIOD->MODER&=~(3<<(7*2));GPIOD->MODER|=0<<7*2;}	//PD7 ����
#define SCCB_SDA_OUT() {GPIOD->MODER&=~(3<<(7*2));GPIOD->MODER|=1<<7*2;} 	//PD7 ���

#define SCCB_SCL_1  HAL_GPIO_WritePin(DCMI_SCL_GPIO_Port,DCMI_SCL_Pin,GPIO_PIN_SET)
#define SCCB_SCL_0  HAL_GPIO_WritePin(DCMI_SCL_GPIO_Port,DCMI_SCL_Pin,GPIO_PIN_RESET)//SCL

#define SCCB_SDA_1  HAL_GPIO_WritePin(DCMI_SDA_GPIO_Port,DCMI_SDA_Pin,GPIO_PIN_SET)
#define SCCB_SDA_0  HAL_GPIO_WritePin(DCMI_SDA_GPIO_Port,DCMI_SDA_Pin,GPIO_PIN_RESET)//SDA	

#define SCCB_SDA_READ()  HAL_GPIO_ReadPin(DCMI_SDA_GPIO_Port,DCMI_SDA_Pin)//����SDA    

//ov2640
#define OV2640_MID				0X7FA2
#define OV2640_PID				0X2642
//��ѡ��DSP��ַ(0XFF=0X00)ʱ,OV2640��DSP�Ĵ�����ַӳ���
#define OV2640_DSP_R_BYPASS     0x05
#define OV2640_DSP_Qs           0x44
#define OV2640_DSP_CTRL         0x50
#define OV2640_DSP_HSIZE1       0x51
#define OV2640_DSP_VSIZE1       0x52
#define OV2640_DSP_XOFFL        0x53
#define OV2640_DSP_YOFFL        0x54
#define OV2640_DSP_VHYX         0x55
#define OV2640_DSP_DPRP         0x56
#define OV2640_DSP_TEST         0x57
#define OV2640_DSP_ZMOW         0x5A
#define OV2640_DSP_ZMOH         0x5B
#define OV2640_DSP_ZMHH         0x5C
#define OV2640_DSP_BPADDR       0x7C
#define OV2640_DSP_BPDATA       0x7D
#define OV2640_DSP_CTRL2        0x86
#define OV2640_DSP_CTRL3        0x87
#define OV2640_DSP_SIZEL        0x8C
#define OV2640_DSP_HSIZE2       0xC0
#define OV2640_DSP_VSIZE2       0xC1
#define OV2640_DSP_CTRL0        0xC2
#define OV2640_DSP_CTRL1        0xC3
#define OV2640_DSP_R_DVP_SP     0xD3
#define OV2640_DSP_IMAGE_MODE   0xDA
#define OV2640_DSP_RESET        0xE0
#define OV2640_DSP_MS_SP        0xF0
#define OV2640_DSP_SS_ID        0x7F
#define OV2640_DSP_SS_CTRL      0xF8
#define OV2640_DSP_MC_BIST      0xF9
#define OV2640_DSP_MC_AL        0xFA
#define OV2640_DSP_MC_AH        0xFB
#define OV2640_DSP_MC_D         0xFC
#define OV2640_DSP_P_STATUS     0xFE
#define OV2640_DSP_RA_DLMT      0xFF 

//��ѡ�񴫸�����ַ(0XFF=0X01)ʱ,OV2640��DSP�Ĵ�����ַӳ���
#define OV2640_SENSOR_GAIN       0x00
#define OV2640_SENSOR_COM1       0x03
#define OV2640_SENSOR_REG04      0x04
#define OV2640_SENSOR_REG08      0x08
#define OV2640_SENSOR_COM2       0x09
#define OV2640_SENSOR_PIDH       0x0A
#define OV2640_SENSOR_PIDL       0x0B
#define OV2640_SENSOR_COM3       0x0C
#define OV2640_SENSOR_COM4       0x0D
#define OV2640_SENSOR_AEC        0x10
#define OV2640_SENSOR_CLKRC      0x11
#define OV2640_SENSOR_COM7       0x12
#define OV2640_SENSOR_COM8       0x13
#define OV2640_SENSOR_COM9       0x14
#define OV2640_SENSOR_COM10      0x15
#define OV2640_SENSOR_HREFST     0x17
#define OV2640_SENSOR_HREFEND    0x18
#define OV2640_SENSOR_VSTART     0x19
#define OV2640_SENSOR_VEND       0x1A
#define OV2640_SENSOR_MIDH       0x1C
#define OV2640_SENSOR_MIDL       0x1D
#define OV2640_SENSOR_AEW        0x24
#define OV2640_SENSOR_AEB        0x25
#define OV2640_SENSOR_W          0x26
#define OV2640_SENSOR_REG2A      0x2A
#define OV2640_SENSOR_FRARL      0x2B
#define OV2640_SENSOR_ADDVSL     0x2D
#define OV2640_SENSOR_ADDVHS     0x2E
#define OV2640_SENSOR_YAVG       0x2F
#define OV2640_SENSOR_REG32      0x32
#define OV2640_SENSOR_ARCOM2     0x34
#define OV2640_SENSOR_REG45      0x45
#define OV2640_SENSOR_FLL        0x46
#define OV2640_SENSOR_FLH        0x47
#define OV2640_SENSOR_COM19      0x48
#define OV2640_SENSOR_ZOOMS      0x49
#define OV2640_SENSOR_COM22      0x4B
#define OV2640_SENSOR_COM25      0x4E
#define OV2640_SENSOR_BD50       0x4F
#define OV2640_SENSOR_BD60       0x50
#define OV2640_SENSOR_REG5D      0x5D
#define OV2640_SENSOR_REG5E      0x5E
#define OV2640_SENSOR_REG5F      0x5F
#define OV2640_SENSOR_REG60      0x60
#define OV2640_SENSOR_HISTO_LOW  0x61
#define OV2640_SENSOR_HISTO_HIGH 0x62

#endif