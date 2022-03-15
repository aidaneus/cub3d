# cub3d

> :warning: **This program is implemented under the Mac OS system.**

## Rus

Проект посящен известной 3D-игре Wolfenstein, которая была первой игрой в жанре FPS.

#### Цель:
```
 Цель проекта изучить raycasting, создать динамическое изображение внутри лабиринта. Разобраться с библиотекой mlx.
```
#### Задача:
```
1. Игра должна находиться в отдельном окне, которое может сворачиваться, передвигаться с помощью курсора,
   закрываться на крестик.
2. Стены должны иметь текстуры, которые отличаются в зависимости от распожения(север, юг, восток, запад).
3. Программа должна иметь возможность устанавливать два различных цвета для пола и потолка.
4. Клавиши со стрелками влево и вправо должны позволять игроку смотреть влево и вправо соответственно.
5. Программа должна принимать в качестве первого аргумента файл с расширением .cub - собранная сцена игры
   по выбранной карте.
6. Карта должна состоять только из 6 возможных символов: 0 для пустого места, 1 для стены и N,S,E или W
   для стартовой позиции игрока с указанным видом(на север, на юг, на восток или на запад).
7. Карта должна быть закрыта/окружена стенами(1), иначе программа должна вернуть ошибку.
8. За исключением содержимого карты, каждый тип элемента может быть разделен одним или
   больше пустых строк(0)
9. Карта игры должна располагаться после объявления аргументов.
10. Игра должна подстраиваться под любой тип карты, которая соответствует стандарту.
11. Стандарт загрузки текстур в карте:
    ·NO - северная текстура стены.
    ·SO - южная текстура стены.
    ·WE - западная текстура стены.
    ·EA - восточная текстура стены.
    ·F - цвет пола в формате RGB в диапазоне [0,255]: 0, 255, 255.
    ·C - цвет потолка в фомате RGB в диапазоне [0,255]: 0, 255, 255.
    * после каждого обозначения стены следует расположение файла текстуры(например, ./texture/wall_2.xpm).
```

## Eng

The project is devoted to the famous 3D game Wolfenstein, which was the first game in the FPS genre.

#### The Goal:
```
 The goal of the project is to study raycasting, to create a dynamic image inside the maze. Deal with the mlx library.
```
#### The Task
```
1. The game must be in a separate window that can be minimized, moved with the cursor, closed with a cross.
2. Walls should have textures that differ depending on the location(north, south, east, west).
3. The program must be able to set two different colors for the floor and ceiling.
4. The left and right arrow keys should allow the player to look left and right respectively.
5. The program must take as a first argument a scene description file with the .cub
   extension - the assembled game scene for the selected map.
6. The map must be composed of only 6 possible characters: 0 for an empty space,1 for a wall,
   and N,S,E or W for the player’s start position and spawning orientation.
7. The map must be closed/surrounded(1) by walls, if not the program must return
   an error.
8. Except for the map content, each type of element can be separated by one or
   more empty line(0).
9. The game map must be placed after the declaration of the arguments.
10. The game must adapt to any type of map that meets the standard.
11. Standard for loading textures in the map:
    ·NO - northern wall texture.
    ·SO - southern wall texture.
    ·WE - Western wall texture.
    ·EA - oriental wall texture.
    ·F - floor color in RGB format in the range [0,255]: 0, 255, 255.
    ·C - ceiling color in RGB format in the range [0,255]: 0, 255, 255.
    * each wall designation is followed by the location of the texture file (e.g. ./texture/wall_2.xpm).
```
