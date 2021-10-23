#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <atomic>
using namespace std;
class fruit{
public:
    fruit() {

    }

    fruit(fruit *pFruit) {

    }

    std::string name;
    int weight = rand();
    void cut() {
        weight /=2;
    }

    virtual void print(){
        std::cout << "Its fruit " << name << ", weight: " << weight << std::endl;
    };

};
class apple : public fruit {
public:
    std::string kind;
    int number = rand();
    auto rename(std::string k){
        name = k;
    }
    auto sell(){
        number-=1;
    }
    void print(){
        std::cout << "Its apple " << name << ", weight: " << weight << ", number: "<< number << ", kind: " << kind << std::endl;
    }
};
auto chetapple(std::vector<fruit*> &k) {
    bool flag = true;
    while(flag) {
        int applecounter = 0;
        for (int i = 0; i < k.size(); i++) {
            if (typeid(*k[i]) == typeid(apple)) {
                applecounter++;
            }
        }
        if (applecounter > 10) {
            flag = false;
            std::cout << "WOW. So much apple!" << std::endl;
        }
        std::this_thread::sleep_for(1000ms);
    }
}
auto chetfruit(std::vector<fruit*> &k) {
    bool flag = true;
    while (flag) {
        int fruitcounter = 0;
        for (int i = 0; i < k.size(); i++) {
            if (typeid(*k[i]) == typeid(fruit)) {
                fruitcounter++;
            }
        }
        if (fruitcounter > 10) {
            flag = false;
            std::cout << "WOW. So much fruit!" << std::endl;
        }
        std::this_thread::sleep_for(1000ms);
    }
}
int main() {
    fruit a;
    a.name = "ANANAS";
    a.weight = 2;
    a.cut();
    apple b;
    b.name = "osetr";
    b.kind = "antonovka";
    b.rename("Big apple");
    apple *h = &b;
    fruit *r = &a;
    std::vector<fruit*> k;
    for (int i =0;i<9;i++) {
        k.push_back(new fruit);
        k.push_back(new apple);
        k[2*i]->print();
        k[2*i+1]->print();
    }
    k.push_back(h);
    k.push_back(r);
    k[11]->print();
    k[10]->print();
    std::thread c(&chetapple, std::ref(k));
    std::thread w(&chetfruit, std::ref(k));
    std::string cl = "1";
    while (cl!="0"){
        std::cout << "apple or just fruit? For end '0'"<< std::endl;
        std::cin >> cl;
        if (cl !="0") {
            std::cout << "name?" << std::endl;
            std::string namee;
            std::cin >> namee;
            std::cout << "Weight?" << std::endl;
            int w;
            std::cin >> w;
            if (cl == "apple") {
                std::cout << "kind?" << std::endl;
                std::string kk;
                std::cin >> kk;
                std::cout << "number?" << std::endl;
                int nu;
                std::cin >> nu;
                apple *p = new apple;
                p->name = namee;
                p->weight = w;
                p->kind = kk;
                p->number = nu;
                k.push_back(p);
            }
            else{
                fruit *p = new fruit;
                p->name = namee;
                p->weight = w;
                k.push_back(p);
            }
        }
        else {

        }
    }
    for (int i =0;i<k.size();i++) {

        k[i]->print();
    }
    c.join();
    w.join();

    return 0;
}
