To use my libraries, follow the steps:
1. import "${library}.h" in your project file.
2. while compiling, 
    gcc -I../MyLibrary/include main.c ../MyLibrary/build/${library}.o -o main