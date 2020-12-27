# - Find langX
# Find the native langX includes and library.
# Copy and change from file FindLog4cpp.cmake.
#
#  langX_INCLUDE_DIR - where to find langX.h, etc.
#  langX_LIBRARIES   - List of libraries when using Log4cpp.
#  langX_FOUND       - True if langX found.

# find headers
find_path(langX_INCLUDE_DIR langXSimple.h
  /opt/local/include/langX
  /usr/local/include/langX
  /usr/include/langX
)

# find library
set(langX_NAMES langX)
find_library(langX_LIBRARY
  NAMES ${langX_NAMES}
  PATHS /usr/lib /usr/local/lib /opt/local/lib
)

if (langX_INCLUDE_DIR AND langX_LIBRARY)
  set(langX_FOUND TRUE)
  set(langX_LIBRARIES ${langX_LIBRARY} )
else ()
  set(langX_FOUND FALSE)
  set(langX_LIBRARIES )
endif ()


if (langX_FOUND)
  message(STATUS "Found langX")
  message(STATUS "langX include: ${langX_INCLUDE_DIR}")
  message(STATUS "langX library: ${langX_LIBRARIES}")
else ()
  if (langX_FIND_REQUIRED)
    message(STATUS "Looked for langX libraries named ${langX_NAMES}.")
    message(FATAL_ERROR "Could NOT find langX library")
  endif ()
endif ()

mark_as_advanced(
  langX_LIBRARY
  langX_INCLUDE_DIR
  )
