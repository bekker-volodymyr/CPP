class AbstractClass {
public:
    virtual ~AbstractClass() = 0;
};

AbstractClass::~AbstractClass() { }

class DerivedFromAbstract : public AbstractClass {

};