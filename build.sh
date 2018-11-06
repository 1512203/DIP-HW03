if [ -d build ]; then
    echo "./build folder already exists!"
else
    mkdir build
fi

cd build
cmake ..
make
