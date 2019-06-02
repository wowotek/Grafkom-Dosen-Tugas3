#include "objects/entities.cpp"
#include "objects/canvas.cpp"

void renderDisplay(void);
void init(void);
void updateScreen(GLint);
void keyboardEvent(unsigned char, int, int);
void mouseEvent(int, int, int, int);
void reshapeEvent(int, int);

Entities persegi   ( 140, 240, 70.00, 1.00, 0.00, 0.00, 0.00);
Entities lingkaran ( 320, 240, 70.00, 0.00, 1.00, 0.00, 1.00);
Entities segi_lima ( 500, 240, 70.00, 0.00, 0.00, 1.00, 2.00);

Canvas canvas;

#define WIDTH 640
#define HEIGHT 480

int main(int argc, char ** argv){
    initGLWindow(
        WIDTH, HEIGHT,
        2880, 540, "BelajarOpenGL-672017282",
        GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE
    );
    init();

    segi_lima.changeRotationDirection(false);

    glutMainLoop();
    return 0;
}

void init(void){
    glutDisplayFunc(renderDisplay);
    glutKeyboardFunc(keyboardEvent);
    glutMouseFunc(mouseEvent);
    glutReshapeFunc(reshapeEvent);

    updateScreen(TO_FPS(120));

    glPointSize(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 480, 0);
}

vec2f ScreenToWorld (vec2f pos)
{
    vec2f res = vec2f(WIDTH, HEIGHT);
    pos = (pos+pos - res) / res.y;
    return vec2f(pos.x, pos.y);
}

vec2f scaleScreenToWorld (vec2f v)
{
    vec2f res = vec2f(WIDTH, HEIGHT);
    v = (v+v) / res;

    return vec2f(v.x, v.y);   
}

void reshapeEvent(int w, int h){
    GLfloat scale = w / h;

    gluOrtho2D(0, scale, 0, 1);
}

void keyboardEvent(unsigned char key, int, int){
    if(key == 'a' || key == 'A'){
        std::cout << "Key '" << key << "' is Pressed" << std::endl;
        
        persegi.changeFillType(0);
        lingkaran.changeFillType(0);
        segi_lima.changeFillType(0);
    } else if (key == 's' || key == 'S') {
        std::cout << "Key '" << key << "' is Pressed" << std::endl;

        persegi.changeFillType(1);
        lingkaran.changeFillType(1);
        segi_lima.changeFillType(1);
    } else if (key == 'd' || key == 'D'){
        std::cout << "Key '" << key << "' is Pressed" << std::endl;

        persegi.changeFillType(2);
        lingkaran.changeFillType(2);
        segi_lima.changeFillType(2);
    }

    glutPostRedisplay();
}

void mouseEvent(int b, int s, int x, int y){
    if(b == 0) {
        // std::cout << "Left Mouse Button is Clicked " << x << " " << y << std::endl;
        canvas.print_all_coordinate();

        if(s == 0){
            canvas.add_coordinate(scaleScreenToWorld(vec2f(x, y)));
        }
    } 
}

void updateScreen(GLint time){
    persegi.update();
    lingkaran.update();
    segi_lima.update();

    glutPostRedisplay();
    glutTimerFunc(time, updateScreen, time);
}

void renderDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);

    persegi.draw();
    lingkaran.draw();
    segi_lima.draw();
    canvas.draw();

    glutSwapBuffers();
}   