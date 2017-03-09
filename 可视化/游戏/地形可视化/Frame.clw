; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Frame.h"
LastPage=0

ClassCount=6
Class1=CFrameApp
Class2=CFrameDoc
Class3=CFrameView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CLineView
Resource3=IDD_DIALOG1

[CLS:CFrameApp]
Type=0
HeaderFile=Frame.h
ImplementationFile=Frame.cpp
Filter=N

[CLS:CFrameDoc]
Type=0
HeaderFile=FrameDoc.h
ImplementationFile=FrameDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CFrameDoc

[CLS:CFrameView]
Type=0
HeaderFile=FrameView.h
ImplementationFile=FrameView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_DRAW_2D


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_DRAW_3D




[CLS:CAboutDlg]
Type=0
HeaderFile=Frame.cpp
ImplementationFile=Frame.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE
Command3=ID_FILE_SAVE_AS
Command4=ID_FILE_PRINT
Command5=ID_FILE_PRINT_PREVIEW
Command6=ID_FILE_PRINT_SETUP
Command7=ID_FILE_MRU_FILE1
Command8=ID_APP_EXIT
Command9=ID_DRAW_2D
Command10=ID_DRAW_3D
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=CLineView
ControlCount=11
Control1=IDC_STATIC,button,1342308359
Control2=IDC_RotateX,button,1342242819
Control3=IDC_RotateY,button,1342242819
Control4=IDC_RotateZ,button,1342242819
Control5=IDC_STATIC,button,1342177287
Control6=IDC_SLIDER1,msctls_trackbar32,1476460568
Control7=IDC_SLIDER2,msctls_trackbar32,1476460568
Control8=IDC_HORIZON,static,1342308352
Control9=IDC_HORIZON1,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352

[CLS:CLineView]
Type=0
HeaderFile=LineView.h
ImplementationFile=LineView.cpp
BaseClass=CFormView
Filter=D
LastObject=ID_DRAW_3D
VirtualFilter=VWC

