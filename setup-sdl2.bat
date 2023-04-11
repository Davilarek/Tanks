@echo off
call download-sdl2.bat
mkdir resources\SDL
for /r %%i in (*.tar.gz) do tar -xvzf "%%i" -C resources\SDL
cd resources\SDL
for /d %%i in (".\*") do (
    xcopy /Y /s /e "%%i\*" ".\"
    rd /s /q "%%i"
)
