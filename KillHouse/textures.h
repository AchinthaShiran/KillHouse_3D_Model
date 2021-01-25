#pragma once
#include<string>
using namespace std;


struct BitMapFile {
	int sizeX;
	int sizeY;
	unsigned char* data;
};

BitMapFile* getBmp(string fileName);

void loadExternalTextures();