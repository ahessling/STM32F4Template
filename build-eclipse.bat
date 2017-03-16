cd..
mkdir STM32F4Template_Eclipse
cd STM32F4Template_Eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_ECLIPSE_VERSION=4.6 -D "CMAKE_TOOLCHAIN_FILE=../STM32F4Template/CMake/GNU-ARM-Toolchain.cmake" ../STM32F4Template/.
