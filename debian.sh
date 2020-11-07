#!/bin/bash

# --- 检查输入 ----

is_install=0
is_force=0
is_clean=0
is_update=0

for opt in $@
do
    if [[ "$opt" == "-f" ]]; then
        is_force=1
    elif [[ "$opt" == "-i" ]]; then
        is_install=1
    elif [[ "$opt" == "-c" ]]; then
        is_clean=1
    elif [[ "$opt" == "-u" ]]; then
        is_update=1
    elif [[ "$opt" == "-h" ]]; then
        echo "usage ./debian.sh [option -c -f -i]"
        echo "-f build deb even if git is not committed"
        echo "-i install deb after it is packaged"
        echo "-c rm  files and directory which it is generated when building"
        exit 0
    else
        echo "not such option: $opt !"
        exit -1
    fi
done

if [[ ${is_clean} = 1 ]]; then
    rm -rf ./build/
    rm -rf *.out
    echo "---make clean done!---"
    exit -1
fi

# --- 检查 git 路径 ---
if [[ ${is_force} != 1 ]]; then
    git_status=$(git status  --porcelain)
    # echo ${git_status}
    if [[ -z ${git_status} ]]; then
        echo "git is clean!"
    else
        echo "git is not clean, please commit first!"
        exit -1
    fi
fi

# --- 编译 ---
mkdir -p ./build/

cd ./build/

cmake ..

make

if ! [[ $? = 0 ]] ; then
    echo "build error or warn!"
    exit -1
fi

mv ./*.out ../

cd ..

# end of file
