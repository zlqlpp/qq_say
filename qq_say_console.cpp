// qqSays2021.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h>
#include <string> 
#include <atltime.h>
 

int main()
{

	boolean a = true;
	while (a) {
		Sleep(10);
		CTime t = CTime::GetCurrentTime(); 
		
		int y = t.GetYear(); //获取年份
		int m = t.GetMonth(); //获取当前月份
		int d = t.GetDay(); //获得几号
		int h = t.GetHour(); //获取当前为几时
		int mm = t.GetMinute(); //获取分钟
		int s = t.GetSecond(); //获取秒 
		int w = t.GetDayOfWeek(); //获取星期几，注意1为星期天，7为星期六
 
		std::string x;
		x = "截至"  ;
		x += std::to_string(y).c_str();
		x += "年";
		x += std::to_string(m).c_str();
		x += "月";
		x += std::to_string(d).c_str();
		x += "日";

		//x += std::to_string(h).c_str();
		//x += "点";
		//x += " 国际组各子系统运行正常";

		printf("%s===\n", x.c_str());

		boolean flag = false;
		if (2==h&&mm == 1 ) {
			x += "  0点-2点，国际组各子系统运行正常";
			flag = true;
		}
		if (4 == h && mm == 1) {
			x += "  2点-4点，国际组各子系统运行正常";
			flag = true;
		}
		if (6 == h && mm == 1) {
			x += "  4点-6点，国际组各子系统运行正常";
			flag = true;
		}
		if (8 == h && mm == 1) {
			x += "  6点-8点，国际组各子系统运行正常";
			flag = true;
		}
		 
		if (flag) {
			HWND game;  //游戏窗口句柄
			RECT  r1;
			POINT p;

			game = ::FindWindow(NULL, L"2021旺季-系统播报群"); //找到窗口句柄   
			::GetWindowRect(game, &r1);



			::GetCursorPos(&p);
			::SetCursorPos(69 + r1.left, 432 + r1.top);

			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(2);

			CString strFull(x.c_str());
			for (int i = 0; i < strFull.GetLength(); i++)
			{
				::PostMessage(game, WM_CHAR, strFull[i], 0);
			}

			::GetCursorPos(&p);
			::SetCursorPos(343 + r1.left, 473 + r1.top);


			::PostMessage(game, WM_KEYDOWN, VK_RETURN, 0);
			::PostMessage(game, WM_KEYUP, VK_RETURN, 0);


			Sleep(90000);

			flag = false;
		}
	}
 
}

 
