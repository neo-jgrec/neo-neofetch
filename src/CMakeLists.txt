add_library( src STATIC
            main.c
)

add_subdirectory( fetch )
target_link_libraries( src fetch )
