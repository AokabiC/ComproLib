#!/bin/bash
echo "Compiling..."
g++ -Wall -std=c++14 ./code.cpp
if [ -e ./a.out ]; then
    key="y"
    testcount=1;
    while [ "$key" = "y" ]
    do
        echo "---------- TEST #${testcount} ----------"
        ./a.out
        testcount=`expr ${testcount} + 1`
        echo -n -e "\e[33mContinue?\e[m "
        read key
    done
    if [ "$key" = "c" ]; then
        cat code.cpp | clip.exe
        echo -e "\e[32m[OK]\e[m Copied to the clipboard."
    fi
else
    echo -e "\e[31m[ERR]\e[m Compilation failed."
fi
rm -f a.out
