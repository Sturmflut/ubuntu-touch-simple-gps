include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(
    Simplegpsbackend_SRCS
    modules/Simplegps/backend.cpp
    modules/Simplegps/gpsdataprovider.cpp
    modules/Simplegps/gpslocationview.cpp
    modules/Simplegps/gpssnrview.cpp
)

add_library(Simplegpsbackend MODULE
    ${Simplegpsbackend_SRCS}
)

set_target_properties(Simplegpsbackend PROPERTIES
         LIBRARY_OUTPUT_DIRECTORY Simplegps)

qt5_use_modules(Simplegpsbackend Gui Qml Quick Location Positioning)

# Copy qmldir file to build dir for running in QtCreator
add_custom_target(Simplegpsbackend-qmldir ALL
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/modules/Simplegps/qmldir ${CMAKE_CURRENT_BINARY_DIR}/Simplegps
    DEPENDS ${QMLFILES}
)

# Install plugin file
install(TARGETS Simplegpsbackend DESTINATION ${QT_IMPORTS_DIR}/Simplegps/)
install(FILES   modules/Simplegps/qmldir DESTINATION ${QT_IMPORTS_DIR}/Simplegps/)

