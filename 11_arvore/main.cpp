#include <iostream>
#include <boost/serialization/serialization.hpp>

using namespace std;

struct Interception {
    string liid_;
    string targetId_;
    TargetType targetType_;
    string deliveryOfIRI_;
    string deliveryOfIPR_;
    string startTime_;
    string endTime_;
};

namespace boost {
namespace serialization {
 void serialize(Archive &ar, const unsigned int version) {
    ar & i.liid_;
    ar & i.targetId_;
    ar & i.targetType_;
    ar & i.deliveryOfIRI_;
    ar & i.deliveryOfIPR_;
    ar & i.startTime_;
    ar & i.endTime_;
 };
}
}

struct Node {
    int value;
    Node * left;//nó que contém lado esquerdo todos os valores da árvore
    Node * right;//nó que contém lado direito todos os valores da árvore
    //Construtor vazio
    Node(){
    }
    //Construtor iniciando as coisas
    Node(int value, Node * left, Node * right):
        value(value), left(left), right(right){
    }
};

struct Tree {
    Node * root;
    Lista(){
        root = nullptr;
    }

    Tree(Tree other){
        root = clone(other.root);
    }

    //Aprendi a clonar uma árvore que não sabia, devido não ter feito a prova ainda na época
    Node * clone(Node * node){
        if(node == nullptr)
            return nullptr;
        return new Node(node->value, clone(node->left),clone(node->right));
    }

    bool equals(Lista other){
        return equals(this->head, other.head);
    }

    bool equals(Node * node, Node * other){
        if((node == nullptr) && (other == nullptr))
            return true;
        if((node == nullptr) || (other == nullptr))
            return false;
        if(node->value != other->value)
            return false;
        return equals(node->left, other->left) &&
               equals(node->right,other->right);
    }


    ~Tree(){
        Node * node = head;
        while(node != nullptr){
            auto aux = node->left;
            auto aux = node->r;
            delete node;
            node = aux;
        }
    }

    void erase(Node * node){
        if(node == nullptr)
            return;
        erase(node->right);
        erase(node->left);
        delete node;
    }

    Node * find(Node * node, int key){
        if(node == nullptr)
            return nullptr;
        if(node->key == key)
            return node;
        auto resp = find(node->left, key);
        if(resp != nullptr)
            return resp;
        return find(node->right, key);
    }

    //ligatures
    int _min(Node * node){
        if((node->left == nullptr) && (node->right == nullptr))
            return node->value;
        int menor;
        if(node->left != nullptr)
            menor = std::min(node->value, _min(node->left));
        if(node->right != nullptr)
            menor = std::min(menor, _min(node->right));
        return menor;
    }

    int _min(Node * node){
        if(node == nullptr)
            return 2147483647;
        return std::min(std::min(node->value, _min(node->left)),
                                 _min(node->right));
    }

    int min(){
        return _min(head);
    }

    int _soma(Node * node){
        if(node == nullptr)
            return 0;
        return node->value + _soma(node->left) + _soma(node->right);
    }

    int soma(){
        return _soma(root);
    }

    void _show(Node * node){
        if(node == nullptr)
            return;
        _show(node->left);
        _show(node->right);
        cout << node->value << " ";
    }

    void show(){
        _show(root);
    }

    void readFromFile(const std::string &fileName, ListType &out) {
        std::ifstream f(fileName.c_str());
        boost::archive::text_iarchive ia(f);
        boost::serialization::load(ia, out, 1);
    }

    void saveToFile(const std::string &fileName, const ListType& in) {
        std::ofstream ofs(fileName.c_str());
        boost::archive::text_oarchive oa(ofs);
        boost::serialization::save(oa, in, 1);
    }


};


int main()
{
    String tx= "arvorEd.txt";
    saveToFile(tx, server->getConfig().getInterceptions());
    readFromFile(tx, server->getConfig().getInterceptions());

    return 0;
}

