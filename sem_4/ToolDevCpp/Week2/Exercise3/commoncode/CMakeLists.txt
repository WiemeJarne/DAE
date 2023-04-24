# common code subdirectory
# library --> geen executable
# header only library
add_library(common_code INTERFACE "waypoint.h" "Path.h")
set(CommonCodeIncludeDir "${CMAKE_CURRENT_SOURCE_DIR}" PARENT_SCOPE)