// $nombredeproyecto$.cpp: define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"

// INI Manager - CRaW --> 26/05/2020
EXPORT void CALLBACK INI_MapFile(char *path, char *file);
EXPORT void CALLBACK INI_UnMapFile(char *file);
EXPORT void CALLBACK INI_Memory2DiskDump();
EXPORT void CALLBACK INI_DumpFile(char *path, char *file);
EXPORT BSTR CALLBACK INI_GetString(char *file, char *key, char *subkey);
EXPORT int32_t CALLBACK INI_GetLong(char *file, char *key, char *subkey);
EXPORT int16_t CALLBACK INI_GetInteger(char *file, char *key, char *subkey);
EXPORT uint8_t CALLBACK INI_GetByte(char *file, char *key, char *subkey);
EXPORT float CALLBACK INI_GetSingle(char *file, char *key, char *subkey);
EXPORT void CALLBACK INI_SetValue(char *file, char *key, char *subkey, char *value);

EXPORT int CALLBACK path_exist(char *path);
EXPORT int CALLBACK thread_creation(int addr);
EXPORT void CALLBACK Data_type(VARIANT data);