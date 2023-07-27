# CMakeList.txt: DesignPatterns için CMake projesi, kaynağı ekleyin ve tanımlayın
# projeye özgü mantık burada bulunur.
#
cmake_minimum_required(VERSION 3.8)

# Kaynağı bu projenin yürütülebilir dosyasına ekleyin.
add_executable (ChainofResponsibility main.cpp chain.hpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ChainofResponsibility PROPERTY CXX_STANDARD 20)
endif()

# TODO: Gerekirse testleri ve yükleme hedeflerini ekleyin.
