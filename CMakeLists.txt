cmake_minimum_required(VERSION 3.21)
project(22_l_asdi_sort_pawlak_ziarek)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(SortApp)
include_directories(SortLib)
include_directories(SortStabilityApp)
include_directories(SortUnitTest)

add_library(SortLib SortLib/SortLib.cpp
        SortLib/InsertionSort.h
        SortLib/BubbleSort.h
        SortLib/MergeSort.h
        SortLib/QuickSort.h)

add_executable(22_l_asdi_sort_pawlak_ziarek
        SortApp/benchmark.h
        SortApp/SortApp.cpp
        SortLib/BubbleSort.h
        SortLib/InsertionSort.h
        SortLib/MergeSort.h
        SortLib/QuickSort.h
        SortLib/SelectionSort.h
        SortLib/ShellSort.h
        SortLib/SortLib.cpp
        )

#Testy
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
if(WIN32)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable( SortUnitTest
        SortUnitTest/InsertionSortUnitTest.cpp
        SortUnitTest/BubbleSortUnitTest.cpp
        SortUnitTest/QuickSortUnitTest.cpp
        SortUnitTest/MergeSortUnitTest.cpp)

target_link_libraries(SortUnitTest PUBLIC gtest_main SortLib)

include(GoogleTest)
gtest_discover_tests(SortUnitTest)
