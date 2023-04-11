@echo off

set SDL_VERSION=2.0.16
set SDL_TTF_VERSION=2.0.15
set SDL_IMAGE_VERSION=2.0.5
set SDL_MIXER_VERSION=2.0.4

set SDL_URL=https://www.libsdl.org/release/SDL2-devel-%SDL_VERSION%-mingw.tar.gz
set SDL_TTF_URL=https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-%SDL_TTF_VERSION%-mingw.tar.gz
set SDL_IMAGE_URL=https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-%SDL_IMAGE_VERSION%-mingw.tar.gz
set SDL_MIXER_URL=https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-devel-%SDL_MIXER_VERSION%-mingw.tar.gz

echo Downloading SDL2...
curl -o SDL2-devel-mingw.tar.gz %SDL_URL%

echo Downloading SDL2_ttf...
curl -o SDL2_ttf-devel-mingw.tar.gz %SDL_TTF_URL%

echo Downloading SDL2_image...
curl -o SDL2_image-devel-mingw.tar.gz %SDL_IMAGE_URL%

echo Downloading SDL2_mixer...
curl -o SDL2_mixer-devel-mingw.tar.gz %SDL_MIXER_URL%

echo Done.
