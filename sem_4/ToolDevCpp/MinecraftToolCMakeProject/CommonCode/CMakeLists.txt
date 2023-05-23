#Common code subdirectory
add_library(CommonCode INTERFACE JsonToObj.h)
set(CommonCodeIncludeDir "${CMAKE_CURRENT_SOURCE_DIR}" PARENT_SCOPE)