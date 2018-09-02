echo "Batch File Start"
c:
cd C:\Users\Hpark4435\Desktop
mkdir KevinDX
cd KevinDX
git init
git clone https://github.com/hyunbin7303/DX11.git
cd C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build
call vcvarsall.bat x86
msbuild cd C:\Users\Hpark4435\Desktop\KevinDX\DX11\D3D11Basic2\D3D11Basic2.vcxproj
pause


