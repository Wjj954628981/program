@echo off

    if exist "tmp.obj" del "tmp.obj"
    if exist "tmp.exe" del "tmp.exe"

    \masm32\bin\ml /c /coff "tmp.asm"
    if errorlevel 1 goto errasm

    \masm32\bin\PoLink /SUBSYSTEM:CONSOLE "tmp.obj"
    if errorlevel 1 goto errlink
    dir "tmp.*"
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
