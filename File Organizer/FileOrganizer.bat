@echo off
setlocal enabledelayedexpansion

set "diretorio=%~dp0"

set "diretorio=%diretorio:~0,-1%"

cd /d "%diretorio%"

for %%f in (*.*) do (
    set "ext=%%~xf"
    set "ext=!ext:~1!"


    if not "!ext!"=="" (
        if not exist "!ext!" (
            mkdir "!ext!"
        )
        move "%%f" "!ext!\"
    )
)

endlocal
