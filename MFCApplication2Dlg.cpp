
// MFCApplication2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include <string>               //--------------------------------------------------
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 对话框



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication2Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 消息处理程序

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//--------------------------------------------------
HWND game;  //游戏窗口句柄
RECT  r1;
POINT p;
 
CWinThread* mythread = NULL;
void CMFCApplication2Dlg::OnBnClickedOk()
{
	
	if (NULL!= mythread) {
		MessageBox(L"已启动不用重复启动");
		return ;
	}
 
	//pThread = ::AfxBeginThread(say, NULL); //接下来做啥就直接调用pThead就行.

	mythread = AfxBeginThread(  //定义say的时候必须是static类型
		say,
		NULL,
		THREAD_PRIORITY_NORMAL,
		0,
		0,
		NULL
	);
	MessageBox(L"启动完成");

	// 输出 tm 结构的各个组成部分


	//x 168  782
	//  820 811
}

UINT       CMFCApplication2Dlg::say(LPVOID   pP) {
	//game = ::FindWindow(NULL, L"原子能"); //找到窗口句柄   新一代保障组
	game = ::FindWindow(NULL, L"新一代保障组"); //找到窗口句柄   
	::GetWindowRect(game, &r1);



	::GetCursorPos(&p);
	::SetCursorPos(69 + r1.left, 432 + r1.top);

	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(2);
	boolean a = true;
	while (a) {
		Sleep(10);
		CTime t = CTime::GetCurrentTime();
		int d = t.GetDay(); //获得几号

		int y = t.GetYear(); //获取年份

		int m = t.GetMonth(); //获取当前月份

		int h = t.GetHour(); //获取当前为几时

		int mm = t.GetMinute(); //获取分钟

		int s = t.GetSecond(); //获取秒

		int w = t.GetDayOfWeek(); //获取星期几，注意1为星期天，7为星期六

		std::string dd = std::to_string(d);

		std::string hh = std::to_string(h);
		std::string msg1 = "截至";
		dd.c_str();
		std::string msg2 = "日";
		hh.c_str();
		std::string msg3 = "点，新一代寄递平台国际组产品线 国际航空运输子系统、国际关务子系统 、国际数据监控子系统、国际交换站子系统、国际处理中心子系统 、国际预处理子系统 ，系统监控正常，运行情况正常。";

		std::string x;
		x += msg1;
		x += dd;
		x += msg2;
		x += hh;
		x += msg3;


		if (mm ==1) {
			//if (s == 0) {
					//a = false;
					//MessageBox(strFull);
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
		}
	}
	return 0;
}//--------------------------------------------------
