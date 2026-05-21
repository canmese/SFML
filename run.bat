@echo off
title SFML Oyun Derleyici

:: 1. Derleyiciyi ve SFML DLL'lerini gecici olarak sisteme tanit (Sadece bu pencere icin gecerli)
set PATH=%~dp0compiler\bin;%~dp0sfml\bin;%PATH%

:: 2. Eski exe dosyasini sil (eger varsa)
if exist main.exe del main.exe

echo [INFO] Derleniyor... Lutfen bekleyin.

:: 3. Kodu Derle (Kendi icindeki compiler ve sfml klasorlerini kullanarak)
g++ -std=c++17 main.cpp -I"sfml/include" -L"sfml/lib" -lsfml-graphics -lsfml-window -lsfml-system -o main.exe

:: 4. Hata kontrolu
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [HATA] Kodunuzda bir sorun var. Derleme basarisiz!
    pause
    exit /b
)

echo [BASARILI] Oyun baslatiliyor...

:: 5. Oyunu calistir
main.exe

exit