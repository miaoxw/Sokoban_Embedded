
#include "config.h"
#include <stdlib.h>

#include <stdio.h> 

//=======================================
#include "app_cfg.h"
#include "Printf.h"
#include "ucos_ii.h"

#include "gui.h"
#include "math.h"
#include "GUI_Protected.h"
#include "GUIDEMO.H"
#include "WM.h"
#include "Dialog.h"
#include "LISTBOX.h"
#include "EDIT.h"
#include "SLIDER.h"
#include "FRAMEWIN.h"
#include "pic.h"

//=========================================
OS_STK  MainTaskStk[MainTaskStkLengh];

/*******************************************************************
*
*      Structure containing information for drawing routine
*
*******************************************************************
*/

typedef struct
{
	I16 *aY;
}PARAM;

/*******************************************************************
*
*                    Defines
*
********************************************************************
*/

#if LCD_BITSPERPIXEL == 1
  #define COLOR_GRAPH0 GUI_WHITE
  #define COLOR_GRAPH1 GUI_WHITE
#else
  #define COLOR_GRAPH0 GUI_GREEN
  #define COLOR_GRAPH1 GUI_YELLOW
#endif

//格子状态预置
#define GROUND 0x1
#define SPOT 0x2
#define WALL 0x4
#define BOX 0x8
#define CHARACTER 0x10
#define BOX_INPLACE (BOX|SPOT)
#define BOX_ONGROUND (BOX|GROUND)
#define CHARACTER_ON_SPOT (CHARACTER|SPOT)
#define CHARACTER_ON_GROUND (CHARACTER|GROUND)
#define OBSTCALE (WALL|BOX)

///////////////////////////////////////////////////////////////////
void soukoban(void *p_arg);
void drawBlockAt(int xPos,int yPos);
void win(void);
void (*stateTable[3][4])(void);

//原始地图，只实现最简单一关
const U8 originalMap[8][8]={
	{GROUND,GROUND,WALL,WALL,WALL,GROUND,GROUND,GROUND},
	{GROUND,GROUND,WALL,SPOT,WALL,GROUND,GROUND,GROUND},
	{GROUND,GROUND,WALL,GROUND,WALL,WALL,WALL,WALL},
	{WALL,WALL,WALL,BOX_ONGROUND,GROUND,BOX_ONGROUND,SPOT,WALL},
	{WALL,SPOT,GROUND,BOX_ONGROUND,CHARACTER_ON_GROUND,WALL,WALL,WALL},
	{WALL,WALL,WALL,WALL,BOX_ONGROUND,WALL,GROUND,GROUND},
	{GROUND,GROUND,GROUND,WALL,SPOT,WALL,GROUND,GROUND},
	{GROUND,GROUND,GROUND,WALL,WALL,WALL,GROUND,GROUND}
};

U8 currentMap[8][8];

//系统当前状态
int state;
//上一操作时间
int time;
//人物当前位置
int char_x,char_y;

void drawInitScreen()
{
	//设置状态
	state=0;
	
	GUI_SetBkColor(GUI_BLACK);
	GUI_SetColor(GUI_YELLOW);
	GUI_Clear();
	
	//画分割线
	GUI_DrawHLine(400,0,800);
	GUI_DrawLine(360,0,360,400);
	
	//写文字
	GUI_SetTextMode(GUI_TM_NORMAL);
	GUI_SetFont(&GUI_Font8x16x2x2);
	GUI_SetColor(GUI_WHITE);
	GUI_DispStringHCenterAt("Copyright(c) 2014 Miao Xiaowei",400,420);
	GUI_SetFont(&GUI_Font8x16);
	GUI_SetLBorder(368);
	GUI_DispStringAt("\r\nInstuction:\r\n\r\n\r\n1.Press any key to start.\r\n\r\n2.Use switches to move.\r\n\r\n3.If there's no operation in a long time, \r\n  the game will exit.\r\n\r\n\r\n\r\n********GOOD LUCK!********",368,8);
	GUI_SetFont(&GUI_Font32B_ASCII);
	GUI_DispStringHCenterAt("Sokoban",180,180);
}

void drawSingleBitmap(U8 state,int line,int coloum)
{
	int startX=60+30*coloum;
	int startY=60+30*line;
	const GUI_BITMAP *pic=NULL;
	switch(state)
	{
		case WALL:
			pic=&bmwall;
			break;
		case GROUND:
			pic=&bmground;
			break;
		case SPOT:
			pic=&bmspot;
			break;
		case BOX_ONGROUND:
			pic=&bmbox;
			break;
		case BOX_INPLACE:
			pic=&bmbox_inplace;
			break;
		case CHARACTER_ON_SPOT:
		case CHARACTER_ON_GROUND:
			pic=&bmcharacter;
			break;
	}
	GUI_DrawBitmap(pic,startX,startY);
}

void enterGame()
{
	int i,j;
	
	state=1;
	GUI_SetBkColor(GUI_BLACK);
	GUI_ClearRect(1,1,359,359);
	
	time=GUI_GetTime();
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
		{
			currentMap[i][j]=originalMap[i][j];
			//人物在这里
			if(currentMap[i][j]&CHARACTER)
			{
				char_x=i;
				char_y=j;
			}
			drawBlockAt(i,j);
		}
}

void drawBlockAt(int xPos,int yPos)
{
	drawSingleBitmap(currentMap[xPos][yPos],xPos,yPos);
}

BOOLEAN canPush(int xPos,int yPos,int xDirection,int yDirection)
{
	int newX=xPos+xDirection;
	int newY=yPos+yDirection;
	//地图外不能推
	if(newX>=0&&newX<=7&&newY>=0&&newY<=7)
	{
		//空地（没有障碍物）可以推
		if(!(currentMap[newX][newY]&OBSTCALE))
			return TRUE;
		//墙不能推
		if(currentMap[newX][newY]&WALL)
			return FALSE;
		//单个箱子可以推
		if(currentMap[newX][newY]&BOX)
		{
			//May be dangerous, but map can guarantee index won't overflow...
			if(!(currentMap[newX+xDirection][newY+yDirection]&OBSTCALE))
				return TRUE;
			else
				return FALSE;
		}
		return TRUE;
	}
	else
		return FALSE;
}

BOOLEAN finished()
{
	int i,j;
	for(i=0;i<8;i++)
		for(j=0;j<9;j++)
		{
			U8 currentBlock=currentMap[i][j];
			U8 result=(~(currentBlock^BOX_INPLACE))&BOX_INPLACE;
			//单独的箱子或是单独的箱子点
			if(result!=BOX_INPLACE&&result!=0)
				return FALSE;
		}
	return TRUE;
}

//要求已经确认向此方向推合法
void push(int xPos,int yPos,int xDirection,int yDirection)
{
	int newX=xPos+xDirection;
	int newY=yPos+yDirection;
	int newerX=newX+xDirection;
	int newerY=newY+yDirection;
	
	//前方有箱子，推出去的也只能是箱子
	if(currentMap[newX][newY]&BOX)
	{
		currentMap[newerX][newerY]|=BOX;
		currentMap[newX][newY]&=~BOX;
		currentMap[newX][newY]|=CHARACTER;
		currentMap[xPos][yPos]&=~CHARACTER;
		drawBlockAt(newerX,newerY);
		drawBlockAt(newX,newY);
		drawBlockAt(xPos,yPos);
	}
	else
	{
		currentMap[newX][newY]|=CHARACTER;
		currentMap[xPos][yPos]&=~CHARACTER;
		drawBlockAt(newX,newY);
		drawBlockAt(xPos,yPos);
	}
	//更新人物当前位置
	char_x+=xDirection;
	char_y+=yDirection;
}

void pushLeft()
{
	time=GUI_GetTime();
	if(canPush(char_x,char_y,-1,0))
		push(char_x,char_y,-1,0);
	if(finished())
		win();
}

void pushRight()
{
	time=GUI_GetTime();
	if(canPush(char_x,char_y,1,0))
		push(char_x,char_y,1,0);
	if(finished())
		win();
}

void pushUp()
{
	time=GUI_GetTime();
	if(canPush(char_x,char_y,0,1))
		push(char_x,char_y,0,1);
	if(finished())
		win();
}

void pushDown()
{
	time=GUI_GetTime();
	if(canPush(char_x,char_y,0,-1))
		push(char_x,char_y,0,-1);
	if(finished())
		win();
}

void win()
{
	state=2;
	GUI_SetTextMode(GUI_TM_TRANS);
	GUI_SetColor(GUI_BLUE);
	GUI_SetFont(&GUI_FontComic24B_ASCII);
	GUI_DispStringHCenterAt("Congratulations!",180,160);
	GUI_SetColor(GUI_YELLOW);
	GUI_SetFont(&GUI_FontComic18B_ASCII);
	GUI_DispStringHCenterAt("You finished the Game!",180,200);
	GUI_SetFont(&GUI_Font16B_ASCII);
	GUI_DispStringHCenterAt("Press any key to return",180,240);
}

//Get input
U8 Key_Scan( void )
{
	Delay( 80 ) ;
	rGPBDAT &=~(1<<6);
	rGPBDAT |=1<<7;

	if(      (rGPFDAT&(1<< 0)) == 0 )		return 1;
	else if( (rGPFDAT&(1<< 2)) == 0 )		return 3;
	else if( (rGPGDAT&(1<< 3)) == 0 )		return 5;
	else if( (rGPGDAT&(1<<11)) == 0 )		return 7;

	rGPBDAT &=~(1<<7);
	rGPBDAT |=1<<6;
	if(      (rGPFDAT&(1<< 0)) == 0 )		return 2;
	else if( (rGPFDAT&(1<< 2)) == 0 )		return 4;
	else if( (rGPGDAT&(1<< 3)) == 0 )		return 6;
	else if( (rGPGDAT&(1<<11)) == 0 )		return 8;
	else return 0xff;	
}

void Key_ISR()
{
	int key;
	key = Key_Scan();
	while(Key_Scan()==key)
		;
	if(state<=2)
	{
		if(key % 2 == 1 && key<=7)
			stateTable[state][(key-1)/2]();
		if(rEINTPEND & 1<<11)
			rEINTPEND |= 1<<11;
		if(rEINTPEND & 1<<19)
			rEINTPEND |= 1<<19;
	}
	//Clear Rs, SRCPND INTPND
	ClearPending(BIT_EINT8_23);
	ClearPending(BIT_EINT0);
	ClearPending(BIT_EINT2);
}

void KeyInit()
{
	MMU_Init();
	
	//Set GPGCON interrupt
	rGPGCON |= (1<<1 | 1<<7 | 1<<11 | 1<<13 );
	rEXTINT1 = 0;
	
	//Interrupt entrance
	pISR_EINT0 = pISR_EINT2 = pISR_EINT8_23 = (U32)Key_ISR;
	
	//Clear Rs
	rEINTPEND |= (1<<11 | 1<<19);
	ClearPending(BIT_EINT0 | BIT_EINT2 | BIT_EINT8_23);
	
	//
	rEINTMASK &= ~(1<<11 | 1<<19);
	
	EnableIrq(BIT_EINT0 | BIT_EINT2 | BIT_EINT8_23);
}

static void idle(void)
{
	int gct=GUI_GetTime();
	if(gct-time>10*OS_TICKS_PER_SEC)
		if(state==1)
			drawInitScreen();
}

int Main(void)
{	
	//函数指针表初始化，分别表示不同状态下按下不同按键调用的函数
	stateTable[0][0]=stateTable[0][1]=stateTable[0][2]=stateTable[0][3]=enterGame;
	stateTable[1][0]=pushDown;
	stateTable[1][1]=pushLeft;
	stateTable[1][2]=pushRight;
	stateTable[1][3]=pushUp;
	stateTable[2][0]=stateTable[2][1]=stateTable[2][2]=stateTable[2][3]=drawInitScreen;
	
	//初始化目标板
	TargetInit(); 
	
	//初始化uC/OS-II  
   	OSInit();	 
   	
   	//初始化系统时基
   	OSTimeSet(0);
   	
   	//创建系统初始任务
  	OSTaskCreate (soukoban,(void *)0, &MainTaskStk[MainTaskStkLengh - 1], MainTaskPrio);
  	
	OSStart();	
	return 0;
}

void soukoban(void *pdata)
{
#if OS_CRITICAL_METHOD == 3// Allocate storage for CPU status register 
	OS_CPU_SR  cpu_sr;
#endif

	OS_ENTER_CRITICAL();
		Timer0Init();//initial timer0 for ucos time tick
		ISRInit();   //initial interrupt prio or enable or disable
		KeyInit();
	OS_EXIT_CRITICAL();
	
	//print massage to Uart
	OSPrintfInit(); 
	OSStatInit();
	
	GUI_Init();   
  
	drawInitScreen();
	
	while(1)
	{  
		idle();
	}	
}
