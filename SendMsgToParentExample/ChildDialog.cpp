// ChildDialog.cpp : implementation file
//

#include "pch.h"
#include "SendMsgToParentExample.h"
#include "ChildDialog.h"
#include "afxdialogex.h"


// ChildDialog dialog

IMPLEMENT_DYNAMIC(ChildDialog, CDialogEx)

ChildDialog::ChildDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_CHILD, pParent)
{

}

ChildDialog::~ChildDialog()
{
}

void ChildDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDT_MSG, m_edtMsg);
}


BEGIN_MESSAGE_MAP(ChildDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_SEND_MSG_TO_PARENT, &ChildDialog::OnBnClickedBtnSendMsgToParent)
END_MESSAGE_MAP()


// ChildDialog message handlers


void ChildDialog::OnBnClickedBtnSendMsgToParent()
{
	CString msg;
	m_edtMsg.GetWindowTextW(msg);

	CString* pStr = new CString(msg);

	GetParent()->PostMessage(FSM_MESSAGE, (WPARAM)pStr, 268);
}


BOOL ChildDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	SetWindowTextW(L"Child Dialog");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
