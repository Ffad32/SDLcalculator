

set working directory
cd c:\home\user\main

64-bit version

compile:

cls && gcc ./src/*.c -lSDL2 -lSDL2_image -L ./lib/x64 -I ./include -I ./src -o ./bin/x64/program.exe && start ./bin/x64/program.exe