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

#include <cstdlib>
#include <utility>

namespace edu {
	namespace vcccd {
		namespace vc {
			namespace csv15 {
				template<class T>
				class LinkedList {
				private:
					struct Node {
						Node(T data, Node *next) : _data(data), _next(next) {}
						Node* _next;
						T _data;
					};
				public:
					class iterator {
					public:
						iterator(Node *node) : _node(node) {}
						iterator(const iterator &other) : _node(other._node) {}

					public:
					    const T &operator*() { return _node->_data; }
						const T &operator*() const { return _node->_data; }
						iterator &operator++() { _node = _node->_next; return *this; }
						iterator operator++(int) { iterator before(*this); _node = _node->_next; return before; }
						bool operator==(const iterator &other) { return other._node == _node; }
						bool operator!=(const iterator &other) { return !operator==(other); }
						Node *node() { return _node; }
					private:
						Node *_node;
					};

				public:
					LinkedList() {
					    //default constructor
					    head = NULL;
					    tail = NULL;
					    _size = 0;
					    std::cout << "_size = " << _size << std::endl;

					}
					LinkedList(const LinkedList &other) {
					    //copy constructor, copies list from one list to newly constructed;
					    //deep copy
					    std::cout << "copy constructor entered" << std::endl;
					    std::cout << "other empty?" << other.empty() <<std::endl;
                        head=NULL;
                        tail=NULL;
                        _size=0;
                        std::cout << "head and tail nullified" << std::endl;
					    iterator i = other.begin();
					    for(int j = 0; j<other.size(); j++){
                            push_back(*i);
                            i++;
                            //not sure if I did this right just a guess
                        }
                        std::cout << "copy created" << std::endl;

					}
					~LinkedList() {
					    //destructor. clears list, deletes (deallocate memory) all nodes
					    if(head!=NULL) {
                            clear();
                        }

					}

				public:
					//i think i got these done

				    bool empty() const {
					    return(_size==0);
					    //return true if list empty, false otherwise
					}

					T &front() {
					    return head->_data;

					    //return a reference to the value at the front of the list
					    //is this right?

					}
					const T &front() const {
                        //return a constant reference to the value at the front of the list
                        return head->_data;
					}

					T &back() {
					    //return a ref to val back of list
					    return tail->_data;
					}
					const T &back() const {
					    //return cons ref val back of list
                        return tail->_data;
					}

					size_t size() const {
					    return _size;
					}

				public:
					iterator begin() {
						return(iterator(head));
					    //returns an iterator pointing to the first element of the list
					}
					const iterator begin() const {
                        return(iterator(head));
					}

					iterator end() {
					    return(iterator(tail));
					}
					const iterator end() const {
					    return(iterator(tail));
					}

				public:
					void clear() {
					    std::cout << "clear entered" << std::endl;
                        erase(head, tail);
					}

					iterator insert(iterator where, const T &value) {

					}

					iterator erase(iterator where) {
					    return(nullptr);
					}
					iterator erase(iterator first, iterator last) {
						//std::cout << "get here? line erase else statement" << std::endl;
						iterator i = first.node();
                        while (_size>0) {
                            Node *temp = i.node();
                            i++;
                            head = i.node();
                            delete temp;
                            _size -= 1;
                        }
                        std::cout << "_size= " <<_size << std::endl;
                        return nullptr;
					}

					void push_back(const T &value) {
					    if(head == NULL){
					        head = new Node(value, tail);
					        tail = head;
					        tail->_next=nullptr;
					        _size+=1;

					    }else {
                            Node *newFront = new Node(value, head);
                            head = newFront;
                            _size+=1;
                        }
					}

					void pop_back() {
					    std::cout << "popback entered" << std::endl;
					    iterator i = head;
					    std::cout<< "popback it i val = " << *i << std::endl;
					    while(i.node()->_next!=tail){
					        i++;
					    }
                        std::cout<< "popback it i val = " << *i << std::endl;
					    Node* temp = tail;
					    tail = i.node();
					    delete temp;
					    _size-=1;
					    std::cout << "temp deleted popback" << std::endl;

					}

					void push_front(const T &value) {
					    //insert new node to back of list
                        if(tail == NULL){
                            push_back(value);
                        }else {
                            Node *myBack = new Node(value, nullptr);
                            tail->_next = myBack;
                            tail = myBack;
                            _size += 1;
                        }
					}

					void pop_front() {}

				public:
					void swap(LinkedList &other) {}

				public:
				    void printList(){
					    if (!this->empty()) {
                            iterator i = head;
                            for (int j = 0; j < _size; j++) {
                                std::cout << " [" << *i << "]";
                                i++;
                            }
                        }else{
					        std::cout << "list to print is empty" <<std::endl;
					    }
                        std::cout<<std::endl;
					}

				private:
					Node *head;
					Node *tail;
					size_t _size;
				};
			}
		}
	}
}