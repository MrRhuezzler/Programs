#ifndef STACK_HPP
#define STACK_HPP

class Stack {

    private:
        int *arr;
        int t;
        int n;

    public:
        Stack(int n);
        ~Stack();
        
        // Methods
        void push(int elem);
        void pop();
        int top();
        int size();

        // Emptiness n Fullness
        bool isfull();
        bool isempty();

        // Outputs
        void print();
        
};

#endif
