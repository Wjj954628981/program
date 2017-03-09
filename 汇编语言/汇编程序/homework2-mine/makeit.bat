@echo off

    if exist "homework2.obj" del "homework2.obj"
    if exist "homework2.exe" del "homework2.exe"

    \masm32\bin\ml /c /coff "homework2.asm"
    if errorlevel 1 goto errasm

    \masm32\bin\PoLink /SUBSYSTEM:CONSOLE "homework2.obj"
    if errorlevel 1 goto errlink
    dir "homework2.*"
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
