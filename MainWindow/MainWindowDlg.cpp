
// MainWindowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MainWindow.h"
#include "MainWindowDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMainWindowDlg dialog



CMainWindowDlg::CMainWindowDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAINWINDOW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	mpoImageTab = new ImageTab;
	mpoRecognizeTab = new RecognizeTab;


}

CMainWindowDlg::~CMainWindowDlg()
{
	delete mpoImageTab;
	delete mpoRecognizeTab;
}

void CMainWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_CTRL, moImageTabCtrl);
	DDX_Control(pDX, IDC_BRIGHTNESS_SLIDER, moBrightnessSlider);
	DDX_Control(pDX, IDC_CONTRAST_SLIDER, moContrastSlider);
	DDX_Control(pDX, IDC_BRIGHTNESS_EDIT, moBrightnessEdit);
	DDX_Control(pDX, IDC_CONTRAST_EDIT, moContrastEdit);
	DDX_Control(pDX, IDC_FRAME_SIZE_COMBO, moFrameSizeCombo);
	DDX_Control(pDX, IDC_ACURRANCY_COMBO, moAccuracyCombo);
	DDX_Control(pDX, IDC_TRESHOLD_TYPE_COMBO2, moThresholdTypeCombo);
	DDX_Control(pDX, ID_RECOGNIZE_IMAGE, moStartRecognizeBtn);
	DDX_Control(pDX, ID_SAVE_IMAGE_BTN, moSaveDrawingBtn);
	DDX_Control(pDX, IDC_FILE_NAME_LABEL, moFileNameLabel);
	DDX_Control(pDX, IDC_STATIC_FILE_NAME, moFileNameStatic);
	DDX_Control(pDX, IDC_SIZE_LABEL, moFileSizeLabel);
	DDX_Control(pDX, IDC_STATIC_FILE_SIZE, moFileSizeStatic);
	DDX_Control(pDX, IDC_STATIC_DIMESIONS, moFileDimensionsStatic);
	DDX_Control(pDX, IDC_DIMENSIONS_LABEL, moFileDimensionsLabel);
	DDX_Control(pDX, IDC_PROGRESS_RECOGNIZE, moProgressBar);
}

BEGIN_MESSAGE_MAP(CMainWindowDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_HELP_ABOUTPROGRAM, &CMainWindowDlg::OnHelpAboutprogram)
	ON_COMMAND(ID_EXIT, &CMainWindowDlg::OnExit)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_CTRL, &CMainWindowDlg::OnTcnSelchangeTabCtrl)
	ON_NOTIFY(TCN_SELCHANGING, IDC_TAB_CTRL, &CMainWindowDlg::OnTcnSelchangingTabCtrl)
	ON_COMMAND(ID_FILE_OPEN, &CMainWindowDlg::OnFileOpen)
END_MESSAGE_MAP()


// CMainWindowDlg message handlers

BOOL CMainWindowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	mvInitializeImageTabCtr(mpoImageTab, _T("Image Tab"), mpoImageTab->IDD);
	mvInitializeImageTabCtr(mpoRecognizeTab, _T("Recognize Tab"), mpoRecognizeTab->IDD);

	moBrightnessSlider.SetRange(-100, 100, TRUE);
	moBrightnessSlider.SetPos(0);

	moContrastSlider.SetRange(-100, 100, TRUE);
	moContrastSlider.SetPos(0);

	moBrightnessEdit.SetWindowTextW(_T("0"));
	moContrastEdit.SetWindowTextW(_T("0"));
	
	moProgressBar.ShowWindow(SW_HIDE);

	mvChangeComponentState(ComponentState::Unlock);
	mvChangeVisibleFileInfo(SW_HIDE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMainWindowDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMainWindowDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMainWindowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

const CString CMainWindowDlg::getDefaultFileName() const
{
	return defaultFileName;
}

void CMainWindowDlg::mvChangeComponentState(ComponentState newStete)
{
	//moImageTabCtrl.EnableWindow(newStete);
	
	moBrightnessSlider.EnableWindow(newStete);
	moContrastSlider.EnableWindow(newStete);
	
	moBrightnessEdit.EnableWindow(newStete);
	moContrastEdit.EnableWindow(newStete);
	
	moAccuracyCombo.EnableWindow(newStete);
	moThresholdTypeCombo.EnableWindow(newStete);
	moFrameSizeCombo.EnableWindow(newStete);

	moSaveDrawingBtn.EnableWindow(newStete);
	moStartRecognizeBtn.EnableWindow(newStete);
}

void CMainWindowDlg::mvChangeVisibleFileInfo(int visibleState)
{
	moFileNameLabel.ShowWindow(visibleState);
	moFileNameStatic.ShowWindow(visibleState);
	moFileSizeLabel.ShowWindow(visibleState);
	moFileSizeStatic.ShowWindow(visibleState);
	moFileDimensionsStatic.ShowWindow(visibleState);
	moFileDimensionsLabel.ShowWindow(visibleState);
}

void CMainWindowDlg::mvInitializeImageTabCtr(CDialog * dlgPage, CString tabName, int dialogResurce)
{
	TC_ITEM tabItem;
	tabItem.mask = TCIF_TEXT;
	tabItem.pszText = (LPTSTR)(LPCTSTR)tabName;
	int curenItemIndex = moImageTabCtrl.GetItemCount();
	moImageTabCtrl.InsertItem(curenItemIndex, &tabItem );
	tabItem.lParam = (LPARAM)( dlgPage );
	moImageTabCtrl.SetItem(curenItemIndex, &tabItem );
	
	VERIFY( dlgPage->Create( dialogResurce, &moImageTabCtrl ) );


	CRect moTabRect;
	moImageTabCtrl.GetWindowRect( &moTabRect );
	int weidth = moTabRect.right - moTabRect.left;
	int height = moTabRect.bottom - moTabRect.top;
	
	dlgPage->SetWindowPos( NULL, 10, 30, weidth, height, SWP_NOSIZE | SWP_NOZORDER );
	dlgPage->ShowWindow( !curenItemIndex ? SW_SHOW : SW_HIDE);
}

void CMainWindowDlg::OnHelpAboutprogram()
{
	CDialog aDlg(IDD_ABOUTBOX);
	aDlg.DoModal();
}

void CMainWindowDlg::OnExit()
{
	DestroyWindow();
}


void CMainWindowDlg::OnTcnSelchangeTabCtrl(NMHDR *pNMHDR, LRESULT *pResult)
{
	int curentSelTab = moImageTabCtrl.GetCurSel();
	TC_ITEM tabItem;
	tabItem.mask = TCIF_PARAM;
	moImageTabCtrl.GetItem( curentSelTab, &tabItem );
	CWnd* pWnd = ( CWnd* )tabItem.lParam;
	if ( pWnd )
		pWnd->ShowWindow(SW_SHOW);
	*pResult = 0;
}


void CMainWindowDlg::OnTcnSelchangingTabCtrl(NMHDR *pNMHDR, LRESULT *pResult)
{
	int curentSelTab = moImageTabCtrl.GetCurSel();
	TC_ITEM tabItem;
	tabItem.mask = TCIF_PARAM;
	moImageTabCtrl.GetItem( curentSelTab, &tabItem );
	CWnd* pWnd = ( CWnd* )tabItem.lParam;
	if( pWnd )
	    pWnd->ShowWindow(SW_HIDE);
	*pResult = 0;
}


void CMainWindowDlg::OnFileOpen()
{
	CFileDialog fileDialog(TRUE, _T("png"), NULL, OFN_HIDEREADONLY, _T("PNG Files(*.png)|*.png||"));	//������ ������ ������ ����� 
	int result = fileDialog.DoModal();	
	if (result == IDOK)	
	{
		defaultFileName = fileDialog.GetPathName();
	}
}
