add_executable(RayTracing 
    main.cpp
    Colour.cpp
    Hittable.cpp
    HittableList.cpp
    Interval.cpp
    Ray.cpp
    Sphere.cpp
    Vector.cpp

    Colour.h
    Common.h
    Hittable.h
    HittableList.h
    Interval.h
    Ray.h
    Sphere.h
    Vector.h
)
# target_include_directories(Debug PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_link_libraries(Debug PUBLIC box2d)
