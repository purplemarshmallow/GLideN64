#ifdef OS_WINDOWS
# include <windows.h>
#else
# include "winlnxdefs.h"
#endif // OS_WINDOWS

#include "PluginAPI.h"

extern "C" {

EXPORT void CALL RomOpen (void)
{
	api().RomOpen();
}

EXPORT void CALL CaptureScreen ( char * Directory )
{
	api().CaptureScreen(Directory);
}

EXPORT void CALL CloseDLL (void)
{
	api().CloseDLL();
}

EXPORT void CALL DllAbout ( HWND hParent )
{
	api().DllAbout(/*hParent*/);
}

EXPORT void CALL DllConfig ( HWND hParent )
{
	api().DllConfig(hParent);
}

EXPORT void CALL DllTest ( HWND hParent )
{
	api().DllTest(hParent);
}

EXPORT void CALL DrawScreen (void)
{
	api().DrawScreen();
}

EXPORT void CALL GetDllInfo ( PLUGIN_INFO * PluginInfo )
{
	api().GetDllInfo(PluginInfo);
}

EXPORT void CALL ReadScreen (void **dest, long *width, long *height)
{
	api().ReadScreen(dest, width, height);
}

EXPORT void CALL FBWrite(unsigned int addr, unsigned int val, unsigned int size)
{
	api().FBWrite(addr, val, size);
}

EXPORT void CALL FBWList(FrameBufferModifyEntry *plist, unsigned int size)
{
	api().FBWList(plist, size);
}

EXPORT void CALL FBRead(unsigned int addr)
{
	api().FBRead(addr);
}

EXPORT void CALL FBGetFrameBufferInfo(void *pinfo)
{
	api().FBGetFrameBufferInfo(pinfo);
}

}
