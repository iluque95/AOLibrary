# C++ Steroids for VB6

Libreria is a library to speed up visual basic 6 limitations.

### **INI Files API**

```cpp
EXPORT void CALLBACK INI_MapFile(char *path, char *file);
EXPORT void CALLBACK INI_UnMapFile(char *file);
EXPORT void CALLBACK INI_Memory2DiskDump();
EXPORT void CALLBACK INI_DumpFile(char *path, char *file);
EXPORT BSTR CALLBACK INI_GetString(char *file, char *key, char *subkey);
EXPORT int32_t CALLBACK INI_GetLong(char *file, char *key, char *subkey);
EXPORT int16_t CALLBACK INI_GetInteger(char *file, char *key, char *subkey);
EXPORT uint8_t CALLBACK INI_GetByte(char *file, char *key, char *subkey);
EXPORT float CALLBACK INI_GetSingle(char *file, char *key, char *subkey);
EXPORT bool CALLBACK INI_GetBoolean(char *file, char *key, char *subkey);
EXPORT void CALLBACK INI_SetValue(char *file, char *key, char *subkey, char *value);
```

```vbnet
Public Declare Sub INI_MapFile Lib "libreria.dll" (ByVal path As String, ByVal file As String)
Public Declare Sub INI_UnMapFile Lib "libreria.dll" (ByVal file As String)
Public Declare Sub INI_Memory2DiskDump Lib "libreria.dll" ()
Public Declare Sub INI_DumpFile Lib "libreria.dll" (ByVal path As String, ByVal file As String)
Public Declare Function INI_GetString Lib "libreria.dll" (ByVal file As String, ByVal key As String, ByVal subkey As String) As String
Public Declare Function INI_GetLong Lib "libreria.dll" (ByVal file As String, ByVal key As String, ByVal subkey As String) As Long
Public Declare Function INI_GetInteger Lib "libreria.dll" (ByVal file As String, ByVal key As String, ByVal subkey As String) As Integer
Public Declare Function INI_GetByte Lib "libreria.dll" (ByVal file As String, ByVal key As String, ByVal subkey As String) As Byte
Public Declare Function INI_GetSingle Lib "libreria.dll" (ByVal file As String, ByVal key As String, ByVal subkey As String) As Single
Public Declare Function INI_GetBoolean Lib "libreria.dll" (ByVal file As String, ByVal key As String, ByVal subkey As String) As Boolean
Public Declare Function INI_SetValue Lib "libreria.dll" (ByVal file As String, ByVal key As String, ByVal subkey As String, ByVal value As String)
```

- ##### INI_MapFile

> Map INI file in to memory using hash tables.

- ##### INI_UnMapFile 

> Free memory unmapping file.

- ##### INI_Memory2DiskDump

> Dump all mapped files in memory to disk.

- ##### INI_DumpFile

> Dump a given mapped file to disk.

- ##### INI_GetString

> Get value in BSTR (vb6 strings).

- ##### INI_GetLong

> Get value casted on to 4 Bytes.

- ##### INI_GetInteger

> Get value casted on to 2 Bytes.

- ##### INI_GetByte

> Get value casted on to 1 Byte.

- ##### INI_GetSingle

> Get value casted on decimal value 4 bytes.

- ##### INI_GetBoolean

> Get value casted on to 1 Byte (true/false).

- ##### INI_SetValue 

> Set value on to mapped file.


### Under investigation

```cpp
EXPORT int CALLBACK path_exist(char *path);
EXPORT int CALLBACK thread_creation(int addr);
EXPORT void CALLBACK Data_type(VARIANT data);
```

- ##### Filesystem

```vbnet
Public Declare Function path_exist Lib "libreria.dll" (ByVal path As String) As Long
```

- ##### Threads

```vbnet
Public Declare Function thread_creation Lib "libreria.dll" (ByVal dir As Long) As Long
```

- ##### Variant data type

```vbnet
Public Declare Sub Data_type Lib "libreria.dll" (ByVal value As Variant)
```