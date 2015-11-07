//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <ctime>
#include <SDL_ttf.h>

#pragma warning( disable : 4996 )


//Screen dimension constants
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 900;

//Texture wrapper class
class LTexture
{
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image at specified path
	bool loadFromFile(std::string path);

	//Creates image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);

	//Deallocates texture
	void free();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia(char* filename);

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Globally used font
TTF_Font *gFont = NULL;

//Update the time and date
void update_time();

//Scene texture
LTexture gPicTexture3;
LTexture gPicTexture2;
LTexture gPicTexture1;
LTexture gPicTexture0;
LTexture gTextTexture;

LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile(std::string path)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	//Return success
	return mTexture != NULL;
}


void LTexture::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("MyWatch", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia(char* filename0, char* filename1, char* filename2, char* filename3,std::string date)
{
	//Loading success flag
	bool success = true;

	//Open the font
	gFont = TTF_OpenFont("1.ttf", 40);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		//Render text
		SDL_Color textColor = { 0, 0, 0 };
		if (!gTextTexture.loadFromRenderedText(date, textColor))
		{
			printf("Failed to render text texture!\n");
			success = false;
		}
	}

	//Load pic
	if (!(gPicTexture3.loadFromFile(filename1) && gPicTexture2.loadFromFile(filename2) && gPicTexture1.loadFromFile(filename3) && gPicTexture0.loadFromFile(filename0)))
	{
		printf("Failed to load arrow texture!\n");
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	gTextTexture.free();

	//Free global font
	TTF_CloseFont(gFont);
	gFont = NULL;

	//Free loaded images
	gPicTexture0.free();
	gPicTexture1.free();
	gPicTexture2.free();
	gPicTexture3.free();

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

//Angle of rotation
double degrees1 = 0;
double degrees2 = 0;
double degrees3 = 0;
std::string date = "";

Uint32 callback1(Uint32 interval, void *param)
{
	return interval;
}

Uint32 callback2(Uint32 interval, void *param)
{
	if (degrees1 == 360){
		degrees1 = 0;
	}
	degrees1 += 6;
	if (degrees2 == 360){
		degrees2 = 0;
	}
	degrees2 += 0.1;
	return interval;
}

Uint32 callback3(Uint32 interval, void *param)
{
	if (degrees3 == 360){
		update_time();
		degrees3 = 0;
	}
	degrees3 += 0.25;
	return interval;
}

void update_time(){
	time_t now;
	struct tm *fmt;

	time(&now);
	fmt = localtime(&now);

	double sec = fmt->tm_sec;
	double min = fmt->tm_min + sec / 60;
	double h = fmt->tm_hour + min / 60;
	degrees1 = 6 * sec;
	degrees2 = 6 * min;
	degrees3 = h > 12 ? 30 * (h - 12) : 30 * h;
	int mday = fmt->tm_mday;
	int wday = fmt->tm_wday;

	switch (wday)
	{
		//case 0:date[0] = 'S'; date[1] = 'U'; date[2] = 'N'; break;
	case 0:date += "SUN "; break;
	case 1:date += "MON "; break;
	case 2:date += "TUE "; break;
	case 3:date += "WED "; break;
	case 4:date += "THU "; break;
	case 5:date += "FRI "; break;
	case 6:date += "SAT "; break;
	default:
		break;
	}
	date += " ";
	date += '0' + (fmt->tm_mon + 1) / 10;
	date += '0' + fmt->tm_mon + 1 - (fmt->tm_mon + 1) / 10 * 10;
	date += '/';
	date += '0' + mday / 10;
	date += '0' + mday - mday / 10 * 10;
}

int main(int argc, char* args[])
{
	
	update_time();
	SDL_TimerID timer1 = SDL_AddTimer(1000, callback1, NULL);
	SDL_TimerID timer2 = SDL_AddTimer(1000, callback2, NULL);
	SDL_TimerID timer3 = SDL_AddTimer(60000, callback3, NULL);


	if (NULL == timer1 || NULL == timer2 || NULL == timer3)
	{
		SDL_Log("add timer fail: %s\n", SDL_GetError());
	}

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!loadMedia("pan.png","sec.png","min.png","h.png",date))
		{
			printf("Failed to load media!\n");
		}
		else
		{

			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Flip type
			SDL_RendererFlip flipType = SDL_FLIP_NONE;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				if (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}					
				}
				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//Render pic&text
				gPicTexture0.render((SCREEN_WIDTH - gPicTexture0.getWidth()) / 2, (SCREEN_HEIGHT - gPicTexture0.getHeight()) / 2, NULL, 0, NULL, flipType);
				gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, SCREEN_HEIGHT*0.65);
				gPicTexture1.render((SCREEN_WIDTH - gPicTexture1.getWidth()) / 2, (SCREEN_HEIGHT - gPicTexture1.getHeight()) / 2, NULL, degrees3, NULL, flipType);
				gPicTexture2.render((SCREEN_WIDTH - gPicTexture2.getWidth()) / 2, (SCREEN_HEIGHT - gPicTexture2.getHeight()) / 2, NULL, degrees2, NULL, flipType);
				gPicTexture3.render((SCREEN_WIDTH - gPicTexture3.getWidth()) / 2, (SCREEN_HEIGHT - gPicTexture3.getHeight()) / 2, NULL, degrees1, NULL, flipType);
				//Update screen
				SDL_RenderPresent(gRenderer);
			}

		}
	}

	//Free resources and close SDL
	close();

	return 0;
}