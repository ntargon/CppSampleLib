
add_executable(main
    main.cpp
    func.cpp
)

add_subdirectory(lib1)
target_link_libraries(main lib1)