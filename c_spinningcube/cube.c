#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

float a, b, c;
float x, y, z;
float ooz;
int xp, yp;
int idx;

float cubeWidth = 10;
int width = 128;
int height = 40;
int distance = 60;
float k1 = 40;

float zBuffer[128 * 40];
char buffer[128 * 40];
int bgAscii = ' ';
float incrementSpeed = 0.6;

float calcX(int i, int j, int k)
{
	return	j * sin(a) * sin(b) * cos(c) -
			k * cos(a) * sin(b) * cos(c) +
			j * cos(a) * sin(c) +
			k * sin(a) * sin(c) +
			i * cos(b) * cos(c);
}

float calcY(int i, int j, int k)
{
	return	j * cos(a) * cos(c) +
			k * sin(a) * cos(c) -
			j * sin(a) * sin(b) * sin(c) +
			k * cos(a) * sin(b) * sin(c) -
			i * cos(b) * sin(c);
}

float calcZ(int i, int j, int k)
{
	return	k * cos(a) * cos(b) -
			j * sin(a) * cos(b) +
			i * sin(b);
}

void calcSurface(float cubeX, float cubeY, float cubeZ, int ch)
{
	x = calcX(cubeX, cubeY, cubeZ);
	y = calcY(cubeX, cubeY, cubeZ);
	z = calcZ(cubeX, cubeY, cubeZ) + distance;

	ooz = 1 / z;
	xp = (int)(width / 2 + k1 * ooz * x * 2);
	yp = (int)(height / 2 + k1 * ooz * y);

	idx = xp + yp * width;

	if(idx >= 0 && idx < width * height)
	{
		if(ooz > zBuffer[idx])
		{
			zBuffer[idx] = ooz;
			buffer[idx] = ch;
		}
	}
}

int main()
{
	printf("\x1b[2J");

	while(1) {
		memset(buffer, bgAscii, width * height);
		memset(zBuffer, 0, width * height * 4);

		for(float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed)
		{
			for(float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed)
			{
				calcSurface(cubeX, cubeY, -cubeWidth, '#');
				calcSurface(cubeWidth, cubeY, cubeX, '$');
				calcSurface(-cubeWidth, cubeY, -cubeX, '/');
				calcSurface(-cubeX, cubeY, cubeWidth, '.');
				calcSurface(cubeX, -cubeWidth, -cubeY, '~');
				calcSurface(cubeX, cubeWidth, cubeY, '+');
			}
		}
		printf("\x1b[H");

		for(int k = 0; k < width * height; k++)
		{
			putchar(k % width ? buffer[k] : 10);
		}

		a += 0.005;
		b += 0.005;
		usleep(1000);
	}

	return 0;
}

