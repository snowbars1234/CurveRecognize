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
}


BEGIN_MESSAGE_MAP(ImageTab, CDialog)
END_MESSAGE_MAP()


// ImageTab message handlers
