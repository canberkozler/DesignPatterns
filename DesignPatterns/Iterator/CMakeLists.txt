# CMakeList.txt: DesignPatterns i�in CMake projesi, kayna�� ekleyin ve tan�mlay�n
# projeye �zg� mant�k burada bulunur.
#
cmake_minimum_required(VERSION 3.8)

# Kayna�� bu projenin y�r�t�lebilir dosyas�na ekleyin.
add_executable (iterator main.cpp iterator.h)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET iterator PROPERTY CXX_STANDARD 20)
endif()

# TODO: Gerekirse testleri ve y�kleme hedeflerini ekleyin.
