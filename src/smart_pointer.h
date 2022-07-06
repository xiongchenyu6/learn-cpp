template <typename A>
class SmartPointer {
public:
    static SmartPointer<A> make_pointer() {
        SmartPointer<A> a;
        a.ip = new A();
        return a;
    }
    ~SmartPointer<A>() { delete ip; }

    A* operator->() { return ip; }

private:
    A* ip;
};
