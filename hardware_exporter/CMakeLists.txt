cmake_minimum_required(VERSION 3.10)
project(hardware_exporter)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Оптимизации для релизной сборки
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -march=native")

# Включаем режим релиза по умолчанию
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Добавляем исходники
file(GLOB SRC_FILES
    "hardware_exporter/*.cpp"
    "hardware_exporter/*.h"
)

# Создаём исполняемый файл
add_executable(hardware_exporter ${SRC_FILES})
