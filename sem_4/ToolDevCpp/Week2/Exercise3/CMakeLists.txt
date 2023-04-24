#root folder van de volledige solution

cmake_minimum_required(VERSION 3.22)

project(AssigmentProject)

add_subdirectory(commoncode)
message("Include directory : ${CommondCodeIncludeDir}")
add_subdirectory(staticlibexample)
message("Static Include directory : ${MatrixMathIncludeDir}")
add_subdirectory(tool)

target_include_directories(
	Tool PUBLIC
	"${CommonCodeIncludeDir}"
	"${MatrixMathIncludeDir}"
)

# de naam van het subproject, niet de folder
target_link_libraries(
	Tool PUBLIC MatrixMath
)