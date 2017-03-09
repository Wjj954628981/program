@echo off

    if exist "print.obj" del "print.obj"
    if exist "print.exe" del "print.exe"

    \masm32\bin\ml /c /coff "print.asm"
    if errorlevel 1 goto errasm

    \masm32\bin\PoLink /SUBSYSTEM:CONSOLE "print.obj"
    if errorlevel 1 goto errlink
    dir "print.*"
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
