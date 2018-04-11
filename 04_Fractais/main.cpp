#include <lib/pen.h>

void triangulo(Pen &p, int lado){
    if(lado < 1)
        return;
    for(int i=0; i<3;i++){
        p.setBackColor(204,255,204);
        p.setColor(255,128,0);
        p.walk(lado);
        p.left(120);
        triangulo(p, lado/2);
        /*p.left(120);
        triangulo(p, lado/2);
        p.left(120);
        triangulo(p, lado/2);
        p.walk(lado);
        p.left(120)*/;
    }
}
void fractalTriangulo(){
    Pen p(800, 600);
    p.setThickness(1);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(500,500);

    //faz o pincel apontar pra direita
    p.setHeading(0);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(0);

    triangulo(p, 300);

    //espera clicar no botao de fechar
    p.wait();
}
void embuarvore(Pen& p, int lado){
      float ang = 45;
    if(lado < 15)
        return;
    p.setColor(255,128,0); //Cor alaranjada amarelada para dar noção de outono
    p.setBackColor(204,255,204); //Plano de fundo claro
    p.walk(lado);
    p.right(ang);
    embuarvore(p, lado -10);
    p.left(ang);
    embuarvore(p, lado -10);
    p.left(ang);
    embuarvore(p, lado -10);
    p.right(ang);
    p.walk(-lado);

    p.setColor(0,153,0);//verde do retorno da recursão

}
void fractalArvore(){
    Pen p(800, 600);
    p.setThickness(12);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(700,600);

    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(0);

    embuarvore(p, 95);

    //triangulo(p, 200);
    //espera clicar no botao de fechar
    p.wait();
}
void gelo(Pen &p, int lado){
    int angulo= 72;

    if(lado < 1)
         return;
    for(int i=0; i<5;i++){
        p.setBackColor(204,255,204);
        p.setColor(0,153,0);
        p.walk(lado);
        gelo(p, lado * 0.35);
        p.walk(-lado);
        p.right(angulo);
    }
}
void fractalGelo(){
    Pen p(1000, 600);
    p.setThickness(1);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(700,350);

    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(0);

    gelo(p,200);

    //espera clicar no botao de fechar
    p.wait();
}
void circulos(Pen& p, int lado){
    if(lado < 1)
          return;
    for(int i=0;i < 6;i++){
          p.setBackColor(204,255,204);
          p.setColor(0,153,0);

          p.circle(lado);
          p.left(60);
          p.up();
          p.walk(lado);
          p.down();
          circulos(p, lado*2/6);
          p.up();
          p.walk(-lado);
          p.down();
     }
}
void fractalcirculos(){
    Pen p(1000, 600);
    p.setThickness(1);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(600,400);

    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(0);

    circulos(p,200);

    //espera clicar no botao de fechar
    p.wait();
}
void Trigo(Pen &p, int lado){
    int dec=3;
    int angulo=40;
    if(lado<1)
        return;

    for(int i=0;i<4;i++){
        p.setBackColor(255,255,255);
        p.setColor(0,0,0);
        p.walk(lado);
        p.right(angulo);
        Trigo(p,lado/dec);
        p.left(2*angulo);
        Trigo(p,lado/dec);
        p.right(angulo);
    }
    p.walk(-lado*4);
}
void fractalTrigo(){
    Pen p(1000,1000);
    p.setThickness(1);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(600,600);

    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(0);

   Trigo(p,100);

    //espera clicar no botao de fechar
    p.wait();
}
int main(){
    //fractalArvore();
    //fractalcirculos();
    //fractalTriangulo();
    //fractalGelo();
    //fractalTrigo();

    return 0;
}




































