#pragma once
#include <iostream>

#ifdef GAME_DEBUG 
#define glDebug(X) \
while(glGetError() != GL_NO_ERROR){}\
X; \
while(GLenum err = glGetError() != GL_NO_ERROR) { \
std::cout << "OpenGL error: " << err << " | In file: " << __FILE__ << " | On line: " << __LINE__ << std::endl; \
}

#define gameEngineDebug(X) std::cout << X << std::endl;

#else
#define glDebug(X) X;
#define gameEngineDebug(X);
#endif