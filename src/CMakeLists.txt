add_library( src STATIC
            main.c
)

add_subdirectory( fetch )
add_subdirectory( parse )
target_link_libraries( src fetch )
target_link_libraries( src parse )
