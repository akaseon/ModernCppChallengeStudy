#! /bin/bash 

if [ "$#" -eq 1 ]; then
    IS_ONE_PROJECT=true;
    PROJECT_NO=${1};
else
    IS_ONE_PROJECT=false;
fi

mkdir -p build;
pushd build;

    cat ../CMakeheader.cmake > ../CMakeLists.txt;

    if [ ${IS_ONE_PROJECT} = true ]; then
        BASE_PATH=$( cd ..; pwd; )

        PROJECT_NAME=$(
            find ${BASE_PATH} -name 'Problem'${PROJECT_NO} -type d;
        )
        echo 'add_subdirectory('${PROJECT_NAME}' )' >> ../CMakeLists.txt
    else
        echo "add_subdirectory(Math)" >> ../CMakeLists.txt
        echo "add_subdirectory(Language)" >> ../CMakeLists.txt
    fi

    cmake ../  -DBUILD_SHARED_LIBS=true -DCMAKE_BUILD_TYPE=Debug;
    make -j10;
    make install;

popd;
