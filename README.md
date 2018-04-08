# ffmpeg-build
steps for building ffmpeg library

### checkout code
git clone --recursive https://github.com/wxz879526/ffmpeg-build.git

### install thirdparty app
Install ActivePerl-5.22.4.2205-MSWin32-x86-64int-403863.exe to your local path, eg: E:\Code\ffmpeg-build\ThirdParty\Perl  
Install nasm-2.13.03-installer-x86.exe to your local path, eg: E:\Code\ffmpeg-build\ThirdParty\NASM  
Install msys2-x86_64-20161025.exe to your local path, eg: E:\Code\ffmpeg-build\ThirdParty\msys64  
Rename yasm-1.3.0-win32.exe to yasm.exe and put to your local path, eg: E:\Code\ffmpeg-build\ThirdParty\yasm  

### build opus and FFmpeg
Open x86 Native Tools Command Prompt for VS 2017.bat,then go to E:\Code\ffmpeg-build  
cd opus  
git checkout tdesktop  
cd win32\VS2015  
msbuild opus.sln /property:Configuration=Debug /property:Platform="Win32"  
msbuild opus.sln /property:Configuration=Release /property:Platform="Win32"

SET PATH=%cd%\ThirdParty\Perl\bin;%cd%\ThirdParty\NASM;%cd%\ThirdParty\yasm;%cd%\ThirdParty\msys64\usr\bin;%PATH%  
cd FFmpeg  
git checkout release/3.4  
set CHERE_INVOKING=enabled_from_arguments  
set MSYS2_PATH_TYPE=inherit  
bash --login ../build_ffmpeg_win.sh  
