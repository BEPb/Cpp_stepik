struct Expression;
struct Number;
struct BinaryOperation;
 
struct Help {
    Help(Expression *ptr=NULL) {
        this->ptr = ptr;
        cnt = 1;
    }
    ~Help() {
        delete ptr;     
    }
    Expression * ptr;
    mutable int cnt ;
};
 
struct SharedPtr {
    // реализуйте следующие методы
    //
    explicit SharedPtr(Expression *ptr = 0) {
        if(ptr != 0)
            h = new Help(ptr);
        else
            h = NULL;
    }
    ~SharedPtr() {      
        if(h!=NULL) {
            --(h->cnt);
            if(h->cnt == 0)
                delete h;
        }
    }
    SharedPtr(const SharedPtr & other) {
        this->h = other.h;
        if(this->h!=NULL && this->h->cnt)
            ++(this->h->cnt);
    }
    SharedPtr& operator=(const SharedPtr & other) {
        if(this!=&other){
            this->~SharedPtr();
            this->h = other.h;
            if(this->h != NULL)
                ++(this->h->cnt);
        }
    }
    Expression* get() const {
        if(this->h != NULL)
            return this->h->ptr;
        else
            return NULL;
    }
    void reset(Expression *ptr = 0) {
        this->~SharedPtr();
        if(ptr != 0)
            h = new Help(ptr);
        else
            h = NULL;
    }
    Expression& operator*() const {
        if(this->h != NULL)
            return *(this->h->ptr);
        else
            return *(Expression *)NULL;
    }
    Expression * operator->() const {
        if(this->h != NULL)
            return this->h->ptr;
        else
            return NULL;
    }
private:
    Help * h=NULL;
};