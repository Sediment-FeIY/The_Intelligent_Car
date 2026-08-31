set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

idf_component_register(
    SRCS 
        "main.c"
    INCLUDE_DIRS 
        "."
)
