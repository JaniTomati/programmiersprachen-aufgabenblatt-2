# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  vec2.cpp
  mat2.cpp
  circle.cpp
  rectangle.cpp
  )
 
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  m)
add_dependencies(example glfw ${COPY_BINARY})
 
# Build tests
add_executable(tests
  vec2.cpp
  mat2.cpp
  circle.cpp
  rectangle.cpp
  window.cpp
  glew.c
  tests.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES})

# Build clock
add_executable(clock
  window.cpp
  glew.c
  vec2.cpp
  mat2.cpp
  circle.cpp
  rectangle.cpp
  clock.cpp
  )
target_link_libraries(clock
  glfw
  ${GLFW_LIBRARIES})
add_dependencies(example glfw ${COPY_BINARY})

