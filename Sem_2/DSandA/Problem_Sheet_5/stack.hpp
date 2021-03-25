#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class Stack {

    private:
        T *arr;
        int t;
        int n;

    public:
        Stack(int n);
        ~Stack();
        
        // Methods
        void push(T elem);
        void pop();
        T top();
        int size();
        void reverse();

        // Emptiness n Fullness
        bool isfull();
        bool isempty();

        // Outputs
        void print();

};


template <typename T>
Stack<T>::Stack(int n)
:n(n), t(-1)
{

    arr = new T[n];

}

template <typename T>
Stack<T>::~Stack(){
    delete[] arr;
}

template <typename T>
void Stack<T>::push(T elem){

    if(!isfull()){
        arr[++t] = elem;
    }else{
        std::cout << "[ERROR] Stack Overflow, when trying to push " << elem << std::endl;
    }

}

template <typename T>
void Stack<T>::pop(){

    if(!isempty()){
        t--;
    }else{
        std::cout << "[ERROR] Stack Underflow, when trying to pop" << std::endl;
    }

}

template <typename T>
T Stack<T>::top(){

    if(!isempty()){
        return arr[t];
    }
    std::cout << "Stack is Empty !" << std::endl; 
    exit(0);

}

template <typename T>
int Stack<T>::size(){
    return t + 1;
}

template <typename T>
bool Stack<T>::isfull(){
    return t == n - 1;
}

template <typename T>
bool Stack<T>::isempty(){
    return t == -1;
}

template <typename T>
void Stack<T>::print(){
    for(int i = 0; i < size(); i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

template <typename T>
void Stack<T>::reverse(){

    T *temp = new T[n];
    int n = size();

    for(int i = 0; i < n; i++){
        temp[i] = top();
        pop();
    }

    for(int i = 0; i < n; i++){
        push(temp[i]);
    }

    delete[] temp;

}


#endif
