#!/bin/bash

PROGNAME=$(basename $0)

copy() {
    cat code.cpp | pbcopy
    printf "\e[32m[OK]\e[m Copied to the clipboard.\n"
}

run() {
    echo "Compiling..."
    g++ -Wall -g -D_GLIBCXX_DEBUG -fsanitize=undefined -std=c++14 ./code.cpp -fvisibility=hidden
    # g++ -std=c++14 ./code.cpp
    if [ $? -gt 0 ]; then
        printf "\e[31m[ERR]\e[m Compilation failed.\n"
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
        printf "\e[33mContinue?\e[m "
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
    printf "\e[32m[OK]\e[m Reset completed.\n"
}

if [ $# = 0 ]; then
    printf "\e[33m[USAGE]\e[m cptest [options]\n"
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
