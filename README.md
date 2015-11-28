My master's thesis

# Artificial life simulation in 3D space

## 1. Program

### Building

1. Clone the repo with `git clone  --recursive git@github.com:makkrnic/alsim.git`
1. Compile and install libnoise/utils (if needed)
```
cd alsim/vendor/libnoise
mkdir build
cd build
cmake ..
make && make install
```
1. If installing libnoise in non-default directory update the `src/cmake/Modules/FindLibNoise.cmake` accordingly.
1. Build using cmake and make: `cmake <path to repo>` and make

### Running
run with ./alsim
