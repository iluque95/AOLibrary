Attribute VB_Name = "Module1"
Public Declare Function path_exist Lib "C:\Users\Itiel\Desktop\AOLibrary\Release\libreria.dll" (ByVal path As String) As Long
Public Declare Function thread_creation Lib "C:\Users\Itiel\Desktop\AOLibrary\Release\libreria.dll" (ByVal dir As Long) As Long

Public Declare Sub INI_MapFile Lib "C:\Users\Itiel\Desktop\AOLibrary\Release\libreria.dll" (ByVal path As String, ByVal File As String)
Public Declare Sub INI_UnMapFile Lib "C:\Users\Itiel\Desktop\AOLibrary\Release\libreria.dll" (ByVal File As String)
Public Declare Function INI_GetString Lib "C:\Users\Itiel\Desktop\AOLibrary\Release\libreria.dll" (ByVal File As String, ByVal key As String, ByVal subkey As String) As String
Public Declare Function INI_GetLong Lib "C:\Users\Itiel\Desktop\AOLibrary\Release\libreria.dll" (ByVal File As String, ByVal key As String, ByVal subkey As String) As Long
Public Declare Function INI_GetInteger Lib "C:\Users\Itiel\Desktop\AOLibrary\Release\libreria.dll" (ByVal File As String, ByVal key As String, ByVal subkey As String) As Integer
Public Declare Function INI_GetByte Lib "C:\Users\Itiel\Desktop\AOLibrary\Release\libreria.dll" (ByVal File As String, ByVal key As String, ByVal subkey As String) As Byte
Public Declare Function INI_GetSingle Lib "C:\Users\Itiel\Desktop\AOLibrary\Release\libreria.dll" (ByVal File As String, ByVal key As String, ByVal subkey As String) As Single

Public Declare Sub Data_type Lib "C:\Users\Itiel\Desktop\AOLibrary\Release\libreria.dll" (ByVal Value As Variant)

Public Declare Function widestring Lib "C:\Users\Itiel\Desktop\AOLibrary\Release\libreria.dll" (str As String) As String





    Private Declare Function QueryPerformanceCounter Lib "kernel32" (lpPerformanceCount As Currency) As Long
    Private Declare Function QueryPerformanceFrequency Lib "kernel32" (lpFrequency As Currency) As Long

Public counter As Long

Public Sub increment_counter(ByVal Value As Long)
    counter = counter + Value
    Form1.Label1.Caption = "Counter: " & counter
End Sub

Public Sub dummy()
    Static var As Long
    var = var + 1
    
     Call INI_MapFile(App.path & "\", "Hechizos.dat")
    
            Dim cTimer As Currency
        Dim cTimer2 As Currency
        Dim Freq As Currency
        
        Dim i As Long
        Dim temp As Double
        
        QueryPerformanceFrequency Freq 'get frequency
        QueryPerformanceCounter cTimer 'get first time
    
    
    Call INI_MapFile(App.path & "\", "OBJs.dat")
    
     QueryPerformanceCounter cTimer2 'get second time
        
    Form1.Label1.Caption = "CRaW fucking DLL: " & Round((cTimer2 - cTimer), 2) & " ms"  'subtract first from second. then divide by freq.
        
    
    Dim Leer As New clsIniManager
    
    
    QueryPerformanceFrequency Freq 'get frequency
    QueryPerformanceCounter cTimer 'get first time
    
    Leer.Initialize ("OBJs.dat")
    
    QueryPerformanceCounter cTimer2 'get second time
        
    Form1.Label2.Caption = "ClsIniManager: " & Round((cTimer2 - cTimer), 2) & " ms"  'subtract first from second. then divide by freq.
    
    Dim str As String
    
    str = INI_GetString("Hechizos.dat", "HECHIZO45", "Nombre")
    str = INI_GetString("Hechizos.dat", "HECHIZO45", "PalabrasMagicas")
    str = INI_GetString("Hechizos.dat", "HECHIZO999", "PalabrasMagicas")
    
    i = INI_GetInteger("OBJs.dat", "INIT", "NumOBJs")
    str = INI_GetString("sarandonga.dat", "INIT", "NumOBJs")
    
    Call INI_MapFile(App.path & "\", "servertorneos.ini")
    
    str = INI_GetString("servertorneos.ini", "MD5Hush", "MD5Aceptado3")
    
    Call INI_UnMapFile("servertorneos.ini")
    
    str = INI_GetString("servertorneos.ini", "MD5Hush", "MD5Aceptado3")
    
End Sub
