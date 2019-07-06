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

reset() {
    cat ./lib/macro > code.cpp
    : > input
    echo -e "\e[32m[OK]\e[m Reset completed."
}

if [ $# = 0 ]; then
    echo -e "\e[33m[USAGE]\e[m cptest [options]"
    echo "    -n : Test normally"
    echo "    -i : Test from input file"
    echo "    -c : Copy to the clipboard"
    echo "    -r : Reset macro"
fi
for OPT in "$@"
do
    case "$OPT" in
        '-n' )
            run
            ;;
        '-i' )
            FLAG_I=1
            run
            ;;
        '-c' )
            copy
            ;;
        '-r' )
            reset
            ;;
    esac
done
