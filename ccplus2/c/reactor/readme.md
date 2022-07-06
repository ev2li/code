gcc -fPIC --shared plugin.c -o libplugin.so
gcc -o main main.c -ldl
