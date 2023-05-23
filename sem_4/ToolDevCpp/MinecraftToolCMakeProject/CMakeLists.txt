#MAIN
cmake_minimum_required(VERSION 3.22)

project(MinecraftTool)

add_subdirectory(rapidjson)
message("Include Directory: ${rapidjsonIncludeDir}")

add_subdirectory(CommonCode)
message("Inlclude Directory : ${CommonCodeIncludeDir}")

add_subdirectory(MinecraftTool)

target_include_directories(
MinecraftTool
PUBLIC
"${rapidjsonIncludeDir}"
"${CommonCodeIncludeDir}"
)

install(TARGETS MinecraftTool DESTINATION bin)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")

set(CPACK_NSIS_MODIFY_PATH ON)
include(CPack)