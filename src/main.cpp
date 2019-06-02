#include "objects/entities.cpp"

void renderDisplay(void);
void init(void);
void updateScreen(GLint);
/*
Entities   persegi(-0.5, 0, 0.15, 1, 0, 0, 0);
Entities lingkaran(0, 0, 0.15, 0, 1, 0, 1);
Entities segi_lima(0.5, 0, 0.15, 0, 0, 1, 2);
*/
int width = 1280, height = 720;
float aspect = 1.0;


#include <vector>

template <typename T>
struct tvec2
{
    T x, y;

    tvec2(void) = default;
    tvec2(T s): x(s), y(s) {}
    tvec2(T x, T y): x(x), y(y) {}


    void operator+=(tvec2<T> other)
    {
        x += other.x;
        y += other.y;
    }

    void operator-=(tvec2<T> other)
    {
        x -= other.x;
        y -= other.y;
    }

    void operator*=(tvec2<T> other)
    {
        x *= other.x;
        y *= other.y;
    }

    void operator/=(tvec2<T> other)
    {
        x /= other.x;
        y /= other.y;
    }


    tvec2<T> operator+(tvec2<T> other)
    {
        return tvec2<T>(x + other.x, y + other.y);
    }

    tvec2<T> operator-(tvec2<T> other)
    {
        return tvec2<T>(x - other.x, y - other.y);
    }

    tvec2<T> operator*(tvec2<T> other)
    {
        return tvec2<T>(x * other.x, y * other.y);
    }

    tvec2<T> operator/(tvec2<T> other)
    {
        return tvec2<T>(x / other.x, y / other.y);
    }

    tvec2<T> operator+(T other)
    {
        return tvec2<T>(x + other, y + other);
    }

    tvec2<T> operator-(T other)
    {
        return tvec2<T>(x - other, y - other);
    }

    tvec2<T> operator*(T other)
    {
        return tvec2<T>(x * other, y * other);
    }

    tvec2<T> operator/(T other)
    {
        return tvec2<T>(x / other, y / other);
    }
};

template <typename T>
tvec2<T> operator+(T a, tvec2<T> b)
{
    return tvec2<T>(a + b.x, a + b.y);
}

template <typename T>
tvec2<T> operator-(T a, tvec2<T> b)
{
    return tvec2<T>(a - b.x, a - b.y);
}

template <typename T>
tvec2<T> operator*(T a, tvec2<T> b)
{
    return tvec2<T>(a * b.x, a * b.y);
}

template <typename T>
tvec2<T> operator/(T a, tvec2<T> b)
{
    return tvec2<T>(a / b.x, a / b.y);
}

template <typename T>
T length(tvec2<T> v)
{
    return sqrt(v.x*v.x + v.y*v.y);
}

template <typename T>
tvec2<T> normalize (tvec2<T> v)
{
    return v / length(v);
}

template <typename T>
T distance (tvec2<T> a, tvec2<T> b)
{
    return length(a - b);
}

typedef tvec2<float> vec2;



const float G = 6.67408 * 10e-11;

struct Body
{
    vec2 position;
    vec2 velocity;
    float radius;

    Body(void) = default;
};

std::vector<Body> bodies;


int main(int argc, char ** argv){
    initGLWindow(width, height, 2880, 540, "BelajarOpenGL-672017282", GLUT_DOUBLE | GLUT_RGB | GLUT_ACCUM);
    aspect = (float)width / (float)height;

    int auxBufferCount;
    glGetIntegerv(GL_AUX_BUFFERS, &auxBufferCount);
    printf("%d\n", auxBufferCount);

    init();

/*
    segi_lima.changeRotationDirection(false);
*/
    glutMainLoop();

    return 0;
}

void mouseFunc(int, int, int, int);
void motionFunc(int, int);

vec2 ScreenToWorld (vec2 pos)
{
    vec2 res = vec2(width, height);
    pos = (pos+pos - res) / res.y;
    return vec2(pos.x, -pos.y);
}

vec2 scaleScreenToWorld (vec2 v)
{
    vec2 res = vec2(width, height);
    v = (v+v) / res;
    return vec2(v.x, -v.y);   
}

void init(void){
    glutMotionFunc(motionFunc);
    glutDisplayFunc(renderDisplay);
    glutMouseFunc(mouseFunc);
    updateScreen(TO_FPS(120));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-aspect, aspect, -1.0, 1.0);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClearAccum(0.0, 0.0, 0.0, 1.0);
}

int buttonPressed = false;
int mouseX, mouseY;

void mouseFunc (int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        buttonPressed = true;
    } else 
    {
        buttonPressed = false;
    }
}

void motionFunc(int x, int y)
{
    mouseX = x;
    mouseY = y;
}

float fDeltaTime = 0.0f;
float fLastTime = 0.0f;
float fTime = 0.0f;

void updateScreen(GLint time) {
    
    if (buttonPressed)
    {
        Body body;
        body.position = ScreenToWorld(vec2(mouseX,mouseY));
        body.velocity = vec2(0,0);
        body.radius = 0.005f;
        bodies.push_back(body);
    }
/*
    persegi.update();
    lingkaran.update();
    segi_lima.update();
*/
    int tick = glutGet(GLUT_ELAPSED_TIME);

    fTime = (float)tick / 1000.0f;
    fDeltaTime = fTime - fLastTime;
    fLastTime = fTime;

    //printf("%f\n", fDeltaTime);

    float density = 1000000000.0f;

    for (unsigned int i = 0; i < bodies.size(); ++i)
    {
        vec2 a = vec2(0);
        for (unsigned int j = 0; j < bodies.size(); ++j)
        {
            if (i == j) continue;

            vec2 p1 = bodies[i].position;
            vec2 p2 = bodies[j].position;
            float r1 = bodies[i].radius;
            float r2 = bodies[j].radius;
            float v1 = 4.0f * M_PI * (r1*r1);
            float v2 = 4.0f * M_PI * (r2*r2);    
            float m1 = r2 * density;
            float m2 = v2 * density;

            float r = distance(p1, p2);

            vec2 u = normalize(p2 - p1);
            vec2 F = G * ((m1 * m2) / (r*r)) * u;

            a += F / m1;
        }

        bodies[i].velocity += a * fDeltaTime;
        bodies[i].position += bodies[i].velocity * fDeltaTime;
    }

    for (unsigned int i = 0; i < bodies.size(); ++i)
    {
        for (unsigned int j = 0; j < bodies.size(); ++j)
        {
            if (i == j) continue;

            vec2 p1 = bodies[i].position;
            vec2 p2 = bodies[j].position;
            float r1 = bodies[i].radius;
            float r2 = bodies[j].radius;
            float vol1 = 4.0f * M_PI * (r1*r1);
            float vol2 = 4.0f * M_PI * (r2*r2);
            vec2 vel1 = bodies[i].velocity;
            vec2 vel2 = bodies[j].velocity;    
            float m1 = vol1 * density;
            float m2 = vol2 * density;

            float r = distance(p1, p2);

            if (r > r1 + r2) continue;

            float volTotal = vol1 + vol2;
            float rTotal = sqrt(volTotal / 4.0f / M_PI);
            float mTotal = volTotal * density;

            Body body;
            body.radius = rTotal;
            
            {
                vec2 apm = p1 * m1;
                vec2 bpm = p2 * m2;
                vec2 avg_pos = apm + bpm;
                body.position = avg_pos / mTotal;
            }
            {
                vec2 avm = vel1 * m1;
                vec2 bvm = vel2 * m2;
                vec2 avg_vel = avm + bvm;
                body.velocity = avg_vel / mTotal;
            }

            bodies[i] = body;
            
            bodies.erase(bodies.begin() + j);
        }
    }    


    /*

    rect(-0.5f, -0.5f, 1.0f, 1.0f);
*/
    glutPostRedisplay();
    glutTimerFunc(time, updateScreen, time);
}

void ActualDraw (float deltaTime)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    for (unsigned int i = 0; i < bodies.size(); ++i)
    {
        //float s = .2f / length(bodies[i].velocity);
        glColor3f(1.0f, 1.0f, 1.0f);
    
        circle(bodies[i].position.x + bodies[i].velocity.x * deltaTime,
               bodies[i].position.y + bodies[i].velocity.y * deltaTime,
               bodies[i].radius);
    }
}

void DrawAntialised (float deltaTime)
{
    //glClear(GL_ACCUM_BUFFER_BIT);

    unsigned int uIterAA = 2;
    for(unsigned int x = 0; x < uIterAA; ++x)
    {
        for(unsigned int y = 0; y < uIterAA; ++y)
        {
            glPushMatrix();
            vec2 delta = scaleScreenToWorld( 1.0f / (vec2(x, y) + 0.5f) );
            glTranslatef(delta.x, delta.y, 0.0f);


            glClear(GL_COLOR_BUFFER_BIT);
            ActualDraw(deltaTime);
            
            glPopMatrix();

            unsigned int n = uIterAA * uIterAA;
            
            glReadBuffer(GL_FRONT);
            glDrawBuffer(GL_BACK);
            glAccum(GL_ACCUM, 1.0 / n);
            glDrawBuffer(GL_FRONT);
        }
    }

    //glAccum(GL_RETURN, 1.0);
    //glFlush();
}

void renderDisplay(void) {

    width = glutGet(GLUT_WINDOW_WIDTH);
    height = glutGet(GLUT_WINDOW_HEIGHT);

    aspect = (float)width / (float)height;

    glLoadIdentity();

    glClear(GL_ACCUM_BUFFER_BIT);

    unsigned int uMotionBlurSamples = 4;
    float fMotionBlurFPS = 60.0f;
    float fMotionBlurDeltaTime = 1.0f / fMotionBlurFPS;

    for (unsigned int i = 0; i < uMotionBlurSamples; ++i)
    {
        unsigned int uIterAA = 2;
        for(unsigned int x = 0; x < uIterAA; ++x)
        {
            for(unsigned int y = 0; y < uIterAA; ++y)
            {
                glPushMatrix();
                gluOrtho2D(-aspect, aspect, -1.0, 1.0);
                vec2 delta = scaleScreenToWorld( (vec2(x, y) + 0.5f)/vec2(uIterAA) );
                glTranslatef(delta.x, delta.y, 0.0f);

                ActualDraw( -fMotionBlurDeltaTime * (float)(i + 1) / (float) uMotionBlurSamples );
                
                glPopMatrix();




                unsigned int n = uIterAA * uIterAA;
                
                glReadBuffer(GL_BACK);
                glDrawBuffer(GL_BACK);
                glAccum(GL_ACCUM, 1.0 / (n * uMotionBlurSamples) );
            }
        }
    }

    glAccum(GL_RETURN, 1.0);
    glFlush();

/*
    glClear(GL_ACCUM_BUFFER_BIT);

    unsigned int uMotionBlurSamples = 8;
    float fMotionBlurFPS = 24.0f;
    float fMotionBlurDeltaTime = 1.0f / fMotionBlurFPS;

    for (unsigned int i = 0; i < uMotionBlurSamples; ++i)
    {
        ActualDraw( -fMotionBlurDeltaTime * (float)(i + 1) / (float)uMotionBlurSamples );

        glReadBuffer(GL_FRONT);
        glDrawBuffer(GL_BACK);
        glAccum (GL_ACCUM, 1.0 / (double) uMotionBlurSamples);
        glDrawBuffer(GL_FRONT);
    }

    glAccum(GL_RETURN, 1.0);
    glFlush();
*/
    glutSwapBuffers();
}   