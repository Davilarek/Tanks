@echo off
@REM call download-sdl2.bat
@REM tar -xvzf *.tar.gz -C .\resources\SDL
mkdir resources\SDL
for /r %%i in (*.tar.gz) do tar -xvzf "%%i" -C resources\SDL
cd resources\SDL
@REM for %%i in (*) do move %%i\*.* .\
@REM for /r %%i in (*.*) do echo %%i
for /d %%i in (".\*") do (
    xcopy /Y /s /e "%%i\*" ".\"
    rd /s /q "%%i"
)