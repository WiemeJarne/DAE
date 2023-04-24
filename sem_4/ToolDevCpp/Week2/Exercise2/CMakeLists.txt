#root folder van de volledige solution

cmake_minimum_required(VERSION 3.22)

project(AssigmentProject)

add_subdirectory(commoncode)
message("Include directory : ${CommondCodeIncludeDir}")
add_subdirectory(tool)
# parameter 1
# welke project heeflt de include directories nodig
# let op : naam van het project zoals gedefinieerd in tool/CMakeLists.txt
# parameter 2
# PUBLIC : zichtbaarheid van header files svoor andere projecten
# parameter 3
# welke subdirectories
target_include_directories(
	Tool PUBLIC
	"${CommonCodeIncludeDir}"
)