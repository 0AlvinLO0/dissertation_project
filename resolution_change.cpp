#include <windows.h>
#include <tchar.h> 
#include <stdio.h> 
using namespace std;
int main()
{
	int cxScreen, cyScreen;
	cxScreen = GetSystemMetrics(SM_CXSCREEN);//get the screen width 
	cyScreen = GetSystemMetrics(SM_CYSCREEN);//get the screen height
	printf("The original screen is %d pixels wide by %d pixels high.\n", cxScreen, cyScreen);

	int a = cxScreen;
	int b = cyScreen;

	DEVMODE DevMode;//define a struct object
	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &DevMode);//get the setting of the original screen

	DevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;//just initialize the width and height
	DevMode.dmPelsWidth = 800;//set width 800 pixel
	DevMode.dmPelsHeight = 600;//set height 600 pixel
	ChangeDisplaySettings(&DevMode, 0);//chage and apply display setting

	_sleep(4 * 1000);//delay 4 seconds

	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &DevMode);
	DevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
	DevMode.dmPelsWidth = a;//set width the width of original screen 
	DevMode.dmPelsHeight = b;//set height the height of original screen 
	ChangeDisplaySettings(&DevMode, 0);//chage and apply display setting
	
	return 0;
}