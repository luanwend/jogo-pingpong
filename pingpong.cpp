#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
 

static GLint windowSizeX = 800, windowSizeY = 1200;
static GLint orthoSizeX = 600, orthoSizeY = 400;
 
static char score_1[20], score_2[20];
static GLint player1_score = 0, player2_score = 0;
static GLint player1_life = 3, player2_life = 3;
static GLint paddle_boundary = 350, paddle_height = 100, paddile_velocity = 10.0;
static GLint player1_paddile_y = 0, player2_paddile_y = 0, paddle_x = 595;
static GLfloat ball_velocity_x = 1, ball_velocity_y = 1, speed_increment = 0.1;
static GLint ball_pos_x = 0, ball_pos_y = 0, ball_radius = 20;
 
void init(void) {
    
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glShadeModel (GL_FLAT);
 
    srand(time(NULL));   
}
 

void drawStrokeText(char*string, int x, int y, int z)
{
    char *c;
    glPushMatrix();
    glTranslatef(x, y+8,z);
    
    for (c=string; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
    }
    glPopMatrix();
}
 

void drawCenterLines() {
   
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , -410);
    glVertex2f(2 , -410);
    glVertex2f(2 , -390);
    glVertex2f(-2 , -390);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , -370);
    glVertex2f(2 , -370);
    glVertex2f(2 , -350);
    glVertex2f(-2 , -350);
    glEnd();
 
    glBegin(GL_QUADS);
   glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , -330);
    glVertex2f(2 , -330);
    glVertex2f(2 , -310);
    glVertex2f(-2 , -310);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , -290);
    glVertex2f(2 , -290);
    glVertex2f(2 , -270);
    glVertex2f(-2 , -270);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , -250);
    glVertex2f(2 , -250);
    glVertex2f(2 , -230);
    glVertex2f(-2 , -230);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , -210);
    glVertex2f(2 , -210);
    glVertex2f(2 , -190);
    glVertex2f(-2 , -190);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , -170);
    glVertex2f(2 , -170);
    glVertex2f(2 , -150);
    glVertex2f(-2 , -150);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , -130);
    glVertex2f(2 , -130);
    glVertex2f(2 , -110);
    glVertex2f(-2 , -110);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , -90);
    glVertex2f(2 , -90);
    glVertex2f(2 , -70);
    glVertex2f(-2 , -70);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , -50);
    glVertex2f(2 , -50);
    glVertex2f(2 , -30);
    glVertex2f(-2 , -30);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , -10);
    glVertex2f(2 , -10);
    glVertex2f(2 , 10);
    glVertex2f(-2 , 10);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , 30);
    glVertex2f(2 , 30);
    glVertex2f(2 , 50);
    glVertex2f(-2 , 50);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , 70);
    glVertex2f(2 , 70);
    glVertex2f(2 , 90);
    glVertex2f(-2 , 90);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , 110);
    glVertex2f(2 , 110);
    glVertex2f(2 , 130);
    glVertex2f(-2 , 130);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , 150);
    glVertex2f(2 , 150);
    glVertex2f(2 , 170);
    glVertex2f(-2 , 170);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , 190);
    glVertex2f(2 , 190);
    glVertex2f(2 , 210);
    glVertex2f(-2 , 210);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , 230);
    glVertex2f(2 , 230);
    glVertex2f(2 , 250);
    glVertex2f(-2 , 250);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , 270);
    glVertex2f(2 , 270);
    glVertex2f(2 , 290);
    glVertex2f(-2 , 290);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , 310);
    glVertex2f(2 , 310);
    glVertex2f(2 , 330);
    glVertex2f(-2 , 330);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , 350);
    glVertex2f(2 , 350);
    glVertex2f(2 , 370);
    glVertex2f(-2 , 370);
    glEnd();
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2 , 390);
    glVertex2f(2 , 390);
    glVertex2f(2 , 410);
    glVertex2f(-2 , 410);
    glEnd();
  
}
 

void drawPaddle(int x, int y) {
    glPushMatrix();
 
    glTranslatef(x, y, 0);
 
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    int height = paddle_height / 2;
    glVertex2f(-5 , height);
    glVertex2f(5 , height);
    glVertex2f(5 , -height);
    glVertex2f(-5, -height);
    glEnd();
 
    glPopMatrix();
}
 
void drawBall(int x, int y) {
    glPushMatrix();
 
    glTranslatef(x, y, 0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidSphere (ball_radius, 20, 16);
 
    glPopMatrix();
}
 

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
 
    drawCenterLines();
 
   
    drawPaddle(-paddle_x, player1_paddile_y);
   
    drawPaddle(paddle_x, player2_paddile_y);
 
  
    drawBall(ball_pos_x, ball_pos_y);
 
    glutSwapBuffers();
    glFlush();
}
 
void startGame(void) {
 
 
    ball_pos_x += ball_velocity_x;
    ball_pos_y += ball_velocity_y;
 
    if (ball_pos_y + ball_radius > orthoSizeY || ball_pos_y - ball_radius < -orthoSizeY)
        ball_velocity_y = -ball_velocity_y;
 
    if (ball_pos_x - ball_radius - 5 < -paddle_x && ball_pos_x - ball_radius < -paddle_x)
        if (ball_pos_y < player1_paddile_y + paddle_height && ball_pos_y > player1_paddile_y - paddle_height) {
            ball_velocity_x = -ball_velocity_x;
            paddile_velocity += speed_increment;
        }
 
 
 
    if (ball_pos_x + ball_radius + 5 > paddle_x && ball_pos_x + ball_radius < paddle_x)
        if (ball_pos_y < player2_paddile_y + paddle_height && ball_pos_y > player2_paddile_y - paddle_height)
            ball_velocity_x = -ball_velocity_x;
 
    
    if (ball_pos_x + ball_radius > orthoSizeX) {
       
        ball_velocity_x = -ball_velocity_x;
    }
 
    
    if (ball_pos_x - ball_radius < -orthoSizeX) {
    
        ball_velocity_x = -ball_velocity_x;
    }
 
    glutPostRedisplay();
}
 

void reshape(int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-orthoSizeX, orthoSizeX, -orthoSizeY, orthoSizeY, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
 

void mouse(int button, int state, int x, int y) {
    switch (button) {
        
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            ball_velocity_x = (rand() % 3) -  (rand() % 1);
            ball_velocity_y = (rand() % 3) -  (rand() % 1);
 
            
            glutIdleFunc(startGame);
            break;
        
        case GLUT_MIDDLE_BUTTON:
            
            ball_pos_x = ball_pos_y = 0;
            player1_paddile_y = player2_paddile_y = 0;
            player1_score = player2_score = 0;
            if (state == GLUT_DOWN)
                
                glutIdleFunc(NULL);
            break;
        default:
        break;
    }
}
 
 
void keyboard (unsigned char key, int x, int y) {
    switch (key) {
       
        case 'w':
            if (player1_paddile_y < paddle_boundary)
                player1_paddile_y += paddile_velocity;
            glutPostRedisplay();
            break;
        
        case 's':
            if (player1_paddile_y > -paddle_boundary)
                player1_paddile_y -= paddile_velocity;
            glutPostRedisplay();
            break;
        
        case 'o':
            if (player2_paddile_y < paddle_boundary)
                player2_paddile_y += paddile_velocity;
            glutPostRedisplay();
            break;
       
        case 'l':
            if (player2_paddile_y > -paddle_boundary)
                player2_paddile_y -= paddile_velocity;
            glutPostRedisplay();
            break;
     
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}
 

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1200, 800);
    glutInitWindowPosition (10, 10);
    glutCreateWindow (argv[0]);
    init ();
 
   
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
 
   
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
