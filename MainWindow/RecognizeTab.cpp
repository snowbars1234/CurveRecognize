// RecognizeTab.cpp : implementation file
//

#include "stdafx.h"
#include "MainWindow.h"
#include "RecognizeTab.h"
#include "afxdialogex.h"


// RecognizeTab dialog

IMPLEMENT_DYNAMIC(RecognizeTab, CDialog)

RecognizeTab::RecognizeTab(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RECOGNIZE_TAB, pParent)
{

}

RecognizeTab::~RecognizeTab()
{
}

void RecognizeTab::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RecognizeTab, CDialog)
END_MESSAGE_MAP()


// RecognizeTab message handlers
