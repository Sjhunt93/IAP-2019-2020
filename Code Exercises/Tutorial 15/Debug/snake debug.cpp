//
//  IAP.cpp
//  IAPProjectDevelopmentTest1
//
//  Created by Samuel Hunt on 16/07/2018.
//  Copyright (c) 2018 SJHDevelopment. All rights reserved.
//

#include "IAP.h"
#include <iostream>
#include <fstream>


const int COLUMNS = 15;
const int ROWS = 16;

const int MAX_SNAKE_SIZE = 100;
const int MOVE_LEFT = -1;
const int MOVE_RIGHT = -1;
const int MOVE_UP = -1;
const int MOVE_DOWN = 1;
const int NO_MOVEMENT = 0;


void IAP::clearGrid ()
{
    //delete this bvody
    for (int i = 0; i < COLUMNS; i++) {
        aserveSetPixelGrid(i, 0);
    }
}

void IAP::initSnake ()
{
    /*
     Go through and clear each body part
     */
    for (int i = 0; i < MAX_SNAKE_SIZE; i++) {
        snake[i].x = 0;
        snake[i].y = 0;
        snake[i].isActive = false;
    }
    /*
     set snake to start in middle of screen.
     */
    snake[0].x = 4;
    snake[0].y = 4;
    snake[1].x = 5;
    snake[1].y = 4;
    snake[2].x = 6;
    snake[2].y = 4;
    
    snake[0].isActive = true;
    snake[1].isActive = true;
    snake[2].isActive = true;
    
}
void IAP::run ()
{
    
    clearGrid();
    initSnake();
    int snakeSize = 3;
    Body target = getNewTarget();
    
    while (true) {
        drawSnake(target
                  );
        aserveSleep(100); //unsure which way round to have sleep/control for playability..
        
        moveSnake();
        
        //Colision detection.
        Body head = snake[0];
        if (head.x == target.y && head.y == target.y) {
            snake[snakeSize] = target;
            snakeSize++;
            target = getNewTarget();
        }
        
    }
    
    
    
}


void IAP::callbackNoteReceived  (int note, int velocity, int channel)
{
    if (velocity) {
        if (note == 69) { //up
            currentVelocityY = MOVE_UP;
            currentVelocityX = NO_MOVEMENT;
        }
        if (note == 60) { //left
            currentVelocityY = NO_MOVEMENT;
            currentVelocityX = MOVE_LEFT;
            
        }
        if (note == 62) { //down
            currentVelocityY = MOVE_DOWN;
            currentVelocityX = MOVE_LEFT;
        }
        if (note == 64) { //right
            currentVelocityY = NO_MOVEMENT;
            currentVelocityX = MOVE_RIGHT;
        }
        
    }
    
}

void IAP::drawSnake (Body target)
{
    int counter = 0;
    std::array<int, 16> rows = {0};
    while (snake[counter].isActive) {
        
        int x = snake[counter].x;
        int y = snake[counter].y;
        
        rows[y] = rows[y] | (1 << x);
        
        counter++;
    }
    //Same as above but add the target.
    rows[target.y] = rows[target.y] | (1 << target.x);
    
    for (int i = 0; i < ROWS; i++) {
        aserveSetPixelGrid(i, rows[i]);
    }
}
bool IAP::moveSnake ()
{
    Body newPosition = snake[0];
    
    //Perform logical check here.
    newPosition.x += currentVelocityX;
    newPosition.y += currentVelocityY;
    
    //Check the limits...
    if (newPosition.x < 0) {
        newPosition.x += COLUMNS;
    }
    if (newPosition.x >= COLUMNS) {
        newPosition.x -= COLUMNS;
    }
    if (newPosition.y < 0) {
        newPosition.y += ROWS;
    }
    if (newPosition.y >= ROWS) {
        newPosition.y -= ROWS;
    }
    
    //move old snake...
    
    for (int i = snake.size()-1; i > 0; i--) {
        snake[i].x = snake[i-1].x;
        snake[i].y = snake[i-1].y;
    }
    snake[0] = newPosition;
    
    return true;
}
Body IAP::getNewTarget ()
{
    Body b;
    b.x = arc4random() % COLUMNS;
    b.y = arc4random() % ROWS;
    b.isActive = true;
    return b;
}
