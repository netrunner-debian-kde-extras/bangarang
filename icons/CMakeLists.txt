PROJECT(Bangarang)

set( CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules )

FIND_PACKAGE(KDE4 REQUIRED)

INCLUDE(KDE4Defaults)

ADD_DEFINITIONS( ${QT_DEFINITIONS} ${KDE4_DEFINITIONS} )

kde4_install_icons( ${ICON_INSTALL_DIR}   )
