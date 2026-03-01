cmake_minimum_required(VERSION 3.23)

project(ChadaTechClock)

set(HeaderDirectory "include/")
set(HeaderFiles "Clock.h")
list(TRANSFORM HeaderFiles PREPEND ${HeaderDirectory})

set(SourceDirectory "src/")
set(SourceFiles "Main.cpp;Clock.cpp")
list(TRANSFORM SourceFiles PREPEND ${SourceDirectory})

add_executable(ChadaTechClock)

target_sources(
    ChadaTechClock
    PUBLIC
    FILE_SET HEADERS
    BASE_DIRS ${HeaderDirectory}
    FILES ${HeaderFiles}

    PRIVATE
    ${SourceFiles}

)