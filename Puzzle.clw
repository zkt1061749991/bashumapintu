; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=FreeLevelDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Puzzle.h"
LastPage=0

ClassCount=10
Class1=CPuzzleApp
Class2=CPuzzleDoc
Class3=CPuzzleView
Class4=CMainFrame

ResourceCount=8
Resource1=IDD_DIALOG4
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Resource3=IDR_MAINFRAME
Resource4=IDD_DIALOG3
Class6=SelectDlg
Class7=EndDlg
Resource5=IDD_DIALOG1
Class8=LookPic
Resource6=IDD_PUZZLE_FORM
Class9=FreeLevelDlg
Resource7=IDD_DIALOG2
Class10=WaysDlg
Resource8=IDD_DIALOG5

[CLS:CPuzzleApp]
Type=0
HeaderFile=Puzzle.h
ImplementationFile=Puzzle.cpp
Filter=N

[CLS:CPuzzleDoc]
Type=0
HeaderFile=PuzzleDoc.h
ImplementationFile=PuzzleDoc.cpp
Filter=N
LastObject=IDC_STATICPIC1
BaseClass=CDocument
VirtualFilter=DC

[CLS:CPuzzleView]
Type=0
HeaderFile=PuzzleView.h
ImplementationFile=PuzzleView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CPuzzleView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_SELECT
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Puzzle.cpp
ImplementationFile=Puzzle.cpp
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
Command1=ID_QUICKSTART
Command2=ID_AOTUPLAYER
Command3=ID_APP_EXIT
Command4=ID_FILE_SAVE
Command5=ID_FILE_KEEP_PLAYING
Command6=ID_SELECT
Command7=ID_PIC_OPEN
Command8=ID_MENUITEM32776
Command9=ID_MENUITEM32777
Command10=ID_MENUITEM32778
Command11=ID_MENUITEM32781
Command12=ID_MENUITEM32771
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

[DLG:IDD_PUZZLE_FORM]
Type=1
Class=CPuzzleView
ControlCount=8
Control1=IDC_STEP,static,1342308353
Control2=IDC_STATICTIME,static,1342308353
Control3=IDC_BUTTONLOOKPIC,button,1342177291
Control4=IDC_BUTTONRESTART,button,1342177291
Control5=IDC_STATIC,static,1342177294
Control6=IDC_STATIC,static,1342177294
Control7=IDC_STATIC,static,1342177294
Control8=IDC_STATIC,static,1342177294

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
Class=EndDlg
ControlCount=5
Control1=IDC_BUTTONPLAYAGAIN,button,1342242827
Control2=IDC_BUTTONUNPLAY,button,1342242827
Control3=IDC_STATICEND,static,1342308352
Control4=IDC_STATIC,static,1342177294
Control5=IDC_STATICENDTEXT,static,1342308353

[DLG:IDD_DIALOG2]
Type=1
Class=SelectDlg
ControlCount=14
Control1=IDCANCEL,button,1342242827
Control2=IDC_STATICPIC1,static,1350566158
Control3=IDC_STATICPIC2,static,1350566158
Control4=IDC_STATICPIC3,static,1350566158
Control5=IDC_STATICPIC4,static,1350566158
Control6=IDC_STATICPIC5,static,1350566158
Control7=IDC_STATICPIC6,static,1350566158
Control8=IDC_STATIC,static,1342177294
Control9=IDC_STATIC,static,1342177294
Control10=IDC_STATIC,static,1342177294
Control11=IDC_STATIC,static,1342177294
Control12=IDC_STATIC,static,1342177294
Control13=IDC_STATIC,static,1342177294
Control14=IDC_STATIC,static,1342177294

[CLS:SelectDlg]
Type=0
HeaderFile=SelectDlg.h
ImplementationFile=SelectDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_STATICPIC1
VirtualFilter=dWC

[CLS:EndDlg]
Type=0
HeaderFile=EndDlg.h
ImplementationFile=EndDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_EDIT_CUT
VirtualFilter=dWC

[DLG:IDD_DIALOG3]
Type=1
Class=LookPic
ControlCount=1
Control1=IDC_STATICLOOKPIC,static,1342177294

[CLS:LookPic]
Type=0
HeaderFile=LookPic.h
ImplementationFile=LookPic.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_AOTUPLAYER
VirtualFilter=dWC

[DLG:IDD_DIALOG4]
Type=1
Class=FreeLevelDlg
ControlCount=4
Control1=IDOK,button,1342242827
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342177294
Control4=IDC_EDIT1,edit,1350631552

[CLS:FreeLevelDlg]
Type=0
HeaderFile=FreeLevelDlg.h
ImplementationFile=FreeLevelDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_DIALOG5]
Type=1
Class=WaysDlg
ControlCount=3
Control1=IDC_BUTTONOK,button,1342242827
Control2=IDC_STATIC,static,1342177294
Control3=IDC_STATICTEXT,static,1342308352

[CLS:WaysDlg]
Type=0
HeaderFile=WaysDlg.h
ImplementationFile=WaysDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTONOK
VirtualFilter=dWC

