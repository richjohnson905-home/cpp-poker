
# Build

    mkdir cmake-build-debug
    cd cmake-build-debug
    conan install ../conanfile.txt
    cmake -G Ninja ..
    ninja