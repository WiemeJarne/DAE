# staticlibexample sub directory
add_library(MatrixMath "FMatrix.h" "FMatrix.cpp")
# cmake current source dir : <root_dir>/staticlibexample
set(MatrixMathIncludeDir "${CMAKE_CURRENT_SOURCE_DIR}" PARENT_SCOPE)