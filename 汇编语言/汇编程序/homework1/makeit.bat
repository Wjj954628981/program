@echo off

    if exist "homework1.obj" del "homework1.obj"
    if exist "homework1.exe" del "homework1.exe"

    \masm32\bin\ml /c /coff "homework1.asm"
    if errorlevel 1 goto errasm

    \masm32\bin\PoLink /SUBSYSTEM:CONSOLE "homework1.obj"
    if errorlevel 1 goto errlink
    dir "homework1.*"
    goto TheEnd

  :errlink
    echo _
    echo Link error
    goto TheEnd

  :errasm
    echo _
    echo Assembly Error
    goto TheEnd
    
  :TheEnd

pause
