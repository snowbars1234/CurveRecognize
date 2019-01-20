#pragma once


// RecognizeTab dialog

class RecognizeTab : public CDialog
{
	DECLARE_DYNAMIC(RecognizeTab)

public:
	RecognizeTab(CWnd* pParent = nullptr);   // standard constructor
	virtual ~RecognizeTab();

// Dialog Data
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RECOGNIZE_TAB };
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
