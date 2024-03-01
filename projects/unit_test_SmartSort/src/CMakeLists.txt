target_sources(smart_sort_lib 
	PRIVATE
		bubble_sort.cpp
	PUBLIC
		bubble_sort.hpp
)

target_include_directories(smart_sort_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)