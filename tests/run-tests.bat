@echo off
chcp 1251 > nul 
setlocal enabledelayedexpansion

set program=%1
set root_folder=%2

if "%~2"=="" (
    set program="../x64/Debug/TSCompiler.exe"
    set root_folder="."
)

for /D /R "%root_folder%" %%d in (*) do (
    echo Processing folder %%d...

    set "result_file=%%d\result.txt"
    echo %date% %time% > "!result_file!"
    echo Results for folder %%d: >> "!result_file!"
    echo. >> "!result_file!"

    for %%f in ("%%d\*.test" "%%d\*.ts") do (
        echo Input data from %%f: >> "!result_file!"
        type "%%f" >> "!result_file!"
        echo. >> "!result_file!"

        echo Output data for %%f: >> "!result_file!"
        %program% "%%f" >> "!result_file!" 2>&1

        echo --------------- >> "!result_file!"
        echo. >> "!result_file!"
    )
)

echo Done processing all tests.