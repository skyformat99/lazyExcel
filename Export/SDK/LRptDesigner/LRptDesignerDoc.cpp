// LRptDesignerDoc.cpp : implementation of the CLRptDesignerDoc class
//

#include "stdafx.h"
#include "LRptDesigner.h"
#include "LRptDesignerDoc.h"
#include "LRptDesignerView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLRptDesignerDoc

IMPLEMENT_DYNCREATE(CLRptDesignerDoc, CDocument)

BEGIN_MESSAGE_MAP(CLRptDesignerDoc, CDocument)
	//{{AFX_MSG_MAP(CLRptDesignerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLRptDesignerDoc construction/destruction


CLRptDesignerDoc::CLRptDesignerDoc():bInitOK(FALSE)
{
	// TODO: add one-time construction code here
	//if(!m_RptGrid.CreateDispatch("CLGridBook.CLBookLib"))
	//	ASSERT(FALSE);
}

CLRptDesignerDoc::~CLRptDesignerDoc()
{
}

/////////////////////////////////////////////////////////////////////////////
// CLRptDesignerDoc serialization

void CLRptDesignerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLRptDesignerDoc diagnostics

#ifdef _DEBUG
void CLRptDesignerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLRptDesignerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLRptDesignerDoc commands

void CLRptDesignerDoc::OnCloseDocument()
{
	CDocument::OnCloseDocument();
	CMainFrame* pMainFrame=(CMainFrame*)(CMainFrame*)GetApp()->m_pMainWnd;
	if(pMainFrame && !pMainFrame->GetActiveView()){
		pMainFrame->OnEnableOwnerDrawCtrl(FALSE);
	}
}


BOOL CLRptDesignerDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized creation code here
//	BSTR strFile=::SysAllocString(lpszPathName);
	//AfxGetApp()->GetActiveView();
	/*
	BOOL bRet= m_RptGrid.LoadData(lpszPathName);
	if(!bRet){
		AfxMessageBox("不可识别的文件格式!");
	}*/
	/*
	CLRptDesignerView* pView = GetApp()->GetActiveView();
	if(pView){
		if(!LoadBook(pView->GetReport(),(char*)lpszPathName)){
			AfxMessageBox("不可识别的文件格式!");
		}else
			return TRUE;
	}*/
	return TRUE;//bRet;
}

BOOL CLRptDesignerDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	CLRptDesignerView* pView = GetApp()->GetActiveView();
	if(pView)
		return SaveBook(GetBook(pView->GetReport()),(char*)lpszPathName);
	else 
		return FALSE;
	//return CDocument::OnSaveDocument(lpszPathName);
}
