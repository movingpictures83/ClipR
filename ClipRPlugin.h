#ifndef CLIPRPLUGIN_H
#define CLIPRPLUGIN_H

#include "Plugin.h"
#include "Tool.h"
#include "PluginProxy.h"
#include <string>

class ClipRPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "ClipR";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;

};

#endif
