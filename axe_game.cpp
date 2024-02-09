#include "raylib.h"
#include <valarray>


int main(){
    //window
    int width = 800;
    int height = 450;

    InitWindow(width, height, "Game");

    //circle
    int circle_x = 400;
    int circle_y = 200;
    int radius = 25;

    //circle edges
    int circle_left_edge = circle_x-radius;
    int circle_right_edge = circle_x+radius;
    int circle_top_edge = circle_y-radius;
    int circle_bot_edge = circle_y+radius;

    //axe
    int axe_x = 300;
    int axe_y = 0;
    int axe_len = 50;
    int axe_wid = 50;
    int direction = 10;

    //axe edges
    int axe_left_edge = axe_x;
    int axe_right_edge = axe_x+axe_wid;
    int axe_top_edge = axe_y;
    int axe_bot_edge = axe_y+axe_len;

//collision detection
    bool collision_axe = 
        (axe_bot_edge>=circle_top_edge)
        &&(axe_top_edge<=circle_bot_edge)
        &&(axe_left_edge>=circle_right_edge)
        &&(axe_right_edge<=circle_left_edge);
        

    //game logic
    SetTargetFPS(60);
    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLUE);
        

        if(collision_axe){
            DrawText("Game Over", width/2,height/2,30, ORANGE);
        }else{
            //edge updates
            circle_left_edge = circle_x-radius;
            circle_right_edge = circle_x+radius;
            circle_top_edge = circle_y-radius;
            circle_bot_edge = circle_y+radius;
            axe_left_edge = axe_x;
            axe_right_edge = axe_x+axe_wid;
            axe_top_edge = axe_y;
            axe_bot_edge = axe_y+axe_len;

            //collision update
            collision_axe = 
            (axe_bot_edge>=circle_top_edge)
            &&(axe_top_edge<=circle_bot_edge)
            &&(axe_left_edge<=circle_right_edge)
            &&(axe_right_edge>=circle_left_edge);

            DrawCircle(circle_x,circle_y,radius, RED);

            DrawRectangle(axe_x,axe_y,axe_wid,axe_len, YELLOW);

            //axe movement
            axe_y+=direction;
            if(axe_y>height){
                direction = -direction;
            }
            if(axe_y<0){
                direction = abs(direction);
            }

            if(IsKeyDown(KEY_D) && circle_x<width){
                circle_x+=10;
            }

            if(IsKeyDown(KEY_A) && circle_x>0){
                circle_x-=10;
            }

            if(IsKeyDown(KEY_W) && circle_y>0){
                circle_y-=10;
            }

            if(IsKeyDown(KEY_S) && circle_y<height){
                circle_y+=10;
            }
        }
        
        //game end text
        EndDrawing();
    }
}