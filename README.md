# ffmpeg-build
steps for building ffmpeg library

### install third party 
1. Download NASM installer from http://www.nasm.us and install E:\Code\ffmpeg-build\ThirdParty\NASM
2. Download MSYS2 installer from http://www.msys2.org/ and install to E:\Code\ffmpeg-build\ThirdParty\msys64
1. Download Yasm executable from http://yasm.tortall.net/Download.html, rename to yasm.exe and put to E:\Code\ffmpeg-build\ThirdParty\yasm

Open x86 Native Tools Command Prompt for VS 2017.bat,then go to E:\Code\ffmpeg-build

### build opus
git clone https://github.com/telegramdesktop/opus.git
cd opus
git checkout tdesktop
cd win32\VS2015
msbuild opus.sln /property:Configuration=Debug /property:Platform="Win32"
msbuild opus.sln /property:Configuration=Release /property:Platform="Win32"

### build ffmpeg
1. SET PATH=%cd%\ThirdParty\NASM;%cd%\ThirdParty\yasm;%cd%\ThirdParty\msys64\usr\bin;%PATH% 
1. git clone https://github.com/FFmpeg/FFmpeg.git ffmpeg
2. cd ffmpeg
3. git checkout release/3.4
4. set CHERE_INVOKING=enabled_from_arguments
5. set MSYS2_PATH_TYPE=inherit
6. bash --login build_ffmpeg_win.sh