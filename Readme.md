![cover_logo](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/cover_logo.jpg?raw=true "")

**_GT_**_Libc_ is **[Game Trainer](https://en.wikipedia.org/wiki/Trainer_(games)) library for _c/c++ in windows_** it provides all the necessary methods to make simple game trainer in
windows using **WIN32-API** with ease.
It uses only **WIN32-API** methods instead of **CRT** method because this is intended to work on **Windows** system only
and not shall be portable or to target other OS like **_Linux_,_MAC OS_** etc.

**NOTE** : This ain't memory scanning,hooking,analyzing library, it won't provide methods for scanning/signature or dumping RAW memory.

**AIM** : The aim of this library is only to provide the most efficient way of creating game trainer 
and to provide a layer on top of **WIN-32 API** _cumbersome_ methods and to make reading/writing ,finding Game process easier and convenient.

## Do check our new game-library for Python aswell [GTLibPy](https://github.com/haseeb-heaven/GTLibPy)

# Online Usage licence : 
THIS LIBRARY IS INTENDED TO USE ONLY FOR **_OFFLINE GAMES_** ONLY AND YOU AGREE NOT TO USE THIS FOR **_ONLINE GAMES_** BY ANY MEANS,AND NOT TO CREATE MODS/CHEATS FOR **ONLINE GAMES.**


# Main Components :

## Finding game : 

Using **GT_FindGameProcess()** method.

![finding_game_process](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/finding_game_process.jpg?raw=true "")


Using **GT_FindGameWindow()** method.

![finding_game_window](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/finding_game_window.jpg?raw=true "")


## Reading Values : 

using **GT_ReadAddress()** or **GT_ReadAddressoffset()** methods.

![reading_memory](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/reading_memory.jpg?raw=true "")

## Writing Values : 

using **GT_WriteAddress()** or **GT_WriteAddressOffset()** methods.

![writing_memory](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/writing_memory.jpg?raw=true "")

## Creating Hot-keys :

using **GT_HotKeysPressed()** **_MACRO_** or **GT_IsKeyPressed()/GT_IsKeyToggled()** methods.

![hotkeys](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/hotkeys.jpg?raw=true "")

# Additional Components :

## Applying cheat codes : 

using **GT_SetCheatCode()** method.

![set_cheat_code](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/set_cheat_code.jpg?raw=true "")

## Searching offset area : 

using **GT_SearchOffsetArea()** method.

![search_offset_area](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/search_offset_area.jpg?raw=true "")

# Advanced game hacking methods.

## Injecting Opcode(s) into game : 

using **GT_InjectOpcode()/GT_InjectOpcodes()** method.

![inject_opcode](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/inject_opcode.jpg?raw=true "")

## Injecting Shellcode into game : 

using **GT_InjectShellCode()** method.

![inject_shellcode](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/inject_shellcode.jpg?raw=true "")

## Injecting DLL into game : 

using **GT_InjectDLL()** method.

![inject_dll](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/inject_dll.jpg?raw=true "")

## Automation scripting  : 

using **GT_DoMousePress()** and **GT_DoKeyPress()** methods.


# GTlibc Logs and errors :

## GTConsole Library Error :
If you tried to access methods of **GT**_Console_ library without using MACRO **_GT_BUILD_CLI_** you will get **undefined reference** error.

![gt_console_error](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/gtconsole_error.jpg?raw=true "")


## Error/Exception Handling :

All the error/exception handling is done by library itself like if you tried read or write from **Invalid Memory section** or if process id,game handle/HWND are invalid  it will automatically handle error.So you don't have to check for any error by yourself

![game_not_found](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/game_not_found.jpg?raw=true "")


![reading_invalid_memory](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/reading_invalid_memory.jpg?raw=true "")


![writing_invalid_memory](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/writing_invalid_memory.jpg?raw=true "")


## Methods Accessibility :

All **Public** and **Semi-Public** methods are accessible . But **Private** methods are not and library will throw error if you tried to access them.

![private_method_error](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/private_method_error.jpg?raw=true "")

## Library Logs :

Logs are **disabled** by default but if you want library to maintain logs use **GT_EnableLogs()** method to **enable** logs.
or if you want to **disable** logs again you can use **GT_DisableLogs()** method.

![enable_disable_logs](https://github.com/haseeb-heaven/GTLibc/blob/master/resources/enable_disable_logs.jpg?raw=true "")


# Trainer Demo :
As a demo of this library Assault-Cube Trainer is included to show demo of all the **GT**Libc and **GT**Console methods and how to use them in making simple game trainer.

# GTLibc Tutorial on YouTube :
[![GTLibc Demo](https://img.youtube.com/vi/knJ1l8rhTnw/0.jpg)](https://www.youtube.com/watch?v=knJ1l8rhTnw)

**DOCUMENTATION INFO :**
All Public and Semi-Private methods are well documented.
but private methods are not documented as it was not necessary to do so.

**VERSION INFO :**<br/>
GTLIBC Version : V 1.0  Dated : 23/03/2018.<br/>
GTLIBC Version : V 1.1  Dated : 12/04/2018.<br/>
GTLIBC Version : V 1.2  Dated : 23/04/2018.<br/>
GTLIBC Version : V 1.3  Dated : 12/08/2018.<br/>
GTLIBC Version : V 1.4  Dated : 28/08/2018.<br/>
GTLIBC Version : V 1.5  Dated : 17/10/2019<br/>
GTLIBC Version : V 1.6 Dated : 04/07/2020<br/>
GTLIBC Version : V 1.6.1 Dated : 22/07/2020<br/>

**CHANGE LOGS FOR V 1.1** <br/>
**[+]** Added Custom **_procedure_** injection and **_shellcode_** injection methods for advanced game hacking. <br/>
**[+]** Added Support for Microsoft's visual studio (_MSVC_ compiler) and for **Visual C/CPP**. <br/>
**[+]** Added wrapper memory methods for better Memory management.  <br/>
**[-]** Removed support for Multiple games found in memory. <br/>
**[-]** Removed feature where application used to exit after showing Error. <br/>

**CHANGE LOGS FOR V 1.2** <br/>
**[+]** Added new **Console** UI integrated Library called **GT**_Console_.<br/>
**[+]** Added **GT** Prefix to all methods to differentiate it from regular **WINAPI** Methods.<br/>
**[+]** Time is now calculated from standard MACROS rather than WIN-API time methods. <br/>
**[+]** Added Private Macros **_GT_BUILD_CLI_** for **GT**_Console_ library and **_GT_USE_SOUND_** to use Sound methods.<br/>
**[+]** Changed try-catch prefix as-well to **gt**-_try_-**gt**-_catch_ to differentiate it from regular CPP try-catch.<br/>
**[+]** Improved performance and removed buffer overflows.<br/>

**CHANGE LOGS FOR V 1.3** <br/>
**[+]** Added architecture/machine detection support.<br/>
**[+]** Added 64-bit support for shellcode injection.<br/>
**[+]** Added advanced hacking method DLL injection.<br/>
**[+]** Improved logs detection method.<br/>

**CHANGE LOGS FOR V 1.4** <br/>
**[+]** Added support for reading and writing Float values.<br/>
**[+]** Improved all read/write methods to adapt generic data types.<br/>
**[+]** Added new Macros for NULL and NIL.<br/>

**CHANGE LOGS FOR V 1.5** <br/>
**[+]** Added new **DLL methods** for Injecting **Assembly** code.<br/>
**[+]** Added new macro _GT_BUILD_DLL_ for Advanced DLL Trainers.<br/>
**[+]** Added new method to get **Static** address.<br/>
**[+]** Added support for **64bit** games to _Read/Write_ address.<br/>
**[-]** Moved _GT_ShowInfo_ and _GT_ShowWarning_ to Public methods.<br/>

**CHANGE LOGS FOR V 1.6** <br/>
**[+]** Updated all **Read/Write** methods to take data size manually.<br/>
**[+]** Added new Wrapper methods for basic Read/Write functionality Like **GT_Read4Byte(),GT_Write4Byte(),GT_ReadFloat()** etc.<br/>
**[+]** Added new method **GT_GetProcessModule()** to get all modules of process and to use it enable _GT_USE_PROC_MODULES_ macro.<br/>
**[-]** Removed Automatic data size detection due to **high error rate**.<br/>
**[+]** Added new method to Resume and Suspend Process/Threads  - **GT_SuspendResumeProcess()**<br/>
**[+]** Added new method to detect Game architecture - **GT_Is64bitGame()**<br/>
**[+]** Added Automatic Game and Trainers architecture compatibility - 32Bit trainer can't access 64bit games.<br/>
**[+]** Added new Method to Read/Write single Pointer from address. **GT_ReadPointer()** and **GT_WritePointer()**<br/>
**[+]** Fixed some more errors and cleaned up the code.<br/>


**CHANGE LOGS FOR V 1.6.1** <br/>
**[+]** Support to add **Time based** Logs.<br/>
**[+]** Automatic detection for Elevated process **(Run as Admin)**.<br/>
**[+]** Added Initialize console trainer method in _GT_Console_ library.<br/>
**[+]** Added options to compile _GTLibc_ with _C++_ use _cpp_compile_ folder run batch files.<br/>

**CHANGE LOGS FOR V 1.6.2** <br/>
**[+]** Support to add **Game File based** Logs.<br/>
**[+]** Added options to supress **(Errors and Warnings)**.<br/>
**[+]** Added Static library support check _Dir_ **(static_libs)**.<br/>

written and maintained by _Haseeb_ _Mir_ (haseebmir.hm@gmail.com)
