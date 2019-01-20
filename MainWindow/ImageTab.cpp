// ImageTab.cpp : implementation file
//

#include "stdafx.h"
#include "MainWindow.h"
#include "ImageTab.h"
#include "afxdialogex.h"


// ImageTab dialog

IMPLEMENT_DYNAMIC(ImageTab, CDialog)

ImageTab::ImageTab(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_IMAGE_TAB, pParent)
{

}

ImageTab::~ImageTab()
{
}

void ImageTab::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DEFAULT_PICTURE, moDefaultPicture);
}


BEGIN_MESSAGE_MAP(ImageTab, CDialog)
	ON_STN_CLICKED(IDC_DEFAULT_PICTURE, &ImageTab::OnStnClickedDefaultPicture)
END_MESSAGE_MAP()


// ImageTab message handlers


void ImageTab::OnStnClickedDefaultPicture()
{
	// TODO: Add your control notification handler code here
}
