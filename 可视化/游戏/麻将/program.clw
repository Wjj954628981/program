; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNum
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "program.h"
LastPage=0

ClassCount=9
Class1=CProgramApp
Class2=CProgramDoc
Class3=CProgramView
Class4=CMainFrame

ResourceCount=6
Resource1=IDR_MAINFRAME
Resource2=IDD_DIALOG3
Class5=CAboutDlg
Class6=CServer
Resource3=IDD_ABOUTBOX
Class7=CGetin
Resource4=IDD_DIALOG2
Class8=CEnter
Class9=CNum
Resource5=IDD_DIALOG1
Resource6=IDD_DIALOG5

[CLS:CProgramApp]
Type=0
HeaderFile=program.h
ImplementationFile=program.cpp
Filter=N

[CLS:CProgramDoc]
Type=0
HeaderFile=programDoc.h
ImplementationFile=programDoc.cpp
Filter=N

[CLS:CProgramView]
Type=0
HeaderFile=programView.h
ImplementationFile=programView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=program.cpp
ImplementationFile=program.cpp
Filter=D
LastObject=CAboutDlg

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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

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
Class=CServer
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_STATIC,static,1342308352

[CLS:CServer]
Type=0
HeaderFile=Server.h
ImplementationFile=Server.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CServer

[DLG:IDD_DIALOG2]
Type=1
Class=CGetin
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CGetin]
Type=0
HeaderFile=Getin.h
ImplementationFile=Getin.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DIALOG3]
Type=1
Class=CEnter
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552

[CLS:CEnter]
Type=0
HeaderFile=Enter.h
ImplementationFile=Enter.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CEnter

[DLG:IDD_DIALOG5]
Type=1
Class=CNum
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342177280
Control3=IDC_STATIC,static,1342177280
Control4=IDC_SCORE1,static,1342177280
Control5=IDC_SCORE2,static,1342177280
Control6=IDC_SCORE3,static,1342177280
Control7=IDC_SCORE4,static,1342177280
Control8=IDC_PLAYER1,static,1342177280
Control9=IDC_PLAYER2,static,1342177280
Control10=IDC_PLAYER3,static,1342177280
Control11=IDC_PLAYER4,static,1342177280
Control12=IDC_CSTRING,static,1342177280

[CLS:CNum]
Type=0
HeaderFile=Num.h
ImplementationFile=Num.cpp
BaseClass=CDialog
Filter=D
LastObject=CNum
VirtualFilter=dWC

