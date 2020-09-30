#pragma once


// ChildDialog dialog

class ChildDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ChildDialog)

public:
	ChildDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ChildDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CHILD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnSendMsgToParent();
	CEdit m_edtMsg;
	virtual BOOL OnInitDialog();
};
