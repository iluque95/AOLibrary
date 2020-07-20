// $nombredeproyecto$.cpp: define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"

// INI Manager - CRaW --> 26/05/2020
EXPORT void CALLBACK INI_MapFile(char *path, char *file);
EXPORT void CALLBACK INI_UnMapFile(char *file);
EXPORT void CALLBACK INI_Memory2DiskDump();
EXPORT void CALLBACK INI_Memory2DiskDumpInBG();
EXPORT void CALLBACK INI_DumpFile(char *path, char *file);
EXPORT void CALLBACK INI_DumpFileInBG(char* path, char* file);
EXPORT BSTR CALLBACK INI_GetString(char *file, char *key, char *subkey);
EXPORT int32_t CALLBACK INI_GetLong(char *file, char *key, char *subkey);
EXPORT int16_t CALLBACK INI_GetInteger(char *file, char *key, char *subkey);
EXPORT uint8_t CALLBACK INI_GetByte(char *file, char *key, char *subkey);
EXPORT float CALLBACK INI_GetSingle(char *file, char *key, char *subkey);
EXPORT bool CALLBACK INI_GetBoolean(char *file, char *key, char *subkey);
EXPORT void CALLBACK INI_SetValue(char *file, char *key, char *subkey, char *value);

// Map Manager - CRaW --> 11/06/2020
EXPORT void CALLBACK MM_ReadMaps(char* path, SAFEARRAY **mapblock);

EXPORT uint16_t CALLBACK MM_NpcsSize();
EXPORT WorldPos CALLBACK MM_GetNpcPos();
EXPORT bool CALLBACK MM_Forward();

EXPORT uint16_t CALLBACK MM_GetNPC(uint64_t encoded);
EXPORT uint16_t CALLBACK MM_GetMap(uint64_t encoded);
EXPORT uint8_t CALLBACK MM_GetX(uint64_t encoded);
EXPORT uint8_t CALLBACK MM_GetY(uint64_t encoded);


EXPORT int CALLBACK path_exist(char *path);
EXPORT int CALLBACK thread_creation(int addr);
EXPORT void CALLBACK Data_type(VARIANT data);