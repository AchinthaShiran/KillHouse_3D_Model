#pragma once
#include<string>
using namespace std;

extern unsigned int texture[2];

struct BitMapFile {
	int sizeX;
	int sizeY;
	unsigned char* data;
};

BitMapFile* getBmp(string fileName);

void loadExternalTextures();