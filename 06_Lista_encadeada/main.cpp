#include <iostream>

using namespace std;

struct  Node{
    int value;
    Node* next;

    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{

    Node* head;

    SList(){
        this->head = nullptr;
    }

    ~SList(){
        head = deletarTudo(head);
    }

/*
    SList(){

    }
*/

    Node * deletarTudo(Node * node){
        if(node == nullptr){
            return nullptr;
        }
        deletarTudo(node->next);
        delete node;
        return nullptr;
    }

    void push_front(int value){
        //this->head = new Node(value, this->head);
        Node * node = new Node(value);
        node->next = head;
        this->head = node;
    }

    void pop_front(){
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }

//    Vetor(string serial){
//        stringstream ss(serial);
//        int value;
//        while(ss >> value){
//            this->push_back(value);
//        }
//    }

//    string _serialize(stringstream &ss, int ind){
//        if(ind == _size)
//            return;
//        ss << _data[ind];
//        _serialize(ss, ind + 1);
//    }

//    string serialize(){
//        stringstream ss;
//        _serialize(ss, 0);
//        return ss.str();
//    }


    void push_back(int value){//PUSH_BACK INTERATIVO
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = head;
        while(node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
    }
    /*
    *PUSH BACK RECURSIVO
    *
    */
    Node * _rpush_back(Node * node, int value){
         if(node == nullptr)
             return new Node(value);
         node->next = _rpush_back(node->next, value);
         return node;
     }

     void rpush_back(int value){
         head = _rpush_back(head, value);
     }

    /*
    *POP BACK ITERATIVA
    */
    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }
    /*
    *POP BACK RECURSIVO PRIVADA
    */
    Node * _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
    }
    /*
    *POP_BACK RECURSIVO PUBLICA
    */
    void rpop_back(){
        this->head = _rpop_back(head);
    }
    /*
    *SHOW INTERATIVO
    */
    void ishow(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }
    /*
    *SHOW RECURSIVO PRIVADA
    */
    Node * _rshow(Node * node){
        if(node == nullptr){
            return nullptr;
        }
        _rshow(node->next);
        cout << node->value << " ";
    }
    /*
    *SHOW RECURSIVO PÚBLICA
    */
    void rshow(){
        _rshow(head);
        cout << "" << endl;
    }
    /*
    * 1 2 3 4 5 remover 3
    *
    */
    /*
    *REMOVER INTERATIVO
    */
    void remover(int value){
        auto node = head;
         if(node == nullptr){
            return ;
         }
         if(node->value == value && node->next == nullptr){
             pop_back();
             return;
         }
             while(node->next->value == value){
                 auto aux = node->next->next;
                 node->next = nullptr;
                 delete node->next;
                 head = aux;
             }
    }

    /*
    *REMOVER RECURSIVO
    */
    Node * _remove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _remove(node->next, value);
    }

    void rremove(int value){
        head = _remove(head, value);
    }

    /*
     * Exemplo: 5 9 1 2; arrancaRabo(1); 5 9 1
     * */
    Node * arrancaRabo(Node * node, int value){
        if(node == nullptr){
            return nullptr;
        }
        if(node->next->value == value){
            return node;
        }
        delete node;
        node->next = arrancaRabo(node->next, value);
    }

    void arrancaRabo(int value){
        this->head= arrancaRabo(head->next,value);
    }

    /*
     * Exemplo: 5 9 1 2; arrancaVenta(9); 9 1 2
     * */
    Node * arrancaVenta(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        node->next = arrancaVenta(node->next, value);
        if(node->next == nullptr){
            if(node->value != value){
                delete node;
                return nullptr;
            }else{
                return node;
            }
        }
        return node;
    }


    /*
    head = 900;
    900:{1 500};
    500:{2 700};
node700:{4 250};
    300:{6 0};
    250:{5 300};
    */

    //5
    //2 >4 X 6
    void inserir_ordenado(int value){//INSERIR ORDENADO INTERATIVO
        auto node = head;
        if(head == nullptr || head->value > value){
            this->head = new Node(value, head);
            return;
        }
        while(node->next != nullptr && node->next->value < value){
            node = node->next;
        }
        node->next = new Node(value, node->next);
    }
    /*
    *INSERIR ORDENADO RECURSIVO
    *
    */
    Node * _rinserir_ordenado(Node * node, int value){
        if(node==nullptr){
             return new Node(value);
        }
        if(node->value> value){
            return new Node(value,node);
        }
        node->next= _rinserir_ordenado(node->next,value);
        return node;
   }

   void rinserir_ordenado(int value){
        this->head=_rinserir_ordenado(head,value);

   }

   int size(){
       int size = 0;
       auto node = head;
       while(node != nullptr){
           node = node->next;
           size++;
       }
       return size;
   }


    int rsomar(Node * node){
        node=head;
        if(node->next==nullptr){
            return node->value;
        }
        return rsomar(node->next)+node->value;
    }

    int rmin(Node * node){
        if(node->next == nullptr)
            return node->value;
        return std::min(node->value, rmin(node->next));
    }
};


int main(){
    SList lista;
    lista.push_back(8);
    lista.push_back(2);
    lista.push_back(4);
    lista.push_back(9);
    lista.push_back(6);
    lista.rshow();
    cout << "VENTA" << endl;
    lista.arrancaVenta(lista.head,4);
    lista.rshow();
    cout << "RABO" << endl;
    lista.arrancaRabo(2);
    lista.rshow();
//    cout << "REMOVER" << endl;
//    lista.remover(2);
//    lista.rshow();



    return 0;
}
