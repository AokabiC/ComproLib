#!/bin/bash

PROGNAME=$(basename $0)

copy() {
    cat code.cpp | clip.exe
    echo -e "\e[32m[OK]\e[m Copied to the clipboard."
}

run() {
    echo "Compiling..."
    g++ -Wall -g -D_GLIBCXX_DEBUG -fsanitize=undefined -std=c++14 ./code.cpp
    if [ $? -gt 0 ]; then
        echo -e "\e[31m[ERR]\e[m Compilation failed."
        return 1
    fi
    key="y"
    testcount=1;
    while [ "$key" = "y" ]
    do
        echo "---------- TEST #${testcount} ----------"
        if [ "$FLAG_I" ] && [ $testcount = 1 ]; then
            ./a.out < input
        else
            ./a.out
        fi
        testcount=`expr ${testcount} + 1`
        echo -n -e "\e[33mContinue?\e[m "
        read key
    done
    if [ "$key" = "c" ]; then
        copy
    fi
    rm -f a.out
}

if [ $# = 0 ]; then
    run
fi
for OPT in "$@"
do
    case "$OPT" in
        '-i' )
            FLAG_I=1
            run
            ;;
        '-c' )
            copy
            ;;
    esac
done
