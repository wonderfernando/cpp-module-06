#include "Base.hpp"

int main(void) {
 
    // 1: Gerar e identificar com ponteiro
    std::cout << "1: Identificar com ponteiro" << std::endl;
    Base* obj1 = generate();
    std::cout << "Tipo identificado (ponteiro): ";
    identify(obj1);
    std::cout << std::endl;
    
    // 2: Identificar com referência
    std::cout << "2: Identificar com referência" << std::endl;
    std::cout << "Tipo identificado (referência): ";
    identify(*obj1);
    std::cout << std::endl;
    
    delete obj1;
   
    
    //   tipos específicos
    std::cout << "4: Testando tipos específicos" << std::endl;
    
    A* a = new A();
    std::cout << "Tipo A - Ponteiro: ";
    identify(a);
    std::cout << "Tipo A - Referência: ";
    identify(*a);
    std::cout << std::endl;
    
    B* b = new B();
    std::cout << "Tipo B - Ponteiro: ";
    identify(b);
    std::cout << "Tipo B - Referência: ";
    identify(*b);
    std::cout << std::endl;
    
    C* c = new C();
    std::cout << "Tipo C - Ponteiro: ";
    identify(c);
    std::cout << "Tipo C - Referência: ";
    identify(*c);
    
    delete a;
    delete b;
    delete c;
    
    return 0;
}