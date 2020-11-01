#!/bin/bash
set -e
oj --version

CXX=${CXX:-g++-8}
CXXFLAGS="${CXXFLAGS:--std=c++17 -O2 -Wall -g}"
#ulimit -s 500000

run() {
    echo "!!function called"
    rm -rf "test"
    file="$1"
    url="$(grep -o '^# *define \+PROBLEM \+\(https\?://.*\)' < "$file" | sed 's/.* http/http/')"
    dir=test/$(echo -n "$url" | md5sum | sed 's/ .*//')
    mkdir -p ${dir}
    $CXX $CXXFLAGS -I . -o ${dir}/a.out "$file"
    if [[ -n ${url} ]] ; then
        if [[ ! -e ${dir}/test ]] ; then
            sleep 2
            oj download --system "$url" -d ${dir}/test
        fi
        oj test --tle 10 --c ${dir}/a.out -d ${dir}/test
    else
        ${dir}/a.out
    fi
}
if [ $# -eq 0 ] ; then
    for f in $(find . -name \*.test.cpp) ; do
        run $f
    done
else
    for f in "$@" ; do
        run "$f"
    done
fi

