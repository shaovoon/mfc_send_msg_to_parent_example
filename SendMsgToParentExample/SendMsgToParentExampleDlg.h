
// SendMsgToParentExampleDlg.h : header file
//

#pragma once


// CSendMsgToParentExampleDlg dialog
class CSendMsgToParentExampleDlg : public CDialogEx
{
// Construction
public:
	CSendMsgToParentExampleDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SENDMSGTOPARENTEXAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnFsmMessage(WPARAM wparam, LPARAM lparam);
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edtText;
	afx_msg void OnBnClickedBtnLaunchChildDialog();
};
