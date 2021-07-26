# Microsoft Developer Studio Project File - Name="Puzzle" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Puzzle - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Puzzle.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Puzzle.mak" CFG="Puzzle - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Puzzle - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
# Begin Target

# Name "Puzzle - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\answer.cpp
# End Source File
# Begin Source File

SOURCE=.\EndDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FreeLevelDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LookPic.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\P.cpp
# End Source File
# Begin Source File

SOURCE=.\Puzzle.cpp
# End Source File
# Begin Source File

SOURCE=.\Puzzle.rc
# End Source File
# Begin Source File

SOURCE=.\PuzzleDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\PuzzleView.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\WaysDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\answer.h
# End Source File
# Begin Source File

SOURCE=.\EndDlg.h
# End Source File
# Begin Source File

SOURCE=.\FreeLevelDlg.h
# End Source File
# Begin Source File

SOURCE=.\LookPic.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\P.h
# End Source File
# Begin Source File

SOURCE=.\Puzzle.h
# End Source File
# Begin Source File

SOURCE=.\PuzzleDoc.h
# End Source File
# Begin Source File

SOURCE=.\PuzzleView.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SelectDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\WaysDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\170709185031.bmp
# End Source File
# Begin Source File

SOURCE=.\res\2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\94403431672264.bmp
# End Source File
# Begin Source File

SOURCE=.\res\aiystan.bmp
# End Source File
# Begin Source File

SOURCE=.\res\anniu.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap16.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap17.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap19.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap20.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\button1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\button2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\end.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Puzzle.ico
# End Source File
# Begin Source File

SOURCE=.\res\Puzzle.rc2
# End Source File
# Begin Source File

SOURCE=.\res\PuzzleDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\timg.bmp
# End Source File
# Begin Source File

SOURCE=".\res\TIM图片20170707225015.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\TIM图片20170707225036.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\TIM图片20170707225045.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=".\res\海贼王.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\结束.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\科比.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\码上拼图.ico"
# End Source File
# Begin Source File

SOURCE=".\res\上.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\说明.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\下.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\选择图片.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\右.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\知道了.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\中.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\左.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\左1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\左2.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\01.wav
# End Source File
# Begin Source File

SOURCE=.\res\03.wav
# End Source File
# Begin Source File

SOURCE=".\res\08_爱给网_aigei_com.wav"
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\res\VICTORY.wav
# End Source File
# Begin Source File

SOURCE=".\res\纸翻开新一页5_爱给网_aigei_com.wav"
# End Source File
# End Target
# End Project
