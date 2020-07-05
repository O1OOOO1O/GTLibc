/*Assault cube trainer 1.3.*/
#define GT_BUILD_CLI /*Define this to use GTConsole library.*/
#define GT_USE_SOUND /*Define this to use Sound*/
#include "GTLibc.c"

/*Defining trainer bg and fg colors*/
#define TRAINER_FG FG_LIGHTCYAN
#define TRAINER_BG FG_BLACK

/*@anony enum for enable/disable COLORS options*/
enum
{
    ENABLE_COLOR = FG_LIGHTGREEN | TRAINER_BG,
    DISABLE_COLOR = FG_LIGHTRED | TRAINER_BG,
    STATUS_COLOR = TRAINER_FG | TRAINER_BG
};

/*@anony enum for status options*/
enum
{
    STATUS_ENABLE,
    STATUS_DISABLE
};

LPVOID health_addr = GT_NULL, shield_addr = GT_NULL, pos_addr = GT_NULL,pistol_addr = GT_NULL, clips_addr = GT_NULL, deaths_addr = GT_NULL;
LPSTR status = "Undefined!";
UINT status_type = NIL,status_len = NIL;
/*Global constants for sound paths*/
LPCSTR enable_path = "resources\\enable_sfx.wav",disable_path = "resources\\disable_sfx.wav",loading_path = "resources\\loading_sfx.wav";


BOOL InitGameTrainer();
VOID RunGameTrainer();
VOID ShowStatus(LPSTR,UINT);
BOOL SetUnlimitedHealth();
BOOL SetUnlimitedAmmo();
BOOL SetUnlimitedClips();
BOOL UpdatePosition();
BOOL ResetDeathCount();

int main()
{
    if(InitGameTrainer())
    {
        RunGameTrainer();
    }
    return 0;
}

//initialize game trainer with process ID, handle , base address, weapon address etc.
BOOL InitGameTrainer()
{
    DWORD processID = NIL;
    LPBYTE base_address = NULL;
    HANDLE game_handle = NULL;
    BOOL game_found = FALSE;
    LPCSTR game_name = "ac_client", window_name = "Assault Cube +5 Trainer";

    //Making Assault cube trainer example.
    //Open game and get process id, handle and base address.
    game_handle = GT_FindGameProcess(game_name);
    if (game_handle != NULL)
    {
        /*Set window properties*/

        //set console background color.
        GT_SetConsoleBGColor(TRAINER_BG);

        //Set console windows text.
        GT_SetWindowTitle(window_name);
        GT_SetConsoleTextColor(TRAINER_FG | TRAINER_BG);

        //set console window size.
        GT_ResizeWindow(250, 250,600,485);

        //set console window style.
        GT_DisableWindowStyle(GWL_STYLE, WS_SIZEBOX | WS_MAXIMIZEBOX);

        //remove vertical scroll bar.
        GT_DisableWindowScrollbar(WS_VSCROLL);

        //remove blinking cursor.
        GT_ShowConsoleCursor(FALSE);

        /*Get process ID handle etc*/
        processID = GT_GetProcessID();
        game_handle = GT_GetGameHandle();
        base_address = GT_GetGameBaseAddress(processID);
    }
    //don't check for if game not found because that is handled by Library itself.

    //check for valid process ID and init addresses.
    if (processID != 0)
    {
        game_found = TRUE;

        //example of static pointer.
        LPVOID base_ptr = GT_ReadPointer((LPVOID)0x509B74, sizeof(DWORD));

        //Example of getting address from pointer.
        health_addr = base_ptr + (DWORD)0xF8;
        shield_addr = base_ptr + (DWORD)0xFC;
        pos_addr = base_ptr + (DWORD)0x5C;
        pistol_addr = base_ptr + (DWORD)0x114;
        clips_addr = base_ptr + (DWORD)0x150;
        deaths_addr = base_ptr + (DWORD)0x204;
    }
    return game_found;
}

VOID RunGameTrainer()
{
    /***********************************************/
    /*************ASSAULT-CUBE TRAINER**************/
    /***********************************************/

    //Trainer Menu variables.
    LPCSTR lp_menu_items[] = {"Unlimited Health","Unlimited Ammo","Unlimited Clips","Update Position","Reset deaths","Exit Trainer"};
    LPCSTR lp_hotkey_items[] = {"[F1]\n","[F2]\n","[F3]\n","[F4]\n","[F5]\n","[END]\n"};
    LPCSTR lp_menu_separators[] = {"\t","\t\t","\t\t","\t\t","\t\t","\t\t","\t\t"};
    SIZE_T sz_menu = sizeof(lp_menu_items) / sizeof(lp_menu_items[0]);

    WORD menu_colors[sz_menu],hkey_colors[sz_menu];
    SHORT op_x[sz_menu],op_y[sz_menu];

    /*Co-ordinates of hotkeys options*/
    COORD hkey_coords = {24,2};

    //Fill menu with same options for color and x,y co-ordinates.
    FillMemory(menu_colors,sizeof(menu_colors),ENABLE_COLOR);
    FillMemory(hkey_colors,sizeof(hkey_colors),DISABLE_COLOR);
    FillMemory(op_x,sizeof(op_x),-1);
    FillMemory(op_y,sizeof(op_y),-1);


    //Printing Heading.
    GT_SetConsoleTextColor(TRAINER_FG  | TRAINER_BG);
    GT_WriteConsoleXY(5,0,"ASSAULT-CUBE v1.3 TRAINER\n\n");

    //create Menu items and hotkeys.
    GT_CreateMenu(lp_menu_items,lp_hotkey_items,lp_menu_separators,sz_menu,menu_colors,hkey_colors,op_x,op_y);

    //running main game loop.
    while(TRUE)
    {

        //Applying unlimited money,health and ammo .

        if(GT_IsKeyToggled(VK_F1))
        {
            if(SetUnlimitedHealth())
            {
                status = "[+]Health Enabled!";
                status_type = STATUS_ENABLE;

                //change hotkey COLORS to enable and play enable sound.
                GT_WriteConsoleXY(hkey_coords.X,hkey_coords.Y,"[F1]");
                GT_PlaySound(enable_path,SND_FILENAME | SND_ASYNC);
                GT_StopSound();
            }
        }

        else if(GT_IsKeyToggled(VK_F2))
        {
            if(SetUnlimitedAmmo())
            {
                status = "[+]Ammo Enabled!";
                status_type = STATUS_ENABLE;

                //change hotkey COLORS to enable and play enable sound.
                GT_WriteConsoleXY(hkey_coords.X,hkey_coords.Y + 1,"[F2]");
                GT_PlaySound(enable_path,SND_FILENAME | SND_ASYNC);
            }
        }

        else if(GT_IsKeyToggled(VK_F3))
        {
            if(SetUnlimitedClips())
            {
                status = "[+]Clips Enabled!";
                status_type = STATUS_ENABLE;

                //change hotkey COLORS to enable and play enable sound.
                GT_WriteConsoleXY(hkey_coords.X,hkey_coords.Y + 2,"[F3]");
                GT_PlaySound(enable_path,SND_FILENAME | SND_ASYNC);
            }
        }

        //Applying weapons cheat codes.
        else if(GT_IsKeyToggled(VK_F4))
        {
            if(UpdatePosition())
            {
                status = "[+]Position Updated!";
                status_type = STATUS_ENABLE;

                //change hotkey COLORS to enable and play enable sound.
                GT_WriteConsoleXY(hkey_coords.X,hkey_coords.Y + 3,"[F4]");
                GT_PlaySound(enable_path,SND_FILENAME | SND_ASYNC);
            }
        }

        else if(GT_IsKeyToggled(VK_F5))
        {
            if(ResetDeathCount())
            {

                status = "[+]Death count reset!";
                status_type = STATUS_ENABLE;

                //change hotkey COLORS to enable and play enable sound.
                GT_WriteConsoleXY(hkey_coords.X,hkey_coords.Y + 4,"[F5]");
                GT_PlaySound(enable_path,SND_FILENAME | SND_ASYNC);
            }

        }

        else if(GT_IsKeyToggled(VK_END))
        {
            GT_WriteConsoleXY(0,9,"Trainer created using GTLibc v1.6");
            break;
        }

        //print status info.
        ShowStatus(status,status_type);
    }

}

BOOL SetUnlimitedHealth()
{
    DWORD value = 0x62C80000;
    GT_Write4Bytes(shield_addr, value);
    return GT_Write4Bytes(health_addr, value);
}

BOOL SetUnlimitedAmmo()
{
    DWORD value = 0x7FFFFFFFUL;
    BOOL status = FALSE;
    static DWORD weapons_offsets[] = {0x0,0x4,0x8,0xC,0x10,0x14,0x44};
    size_t offsets_size = sizeof(weapons_offsets);
    status = GT_WriteAddressOffsets(pistol_addr,weapons_offsets,offsets_size,&value,sizeof(DWORD));
    return status;
}

BOOL SetUnlimitedClips()
{
    DWORD value = 0x7FFFFFFFUL;
    return GT_Write4Bytes(clips_addr, value);
}

BOOL UpdatePosition()
{
    FLOAT value = GT_ReadFloat(pos_addr) + 2.5f;
    return GT_WriteFloat(pos_addr, value);
}

BOOL ResetDeathCount()
{
    DWORD value = 0;
    return GT_Write4Bytes(deaths_addr, value);
}

void ShowStatus(LPSTR status,UINT status_type)
{
    UINT sz_status = lstrlen(status);

    if(sz_status > 0)
    {
        if(sz_status < status_len)
        {
            //clear status.
            GT_ClearConsoleText(10,11,status_len);
        }
    }

    //print status static text.
    GT_SetConsoleTextColor(STATUS_COLOR);
    GT_WriteConsoleXY(0,11,"Status : ");

    //print status message.
    (status_type == STATUS_ENABLE) ? GT_SetConsoleTextColor(ENABLE_COLOR) : (status_type == STATUS_DISABLE) ? GT_SetConsoleTextColor(DISABLE_COLOR) : GT_SetConsoleTextColor(TRAINER_FG  | TRAINER_BG );
    GT_WriteConsole("%s",status);

    if(sz_status > 0)
        status_len = sz_status;
}
