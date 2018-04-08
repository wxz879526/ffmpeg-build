# ffmpeg-build
steps for building ffmpeg library

### checkout code
git clone --recursive https://github.com/wxz879526/ffmpeg-build.git

### install thirdparty app
Install nasm-2.13.03-installer-x86.exe to your local path, eg: E:\Code\ffmpeg-build\ThirdParty\NASM  
Install msys2-x86_64-20161025.exe to your local path, eg: E:\Code\ffmpeg-build\ThirdParty\msys64  
Rename yasm-1.3.0-win32.exe to yasm.exe and put to your local path, eg: E:\Code\ffmpeg-build\ThirdParty\yasm  

Open x86 Native Tools Command Prompt for VS 2017.bat,then go to E:\Code\ffmpeg-build  

### build opus
cd opus  
git checkout tdesktop  
cd win32\VS2015  
msbuild opus.sln /property:Configuration=Debug /property:Platform="Win32"  
msbuild opus.sln /property:Configuration=Release /property:Platform="Win32"

### build ffmpeg
SET PATH=%cd%\ThirdParty\NASM;%cd%\ThirdParty\yasm;%cd%\ThirdParty\msys64\usr\bin;%PATH%  
cd FFmpeg  
git checkout release/3.4  
set CHERE_INVOKING=enabled_from_arguments  
set MSYS2_PATH_TYPE=inherit  
bash --login ../build_ffmpeg_win.sh  
