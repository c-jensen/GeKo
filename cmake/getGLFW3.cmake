set(glfw_PREFIX "${DEPENDENCIES_PATH}/glfw")
set(glfw_INSTALL_DIR "${DEPENDENCIES_PATH}/glfw")
set(glfw_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${glfw_INSTALL_DIR})   
	   
ExternalProject_Add (
    	glfw
	PREFIX ${glfw_PREFIX}
    	GIT_REPOSITORY "https://github.com/glfw/glfw"
    	GIT_TAG "3.1.1"
	INSTALL_DIR ${glfw_INSTALL_DIR}
    	UPDATE_COMMAND ""
    	INSTALL_COMMAND "" 
	CMAKE_ARGS ${glfw_CMAKE_ARGS}
)

IF (MINGW)

	set(GLFW3_INCLUDE_PATH "${DEPENDENCIES_PATH}/glfw/src/glfw/include")
	set(GLFW3_LIB "${DEPENDENCIES_PATH}/glfw/src/glfw-build/src/libglfw3.a")

ELSEIF (MSVC)

    	set(GLFW3_INCLUDE_PATH "${DEPENDENCIES_PATH}/glfw/src/glfw/include")
	set(GLFW3_LIB "${DEPENDENCIES_PATH}/glfw/src/glfw-build/src/$<CONFIGURATION>/glfw3.lib")

#ELSEIF(APPLE)

    #set(GLFW3_INCLUDE_PATH "${DEPENDENCIES_PATH}/glfw/src/glfw/include")
    #set(GLFW3_LIB "${DEPENDENCIES_PATH}/glfw/src/glfw-build/src/$<CONFIGURATION>/glfw3.lib")

ELSEIF("${CMAKE_SYSTEM}" MATCHES "Linux")
	set(GLFW3_INCLUDE_PATH "${DEPENDENCIES_PATH}/glfw/src/glfw/include")
    	set(GLFW3_LIB "${DEPENDENCIES_PATH}/glfw/src/glfw-build/src/libglfw3.a") 

ELSE()
	set(GLFW3_INCLUDE_PATH "${DEPENDENCIES_PATH}/glfw/src/glfw/include")
	set(GLFW3_LIB "${DEPENDENCIES_PATH}/glfw/src/glfw-build/src/libglfw3.a")
	
ENDIF ()
