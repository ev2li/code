gcc -fPIC --shared plugin.c -o libplugin.so

gcc -o main main.c -ldl


gcc -fPIC --shared plugin2.c -o libplugin2.so

gcc -o main2 main.2c -ldl
