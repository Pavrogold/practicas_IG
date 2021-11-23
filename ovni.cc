#include "ovni.h"
#include <iostream>

Ovni::Ovni()
{
    cabina = new Esfera(30, 30, 30);
    cuerpo = new Cono(30, 30, 70, 100, true);
    abductor = new Cono(10, 10, 30, 20, false);

    Material gris({0.4, 0.5, 0.4, 1.0}, {1.0, 1.0, 1.0, 1.0}, {0.0, 0.05, 0.0, 1.0}, 100);
    Material negro({0.2775, 0.2775, 0.2775, 1.0}, {0.773911, 0.773911, 0.773911, 1.0}, {0.23125, 0.23125, 0.23125, 1.0}, 100);

    cabina->setMaterial( gris );
    cuerpo->setMaterial( negro );
    abductor->setMaterial( negro );

}

void Ovni::draw()
{
    cuerpo->draw();

    glPushMatrix();
        glTranslatef(0, 50, 0);
        cabina->draw();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, -10, 0);
        abductor->draw();
    glPopMatrix();

    glPushMatrix();
        glRotatef(r_luces, 0, 1, 0);
        luces.draw();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, h_gancho+80, 0);
        glRotatef(180, 1, 0, 0);
        inferior.draw();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, -h_ballena_max*ctr_ballena/ctr_ballena_max, 0.0);
        glScalef(escalado_max*ctr_ballena/ctr_ballena_max, escalado_max*ctr_ballena/ctr_ballena_max, escalado_max*ctr_ballena/ctr_ballena_max);
        glRotatef(y_ballena, 0, 1, 0);
        glRotatef(x_ballena, 0, 0, 1);
        glRotatef(-10, 1, 0, 0);
        laboon.draw();
    glPopMatrix();

}

void Ovni::aumentar_r_luces(float aumento)
{
    r_luces += aumento;
}

void Ovni::aumentar_foco_x(float aumento)
{
    inferior.aumentar_foco_x(aumento);
}

void Ovni::aumentar_foco_y(float aumento)
{
    inferior.aumentar_foco_y(aumento);
}

void Ovni::aumentar_h_gancho(float aumento)
{
    h_gancho += aumento;

    if (aumento + h_gancho > max_h_gancho)
        h_gancho = max_h_gancho;
    else if (aumento + h_gancho < min_h_gancho)
        h_gancho = min_h_gancho;

}

void Ovni::aumentar_ballena(float aumento)
{
    ctr_ballena += aumento;

    if (ctr_ballena > ctr_ballena_max)
        ctr_ballena = ctr_ballena_max;
    else if (ctr_ballena < 0)
        ctr_ballena = 0;
}

void Ovni::aumentar_ballena_x(float aumento)
{
    x_ballena += aumento;

    if (x_ballena > x_ballena_max)
        x_ballena = x_ballena_max;
    else if (x_ballena < -x_ballena_max)
        x_ballena = -x_ballena_max;
}

void Ovni::aumentar_ballena_y(float aumento)
{
    y_ballena += aumento;
}

void Ovni::gradosLibertad(int i, float aumento)
{
    switch(i){
        case 0:
            aumentar_r_luces(aumento);
        break;

        case 1:
            aumentar_foco_y(aumento);
        break;

        case 2:
            aumentar_h_gancho(aumento);
        break;

        case 3:
            aumentar_foco_x(aumento);
        break;

        case 4:
            aumentar_ballena(aumento);
        break;

        case 5:
            aumentar_ballena_x(aumento);
        break;

        case 6:
            aumentar_ballena_y(aumento);
        break;
    }
}

void Ovni::cambiar_solido()
{
    cabina->cambiar_solido();
    cuerpo->cambiar_solido();
    luces.cambiar_solido();
    inferior.cambiar_solido();
    laboon.cambiar_solido();
    abductor->cambiar_solido();
}
void Ovni::cambiar_lineas()
{
    cabina->cambiar_lineas();
    cuerpo->cambiar_lineas();
    luces.cambiar_lineas();
    inferior.cambiar_lineas();
    laboon.cambiar_lineas();
    abductor->cambiar_lineas();
}
void Ovni::cambiar_puntos()
{
    cabina->cambiar_puntos();
    cuerpo->cambiar_puntos();
    luces.cambiar_puntos();
    inferior.cambiar_puntos();
    laboon.cambiar_puntos();
    abductor->cambiar_puntos();
}
void Ovni::cambiar_ajedrez()
{
    cabina->cambiar_ajedrez();
    cuerpo->cambiar_ajedrez();
    luces.cambiar_ajedrez();
    inferior.cambiar_ajedrez();
    laboon.cambiar_ajedrez();
    abductor->cambiar_ajedrez();
}

void Ovni::activar_inmediato()
{
    cabina->activar_inmediato();
    cuerpo->activar_inmediato();
    luces.activar_inmediato();
    inferior.activar_inmediato();
    laboon.activar_inmediato();
    abductor->activar_inmediato();
}
void Ovni::activar_diferido()
{
    cabina->activar_diferido();
    cuerpo->activar_diferido();
    luces.activar_diferido();
    inferior.activar_diferido();
    laboon.activar_diferido();
    abductor->activar_diferido();
}
