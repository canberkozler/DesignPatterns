# CMakeList.txt: DesignPatterns için CMake projesi, kaynağı ekleyin ve tanımlayın
# projeye özgü mantık burada bulunur.
#
cmake_minimum_required(VERSION 3.8)

# Kaynağı bu projenin yürütülebilir dosyasına ekleyin.
add_executable (template main.cpp template.h "${CMAKE_SOURCE_DIR}/Utility/rand.cpp" "${CMAKE_SOURCE_DIR}/Utility/rand.h")

target_include_directories(template PRIVATE "${CMAKE_SOURCE_DIR}/Utility")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET template PROPERTY CXX_STANDARD 20)
endif()

# TODO: Gerekirse testleri ve yükleme hedeflerini ekleyin.
