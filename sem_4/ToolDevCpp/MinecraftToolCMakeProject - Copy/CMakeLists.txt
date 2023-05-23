# MAIN
cmake_minimum_required(VERSION 3.22)

project(MinecraftJson)

add_subdirectory(rapidjson)
message("Include Directory: ${RapidJsonIncludeDir}")

add_subdirectory(commoncode)
message("Include Directory: ${CommonCodeIncludeDir}")

add_subdirectory(MinecraftJsonConsole)
target_include_directories(MinecraftJsonConsole PUBLIC ${RapidJsonIncludeDir})
target_include_directories(MinecraftJsonConsole PUBLIC ${CommonCodeIncludeDir})

install(TARGETS MinecraftJsonConsole DESTINATION bin)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")

set(CPACK_NSIS_MODIFY_PATH ON)
include(CPack)