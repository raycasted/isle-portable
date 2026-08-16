#include "config.h"

#include <SDL3/SDL_log.h>
#include <iniparser.h>

void OGXB_SetupDefaultConfigOverrides(dictionary* p_dictionary)
{
	SDL_Log("Overriding default config for Original XBOX");
	// D: is where the disk drive is on the Original XBOX (TODO: change this so you can run it off HDD?)
	iniparser_set(p_dictionary, "isle:diskpath", "D:\\isle\\DATA\\disk");
	iniparser_set(p_dictionary, "isle:cdpath", "D:\\isle");

	// Enable cursor by default
	iniparser_set(p_dictionary, "isle:Draw Cursor", "true");
	iniparser_set(p_dictionary, "isle:Anisotropic", "1");
	iniparser_set(p_dictionary, "isle:MSAA", "1");
	iniparser_set(p_dictionary, "isle:savepath", "E:\\UDATA\\isle");
	// 0x2 "software" and 0x7 "palettesw" work
	iniparser_set(p_dictionary, "isle:3D Device ID", "0 0x682656f3 0x0 0x0 0x2000000");
	iniparser_set(p_dictionary, "isle:Full Screen", "true");
	iniparser_set(p_dictionary, "isle:Exclusive Full Screen", "false");
	iniparser_set(p_dictionary, "isle:Horizontal Resolution", "640");
	iniparser_set(p_dictionary, "isle:Vertical Resolution", "480");
	iniparser_set(p_dictionary, "isle:Island Quality", "1");
	iniparser_set(p_dictionary, "isle:Island Texture", "0");
	iniparser_set(p_dictionary, "isle:Max LOD", "0.000000");
	iniparser_set(p_dictionary, "isle:Frame Delta", "16.66667"); // this gets casted to int anyway...
	iniparser_set(p_dictionary, "isle:Display Bit Depth", "16");

}
