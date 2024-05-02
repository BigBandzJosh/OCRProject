cmake_minimum_required(VERSION 3.16.3)
project(TesseractApp)


set(CMAKE_CXX_STANDARD 14)
# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(Tesseract REQUIRED tesseract)
pkg_check_modules(LEPT REQUIRED lept)

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

link_directories(/opt/homebrew/opt/tesseract/lib/ /opt/homebrew/opt/leptonica/lib/)

# Link the libraries to your executable
target_link_libraries(Tesseract
        ${Tesseract_LIBRARIES}
        ${LEPT_LIBRARIES}
)
