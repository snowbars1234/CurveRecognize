#pragma once


// ImageTab dialog

class ImageTab : public CDialog
{
	DECLARE_DYNAMIC(ImageTab)

public:
	ImageTab(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ImageTab();

// Dialog Data
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMAGE_TAB };
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
