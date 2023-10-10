if [ -d "./build" ]; then
    echo "Folder exists"
    rm -rf ./build
    mkdir -p ./build
else
    echo "Folder does not exist"
    mkdir -p ./build
fi

cd build
cmake ..
make
cd ..
./demo