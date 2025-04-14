@echo off

REM Check if a target folder path was provided
if "%~1"=="" (
    echo Please provide a target folder path.
    exit /b 1
)

set "target_folder=%~1"

REM Copy specified files to the target folder
copy make-generator-with-aider-commands.txt "%target_folder%"
copy make-generator-with-aider.bat "%target_folder%"
copy make-generator-with-aider.txt "%target_folder%"
copy .aider.conf.yml "%target_folder%"
copy CMakeLists.txt "%target_folder%"

REM Create "sol" folder in target folder if it doesn't exist
if not exist "%target_folder%\sol" mkdir "%target_folder%\sol"

REM Copy files from local "sol" folder to the target folder's "sol" folder
copy sol\generator.cpp "%target_folder%\sol"
copy sol\generator_specific.cpp "%target_folder%\sol"
copy sol\testlib.h "%target_folder%\sol"
copy sol\config.txt "%target_folder%\sol"

REM Change directory to the target folder and run make-generator-with-aider.bat
cd /d "%target_folder%"
call .\make-generator-with-aider.bat

REM Create "build" folder in target folder if it doesn't exist
if not exist build mkdir build

REM Change directory to the "build" folder, run CMake and build using Make or MSBuild (depending on your system)
cd /d "%target_folder%\build"
cmake ..
cmake --build .

REM Delete specified files from the target folder
del "%target_folder%\make-generator-with-aider-commands.txt"
del "%target_folder%\make-generator-with-aider.bat"
del "%target_folder%\make-generator-with-aider.txt"
del "%target_folder%\.aider.conf.yml"
del "%target_folder%\.aider.chat.history.md"

REM Open explorer at build folder
start "" "%target_folder%\build"