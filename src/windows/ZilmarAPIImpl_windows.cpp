#include "GLideN64_Windows.h"
#include "../PluginAPI.h"
#include "../GLideN64.h"
#include "../GLideNUI/GLideNUI.h"
#include "../OpenGL.h"
#include "../Config.h"
#include "../Revision.h"
#include "../framebuffer.h"
#include "../gDP.h"
#include "../RSP.h"

void PluginAPI::DllAbout(/*HWND _hParent*/)
{
	Config_LoadConfig();
	wchar_t strIniFolderPath[PLUGIN_PATH_SIZE];
	api().FindPluginPath(strIniFolderPath);
	RunAbout(strIniFolderPath);
}

void PluginAPI::CaptureScreen(char * _Directory)
{
	video().setCaptureScreen(_Directory);
}

void PluginAPI::DllConfig(HWND _hParent)
{
	Config_DoConfig(/*_hParent*/);
}

void PluginAPI::GetDllInfo(PLUGIN_INFO * PluginInfo)
{
	PluginInfo->Version = 0x103;
	PluginInfo->Type = PLUGIN_TYPE_GFX;
	sprintf(PluginInfo->Name, "%s rev.%s", pluginName, PLUGIN_REVISION);
	PluginInfo->NormalMemory = FALSE;
	PluginInfo->MemoryBswaped = TRUE;
}

void PluginAPI::ReadScreen(void **_dest, long *_width, long *_height)
{
	video().readScreen(_dest, _width, _height);
}

void PluginAPI::FBWrite(unsigned int addr, unsigned int size)
{

}

void PluginAPI::FBWList(FrameBufferModifyEntry *plist, unsigned int size)
{

}

void PluginAPI::FBRead(unsigned int addr)
{

}

typedef struct
{
	u32 addr;
	u32 size;
	u32 width;
	u32 height;
} FrameBufferInfo;

void PluginAPI::FBGetFrameBufferInfo(void *p)
{
	FrameBufferInfo * pinfo = (FrameBufferInfo *)p;
	memset(pinfo, 0, sizeof(FrameBufferInfo) * 6);

	pinfo[0].addr = gDP.colorImage.address;
	pinfo[0].size = gDP.colorImage.size;
	pinfo[0].width = gDP.colorImage.width;
	pinfo[0].height = gDP.colorImage.height;
}
