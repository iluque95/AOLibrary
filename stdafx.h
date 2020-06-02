// stdafx.h: archivo de inclusión de los archivos de inclusión estándar del sistema
// o archivos de inclusión específicos de un proyecto utilizados frecuentemente,
// pero rara vez modificados
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Excluir material rara vez utilizado de encabezados de Windows
#define EXPORT __declspec( dllexport )
#define MSGBOX(x) \
{ \
   std::ostringstream oss; \
   oss << x; \
   MessageBoxA(0,oss.str().c_str(), "Alerta !!", MB_OK | MB_ICONQUESTION); \
}

// Archivos de encabezado de Windows:
#include <windows.h>
#include <filesystem>
#include <sstream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <thread>
#include <chrono>
#include <OAIdl.h>

namespace fs = std::filesystem;

std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<std::string, std::string> > > mapped_file;

bool isRunning = false;

void free_memory();