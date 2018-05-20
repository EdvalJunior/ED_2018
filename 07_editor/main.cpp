#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "sftext.h"

using namespace std;

struct Ambiente{
    list<char> texto;
    list<char>::iterator cursor;
    Ambiente(){
        cursor = texto.end();
    }

    string toString(){
        stringstream ss;
        for(auto it = texto.begin(); it != texto.end(); it++){
            if(it == cursor)
                ss << "#";
                ss << (*it);
        }
        if(cursor == texto.end())
            ss << "#";
        return ss.str();
    }
};

int main()
{
    Ambiente amb;
    amb.texto.push_back('a');
    amb.texto.push_back('m');
    amb.texto.push_back('o');
    amb.texto.push_back('r');

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    while(janela.isOpen()){

        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                janela.close();
            if(event.type == sf::Event::KeyPressed){
                if((event.key.code >= sf::Keyboard::A) &&
                   (event.key.code <= sf::Keyboard::Z)){
                    char tecla = 'a' + (event.key.code - sf::Keyboard::A);
                    cout << tecla << endl;
                    amb.texto.insert(amb.cursor, tecla);
                }
                //TECLA CTRL Z
                else if(event.key.code == sf::Keyboard::Z){
                    if(event.key.control)
                        cout << "control z" << endl;
                }
                //TECLA CTRL R
                else if(event.key.code == sf::Keyboard::R){
                    if(event.key.control)
                        cout << "control r" << endl;
                }
                //TECLADO ALFABÉTICO
                else if((event.key.code >= sf::Keyboard::A) &&
                   (event.key.code <= sf::Keyboard::Z)){
                    char tecla = (event.key.code - sf::Keyboard::A) + 'a';
                    amb.texto.insert(amb.cursor, tecla);
                    cout << tecla << endl;
                }
                //Tecla Enter
                else if((event.key.code == sf::Keyboard::Return)){
                    cout << "enter" << endl;
                    amb.texto.insert(amb.cursor, '\n');
                }
                //TECLA ESPAÇO
                else if((event.key.code == sf::Keyboard::Space)){
                    cout << "espaco" << endl;
                    amb.texto.insert(amb.cursor, ' ');
                }
                //TECLA BACKSPACE
                else if(event.key.code == sf::Keyboard::BackSpace){
                    cout << "backspace" << endl;
                    if(amb.cursor!=amb.texto.begin())
                        amb.texto.erase(amb.cursor++, amb.cursor--);
                //TECLA DELETE
                }else if(event.key.code == sf::Keyboard::Delete){
                    cout << "delete" << endl;
                    if(amb.cursor != amb.texto.end()){
                       amb.texto.erase(amb.cursor++);
                    }
                }
                //TECLA LEFT
                else if(event.key.code == sf::Keyboard::Left){
                    amb.cursor--;
                }
                //TECLA RIGHT
                else if(event.key.code == sf::Keyboard::Right){
                    amb.cursor++;
                }
            }
        }

        auto pos = sf::Vector2f(30, 50);
        janela.clear();
        janela.draw(sfText(pos, amb.toString(), sf::Color::White, 30));
        janela.display();
    }
    return 0;

}




