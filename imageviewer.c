#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main()
{
    FILE *in = stdin;
    char *pthrowawy = calloc(1000, sizeof(char));
    // Read first line
    fgets(pthrowawy, 1000, in);
    // Read second line
    fgets(pthrowawy, 1000, in);
    free(pthrowawy);
    // Read third line
    char *pdimensions = calloc(1000, sizeof(char));
    fgets(pdimensions, 1000, in);


    const int width = 900;
    const int height = 600;
    SDL_Init(SDL_INIT_VIDEO);
    printf("Hello, World!\n");
    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

    SDL_Rect pixel = (SDL_Rect){0, 0, 1, 1};
    Uint32 color = 0;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Uint8 r, g, b;
            r = (Uint8) getchar();
            g = (Uint8) getchar();
            b = (Uint8) getchar();
            color = SDL_MapRGB(psurface->format, r, g, b);
            pixel.x = x;
            pixel.y = y;
            SDL_FillRect(psurface, &pixel, color);
        }
    }
    SDL_UpdateWindowSurface(pwindow);
    int app_running = 1;
    while (app_running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                app_running = 0;
            }
        }
    }
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
    return 0;
}