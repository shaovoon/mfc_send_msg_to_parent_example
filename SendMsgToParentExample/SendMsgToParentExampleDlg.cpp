
// SendMsgToParentExampleDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "SendMsgToParentExample.h"
#include "SendMsgToParentExampleDlg.h"
#include "afxdialogex.h"
#include "ChildDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSendMsgToParentExampleDlg dialog



CSendMsgToParentExampleDlg::CSendMsgToParentExampleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SENDMSGTOPARENTEXAMPLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSendMsgToParentExampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDT_TEXT, m_edtText);
}

BEGIN_MESSAGE_MAP(CSendMsgToParentExampleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(FSM_MESSAGE, &CSendMsgToParentExampleDlg::OnFsmMessage)
	ON_BN_CLICKED(IDC_BTN_LAUNCH_CHILD_DIALOG, &CSendMsgToParentExampleDlg::OnBnClickedBtnLaunchChildDialog)
END_MESSAGE_MAP()


// CSendMsgToParentExampleDlg message handlers

BOOL CSendMsgToParentExampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	SetWindowTextW(L"Parent Dialog");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSendMsgToParentExampleDlg::OnPaint()
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
HCURSOR CSendMsgToParentExampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CSendMsgToParentExampleDlg::OnFsmMessage(WPARAM wparam, LPARAM lparam)
{
	CString* pStr = reinterpret_cast<CString*>(wparam);

	switch (lparam)
	{
	case 268:
		m_edtText.SetWindowTextW(*pStr);
	}

	delete pStr;

	return 0;
}

void CSendMsgToParentExampleDlg::OnBnClickedBtnLaunchChildDialog()
{
	ChildDialog dlg;
	dlg.DoModal();
}
