cmake_minimum_required(VERSION 3.15) # минимальная версия cmake

project(Meloman VERSION 2.0 LANGUAGES CXX)  # название проекта

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Позиционно-независимый код для DLL
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include_directories(${CMAKE_SOURCE_DIR}/include)

set(DomainSources
  src/domain/AudioContent.cpp
  src/domain/InstrumentalTrack.cpp
  src/domain/MusicDisk.cpp
  src/domain/MusicalComposition.cpp
  src/domain/Song.cpp
)

set(FactorySources
  src/factories/CompositionFactory.cpp
  src/factories/LoggerFactory.cpp
)

set(LoggingSources
  src/logging/FileLogger.cpp
)

set(PresentationSources
  src/presentation/ConsolePresenter.cpp
  src/presentation/FilePresenter.cpp
)

set(DataSourceSources
  src/datasource/DiskStorage.cpp
)

add_library(MusicLibrary SHARED
  ${DomainSources}
  ${FactorySources}
  ${LoggingSources}
  ${DataSourceSources}
)

target_include_directories(MusicLibrary
    PUBLIC ${CMAKE_SOURCE_DIR}/include
    PRIVATE ${CMAKE_SOURCE_DIR}/src
)

if(WIN32)
    target_compile_definitions(MusicLibrary PRIVATE MUSIC_LIBRARY_EXPORTS)
endif()

add_executable(Meloman src/Meloman.cpp ${PresentationSources})

target_link_libraries(Meloman PRIVATE MusicLibrary)

target_include_directories(Meloman PRIVATE ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(gui)
