#ifndef STACK_HPP
#define STACK_HPP

class Stack {

    private:
        char *arr;
        int t;
        int n;

    public:
        Stack(int n);
        ~Stack();
        
        // Methods
        void push(char elem);
        void pop();
        char top();
        int size();
        void reverse();

        // Emptiness n Fullness
        bool isfull();
        bool isempty();

        // Outputs
        void print();

};

#endif
