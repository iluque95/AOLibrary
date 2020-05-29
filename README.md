# C++ Steroids for VB6

Libreria is a library to speed up visual basic 6 limitations.

### **INI Files API**

- ##### INI_MapFile

```visualbasic
Public Declare Sub INI_MapFile Lib "libreria.dll" (ByVal path As String, ByVal file As String)
```

> Map INI file in to memory using hash tables.

- ##### INI_UnMapFile 

```visualbasic
Public Declare Sub INI_UnMapFile Lib "libreria.dll" (ByVal file As String)
```

> Free memory unmapping file.

- ##### INI_Memory2DiskDump

```visualbasic
Public Declare Sub INI_Memory2DiskDump Lib "libreria.dll" ()
```

> Dump all mapped files in memory to disk.

- ##### INI_DumpFile

```visualbasic
Public Declare Sub INI_DumpFile Lib "libreria.dll" (ByVal path As String, ByVal File As String)
```

> Dump a given mapped file to disk.

- ##### INI_GetString

```visualbasic
Public Declare Function INI_GetString Lib "libreria.dll" (ByVal File As String, ByVal key As String, ByVal subkey As String) As String
```

> Get value in BSTR (vb6 strings).

- ##### INI_GetLong

```visualbasic
Public Declare Function INI_GetLong Lib "libreria.dll" (ByVal file As String, ByVal key As String, ByVal subkey As String) As Long
```

> Get value casted on to 4 Bytes.

- ##### INI_GetInteger

```visualbasic
Public Declare Function INI_GetInteger Lib "libreria.dll" (ByVal file As String, ByVal key As String, ByVal subkey As String) As Integer
```
> Get value casted on to 2 Bytes.

- ##### INI_GetByte

```visualbasic
Public Declare Function INI_GetByte Lib "libreria.dll" (ByVal file As String, ByVal key As String, ByVal subkey As String) As Byte
```

> Get value casted on to 1 Byte.

- ##### INI_GetSingle

```visualbasic
Public Declare Function INI_GetSingle Lib "libreria.dll" (ByVal file As String, ByVal key As String, ByVal subkey As String) As Single
```

> Get value casted on decimal value 4 bytes.

- ##### INI_SetValue 

```visualbasic
Public Declare Function INI_SetValue Lib "libreria.dll" (ByVal file As String, ByVal key As String, ByVal subkey As String, ByVal Value As String)
```

> Set value on to mapped file.


### Under investigation

- ##### Filesystem

```visualbasic
Public Declare Function path_exist Lib "libreria.dll" (ByVal path As String) As Long
```

- ##### Threads

```visualbasic
Public Declare Function thread_creation Lib "libreria.dll" (ByVal dir As Long) As Long
```

- ##### Variant data type

```visualbasic
Public Declare Sub Data_type Lib "libreria.dll" (ByVal Value As Variant)
```