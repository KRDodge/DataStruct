# CMakeList.txt: DataStruct에 대한 CMake 프로젝트, 여기에 소스를 포함하고
# 프로젝트 특정 논리를 정의합니다.
#
cmake_minimum_required (VERSION 3.8)

# 지원되는 경우 MSVC 컴파일러에 대해 핫 다시 로드 사용하도록 설정합니다.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("DataStruct")

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# src/chapter1 디렉토리 내의 모든 소스 파일 포함
file(GLOB_RECURSE 
CHAPTER1_SOURCES 
CHAPTER2_SOURCES 
CHAPTER3_SOURCES 
CHAPTER4_SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# 프로젝트의 실행 파일 추가
add_executable(${PROJECT_NAME}
    DataStruct.cpp   # main 함수가 있는 파일
    ${CHAPTER1_SOURCES}
    ${CHAPTER2_SOURCES}
    ${CHAPTER3_SOURCES}
    ${CHAPTER4_SOURCES}
 "include/chapter4/DblList.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DataStruct PROPERTY CXX_STANDARD 20)
endif()

# TODO: 필요한 경우 테스트를 추가하고 대상을 설치합니다.
