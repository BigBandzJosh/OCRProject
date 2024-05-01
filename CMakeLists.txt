cmake_minimum_required(VERSION 3.16.3)
project(TesseractApp)


set(CMAKE_CXX_STANDARD 14)
# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(Tesseract tesseract)
pkg_check_modules(LEPT lept)

# Add include directories
include_directories(
        ${Tesseract_INCLUDE_DIRS}
        ${LEPT_INCLUDE_DIRS}
        "/opt/homebrew/opt/tesseract/include"
        "/opt/homebrew/opt/leptonica/include"

)

add_executable(Tesseract
        main.cpp
)

# Link the libraries to your executable
target_link_libraries(Tesseract
        ${Tesseract_LIBRARIES}
        ${LEPT_LIBRARIES}
)
