#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

const int screen_x = 326;
const int screen_y = 580;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

using namespace std;

SDL_Texture *LoadImage(string file)
{
    SDL_Texture *texture = nullptr;
    texture = IMG_LoadTexture(renderer, file.c_str());
    return texture;
}

void show(int x, int y, SDL_Texture *texture, SDL_Renderer *second_renderer)
{
    //Initialize variables and set x and y axis.
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(second_renderer, texture, NULL, &pos);
}

SDL_Texture *Text(SDL_Texture *word,std::string sday,SDL_Renderer * renderer)
{
	TTF_Font *font=nullptr;

	if( TTF_Init() == -1 )
	{
		printf("TTF_OpenFont: Openttf %s\n", TTF_GetError());
	}

	font = TTF_OpenFont("abc.ttf", 38);		//打开一个字体的代码

    if(!font)
    { 
           printf("TTF_OpenFont: Open simsun.ttf %s\n", TTF_GetError());
          
    }

	SDL_Color black = {0,0,0};
	SDL_Surface *text = nullptr;
	text = TTF_RenderText_Blended(font,sday.c_str(),black);
	word = SDL_CreateTextureFromSurface(renderer, text);

	SDL_FreeSurface(text);
	TTF_CloseFont(font);

	if (word!= NULL)
        return word;
}

int main(int argc, char* argv[])
{
    //Initialize variables limited to function 'main'.
    int bW, bH, iW, iH;
	int useClip = 1;
	string tmp[8][4]={{"a","b","c"},{"d","e","f"},{"g","h","i"},{"j","k","l"},{"m","n","o"},
	{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
	string keyboard2b[10]={"0","1","2","3","4","5","6","7","8","9"};

	SDL_Texture *background = nullptr,*word = nullptr,*number = nullptr,*Eng = nullptr;

    //Initialize all of SDL's features; an SDL window and make the window rendable.
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("board", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_x, screen_y, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //Load background images from 'LoadImage' function.

	//载入字母九键和数字键的图片
    background = LoadImage("back.png");
	number = LoadImage("keyboard2.png");
	Eng = LoadImage("keyboard1.png");
    //Clear Render 'renderer'.
    SDL_RenderClear(renderer);

    //Display and tile background image. "background.bmp"
    SDL_QueryTexture(background, NULL, NULL, &bW, &bH);
    show(0, 0, background, renderer);
	show(0, 0, Eng, renderer);

    //Apply renderer to screen.
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
	int x1=7;		
	int count[8] = {0};

	while(useClip)
	{
		SDL_Event event;
		int x,y;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_MOUSEBUTTONDOWN:
					{
						if(event.button.button=SDL_BUTTON_LEFT)
						{
							x=event.button.x;
							y=event.button.y;

							//点击abc所在的键，输出abc
							if((x>bW/5*2)&&(x<bW/5*3)&&(y>390)&&(y<440))
							{
								count[1]=0,count[2]=0,count[3]=0,count[4]=0,
									count[5]=0,count[6]=0,count[7]=0;
								word = Text(word,tmp[0][count[0]],renderer);
								show(x1,225,word,renderer);
								SDL_RenderPresent(renderer);/*更新屏幕*/
								if(count[0]>=2)
									count[0]=0;
								else
									count[0]++;
								
								x1+=14;
							}

							//点击def所在的键，输出def
							if((x>bW/5*3)&&(x<bW/5*4)&&(y>390)&&(y<440))
							{
								count[0]=0,count[2]=0,count[3]=0,count[4]=0,
									count[5]=0,count[6]=0,count[7]=0;
								word = Text(word,tmp[1][count[1]],renderer);
								show(x1,225,word,renderer);
								SDL_RenderPresent(renderer);/*更新屏幕*/
								if(count[1]>=2)
									count[1]=0;
								else
									count[1]++;
								x1+=14;
							}

							//点击ghi所在的键，输出ghi
							if((x>bW/5)&&(x<bW/5*2)&&(y>440)&&(y<490))
							{
								count[0]=0,count[1]=0,count[3]=0,count[4]=0,
									count[5]=0,count[6]=0,count[7]=0;
								word = Text(word,tmp[2][count[2]],renderer);
								show(x1,225,word,renderer);
								SDL_RenderPresent(renderer);/*更新屏幕*/
								if(count[2]>=2)
									count[2]=0;
								else
									count[2]++;
								x1+=14;
							}

							//点击jkl所在的键，输出jkl

							if((x>bW/5*2)&&(x<bW/5*3)&&(y>440)&&(y<490))
							{
								count[0]=0,count[1]=0,count[2]=0,count[4]=0,
									count[5]=0,count[6]=0,count[7]=0;
								word = Text(word,tmp[3][count[3]],renderer);
								show(x1,225,word,renderer);
								SDL_RenderPresent(renderer);/*更新屏幕*/
								if(count[3]>=2)
									count[3]=0;
								else
									count[3]++;
								x1+=14;
							}

							//点击mno所在的键，输出mno
							if((x>bW/5*3)&&(x<bW/5*4)&&(y>440)&&(y<490))
							{
								count[0]=0,count[1]=0,count[2]=0,count[3]=0,
									count[5]=0,count[6]=0,count[7]=0;
								word = Text(word,tmp[4][count[4]],renderer);
								show(x1,225,word,renderer);
								SDL_RenderPresent(renderer);/*更新屏幕*/
								if(count[4]>=2)
									count[4]=0;
								else
									count[4]++;
								x1+=16;
							}

							//点击pqrs所在的键，输出pqrs
							if((x>bW/5)&&(x<bW/5*2)&&(y>490)&&(y<540))
							{
								count[0]=0,count[1]=0,count[2]=0,count[3]=0,
									count[4]=0,count[6]=0,count[7]=0;
								word = Text(word,tmp[5][count[5]],renderer);
								show(x1,225,word,renderer);
								SDL_RenderPresent(renderer);/*更新屏幕*/
								if(count[5]>=3)
									count[5]=0;
								else
									count[5]++;
								x1+=14;
							}

							//点击tuv所在的键，输出tuv
							if((x>bW/5*2)&&(x<bW/5*3)&&(y>490)&&(y<540))
							{
								count[0]=0,count[1]=0,count[2]=0,count[3]=0,
									count[4]=0,count[5]=0,count[7]=0;
								word = Text(word,tmp[6][count[6]],renderer);
								show(x1,225,word,renderer);
								SDL_RenderPresent(renderer);/*更新屏幕*/
								if(count[6]>=2)
									count[6]=0;
								else
									count[6]++;
								x1+=14;
							}

							//点击wxyz所在的键，输出wxyz
							if((x>bW/5*3)&&(x<bW/5*4)&&(y>490)&&(y<540))
							{
								count[0]=0,count[1]=0,count[2]=0,count[3]=0,
									count[4]=0,count[5]=0,count[6]=0;
								word = Text(word,tmp[7][count[7]],renderer);
								show(x1,225,word,renderer);
								SDL_RenderPresent(renderer);/*更新屏幕*/
								if(count[7]>=3)
									count[7]=0;
								else
									count[7]++;
								x1+=14;
							}

							//点击回车键，载入数字键盘
							if((x>bW/5*4)&&(x<bW)&&(y>490)&&(y<590))
							{
								show(0, 0, number, renderer);
								SDL_RenderPresent(renderer);/*更新屏幕*/

								SDL_Event event1;
								int x2,y2;
								int flags=1;
								while(flags)
								{
									while(SDL_PollEvent(&event1))
									{
										switch(event1.type)
										{
											case SDL_MOUSEBUTTONDOWN:
											{
												if(event1.button.button=SDL_BUTTON_LEFT)
												{
													x2=event1.button.x;
													y2=event1.button.y;											

													//点击0所在的键，输出0
													if((x2>bW/5*2)&&(x2<bW/5*3)&&(y2>540)&&(y2<590))
													{
														word = Text(word,keyboard2b[0],renderer);
														show(x1,225,word,renderer);
														SDL_RenderPresent(renderer);/*更新屏幕*/														
														x1+=15;
													}

													//点击1所在的键，输出1
													if((x2>bW/5)&&(x2<bW/5*2)&&(y2>390)&&(y2<440))
													{
														word = Text(word,keyboard2b[1],renderer);
														show(x1,225,word,renderer);
														SDL_RenderPresent(renderer);/*更新屏幕*/														
														x1+=13;
													}

													//点击2所在的键，输出2
													if((x2>bW/5*2)&&(x2<bW/5*3)&&(y2>390)&&(y2<440))
													{
														word = Text(word,keyboard2b[2],renderer);
														show(x1,225,word,renderer);
														SDL_RenderPresent(renderer);/*更新屏幕*/														
														x1+=14;
													}

													//点击3所在的键，输出3
													if((x2>bW/5*3)&&(x2<bW/5*4)&&(y2>390)&&(y2<440))
													{
														word = Text(word,keyboard2b[3],renderer);
														show(x1,225,word,renderer);
														SDL_RenderPresent(renderer);/*更新屏幕*/														
														x1+=14;
													}

													//点击4所在的键，输出4
													if((x2>bW/5)&&(x2<bW/5*2)&&(y2>440)&&(y2<490))
													{
														word = Text(word,keyboard2b[4],renderer);
														show(x1,225,word,renderer);
														SDL_RenderPresent(renderer);/*更新屏幕*/														
														x1+=15;
													}

													//点击5所在的键，输出5
													if((x2>bW/5*2)&&(x2<bW/5*3)&&(y2>440)&&(y2<490))
													{
														word = Text(word,keyboard2b[5],renderer);
														show(x1,225,word,renderer);
														SDL_RenderPresent(renderer);/*更新屏幕*/														
														x1+=15;
													}

													//点击6所在的键，输出6
													if((x2>bW/5*3)&&(x2<bW/5*4)&&(y2>440)&&(y2<490))
													{
														word = Text(word,keyboard2b[6],renderer);
														show(x1,225,word,renderer);
														SDL_RenderPresent(renderer);/*更新屏幕*/														
														x1+=15;
													}

													//点击7所在的键，输出7
													if((x2>bW/5)&&(x2<bW/5*2)&&(y2>490)&&(y2<540))
													{
														word = Text(word,keyboard2b[7],renderer);
														show(x1,225,word,renderer);
														SDL_RenderPresent(renderer);/*更新屏幕*/														
														x1+=15;
													}

													//点击8所在的键，输出8
													if((x2>bW/5*2)&&(x2<bW/5*3)&&(y2>490)&&(y2<540))
													{
														word = Text(word,keyboard2b[8],renderer);
														show(x1,225,word,renderer);
														SDL_RenderPresent(renderer);/*更新屏幕*/														
														x1+=15;
													}

													//点击9所在的键，输出9
													if((x2>bW/5*3)&&(x2<bW/5*4)&&(y2>490)&&(y2<540))
													{
														word = Text(word,keyboard2b[9],renderer);
														show(x1,225,word,renderer);
														SDL_RenderPresent(renderer);/*更新屏幕*/														
														x1+=15;
													}

													//点击数字键盘中的回车键，显示字母键盘，可以输入字母
													if((x2>bW/5*4)&&(x2<bW)&&(y2>490)&&(y2<590))
													{
														show(0, 0, Eng, renderer);
														SDL_RenderPresent(renderer);/*更新屏幕*/
														flags=0;
													}break;
												}
											}
										}
									}
								}
							}
						}
					}
				case SDL_KEYDOWN:
					if(event.key.keysym.sym==SDLK_ESCAPE)
					{
						useClip=0;
					}break;

				case SDL_QUIT:
					{
						useClip=0;
						printf("\n\nquit!\n\n*******\n");
					}break;
			}
		}
	}

	SDL_DestroyTexture(Eng);
	SDL_DestroyTexture(number);
    SDL_DestroyTexture(background);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    //Quit SDL.
    SDL_Quit();

    return 0;
}