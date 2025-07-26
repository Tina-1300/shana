@echo off
IF EXIST build (
    echo Deleting the build folder...
    rmdir /s /q build
    exit
)


echo Creating the build folder...
mkdir build

cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
cmake --install .
