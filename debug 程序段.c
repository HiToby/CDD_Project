#if 0
	//*********************************************************   0x117模式下 PutPixel64K 以及 GetPixel64K 函数检测
	int x,y,i,j,k,r,g,b;

	Set_SVGAMode(0x117);

	//	PutPixel64K  &  rgbcolor64K
	for (x = 0; x < 1024; x++)
		for (y = 0; y < 768; y++)
		{
			PutPixel64K (x,y,rgbcolor64K(0x94,0x00,0xd3));
			// PutPixel256(x,y,10);
		// getch();
		}

	//	GetPixel64K
	//for (x = 200; x < 300; x++)
		// for (y = 500; y < 600; y++)
		// {
			// PutPixel64K (x,y,GetPixel64K(x - 200, y - 500));
		//	PutPixel256(x,y,10);
		// getch();
		// }

	getch(); //画出图形后需停留观察图形
	return 0;
#endif


#if 0
	//**************************************************************  VGAHI模式下图形绘制函数示例
	int x,y,i,j;
	int Cursor[16][10] = {
		{1,0,0,0,0,0,0,0,0,0},
		{1,1,0,0,0,0,0,0,0,0},
		{1,1,1,0,0,0,0,0,0,0},
		{1,1,1,1,0,0,0,0,0,0},
		{1,1,1,1,1,0,0,0,0,0},
		{1,1,1,1,1,1,0,0,0,0},
		{1,1,1,1,1,1,1,0,0,0},
		{1,1,1,1,1,1,1,1,0,0},
		{1,1,1,1,1,1,1,1,1,0},
		{1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,0,0,0,0,0},
		{1,1,1,0,1,0,0,0,0,0},
		{1,1,0,0,1,1,0,0,0,0},
		{1,0,0,0,0,1,1,0,0,0},
		{0,0,0,0,0,1,1,0,0,0},
		{0,0,0,0,0,0,1,0,0,0},
	};
	//Set_VGAmode();
	//Set_SVGAMode(0x102);
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setviewport(20,100,570,450,1);
	x = 500; y = 200;

	for (i = 0; i < 16; i++)
		for (j = 0; j < 10; j++)
		{
			if (Cursor[i][j]!=0)
				putpixel(x+1,y+1,WHITE);
		}

	setfillstyle(1,WHITE);
	bar(100,100,400,120);
	setcolor(BLUE);
	circle(250,50,30);
	circle(250,10,8);
	circle(220,15,5);
	circle(280,15,5);
	setfillstyle(1,BLUE);
	floodfill(250,50,BLUE);
	floodfill(250,10,BLUE);
	floodfill(220,15,BLUE);
	floodfill(280,15,BLUE);
	settextstyle(1,0,3);
	setcolor(RED);
	outtextxy(150,30,"SEARCHING ENGINE");
	setfillstyle(1,LIGHTGRAY);
	bar(420,100,460,120);
	setcolor(WHITE);
	line(419,99,461,99);
	line(419,99,419,121);
	setcolor(DARKGRAY);
	line(461,121,461,99);
	line(461,121,419,121);
	setcolor(RED);
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	outtextxy(423,102,"search");
	outtextxy(125,130,"help");
	outtextxy(225,130,"more");
	outtextxy(325,130,"about");
	setcolor(DARKGRAY);
	line(102,101,102,119);
	getch();
	closegraph();
	getchar();
	return 0;
#endif


#if 0
	//***************************************************************  鼠标检测
	_Mouse Old_Mouse, New_Mouse = {0,0,0,1};
	int i,j; // 循环变量

	Set_SVGAMode(0x117);

	//绘制背景
	for (i = 0; i < ModeInfo.XRes ; i++)
		for (j = 0; j < ModeInfo.YRes ; j++)
		{
			PutPixel64K (i,j,rgbcolor64K(0x94,0x00,0xd3));
		//	PutPixel256(x,y,10);
		// getch();
		}

	MouseReset();
	// MouseInit();
	// Set_MouseRange(0,0,ModeInfo.XRes - 1,ModeInfo.YRes - 1);
	Get_MouseBK(New_Mouse);
	Get_MouseStatus(&New_Mouse);
	Old_Mouse = New_Mouse;

	while (1){
		// Get_MouseStatus  &  If_MousePress 函数检测程序段，需关闭SVGA模式
		// Get_MouseStatus(&New_Mouse);
		// printf("Mouse.x = %d ; Mouse.y = %d ; Mouse.button = %d", New_Mouse.x,New_Mouse.y,New_Mouse.button);
		// delay(20);
		// system("cls");
		// if(If_MousePress(0,0,10,10,New_Mouse) == 1)
			// exit(1);
	
		//
		// Draw_Mouse 函数检测程序段
		// New_Mouse.x = 200;
		// New_Mouse.y = 200;
		// New_Mouse.shape = 1;
		// Draw_Mouse(New_Mouse);
		// Draw_MouseBK  &  Get_MouseBK函数检测程序段
		// for(New_Mouse.y = i = 50, j = 50; j <= 200; j++)
		// {
			// New_Mouse.x = j;
			// Draw_MouseBK(Old_Mouse);
			// Get_MouseBK(New_Mouse);
			// Draw_Mouse(New_Mouse);
			// delay(50);
		// }
		
		//综合检测程序段
		if(If_MousePress(0,0,50,50,New_Mouse) == 3)
			exit(1);
		Get_MouseStatus(&New_Mouse);
		if (New_Mouse.x == Old_Mouse.x && New_Mouse.y == Old_Mouse.y)
		{
			delay(100);
			Draw_MouseBK(Old_Mouse);
			// delay(500);
			Old_Mouse = New_Mouse;
			continue;
		}
		else if (New_Mouse.x >= 0 && New_Mouse.x <= 300)
		{
			New_Mouse.shape = 1;
			Draw_MouseBK(Old_Mouse);
			Get_MouseBK(New_Mouse);
			Draw_Mouse(New_Mouse);
			delay(30);
			Old_Mouse = New_Mouse;
			continue;
		}
		else if (New_Mouse.x >= 300 && New_Mouse.x <= 550)
		{
			New_Mouse.shape = 2;
			Draw_MouseBK(Old_Mouse);
			Get_MouseBK(New_Mouse);
			Draw_Mouse(New_Mouse);
			Old_Mouse = New_Mouse;
			delay(30);
			continue;
		}
		else if (New_Mouse.x >= 550 && New_Mouse.x < 1024)
		{
			New_Mouse.shape = 3;
			Draw_MouseBK(Old_Mouse);
			Get_MouseBK(New_Mouse);
			Draw_Mouse(New_Mouse);
			Old_Mouse = New_Mouse;
			delay(30);
			continue;
		}
	}
	return 0;
#endif


#if 0
	//*********************************************************   贴图相关函数检测
	//***********************************  普通贴图
	int i,j,old_i,old_j;
	unsigned long Pixel;
	FILE *fp;

	Set_SVGAMode(0x117);
	Draw_Bmp64K(-100,-100,"./logo256.bmp");
	getch();

	//***********************************  异或贴图
	/*for (i = old_i = 0; i < 1024; i++)
		for (j = old_j = 0; j < 768; j++)
			PutPixel64K(i,j,0xffff);
	for (i = old_i = 10; i < 15; i++)
		for (j = old_j = 10; j < 11; j++)
		{
			old_i = i;
			old_j = j;
			Draw_Bmp64K_Xor(i,j,"./1.bmp");
			delay(200);
			Draw_Bmp64K_Xor(old_i,old_j,"./1.bmp");
			//delay(100);
		}

	getch();*/

	retrurn 0;
	
#endif

#if 0
	//*********************************************************    画线画圆相关函数检测
	Set_SVGAMode(0x117);

	Draw_DotLine(0,0,100,100,0xffff);
	Draw_Line(100,100,200,200,0xffff);
	Draw_Circle(400,400,20,0xffff);

	getch();

#endif


#if 0
	//*********************************************************    键盘相关函数检测
	int x;
	system("cls");
	while(1)
	{
		if (!bioskey(1))
			x = bioskey(0);
		if (x == ESC)
		{
			system("cls");
			printf("GOOD BYE!!!!");
			delay(3000);
			exit(1);
		}else if (x == ENTER)
		{
			printf("\n");
		}else if (x == KEY_C && (bioskey(2) & 0x04))
		{
			system("cls");
			printf("HELLO!!!!");
			delay(3000);
		}else printf("%c",x);
	}

#endif

