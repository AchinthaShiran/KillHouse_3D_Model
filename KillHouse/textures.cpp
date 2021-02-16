#include<math.h>
#include<string>
#include<fstream>
#include<GL/glut.h>
#include "textures.h"

using namespace std;




BitMapFile* getBmp(string fileName) {
	int offSet, headerSize;

	//init Bitmap files from input(RGB) and output(RGBA)
	BitMapFile* bmpRGB = new BitMapFile;
	BitMapFile* bmpRGBA = new BitMapFile;

	//read input from file
	ifstream infile(fileName.c_str(), ios::binary);
	

	//get starting point of image data in bmp file
	infile.seekg(10);
	infile.read((char*)&offSet, 4);

	//get header size of bmp file
	infile.read((char*)&headerSize, 4);
	
	//get image width and height from header
	infile.seekg(18);
	infile.read((char*)&bmpRGB->sizeX, 4);
	infile.read((char*)&bmpRGB->sizeY, 4);

	//det length of 0 byte padding of scanlines
	//each scanline of  a bmp file is a 4-byte aligned by padding wth zeros
	int padding = (3 * bmpRGB->sizeX) % 4 ? 4 - (3 * bmpRGB->sizeX) % 4 : 0;

	//add the padding to determine size of each scanline
	int sizeScanLine = 3 * bmpRGB->sizeX + padding;

	//Allicate storage for image in input bitmap file
	int sizeStorage = sizeScanLine * bmpRGB->sizeY;
	bmpRGB->data = new unsigned char[sizeStorage];

	//read bmp file data into input bitmap file
	infile.seekg(offSet);
	infile.read((char*)bmpRGB->data, sizeStorage);

	//reverse color values from BGR to RGB
	int startScanLine, endScanLineImageData, temp;

	for (int y = 0; y< bmpRGB->sizeY; y++) {
		startScanLine = y * sizeScanLine; //start pos of the yth scanline
		endScanLineImageData = startScanLine + 3 * bmpRGB -> sizeX; // image data excludes padding
		
		for (int x = startScanLine; x < endScanLineImageData; x += 3) {
			temp = bmpRGB->data[x];
			bmpRGB->data[x] = bmpRGB->data[x + 2];
			bmpRGB -> data[x + 2] = temp;
		}
	}

	//set image width and height values and allocate storage for image in output nbitmap file
	bmpRGBA->sizeX = bmpRGB->sizeX;
	bmpRGBA->sizeY = bmpRGB->sizeY;
	bmpRGBA->data = new unsigned char[4 * bmpRGB->sizeX * bmpRGB->sizeY];

	//copy RGB data from input to output bmp files,set output A to 1
	for (int j = 0; j < 4 * bmpRGB->sizeY * bmpRGB->sizeY; j += 4) {
		bmpRGBA->data[j] = bmpRGB->data[(j / 4) * 3];
		bmpRGBA->data[j + 1] = bmpRGB->data[(j / 4) * 3 + 1];
		bmpRGBA->data[j + 2] = bmpRGB->data[(j / 4) * 3 + 2];
		bmpRGBA->data[j + 3] = 0xFF;

	}

	return bmpRGBA;
}
void loadExternalTextures() {
	BitMapFile* image[10];
	image[0] = getBmp("D:/Achi/Uni Notes/3rd Year/Semester ii/CS308/308_Project/KillHouse/asserts/wall.bmp");
	image[1] = getBmp("D:/Achi/Uni Notes/3rd Year/Semester ii/CS308/308_Project/KillHouse/asserts/wall3.bmp");
	image[2] = getBmp("D:/Achi/Uni Notes/3rd Year/Semester ii/CS308/308_Project/KillHouse/asserts/wall2.bmp");
	image[3] = getBmp("D:/Achi/Uni Notes/3rd Year/Semester ii/CS308/308_Project/KillHouse/asserts/wood.bmp");
	image[4] = getBmp("D:/Achi/Uni Notes/3rd Year/Semester ii/CS308/308_Project/KillHouse/asserts/floor.bmp");
	image[5] = getBmp("D:/Achi/Uni Notes/3rd Year/Semester ii/CS308/308_Project/KillHouse/asserts/container1.bmp");
	image[6] = getBmp("D:/Achi/Uni Notes/3rd Year/Semester ii/CS308/308_Project/KillHouse/asserts/outerWall.bmp");
	image[7] = getBmp("D:/Achi/Uni Notes/3rd Year/Semester ii/CS308/308_Project/KillHouse/asserts/metalBars.bmp");
	image[8] = getBmp("D:/Achi/Uni Notes/3rd Year/Semester ii/CS308/308_Project/KillHouse/asserts/woodenBox.bmp");
	image[9] = getBmp("D:/Achi/Uni Notes/3rd Year/Semester ii/CS308/308_Project/KillHouse/asserts/wood2.bmp");

	for (int i = 0; i < 10; i++) {
		glBindTexture(GL_TEXTURE_2D, i);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[i]->sizeX, image[i]->sizeY, 0, GL_RGBA, GL_UNSIGNED_BYTE, image[i]->data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}

}