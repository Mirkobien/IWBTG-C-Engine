del iwbtg.exe
cls
gcc -std=c99 -g main.c -o iwbtg.exe -lm -lSDL2 -lSDL2_image -lSDL2_mixer -fmax-errors=5
iwbtg.exe