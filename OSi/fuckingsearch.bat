@echo off

setlocal

rem change to the correct directory
cd /d C:\

rem count the files
dir /b %1 /s 2> nul | find "" /v /c > %temp%\count
set /p _count=<%temp%\count

rem cleanup
del %temp%\count

rem output the number of files
echo Files found : %_count%

rem list the files
echo Files Paths :
dir /b %1 /s

endlocal
