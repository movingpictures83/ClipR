#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "ClipRPlugin.h"

void ClipRPlugin::input(std::string file) {
 inputfile = file;
readParameterFile(file);
}

void ClipRPlugin::run() {}

void ClipRPlugin::output(std::string file) {
 std::string outputfile = file;
myCommand += "clipR";
myCommand += " ";
addRequiredParameterNoFlag("database");
addRequiredParameterNoFlag("fastafile");
addRequiredParameter("--anchorL", "anchorL");
addRequiredParameter("--seed", "seed");
myCommand += " -e ";
addRequiredParameter("-v", "v");
myCommand += " -o "+outputfile + " ";
std::cout << myCommand << std::endl; 
system(myCommand.c_str());
}

PluginProxy<ClipRPlugin> ClipRPluginProxy = PluginProxy<ClipRPlugin>("ClipR", PluginManager::getInstance());
