
On Linux, use python virtualenv.

    unzip conan-1.58.0.zip as conan_src
    cd conan_src
    pip install -e .


# Build

    mkdir build
    cd build
    conan install ../conanfile.txt
    cmake ..
    cmake --build .