@echo off
chcp 1251 > nul 
setlocal enabledelayedexpansion

set program=%1
set test_folder=%2

if "%~2"=="" (
    set program="../x64/Debug/TSCompiler.exe"
    set test_folder="."
)

set result_file="%test_folder%\result.txt"

echo %date% %time% > %result_file%
echo. >> %result_file%

for %%f in ("%test_folder%\*.test") do (
    echo Input data from %%f: >> %result_file%
    type %%f >> %result_file%
    echo. >> %result_file%
    
    echo Output data for %%f: >> %result_file%
    %program% %%f >> %result_file% 2>&1
    
    echo --------------- >> %result_file%
    echo. >> %result_file%
)

del output.txt

code %result_file%