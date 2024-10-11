cmake_minimum_required(VERSION 3.24)
project(Story_game VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

# this copy dat-files to output directory. May be it's not true
configure_file(data/pages.dat ${PROJECT_BINARY_DIR}/data/pages.dat)
configure_file(data/entities.dat ${PROJECT_BINARY_DIR}/data/entities.dat)
configure_file(data/items.dat ${PROJECT_BINARY_DIR}/data/items.dat)
configure_file(data/saves.dat ${PROJECT_BINARY_DIR}/data/saves.dat)

# add include directory
include_directories(${PROJECT_SOURCE_DIR})

# I remove h-files.
add_executable(Story_game main.cpp map/SerializedMap.cpp map/ItemMap.cpp item/Item.cpp GameObject.cpp item/Bauble.cpp item/Weapon.cpp item/Equipment.cpp entity/Entity.cpp entity/Player.cpp Page.cpp map/EntityMap.cpp map/PageMap.cpp)

#add additional inl=clude directory
target_include_directories(Story_game PUBLIC
        "${PROJECT_SOURCE_DIR}"
        "${PROJECT_SOURCE_DIR}/map"
        "${PROJECT_SOURCE_DIR}/item"
        "${PROJECT_SOURCE_DIR}/entity"
        "${PROJECT_SOURCE_DIR}/data"
        )