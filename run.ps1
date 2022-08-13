$exeName = "build/main.exe"
g++ -std=c++17 main.cpp -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -o $exeName
Start-Process $exeName
