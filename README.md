# olcEngine Test

A project to test the olcPixelGameEngine

## Installation

You can:

1. Use an IDE like Visual Studio and Install C++ components
2. Install the latest version of gcc for Windows: <a href="https://winlibs.com">here</a><br/>
   To compile and run the project using powershell:

    ```
    ./run.ps1
    ```

    Manually:

    ```
    g++ -std=c++17 main.cpp -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -o "build/main.exe"
    ./build/main.exe
    ```
