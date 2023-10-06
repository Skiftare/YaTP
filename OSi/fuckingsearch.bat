@echo off
setlocal
cd /d C:\
echo search in C disk
dir /b %1 /s 2> nul | find "" /v /c > %temp%\count
set /p _count=<%temp%\count
del %temp%\count
echo Files found : %_count%
echo Files Paths :
dir /b %1 /s
endlocal
