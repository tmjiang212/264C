#include <stdio.h>
#include <unistd.h>
#include "libaxio.h"


int main()
{
	unsigned int device;
	unsigned int hi_low;

	int i;
	device=0;
	//0x0f pin3,5,7,9 is di      pin 11,13,15,17 is do
	AXBoardSetIndexValue(EAPI_AX_HWMON_MAIN_DIO_DIR,device,0x0F);
	
	device=1;
	//0xf0 pin19,21,23,25 is do       pin 27,29,31,33 is di
	AXBoardSetIndexValue(EAPI_AX_HWMON_MAIN_DIO_DIR,device,0xF0);
	
	device=2;
	//0xf0 pin4,6,8,10 is do     pin 12,14,16,18 is di
	AXBoardSetIndexValue(EAPI_AX_HWMON_MAIN_DIO_DIR,device,0xF0);
	
	device=3;
	//0xf0 pin20,22,24,26     is do  pin 28,30,32,34 is di
	AXBoardSetIndexValue(EAPI_AX_HWMON_MAIN_DIO_DIR,device,0xF0);
	
	usleep(100000);
	for (i=0;i<4;i++)
	{
		device=i;
		AXBoardGetIndexValue(EAPI_AX_HWMON_MAIN_DIO_DIR,device,&hi_low);
		printf("get device[%d],dio mode[%02x]\n",device,hi_low);
		
	}
	/*                             
	pin define as below

	pin3:dio0             pin4:dio16
	pin5:dio1             pin6:dio17
	pin7:dio2             pin8:dio18
	pin9:dio3             pin10:dio19
	pin11:dio4            pin12:dio20
	pin13:dio5            pin14:dio21
	pin15:dio6            pin16:dio22
	pin17:dio7            pin18:dio23
	pin19:dio8            pin20:dio24
	pin21:dio9            pin22:dio25
	pin23:dio10           pin24:dio26
	pin25:dio11           pin26:dio27
	pin27:dio12           pin28:dio28
	pin29:dio13           pin30:dio29
	pin31:dio14           pin32:dio30
	pin33:dio15           pin34:dio31
	*/
        //device 0
	//set pin 3,5,7,9 is low

	for (i=4;i<8;i++)
		AXBoardSetValue(EAPI_AX_HWMON_DO0+i,0);
	//set dio mode 0x55  0101010101
	
	
	
	for(i=0;i<4;i++)
	{
		//get pin 11,13,15,17 (DO mode)
		EApiBoardGetValue(EAPI_AX_HWMON_DO4+i,&hi_low);
		printf("do%d,[%d]\n",4+i,hi_low);
	}
	//return 1;
	for (i=0;i<4;i++)
	{
		//get pin 3,5,7,9 (DI mode)
		EApiBoardGetValue(EAPI_AX_HWMON_DI0+i,&hi_low);	
		printf("di%d,[%d]\n",i,hi_low);
	}
printf("-----------------------------------------------------------------\n");
	//set pin 19,21,23,25 is low (do mode)
	for (i=0;i<4;i++)
                AXBoardSetValue(EAPI_AX_HWMON_DO8+i,0);
	//return 1;
	for(i=0;i<4;i++)
        {
                //get  pin 19,21,23,25 (do mode)
                EApiBoardGetValue(EAPI_AX_HWMON_DO8+i,&hi_low);
                printf("do%d,[%d]\n",8+i,hi_low);
        }
	for (i=0;i<4;i++)
        {
                //get pin 27,29,31,33 (di mode)
                EApiBoardGetValue(EAPI_AX_HWMON_DI12+i,&hi_low);
                printf("di%d,[%d]\n",12+i,hi_low);
        }
printf("-----------------------------------------------------------------\n");
	 //set pin 4,6,8,10 is low
        for (i=0;i<4;i++)
                AXBoardSetValue(EAPI_AX_HWMON_DO16+i,0);
        for(i=0;i<4;i++)
        {
                //get  pin 4,6,8,10
                EApiBoardGetValue(EAPI_AX_HWMON_DO16+i,&hi_low);
                printf("do%d,[%d]\n",16+i,hi_low);
        }
        for (i=0;i<4;i++)
        {
                //get pin 12,14,16,18
                EApiBoardGetValue(EAPI_AX_HWMON_DI20+i,&hi_low);
                printf("di%d,[%d]\n",20+i,hi_low);
        }
printf("-----------------------------------------------------------------\n");
	for (i=0;i<4;i++)
                AXBoardSetValue(EAPI_AX_HWMON_DO24+i,0);
        //return 1;
        for(i=0;i<4;i++)
        {
                //get  pin 4,6,8,10
                EApiBoardGetValue(EAPI_AX_HWMON_DO24+i,&hi_low);
                printf("do%d,[%d]\n",24+i,hi_low);
        }
        for (i=0;i<4;i++)
        {
                //get pin 12,14,16,18
                EApiBoardGetValue(EAPI_AX_HWMON_DI28+i,&hi_low);
                printf("di%d,[%d]\n",28+i,hi_low);
        }
	return 0;
}

