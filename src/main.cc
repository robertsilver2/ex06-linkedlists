/**
 * CS V15 Data Structures and Algorithms
 * CRN: 70342
 * Assignment: ex06-LinkedList
 *
 *
 * Statement of code ownership: I hereby state that I have written all of this
 * code and I have not copied this code from any other person or source.
 *
 * @robertsilver2
 */

#include <iostream>
#include "list.h"
using edu::vcccd::vc::csv15::LinkedList;
int main(int argc, char *argv[]) {
    std::cout << "OwO oh henlo there world" <<std::endl;
    //LinkedList test1;
    for(int i= 0; i<1; i++) {
        LinkedList<uint64_t> testing1;
        testing1.printList();
        uint64_t testPush1 = 10;
        testing1.push_back(testPush1);
        testing1.push_back(testPush1*2);
        testing1.push_back(testPush1*3);
        std::cout<< "print testing1: " <<std::endl;
        testing1.printList();
        LinkedList<uint64_t> testing2(testing1);
        std::cout<< "print testing2: " <<std::endl;
        testing2.printList();

        LinkedList<uint64_t> testing3(testing2);
        testing3.printList();
        std::cout << "testing3 front is " << testing3.front() << std::endl;
        std::cout << "testing3 back is " << testing3.back() << std::endl;
        std::cout << "testing3 size is " << testing3.size() << std::endl;
        testing3.pop_back();
        std::cout << "testing3 back is " << testing3.back() << std::endl;
        testing3.printList();
        testing3.pop_front();
        std::cout << "testing3 front is " << testing3.front() << std::endl;
        testing3.printList();

        LinkedList<uint64_t> testing4;
        testing4.push_back(32);
        testing4.push_back(2);
        testing4.push_back(101);
        testing4.push_back(29);
        std::cout << "testing4: " << std::endl;
        testing4.printList();
        std::cout << "testing1: " << std::endl;
        testing1.printList();
        testing4.swap(testing1);
        std::cout << "swap done:" << std::endl;
        std::cout << "testing4: " << std::endl;
        testing4.printList();
        std::cout << "testing1: " << std::endl;
        testing1.printList();



    }//put in a loop so object lifetime will end before end of main, test destructor
    std::cout << "loop exited" << std::endl;
    std::cout << "done??" << std::endl;
}