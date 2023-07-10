# CMakeList.txt: DesignPatterns için CMake projesi, kaynaðý ekleyin ve tanýmlayýn
# projeye özgü mantýk burada bulunur.
#
cmake_minimum_required(VERSION 3.8)

# Kaynaðý bu projenin yürütülebilir dosyasýna ekleyin.
add_executable (state main.cpp state.h)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET state PROPERTY CXX_STANDARD 20)
endif()

# TODO: Gerekirse testleri ve yükleme hedeflerini ekleyin.
