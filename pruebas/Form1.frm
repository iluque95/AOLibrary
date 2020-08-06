VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3270
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   5685
   BeginProperty Font 
      Name            =   "Tahoma"
      Size            =   8.25
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   ScaleHeight     =   3270
   ScaleWidth      =   5685
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command4 
      Caption         =   "Close"
      Height          =   375
      Left            =   600
      TabIndex        =   5
      Top             =   2760
      Width           =   975
   End
   Begin VB.Timer Timer1 
      Interval        =   1
      Left            =   4800
      Top             =   1920
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Read"
      Height          =   600
      Left            =   480
      TabIndex        =   3
      Top             =   2040
      Width           =   1590
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Thread"
      Height          =   600
      Left            =   2400
      TabIndex        =   1
      Top             =   2040
      Width           =   1095
   End
   Begin VB.TextBox Text1 
      Height          =   735
      Left            =   480
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   600
      Width           =   3855
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Label1"
      Height          =   195
      Left            =   600
      TabIndex        =   4
      Top             =   1680
      Width           =   3585
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Label1"
      Height          =   195
      Left            =   600
      TabIndex        =   2
      Top             =   1440
      Width           =   3585
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
    
    Private Declare Function QueryPerformanceCounter Lib "kernel32" (lpPerformanceCount As Currency) As Long
    Private Declare Function QueryPerformanceFrequency Lib "kernel32" (lpFrequency As Currency) As Long
     
Private Sub Command4_Click()
End
End Sub

Private Sub Command5_Click()
    MsgBox widestring("HEY")
End Sub

    Private Sub Form_Load()

        
        
        'do your stuff here stuff
        'For i = 1 To 2000000
        '    temp = Sqr(i / 20 * (50 Mod i) ^ 3.333)
        'Next
    
        
        Dim i As Long
    
        
        'MsgBox VarType(i)
        
       Dim cad As String
       
       ''Call testing(cad)
       
        'Data_type cad
       
    End Sub


Sub testing(asd As Variant)
    MsgBox VarType(asd)
End Sub




Private Sub Command2_Click()
    MsgBox thread_creation(AddressOf increment_counter)
End Sub

Private Sub Command3_Click()

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
        
    Label1.Caption = "CRaW fucking DLL: " & Round((cTimer2 - cTimer), 2) & " ms"  'subtract first from second. then divide by freq.
        
    
    Dim Leer As New clsIniManager
    
    
    QueryPerformanceFrequency Freq 'get frequency
    QueryPerformanceCounter cTimer 'get first time
    
    Leer.Initialize ("OBJs.dat")
    
    QueryPerformanceCounter cTimer2 'get second time
        
    Label2.Caption = "ClsIniManager: " & Round((cTimer2 - cTimer), 2) & " ms"  'subtract first from second. then divide by freq.
    
    MsgBox INI_GetString("Hechizos.dat", "HECHIZO45", "Nombre")
    MsgBox INI_GetString("Hechizos.dat", "HECHIZO45", "PalabrasMagicas")
    MsgBox INI_GetString("Hechizos.dat", "HECHIZO999", "PalabrasMagicas"), , "Provocando error"
    
    prueba = INI_GetInteger("OBJs.dat", "INIT", "NumOBJs")
    MsgBox INI_GetString("sarandonga.dat", "INIT", "NumOBJs"), , "Provocando error"
    
    Call INI_MapFile(App.path & "\", "servertorneos.ini")
    
    MsgBox INI_GetString("servertorneos.ini", "MD5Hush", "MD5Aceptado3")
    
    Call INI_UnMapFile("servertorneos.ini")
    
    MsgBox INI_GetString("servertorneos.ini", "MD5Hush", "MD5Aceptado3"), , "Provocando error (Debería estar vacío)"

    
End Sub

Private Sub Timer1_Timer()
    dummy
End Sub
