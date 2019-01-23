
// MainWindowDlg.h : header file
//

#pragma once

#include "ImageTab.h"
#include "RecognizeTab.h"

enum ComponentState {
	Lock,
	Unlock
};

// CMainWindowDlg dialog
class CMainWindowDlg : public CDialogEx
{
// Construction
public:
	CMainWindowDlg(CWnd* pParent = nullptr);	// standard constructor
	~CMainWindowDlg();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAINWINDOW_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	ImageTab* mpoImageTab;
	RecognizeTab* mpoRecognizeTab;

public:
	CProgressCtrl moProgressBar;
	afx_msg void OnHelpAboutprogram();
	afx_msg void OnExit();
	afx_msg void OnTcnSelchangeTabCtrl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTcnSelchangingTabCtrl(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnFileOpen();

	CTabCtrl moImageTabCtrl;
	
	CSliderCtrl moBrightnessSlider;
	CSliderCtrl moContrastSlider;
	
	CEdit moBrightnessEdit;
	CEdit moContrastEdit;
	
	CComboBox moFrameSizeCombo;
	CComboBox moAccuracyCombo;
	CComboBox moThresholdTypeCombo;
	
	CButton moStartRecognizeBtn;
	CButton moSaveDrawingBtn;
	
	CStatic moFileNameLabel;
	CStatic moFileNameStatic;
	CStatic moFileSizeLabel;
	CStatic moFileSizeStatic;
	CStatic moFileDimensionsStatic;
	CStatic moFileDimensionsLabel;

	const CString getDefaultFullFileName( )const;

private:
	CString defaultFullFileFileName;
	void mvChangeComponentState(ComponentState newStete);
	void mvVisibleFileInfo(int visibleState);
	void mvInitializeImageTabCtr(CDialog* dlgPage, CString tabName, int dialogResurce);
	HRESULT syncronizedEditAndSlider(CSliderCtrl* poSliderCtrl, CString newPos);
	
public:
	afx_msg void OnBnClickedRecognizeImage();
	afx_msg void OnFileClose();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeBrightnessEdit();
	afx_msg void OnEnChangeContrastEdit();
};
